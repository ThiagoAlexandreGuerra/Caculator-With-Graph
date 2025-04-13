#include <iostream>

#include "FindNumber.h"
#include "FormatFunction.h"

using namespace std;

FormatFunction::FormatFunction(/* args */)
{
    My_Function= (X_Type*) new X_Type[5]();
    Amount_of_X=0;
}

FormatFunction::~FormatFunction()
{
    delete [] My_Function;
}

X_Type* FormatFunction::Get(string OperationFromUser){
   return Lending(OperationFromUser);
};

X_Type* FormatFunction::Lending(string OperationFromUser){

    FF_stringFromUser=OperationFromUser;
    cout<<endl<<endl<<"FormatFunction_____________________________________________________: "<<endl;
    cout<<"| FF_stringFromUser: "<<FF_stringFromUser<<endl;
    CountAmountOfX();
    cout<<"| Amount_of_X: "<<Amount_of_X<<endl;

    AlocationVector_FirstIndentied();
    SetXIn_FirstIndentied();

    for(int i=0 ; i<Amount_of_X ; i++){
        cout<<"|X_position: "<<FirstIndentied[i].X_Position <<endl;
        cout<<"|X_factor: "<<FirstIndentied[i].X_Factor <<endl;
        cout<<"|X_expoent: "<<FirstIndentied[i].X_Expoent <<endl<<endl<<endl;
    }

    return UserFunction();

};

void FormatFunction::CountAmountOfX(){

    for(int i=0 ; i<FF_stringFromUser.size() ; i++){
        if(FF_stringFromUser[i]=='X'){Amount_of_X++;}
    }
};

void FormatFunction::AlocationVector_FirstIndentied(){
    FirstIndentied=(X_Type*) new X_Type[Amount_of_X]();
    if(FirstIndentied==NULL){
        cout<<"Falha de alocação"<<endl;
    }
}

void FormatFunction::SetXIn_FirstIndentied(){

    FindNumber GetValue;
    Result fator;
    Result expoent;
    Result auxGet;
    Return_FindUpperLimit RFUL;
    int aux=0;
    cout<<endl<<endl<<"SetXIn_FirstIndentied________________________________________________:"<<endl;
    for(int i=0 ; i<FF_stringFromUser.size() ; i++){

        if(FF_stringFromUser[i]=='X'){
            cout<<"| Call FindNumber!!!!!!!!!!!!!!!!!!"<<endl<<endl;
            cout<<"| FF_stringFromUser["<<i<<"]: "<<FF_stringFromUser[i]<<endl;
            fator= GetValue.Get(FF_stringFromUser,FindLowerLimit(i),(i-1));
            if(fator.isZero){fator.VALUE=0;}else{fator.VALUE=fator.VALUE==0?1:fator.VALUE;}
            cout<<"| #fator.VALUE: "<<fator.VALUE<<endl;
            RFUL=FindUpperLimit(i);
            cout<<"| RFUL.IfsingExponetiation: "<<RFUL.IfsingExponetiation<<endl;
            if(RFUL.IfsingExponetiation){
                cout<<"| Call FindNumber!!!!!!!!!!!!!!!!!!"<<endl;
                cout<<"| HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
                cout<<"| FF_stringFromUser["<<i<<"]: "<<FF_stringFromUser[i]<<endl;
                cout<<"| FF_stringFromUser["<<RFUL.NewIndex<<"]: "<<FF_stringFromUser[RFUL.NewIndex]<<endl;
                if(RFUL.value>RFUL.NewIndex){swap( RFUL.value ,RFUL.NewIndex );}
                expoent= GetValue.Get(FF_stringFromUser, RFUL.value, RFUL.NewIndex);
                expoent.VALUE==0?expoent.VALUE=1:expoent.VALUE;
            }else{
                cout<<"| Call FindNumber!!!!!!!!!!!!!!!!!!"<<endl;
                cout<<"| FF_stringFromUser["<<i<<"]: "<<FF_stringFromUser[i]<<endl;
                cout<<"| i: "<<i<<endl;
                auxGet=GetValue.Get(FF_stringFromUser,(i),RFUL.value);
                if(auxGet.isZero){auxGet.VALUE=0;}else{auxGet.VALUE==0?1:auxGet.VALUE;}
                fator.VALUE= (auxGet.VALUE==0?1:auxGet.VALUE) * fator.VALUE;
                expoent.VALUE=1;
            }
            cout<<"| fator: "<<fator.VALUE<<endl;
            cout<<"| expoent: "<<expoent.VALUE<<endl;
            cout<<"| Position: "<<i<<endl<<endl;
            FirstIndentied[aux].X_Factor=fator.VALUE;
            FirstIndentied[aux].X_Expoent=expoent.VALUE;
            FirstIndentied[aux].X_Position=i;
            aux++;
        }
    }
    cout<<"_____________________________________________________________________|"<<endl;
}

int FormatFunction::FindLowerLimit(int currentIndex){

    int i=currentIndex;

    for(i; i!= 0 ; i-- ){
        if(FF_stringFromUser[i]=='+' || FF_stringFromUser[i]=='-'){
            return i;
        }
    }

    return 0;
};
Return_FindUpperLimit FormatFunction::FindUpperLimit(int currentIndex){

    int i=currentIndex;
    bool findSing_exponentiationFirstTime=true;
    Return_FindUpperLimit returnn;
    cout<<"FindUpperLimit************************:"<<endl;
    for(i; i< FF_stringFromUser.size() ; i++ ){

        if(FF_stringFromUser[i] =='^' && findSing_exponentiationFirstTime){
                        
            returnn.IfsingExponetiation=true;
            returnn.NewIndex=i+1;
            cout<<"| findSing_exponentiationFirstTime "<< findSing_exponentiationFirstTime<<endl;
            cout<<"| returnn.NewIndex: "<<returnn.NewIndex<<endl;
            cout<<"| FF_stringFromUser[returnn.NewIndex]: "<<FF_stringFromUser[returnn.NewIndex]<<endl;
            cout<<"**********************************|"<<endl<<endl;

            findSing_exponentiationFirstTime=false;
        }
        if(FF_stringFromUser[i]=='+' || FF_stringFromUser[i]=='-' || (i==FF_stringFromUser.size()-1)){
            returnn.value=i;
        

            cout<<"| returnn.value: "<<returnn.value<<endl;
            cout<<"| i: "<<i<<endl;
            cout<<"| FF_stringFromUser[i]: "<<FF_stringFromUser[i]<<endl;
            cout<<"**********************************|"<<endl<<endl;
            if (findSing_exponentiationFirstTime){returnn.IfsingExponetiation=false;}
            
            return returnn;
        }
    }
    returnn.IfsingExponetiation=false;
    returnn.value=1;
    return returnn;

};

X_Type* FormatFunction::UserFunction(){

    X_Type* UserFunction_VetAux=(X_Type*) new X_Type[4]();
    
    UserFunction_VetAux[0].X_Expoent=1;UserFunction_VetAux[0].X_Position=0;
    UserFunction_VetAux[1].X_Expoent=2;UserFunction_VetAux[1].X_Position=0;
    UserFunction_VetAux[2].X_Expoent=3;UserFunction_VetAux[2].X_Position=0;

    UserFunction_VetAux[3].X_Factor=FindConstantTerm();
    UserFunction_VetAux[3].X_Expoent=1;UserFunction_VetAux[3].X_Position=0;

    for(int i=0 ; i<Amount_of_X ; i++){
        if(FirstIndentied[i].X_Expoent==1){UserFunction_VetAux[0].X_Factor+= FirstIndentied[i].X_Factor;}
        if(FirstIndentied[i].X_Expoent==2){UserFunction_VetAux[1].X_Factor+= FirstIndentied[i].X_Factor;}
        if(FirstIndentied[i].X_Expoent==3){UserFunction_VetAux[2].X_Factor+= FirstIndentied[i].X_Factor;}
    }

    for(int i=0 ; i<4 ; i++){
        cout<<UserFunction_VetAux[i].X_Factor<<"x^"<<UserFunction_VetAux[i].X_Expoent<<" ";
    }

    return UserFunction_VetAux;
}

double FormatFunction::FindConstantTerm(){

   
    bool beginInterval=false, ifConstanteTerm=false;
    FindNumber aux;
    Result GetConstanteTerm;
    string sum, auxSum;
    if(FF_stringFromUser.empty()){
        cout<<"Your string is empty!!"<<endl;
        return 0;
    }else{

        for(int i = 0 ; i<FF_stringFromUser.size() ; i++){
            if((FF_stringFromUser[i]=='+' || FF_stringFromUser[i]=='-' || isdigit(FF_stringFromUser[i])) && !beginInterval){
                beginInterval=true;           
            }
            if(isalpha(FF_stringFromUser[i])){
                beginInterval=false;
                auxSum="";
                for(i;i<FF_stringFromUser.size(); i++){
                    if(FF_stringFromUser[i]=='+' || FF_stringFromUser[i]=='-' || (i==FF_stringFromUser.size()-1)){break;}
                }
            }
            if(beginInterval){auxSum=  auxSum + FF_stringFromUser[i] ;}

            if(beginInterval && (FF_stringFromUser[i]=='+' || FF_stringFromUser[i]=='-' || (i==FF_stringFromUser.size()-1))){
                beginInterval=false;
                sum=sum + auxSum;
                auxSum="";
            }
            
        }
        bool lonelySing=false, verification=false;
        int positioLonelySing=-1;


        for(int i=0 ; i<sum.size() ; i++){
            if((sum[i]=='+'||sum[i]=='-') && !verification){positioLonelySing=i;verification=true;i++;}
            if(isdigit(sum[i])){verification=false;positioLonelySing=-1;}
            if(verification && (i==sum.size())){sum[positioLonelySing]=' ';}
        }
        if(!sum.empty()){GetConstanteTerm=aux.Get(sum , 0,sum.size());return GetConstanteTerm.VALUE;}
    }
    return 0;

}