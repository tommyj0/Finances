#pragma once

#include "Expense.h"

#include <memory>
#include <string>
#include <vector>

class Finances {
private:
  float savings = 0.f;
  float income_yearly = 0.f;
  float income_monthly = 0.f;
  bool has_savings = false;

  std::vector<std::unique_ptr<IExpense>> expenses;

  void upsert_expense(std::unique_ptr<IExpense> expense);

public:
  Finances(float income_yearly, float savings);
  void set_utils_monthly(float utils_monthly);
  void set_rent_monthly(float rent_monthly);
  void set_mortgage_monthly(float mortgage_monthly);
  void set_subscriptions_monthly(float subscriptions_monthly);
  void set_groceries_monthly(float groceries_monthly);
  void set_council_tax_band(char council_tax_band);
  void set_student_loan(float total_owed);
  
  void print_summary();
};