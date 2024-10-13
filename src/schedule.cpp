#include "schedule.h"

namespace fluent {

Schedule::Schedule(fluent::Frequency frequency, fluent::Date start_date,
                   fluent::Date end_date) {
  _frequency = frequency;
  _start_date = start_date;
  _end_date = end_date;

  _cashflows.push_back(fluent::Cashflow(1000, _start_date));
  _cashflows.push_back(fluent::Cashflow(1000, _end_date));
}

fluent::Date Schedule::next_date(fluent::Date date) { return date; }

std::vector<fluent::Cashflow> Schedule::get_cashflows(fluent::Date date) {
  date.get_longdate();
  return _cashflows;
}

}  // namespace fluent