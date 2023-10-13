#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;

int count;
time_t now = time(0);
tm *current_time = localtime(&now);
int year = 1900 + current_time->tm_year;
int month = 1 + current_time->tm_mon;
int day = current_time->tm_mday;
int hour = current_time->tm_hour;
int minute = current_time->tm_min;
int second = current_time->tm_sec;

ofstream stats("statics.txt", ios::app);

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
        int number;
        string name, gmail;
        cout << "How many new students to add?: ";
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

            login << endl << "Student Name: " << name << endl;
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

        cout << "How many books to add?: ";
        cin >> count;

        for (int i = 1; i <= count; i++)
        {
            cout << "Book NO." << i;
            cout << endl << "Book ID: ";
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

            books << endl << "Book ID: " << id << endl;
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

void issueBook()
{
    int bookID, issueD, dueD;
    string name;
    ifstream booksFile("books.txt");
    ifstream nameFile("login.txt");
    ofstream issue("issuedBooks.txt", ios::app);

    if (!booksFile.is_open())
    {
        cout << "Error opening the books file for reading." << endl;
        return;
    }

    if (issue.is_open())
    {
        cout << "How many books for entry?: ";
        cin >> count;

        for (int i = 1; i <= count; i++)
        {
            cout << "Book NO." << i;
            cout << endl << "Book ID: ";
            cin >> bookID;

            bool bookFound = false;
            string line;
            while (getline(booksFile, line))
            {
                if (line.find("Book ID: " + to_string(bookID)) != string::npos)
                {
                    bookFound = true;
                    break;
                }
            }

            if (!bookFound)
            {
                cout << "Book not found." << endl;
                return;
            }

            cout << "Student Name: ";
            cin.ignore();
            getline(cin, name);

            bool nameFound = false;

            while (getline(nameFile, line))
            {
                if (line.find("Student Name: " + name) != string::npos)
                {
                    nameFound = true;
                    break;
                }
            }

            if (!nameFound)
            {
                cout << "Name not found." << endl;
                return;
            }

            cout << "Issue Date: ";
            cin >> issueD;

            cout << "Due Date: ";
            cin >> dueD;

            issue << endl << "Book ID: " << bookID << endl;
            issue << "Student Name: " << name << endl;
            issue << "Issue Date: " << issueD << endl;
            issue << "Due Date: " << dueD << endl;

            stats << endl << "Issue Details" << endl;
            stats << "Book ID: " << bookID << endl;
            stats << "Student Name: " << name << endl;
            stats << "Issue Date: " << issueD << endl;
            stats << "Due Date: " << dueD << endl;
            stats << "Current Date and Time: " << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << endl;

            cout << "Book issued successfully!" << endl;
        }
    }
    else
    {
        cout << "Error opening the issued books file for writing." << endl;
    }

    issue.close();
    booksFile.close();
    nameFile.close();
}

void returnBook()
{
    int bookID, issueD, dueD;
    string name;
    ifstream File("issuedBooks.txt");
    ofstream returned("returnedBooks.txt", ios::app);

    if (!File.is_open())
    {
        cout << "Error opening the books file for reading." << endl;
        return;
    }

    if (returned.is_open())
    {
        cout << "How many books for entry?: ";
        cin >> count;

        for (int i = 1; i <= count; i++)
        {
            cout << "Book NO." << i;
            cout << endl << "Book ID: ";
            cin >> bookID;

            bool bookFound = false;
            string line;
            while (getline(File, line))
            {
                if (line.find("Book ID: " + to_string(bookID)) != string::npos)
                {
                    bookFound = true;
                    break;
                }
            }

            if (!bookFound)
            {
                cout << "Book not matched." << endl;
                return;
            }

            cout << "Student Name: ";
            cin.ignore();
            getline(cin, name);

            bool nameFound = false;
            while (getline(File, line))
            {
                if (line.find("Student Name: " + name) != string::npos)
                {
                    nameFound = true;
                    break;
                }
            }

            if (!nameFound)
            {
                cout << "Name not matched." << endl;
                return;
            }

            cout << "Issue Date: ";
            cin >> issueD;

            bool dateFound = false;
            while (getline(File, line))
            {
                if (line.find("Issue Date: " + to_string(issueD)) != string::npos)
                {
                    dateFound = true;
                    break;
                }
            }

            if (!dateFound)
            {
                cout << "Date not matched." << endl;
                return;
            }

            cout << "Due Date: ";
            cin >> dueD;

            while (getline(File, line))
            {
                if (line.find("Due Date: " + to_string(dueD)) != string::npos)
                {
                    dateFound = true;
                    break;
                }
            }

            if (!dateFound)
            {
                cout << "Date not matched." << endl;
                return;
            }

            returned << endl << "Book ID: " << bookID << endl;
            returned << "Student Name: " << name << endl;
            returned << "Issue Date: " << issueD << endl;
            returned << "Due Date: " << dueD << endl;

            stats << endl << "Returned Book" << endl;
            stats << "Book ID: " << bookID << endl;
            stats << "Student Name: " << name << endl;
            stats << "Issue Date: " << issueD << endl;
            stats << "Due Date: " << dueD << endl;
            stats << "Current Date and Time: " << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << endl;

            cout << "Book returned successfully!" << endl;
        }
    }
    else
    {
        cout << "Error opening the issued books file for writing." << endl;
    }

    returned.close();
    File.close();
}

int main()
{
    int out;
    string ans;
    cout << "********** MISERY LIBRARY MANAGEMENT SYSTEM **********\n";
    do
    {
        cout << "1. New Student\n"
             << "2. New Book\n"
             << "3. Issue Book\n"
             << "4. Return Book\n"
             << "5. Close Application\n";
        cout << ">> Choose any option to get started with: ";
        cin >> out;
        switch (out)
        {
        case 1:
            newStudent();
            break;

        case 2:
            newBook();
            break;

        case 3:
            issueBook();
            break;

        case 4:
            returnBook();
            break;

        case 5:
            exit(0);
            break;

        default:
            cout << "NEGAWATT ENTER SOMETHING BETTER (1-4)" << endl;
            break;
        }
        cout << "Again? (y/n): ";
        cin.ignore();
        cin >> ans;
    } while (ans == "Y" || ans == "y");
}
