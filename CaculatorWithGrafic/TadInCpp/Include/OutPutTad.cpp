#include <iostream>
#include <string>
#include <sstream>

#include "OutPutTad.h"

using namespace std;

OutPutTad::OutPutTad(){}


string OutPutTad::Get( string S){
    return Leanding(S);
}

string OutPutTad::Leanding(string S){

    
   
    DeliveryFunctionResults= ResultFunction.Get(S);

    if(DeliveryFunctionResults.TypeOfFunction==1){ return LinearFunction_Delivery();}
    if(DeliveryFunctionResults.TypeOfFunction==2){ return QuadraticFunction_Delivery();}
    if(DeliveryFunctionResults.TypeOfFunction==3){ return CubicFunction_Delivery();}

    return "Not is function";
}


string OutPutTad::LinearFunction_Delivery() {
    ostringstream oss;

    oss << "{\n\t\"data\": [\n";

    int Length = DeliveryFunctionResults.MyCordinates_Length;

    for (int i = 0; i < Length; i++) {
        oss << "\t\t{ \"x\": " << DeliveryFunctionResults.MyCoordinates[i].X
            << ", \"y\": " << DeliveryFunctionResults.MyCoordinates[i].Y << " }";
        if (i != Length - 1)
            oss << ",";
        oss << "\n";
    }

    oss << "\t],\n";
    oss << "\t\"Root\": [\n\t\t{ \"x\": " << DeliveryFunctionResults.FirstRoot << ", \"y\": 0 }\n\t],\n";
    oss << "\t\"TYPE_Function\": [\n\t\t{ \"T\": " << 1 << " }\n\t],\n";
    oss << "\t\"TYPE\": [\n\t\t{ \"T\": \"Function\" }\n\t],\n";
    oss << "\t\"FindConstanteTerm\": [\n\t\t{ \"if\": " << DeliveryFunctionResults.FindConstanteTerm << " }\n\t],\n";
    oss << "\t\"FindFirstRoot\": [\n\t\t{ \"if\": " << DeliveryFunctionResults.FindFirstRoot << " }\n\t],\n";
    oss << "\t\"Slope\": [\n\t\t{ \"a\": " << DeliveryFunctionResults.slope << " }\n\t],\n";
    oss << "\t\"ConstantTerm\": [\n\t\t{ \"c\": " << DeliveryFunctionResults.ConstantTerm << " }\n\t],\n";
    if (DeliveryFunctionResults.IfVector_Derivative_Allocated) {
        oss << "\t\"First_Derivative\": [\n";
        oss << "\t\t{ \"a\": " << DeliveryFunctionResults.Derivatives[0].X_Factor << " },\n";
        oss << "\t\t{ \"e_a\": " << DeliveryFunctionResults.Derivatives[0].X_Expoent << " }\n";
        oss << "\t]\n";

    }
    oss << "}";

    string json = oss.str();

    return json;
}



string OutPutTad::QuadraticFunction_Delivery(){ 
    string MyCoords = "{\n\t\"data\": [\n";

    int Length = DeliveryFunctionResults.MyCordinates_Length;

    for (int i = 0; i < Length; i++) {
        MyCoords += "\t\t{ \"x\": " + to_string(DeliveryFunctionResults.MyCoordinates[i].X) +
                    ", \"y\": " + to_string(DeliveryFunctionResults.MyCoordinates[i].Y) + " }";
        if (i != Length - 1)
            MyCoords += ",";
        MyCoords += "\n";
    }

    MyCoords += "\t],\n";

    MyCoords += "\t\"FirstRoot\": [\n\t\t{ \"x\": " + to_string(DeliveryFunctionResults.FirstRoot) + ", \"y\": 0 }\n\t],\n";
    MyCoords += "\t\"SecondRoot\": [\n\t\t{ \"a\": " + to_string(DeliveryFunctionResults.SecondRoot) + " }\n\t],\n";
    MyCoords += "\t\"Slope\": [\n\t\t{ \"a\": " + to_string(DeliveryFunctionResults.slope) + " }\n\t],\n";
    MyCoords += "\t\"Delta\": [\n\t\t{ \"a\": " + to_string(DeliveryFunctionResults.Delta) + " }\n\t],\n";
    MyCoords += "\t\"B_Coefficient\": [\n\t\t{ \"a\": " + to_string(DeliveryFunctionResults.B_Coefficient) + " }\n\t],\n";
    MyCoords += "\t\"C_Coefficient\": [\n\t\t{ \"a\": " + to_string(DeliveryFunctionResults.C_Coefficient) + " }\n\t],\n";
    MyCoords += "\t\"ConstantTerm\": [\n\t\t{ \"c\": " + to_string(DeliveryFunctionResults.ConstantTerm) + " }\n\t],\n";

    
    MyCoords += "\t\"Vertex\": { \"x\": " + to_string(DeliveryFunctionResults.Vertex.X) +
                ", \"y\": " + to_string(DeliveryFunctionResults.Vertex.Y) + " }\n";

    MyCoords += "}";

    return MyCoords;
}

string OutPutTad::CubicFunction_Delivery() {
    
    ostringstream oss;
    oss << "{\n\t\"data\": [\n";

    int Length = DeliveryFunctionResults.MyCordinates_Length;

    for (int i = 0; i < Length; i++) {
        oss << "\t\t{ \"x\": " << DeliveryFunctionResults.MyCoordinates[i].X
            << ", \"y\": " << DeliveryFunctionResults.MyCoordinates[i].Y << " }";
        if (i != Length - 1)
            oss << ",";
        oss << "\n";
    }

    oss << "\t],\n";

    if (DeliveryFunctionResults.FindFirstRoot) {
        oss << "\t\"FirstRoot\": [\n\t\t{ \"x\": " << DeliveryFunctionResults.FirstRoot << ", \"y\": 0 }\n\t],\n";
    }
    if (DeliveryFunctionResults.FindSecondRoot) {
        oss << "\t\"SecondRoot\": [\n\t\t{ \"x\": " << DeliveryFunctionResults.SecondRoot << ", \"y\": 0 }\n\t],\n";
    }
    if (DeliveryFunctionResults.FindThirdRoot) {
        oss << "\t\"ThirdRoot\": [\n\t\t{ \"x\": " << DeliveryFunctionResults.ThirdRoot << ", \"y\": 0 }\n\t],\n";
    }

    oss << "\t\"Slope\": [\n\t\t{ \"a\": " << DeliveryFunctionResults.slope << " }\n\t],\n";
    oss << "\t\"Delta\": [\n\t\t{ \"a\": " << DeliveryFunctionResults.Delta << " }\n\t],\n";
    oss << "\t\"B_Coefficient\": [\n\t\t{ \"a\": " << DeliveryFunctionResults.B_Coefficient << " }\n\t],\n";
    oss << "\t\"C_Coefficient\": [\n\t\t{ \"a\": " << DeliveryFunctionResults.C_Coefficient << " }\n\t],\n";
    oss << "\t\"ConstantTerm\": [\n\t\t{ \"c\": " << DeliveryFunctionResults.ConstantTerm << " }\n\t],\n";

    if (DeliveryFunctionResults.IfVector_Derivative_Allocated) {
        oss << "\t\"First_Derivative\": [\n";
        oss << "\t\t{ \"c\": " << DeliveryFunctionResults.Derivatives[0].X_Factor << " },\n";
        oss << "\t\t{ \"e_c\": " << DeliveryFunctionResults.Derivatives[0].X_Expoent << " },\n";
        oss << "\t\t{ \"b\": " << DeliveryFunctionResults.Derivatives[1].X_Factor << " },\n";
        oss << "\t\t{ \"e_b\": " << DeliveryFunctionResults.Derivatives[1].X_Expoent << " },\n";
        oss << "\t\t{ \"a\": " << DeliveryFunctionResults.Derivatives[2].X_Factor << " },\n";
        oss << "\t\t{ \"e_a\": " << DeliveryFunctionResults.Derivatives[2].X_Expoent << " }\n";
        oss << "\t],\n";

        oss << "\t\"Second_Derivative\": [\n";
        oss << "\t\t{ \"a\": " << DeliveryFunctionResults.Derivatives[3].X_Factor << " },\n";
        oss << "\t\t{ \"e_a\": " << DeliveryFunctionResults.Derivatives[3].X_Expoent << " },\n";
        oss << "\t\t{ \"b\": " << DeliveryFunctionResults.Derivatives[4].X_Factor << " },\n";
        oss << "\t\t{ \"e_b\": " << DeliveryFunctionResults.Derivatives[4].X_Expoent << " }\n";
        oss << "\t]\n";
    }


    oss << "}";
    return oss.str(); 
}
OutPutTad::~OutPutTad(){

    if(DeliveryFunctionResults.IfVector_Derivative_Allocated){
        delete [] DeliveryFunctionResults.Derivatives;
        DeliveryFunctionResults.Derivatives=NULL;
    }
    if(DeliveryFunctionResults.IfVector_CriticalPoint_Allocated){
        delete [] DeliveryFunctionResults.CriticalPoint;
        DeliveryFunctionResults.CriticalPoint=NULL;
    }
    if(DeliveryFunctionResults.IfVector_InflectionPoint_Allocated){
        delete [] DeliveryFunctionResults.InflectionPoint;
        DeliveryFunctionResults.InflectionPoint=NULL;
    }
    delete [] DeliveryFunctionResults.MyCoordinates;
    DeliveryFunctionResults.MyCoordinates=NULL;

}
