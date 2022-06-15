#include <iostream>
#include <string>
#include "Vector.h"
#include "Date.h"

using namespace std;

int main()
{
    /*
    // Checking of GetAllocation method
    Vector<int> intVector;
    cout << "TEST ID 1:"
         << "\nAllocated space for int vector: " << intVector.GetAllocation() << endl;

    // Checking of GetSize method
    cout << "\nTEST ID 2:"
         << "\nNumber of element in int vector: " << intVector.GetSize() << endl;

    // Checking of Add method
    intVector.Add(1);
    intVector.Add(2);
    intVector.Add(3);
    cout << "\nTEST ID 3:"
         << "\nAllocated space with 3 elements: " << intVector.GetAllocation() << endl;
    intVector.Add(4);
    cout << "Allocated space after adding fourth element: " << intVector.GetAllocation() << endl;

    // Checking of At method
    cout << "\nTEST ID 4:"
         << "\nPrinting whole vector" << endl;
    for (unsigned i = 0; i < intVector.GetSize(); i++)
    {
        cout << intVector.At(i) << endl;
    }

    // Checking of Remove method
    cout << "\nTEST ID 5:"
         << "\nElement at index 2: " << intVector.At(2) << endl;
    cout << "Number of element in int vector: " << intVector.GetSize() << endl;
    intVector.Remove(2);
    cout << "Element at index 2 after removing element at index 2: " << intVector.At(2) << endl;
    cout << "Number of element in int vector: " << intVector.GetSize() << endl;

    // Testing for deep copying
    cout << "\nTEST ID 6:" << endl;
    Vector<int> intVector1;
    intVector1.Add(50);
    intVector1.Add(100);
    intVector1.Add(200);
    intVector1.Add(400);
    cout << "Vector 1: " << intVector1.At(0) << endl;
    cout << "Vector 1: " << intVector1.At(1) << endl;
    cout << "Vector 1: " << intVector1.At(2) << endl;
    cout << "Vector 1: " << intVector1.At(3) << endl;
    cout << "Vector 1 address: " << &intVector1 << endl;
    Vector<int> intVector2;
    intVector2 = intVector1;
    cout << "\nVector 2: " << intVector2.At(0) << endl;
    cout << "Vector 2: " << intVector2.At(1) << endl;
    cout << "Vector 2: " << intVector2.At(2) << endl;
    cout << "Vector 2: " << intVector2.At(3) << endl;
    cout << "Vector 2 address: " << &intVector2 << endl;
    Vector<int> intVector3(intVector1);
    cout << "\nVector 3: " << intVector3.At(0) << endl;
    cout << "Vector 3: " << intVector3.At(1) << endl;
    cout << "Vector 3: " << intVector2.At(2) << endl;
    cout << "Vector 3: " << intVector2.At(3) << endl;
    cout << "Vector 3 address: " << &intVector3 << endl;

    // Check if vector able to store another data type
    Vector<string> strVector;
    cout << "\nTEST 7:"
         << "\nAllocated space for str vector: " << strVector.GetAllocation() << endl
         << "Number of element in str vector: " << strVector.GetSize() << endl;
    strVector.Add("Hello World");
    cout << "After adding: " << strVector.At(0) << endl
         << "Number of element in str vector: " << strVector.GetSize() << endl;*/

    Date date1(1,"2",2022);
    Date date2(2,"3",2022);
    Vector<Date> dateVec1;
    dateVec1.Add(date1);
    dateVec1.Add(date2);
    cout << "Address of date 1: " << &date1 << endl;
    cout << "Address of date 2: " << &date2 << endl;
    cout << "Address of date 1 in vec 1: " << &dateVec1.At(0) << endl;
    cout << "Address of date 2 in vec 1: " << &dateVec1.At(1) << endl;
    Vector<Date> dateVec2(dateVec1);
    cout << "Address of date 1 in vec 2: " << &dateVec2.At(0) << endl;
    cout << "Address of date 2 in vec 2: " << &dateVec2.At(1) << endl;

    return 0;
}
