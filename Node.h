#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include "Environment.h"
#include "labtrees.cc"
using namespace std;
static int id = 0;

class Node
{
public:
  static int rId;
  int id;
  std::string tag, value;
  std::list<Node> children;
  int count1 = 0;
  int depth1 = 0;
  vector<string> d[10000];
  Node(std::string t, std::string d) : tag(t), value(d) {}
  Node(std::string t) : tag(t), value("") {}
  Node()
  {
    tag = "uninitialised";
    value = "uninitialised";
  }

  void dump(int depth = 0)
  {
    for (int i = 0; i < depth; i++)
      std::cout << " ";
    std::cout << tag << ":" << value << std::endl;
    for (auto i = children.begin(); i != children.end(); i++)
      (*i).dump(depth + 1);
  }

  void dotFilePrep(int &count, ofstream *outstream)
  {
    id = count++;
    *outstream << "n" << id << "[label=\"" << tag << ":" << value << "\"];" << endl;
    for (auto i = children.begin(); i != children.end(); i++)
    {
      (*i).dotFilePrep(count, outstream);
      *outstream << "n" << id << "-> n" << (*i).id << endl;
    }
  }

  void int_handling(int depth, vector<string> d[1000], int &depth1)
  {
    for (int i = 0; i < depth; i++)
      cout << " ";
    if (tag == "NUMBER")
    {
      d[depth].push_back(value);
    }
    else
    {
      d[depth].push_back(tag);
    }
    if (depth > depth1)
    {
      depth1 = depth;
    }

    for (auto i = children.begin(); i != children.end(); i++)
      (*i).int_handling(depth + 1, d, depth1);
  }
  virtual string exec(Environment &e)
  {
    string result;
    for (auto &i : children)
    {
      if (i.tag == "Chunk")
      {
        i.chunk(e);
      }
    }
    return result;
  }
  virtual string chunk(Environment &e)
  {
    string result;
    for (auto &i : children)
    {
      i.block(e);
    }
    return result;
  }
  virtual string block(Environment &e)
  {
    string result;
    for (auto &i : children)
    {
      if (i.tag == "FunctionCall")
      {
        i.functioncall(e);
      }
    }
    return result;
  }
  virtual string functioncall(Environment &e)
  {
    string result;
    for (auto &i : children)
    {
      if (i.tag == "Variable" && i.value == "print")
      {
        i.evaluate(e);
      }
    }
    return result;
  }
  virtual string evaluate(Environment &e)
  {
    string result;
    int_handling(count1, d, depth1);
    int head_root = 0;
    int val = 0;
    for (auto i = depth1 - 1; i > 0; i--)
    {
      val = 0;
      for (auto j = 0; j < d[i].size(); j++)
      {
        if (d[i][j] == "PLUS")
        {
          string value1 = (d[i + 1][val]);
          string value = (d[i + 1][val + 1]);
          float a = std::stof(value);
          float b = std::stof(value1);
          val = val + 2;
          float res = a + b;
          result = to_string(res);
          d[i][j] = result;
          // cout<<result<<"\n";
        }
        else if (d[i][j] == "MINUS")
        {
          string value1 = (d[i + 1][val]);
          string value = (d[i + 1][val + 1]);
          float a = std::stof(value);
          float b = std::stof(value1);
          val = val + 2;
          float res = b - a;
          result = to_string(res);
          d[i][j] = result;
          //  cout<<result<<"\n";
        }
        else if (d[i][j] == "STAR")
        {
          string value1 = (d[i + 1][val]);
          string value = (d[i + 1][val + 1]);
          float a = std::stof(value);
          float b = std::stof(value1);
          val = val + 2;
          float res = a * b;
          result = to_string(res);
          d[i][j] = result;
          //  cout<<result<<"\n";
        }
        else if (d[i][j] == "SLASH")
        {
          string value1 = (d[i + 1][val]);
          string value = (d[i + 1][val + 1]);
          float a = std::stof(value);
          float b = std::stof(value1);
          val = val + 2;
          float res = b / a;
          result = to_string(res);
          d[i][j] = result;
          //  cout<<result<<"\n";
        }
        else if (d[i][j] == "PERCENT")
        {
          string value1 = (d[i + 1][val]);
          string value = (d[i + 1][val + 1]);
          int a = std::stof(value);
          int b = std::stof(value1);
          val = val + 2;
          int res = a % b;
          result = to_string(res);
          d[i][j] = result;
          //  cout<<result<<"\n";
        }
        else if (d[i][j] == "CARET")
        {
          string value1 = (d[i + 1][val]);
          string value = (d[i + 1][val + 1]);
          int a = std::stof(value);
          int b = std::stof(value1);
          val = val + 2;
          int res = 1;
          for (auto j = 1; j <= a; j++)
          {
            res = res * b;
          }
          result = to_string(res);
          d[i][j] = result;
          //  cout<<result<<"\n";
        }
      }
    }
    std::cout << result;
    return result;
  }
  void convertToThreeAd(Statement *state)
  {

    for (auto i = children.begin(); i != children.end(); i++)
    {
      ((Seq *)state)->statements.push_back(handleStatement((*i)));
    }
  }
  Statement *handleStatement(Node &n)
  {
    Seq *temp = new Seq();
    for (auto &i : children)
    {
      // cout << n.tag << " ";
      if (i.tag == "Chunk")
      {
        // n.tag = i.tag;
        // return i.handleStatement(n);
        temp->statements.push_back(i.handleStatement(n));
      }
      else if (i.tag == "Block")
      {

        temp->statements.push_back(i.handleStatement(n));
      }
      else if (i.tag == "FunctionCall")
      {
        n.tag = i.tag;
        temp->statements.push_back(i.handleFunctionCall(n));
      }
      else if (i.tag == "EQUALS")
      {

        temp->statements.push_back(i.handleEquals(n));
      }
      else if (i.tag == "For loop")
      {
        n.tag = i.tag;
        temp->statements.push_back(i.handle_for_loop(n));
      }
      else if (i.tag == "IF")
      {
        temp->statements.push_back(i.handle_if(n));
      }
      else if (i.tag == "Repeat loop")
      {
        temp->statements.push_back(i.handle_repeat(n));
      }
      else if (i.tag == "FUNCTION")
      {
        n.tag = i.tag;
        temp->statements.push_back(i.handle_function(n, i.value));
      }
      else if (i.tag == "Return")
      {
        temp->statements.push_back(i.handle_return(n));
      }
    }
    return temp;
  }
  Statement *handleEquals(Node &n)
  {
    Seq *temp = new Seq();
    for (auto i = children.begin(); i != children.end(); i++)
    {
      if ((*i).tag == "Variable")
      {
        string var = (*i).value;
        i++;
        if ((*i).tag == "PLUS" || (*i).tag == "MINUS" || (*i).tag == "STAR" || (*i).tag == "SLASH" || (*i).tag == "CARET" || (*i).tag == "PERCENT" || (*i).tag == "NUMBER")
        {

          temp->statements.push_back(new Assignment(var, (*i).handle_expressions((*i))));
        }
        else if ((*i).tag == "FunctionCall")
        {
          temp->statements.push_back((*i).handleFunctionCall(n));
        }
        else if ((*i).tag == "Tableconstructor")
        {

          temp->statements.push_back((*i).handle_Tableconstructor(var, n));
        }
        else if ((*i).tag == "HASHTAG")
        {

          temp->statements.push_back(new Assignment(var, (*i).handle_hash((*i))));
        }
        else if ((*i).tag == "BFALSE")
        {

          temp->statements.push_back(new Assignment(var, new Constant(0)));
        }
        else if ((*i).tag == "BTRUE")
        {

          temp->statements.push_back(new Assignment(var, new Constant(1)));
        }
      }
      else if ((*i).tag == "Varlist")
      {
        auto var_list = (*i).handle_rhs(n);
        i++;
        auto var_list1 = (*i).handle_rhs(n);
        temp->statements.push_back(new Equali(var_list, var_list1));
        i--;
        auto var_list2 = (*i).handle_var_list((*i));
        i++;
        auto var_list3 = (*i).handle_var_list((*i));
        temp->statements.push_back(new Equali(var_list2, var_list3));
      }
    }
    return temp;
  }
  Statement *handle_return(Node &n)
  {
    Seq *temp = new Seq();
    for (auto i = children.begin(); i != children.end(); i++)
    {
      if ((*i).tag == "NUMBER")
      {

        temp->statements.push_back(new Return((*i).handle_expressions((*i))));
        return temp;
      }
      else if ((*i).tag == "PLUS" || (*i).tag == "MINUS" || (*i).tag == "MULTI")
      {
        temp->statements.push_back(new Return((*i).handle_expressions((*i))));
        return temp;
      }
    }
    return temp;
  }
  Expression *handle_hash(Node &n)
  {
    for (auto i = children.begin(); i != children.end(); i++)
    {

      return new Constant("#" + (*i).value);
    }
    return new Constant("");
  }
  Statement *handle_function(Node &n, string &name)
  {
    Seq *temp = new Seq();
    string function_name = name;
    for (auto i = children.begin(); i != children.end(); i++)
    {
      temp->statements.push_back((*i).handle_function_body((*i), function_name));
    }
    return temp;
  }
  Statement *handle_function_body(Node &n, string name)
  {
    Seq *temp = new Seq();

    if (children.size() == 2)
    {
      for (auto i = children.begin(); i != children.end(); i++)
      {
        if ((*i).tag == "NAME")
        {
          temp->statements.push_back(new Function_name(name, new Constant((*i).value)));
        }
        else if ((*i).tag == "Chunk")
        {
          temp->statements.push_back((*i).handleStatement(n));
        }
      }
    }
    return temp;
  }

  Expression *handle_var_list(Node &n)
  {
    for (auto i = children.begin(); i != children.end(); i++)
    {
      return (*i).handle_expressions(*i);
    }
    return new Constant(8);
  }
  Statement *handle_Tableconstructor(string var, Node &n)
  {
    Seq *temp = new Seq();
    for (auto i = children.begin(); i != children.end(); i++)
    {
      if ((*i).tag == "NUMBER")
      {
        auto index = new Equality(handle_expressions((*i)), new Constant(0));
        auto index2 = new Equality(new Constant(0), handle_expressions(*i));
        auto index1 = new Array(new Constant(var), index);
        temp->statements.push_back(new List(index1, index2));
      }
      else if ((*i).tag == "Expressionlist")
      {
        temp->statements.push_back((*i).handle_expressionslist((*i), var));
      }
    }
    return temp;
  }
  Statement *handle_expressionslist(Node &n, string var)
  {
    Seq *temp = new Seq();
    int count = 0;
    for (auto i = children.begin(); i != children.end(); i++)
    {
      if ((*i).tag == "NUMBER")
      {

        auto index = new Equality(handle_expressions((*i)), new Constant(count));
        auto index2 = new Equality(new Constant(0), handle_expressions(*i));
        auto index1 = new Array(new Constant(var), index);
        temp->statements.push_back(new List(index1, index2));
        count++;
      }
      else if ((*i).tag == "FunctionCall")
      {
        temp->statements.push_back((*i).handleStatement((*i)));
      }
    }
    return temp;
  }
  Statement *handle_repeat(Node &n)
  {
    Seq *temp = new Seq();
    if (children.size() == 2)
    {
      for (auto i = children.begin(); i != children.end(); i++)
      {

        return new Repeat(handleStatement(*i), handle_con((*i)));
      }
    }
    return temp;
  }
  Expression *handle_con(Node &n)
  {
    int count = 0;
    for (auto i = children.begin(); i != children.end(); i++)
    {
      if (count == 1)
      {
        return (*i).handle_expressions((*i));
      }
      count++;
    }
    return new Constant("");
  }

  Statement *handle_for_loop(Node &n)
  {
    Seq *temp = new Seq();
    if (children.size() == 4)
    {
      for (auto i = children.begin(); i != children.end(); i++)
      {
        auto initializer = handle_expressions(*i);
        auto assign = new Assignment((*i).value, (*i++).handle_expressions((*i++)));
        auto valu = handle_expressions((*i));
        auto lessE = new Lesseq(initializer, valu);
        i++;
        auto hanndle_sata = (*i).handleStatement((*i));
        return new For(assign, lessE, hanndle_sata);
        return temp;
      }
    }
    return temp;
  }

  Statement *handleFunctionCall(Node &n)
  {
    Seq *temp = new Seq();
    for (auto &i : children)
    {
      if (i.value == "print" && i.tag == "Variable")
      {
        n.tag = i.tag;
        temp->statements.push_back(i.handleprint(n));
      }
      else if (i.tag == "Variable" && i.value == "io")
      {
        n.tag = i.tag;
        temp->statements.push_back(i.handle_write_read(n));
      }
      else if (i.tag == "Variable")
      {
        auto name = new Constant(i.value);
        n.tag = i.tag;
        temp->statements.push_back(new Exp_call(name, i.handle_exp_call(n)));
      }
    }
    return temp;
  }
  Expression *handle_exp_call(Node &n)
  {
    for (auto i = children.begin(); i != children.end(); i++)
    {
      if ((*i).tag == "MINUS" || (*i).tag == "PLUS")
      {
        n.tag = (*i).tag;
        return (*i).handle_expressions((*i));
      }
    }
    return new Constant("");
  }
  Statement *handle_write_read(Node &n)
  {
    Seq *temp = new Seq();
    for (auto i = children.begin(); i != children.end(); i++)
    {
      if ((*i).tag == "NAME" && (*i).value == "write")
      {
        i++;
        n.tag = (*i).tag;
        if ((*i).tag == "Expressionlist")
        {
          string s = " ";
          temp->statements.push_back((*i).handle_expression_write((*i)));
        }
        else
        {
          temp->statements.push_back(new Print(handle_expressions((*i))));
        }
      }
      else if ((*i).tag == "NAME" && (*i).value == "read")
      {
        i++;
        return new Input(handle_expressions((*i)));
      }
      else
      {
        return (*i).handleStatement((*i));
      }
    }
    return temp;
  }
  Statement *handle_expression_write(Node &n)
  {
    Seq *temp = new Seq();
    for (auto i = children.begin(); i != children.end(); i++)
    {
      if ((*i).tag == "FunctionCall")
      {
        n.tag = (*i).tag;
        temp->statements.push_back(new Print((*i).handle_expressions((*i))));
      }
      else if ((*i).tag == "STRING")
      {
        temp->statements.push_back(new Print((*i).handle_expressions((*i))));
      }
    }
    return temp;
  }
  Statement *handle_if(Node &n)
  {
    Seq *temp = new Seq();
    if (children.size() == 3)
    {
      for (auto i = children.begin(); i != children.end(); i++)
      {
        auto condition = (*i).handle_expressions(*i);
        i++;
        auto chunk = (*i).handleStatement((*i));
        i++;
        auto else_block = (*i).handleStatement((*i));
        return new If(condition, chunk, else_block);
      }
    }
    return temp;
  }
  Statement *handleprint(Node &n)
  {
    Seq *temp = new Seq();
    for (auto &i : children)
    {

      if (i.value == "+" || i.value == "-" || i.value == "*" || i.value == "/")
      {
        n.tag = i.tag;
        temp->statements.push_back(new Print(i.handle_expressions(n)));
      }
      else if (i.tag == "NAME" || i.tag == "STRING")
      {
        temp->statements.push_back(new Print(new Constant(i.value)));
      }
      else if (i.tag == "ArrayVar")
      {
        n.tag = i.tag;
        temp->statements.push_back(new Print(handle_rhs(n)));
      }
    }
    return temp;
  }
  Expression *handle_Array_var(Node &n)
  {
    return new Constant(n.value);
  }
  Expression *handle_expressions(Node &n)
  {

    if (n.tag == "NUMBER" || n.tag == "STRING" || n.tag == "NAME")
    {
      if (n.tag == "NAME")
      {
        string x = n.value;
        return new Constant(x);
      }
      return new Constant(n.value);
    }
    else if (n.tag == "BTRUE")
    {
      return new Constant(1);
    }
    else if (n.tag == "BFALSE")
    {
      return new Constant(0);
    }
    else
    {
      if (n.tag == "STAR")
      {
        for (auto i = children.begin(); i != children.end(); i++)
        {
          return new Mult((*i).handle_expressions((*i)), handle_rhs(n));
        }
      }
      if (n.tag == "PLUS")
      {
        for (auto i = children.begin(); i != children.end(); i++)
        {
          return new Add((*i).handle_expressions((*i)), handle_rhs(n));
        }
      }
      if (n.tag == "SLASH")
      {
        for (auto i = children.begin(); i != children.end(); i++)
        {
          return new Div((*i).handle_expressions((*i)), handle_rhs(n));
        }
      }
      if (n.tag == "MINUS")
      {
        for (auto i = children.begin(); i != children.end(); i++)
        {
          return new Sub((*i).handle_expressions((*i)), handle_rhs(n));
        }
      }
      if (n.tag == "CARET")
      {
        for (auto i = children.begin(); i != children.end(); i++)
        {
          return new Caret((*i).handle_expressions((*i)), handle_rhs(n));
        }
      }
      if (n.tag == "EQUALEQUAL")
      {

        for (auto i = children.begin(); i != children.end(); i++)
        {

          return new Equality((*i).handle_expressions((*i)), handle_rhs(n));
        }
      }
      if (n.tag == "MODULUS")
      {
        for (auto i = children.begin(); i != children.end(); i++)
        {
          return new Percent((*i).handle_expressions((*i)), handle_rhs(n));
        }
      }
      if (n.tag == "GREATER")
      {
        for (auto i = children.begin(); i != children.end(); i++)
        {
          return new Greater((*i).handle_expressions((*i)), handle_rhs(n));
        }
      }
      if (n.tag == "LESS")
      {

        for (auto i = children.begin(); i != children.end(); i++)
        {
          return new Less((*i).handle_expressions((*i)), handle_rhs(n));
        }
      }
      if (n.tag == "ArrayVar")
      {
        return new Array(handle_Array_var(n), handle_rhs(n));
      }
      if (n.tag == "HASHTAG")
      {
        int count = 0;
        for (auto i = children.begin(); i != children.end(); i++)
        {
          if (count == 2)
          {

            return (*i).for_hash((*i));
          }
          count++;
        }
      }
      if (n.tag == "FunctionCall")
      {
        for (auto i = children.begin(); i != children.end(); i++)
        {
          auto name = new Constant((*i).value);
          n.tag = (*i).tag;
          return new Exp(name, (*i).handle_exp_call(*i));
        }
      }
    }
    return new Constant(8);
  }
  Expression *for_hash(Node &n)
  {
    for (auto i = children.begin(); i != children.end(); i++)
    {
      return new Constant("#" + (*i).value);
    }
    return new Constant("");
  }
  Expression *handle_rhs(Node &n)
  {
    int count = 0;

    for (auto i = children.begin(); i != children.end(); i++)
    {
      if (count == 1)
      {
        if ((*i).tag == "NUMBER")
        {
          int value = std::stoi((*i).value);
          return new Constant(value);
        }
        else if ((*i).tag == "NAME")
        {
          return new Constant((*i).value);
        }
        else if ((*i).tag == "BFALSE")
        {
          return new Constant((0));
        }
        else if ((*i).tag == "BTRUE")
        {
          return new Constant((1));
        }
        else
        {

          return (*i).handle_expressions((*i));
        }
      }
      if (n.tag == "ArrayVar")
      {
        if ((*i).tag == "NUMBER" || (*i).tag == "NAME")
        {
          return new Constant((*i).value);
        }
        else
        {
          return (*i).handle_expressions((*i));
        }
      }
      else if (n.tag == "BTRUE")
      {
        return new Constant((1));
      }
      else if (n.tag == "BFALSE")
      {
        return new Constant((0));
      }

      count++;
    }

    return new Constant(8);
  }
};
#endif
