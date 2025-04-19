#ifndef ONLYEXPRESSION_H
#define ONLYEXPRESSION_H

#include <iostream>
#include <string>

using namespace std;

class OnlyExpression
{
private:
    string Leading(string S);
    string FormatString(string S);
public:
    OnlyExpression();
    ~OnlyExpression();
    string Get(string S);
};


#endif