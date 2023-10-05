#include <iostream>
#include <fstream>
using namespace std;

bool validateEmail(const string &email)
{
    size_t atPos = email.find('@');
    size_t dotPos = email.rfind('.');
    return (atPos != string::npos && dotPos != string::npos && dotPos > atPos);
}

int newStudent()
{
    ofstream login("login.txt", ios::app);
    if (login.is_open())
    {
        int count, number;
        string name, gmail;
        cout << "How many new students to add?:";
        cin >> count;
        for (int i = 1; i <= count; i++)
        {
            cout << "\nStudent No." << i;
            cout << "\nStudent Name: ";
            cin.ignore();
            getline(cin, name);
            bool validEmail = false;
            while (!validEmail)
            {
                cout << "Gmail: ";
                cin >> gmail;
                if (!validateEmail(gmail))
                {
                    cout << "Invalid email address. Please enter a valid email address." << endl;
                }
                else
                {
                    validEmail = true;
                }
            }
            cout << "Contact Number: ";
            cin >> number;

            login << endl
                  << "Student Name: " << name << endl;
            login << "Gmail: " << gmail << endl;
            login << "Contact Number: " << number << endl;
        }
        login.close();
    }
    else
    {
        cout << "Error opening the file for writing." << endl;
    }
}

int main()
{
    cout << "********** MISERY LIBRARY MANAGEMENT SYSTEM **********\n";
    cout << ">>Choose any option to get started with:\n";
    cout << "1. New Student\n";
    newStudent();
}
