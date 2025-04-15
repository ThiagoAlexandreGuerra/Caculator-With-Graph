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
    if(HowIsTheTypeOfFunction==3){CubicFunction(); return CubicFunctionResponse;}

} 

void GerPoints::DefineFunctionType(){

    for(int i=0 ; i<3 ; i++){
        if(FunctionFromUser[i].X_Factor!=0){
            HowIsTheTypeOfFunction=FunctionFromUser[i].X_Expoent;}
    }
}

void GerPoints::LinearFunction(){

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
    
    // for(int K=0; K<1000 ; K++){
    //     cout<<"("<<LinearFunctionResponse.MyCoordinates[K].x<<";"<<LinearFunctionResponse.MyCoordinates[K].y<<") " <<K<<" ";
    //     if(I%50==0){cout<<endl;}
    // }
    
}

void GerPoints::QuadraticFunction(){
    
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

    // for(int K=0; K<1000 ; K++){
    //     cout<<"("<<QuadraticFunctionResponse.MyCoordinates[K].x<<";"<<QuadraticFunctionResponse.MyCoordinates[K].y<<") ";
    //     if(K%50==0){cout<<endl;}
    // }
}

void GerPoints::CubicFunction(){

    CubicFunctionResponse.TypeOfFunction=3;

    double A=0 , B=0 , C=0, D=0;

    A=FunctionFromUser[2].X_Factor;
    B=FunctionFromUser[1].X_Factor;
    C=FunctionFromUser[0].X_Factor;
    D=FunctionFromUser[3].X_Factor;
    FuncDivisorOfX(D);

    double Y=0 , firstTerm=0 , SecondTerm=0 , ThirdTerm=0;

    firstTerm=A*(pow(3,3));
    ThirdTerm=C*3;
    SecondTerm=B*(pow(3,2));

    Y=firstTerm + SecondTerm + ThirdTerm + D;
    cout<<"firstTerm__: "<<firstTerm<<endl;
    cout<<"SecondTerm_: "<<SecondTerm<<endl;
    cout<<"ThirdTerm__: "<<ThirdTerm<<endl;
    if(Y==0){
        CubicFunctionResponse.FindFirstRoot=true;
        CubicFunctionResponse.FirstRoot=3;
    }
    cout<<endl<<"Y: "<<Y;

    firstTerm=A*(pow(-3,3));
    ThirdTerm=C*(-3);
    SecondTerm=B*(pow(-3,2));

    Y=A*(pow(-3,3)) + B*(pow(-3,2)) + C*(-3) + D;
    if(Y==0){
        if(!CubicFunctionResponse.FindFirstRoot){
            CubicFunctionResponse.FindSecondRoot=true;
            CubicFunctionResponse.SecondRoot=-3;
        }else{
            CubicFunctionResponse.FindFirstRoot=true;
            CubicFunctionResponse.FirstRoot=-3;
        }
    }
    cout<<"firstTerm__: "<<firstTerm<<endl;
    cout<<"SecondTerm_: "<<SecondTerm<<endl;
    cout<<"ThirdTerm__: "<<ThirdTerm<<endl;
    cout<<endl<<"Y: "<<Y;
    

    int X=0;
    for(int i=0; i<DivisorOfConstantTerm_Size; i++ ){
        X=DivisorOfConstantTerm[i];
        Y=A*(pow(X,3)) + B*(pow(X,2)) + C*(X) + D;
        cout<<endl<<"Y: "<<Y;
        cout<<endl<<"X: "<<X<<endl;
        firstTerm=A*(pow(X,3));
        ThirdTerm=C*(X);
        SecondTerm=B*(pow(X,2));
        cout<<"firstTerm__: "<<firstTerm<<endl;
        cout<<"SecondTerm_: "<<SecondTerm<<endl;
        cout<<"ThirdTerm__: "<<ThirdTerm<<endl;


        if(Y==0){
            if(!CubicFunctionResponse.FindFirstRoot){
                CubicFunctionResponse.FindFirstRoot=true;
                CubicFunctionResponse.FirstRoot=X;
            }else if(!CubicFunctionResponse.FindSecondRoot){
                CubicFunctionResponse.FindSecondRoot=true;
                CubicFunctionResponse.SecondRoot=X;
            }else if(!CubicFunctionResponse.FindThirdRoot){
                CubicFunctionResponse.FindThirdRoot=true;
                CubicFunctionResponse.ThirdRoot=X;
            }
        }
    }

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

    int Length= floor(Range_1) + floor(Range_2) + 1000;

    CubicFunctionResponse.MyCordinates_Length=Length;

    CubicFunctionResponse.MyCoordinates=new Coordinates[Length]();

    double XX=Range_1 - 499;

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

    // for(int K=0; K<1000 ; K++){
    //     cout<<"("<<CubicFunctionResponse.MyCoordinates[K].x<<";"<<CubicFunctionResponse.MyCoordinates[K].y<<") ";
    //     if(K%50==0){cout<<endl;}
    //     if(CubicFunctionResponse.MyCoordinates[K].y==0){cout<<endl<<endl<<endl;}

    // }
}

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

    delete []FunctionFromUser;
}