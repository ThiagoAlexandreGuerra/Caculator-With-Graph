#ifndef OUTPUTTAD_H
#define OUTPUTTAD_H

#include "GerPoints.h"

class   OutPutTad{

    private:
        GerPoints ResultFunction;
        GerPoints_result DeliveryFunctionResults;

        string Leanding(string S);
        string LinearFunction_Delivery();
        string QuadraticFunction_Delivery();
        string CubicFunction_Delivery();


    public:
        OutPutTad();
        ~OutPutTad();
        string Get(string S);
};

#endif