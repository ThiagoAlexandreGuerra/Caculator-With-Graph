#include <string>
#include <iostream>
#include <sstream>

#include "FindNumber.h"
#include "OnlyExpression.h"
OnlyExpression::OnlyExpression(/* args */)
{
}

OnlyExpression::~OnlyExpression()
{
}

string OnlyExpression::Get(string S){
    return Leading(S);
};
string OnlyExpression::Leading(string S){

    FindNumber get;
    string result;

    result=to_string((get.Get(S,0,S.size()).VALUE));

    result=FormatString(result);

    return result;

};
string OnlyExpression::FormatString(string S){

    ostringstream oss;
    
    oss<<"{\n\t \"TYPE\":[\n\t\t {\"t\": \"Expression\"} \n\t],\n";
    oss<<"\t \"Result\" :[\n\t\t {\"r\": \""<< S << "\"} \n\t] \n";
    oss<<"}";

    return oss.str();
};

