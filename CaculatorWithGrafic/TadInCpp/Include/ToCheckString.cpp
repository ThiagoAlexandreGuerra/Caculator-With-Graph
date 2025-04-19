#include <iostream>
#include <string>
#include <sstream>

#include "ToCheckString.h"

using namespace std;
ToCheckString::ToCheckString(){
    StringFromUser="";
    ErrosInString="";

    AmountOfErros=0;

    RESULT.is_Expression=false;
    RESULT.is_Function=false;
    RESULT.FindErro=false;
    RESULT.RigthString="";
};
RESULT_TochekString ToCheckString::Get(string string_from_user){
    return Leanding(string_from_user);
};

RESULT_TochekString ToCheckString::Leanding(string string_from_user){
    StringFromUser=string_from_user;

    verification();
    if (AmountOfErros!=0){Format_ShowErrors();RESULT.FindErro=true;}else{StraightenTheString();}
    if(Function_or_Expression()==1){RESULT.is_Function=true;}else{RESULT.is_Expression=true;}
    
    RESULT.RigthString=StringFromUser;
    RESULT.ERROS=ErrosInString;
    cout<<"TAD: ToCheckString ,Leanding______________:"<<endl;
    cout<<"| RESULT.is_Function: "<<RESULT.is_Function<<endl;
    cout<<"| RESULT.is_Expression: "<<RESULT.is_Expression<<endl;
    cout<<"| RESULT.RigthString: "<<RESULT.RigthString<<endl;
    cout<<"| RESULT.ERROS: "<<RESULT.ERROS<<endl;
    cout<<"|________________________________________||"<<endl;
    return RESULT;
    
};


void ToCheckString::verification(){
    int consecutive_plus_sing=0, consecutive_mult_sing=0 ,consecutive_div_sing=0,consecutive_expoente_sing=0, consecutive_dot_sing=0;
    int consecutive_minus_sing=0 , consecutive_percent_sing=0 , consecutive_fatorial_sing=0 , amontOfcontentes=0;
    
    bool firstLetter=true , checkDivision=false;
    string letter="";

    for(int i=0 ; i<StringFromUser.size(); i++){
        if(isdigit(StringFromUser[i])||isalpha(StringFromUser[i])){
            if(checkDivision){if(StringFromUser[i]=='0'){ShowErrors("Division for zero");}; checkDivision=false;}
            consecutive_plus_sing=0;
            consecutive_mult_sing=0;
            consecutive_div_sing=0;
            consecutive_expoente_sing=0;
            consecutive_dot_sing=0;
            consecutive_minus_sing=0;
            consecutive_percent_sing=0;
            consecutive_fatorial_sing=0; 
        }

        if(StringFromUser[i]=='+'){ consecutive_plus_sing++;if(consecutive_plus_sing==2){ShowErrors("consecutive_plus_sing");}}
        if(StringFromUser[i]=='-'){ consecutive_minus_sing++;if(consecutive_minus_sing==2){ShowErrors("consecutive_minus_sing");}}
        if(StringFromUser[i]=='/'){ consecutive_div_sing++;if(consecutive_div_sing==2){ShowErrors("consecutive_div_sing");}; checkDivision=true;}
        if(StringFromUser[i]=='*'){ consecutive_mult_sing++;if(consecutive_mult_sing==2){ShowErrors("consecutive_mult_sing");}}
        if(StringFromUser[i]=='!'){ consecutive_fatorial_sing++;if(consecutive_fatorial_sing==2){ShowErrors("consecutive_fatorial_sing");}}
        if(StringFromUser[i]=='%'){ consecutive_percent_sing++;if(consecutive_percent_sing==2){ShowErrors("consecutive_percent_sing");}}
        if(StringFromUser[i]=='^'){ consecutive_expoente_sing++;if(consecutive_expoente_sing==2){ShowErrors("consecutive_expoente_sing");}}
        if(StringFromUser[i]=='.'){ consecutive_dot_sing++;if(consecutive_dot_sing==2){ShowErrors("consecutive_dot_sing");}}

        if((StringFromUser[i]=='(')||(StringFromUser[i]==')')
        ||(StringFromUser[i]=='[')||(StringFromUser[i]==']')
        ||(StringFromUser[i]=='{')||(StringFromUser[i]=='}')){

                amontOfcontentes++;
        }

        if( (consecutive_plus_sing+consecutive_mult_sing+consecutive_div_sing+consecutive_expoente_sing+consecutive_dot_sing + consecutive_minus_sing + consecutive_percent_sing +consecutive_fatorial_sing) ==2 ){ShowErrors("Consecutive_Whatever_sing");}

        if(isalpha(StringFromUser[i])){
            if(firstLetter){
                letter=StringFromUser[i];
                firstLetter=false;
            }
            if(StringFromUser[i]!=letter[0]){
                ShowErrors("Diferent Letters");
            }
        }
    }

    if( consecutive_plus_sing!=0
        ||consecutive_mult_sing!=0
        ||consecutive_div_sing!=0
        ||consecutive_expoente_sing!=0
        ||consecutive_dot_sing!=0
        ||consecutive_minus_sing!=0
        ||consecutive_percent_sing!=0
        ||consecutive_fatorial_sing!=0 ){

            ShowErrors("Lonely sing of operation");
        }

    if(amontOfcontentes%2!=0){
        ShowErrors("Lonely paretheses , brackets or braces");
    }
};

void ToCheckString::ShowErrors(string S){
    oss << "\t\t{ \"Error\": \"" << S << "\" },\n";
    AmountOfErros++;
}

void ToCheckString::Format_ShowErrors(){
    ErrosInString = oss.str();

    
    if (!ErrosInString.empty()) {
        ErrosInString.erase(ErrosInString.find_last_of(','), 1);
    }

    ErrosInString = "{\n\t\"ERRO_MSN\": [\n" + ErrosInString + "\n\t],\n";
    ErrosInString += "\t\"TYPE\" : [\n\t\t { \"t\": \"Error\" } \n\t],\n";
    ErrosInString += "\t\"AmountOfErros\": [\n\t\t{ \"a\": " + to_string(AmountOfErros) + " }\n\t]\n}";
}

int ToCheckString::Function_or_Expression(){
    for(int i=0 ; i<StringFromUser.size(); i++){if(isalpha(StringFromUser[i])){return 1;}}
    return 2;
};
void ToCheckString::StraightenTheString(){

    for(int i=0 ; i<StringFromUser.size(); i++){
        if(isalpha(StringFromUser[i])){StringFromUser[i]='X';}
    }
}; 

ToCheckString::~ToCheckString(){};
