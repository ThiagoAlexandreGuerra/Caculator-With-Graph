#include <iostream>
#include <string>

#include "OutPutTad.h"

using namespace std;

OutPutTad::OutPutTad(){

}

OutPutTad::~OutPutTad(){

}

string OutPutTad::Get( string S){
    return Leanding(S);
}

string OutPutTad::Leanding(string S){

   
    DeliveryFunctionResults= ResultFunction.Get(S);

    if(DeliveryFunctionResults.TypeOfFunction==1){ return LinearFunction_Delivery();}
    if(DeliveryFunctionResults.TypeOfFunction==2){ return QuadraticFunction_Delivery();}
    if(DeliveryFunctionResults.TypeOfFunction==3){ return CubicFunction_Delivery();}


}

string OutPutTad::LinearFunction_Delivery() {
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

    MyCoords += "\t\"Root\": [\n\t\t{ \"x\": " + to_string(DeliveryFunctionResults.FirstRoot) + ", \"y\": 0 }\n\t],\n";

    MyCoords += "\t\"Slope\": [\n\t\t{ \"a\": " + to_string(DeliveryFunctionResults.slope) + " }\n\t],\n";

    MyCoords += "\t\"ConstantTerm\": [\n\t\t{ \"c\": " + to_string(DeliveryFunctionResults.ConstantTerm) + " }\n\t]\n";

    MyCoords += "}";

    cout << "\n\n" << MyCoords;
    return MyCoords;
}


string OutPutTad::QuadraticFunction_Delivery(){
    return "";
}
string OutPutTad::CubicFunction_Delivery(){
    return "";
}