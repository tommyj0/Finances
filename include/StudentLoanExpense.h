#pragma once

#include "IExpense.h"
#include "Thresholds.h"

#include <algorithm>
#include <string>

class StudentLoanExpense : public IExpense
{
  std::string id;
  float total_owed;

public:
  explicit StudentLoanExpense(float total_owed) :
    id("STUDENT LOAN"),
    total_owed(total_owed)
  {
  }

  const std::string& get_id() const override
  {
    return id;
  }

  float get_monthly_cost(float yearly_income) const override
  {
    if (total_owed <= 0.f || yearly_income <= 0.f) {
      return 0.f;
    }

    Thresholds student_loan_thresholds({12.f * 2728.f, 100000000.f}, {0.f, 0.09f});
    const float monthly_payment = student_loan_thresholds.calculate_tax(yearly_income) / 12.f;
    return std::min(monthly_payment, total_owed);
  }
};
