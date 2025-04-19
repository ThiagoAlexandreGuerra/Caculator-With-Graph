#ifndef GERPOINTS_H
#define GERPOINTS_H
#include <string>
#include "FormatFunction.h"
typedef struct{

    double X;
    double Y;

}Coordinates;

typedef struct 
{
    Coordinates *MyCoordinates;
    Coordinates Vertex;
    Coordinates *InflectionPoint;
    Coordinates *CriticalPoint;

    X_Type *Derivatives;
   
    int TypeOfFunction;
    int MyCordinates_Length;

    double Delta;
    double FirstRoot;
    double SecondRoot;
    double ThirdRoot;
    double slope;
    double B_Coefficient;
    double C_Coefficient;
    double ConstantTerm;
    

    bool FindFirstRoot;
    bool FindSecondRoot;
    bool FindThirdRoot;
    bool FindConstanteTerm;
    bool IfVector_InflectionPoint_Allocated;
    bool IfVector_CriticalPoint_Allocated;
    bool IfVector_Derivative_Allocated;
   
}GerPoints_result;

class GerPoints{

    private:

        X_Type *FunctionFromUser=nullptr;

        int HowIsTheTypeOfFunction;
        int DivisorOfConstantTerm_Size;
        GerPoints_result LinearFunctionResponse, QuadraticFunctionResponse , CubicFunctionResponse;
        
        double *DivisorOfConstantTerm=nullptr;

        GerPoints_result Lending(string S); 
        void DefineFunctionType();
        void LinearFunction();
        void QuadraticFunction();
        void CubicFunction();
        void CubicFunctionFor_ONE_Root(double A , double B, double C, double D);
        void CubicFunctionFor_TWO_Root(double A , double B, double C, double D);
        void CubicFunctionFor_THREE_Root(double A , double B, double C, double D);
        void FuncDivisorOfX(float Number);
        void FindDerivative(GerPoints_result& howIsFunction);

    public:
        GerPoints_result Get(string S);
        GerPoints();
        ~GerPoints(); 
};

#endif