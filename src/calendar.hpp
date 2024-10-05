#pragma once

#include "date.hpp"

namespace fluent
{
    class Calendar
    {
    public:
        fluent::Date advance(int days, fluent::Date from_date)
        {
            long from_date_longdate = from_date.get_longdate();
            long advanced_longdate = from_date_longdate + days;
            return Date(advanced_longdate);
        }

    private:
        bool _include_weekends;
    };
}