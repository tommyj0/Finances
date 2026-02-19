#pragma once

#include "CouncilTaxBands.h"
#include "IExpense.h"

#include <string>

class CouncilTaxExpense : public IExpense
{
  std::string id;
  char band;

public:
  explicit CouncilTaxExpense(char band) :
    id("COUNCIL TAX"),
    band(band)
  {
  }

  const std::string& get_id() const override
  {
    return id;
  }

  float get_monthly_cost(float /*yearly_income*/) const override
  {
    CouncilTaxBands council_tax_bands(
      {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
      {1455.36f, 1697.91f, 1940.46f, 2183.03f, 2668.14f, 3153.26f, 3638.39f, 4366.06f}
    );

    return council_tax_bands.calculate_tax(band) / 12.f;
  }
};
