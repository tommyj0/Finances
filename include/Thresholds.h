#include <vector>

class Thresholds {
private:
  // implied that they are in order
  struct TaxBracket {
    float upper_bound;
    float tax_rate;
  };
  std::vector<TaxBracket> brackets;

public:
  Thresholds(std::vector<float> upper_bounds, std::vector<float> tax_rates);
  float calculate_tax(float income);
};
