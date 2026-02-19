#pragma once

#include <string>

class IExpense
{
public:
  virtual ~IExpense() = default;
  virtual const std::string& get_id() const = 0;
  virtual float get_monthly_cost(float yearly_income) const = 0;
};
