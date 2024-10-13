#include "fixed_bond.h"

#include <cmath>

namespace fluent {

double FixedBond::price() {
  double price = (_coupon_rate * (_maturity / 365.0)) * _face_value;
  return price;
}

double FixedBond::ytm(double price) {
  double coupon_payment = _face_value * _coupon_rate;
  double x = (coupon_payment + (_face_value - price) / _maturity) /
             ((_face_value + price) / 2);
  return x;
}

std::vector<fluent::Cashflow> FixedBond::get_cashflows() {
  std::vector<fluent::Cashflow> cashflows;
  double coupon_amount = _face_value * _coupon_rate;
  for (int i = 1; i < _maturity + 1; i++) {
    if (i == (_maturity)) {
      coupon_amount += _face_value;
    }
    double discounted_cashflow = coupon_amount / pow(1 + _coupon_rate, i);
    fluent::Cashflow cashflow(discounted_cashflow,
                              fluent::Date(1, fluent::Month::February, 2024));
    cashflows.push_back(cashflow);
  }
  return cashflows;
}

std::vector<fluent::Cashflow> FixedBond::get_cashflows(double required_return) {
  std::vector<fluent::Cashflow> cashflows;
  double coupon_amount = _face_value * _coupon_rate;
  for (int i = 1; i < _maturity + 1; i++) {
    if (i == (_maturity)) {
      coupon_amount += _face_value;
    }
    double discounted_cashflow = coupon_amount / pow(1 + required_return, i);
    fluent::Cashflow cashflow(discounted_cashflow,
                              fluent::Date(1, fluent::Month::February, 2024));
    cashflows.push_back(cashflow);
  }
  return cashflows;
}

}  // namespace fluent