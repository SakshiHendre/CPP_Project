# C++ Project - Simple Program

This is a simple C++ project that prints a message to the console. It was created as a basic example for compiling and pushing a project using MinGW-w64 and GitHub.

##  Features

- Uses standard C++
- Console output
- Built with MinGW-w64 on Windows

##  Prerequisites

- C++ Compiler (e.g., MSYS2,MinGW-w64 or GCC)
- Git
- VSCode (optional, but recommended)

## Problems I faced during the setup
doesn't display the output on the command prompt of vscode ,

ld.exe: cannot find version: No such file or directory
collect2.exe: error: ld returned 1 exit status

encountered above error and this error usually means that MSYS2 environment is mixing 
incompatible tools or missing some files, specifically the linker is failing due to 
misconfigured paths or missing libraries

fixed it by following:-
Open the MSYS2 UCRT64 shell (C:\msys64\ucrt64\usr\bin\bash.exe or via start menu).

Navigate to your source directory (use MSYS path syntax):

cd /c/VSCode_file
g++ main.cpp -o main.exe
./main.exe

This ensures all MSYS2 runtime libs and environment variables are correctly loaded.
PS. still figuring out why don't it show the output on the command prompt terminal of vscode 


