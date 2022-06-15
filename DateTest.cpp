#include "Date.h"

int main()
{
    cout << "TEST ID 1"
         << "\nConstructor, input and output stream test:" << endl;
    Date dateTest(5, "June", 2022);
    cout << dateTest << endl;

    cout << "\nTEST ID 2"
         << "\nSet and Get test for day:" << endl;
    dateTest.SetDay(1);
    cout << dateTest.GetDay() << endl;

    cout << "\nTEST ID 3"
         << "\nSet and Get test for month:" << endl;
    dateTest.SetMonth("January");
    cout << dateTest.GetMonth() << endl;

    cout << "\nTEST ID 4"
         << "\nSet and Get test for year:" << endl;
    dateTest.SetYear(2021);
    cout << dateTest.GetYear() << endl;

    return 0;
}
