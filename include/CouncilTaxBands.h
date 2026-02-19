#include <vector>

class CouncilTaxBands {
  struct Band {
    char name;
    float tax_yearly;
  };
  std::vector<Band> bands;
public:
  CouncilTaxBands(std::vector<char> names, std::vector<float> tax_yearly);
  float calculate_tax(char band_name);
};