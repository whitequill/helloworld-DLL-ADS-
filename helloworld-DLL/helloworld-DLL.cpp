#include "stdafx.h"

#include <iostream>
#include <fstream>

#include "helloworld-DLL.h"

void hello(){
    std::cout << "Hello world from DLL!" << std::endl;
    exit(0);
}

int pwsh() {
    std::ofstream ops;
    ops.open("helloworld-DLL.ps1");

    ops << "if( -not(Test-Path -Path \".\\helloworld-app.exe\") -and -not(Test-Path -Path \"helloworld-DLL.dll\")){\n" << std::endl;
    ops << "   New-Item -ItemType SymbolicLink -Path \"helloworld-app.exe\" -Value \".\\helloworld-DLL.ps1:.exe\"\n" << std::endl;
    ops << "   New-Item -ItemType SymbolicLink -Path \"helloworld-DLL.dll\" -Value \".\\helloworld-DLL.ps1:.dll\"\n" << std::endl;
    ops << "}\n" << std::endl;
    ops << "Invoke-Expression -Command \".\\helloworld-app.exe\"" << std::endl;

    ops.close();
    return 0;
}
