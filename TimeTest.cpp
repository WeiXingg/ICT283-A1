#include "Time.h"

int main()
{
    cout << "TEST ID 1"
         << "\nConstructor, input and output stream test:" << endl;
    Time timeTest(10, 05);
    cout << timeTest << endl;

    cout << "\nTEST ID 2"
         << "\nSet and Get test for hour:" << endl;
    timeTest.SetHour(22);
    cout << timeTest.GetHour() << endl;

    cout << "\nTEST ID 3"
         << "\nSet and Get test for minute:" << endl;
    timeTest.SetMinute(55);
    cout << timeTest.GetMinute() << endl;

    return 0;
}
