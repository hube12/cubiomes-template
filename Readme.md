# Cubiome template with cmake support

## Install an IDE or text editor

- Clion : https://www.jetbrains.com/clion/
- Intellij : https://www.jetbrains.com/idea/
- VSCode: https://code.visualstudio.com/
- Atom, sublime-text, Notepad++, Netbeans...

## Install a C/C++ toolchain

### Linux
- Debian based (Ubuntu/Devuan...):

`apt install gcc g++ clang cmake`

- Arch based :

`yum install gcc g++ clang cmake`

- Fedora based (RHEL) :

`dnf install gcc g++ clang cmake`

### Windows (select one of those toolchains)
  
#### Select your toolchain

- WSL : https://docs.microsoft.com/windows/wsl/install-win10

Install as in the docs, your computer might reboot. Go in a powershell/cmd/terminal and type 
`wsl` you should be greeted by an error message saying no distribution are installed if so then
you did it correctly, if not then you have an issue, read the FAQ of Microsoft. Go in the Microsoft
Windows Store and search for debian, install the first result (should be a spiral in pink circle logo),
you don't need an account! to `Get` it, just close the prompt when it ask and wait for the button to change to install.
Now that it is installed, you should be able to search for debian in your windows search bar and then click on the 
result. It will open a shell and install debian, now open another shell and type wsl, you should be able to enter in a
linux subsystem. Now install a ssh server (follow this guide https://www.jetbrains.com/help/clion/how-to-use-wsl-development-environment-in-product.html#wsl-general).
Make sure like linux to install gcc g++ and cmake `sudo apt update && sudo apt install gcc g++ cmake`
Check you can connect externally with `ssh <user>@localhost -p 2222`.

- MSYS2 (mingw): https://www.msys2.org/

Follow the guide here to install the necessary packages https://github.com/orlp/dev-on-windows/wiki/Installing-GCC--&-MSYS2
Commands are `pacman -Syuu` (might need to close prompt) then 
`pacman -Syuu && pacman -S --needed base-devel mingw-w64-i686-toolchain mingw-w64-x86_64-toolchain git subversion mercurial mingw-w64-i686-cmake mingw-w64-x86_64-cmake`

- Cygwin : https://www.cygwin.com/

To install that one, download the executable (https://www.cygwin.com/setup-x86_64.exe) then
click next, next (from internet), next (C:\cygwin64), next (don't touch local),
next (use proxy settings), select a mirror (cygwin.mirror.constant.com for example) next.
Now on the View menu select Full, then in the search type `gcc-g++` and select `gcc-g++` in
the list (click on skip and select latest non Test version 10.2.XX as of right now),type 
in search bar `make` then install `make` (scroll down)  and finally type in
search bar `cmake` then install `cmake` the same way (my version is 3.20.XXX).


#### Make sure your toolchain is correctly installed

Add to the PATH variable (https://www.architectryan.com/2018/03/17/add-to-the-path-on-windows-10/) the toolchain for msys and cygwin only for wsl check ssh works.
Now open a command line and log in via ssh for wsl (don't for others) and run `cmake --version`
this should print a number and not an error, if not then something is wrong.

## Run this project
### Clone the project
Install git if you don't have it: https://git-scm.com/book/en/v2/Getting-Started-Installing-Git
```shell
git clone --recurse-submodules https://github.com/hube12/cubiomes-template
```

### Test the config

Go in CMakeLists.txt at the root and change the project name to your liking (project_name)
Go in src/CMakeLists.txt and change the `set(NAME cubiomes-example)` to your liking (executable_name)
Try run cmake from command line `cmake -Bbuild .` this should not print any errors, if any then go back
to install your toolchain step or google it.

### Run it

Now you can run it with `cmake -Bbuild . && make <executable_name> && ./<executable_name>`.

With clion a target appeared at the top that you can run directly with the little arrow or Shift+F10

## Gotcha

- Can't install a toolchain ? Google it

- Forgot to recurse submodules, run this : `git submodule update --init`

- Cmake too old? Update https://cmake.org/

- Compilation error, CXX compiler not found C Compiler not found, install gcc, g++, clang...

- Cmake not found? check in path, run ldconfig, make sure to export path in bashrc and source it

- Issue with a compiler arg? google it or open an issue
