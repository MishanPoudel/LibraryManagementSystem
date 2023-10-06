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

void newBook()
{
    ofstream books("books.txt", ios::app);
    if (books.is_open())
    {
        int id, price, year;
        string name, publisher;
        cout << "How many books to add?:";
        cin >> count;
        for (int i = 1; i <= count; i++)
        {
            cout << "Book ID: ";
            cin >> id;

            cout << "Book Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Publisher: ";
            getline(cin, publisher);

            cout << "Price: ";
            cin >> price;

            cout << "Publication Year: ";
            cin >> year;

            books << endl
                  << "Book ID: " << id << endl;
            books << "Name: " << name << endl;
            books << "Publisher: " << publisher << endl;
            books << "Price: " << price << endl;
            books << "Year: " << year << endl;

            cout << "Book information added successfully!" << endl;
        }
    }
    else
    {
        cout << "Error opening the file for writing." << endl;
    }

    books.close();
}

int main()
{
    cout << "********** MISERY LIBRARY MANAGEMENT SYSTEM **********\n";
    cout << ">>Choose any option to get started with:\n";
    cout << "1. New Student\n"
         << "2. New Book\n"
         << "2. \n"
         << "2. New Book\n";
    // newStudent();
    newBook();
}
