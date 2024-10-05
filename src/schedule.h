#pragma once

#include "date.hpp"
#include "frequency.hpp"
#include "cashflow.h"

#include <vector>

namespace fluent
{
    class Schedule
    {
    public:
        Schedule(fluent::Frequency frequency,
            fluent::Date start_date,
            fluent::Date end_date
        );

        fluent::Date next_date(fluent::Date date);
        std::vector<fluent::Cashflow> get_cashflows(fluent::Date date);
    private:
        fluent::Frequency _frequency;
        fluent::Date _start_date;
        fluent::Date _end_date;
        std::vector<fluent::Cashflow> _cashflows;
    };
}
