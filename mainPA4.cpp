// Author: Orion Erazo
// BannerID: 001396823
// Course: CS 181
// Assignment: PA4
// Date Assigned: Monday, March 18, 2024
// Date/Time Due: Saturday, March 30, 2024 -- 11:55 pm
// Description: This program will exercise Object-Oriented concepts with C++.

// Certification of Authenticity:
// I certify that this assignment is entirely my own work.

/* This program will read the name, wage, hours, and bonus of a manager given by
the user and store that information in dynamic Manager objects. Pointers for
these objects are stored in an array of pointers, and the objects are compared
for which manager is paid the highest and what the average pay is. These results
are displayed*/

#include <iostream>
#include <iomanip>

using namespace std;

//Including Employee and Manager classes
#include "Employee.h"
#include "Manager.h"

int main()
{
    //Declaring variable for number of managers
    int manNum;

    //Prompting user for number of managers, reading input into variable
    cout<<"Enter number of managers: ";
    cin>>manNum;
    cout<<endl;

    //Creating array of pointers
    Manager** managers = new Manager*[100];

    //Declaring variables for reading information and calculating results
    string name;
    double wage;
    double hours;
    double bonus;
    float highPay;
    float avgPay;
    int highMan;

    //Loop for reading the given amount of managers
    for(int i=0;i<manNum;i++)
    {
        //Resetting reading variables to empty
        name = " ";
        wage = 0;
        hours = 0;
        bonus = 0;

        //Reading inputs from user into variables
        cout<<"Enter manager "<<i<<" name: ";
        cin>>name;
        cout<<"Enter manager "<<i<<" hourly wage: ";
        cin>>wage;
        cout<<"Enter manager "<<i<<" hours worked: ";
        cin>>hours;
        cout<<"Enter manager "<<i<<" bonus: ";
        cin>>bonus;
        cout<<endl;

        //Dynamically creating Manager object and storing pointer in array
        managers[i] = new Manager(name,wage,hours,bonus);

        //Calculating highest pay and storing index of highest paid manager
        if(managers[i]->calcPay() > highPay)
        {
            highPay = managers[i]->calcPay();
            highMan = i;
        }

        //Adding all manager pay
        avgPay = avgPay + managers[i]->calcPay();
    }

    //Determining average pay
    avgPay = avgPay/manNum;

    //Displaying highest paid manager and average pay
    cout<<fixed;
    cout<<"The highest paid manager is "<<managers[highMan]->getName()<<" who is paid $"<<setprecision(2)<<highPay<<endl;
    cout<<"Average pay is $"<<avgPay;

    return 0;
}
