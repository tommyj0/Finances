#include "CouncilTaxBands.h"
#include <stdexcept>
#include <vector>



CouncilTaxBands::CouncilTaxBands(std::vector<char> names, std::vector<float> tax_yearly)
{
  for (size_t i = 0; i < names.size(); ++i) {
    bands.push_back({names[i], tax_yearly[i]});
  }
}

float CouncilTaxBands::calculate_tax(char band_name)
{
  for (const auto& band : this->bands) {
    if (band.name == band_name) {
      return band.tax_yearly;
    }
  }
  // throw an error if not found
  throw std::invalid_argument("Band name not found");

}