#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

	/**
	 * @class Time
	 * @brief  Manages the hour and minute only for time
	 *
	 * This class will only handle hours and minutes and not seconds or milliseconds.
	 *
	 * @author Wei Xing
	 * @version 01
	 * @date 15/06/2022 Wei Xing, Started
	 *
	 * @todo None for now
	 *
	 * @bug To the best of my knowledge, my program has no bugs
	 */

class Time
{
public:
    Time();
    Time(const unsigned hour, const unsigned minute);

        /**
         * Set hour
         * @param hour
         * @return None
         */
    void SetHour(const unsigned hour);

        /**
         * Set minute
         * @param minute
         * @return None
         */
    void SetMinute(const unsigned minute);

        /**
         * Get hour
         * @param None
         * @return m_hour
         */
    unsigned GetHour() const;

        /**
         * Get minute
         * @param None
         * @return m_minute
         */
    unsigned GetMinute() const;

private:
        /// Hour in numbers
    unsigned m_hour;

        /// Minute in numbers
    unsigned m_minute;
};

ostream & operator <<( ostream & os, const Time & T );
istream & operator >>( istream & input, Time & T );

#endif
