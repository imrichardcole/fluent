#include "cashflow.h"
#include "schedule.h"
#include "date.hpp"
#include "fixed_bond.h"
#include "discounting.hpp"

#include <numeric>       

#include <gtest/gtest.h>

TEST(bonds, price_at_issuance)
{
    double face_value = 100.0;
    double coupon_rate = 0.05;
    auto frequency = fluent::Frequency::ANNUAL;
    int maturity = 7.0;
    fluent::FixedBond bond(face_value, coupon_rate, frequency, maturity);
    double price = bond.price();
    ASSERT_EQ(price, 100.0);
}

TEST(bonds, cashflows)
{
    double face_value = 100.0;
    double coupon_rate = 0.05;
    auto frequency = fluent::Frequency::ANNUAL;
    int maturity = 5.0;
    fluent::FixedBond bond(face_value, coupon_rate, frequency, maturity);

    std::vector<fluent::Cashflow> cashflows = bond.get_cashflows();
    ASSERT_EQ(cashflows.size(), 5);
    ASSERT_NEAR(cashflows.at(0).get_amount(), 4.762, 0.001);
    ASSERT_NEAR(cashflows.at(1).get_amount(), 4.535, 0.001);
    ASSERT_NEAR(cashflows.at(2).get_amount(), 4.319, 0.001);
    ASSERT_NEAR(cashflows.at(3).get_amount(), 4.114, 0.001);
    ASSERT_NEAR(cashflows.at(4).get_amount(), 82.270, 0.001);
}

TEST(bonds, cashflows_ex)
{
    double face_value = 100.0;
    double coupon_rate = 0.05;
    auto frequency = fluent::Frequency::ANNUAL;
    int maturity = 5.0;
    fluent::FixedBond bond(face_value, coupon_rate, frequency, maturity);

    std::vector<fluent::Cashflow> cashflows = bond.get_cashflows(0.025);
    ASSERT_EQ(cashflows.size(), 5);
    ASSERT_NEAR(cashflows.at(0).get_amount(), 4.878, 0.001);
    ASSERT_NEAR(cashflows.at(1).get_amount(), 4.759, 0.001);
    ASSERT_NEAR(cashflows.at(2).get_amount(), 4.643, 0.001);
    ASSERT_NEAR(cashflows.at(3).get_amount(), 4.530, 0.001);
    ASSERT_NEAR(cashflows.at(4).get_amount(), 92.805, 0.001);

    double price = 0.0;
    for (auto cashflow : cashflows)
    {
        price += cashflow.get_amount();
    }
    ASSERT_NEAR(price, 111.61, 0.01);
}

TEST(bonds, ytm)
{
    double face_value = 1000.0;
    double coupon_rate = 0.15;
    auto frequency = fluent::Frequency::ANNUAL;
    int maturity = 7.0;
    fluent::FixedBond bond(face_value, coupon_rate, frequency, maturity);
    double ytm = bond.ytm(850.0);
    ASSERT_NEAR(ytm, 0.1853, 0.005);
}