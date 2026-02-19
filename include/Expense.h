#pragma once

#include "IExpense.h"

#include <string>
#include <utility>

class Expense : public IExpense
{
  float monthly_cost = 0.f;
  std::string id;

public:
  Expense(std::string id, float monthly_cost) :
    monthly_cost(monthly_cost),
    id(std::move(id))
  {
  }

  void set_monthly_cost(float monthly_cost)
  {
    this->monthly_cost = monthly_cost;
  }

  const std::string& get_id() const override
  {
    return id;
  }

  float get_monthly_cost(float /*yearly_income*/) const override
  {
    return monthly_cost;
  }
};