#include "Finances.h"
#include "secret_financial_info.h"

// example usage
int main(int argc, char* argv[])
{

  Finances finances(yearly_income, savings); // £30,000 yearly income, £10,000 savings
  finances.set_rent_monthly(1000.f); // £1,200 monthly rent
  finances.set_utils_monthly(150.f); // £150 monthly utilities
  finances.set_council_tax_band('D'); // council tax band D
  finances.set_groceries_monthly(200.f); // £200 monthly groceries
  
  finances.print_summary();
  return 0;
}