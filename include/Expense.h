class Expense
{
  monthly_cost = 0.f;
public:
  virtual float get_monthly_cost();
  virtual float set_monthly_cost(float monthly_cost);
  Expense(float monthly_cost);
};