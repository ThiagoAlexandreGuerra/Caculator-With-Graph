#ifndef TOCHECKSTRING_H
#define TOCHECKSTRING_H

#include <string>
#include <sstream>
using namespace std;

typedef struct{

    bool is_Function;
    bool is_Expression;
    bool FindErro;
    string RigthString;
    string ERROS;

}RESULT_TochekString;

class ToCheckString{

    private:
        RESULT_TochekString Leanding(string string_from_user);
        int Function_or_Expression();
        void verification();
        void ShowErrors(string s);
        void Format_ShowErrors();
        void StraightenTheString(); 
        
        ostringstream oss;
        string StringFromUser , ErrosInString;
        int AmountOfErros;
        RESULT_TochekString RESULT;

    public:
        ToCheckString();
        ~ToCheckString();
        RESULT_TochekString Get(string string_from_user);

};


#endif