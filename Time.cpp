#include "Time.h"
#include <iomanip>

Time::Time() // Default constructor
{
    m_hour = 0;
    m_minute = 0;
}

Time::Time(const unsigned hour, const unsigned minute) // Parameterized constructor
{
    m_hour = hour;
    m_minute = minute;
}

void Time::SetHour(const unsigned hour) // Setter for  hour
{
    m_hour = hour;
}

void Time::SetMinute(const unsigned minute) // Setter for minute
{
    m_minute = minute;
}

unsigned Time::GetHour() const // Getter for hour
{
    return m_hour;
}

unsigned Time::GetMinute() const // Getter for minute
{
    return m_minute;
}

istream & operator >>( istream & input, Time & T )
{
    string hour, minute;
    getline(input, hour, ':');
    T.SetHour(stoi(hour));
    getline(input, minute, ',');
    T.SetMinute(stoi(minute));
    return input;
}

ostream & operator <<( ostream & os, const Time & T )
{
    os  << setfill('0') << setw(2) << T.GetHour() << ":"
        << setfill('0') << setw(2) << T.GetMinute();
    return os;
}
