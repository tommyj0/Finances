#pragma once

#include <stdexcept>
#include <vector>

class CouncilTaxBands {
  struct Band {
    char name;
    float tax_yearly;
  };
  std::vector<Band> bands;
public:
  CouncilTaxBands(std::vector<char> names, std::vector<float> tax_yearly)
  {
    for (size_t i = 0; i < names.size(); ++i) {
      bands.push_back({names[i], tax_yearly[i]});
    }
  }

  float calculate_tax(char band_name)
  {
    for (const auto& band : this->bands) {
      if (band.name == band_name) {
        return band.tax_yearly;
      }
    }
    throw std::invalid_argument("Band name not found");
  }
};