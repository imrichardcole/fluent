#include "cashflow.h"
#include "schedule.h"
#include "date.hpp"

#include <gtest/gtest.h>

TEST(schedule, simple_schedule_creation)
{
    fluent::Date start_date(5, fluent::October, 2024);
    fluent::Date end_date(5, fluent::October, 2025);
    fluent::Schedule schedule(fluent::ANNUAL, start_date, end_date);

    std::vector<fluent::Cashflow> cashflows = schedule.get_cashflows(start_date);
    ASSERT_EQ(cashflows.size(), 2);
}
