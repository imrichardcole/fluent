#include "date.hpp"
#include "frequency.hpp"

#include <gtest/gtest.h>

TEST(date, simple_date_creation)
{
    fluent::Date date(5, fluent::October, 2024);
    ASSERT_EQ(date.get_longdate(), 20241005);
}

TEST(date, from_longdate)
{
    fluent::Date date(19821130);
    ASSERT_EQ(date.get_day(), 30);
    ASSERT_EQ(date.get_month(), 11);
    ASSERT_EQ(date.get_year(), 1982);
    ASSERT_EQ(date.get_longdate(), 19821130);
}