#include "Expense.h"

Expense::Expense(float monthly_cost) : monthly_cost(monthly_cost)
{

}

Expense::set_monthly_cost(float monthly_cost)
{
  this->monthly_cost = monthly_cost;
}

float Expense::get_monthly_cost()
{
  return monthly_cost;
}