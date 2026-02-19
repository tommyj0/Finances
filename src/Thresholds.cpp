#include "Thresholds.h"

#include <algorithm>

Thresholds::Thresholds(std::vector<float> upper_bounds, std::vector<float> tax_rates)
{
  for (size_t i = 0; i < upper_bounds.size(); ++i) {
    brackets.push_back({upper_bounds[i], tax_rates[i]});
  }
}

float Thresholds::calculate_tax(float income)
{
  float tax = 0.f;
  float remaining_income = income;
  
  for (const auto& bracket : brackets) {
    if (remaining_income <= 0.f) {
      break;
    }
    
    float taxable_amount = std::min(remaining_income, bracket.upper_bound);
    tax += taxable_amount * bracket.tax_rate;
    remaining_income -= taxable_amount;
  }
  
  return tax;
}
