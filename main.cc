#include <iostream>
#include <stdio.h>
#include <fstream>
#include "ass1.tab.hh"
#include <bits/stdc++.h>

using namespace std;
extern Node root;
extern FILE *yyin;

void yy::parser::error(std::string const &err)
{
  std::cout << "It's one of the bad ones... " << err << std::endl;
}

void dumpCFG(BBlock *start)
{
  set<BBlock *> done, todo;
  todo.insert(start);
  while (todo.size() > 0)
  {
    // Pop an arbitrary element from todo set
    auto first = todo.begin();
    BBlock *next = *first;
    todo.erase(first);
    next->dump();
    done.insert(next);
    if (next->tExit != NULL && done.find(next->tExit) == done.end())
      todo.insert(next->tExit);
    if (next->fExit != NULL && done.find(next->fExit) == done.end())
      todo.insert(next->fExit);
  }
}

void generateCFGDotFile(BBlock *start)
{
  string dotNodeStr = "", dotNodeConStr = "";
  start->dotFile(dotNodeStr, dotNodeConStr);
  dotNodeStr.insert(0, "digraph structs {\n");
  dotNodeConStr += "}";
  ofstream file("cfg.dot", ios::trunc);
  if (file.is_open())
  {
    file << dotNodeStr;
    file << dotNodeConStr;
    file.close();
  }
  else
  {
    cout << "Unable to open file\n";
  }
}
void generatetargetFile(BBlock *start)
{
  // string dotNodeStr = "", dotNodeConStr = "";
  // set<string> s;
  // int val = 0;
  // set<string> s1;
  // start->TargetFile(dotNodeStr, dotNodeConStr, s);
  // for (auto i = s.begin(); i != s.end(); i++)
  // {
  //   string a = (*i);
  //   int val = 0;
  //   for (auto i = 0; i < a.length(); i++)
  //   {
  //     if (isdigit(a[i]) == false)
  //     {
  //       val = 1;
  //     }
  //   }
  //   if (val == 1)
  //   {
  //     s1.insert((*i));
  //   }
  // }
  // string d = "";
  // for (auto i = s1.begin(); i != s1.end(); i++)
  // {
  //   if ((*i) != "print")
  //   {
  //     d += " int " + (*i) + ";\n";
  //   }
  // }
  // ofstream file("target.cc", ios::trunc);
  // if (file.is_open())
  // {
  //   file << "#include<stdio.h>\n #include<math.h>\n";
  //   file << "int main(){\n";
  //   file << d;
  //   file << dotNodeStr;
  //   file << dotNodeConStr;
  //   file << " return 0;\n";
  //   file << "}";
  //   file.close();
  // }
  // else
  // {
  //   cout << "Unable to open file\n";
  // }
}

int main(int argc, char *argv[])
{
  yyin = fopen(argv[1], "r");
  yy::parser parser;
  Environment e = Environment();
  BBlock *start = new BBlock();
  BBlock *tempStart = start;
  Statement *state = new Seq();

  if (!parser.parse())
  {
    // std::cout << "ParseTree:"<<std::endl;
    root.dump();
    std::ofstream outstream;
    root.exec(e);
    outstream.open("tree.dot");
    outstream << "digraph {" << std::endl;
    int count = 0;
    root.dotFilePrep(count, &outstream);
    outstream << "}" << std::endl;
    outstream.close();
    std::cout << "\nCFG:\n";
    root.convertToThreeAd(state);
    state->convert(tempStart);
    dumpCFG(tempStart);
    generateCFGDotFile(start);
    generatetargetFile(start);
  }
  return 0;
}
