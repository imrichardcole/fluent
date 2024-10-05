#include "cashflow.h"
#include "schedule.h"
#include "date.hpp"

#include <gtest/gtest.h>

TEST(cashflows, simple_cashflow_creation)
{
    fluent::Date today(1, fluent::October, 2024);
    fluent::Cashflow flow(1000.0, today);
}

TEST(cashflows, other)
{
    fluent::Date start_date(5, fluent::October, 2024);
    fluent::Date end_date(5, fluent::October, 2026);

    fluent::Schedule schedule(fluent::ANNUAL, start_date, end_date);
    fluent::Date today(1, fluent::October, 2024);

    fluent::Date next_date = schedule.next_date(today);
}
