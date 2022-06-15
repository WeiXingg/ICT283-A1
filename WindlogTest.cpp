#include "Windlog.h"

int main()
{
    cout << "TEST ID 1"
         << "\nConstructor, input and output stream test:" << endl;
    Date tempDate(5,"June",2022);
    Time tempTime(10,05);
    Windlog windLogTest(tempDate, tempTime, 10, 50, 10.22);
    cout << windLogTest << endl;

    cout << "\nTEST ID 2" // Setter and Getter check for date
         << "\nSet date test:" << endl;
    Date tempDate1(10,"July",2021);
    windLogTest.SetDate(tempDate1);
    cout << windLogTest << endl;
    cout << "Get date test:" << endl;
    Date tempDate2(15,"August",2020);
    cout << "Before GetDate(): " << tempDate2 << endl;
    windLogTest.GetDate(tempDate2);
    cout << "After GetDate(): " << tempDate2 << endl;

    cout << "\nTEST ID 3" // Setter and Getter check for time
         << "\nSet time test:" << endl;
    Time tempTime1(06,20);
    windLogTest.SetTime(tempTime1);
    cout << windLogTest << endl;
    cout << "Get time test:" << endl;
    Time tempTime2(17,55);
    cout << "Before GetTime(): " << tempTime2 << endl;
    windLogTest.GetTime(tempTime2);
    cout << "After GetTime(): " << tempTime2 << endl;

    cout << "\nTEST ID 4"
         << "\nSet and Get test for wind speed:" << endl;
    windLogTest.SetWindSpeed(20);
    cout << windLogTest.GetWindSpeed() << endl;

    cout << "\nTEST ID 5"
         << "\nSet and Get test for solar radiation:" << endl;
    windLogTest.SetSolarRadiation(100);
    cout << windLogTest.GetSolarRadiation() << endl;

    cout << "\nTEST ID 6"
         << "\nSet and Get test for air temperature:" << endl;
    windLogTest.SetAirTemperature(15.21);
    cout << windLogTest.GetAirTemperature() << endl;

    return 0;
}
