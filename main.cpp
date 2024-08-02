#include <iostream>
#include <stdio.h>
#include <chrono>
#include <thread>

#include "C:\Program Files (x86)\Lua\5.1\include\lua.hpp"
#include "C:\Program Files (x86)\Lua\5.1\include\lauxlib.h"

using namespace std;


// Função para executar o script Lua e o contador
void executarLuaEContador() {
    // Iniciar Lua
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    // Executar o script Lua
    if (luaL_dofile(L, "./lib/main.lua") != 0) {
        fprintf(stderr, "Erro: %s\n", lua_tostring(L, -1));
    }

    lua_close(L);
}

// Função principal
int main() {
    auto inicio = chrono::high_resolution_clock::now();

    // Criar uma thread para executar o Lua e o contador
    std::thread t(executarLuaEContador);

    // Esperar a thread terminar
    t.join();

    auto fim = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = fim - inicio;

    cout << "Tempo de execução: " << duration.count() << " segundos" << endl;

    system("PAUSE");
    return 0;
}
