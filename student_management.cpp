
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    float marks;

public:

    Student(int r, string n, float m)
    {
        rollNo = r;
        name = n;
        marks = -1;
        setMarks(m);
    }

    // Getter Functions
    int getRollNo()
    {
        return rollNo;
    }

    string getName()
    {
        return name;
    }

    float getMarks()
    {
        return marks;
    }

    bool setMarks(float m)
    {
        if (m >= 0 && m <= 100)
        {
            marks = m;
            return true;
        }
        else
        {
            cout << "Invalid marks! Enter marks between 0 and 100." << endl;
            return false;
        }
    }

    void display()
    {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;

        if (marks == -1)
        {
            cout << "Marks: Invalid" << endl;
            cout << "Result: Marks not available" << endl;
        }
        else
        {
            cout << "Marks: " << marks << endl;

            if (marks >= 40)
                cout << "Result: PASS" << endl;
            else
                cout << "Result: FAIL" << endl;
        }

        cout << endl;
    }
};

void printResult(Student s)
{
    cout << "----- STUDENT RESULT -----" << endl;
    cout << "Roll Number: " << s.getRollNo() << endl;
    cout << "Name: " << s.getName() << endl;

    if (s.getMarks() == -1)
    {
        cout << "Marks: Invalid" << endl;
        cout << "Result: Marks not available" << endl;
    }
    else
    {
        cout << "Marks: " << s.getMarks() << endl;

        if (s.getMarks() >= 40)
            cout << "Result: PASS" << endl;
        else
            cout << "Result: FAIL" << endl;
    }
}

int main()
{
    Student batch[3] = {
        Student(101, "Anu", 85),
        Student(102, "Meera", 35),
        Student(103, "Rahul", 75)
    };

    // Display student details
    cout << "STUDENT MANAGEMENT SYSTEM" << endl;

    for (int i = 0; i < 3; i++)
    {
        batch[i].display();
    }

    int choice;

    cout << "Do you want to re-evaluate marks?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int roll;

        cout << "Enter student roll number: ";
        cin >> roll;

        bool found = false;

        for (int i = 0; i < 3; i++)
        {
            if (batch[i].getRollNo() == roll)
            {
                float newMarks;

                cout << "Enter new marks: ";
                cin >> newMarks;

                if (batch[i].setMarks(newMarks))
                {
                    cout << "Marks updated successfully!" << endl;
                }

                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Student not found!" << endl;
        }
    }

    // Print final results
    cout << "===== FINAL STUDENT RESULTS =====" << endl;

    for (int i = 0; i < 3; i++)
    {
        printResult(batch[i]);
    }

    return 0;
}
