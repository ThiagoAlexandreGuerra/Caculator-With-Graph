#ifndef FINDNUMBER_H
#define FINDNUMBER_H

#include <string>


using namespace std;

typedef struct{

    double VALUE;
    bool isZero;
}Result;

class FindNumber{

    private:
        Result RESULT;
        int FindNumber_LowerLimit, FindNumber_UperLimit;
        string FindNumber_stringFromUser , Operation;

        Result Leading(string StringFromUser, int LowerLimit , int UperLimit);
        void SplitStringFromUser();
        double RealiseTheOperations();
        bool IfDigit(string expression);


    public:
        FindNumber();
        ~FindNumber();
        Result Get(string StringFromUser, int LowerLimit , int UperLimit );


};

#endif