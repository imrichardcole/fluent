#include <cmath>

namespace fluent {
double discount(double duration, double rate) {
  return 1 / std::pow(1 + rate, duration);
}

double discount_future_cashflow(double amount, double duration, double rate) {
  return amount / std::pow(1 + rate, duration);
}
}  // namespace fluent