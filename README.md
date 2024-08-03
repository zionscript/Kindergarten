## A Lua-CPP toolkit for HPC simulations and IA forge

### First Step:
- Download Lua Binaries from [https://lua.org]
- Rename Lua libs in libs folder

### Second Step:
- Include Lua files in C++ code
  
### Example:
```cpp
#include <iostream>
#include <stdio.h>
#include "C:/Lua/5.1/include/lua.hpp"

int main() {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    if (luaL_dofile(L, "./lib/main.lua") != 0) {
        fprintf(stderr, "Error: %s\n", lua_tostring(L, -1));
        return -1;
    }

    lua_close(L);
    system("PAUSE");
}
```

### C++ to Lua

<code>g++ main.cpp -I "C:\Program Files (x86)\Lua\5.1\include" -L "C:\Program Files (x86)\Lua\5.1\lib" -llua -shared -fpic -o "nome da lib final".dll</code>

### Lua to C++

<code>g++ main.cpp -I "C:\Program Files (x86)\Lua\5.1\include" -L "C:\Program Files (x86)\Lua\5.1\lib" -llua -o main</code>