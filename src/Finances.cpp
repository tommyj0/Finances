#include "Finances.h"
#include "Thresholds.h"
#include "CouncilTaxBands.h"
#include <cstdio>


Finances::Finances(float income_yearly, float savings) :
income_yearly(income_yearly),
income_monthly(income_yearly / 12.f),
has_income(true),
savings(savings)
{

}

float Finances::calculate_taxes_paid_monthly()
{
  if (!has_income) {
    return 0.f;
  }
  // UK defaults
  Thresholds income_thresholds({12570.f, 50270.f, 125140.f,1000000}, {0.f, 0.2f, 0.4f, 0.45f});

  const float tax_yearly = income_thresholds.calculate_tax(income_yearly);
  const float tax_monthly = tax_yearly / 12.f;
  return tax_monthly;
}

float Finances::calculate_ni_paid_monthly()
{
  if (!has_income) {
    return 0.f;
  }
  // UK defaults
  Thresholds ni_thresholds({12570.f, 50270.f, 100000000}, {0.f, 0.08, 0.02f});

  const float ni_yearly = ni_thresholds.calculate_tax(income_yearly);
  const float ni_monthly = ni_yearly / 12.f;
  return ni_monthly;
}

float Finances::calculate_council_tax_paid_monthly()
{
  if (!has_council_tax) {
    return 0.f;
  }
  // Manchester defaults
  CouncilTaxBands council_tax_bands({'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}, {1455.36f, 1697.91f, 1940.46f, 2183.03f, 2668.14f, 3153.26f, 3638.39f, 4366.06f});

  const float council_tax_yearly = council_tax_bands.calculate_tax(council_tax_band);
  const float council_tax_monthly = council_tax_yearly / 12.f;
  return council_tax_monthly;
}

void Finances::set_council_tax_band(char council_tax_band)
{
  this->council_tax_band = council_tax_band;
  has_council_tax = true;
}
void Finances::set_utils_monthly(float utils_monthly)
{
  this->utils_monthly = utils_monthly;
  has_utils = true;
}

void Finances::set_rent_monthly(float rent_monthly)
{
  this->rent_monthly = rent_monthly;
  has_rent = true;
}

void Finances::print_summary()
{ 
  float running_total_monthly = income_monthly;

  printf("Starting Monthly Income: £%.2f\n", running_total_monthly);

  if (has_savings) {
    printf("Savings: £%.2f\n", savings);
  }

  if (has_income)  {
    const float tax_monthly = calculate_taxes_paid_monthly();
    running_total_monthly -= tax_monthly;
    printf("[TAX] Expenditure: £%.2f | Running Total: £%.2f\n", tax_monthly, running_total_monthly);

    const float ni_monthly = calculate_ni_paid_monthly();
    running_total_monthly -= ni_monthly;
    printf("[NI] Expenditure: £%.2f | Running Total: £%.2f\n", ni_monthly, running_total_monthly);
  } 

  if (has_council_tax) {
    const float council_tax_monthly = calculate_council_tax_paid_monthly();
    running_total_monthly -= council_tax_monthly;
    printf("[COUNCIL TAX] Expenditure: £%.2f | Running Total: £%.2f\n", council_tax_monthly, running_total_monthly);
  }

  if (has_rent) {
    running_total_monthly -= rent_monthly;
    printf("[RENT] Expenditure: £%.2f | Running Total: £%.2f\n", rent_monthly, running_total_monthly);
  }

  if (has_utils) {
    running_total_monthly -= utils_monthly;
    printf("[UTILS] Expenditure: £%.2f | Running Total: £%.2f\n", utils_monthly, running_total_monthly);
  }
  if (has_groceries) {
    running_total_monthly -= groceries_monthly;
    printf("[GROCERIES] Expenditure: £%.2f | Running Total: £%.2f\n", groceries_monthly, running_total_monthly);
  }

  printf("Ending Monthly Total: £%.2f\n", running_total_monthly);
}