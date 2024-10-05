#include "date.hpp"
#include "calendar.hpp"

#include <gtest/gtest.h>

TEST(calendar, advance_days)
{
    fluent::Date start_date(5, fluent::October, 2024);
    fluent::Calendar calander;
    fluent::Date advanced_date = calander.advance(10, start_date);
    ASSERT_EQ(advanced_date, fluent::Date(15, fluent::October, 2024));
}

TEST(calendar, advance_days_into_next_month)
{
    fluent::Date start_date(5, fluent::October, 2024);
    fluent::Calendar calander;
    fluent::Date advanced_date = calander.advance(30, start_date);
    ASSERT_EQ(advanced_date, fluent::Date(5, fluent::November, 2024));
}

TEST(calendar, advance_days_into_next_year)
{
    fluent::Date start_date(15, fluent::December, 2024);
    fluent::Calendar calander;
    fluent::Date advanced_date = calander.advance(30, start_date);
    ASSERT_EQ(advanced_date, fluent::Date(15, fluent::January, 2025));
}
