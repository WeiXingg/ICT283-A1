#include "Date.h"
#include "Windlog.h"
#include "Vector.h"
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>

// Forward declarations
void Menu(Vector<Windlog>& windLog);
bool InputFile(Vector<Windlog>& data);
int CheckYearInput();
int CheckMonthInput();
const string CheckMonth(const int month);
Vector<Windlog> FilterByYear(Vector<Windlog>& data, int yearInput);
Vector<Windlog> FilterByMonth(Vector<Windlog>& data, int monthInput);
double CalculateAvgSpeed(Vector<Windlog>& data);
double CalculateAvgTemperature(Vector<Windlog>& data);
double CalculateTotalSolarRadiation(Vector<Windlog>& data);
void OptionOne(Vector<Windlog>& windLog);
void OptionTwo(Vector<Windlog>& windLog);
void OptionThree(Vector<Windlog>& windLog);
void OptionFour(Vector<Windlog>& windLog);

int main()
{
    Vector<Windlog> windLog;
    if (InputFile(windLog)) //To check if file is successfully loaded
    {
        Menu(windLog);
    }
    return 0;
}

void Menu(Vector<Windlog>& windLog)
{
    int input;
    bool flag = true;
    while(flag) // To keep the program running until user selects exit
    {
        cout << "The program will keep running until you choose to exit.\n" << endl
             << "Choose from option 1 to 5." << endl
             << "1. View the average wind speed and ambient air temperature for a specified month and year." << endl
             << "2. View average wind speed and ambient air temperature for each month of a specified year." << endl
             << "3. View total solar radiation in kWh/m2 for each month of a specified year." << endl
             << "4. Write to a file for the average wind speed in km/h, average ambient air temperature and total solar "
             "radiation in \n   kWh/m2 for each month of a specified year." << endl
             << "5. Exit the program." << endl;
        cout << "\nYour option: " << endl;
        cin >> input;
        while (input < 1 || input > 5) // Validation of user input
        {
            cout << "\nEnter a valid response:" << endl;
            cin.clear();
            cin.ignore(123, '\n');
            cin >> input;
        }
        switch (input) // Switch case for user input
        {
        case 1:
            OptionOne(windLog);
            break;

        case 2:
            OptionTwo(windLog);
            break;

        case 3:
            OptionThree(windLog);
            break;

        case 4:
            OptionFour(windLog);
            break;

        case 5:
            cout << "\nThe program will end." << endl;
            flag = false;
            break;

        default:
            break;
        }
    }

}

bool InputFile(Vector<Windlog>& data)
{
    //ifstream infile("MetData-31-3a.csv"); // commented out as used for main testing only
    ifstream infile("MetData_Mar01-2015-Mar01-2016-ALL.csv");
    if (!infile)
    {
        cout << "File not found. Please ensure file name is correct and run program again" << endl;
        return false;
    }
    Windlog tempWindlog;
    string tempString;
    getline(infile, tempString, '\n'); // Skip first line in input file
    while (getline(infile, tempString, '\n')) // Loop through every line in file
    {
        if (tempString.empty()) // Check for empty line
        {
            getline(infile, tempString, '\n'); // Skip empty line
        }
        else
        {
            stringstream (tempString) >> tempWindlog; // Add data into object
            data.Add(tempWindlog); // Add object into vector
        }
    }
    return true;
}

int CheckYearInput() // Validation for year input by user
{
    int yearInput;
    cout << "\nEnter year: " << endl;
    cin >> yearInput;
    while (yearInput < 1000 || yearInput > 9999)
    {
        cout << "\nEnter a valid year:" << endl;
        cin.clear();
        cin.ignore(123, '\n');
        cin >> yearInput;
    }
    return yearInput;
}

int CheckMonthInput() // Validation for month input by user
{
    int monthInput;
    cout << "\nEnter month: " << endl;
    cout << "(Enter 1-12 e.g 1 for January)" << endl;
    cin >> monthInput;
    while (monthInput < 1 || monthInput > 12)
    {
        cout << "\nEnter a valid month:" << endl;
        cin.clear();
        cin.ignore(123, '\n');
        cin >> monthInput;
    }
    return monthInput;
}

const string CheckMonth(const int month) // Constant string for list of months
{
    if(month <= 0 || month >= 13) // Ensure month is within range
        return "";
    string MONTH_STR[] = {"January", "February", "March", "April", "May", "June", "July", "August",
                          "September", "October", "November", "December"};
    return MONTH_STR[month - 1];
}

Vector<Windlog> FilterByYear(Vector<Windlog>& data, int yearInput)
{
    Vector<Windlog> result;
    Date tempDate;
    for(unsigned i = 0; i < data.GetSize(); i++)
    {
        data.At(i).GetDate(tempDate); // Retrieve date based on year input
        int year = tempDate.GetYear(); // Retrieve year
        if (yearInput == year) // Match user input
        {
            result.Add(data.At(i)); // If match, add the data into vector
        }
    }
    return result;
}

Vector<Windlog> FilterByMonth(Vector<Windlog>& data, int monthInput)
{
    Vector<Windlog> result;
    Date tempDate;
    for(unsigned i = 0; i < data.GetSize(); i++)
    {
        data.At(i).GetDate(tempDate); // Retrieve date based on month input
        int month = stoi(tempDate.GetMonth()); // Retrieve month
        if (monthInput == month) // Match user input
        {
            result.Add(data.At(i)); // If match, add the data into vector
        }
    }
    return result;
}

double CalculateAvgSpeed(Vector<Windlog>& data)
{
    double avgSpeed = 0;
    for(unsigned i = 0; i < data.GetSize(); i++)
    {
        avgSpeed += data.At(i).GetWindSpeed();
    }
    return avgSpeed / data.GetSize() * 3.6; // Average speed in km/h
}

double CalculateAvgTemperature(Vector<Windlog>& data)
{
    double avgTemperature = 0;
    for(unsigned i = 0; i < data.GetSize(); i++)
    {
        avgTemperature += data.At(i).GetAirTemperature();
    }
    return avgTemperature / data.GetSize();
}

double CalculateTotalSolarRadiation(Vector<Windlog>& data)
{
    double totalSolarRadiation = 0;
    for(unsigned i = 0; i < data.GetSize(); i++)
    {
        if ((data.At(i).GetSolarRadiation()) >= 100)
            totalSolarRadiation += data.At(i).GetSolarRadiation();
    }
    return totalSolarRadiation / 1000; // Total solar radiation in kWh/m2
}

void OptionOne(Vector<Windlog>& windLog)
{
    int yearInput = CheckYearInput();
    int monthInput = CheckMonthInput();
    Vector<Windlog> tempWindlog = windLog; // create temp vector and copy main vector into it
    tempWindlog = FilterByYear(tempWindlog, yearInput); // Filter year according to user input and copy into temp vector
    tempWindlog = FilterByMonth(tempWindlog, monthInput); // Filter month according to user input and copy into temp vector
    double avgSpeed = CalculateAvgSpeed(tempWindlog); // Calculate average speed using temp vector
    double avgTemperature = CalculateAvgTemperature(tempWindlog); // Calculate average temperature using temp vector
    string outputMonth = CheckMonth(monthInput); // To retrieve month name from constant month string based on user input
    if (tempWindlog.GetSize() == 0)
    {
        cout << endl << outputMonth << " " << yearInput << ": No Data" << endl;
    }
    else
    {
        cout << '\n' << outputMonth << " " << yearInput << ": "
             << fixed << setprecision(1) << avgSpeed << " km/h, "
             << fixed << setprecision(1) << avgTemperature << " degrees C" << endl;
    }
    cout << endl;
}

void OptionTwo(Vector<Windlog>& windLog)
{
    int yearInput = CheckYearInput();
    Vector<Windlog> tempWindlog = windLog; // create temp vector and copy main vector into it
    Vector<Windlog> filteredResult;
    tempWindlog = FilterByYear(tempWindlog, yearInput); // Filter year according to user input and copy into temp vector
    if (tempWindlog.GetSize() == 0 )
    {
        cout << "\n" << yearInput << "\nNo Data" << endl;
    }
    else
    {
        cout << endl << yearInput << endl;
        for(int i = 1; i <= 12; i++)
        {
            filteredResult = FilterByMonth(tempWindlog, i); // Filter month according to current index and copy into another temp vector
            double avgSpeed = CalculateAvgSpeed(filteredResult); // Calculate average speed using temp vector
            double avgTemperature = CalculateAvgTemperature(filteredResult); // Calculate average temperature using temp vector
            string outputMonth = CheckMonth(i); // To retrieve month name from constant month string based on current index
            if (filteredResult.GetSize() == 0)
            {
                cout << outputMonth << ": No Data" << endl;
            }
            else
            {
                cout << outputMonth << ": "
                     << fixed << setprecision(1) << avgSpeed << " km/h, "
                     << fixed << setprecision(1) << avgTemperature << " degrees C" << endl;
            }
        }
    }
    cout << endl;
}

void OptionThree(Vector<Windlog>& windLog)
{
    int yearInput = CheckYearInput();
    Vector<Windlog> tempWindlog = windLog; // create temp vector and copy main vector into it
    Vector<Windlog> filteredResult;
    tempWindlog = FilterByYear(tempWindlog, yearInput); // Filter year according to user input and copy into temp vector
    if (tempWindlog.GetSize() == 0 )
    {
        cout << "\n" << yearInput << "\nNo Data" << endl;
    }
    else
    {
        cout << endl << yearInput << endl;
        for(int i = 1; i <= 12; i++)
        {
            filteredResult = FilterByMonth(tempWindlog, i); // Filter month according to current index and copy into another temp vector
            double totalSolarRadiation = CalculateTotalSolarRadiation(filteredResult); // Calculate total solar radiation using temp vector
            string outputMonth = CheckMonth(i); // To retrieve month name from constant month string based on current index
            if (filteredResult.GetSize() == 0)
            {
                cout << outputMonth << ": No Data" << endl;
            }
            else
            {
                cout << outputMonth << ": "
                     << fixed << setprecision(1) << totalSolarRadiation << " kWh/m2" << endl;
            }
        }
    }
    cout << endl;
}

void OptionFour(Vector<Windlog>& windLog)
{
    ofstream ofile("WindTempSolar.csv");
    int yearInput = CheckYearInput();
    Vector<Windlog> tempWindlog = windLog; // create temp vector and copy main vector into it
    Vector<Windlog> filteredResult;
    tempWindlog = FilterByYear(tempWindlog, yearInput); // Filter year according to user input and copy into temp vector
    ofile << yearInput << endl;
    if (tempWindlog.GetSize() == 0 )
    {
        ofile << "No data" << endl;
    }
    else
    {
        for(int i = 1; i <= 12; i++)
        {
            filteredResult = FilterByMonth(tempWindlog, i); // Filter month according to current index and copy into another temp vector
            double avgSpeed = CalculateAvgSpeed(filteredResult); // Calculate average speed using temp vector
            double avgTemperature = CalculateAvgTemperature(filteredResult); // Calculate average temperature using temp vector
            double totalSolarRadiation = CalculateTotalSolarRadiation(filteredResult); // Calculate total solar radiation using temp vector
            string outputMonth = CheckMonth(i); // To retrieve month name from constant month string based on current index
            if (filteredResult.GetSize() != 0)
            {
                ofile << outputMonth << ","
                      << fixed << setprecision(1) << avgSpeed << ","
                      << fixed << setprecision(1) << avgTemperature << ","
                      << fixed << setprecision(1) << totalSolarRadiation << endl;
            }
        }
    }
    cout << "\nWindTempSolar.csv has been created\n" << endl;
}
