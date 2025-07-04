#include <iostream>

#include "FindNumber.h"
#include "FormatFunction.h"

using namespace std;

FormatFunction::FormatFunction(/* args */)
{
    My_Function= (X_Type*) new X_Type[5]();
    Amount_of_X=0;
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
    int aux=0 , k=0;
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
            cout<<"| FF_stringFromUser.size()>1: "<<(FF_stringFromUser.size()>1)<<endl;
            if(FF_stringFromUser.size()>2){i=ifNextIsXToo(i,aux);}
            aux++;
        }
        
    }
    cout<<"_____________________________________________________________________|"<<endl;
}

int FormatFunction::FindLowerLimit(int currentIndex){

    int i=currentIndex;

    for(i; i!= 0 ; i-- ){
        if(FF_stringFromUser[i]=='+' || FF_stringFromUser[i]=='-' || FF_stringFromUser[i]=='/'){
            if(FF_stringFromUser[i]=='/'){return i++;}
            return i;
        }
    }

    return 0;
};

Return_FindUpperLimit FormatFunction::FindUpperLimit(int currentIndex){

    int i=currentIndex;
    bool findSing_exponentiationFirstTime=true , find_DivisionByX=false;
    Return_FindUpperLimit returnn;
    if(FF_stringFromUser[i]=='X'){i++;}
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
        if(FF_stringFromUser[i]=='/'){
            for(int k=i; k<FF_stringFromUser.size(); k++){ if(isalpha(FF_stringFromUser[k])){find_DivisionByX=true; i--;break;}}
        }
        if(FF_stringFromUser[i]=='+' || FF_stringFromUser[i]=='-' || (i==FF_stringFromUser.size()-1)||(isalpha(FF_stringFromUser[i])) || (find_DivisionByX)){
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

int FormatFunction::ifNextIsXToo(int currentIndex , int currentAux){
    cout<<"| FF_stringFromUser.size(): "<<FF_stringFromUser.size()<<endl;
    if(currentIndex+1>=FF_stringFromUser.size()){ cout<<"| No pass!!!!!!!!!!!"<<endl;return currentIndex;}
    
    if((FF_stringFromUser[currentIndex]=='X') && (currentIndex+1<FF_stringFromUser.size())){currentIndex++;}else{return currentIndex;}

    cout<<"TadInCpp FormatFunction ifNextIsXToo___: "<<endl;
    cout<<"| FF_stringFromUser["<<currentIndex<<"]: "<<FF_stringFromUser[currentIndex]<<endl;
    cout<<"| FF_stringFromUser.size(): "<<FF_stringFromUser.size()<<endl;
    cout<<"| currentIndex: "<<currentIndex<<endl;
    cout<<"| currentAux: "<<currentAux<<endl;
    bool  findX=false , firstTime=true , find_Division=false;
    FindNumber GetValue;
    Result fator;
    Result expoent;
    Result auxGet;
    Return_FindUpperLimit RFUL;

    int cont_x=0 ,k=0;
    for(k=currentIndex ; k<FF_stringFromUser.size() ; k++ ){
            if(FF_stringFromUser[k]=='/'){find_Division=true;}
            if(((FF_stringFromUser[k]=='+')||(FF_stringFromUser[k]=='-')) && (!findX)){
                cout<<"| Achive plus or minus sing and out !!!"<<endl;
                cout<<"|______________________________________||"<<endl;
                return currentIndex-1;

            }
            if((isalpha(FF_stringFromUser[k]))){
                cout<<"| FF_stringFromUser["<<k<<"] :"<<FF_stringFromUser[k]<<endl;
                findX=true;
                if(find_Division){
                    fator= GetValue.Get(FF_stringFromUser,FindLowerLimit(k),(k-1));
                    cout<<"| fator.isZero :"<<fator.isZero<<endl;
                    cout<<"| fator.VALUE :"<<fator.VALUE<<endl;
                    if(fator.isZero){fator.VALUE=0;}else{fator.VALUE=fator.VALUE==0?1:fator.VALUE;}
                    firstTime=false;

                }
                RFUL=FindUpperLimit(k);
                cout<<"| findX :"<<findX <<endl;
                cout<<"| cont_x :"<<cont_x <<endl;
                cout<<"| RFUL.IfsingExponetiation :"<<RFUL.IfsingExponetiation <<endl;
                cout<<"| RFUL.NewIndex :"<<RFUL.NewIndex <<endl;
                cout<<"| RFUL.value :"<<RFUL.value <<endl;
                if(RFUL.IfsingExponetiation){   
                    if(RFUL.value>RFUL.NewIndex){swap( RFUL.value ,RFUL.NewIndex );}
                    expoent= GetValue.Get(FF_stringFromUser, RFUL.value, RFUL.NewIndex);
                    cout<<"| expoent.isZero :"<<expoent.isZero <<endl;
                    cout<<"| expoent.VALUE :"<<expoent.VALUE <<endl;
                    
                    if(!find_Division){fator.VALUE=1;}

                }else{
                    
                    auxGet=GetValue.Get(FF_stringFromUser,(k),RFUL.value);
                    cout<<"| auxGet.isZero :"<<auxGet.isZero <<endl;
                    cout<<"| auxGet.VALUE :"<<auxGet.VALUE <<endl;
                    
                    if(auxGet.isZero){auxGet.VALUE=0;}else{auxGet.VALUE=(auxGet.VALUE==0?1:auxGet.VALUE);}
                    firstTime==true?fator.VALUE= auxGet.VALUE:fator.VALUE*= auxGet.VALUE;
                    firstTime=false;
                    expoent.VALUE=1;
                }
                cout<<"| fator.VALUE: "<<fator.VALUE <<endl;
                cout<<"| expoent.VALUE: "<<expoent.VALUE <<endl;
                cout<<"| before FirstIndentied[currentAux].X_Expoent : "<< FirstIndentied[currentAux].X_Expoent <<endl;

                if(!(expoent.VALUE==0)){
                    find_Division?FirstIndentied[currentAux].X_Factor/=fator.VALUE :FirstIndentied[currentAux].X_Factor*=fator.VALUE;
                    find_Division?FirstIndentied[currentAux].X_Expoent-=expoent.VALUE:FirstIndentied[currentAux].X_Expoent+=expoent.VALUE;
            
                }
                cout<<"|  FirstIndentied[currentAux].X_Factor :"<< FirstIndentied[currentAux].X_Factor <<endl;
                cout<<"| FirstIndentied[currentAux].X_Expoent :"<< FirstIndentied[currentAux].X_Expoent <<endl;
            
            }
    }
    cout<<"| FF_stringFromUser["<<k<<"] :"<<FF_stringFromUser[k] <<endl;
    cout<<"|________________________________________||"<<endl;
    return k;
}

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
        cout<<"| Your string is empty!!"<<endl;
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

FormatFunction::~FormatFunction(){
    delete [] My_Function;
    delete [] FirstIndentied;
}