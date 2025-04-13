#include <iostream>
#include <string>                        // <- necessário para std::string
#include <emscripten/emscripten.h>       // <- necessário para EMSCRIPTEN_KEEPALIVE

#include "OutPutTad.h"
using namespace std;

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    const char* points(const char* expr) {
        static std::string result;  // Static para evitar que a string seja destruída ao sair da função
        OutPutTad Test;
        result = Test.Get(expr);

        return result.c_str();  // Retorna ponteiro para o buffer interno da string
    }
}

int main() {
    return 0;
}
