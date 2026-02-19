class Finances {
private:
  float savings = 0.f;
  float income_yearly = 0.f;
  float income_monthly = 0.f;
  float utils_monthly = 0.f;
  float rent_monthly = 0.f;
  float mortgage_monthly = 0.f;
  float council_tax_monthly = 0.f;
  float student_loan_monthly = 0.f;
  float groceries_monthly = 0.f;
  float subscriptions_monthly = 0.f;
  
  bool has_income = false;
  bool has_car = false;
  bool has_utils = false;
  bool has_rent = false;
  bool has_mortgage = false;
  bool has_council_tax = false;
  bool has_savings = false;
  bool has_student_loan = false;

  char council_tax_band = 'D'; // default to D, which is the average band in the UK
  

  float calculate_taxes_paid_monthly();
  float calculate_ni_paid_monthly();
  float calculate_council_tax_paid_monthly();
  float calculate_student_loan_paid_monthly();
  
  
public:
  Finances(float income_yearly, float savings);
  void set_utils_monthly(float utils_monthly);
  void set_rent_monthly(float rent_monthly);
  void set_mortgage_monthly(float mortgage_monthly);
  void set_subscriptions_monthly(float subscriptions_monthly);
  void set_groceries_monthly(float groceries_monthly);
  void set_council_tax_band(char council_tax_band);
  
  void print_summary();
};