#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee
{
    private:
        double bonus;
    public:
        //Creating new Manager, passing Employee constructor
        Manager(string theName, double theWage, double theHours, double theBonus) : Employee(theName, theWage, theHours)
        {bonus = theBonus;}

        //Redefined pay calculator to include manager bonus
        double calcPay() const;
};

#endif // MANAGER_H
