#include <stdexcept>
#include "CommandLineArguments.hpp"

// constructor
osk::CmdLineArgs::CmdLineArgs(int argc, char *argv[], bool useWinType){
  // ----- set original arguments ---- //
  this->originArgs = new std::string[argc];
  for(int index = 0; index < argc; index++) *(this->originArgs + index) = std::string(argv[index]);
  this->originArgLength = argc;
  // ----- get exe path ----- //
  this->path = this->originArgs[0];
  // ----- parse args ----- //
  const char prefix = useWinType ? '/' : '-';
  std::string *store = nullptr;
  for(int index = 1; index < this->originArgLength; index++){
    if(this->originArgs[index][0] == prefix){
      // option name
      std::string key;
      if(!useWinType && this->originArgs[index][1] == '-'){
        // --option
        key = this->originArgs[index].substr(2);
      } else{
        // -option or /option
        key = this->originArgs[index].substr(1);
      }
      this->options[key] = "true";
      store = &(this->options[key]);
    } else{
      // value
      if(store != nullptr)
        *store = this->originArgs[index];
      else this->arguments.push_back(this->originArgs[index]);
      store = nullptr;
    }
  }
}

// destructor
osk::CmdLineArgs::~CmdLineArgs(){
  delete[] this->originArgs;
}

// ----- getter ----- //

// get this executable binary path
std::string osk::CmdLineArgs::getPath(){
  return this->path;
}

// get argument from index
// if index exceeds the size of args, throw out_of_range exception
std::string osk::CmdLineArgs::getArgument(int index){
  if(index >= this->arguments.size())
    throw std::out_of_range("index exceeds the size of arguments");
  return this->arguments[index];
}

// get option from option name (key)
std::string osk::CmdLineArgs::getOption(std::string key){
  if(this->options.find(key) == this->options.end())
    return std::string("false");
  return this->options[key];
}

// get aguments length
int osk::CmdLineArgs::getArgumentLength(){
  return this->arguments.size();
}

// get full arguments
std::vector<std::string> osk::CmdLineArgs::getArguments(){
  return this->arguments;
}

// get full options
std::unordered_map<std::string, std::string> osk::CmdLineArgs::getOptions(){
  return this->options;
}

// ----- getter operator overload ----- //

// get argument from index
std::string osk::CmdLineArgs::operator[](int index){
  return this->getArgument(index);
}

// get option from option name (key)
std::string osk::CmdLineArgs::operator[](std::string key){
  return this->getOption(key);
}

// get argument from index
std::string osk::CmdLineArgs::operator()(int index){
  return this->getArgument(index);
}

// get option from option name (key)
std::string osk::CmdLineArgs::operator()(std::string key){
  return this->getOption(key);
}

// comp between argument length <=> int
bool osk::CmdLineArgs::operator<=>(int tmp){
  const int comp = this->arguments.size() - tmp;
  return comp ? comp / (comp < 0 ? comp * -1 : comp) : 0;
}
