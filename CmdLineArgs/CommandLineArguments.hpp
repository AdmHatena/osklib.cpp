#pragma once

#ifndef _OSK_COMMANDLINE_ARGUMENTS_PARSER_
#define _OSK_COMMANDLINE_ARGUMENTS_PARSER_

#include <string>
#include <vector>
#include <compare>
#include <unordered_map>

namespace osk{
  class CmdLineArgs{
    private:
    // program path
    std::string path;
    // original command line arguments
    std::string *originArgs;
    // original command line argument size
    int originArgLength;
    // arguments
    std::vector<std::string> arguments;
    // options
    std::unordered_map<std::string, std::string> options;
    public:
    // constructor
    // useWinType
    // - true : /r /t 0
    // - false: -r --time 0
    CmdLineArgs(int argc, char *argv[], bool useWinType = false);
    // destructor
    ~CmdLineArgs();
    /*/ ----- getter ----- /*/
    // get this executable binary path
    std::string getPath();
    // get argument from index
    std::string getArgument(int index);
    // get option from option name (key)
    std::string getOption(std::string key);
    // get arguments length
    int getArgumentLength();
    // get full arguments
    std::vector<std::string> getArguments();
    // get full options
    std::unordered_map<std::string, std::string> getOptions();
    /*/ ----- getter operator overload ----- /*/
    // get argument from index
    std::string operator[](int index);
    // get option from option name (key)
    std::string operator[](std::string key);
    // get argument from index
    std::string operator()(int index);
    // get option from option name (key)
    std::string operator()(std::string key);
    // comp between argument length <=> int
    bool operator<=>(int tmp);
  };
};
#endif

// compile with option in g++: -std=c++20