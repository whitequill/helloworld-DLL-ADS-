**This should be obvious, but this will only work on NTFS!**  
_I have never seen or heard of this being done before; this whole project is a proof-of-concept_.

**be sure to change the command line variables in the Linker in the Project properties for `helloworld-DLL` and `helloworld-app` or you'll get build errors cause the output path doesn't exist.**

This is a test project which compiles an Executable and Dynamic Link-Library into Alternate-Data-Streams (ADS) I have named `helloworld-DLL.ps1:.exe` and `helloworld-DLL.ps1:.dll`.  The Powershell script, when run, will create symbolic links to the streams and name them; `helloworld-app.exe` and `helloworld-DLL.dll`.  Files seem to be able to tell what other files are in the directory with it.  So you can't just run `helloworld-DLL.ps1:.exe` it will complain there is no `.dll` file even though its in a data stream in the same file!  The files need to be next to each other in the same directory.  I do not know why.

I have not figured out how to have files recognize they are in streams in the same file or if this is even possible.

Also building as _Debug_ does not work!  You **must** build as _Release_.  I have not figured out why this is either.

_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

If you are going to do this project I highly suggest building this File manager as it allows you to see Alternate-Data-Streams as files in the file browser as an option.
https://github.com/files-community/Files/

It is a WinUI3 application so running it can be a little confusing.

If you're having trouble make a shortcut file and paste: `C:\Windows\explorer.exe shell:appsFolder\FilesDev_ykqwq8d6ps0ag!App` into it.

This is cause the program isn't runnable though the exe file its self.  Make sure you deploy the solution after building or it can't be run; as far as I know. (which I don't know) This is just what I have found.
_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
There is also an issue with the PowerShell script not being input into the `.ps1` file. If so just copy-paste
```Powershell
if( -not(Test-Path -Path ".\helloworld-app.exe") -and -not(Test-Path -Path "helloworld-DLL.dll")){
    New-Item -ItemType SymbolicLink -Path "helloworld-app.exe" -Value ".\helloworld-DLL.ps1:.exe"
    New-Item -ItemType SymbolicLink -Path "helloworld-DLL.dll" -Value ".\helloworld-DLL.ps1:.dll"
    }
Invoke-Expression -Command ".\helloworld-app.exe"
```
into the, probably empty, helloworld.ps1 file that should have been populated with `helloworld-DLL.cpp`.  Also hard-links don't work to link to ADS.

**By the end you should have two symbolic links one to each alternate data stream that was built.**

All of the "secret-sauce" is in the Linker settings in the Project properties.
