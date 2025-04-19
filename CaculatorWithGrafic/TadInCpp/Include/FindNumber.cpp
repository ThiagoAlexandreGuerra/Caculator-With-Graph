#include <string>
#include <iostream>

#include "muParser.h"

#include "FindNumber.h"


using namespace std;

FindNumber::FindNumber(){
    RESULT.VALUE=0;
    RESULT.isZero=true;
    FindNumber_LowerLimit=0;
    FindNumber_UperLimit=0;
    FindNumber_stringFromUser="" ; 
    Operation="";
}
FindNumber::~FindNumber(){}

Result FindNumber::Get(string OperationFromUser, int LowerLimit , int UperLimit){
   return Leading(OperationFromUser, LowerLimit, UperLimit);
};

Result FindNumber::Leading(string OperationFromUser, int LowerLimit , int UperLimit){
    FindNumber_stringFromUser = OperationFromUser;
    FindNumber_LowerLimit = LowerLimit;
    FindNumber_UperLimit = UperLimit;
    cout<<"FindNumber Leading_____________________________________________________:"<<endl;
    cout<<"| call SplitStringFromUser --->"<<endl;
    SplitStringFromUser();
    RESULT.VALUE = RealiseTheOperations();
    cout<<endl<<endl<<"| RESULT.VALUE: "<<RESULT.VALUE<<endl;
    cout<<"| RESULT.isZero : "<<RESULT.isZero<<endl;

    return RESULT;
};

void FindNumber::SplitStringFromUser() {
    int StringSize = FindNumber_stringFromUser.size();
    cout<<endl<<endl<<"SplitStringFromUser________________________________________:"<<endl;
    cout<<"| SplitStringFromUser: "<<FindNumber_stringFromUser<<endl;
    cout<<"| FindNumber_stringFromUser.size(): "<<FindNumber_stringFromUser.size()<<endl;
    cout<<"| FindNumber_LowerLimit: "<<FindNumber_LowerLimit<<endl;
    cout<<"| FindNumber_UperLimit: "<<FindNumber_UperLimit<<endl;

    for (int i = 0; i < FindNumber_LowerLimit; i++) {
        FindNumber_stringFromUser[i] = ' ';
    }
    for (int i = StringSize - 1; i > FindNumber_UperLimit; i--) {
        FindNumber_stringFromUser[i] = ' ';
    }

    Operation=FindNumber_stringFromUser; 
    bool lonelySing=false, verification=false, findDigit=false;

    int positioLonelySing=-1;


    for(int i=0 ; i<Operation.size() ; i++){
        if(isdigit(Operation[i])){findDigit=true;}
        if(isalpha(Operation[i])){Operation[i]=' ';}
        if((Operation[i]=='+'||Operation[i]=='-'||Operation[i]=='*') && !verification){positioLonelySing=i;verification=true;i++;}
        if(isdigit(Operation[i])){verification=false;positioLonelySing=-1;}
        if(verification && (i==Operation.size()-1)){Operation[positioLonelySing]=' ';}
        if(Operation[i]=='/' && !findDigit){Operation[i]=' ';}
    }

    for(int i=0 ; i<Operation.size();i++){
        if(isdigit(Operation[i]) && Operation[i]!='0'){RESULT.isZero=false;}
    }
    if(FindNumber_LowerLimit==FindNumber_UperLimit){RESULT.isZero=false;}
    if(!IfDigit(Operation)){RESULT.isZero=false;}
    
    cout<<"| Operation: "<<Operation<<endl;
    cout<<"|__________________________________________________________|"<<endl<<endl;
}

double FindNumber::RealiseTheOperations() {
    if (IfDigit(Operation)) {
        try {
            mu::Parser parser;
            parser.SetExpr(Operation);
            double resultado = parser.Eval();
            return resultado;
        } catch (mu::Parser::exception_type &e) {
            std::cerr << "Erro muParser: " << e.GetMsg() << std::endl;
            return std::nan("1");
        }
    }

    return 0 ; 
}


bool FindNumber::IfDigit(string expression){

    for(int i=0 ; i<expression.size(); i++){
        if(isdigit(expression[i])){return true;}
    }
    return false;
}