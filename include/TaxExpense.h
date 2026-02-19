#pragma once

#include "IExpense.h"
#include "Thresholds.h"

#include <string>
#include <utility>
#include <vector>

class TaxExpense : public IExpense
{
  std::string id;
  std::vector<float> upper_bounds;
  std::vector<float> tax_rates;

public:
  TaxExpense(std::string id, std::vector<float> upper_bounds, std::vector<float> tax_rates) :
    id(std::move(id)),
    upper_bounds(std::move(upper_bounds)),
    tax_rates(std::move(tax_rates))
  {
  }

  const std::string& get_id() const override
  {
    return id;
  }

  float get_monthly_cost(float yearly_income) const override
  {
    if (yearly_income <= 0.f) {
      return 0.f;
    }

    Thresholds thresholds(upper_bounds, tax_rates);
    return thresholds.calculate_tax(yearly_income) / 12.f;
  }
};
