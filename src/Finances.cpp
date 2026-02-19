#include "Finances.h"
#include "CouncilTaxExpense.h"
#include "StudentLoanExpense.h"
#include "TaxExpense.h"

#include <cstdio>
#include <memory>


Finances::Finances(float income_yearly, float savings) :
  savings(savings),
  income_yearly(income_yearly),
  income_monthly(income_yearly / 12.f),
  has_savings(savings > 0.f)
{
  upsert_expense(std::make_unique<TaxExpense>(
    "TAX",
    std::vector<float>{12570.f, 50270.f, 125140.f, 1000000.f},
    std::vector<float>{0.f, 0.2f, 0.4f, 0.45f}
  ));

  upsert_expense(std::make_unique<TaxExpense>(
    "NI",
    std::vector<float>{12570.f, 50270.f, 100000000.f},
    std::vector<float>{0.f, 0.08f, 0.02f}
  ));
}

void Finances::upsert_expense(std::unique_ptr<IExpense> expense)
{
  const std::string expense_id = expense->get_id();

  for (auto& existing_expense : expenses) {
    if (existing_expense->get_id() == expense_id) {
      existing_expense = std::move(expense);
      return;
    }
  }

  expenses.push_back(std::move(expense));
}

void Finances::set_council_tax_band(char council_tax_band)
{
  upsert_expense(std::make_unique<CouncilTaxExpense>(council_tax_band));
}

void Finances::set_utils_monthly(float utils_monthly)
{
  upsert_expense(std::make_unique<Expense>("UTILS", utils_monthly));
}

void Finances::set_rent_monthly(float rent_monthly)
{
  upsert_expense(std::make_unique<Expense>("RENT", rent_monthly));
}

void Finances::set_mortgage_monthly(float mortgage_monthly)
{
  upsert_expense(std::make_unique<Expense>("MORTGAGE", mortgage_monthly));
}

void Finances::set_subscriptions_monthly(float subscriptions_monthly)
{
  upsert_expense(std::make_unique<Expense>("SUBSCRIPTIONS", subscriptions_monthly));
}

void Finances::set_groceries_monthly(float groceries_monthly)
{
  upsert_expense(std::make_unique<Expense>("GROCERIES", groceries_monthly));
}

void Finances::set_student_loan(float total_owed)
{
  upsert_expense(std::make_unique<StudentLoanExpense>(total_owed));
}

void Finances::print_summary()
{
  float running_total_monthly = income_monthly;

  printf("Starting Monthly Income: £%.2f\n", running_total_monthly);

  if (has_savings) {
    printf("Savings: £%.2f\n", savings);
  }

  for (const auto& expense : expenses) {
    const float monthly_cost = expense->get_monthly_cost(income_yearly);
    running_total_monthly -= monthly_cost;
    printf("[%s] Expenditure: £%.2f | Running Total: £%.2f\n",
      expense->get_id().c_str(),
      monthly_cost,
      running_total_monthly
    );
  }

  printf("Ending Monthly Total: £%.2f\n", running_total_monthly);
}