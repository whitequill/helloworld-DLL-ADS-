**This should be obvious, but this will only work on NTFS!**  

This is a test project which compiles an Executable and Dynamic Link-Library into Alternate-Data-Streams (ADS) I have named `helloworld-DLL.ps1:.exe` and `helloworld-DLL.ps1:.dll`.  The Powershell script, when run, will create symbolic links to the streams and name them; `helloworld-app.exe` and `helloworld-DLL.dll`.  Files seem to be able to tell what other files are in the directory with it.  This is cause if you just have a link to `helloworld-app.exe` it will complain that there isn't a Dynamic Link-Library in the same directory even though its in an ADS in a file in the same directory.

I have not figured out how to have files recognize they are in streams in the same file or if this is even possible.

Also building as _Debug_ does not work!  You **must** build as _Release_.  I have not figured out why this is either.

_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

If you are going to do this project I highly suggest building this File manager as it allows you to see Alternate-Data-Streams as files in the file browser as an option.
https://github.com/files-community/Files/

It is a WinUI3 application so running it can be a little confusing.

If you're having trouble make a shortcut file and paste: `C:\Windows\explorer.exe shell:appsFolder\FilesDev_ykqwq8d6ps0ag!App` into it.

This is cause the program isn't runnable though the exe file its self.  Make sure you deploy the solution after building or it can't be run. 
_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
There is also an issue with the PowerShell script not input into the `.ps1` file. If so just copy-paste
```Powershell
if( -not(Test-Path -Path ".\helloworld-app.exe") -and -not(Test-Path -Path "helloworld-DLL.dll")){
    New-Item -ItemType SymbolicLink -Path "helloworld-app.exe" -Value ".\helloworld-DLL.ps1:.exe"
    New-Item -ItemType SymbolicLink -Path "helloworld-DLL.dll" -Value ".\helloworld-DLL.ps1:.dll"
    }
Invoke-Expression -Command ".\helloworld-app.exe"
```
into the, probably empty, helloworld.ps1 file that should have been populated with `helloworld-DLL.cpp`.
