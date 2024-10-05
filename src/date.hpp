#pragma once

#include "frequency.hpp"

#include <string>
#include <sstream>
#include <iostream>

namespace fluent
{
	enum Month
	{
		January = 1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December
	};

	class Date
	{
	public:
		Date(const int day, const Month month, const int year)
		{
			_day = day;
			_month = month;
			_year = year;
			std::stringstream date_stream;
			date_stream << year;

			if (_month < 10)
			{
				date_stream << "0" << _month;
			}
			else {
				date_stream << _month;
			}

			if (_day < 10)
			{
				date_stream << "0" << _day;
			}
			else {
				date_stream << _day;
			}
			std::string longdate_string = date_stream.str();
			_longdate = atoi(longdate_string.c_str());
		}

		Date(const long longdate)
		{
			_longdate = longdate;
			_day = longdate % 100;
			_month = static_cast<Month>(((longdate % 10000) - _day) / 100);
			_year = (longdate - (longdate % 10000)) / 10000;
		}

		Date() : _day(1), _month(January), _year(1900), _longdate(19000101) {};

		friend void PrintTo(const Date& date, std::ostream* os) {
			*os << "(" << date._longdate << ")";
		}

		friend bool operator==(const Date& lhs, const Date& rhs)
		{
			return lhs._longdate == rhs._longdate;
		}

		int const get_day()
		{
			return _day;
		}

		Month const get_month()
		{
			return _month;
		}

		int const get_year()
		{
			return _year;
		}

		int const get_longdate()
		{
			return _longdate;
		}

	private:
		int _day;
		Month _month;
		int _year;
		int _longdate;
	};

}