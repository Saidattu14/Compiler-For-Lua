#define ENVIRONMENT_H
#include <string>
#include <map>

class Environment{
public:
  std::map <std::string, std::string> env;
  Environment() {}
  void addVariable(std::string name, std::string value)
  {
    env[name] = value;
  }
  std::string getVariableValue(std::string name)
  {
    if(env.find(name)->second != "")
    {
      return env.find(name)->second;
    }
    else
    {
      return "";
    }
  }
};