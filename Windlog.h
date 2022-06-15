#ifndef WINDLOG_H_INCLUDED
#define WINDLOG_H_INCLUDED
#include "Date.h"
#include "Time.h"

#include <iostream>
#include <string>

using namespace std;

	/**
	 * @class Windlog
	 * @brief  Manages date and time object and additional variables needed
	 *
	 * A Windlog class created specifically to handle date and time objects with additional variable of
	 * wind speed, solar radiation and air temperature.
	 *
	 * @author Wei Xing
	 * @version 01
	 * @date 15/06/2022 Wei Xing, Started
	 *
	 * @todo None for now
	 *
	 * @bug To the best of my knowledge, my program has no bugs
	 */

class Windlog
{
public:
    Windlog();
    Windlog(const Date& date, const Time& time, const unsigned windSpeed,
            const unsigned solarRadiation, const double airTemperature);

        /**
         * Set date object
         * @param date object
         * @return m_date
         */
    void SetDate(const Date& date);

        /**
         * Set time object
         * @param time object
         * @return m_time
         */
    void SetTime(const Time& time);

        /**
         * Set wind speed
         * @param windSpeed
         * @return m_windSpeed
         */
    void SetWindSpeed(const unsigned windSpeed);

        /**
         * Set solar radiation
         * @param solarRadiation
         * @return m_solarRadiation
         */
    void SetSolarRadiation(const unsigned solarRadiation);

        /**
         * Set airTemperature
         * @param airTemperature
         * @return m_airTemperature
         */
    void SetAirTemperature(const double airTemperature);

        /**
         * Get date object
         * @param m_date
         * @return date
         */
    void GetDate(Date& date) const;

        /**
         * Get time object
         * @param m_time
         * @return time
         */
    void GetTime(Time& time) const;

        /**
         * Get wind speed
         * @param None
         * @return m_windSpeed
         */
    unsigned GetWindSpeed() const;

        /**
         * Get solar radiation
         * @param None
         * @return m_solarRadiation
         */
    unsigned GetSolarRadiation() const;

        /**
         * Get air temperature
         * @param None
         * @return m_airTemperature
         */
    double GetAirTemperature() const;

private:
        /// Date object
    Date m_date;
        /// Time object
    Time m_time;
        /// Wind Speed
    unsigned m_windSpeed;
        /// Solar Radiation
    unsigned m_solarRadiation;
        /// Air Temperature
    double m_airTemperature;
};

ostream & operator <<( ostream & os, const Windlog & wl );
istream & operator >>( istream & input, Windlog & wl );

#endif
