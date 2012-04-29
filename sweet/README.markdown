# Sweet Lua

## Introduction

[Sweet Lua](http://www.sweetsoftware.co.nz/lua_overview.html) is a C++ to Lua binding library which have some nice features:

* Bind C++ functions as Lua functions and closures with out of order parameters. 
* Bind C++ objects as Lua tables with lifetime controlled by either C++ or Lua. 
* Coroutines. 
* Type safety. 
* Error handling. 
* Convert C++ iterator sequences to Lua iterators. 
* STL vector, list, set, and map integration. 
* Boost Filesystem integration.


So I decided port it to [NTL](http://ontl.org) (light VC++ runtime) to use at own projects.
