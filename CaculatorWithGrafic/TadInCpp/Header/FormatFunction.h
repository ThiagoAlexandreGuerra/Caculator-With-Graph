#ifndef FORMATFUNCTION_H
#define FORMATFUNCTION_H

#include <string>
using namespace std;

typedef struct {

    int X_Position;
    double X_Factor;
    double X_Expoent;
}X_Type;

typedef struct{

    bool IfsingExponetiation;
    int value;
    int NewIndex;
}Return_FindUpperLimit;

class FormatFunction
{
private:
    X_Type* My_Function , *FirstIndentied ;

    int Amount_of_X;
    string FF_stringFromUser;

    X_Type* Lending(string OperationFromUser);
    X_Type* UserFunction();
    int FindLowerLimit(int currentIndex);
    double FindConstantTerm();
    Return_FindUpperLimit FindUpperLimit(int currentIndex);

    void CountAmountOfX();
    void AlocationVector_FirstIndentied();
    void SetXIn_FirstIndentied();
    int ifNextIsXToo(int currentIndex, int currentAux);
public:
    FormatFunction();
    ~FormatFunction();
    X_Type* Get(string OperationFromUser);
};

#endif