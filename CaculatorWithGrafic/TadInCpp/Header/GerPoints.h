#ifndef GERPOINTS_H
#define GERPOINTS_H

#include "FormatFunction.h"
typedef struct{

    double X;
    double Y;

}Coordinates;

typedef struct 
{
    Coordinates *MyCoordinates;
    Coordinates Vertex;

    int TypeOfFunction;
    int MyCordinates_Length;

    double ConstantTerm;
    double slope;

    double FirstRoot;
    double SecondRoot;
    double ThirdRoot;
    double B_Coefficient;
    double C_Coefficient;

    bool FindFirstRoot;
    bool FindSecondRoot;
    bool FindThirdRoot;

}GerPoints_result;

class GerPoints{

    private:

        X_Type *FunctionFromUser;

        int HowIsTheTypeOfFunction;
        int DivisorOfConstantTerm_Size;
        GerPoints_result LinearFunctionResponse, QuadraticFunctionResponse , CubicFunctionResponse;
        
        double *DivisorOfConstantTerm=nullptr;

        GerPoints_result Lending(string S); 
        void DefineFunctionType();
        void LinearFunction();
        void QuadraticFunction();
        void CubicFunction();
        void FuncDivisorOfX(float Number);

    public:
        GerPoints_result Get(string S);
        GerPoints();
        ~GerPoints(); 
};

#endif