#include "Date.h"

Date::Date() // Default constructor
{
    m_day = 0;
    m_month = "";
    m_year = 0;
}

Date::Date(const int day, const string month, const int year) // Parameterized constructor
{
    m_day = day;
    m_month = month;
    m_year = year;
}

void Date::SetDay(const int day) // Setter for day
{
    m_day = day;
}

void Date::SetMonth(const string month) // Setter for month
{
    m_month = month;
}
void Date::SetYear(const int year) // // Setter for year
{
    m_year = year;
}

int Date::GetDay() const // Getter for day
{
    return m_day;
}

string Date::GetMonth() const // Getter for month
{
    return m_month;
}

int Date::GetYear() const // Getter for year
{
    return m_year;
}

istream & operator >>( istream & input, Date & D )
{
    string day, month, year;
    getline(input, day, '/');
    D.SetDay(stoi(day));
    getline(input, month, '/');
    D.SetMonth(month);
    getline(input, year, ' ');
    D.SetYear(stoi(year));
    return input;
}

ostream & operator <<( ostream & os, const Date & D )
{
    os  << D.GetDay() << "/" << D.GetMonth()
        << "/" << D.GetYear();
    return os;
}
