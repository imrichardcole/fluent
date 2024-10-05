#pragma once

#include "date.hpp"
#include "cashflow.h"
#include "schedule.h"

namespace fluent
{

	class FixedBond
	{
	public: 
		FixedBond(double face_value, double coupon_rate, fluent::Frequency frequency, int maturity) : 
			_face_value(face_value),
			_coupon_rate(coupon_rate),
			_frequency(frequency),
			_maturity(maturity) {};

		double price();

		double ytm(double price);
		std::vector<fluent::Cashflow> get_cashflows();
		std::vector<fluent::Cashflow> get_cashflows(double required_return);
	private:
		double _face_value;
		double _coupon_rate;
		fluent::Frequency _frequency;
		int _maturity;
	};

}