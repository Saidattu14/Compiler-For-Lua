/* 
   DV1465 / DV1505 / DV1511 Lab-task example code.
   (C) Dr Andrew Moss, Erik Bergenholtz  2016, 2017, 2018
   This code is released into the public domain.

   You are free to use this code as a base for your second assignment after
   the lab sessions (it is not required that you do so). 

   2018: Took out the double-pointers.
*/

#include <list>
#include <set>
#include <initializer_list>
#include <string>
#include <iostream>

using namespace std;

/************* Three Address Instructions *************/
class ThreeAd
{
public:
    string name, lhs, rhs;
    char op;

    ThreeAd(string name, char op, string lhs, string rhs) : name(name), op(op), lhs(lhs), rhs(rhs)
    {
    }

    void dump()
    {
        cout << name << " := ";
        cout << lhs << " " << op << " " << rhs << endl;
    }
    string toStr()
    {
        return (name + "<-" + lhs + " " + op + " " + rhs);
    }
};

static int nCounter = 0;
class BBlock
{
public:
    list<ThreeAd> instructions;
    BBlock *tExit, *fExit;
    string name;

    BBlock() : tExit(NULL), fExit(NULL), name("blk" + to_string(nCounter++))
    {
    }

    void dump()
    {
        cout << "BBlock @ " << this << endl;
        cout << name << endl;
        for (auto i : instructions)
            i.dump();
        if (tExit)
            cout << "True:  " << tExit->name << endl;
        else
            cout << "True:  " << 0 << endl;
        if (fExit)
            cout << "False:  " << fExit->name << endl;
        else
            cout << "False:  " << 0 << endl;
    }
    void dotFile(string &nodeStr, string &conStr)
    {
        nodeStr += name + " [label=\"";

        for (auto i : instructions)
            nodeStr += i.toStr() + "\\n";

        nodeStr += "\"];\n";
        //std::cout << nodeStr;

//true condition
        if (tExit != NULL)
        {
            string temp = name + " -> " + tExit->name + " [label=\"true\"];\n";
            if (conStr.find(temp) == string::npos)
            {
                conStr += temp;
                if (name != tExit->name)
                    tExit->dotFile(nodeStr, conStr);
            }
        }

        if (fExit != NULL)
        {
            string temp = name + " -> " + fExit->name + " [label=\"false\"];\n";
            if (conStr.find(temp) == string::npos)
            {
                conStr += temp;
                if (name != fExit->name)
                    fExit->dotFile(nodeStr, conStr);
            }
        }
    }
    string Var_dic(set<string>s)
    {
        int val = 0;
        //
     set<string> s1;
        for (auto i = s.begin(); i != s.end(); i++)
        {
    string a = (*i);
    int val = 0;
    for (auto i = 0; i < a.length(); i++)
    {
      if (isdigit(a[i]) == false)
      {
        val = 1;
      }
    }
    if (val == 1)
    {
      s1.insert((*i));
    }
     }
  string d = "";
  for (auto i = s1.begin(); i != s1.end(); i++)
  {
    if ((*i) != "print")
    {
      d += " int " + (*i) + ";\n";
    }
         }

        return d;

    }
     void TargetFile(string &nodeStr, string &conStr, set<string> &s, set<string> &s1,int else_dt)
    {
      
        int _if_count = 0;
        int data = 0;
        int val = 0;
        int res = 0;
         for (auto i = instructions.begin(); i != instructions.end(); i++)
        {
            if((*i).name == "end")
            {
                if(else_dt == 100)
                {
                    res = 0;
                }
                else if(else_dt == 50)
                {
                    nodeStr += "\n";
                    nodeStr += "}";
                    res = 0;
                }
                else
                {
                     res = 1;
                }
              
            }
            else
            {
                res = 0;
            }
            val++;
        }
        if(res == 0)
        {
        for (auto i = instructions.begin(); i != instructions.end(); i++)
        {
            data = 100;
            // cout << (*i).rhs << "rhs   " << (*i).op << " op   "
            //      << (*i).lhs << "  lhs    "
            //      << (*i).name << "   name  \n"
            //      << "\n";
            string o, n, r, l;
             o = (*i).op;
            n = (*i).name;
            l = (*i).lhs;
            r = (*i).rhs;
            if(n != "If")
            {
            s.insert((*i).rhs);
            s.insert((*i).name);
            s.insert((*i).lhs);
            }
            if ((*i).name == "print")
            {
                string var = (*i).rhs;
                string var1 = "STRING";
                int k = 0;
                for(auto i1 = 0; i1<= var1.length();i1++)
                {
                    if(var1[i1] == var[i1])
                    {
                        k++;
                    }
                }
                if(k == 6)
                {
                    string x = " ";
                    for(auto i1 = 6; i1< var.length();i1++)
                    {
                     x = x + var[i1];
                    }
                    
                    nodeStr += "printf( \"" + x + " \");\n";
                     s.erase((*i).rhs);
                }
                else
                {
                 string p = "%d";
                 string p1 = " ";
                 int k = 0;
                    for(auto i1 = 0; i1< var.length();i1++)
                    {
                     if(var[i1] == p1[0])
                     {
                         p = " ";
                         k++;
                     }
                    
                    }
                    if(k>1)
                    {
                         nodeStr += "printf(\"" + (*i).rhs + " \" " + " );\n";
                          s.erase((*i).rhs);
                    }
                    else
                    {

                 nodeStr += "printf( \"" + p + " \", " + (*i).rhs + " );\n";
                    }
                }
                nodeStr += "\n";

            }
            else if (o == "+" || o == "-" || o == "*" || o == "/" || o == "%")
            {
                string a = (*i).name + " = " + (*i).lhs + "  " + (*i).op + " " + (*i).rhs + ";\n";
                nodeStr += a;
            }
            else if (o == "=")
            {
                string x = (*i).rhs;
                string y = " ";
                string z = "#";
                if(x[0] == z[0])
                {
                    for (auto i3 = 1; i3<x.length(); i3++)
                    {
                    y = y + x[i3];
                    }
                    y = y + ".size()";
                    (*i).rhs = y;
                     string a = (*i).name + "=" + y + ";\n";
                nodeStr += a;
                }
                else
                {
                string a = (*i).name + "=" + (*i).rhs + ";\n";
                nodeStr += a;
                }
            }
            else if (o == "^")
            {
                string a = (*i).name + " = " + "pow(" + (*i).lhs + "  " + " ," + " " + (*i).rhs + ");\n";
                nodeStr += a;
            }
            else if(o == "i")
            {



               string var = (*i).rhs;
                string var1 = "STRING";
                int k = 0;
                for(auto i1 = 0; i1<= var1.length();i1++)
                {
                    if(var1[i1] == var[i1])
                    {
                        k++;
                    }
                }
                if(k == 6)
                {
                    string x = " ";
                    for(auto i1 = 6; i1< var.length();i1++)
                    {
                     x = x + var[i1];
                    }
                    
                    nodeStr += "printf( \"" + x + " \");\n";
                     s.erase((*i).rhs);
                }
                else
                {
                 string p = " ";
                 nodeStr += "printf( \"" + p + " \", " + (*i).rhs + " );\n";
                  
                }
                string p = "%d";
                nodeStr += "scanf( \"" + p + "\", "+ "&" + (*i).name + ");\n";
                nodeStr += "\n";

            }
             else if(n == "end")
            {
               
                data = 0;
                nodeStr += "\n";
                nodeStr += "}";
                break;
            }
            else if(o == "<")
            {
                 string a = "if( " + l  + o + r + "){ " ;
                  a += "\n";
                 a = a + n + " =  0 ;  " ;
                   a += "\n";
                  nodeStr += a;
                nodeStr += "}";
                a = "else{ " +  n + " = 1;";
                 a += "\n";
                  nodeStr += a;
                nodeStr += "}";
            }
        
            else if(n == "If")
            {
               
                
                if(val == 2)
                {
                    else_dt = 100;
                    for (auto i1 = instructions.begin(); i1 != instructions.end(); i1++)
                    {
                         s.insert((*i1).rhs);
                        s.insert((*i1).name);
                        s.insert((*i1).lhs);

                         string k ;
                          k = (*i1).op;
                         string k1 = "L";
                        if(k == k1)
                        {
                            string x = (*i1).rhs;
                            string y = " ";
                            string z = "#";
                            if(x[0] == z[0])
                            {
                                for (auto i3 = 1; i3<x.length(); i3++)
                                {
                                y = y + x[i3];
                                }
                                y = y + ".size()";
                                (*i1).rhs = y;
                                
                            }
                            string a = "for( ; " + (*i1).lhs + "<=" + (*i1).rhs + ";)";
                            nodeStr += a;
                            nodeStr += "\n";
                            nodeStr += "{";
                            
                        }
                        
                        break;
                    }

                    
                }
                else
                {
                    string a = "if( !" + l  + ")";
                    nodeStr += a;
                    nodeStr += "\n";
                    nodeStr += "{";
                    if(fExit == NULL)
                    {
                        else_dt = 100;
                    }
                    else
                    { 
                        else_dt = 0;
                    }

                if(tExit != NULL)
                {
                   
                    
                    tExit->TargetFile(nodeStr, conStr, s,s1,else_dt);
                     nodeStr += "\n";
                    nodeStr += "}";
                     tExit = NULL;
                     data = 0;
                }
                if(fExit != NULL)
                {
                    else_dt = 50;
                    nodeStr += "else {";
                     nodeStr += "\n";
                    fExit->TargetFile(nodeStr, conStr, s,s1,50);
                    fExit = NULL;
                    data = 0;
                }
                }
                
               
               
                
                break;
             
            }
        
            else if(o == "l")
            {
                string a =  "int  " + (*i).lhs + "( int " +  (*i).rhs + ")";
                conStr +=  a;
                conStr += "\n";
                if (tExit != NULL)
                {
                    conStr += "{";
                     conStr += "\n";
                    tExit->TargetFile(nodeStr, conStr, s,s1,else_dt);
                     s1 = s;
                     s1.erase((*i).rhs);
                     string var_fun = Var_dic(s1);
                     s.clear();
                     conStr = conStr + var_fun;
                     conStr += nodeStr;
                     conStr += "} \n";
                    nodeStr = " ";
                    tExit = NULL;
                    
                }
                if (fExit != NULL)
                {
                    fExit->TargetFile(nodeStr, conStr, s,s1,else_dt);
                    conStr += "} \n";
                     fExit = NULL;
                }
                data = data+1;
                val =0;
                break;
            }
            else if (o == "R")
            {

                string a =  "return( "  + (*i).lhs + ");\n";
                nodeStr += a;
            }
            
            else if(o == "E")
            {
                string a = n + "=" + (*i).lhs + ";\n";
                nodeStr += a;
            }
        
            else if(o == "V")
            {
                s.erase((*i).lhs);
                s.insert((*i).name);
                string a = (*i).name + "=" + (*i).lhs + "(" +  (*i).rhs + ")"+   ";\n";
                nodeStr += a;
            }
        
            
                            else if(o == "A")
                            {
                
                            string a = (*i).name + "=" + (*i).lhs + "[" +  (*i).rhs + "]"+   ";\n";
                            nodeStr += a;
                             }
            
            else if(n== "do")
            {
                s.erase(n);
                string x = "do";
                string a = x  + "{ \n";
                nodeStr += a;

               
            }
            else if(n == "while")
            {
                s.erase(n);
                string a =    "}";
                nodeStr += a;
                (*i++);
                string b = "while( " + (*i).lhs + "==" + (*i).rhs + ");\n";
                nodeStr += b;
                fExit = NULL;
            }
        
            
            
        }
        }
       
        
                 if (tExit != NULL && data == 100 && else_dt != 1)
                {
                    
                    nodeStr += "\n";
                    tExit->TargetFile(nodeStr, conStr, s,s1,else_dt);
                 
                    
                }
                if (fExit != NULL )
                {
                    nodeStr += "\n";
                    fExit->TargetFile(nodeStr, conStr, s,s1,else_dt);
                }

    }
};

static int eCounter = 0;
/******************** Expressions ********************/
class Expression
{
public:
    string name;
    int nCounter;
    Expression() : name(" ")
    {
    }
    Expression(string name) : name(name) {}
    virtual string makeNames()
    {
        // Lecture 8 / slide 3-onwards.
        // Psuedo-code is illustrated on slide 5.
        // Virtual (but not pure) to allow overriding in the leaves.
        return "_t" + to_string(eCounter++);
    }

    virtual string convert(BBlock *) = 0; // Lecture 8 / slide 12.
    virtual void dump(int depth = 0) = 0;
};

class Add : public Expression
{
public:
    Expression *lhs, *rhs;

    Add(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    string convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, '+', lhs_name, rhs_name);
        out->instructions.push_back(instruction);
        return name;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "+" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};

class Sub : public Expression
{
public:
    Expression *lhs, *rhs;

    Sub(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    string convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, '-', lhs_name, rhs_name);
        out->instructions.push_back(instruction);
        return name;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "-" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};

class Div : public Expression
{
public:
    Expression *lhs, *rhs;

    Div(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    string convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, '/', lhs_name, rhs_name);
        out->instructions.push_back(instruction);
        return name;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "/" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};

class Caret : public Expression
{
public:
    Expression *lhs, *rhs;

    Caret(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    string convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, '^', lhs_name, rhs_name);
        out->instructions.push_back(instruction);
        return name;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "^" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};

class Percent : public Expression
{
public:
    Expression *lhs, *rhs;

    Percent(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    string convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, '%', lhs_name, rhs_name);
        out->instructions.push_back(instruction);
        return name;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "%" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};

class Mult : public Expression
{
public:
    Expression *lhs, *rhs;

    Mult(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    string convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, '*', lhs_name, rhs_name);
        out->instructions.push_back(instruction);
        return name;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "*" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};

class Less : public Expression
{
public:
    Expression *lhs, *rhs;

    Less(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    string convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, '<', lhs_name, rhs_name);
        out->instructions.push_back(instruction);
        return name;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "<" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};
class Lesseq : public Expression
{
public:
    Expression *lhs, *rhs;

    Lesseq(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    string convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, 'L', lhs_name, rhs_name);
        out->instructions.push_back(instruction);
        return name;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "<=" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};
class Greater : public Expression
{
public:
    Expression *lhs, *rhs;

    Greater(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    string convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, '>', lhs_name, rhs_name);
        out->instructions.push_back(instruction);
        return name;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << ">" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};
class GreaterEq : public Expression
{
public:
    Expression *lhs, *rhs;

    GreaterEq(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    string convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, 'E', lhs_name, rhs_name);
        out->instructions.push_back(instruction);
        return name;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << ">=" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};

class Variable : public Expression
{
public:
    string name;

    Variable(string n) : name(n)
    {
    }

    string convert(BBlock *out)
    {
        // Write three address instructions into the block
        return name;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << " " << endl;
    }
};

class Constant : public Expression
{
public:
    Constant(int nr) : Expression(to_string(nr)) {}
    Constant(string str) : Expression(str) {}

    string makeNames()
    {
        return name;
    }

    string convert(BBlock *out)
    {
        // Write three address instructions to output
        return name;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << " " << endl;
    }
};
class Input : public Expression
{
public:
    Expression *args;

    Input(Expression *args) : args(args)
    {
    }

    string convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string args_name = args->convert(out);
        ThreeAd instruction = ThreeAd(name, 'i', args_name, args_name);
        out->instructions.push_back(instruction);
        return name;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "i" << endl;
        args->dump(depth + 1);
    }
};

class notEqual : public Expression
{
public:
    Expression *lhs, *rhs;

    notEqual(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    string convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, '!', lhs_name, rhs_name);
        out->instructions.push_back(instruction);
        return name;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "!" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};

class Array : public Expression
{
public:
    Expression *lhs, *rhs;

    Array(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    string convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, 'A', lhs_name, rhs_name);
        out->instructions.push_back(instruction);
        return name;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "A[]" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};
class Exp : public Expression
{
public:
    Expression *lhs, *rhs;

    Exp(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    string convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
         string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, 'V',lhs_name, rhs_name);
        out->instructions.push_back(instruction);
        return name;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "A[]" << endl;
        rhs->dump(depth + 1);
    }
};

class Equality : public Expression
{
public:
    Expression *lhs, *rhs;

    Equality(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    string convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, 'E', lhs_name, rhs_name);
        out->instructions.push_back(instruction);
        return name;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "==" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};
/******************** Statements ********************/
class Statement
{
public:
    string name;
    Statement() {}
    virtual BBlock *convert(BBlock *) = 0;
    virtual void dump(int depth = 0) = 0;
    virtual string makeNames()
    {
        // Lecture 8 / slide 3-onwards.
        // Psuedo-code is illustrated on slide 5.
        // Virtual (but not pure) to allow overriding in the leaves.
        return "_t" + to_string(eCounter++);
    }
};
class Seq : public Statement
{
public:
    list<Statement *> statements;
    Seq() {}
    Seq(initializer_list<Statement *> statements_list) : statements(statements_list)
    {
    }

    BBlock *convert(BBlock *out)
    {
        // Write three address instructions into the block
        BBlock *start = out;
        for (auto i : statements)
        {
            out = i->convert(out);
        }
        return start;
    }
    void dump(int depth = 0)
    {
        cout << "Statement(S)" << endl;
        for (int i = 0; i < depth; i++)
            cout << " ";
        for (auto i : statements)
            i->dump(depth + 1);
    }
};

class Print : public Statement
{
public:
    Expression *exp;
    Print() {}
    Print(Expression *exp) : exp(exp) {}

    BBlock *convert(BBlock *out)
    {
        string temp = exp->convert(out);
        ThreeAd instruction = ThreeAd("print", 't', temp, temp);
        out->instructions.push_back(instruction);
        return out;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "Statement(print)" << endl;
        exp->dump(depth + 1);
    }
};
class Equali : public Statement
{
public:
    Expression *lhs, *rhs;

    Equali(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    BBlock *convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(lhs_name,'=',rhs_name,rhs_name);
        out->instructions.push_back(instruction);
        return out;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "==" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};
class Equal : public Statement
{
public:
    Expression *lhs;
    Variable *rhs;

    Equal(Expression *lhs, string rhs) : lhs(lhs), rhs(new Variable(rhs))
    {
    }

    BBlock *convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(lhs_name,'=',rhs_name,rhs_name);
        out->instructions.push_back(instruction);
        return out;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "==" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};

class List : public Statement
{
public:
    Expression *lhs,*rhs,*str1;

    List(Expression *lhs, Expression *rhs, Expression *str1) : lhs(lhs), rhs(rhs), str1(str1)
    {
    }
   


    BBlock *convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = str1->convert(out);
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, 'L', lhs_name, rhs_name);
        out->instructions.push_back(instruction);
        return out;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "==" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};


class Assignment : public Statement
{
public:
    Variable *lhs;
    Expression *rhs;

    Assignment(string lhs, Expression *rhs) : lhs(new Variable(lhs)), rhs(rhs)
    {
    }

    BBlock *convert(BBlock *out)
    {
        // Write three address instructions into the block
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd( lhs_name,'=', rhs_name, rhs_name);
        out->instructions.push_back(instruction);
        return out;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "Statement(A)" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};


class Exp_call : public Statement
{
public:
    Expression *lhs;
    Expression *rhs;

    Exp_call(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    BBlock *convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, 'E', lhs_name, rhs_name);
        out->instructions.push_back(instruction);
        return out;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "()" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};

class Function_name : public Statement
{
public:
    Variable *lhs;
    Expression *rhs;
    Statement *rls;
    Function_name(string lhs, Expression *rhs) : lhs(new Variable(lhs)), rhs(rhs)
    {
    }

    BBlock *convert(BBlock *out)
    {
        // Write three address instructions into the block
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, 'call', lhs_name, rhs_name);
        out->instructions.push_back(instruction);
        BBlock *Continue = new BBlock;
        BBlock *Continue1 = new BBlock;
        out->tExit = Continue;
        out->fExit = Continue1;
        out = Continue;
        return out;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "Statement(A)" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};
class Function_data : public Statement
{
public:
    
    Statement *rls,*rhs,*lhs;
    Function_data(Statement *lhs, Statement *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    BBlock *convert(BBlock *out)
    {
        // Write three address instructions into the block
       
      
        BBlock *Continue = new BBlock;
        BBlock *tExit1 = new BBlock();
       
        out->tExit = Continue;
        Continue = lhs->convert(out);
        out->fExit = tExit1;
        tExit1 = rhs->convert(tExit1);
        out = Continue;
        return out;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "Statement(A)" << endl;
        lhs->dump(depth + 1);
        rhs->dump(depth + 1);
    }
};

class If : public Statement
{
public:
    Expression *condition;
    Statement *ifStatement;
    Statement *elseStatement;

    If(Expression *condition, Statement *ifStatement, Statement *elseStatement) : condition(condition), ifStatement(ifStatement), elseStatement(elseStatement)
    {
    }

    BBlock *convert(BBlock *out)
    {
        // Write three address instructions into the block
        
        BBlock *temp = new BBlock();
        BBlock *temp1 = new BBlock();
        out->tExit = temp;
        ThreeAd instruction = ThreeAd("If",' ', condition->convert(out), " ");
        temp->instructions.push_back(instruction);
        BBlock *joinBlock = new BBlock();
        BBlock *tExit1 = new BBlock();
        BBlock *fExit1 = elseStatement ? new BBlock() : joinBlock;
        temp->fExit = fExit1;
        temp->tExit = temp1;
        ifStatement->convert(temp1);
        temp1->tExit = joinBlock;
        
        if (elseStatement)
        {


            fExit1 = elseStatement->convert(fExit1);
            fExit1->tExit = joinBlock;
        }
        return joinBlock;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "Statement(I)" << endl;
        condition->dump(depth + 1);
        ifStatement->dump(depth + 1);
        if (elseStatement)
            elseStatement->dump(depth + 1);
    }
};
class Repeat : public Statement
{
public:
    Expression *con;
    Statement *rep;

    Repeat(Statement *rep, Expression *con) : rep(rep), con(con)
    {
    }

    BBlock *convert(BBlock *out)
    {
        // Write three address instructions into the block
        
        BBlock *joinBlock = new BBlock();
        BBlock *Continue = new BBlock;
        BBlock *trueB = new BBlock;
        BBlock *temp1 = new BBlock;
        out->tExit = trueB;
        ThreeAd  instruction = ThreeAd("do", 'd', "", "");
        trueB->instructions.push_back(instruction);
        rep->convert(trueB);
        out->fExit = temp1;
        ThreeAd  instruction1 = ThreeAd("while", 'w', "", "");
        temp1->instructions.push_back(instruction1);
        con->convert(temp1);
        temp1->fExit = trueB;
        out = temp1;
        return out;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "Statement(R)" << endl;
        con->dump(depth + 1);
        rep->dump(depth + 1);
    }
};
class Return : public Statement
{
public:
    Expression *con;

    Return(Expression *con) : con(con)
    {
    }

    BBlock *convert(BBlock *out)
    {
        // Write three address instructions into the block
        ThreeAd instruction = ThreeAd(name, 'R', con->convert(out), "");
        out->instructions.push_back(instruction);
        return out;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "Statement(R)" << endl;
        con->dump(depth + 1);
    }
};

class Function : public Statement
{
public:
    Expression *condition;
    Statement *rep;

    Function(Statement *rep, Expression *cond) : rep(rep), condition(cond)
    {
    }

    BBlock *convert(BBlock *out)
    {
        // Write three address instructions into the block
        BBlock *joinBlock = new BBlock();
        condition->convert(out);

        BBlock *Continue = new BBlock;

        BBlock *trueB = new BBlock;

        out->tExit = trueB;
        BBlock *temp1 = new BBlock;
        condition->convert(trueB);
        trueB->tExit = temp1;
        trueB->fExit = Continue;
        temp1->fExit = Continue;
        out->fExit = Continue;
        out = Continue;
        return out;

    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "Statement(F)" << endl;
        condition->dump(depth + 1);
        rep->dump(depth + 1);
    }
};

class For : public Statement
{
public:
    Assignment *A;
    Equal  *B;
    Expression *max, *increment;
    Statement *state;
    Lesseq *compare;
    
    Add *i;

    For(Assignment *A, Expression *max, Expression *increment, Statement *state) : A(A), max(max), increment(increment), state(state) {}

    For(Assignment *A, Expression *max, Statement *state) : A(A), max(max), state(state) { increment = new Constant(1); }

    BBlock *convert(BBlock *out)
    {
        // Write three address instructions into the block
        
        BBlock *trueB = new BBlock();
        //BBlock *cont = new BBlock();
        BBlock *exp = new BBlock();
       
        Add *i = new Add(A->lhs, increment);
        out->tExit =exp;
        string val =  max->convert(exp);
        ThreeAd instruction = ThreeAd("If",' ',val , " ");       
        //exp->instructions.push_back(ThreeAd("",' ',"",""));
        //out->instructions.push_back(ThreeAd("",' ',"",""));
        A->convert(out);
        exp->instructions.push_back(instruction);
        exp->tExit = trueB;
        BBlock *temp = trueB;
        auto val1 = state->convert(temp);
        while(temp->tExit != NULL)
        {
            temp = temp->tExit;
        }
        BBlock *join = new BBlock();
        exp->fExit = join;
        i->convert(temp);
        Equal *B = new Equal(A->lhs, i->name);
        B->convert(temp);
        ThreeAd instruction1 = ThreeAd("end",' '," " , " ");
        temp->instructions.push_back(instruction1);
        temp->tExit = exp;
        return join;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "Statement(For)" << endl;
        max->dump(depth + 1);
        increment->dump(depth + 1);
        state->dump(depth + 1);
    }
};

/* Test cases */
// Statement *test = new Seq({
//                           new Assignment(
//                                   "x",
//                                   new Add(
//                                           new Variable("x"),
//                                           new Constant(1)
//                                   )
//                           ),new If(
//                                   new Equality(
//                                           new Variable("x"),
//                                           new Constant(10)
//                                   ),new Assignment(
//                                           "y",
//                                           new Add(
//                                                   new Variable("x"),
//                                                   new Constant(1)
//                                           )
//                                   ), new Assignment(
//                                           "y",
//                                           new Mult(
//                                                   new Variable("x"),
//                                                   new Constant(2)
//                                           )
//                                   )
//                           ), new Assignment(
//                                   "x",
//                                   new Add(
//                                           new Variable("x"),
//                                           new Constant(1)
//                                   )
//                           )
// });

// /*
//  * Iterate over each basic block that can be reached from the entry point
//  * exactly once, so that we can dump out the entire graph.
//  * This is a concrete example of the graph-walk described in lecture 7.
//  */
// void dumpCFG(BBlock *start)
// {
//         set<BBlock *> done, todo;
//         todo.insert(start);
//         while(todo.size()>0)
//         {
//                 // Pop an arbitrary element from todo set
//                 auto first = todo.begin();
//                 BBlock *next = *first;
//                 todo.erase(first);
//                 next->dump();
//                 done.insert(next);
//                 if(next->tExit!=NULL && done.find(next->tExit)==done.end())
//                         todo.insert(next->tExit);
//                 if(next->fExit!=NULL && done.find(next->fExit)==done.end())
//                         todo.insert(next->fExit);
//         }
// }

// int main() {
//     test->dump();
//     BBlock* start = new BBlock();
//     start = test->convert(start);
//     dumpCFG(start);
//     return 0;
// }
