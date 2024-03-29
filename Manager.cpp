#include <iostream>
#include <cstdlib>

using namespace std;

#include "Manager.h"

double Manager::calcPay() const
{
    return wage * hours + bonus;
}
