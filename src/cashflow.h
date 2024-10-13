#pragma once

#include "date.hpp"

namespace fluent {
class Cashflow {
 public:
  Cashflow(double amount, fluent::Date date);

  double get_amount() { return _amount; }

 private:
  double _amount;
  fluent::Date _date;
};
}  // namespace fluent