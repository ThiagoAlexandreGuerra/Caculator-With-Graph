#include <iostream>
#include <cmath>

#include "GerPoints.h"

using namespace std;


GerPoints::GerPoints(){}

GerPoints_result GerPoints::Get(string S){
   
    return Lending(S);
}

GerPoints_result GerPoints::Lending(string S){

    LinearFunctionResponse.FindFirstRoot=false;
    LinearFunctionResponse.FindSecondRoot=false;
    LinearFunctionResponse.FindThirdRoot=false;

    QuadraticFunctionResponse.FindFirstRoot=false;
    QuadraticFunctionResponse.FindSecondRoot=false;
    QuadraticFunctionResponse.FindThirdRoot=false;

    CubicFunctionResponse.FindThirdRoot=false;
    CubicFunctionResponse.FindThirdRoot=false;
    CubicFunctionResponse.FindThirdRoot=false;


    FunctionFromUser= new X_Type[4]();
    FormatFunction GiveMeTheFormatFunction;

    FunctionFromUser=GiveMeTheFormatFunction.Get(S);

    cout<<"In Brain_______________________________________________________________________________:"<<endl;
    for(int i=0 ; i<4 ; i++){
        cout<<" "<<(FunctionFromUser[i].X_Factor>0?"+":"")<<FunctionFromUser[i].X_Factor<<(FunctionFromUser[i].X_Expoent>0?"X^":"^")<<(FunctionFromUser[i].X_Expoent>0?(FunctionFromUser[i].X_Expoent):1);
    }
    cout<<endl<<endl<<"success!!!!!!_______________________________________________________________________________|"<<endl;
    DefineFunctionType();

    if(HowIsTheTypeOfFunction==1){LinearFunction(); return LinearFunctionResponse;}
    if(HowIsTheTypeOfFunction==2){QuadraticFunction(); return QuadraticFunctionResponse;}
    if(HowIsTheTypeOfFunction==3){CubicFunction();cout<<"| GerPoint send!!!!!!!!!!!"<<endl; return CubicFunctionResponse;}

} 

void GerPoints::DefineFunctionType(){

    for(int i=0 ; i<3 ; i++){
        if(FunctionFromUser[i].X_Factor!=0){
            HowIsTheTypeOfFunction=FunctionFromUser[i].X_Expoent;}
    }
}

void GerPoints::LinearFunction(){
    FindDerivative(LinearFunctionResponse);
    LinearFunctionResponse.TypeOfFunction=1;

    LinearFunctionResponse.slope=FunctionFromUser[0].X_Factor;
    LinearFunctionResponse.ConstantTerm=FunctionFromUser[3].X_Factor;

    double a=0 , b=0 , Root=0;

    a= LinearFunctionResponse.slope;
    b=LinearFunctionResponse.ConstantTerm;

    Root=-1*(b/a);

    LinearFunctionResponse.FirstRoot=Root;
    LinearFunctionResponse.FindFirstRoot=true;
    LinearFunctionResponse.MyCordinates_Length=1003;
    LinearFunctionResponse.MyCoordinates=new Coordinates[1003]();

    int I= Root-500;
    int Aux=0;

    double y=0;
    for(Aux; Aux<1000 ; Aux++){
        
        LinearFunctionResponse.MyCoordinates[Aux].X=(I);
        y=(I)*a + b;
        LinearFunctionResponse.MyCoordinates[Aux].Y=y;
        I++;
    }

    cout<<endl<<" LinearFunctionResponse.slope_________: "<< LinearFunctionResponse.slope<<endl;
    cout<<endl<<" LinearFunctionResponse.ConstantTerm__:"<< LinearFunctionResponse.ConstantTerm<<endl;
    cout<<endl<<" LinearFunctionResponse.FirstRoot_____:"<< LinearFunctionResponse.FirstRoot<<endl;
    
    
}

void GerPoints::QuadraticFunction(){
    FindDerivative(QuadraticFunctionResponse);
    QuadraticFunctionResponse.TypeOfFunction=2;


    double Delta=0, A=0 , B=0 , C=0 , ROOT1=0, ROOT2=0 ;
    bool IfDeltaValid=false;

    QuadraticFunctionResponse.slope=FunctionFromUser[1].X_Factor;
    QuadraticFunctionResponse.B_Coefficient=FunctionFromUser[0].X_Factor;
    QuadraticFunctionResponse.ConstantTerm=FunctionFromUser[3].X_Factor;

    A=QuadraticFunctionResponse.slope;
    B=QuadraticFunctionResponse.B_Coefficient;
    C=QuadraticFunctionResponse.ConstantTerm;

    Delta=(pow(B,2))-4*A*C;
    QuadraticFunctionResponse.Delta=Delta;

    if(Delta>0){IfDeltaValid=true;}

    if(IfDeltaValid){

        ROOT1=((-1*B)-(sqrt(Delta)))/(2*A);
        ROOT2=((-1*B)+(sqrt(Delta)))/(2*A);
        QuadraticFunctionResponse.FirstRoot=ROOT1;
        QuadraticFunctionResponse.SecondRoot=ROOT2;
        QuadraticFunctionResponse.FindFirstRoot=true;
        QuadraticFunctionResponse.FindSecondRoot=true;

    }

    double X_Vetex=0;
    double Y_Vetex=0;

    X_Vetex=-1*(B/(2*A));
    Y_Vetex=-1*((Delta)/(4*A));

    QuadraticFunctionResponse.Vertex.X=X_Vetex;
    QuadraticFunctionResponse.Vertex.Y=Y_Vetex;

    double Range=fabs( ROOT1-ROOT2 );
    int Length=0;

    if((Range>0) && (Range<100) ){Length=5000;}
    if((Range>=100) && (Range<300) ){Length=5500;}
    if((Range>=300) && (Range<600) ){Length=6500;}
    if((Range>=600) && (Range<1000) ){Length=10000;}
    
    QuadraticFunctionResponse.MyCordinates_Length=Length;

    QuadraticFunctionResponse.MyCoordinates=new Coordinates[Length]();

    if(ROOT1>ROOT2){swap(ROOT1,ROOT2);}
    
    double X=0;
    if(Length==5000){X=ROOT1-1050;} 
    if(Length==5500){X=ROOT1-1350;} 
    if(Length==6500){X=ROOT1-1480;} 
    if(Length==10000){X=ROOT1-1750;} 
    
    double Y=0;

    for(int i = 0 ; i<Length ; i++){
        Y=(A*(pow(X,2))) + (B*X) + C;
        QuadraticFunctionResponse.MyCoordinates[i].X=X;
        QuadraticFunctionResponse.MyCoordinates[i].Y=Y;
        if(Y==0){cout<<"****************************************************************************"<<endl<<endl;}
        X=X+0.225;
    }
    
     
    cout<<"QuadraticFunctionResponse.slope__________: "<<QuadraticFunctionResponse.slope<<endl;
    cout<<"QuadraticFunctionResponse.B_Coefficient__: " <<QuadraticFunctionResponse.B_Coefficient<<endl;
    cout<<"QuadraticFunctionResponse.ConstantTerm___: "<<QuadraticFunctionResponse.ConstantTerm<<endl;
    cout<<"Delta____________________________________: "<<Delta<<endl;
    cout<<"QuadraticFunctionResponse.FirstRoot______: "<< QuadraticFunctionResponse.FirstRoot<<endl;
    cout<<"QuadraticFunctionResponse.SecondRoot_____: "<<QuadraticFunctionResponse.SecondRoot<<endl;
    cout<<"QuadraticFunctionResponse.Vertex.x_______: "<<QuadraticFunctionResponse.Vertex.X<<endl;
    cout<<"QuadraticFunctionResponse.Vertex.y_______: "<<QuadraticFunctionResponse.Vertex.Y<<endl;

   
}

void GerPoints::CubicFunction(){
    cout<<"CubicFunction_______________________________:"<<endl;
    FindDerivative(CubicFunctionResponse);
    CubicFunctionResponse.TypeOfFunction=3;

    double A=0 , B=0 , C=0, D=0;

    A=FunctionFromUser[2].X_Factor;
    B=FunctionFromUser[1].X_Factor;
    C=FunctionFromUser[0].X_Factor;
    D=FunctionFromUser[3].X_Factor;
    FuncDivisorOfX(D);
    CubicFunctionResponse.slope=A;
    CubicFunctionResponse.B_Coefficient=B;
    CubicFunctionResponse.C_Coefficient=C;
    CubicFunctionResponse.ConstantTerm=D;

    double Y=0 ;
    int X=0;
    bool first_Arrey=true;
    int if_root[5]={1,-1,3,-3};
    for(int i=0;i<DivisorOfConstantTerm_Size ; i++){ 
        if(first_Arrey){
            X=if_root[i];
            if(i==3){first_Arrey=false;i=0;}
        }else{
            X=DivisorOfConstantTerm[i];
        }

        Y= (A*(pow(X,3))) + B*(pow(X,2)) + (C*X) + D;

        if(Y==0){
           if(!CubicFunctionResponse.FindFirstRoot){
                CubicFunctionResponse.FirstRoot=X;
                CubicFunctionResponse.FindFirstRoot=true;
           }else if(!CubicFunctionResponse.FindSecondRoot){
                CubicFunctionResponse.SecondRoot=X;
                CubicFunctionResponse.FindSecondRoot=true;
           }else if(!CubicFunctionResponse.FindThirdRoot){
                CubicFunctionResponse.ThirdRoot=X;
                CubicFunctionResponse.FindThirdRoot=true;
           }
           
        }
    }
    cout<<"| CubicFunctionResponse.FirstRoot: "<<CubicFunctionResponse.FirstRoot<<endl;
    cout<<"| CubicFunctionResponse.SecondRoot: "<<CubicFunctionResponse.SecondRoot<<endl;
    cout<<"| CubicFunctionResponse.ThirdRootRoot: "<<CubicFunctionResponse.ThirdRoot<<endl;
    cout<<"| CubicFunctionResponse.FindFirstRoot: "<<CubicFunctionResponse.FindFirstRoot<<endl;
    cout<<"| CubicFunctionResponse.FindSecondRoot: "<<CubicFunctionResponse.FindSecondRoot<<endl;
    cout<<"| CubicFunctionResponse.FindThirdRoot: "<<CubicFunctionResponse.FindThirdRoot<<endl;

    if(CubicFunctionResponse.FindFirstRoot && CubicFunctionResponse.FindSecondRoot && CubicFunctionResponse.FindThirdRoot){CubicFunctionFor_THREE_Root(A,B,C,D);
    }else if(CubicFunctionResponse.FindFirstRoot && CubicFunctionResponse.FindSecondRoot){CubicFunctionFor_TWO_Root(A,B,C,D);
    }else if(CubicFunctionResponse.FindFirstRoot){CubicFunctionFor_ONE_Root(A,B,C,D);
    }else{
        cout<<"Your function no have root in reais.!!!"<<endl;
    }
    
    
    // corrigir esse cenario depois
}

void GerPoints::CubicFunctionFor_ONE_Root(double A , double B, double C, double D){
    double ROOT_1=0;

    ROOT_1= CubicFunctionResponse.FirstRoot;

    int Length=6000;

    CubicFunctionResponse.MyCordinates_Length=Length;
    CubicFunctionResponse.MyCoordinates=new Coordinates[Length]();

    double XX=ROOT_1 - 2999, Y=0;

    for(int i=0 ; i<Length ; i++){
        Y=A*(pow((XX/10),3)) + B*(pow((XX/10),2)) + C*(XX/10) + D;
        CubicFunctionResponse.MyCoordinates[i].X=XX;
        CubicFunctionResponse.MyCoordinates[i].Y=Y;
        XX+=0.255;
    }

    cout<<endl<<"A______________________________: "<<A;
    cout<<endl<<"B______________________________: "<<B;
    cout<<endl<<"C______________________________: "<<C;
    cout<<endl<<"D______________________________: "<<D;
    cout<<endl<<"CubicFunctionResponse.FirstRoot: "<<ROOT_1<<endl;
    cout<<endl<<"Length_________________________: "<<Length<<endl;

};
void GerPoints::CubicFunctionFor_TWO_Root(double A , double B, double C, double D){
    double ROOT_1=0, ROOT_2=0;

    ROOT_1= CubicFunctionResponse.FirstRoot;
    ROOT_2= CubicFunctionResponse.SecondRoot;

    if(ROOT_1>ROOT_2){
        swap(ROOT_1,ROOT_2);
    }

    double Range_1=0;
    
    Range_1=fabs(ROOT_1-ROOT_2);

    int Length= floor(Range_1) + 6000;

    CubicFunctionResponse.MyCordinates_Length=Length;

    CubicFunctionResponse.MyCoordinates=new Coordinates[Length]();

    double XX=ROOT_1 - 499, Y=0;
    
    for(int i=0 ; i<Length ; i++){
        Y=A*(pow((XX/10),3)) + B*(pow((XX/10),2)) + C*(XX/10) + D;
        CubicFunctionResponse.MyCoordinates[i].X=XX;
        CubicFunctionResponse.MyCoordinates[i].Y=Y;
        XX+=0.255;
    }

    cout<<endl<<"A______________________________: "<<A;
    cout<<endl<<"B______________________________: "<<B;
    cout<<endl<<"C______________________________: "<<C;
    cout<<endl<<"D______________________________: "<<D;
    cout<<endl<<"CubicFunctionResponse.FirstRoot: "<<ROOT_1<<endl;
    cout<<endl<<"CubicFunctionResponse.SecondRoot: "<<ROOT_2<<endl;
    cout<<endl<<"Length_________________________: "<<Length<<endl;
};
void GerPoints::CubicFunctionFor_THREE_Root(double A , double B, double C, double D){

    
    double ROOT_1=0, ROOT_2=0 , ROOT_3=0;

    ROOT_1= CubicFunctionResponse.FirstRoot;
    ROOT_2= CubicFunctionResponse.SecondRoot;
    ROOT_3= CubicFunctionResponse.ThirdRoot;

    if(ROOT_1>ROOT_2){
        swap(ROOT_1,ROOT_2);
    }

    if(ROOT_2>ROOT_3){
        swap(ROOT_2, ROOT_3);
    }

    if(ROOT_1>ROOT_2){
        swap(ROOT_1 , ROOT_2);
    }

    double Range_1=0 , Range_2=0;
    
    Range_1=fabs(ROOT_1-ROOT_2);
    Range_2=fabs(ROOT_2-ROOT_3);

    int Length= floor(Range_1) + floor(Range_2) + 6000;

    CubicFunctionResponse.MyCordinates_Length=Length;

    CubicFunctionResponse.MyCoordinates=new Coordinates[Length]();

    double XX=ROOT_1 - 499, Y=0;
    
    for(int i=0 ; i<Length ; i++){
        Y=A*(pow((XX/10),3)) + B*(pow((XX/10),2)) + C*(XX/10) + D;
        CubicFunctionResponse.MyCoordinates[i].X=XX;
        CubicFunctionResponse.MyCoordinates[i].Y=Y;
        XX++;
    }

    cout<<endl<<"A______________________________: "<<A;
    cout<<endl<<"B______________________________: "<<B;
    cout<<endl<<"C______________________________: "<<C;
    cout<<endl<<"D______________________________: "<<D;
    cout<<endl<<"CubicFunctionResponse.FirstRoot: "<<ROOT_1<<endl;
    cout<<endl<<"CubicFunctionResponse.SecondRoot: "<<ROOT_2<<endl;
    cout<<endl<<"CubicFunctionResponse.ThirdRoot: "<<ROOT_3<<endl;
    cout<<endl<<"Length_________________________: "<<Length<<endl;

};

void GerPoints::FindDerivative(GerPoints_result& whatIsTheFunction){
    cout<<"GerPoints FindDerivative_______________________________________________: "<<endl;
    int aux=HowIsTheTypeOfFunction-1;

    int length=(2*HowIsTheTypeOfFunction)-1;
    
    whatIsTheFunction.Derivatives=new X_Type[length]();
    
    if(whatIsTheFunction.Derivatives!=NULL){

        for(int i=0; i<length ; i++){
            if(i<HowIsTheTypeOfFunction){
                whatIsTheFunction.Derivatives[i].X_Factor = FunctionFromUser[i].X_Factor*FunctionFromUser[i].X_Expoent;
                whatIsTheFunction.Derivatives[i].X_Expoent = FunctionFromUser[i].X_Expoent-1;
                cout<<"| in for,  FunctionFromUser["<<i<<"].X_Factor :"<<FunctionFromUser[i].X_Factor<<endl;
                cout<<"| in for,  FunctionFromUser["<<i<<"].X_Expoent :"<<FunctionFromUser[i].X_Expoent<<endl;
                cout<<"| in for, whatIsTheFunction.Derivatives["<<i<<"].X_Factor :"<<whatIsTheFunction.Derivatives[i].X_Factor<<endl;
                cout<<"| in for, whatIsTheFunction.Derivatives["<<i<<"].X_Expoent :"<<whatIsTheFunction.Derivatives[i].X_Expoent<<endl;
                cout<<"|"<<endl;

            }else{
                whatIsTheFunction.Derivatives[i].X_Factor = whatIsTheFunction.Derivatives[aux].X_Factor*whatIsTheFunction.Derivatives[aux].X_Expoent;
                whatIsTheFunction.Derivatives[i].X_Expoent = whatIsTheFunction.Derivatives[aux].X_Expoent-1;
                cout<<"| in for,  whatIsTheFunction.Derivatives["<<aux<<"].X_Factor :"<<whatIsTheFunction.Derivatives[aux].X_Factor<<endl;
                cout<<"| in for, whatIsTheFunction.Derivatives["<<aux<<"].X_Expoent :"<<whatIsTheFunction.Derivatives[aux].X_Expoent<<endl;
                cout<<"| in for, whatIsTheFunction.Derivatives["<<i<<"].X_Factor :"<<whatIsTheFunction.Derivatives[i].X_Factor<<endl;
                cout<<"| in for, whatIsTheFunction.Derivatives["<<i<<"].X_Expoent :"<<whatIsTheFunction.Derivatives[i].X_Expoent<<endl;
                cout<<"|"<<endl;

                
                aux--;
            }
        }
        whatIsTheFunction.IfVector_Derivative_Allocated=true;
    }else{
        whatIsTheFunction.IfVector_Derivative_Allocated=false;
    }
    cout<<"_______________________________________________________________________||"<<endl;
};

void GerPoints::FuncDivisorOfX(float Number) {
    if (Number < 1) {Number*(-1);} 

    int Limit = static_cast<int>(Number / 2);
    int Aux = 0;

    for (int i = 1; i <= Limit; i++) {
        if (static_cast<int>(Number) % i == 0) {
            Aux++;
        }
    }
    Aux=Aux*2 + 2;

    DivisorOfConstantTerm = new double[Aux]();

    int Aux2 = 0;

    for (int i = 1; i <= Limit; i++) {
        if (static_cast<int>(Number) % i == 0) {
            DivisorOfConstantTerm[Aux2] = i;cout<<i;
            Aux2++;
            DivisorOfConstantTerm[Aux2] =-1*i;cout<<(-1*i)<<endl;
            Aux2++;
        }
    }

    DivisorOfConstantTerm[Aux-2]=Number;
    DivisorOfConstantTerm[Aux-1]=-1 * Number;

    for (int i = 0; i < Aux; i++) {
        std::cout << DivisorOfConstantTerm[i] << " ";
    }
    
    DivisorOfConstantTerm_Size=Aux;

}

GerPoints::~GerPoints(){

    delete [] DivisorOfConstantTerm;
    delete [] FunctionFromUser;
}