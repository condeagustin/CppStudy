@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x64     
set compilerflags=/Od /Zi /EHsc /std:c++latest
set linkerflags=/OUT:Test.exe
cl.exe %compilerflags% main.cpp /link %linkerflags%