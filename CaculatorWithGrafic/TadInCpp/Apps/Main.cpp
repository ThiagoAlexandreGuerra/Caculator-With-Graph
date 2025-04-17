#include <iostream>
#include <string>                        
#include <emscripten/emscripten.h>      

#include "ToCheckString.h"
#include "OutPutTad.h"
#include "OnlyExpression.h"

using namespace std;

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    const char* points(const char* expr) {
        static std::string result;  
        OutPutTad Test;
        ToCheckString check;
        RESULT_TochekString data;
        OnlyExpression OnEx;

        static std::string OnlyExpr;
        static std::string aux;
        data= check.Get(expr);

        if(!data.FindErro){
            if(data.is_Function){result = Test.Get(expr); return result.c_str();}
            if(data.is_Expression){OnlyExpr= OnEx.Get(expr); return OnlyExpr.c_str();}
        }
        aux=data.ERROS;
        return aux.c_str();
    }
}

int main() {
    return 0;
}
