#include <iostream>
#include <stdio.h>
#include <chrono>

#include <../../../../../../../Lua/5.1/include/lua.hpp>

#include "KleinbergProtocol.h"

using namespace std;

int rows, cols;

// Função para executar o script Lua e o contador
int LuaVM() {
    // Iniciar Lua
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    // Executar o script Lua
    if (luaL_dofile(L, "./lib/main.lua") != 0) {
        fprintf(stderr, "Erro: %s\n", lua_tostring(L, -1));
    }

    lua_getglobal(L, "rows");
    rows = lua_tonumber(L, -1);
    lua_pop(L, 1);

    lua_getglobal(L, "cols");
    cols = lua_tonumber(L, -1);
    lua_pop(L, 1);

    lua_close(L);
}


// Função principal
int main() {

    LuaVM();

    KleinbergProtocol kleinberg(rows, cols);

    //inicializa o torus e cria o Kleinberg Node
    kleinberg.drawGrid();
    
    kleinberg.drawNeighbour(rows, cols);

    

    cout << "[FIM]" << endl;

    system("PAUSE");
    return 0;
}
