# command line arguments parser

- [CommandLineArguments.hpp](./CommandLineArguments.hpp) (header file)
- [CommandLineArguments.cpp](./CommandLineArguments.cpp) (source code)
- [CommandLineArguments.a](./CommandLineArguments.a) (static library)

## useage
```cpp
#include "osklib.hpp"
// or
#include "osklib/CommandLineArguments.hpp"

int main(int argc, char *argv[]){
  osk::CmdLineArgs args(argc, argv);

  /*/
    example)
    /home/name/execute a b --key=yaki -val=soba c d
    =>
      args: a, b, c, d
      options: key=yaki, val=soba
      path: /home/name/execute
  /*/
}
```
and compile with option "-std=c++20", "-Wl CmdLineArgs.a" on gcc10 or over.

## documents

### constructor
```cpp
int main(int argc, char *argv[]){
  osk::CmdLineArgs args(argc, argv);
}
```
passes the arguments of the main function, int argc and char *argv[], directly to the constructor.
@
### std::string osk::CmdLineArgs::getPath();
```cpp
// command.cpp
int main(int argc, char *argv[]){
  osk::CmdLineArgs args(argc, argv);
  std::cout << "Path: \"" << args.getPath() << "\"" << std::endl;
}
```
```
PS > ls

Directory: C:\Users\name\Desktop\tempdir\

Name
----
CmdLineArgs.a
CmdLineArgs.hpp
command.cpp

PS > g++ command.cpp -o command.exe -std=c++20 -Wl CmdLineArgs.a
PS > ./command.exe
Path: C:\Users\name\Desktop\tempdir\command.exe
```
return the path of the program (executable binary) itself.

### std::string osk::CmdLineArgs::getArgument(int index);
```cpp
// command.cpp
int main(int argc, char *argv[]){
  osk::CmdLineArgs args(argc, argv);
  for(int index = 0; index < argc; index++){
    std::cout << args.getArgument(index) << std::endl;
  }
}
```
```
PS > ./command.exe 1st 2nd 3rd 4th
1st
2nd
3rd
4th
```
