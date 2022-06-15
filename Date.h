#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

	/**
	 * @class Date
	 * @brief  Manages the day, month and year
	 *
	 * This class will handle the day in numbers, months in alphabets and years in numbers.
	 *
	 * @author Wei Xing
	 * @version 01
	 * @date 08/06/2022 Wei Xing, Started
	 *
	 * @todo None for now
	 *
	 * @bug To the best of my knowledge, my program has no bugs
	 */

class Date
{
public:
    Date();
    Date(const int day, const string month, const int year);

        /**
         * Set day
         * @param day
         * @return None
         */
    void SetDay(const int day);

        /**
         * Set month
         * @param month
         * @return None
         */
    void SetMonth(const string month);

        /**
         * Set year
         * @param year
         * @return None
         */
    void SetYear(const int year);

        /**
         * Return day
         * @param None
         * @return m_day
         */
    int GetDay() const;

        /**
         * Return month
         * @param None
         * @return m_month
         */
    string GetMonth() const;

        /**
         * Return year
         * @param None
         * @return m_year
         */
    int GetYear() const;

private:
        /// Day in numbers
    int m_day;

        /// Month in alphabets
    string m_month;

        /// Year in numbers
    int m_year;

};

ostream & operator <<( ostream & os, const Date & D );
istream & operator >>( istream & input, Date & D );

#endif
