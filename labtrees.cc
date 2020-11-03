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
        return (name + " \\<\\- " + lhs + " " + op + " " + rhs);
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
        if (tExit)
            cout << "False:  " << tExit->name << endl;
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
    void TargetFile(string &nodeStr, string &conStr, set<string> &s)
    {
        for (auto i = instructions.begin(); i != instructions.end(); i++)
        {
            // cout << (*i).rhs << "rhs   " << (*i).op << " op   "
            //      << (*i).lhs << "  lhs    "
            //      << (*i).name << "   name  \n"
            //      << "\n";
            
            
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
        ThreeAd instruction = ThreeAd(name, '>=', lhs_name, rhs_name);
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

        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, 'A', " ", rhs_name);
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
        ThreeAd instruction = ThreeAd(name, '=', lhs_name, rhs_name);
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
        string temp1 = "print";
        ThreeAd instruction = ThreeAd(name, 'print', temp1, temp);
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
        ThreeAd instruction = ThreeAd(name, '=', lhs_name, rhs_name);
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
    Expression *lhs, *rhs;

    List(Expression *lhs, Expression *rhs) : lhs(lhs), rhs(rhs)
    {
    }

    BBlock *convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
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

class Input : public Statement
{
public:
    Expression *args;

    Input(Expression *args) : args(args)
    {
    }

    BBlock *convert(BBlock *out)
    {
        // Write three address instructions into the block
        name = makeNames();
        string args_name = args->convert(out);
        ThreeAd instruction = ThreeAd(name, 'i', args_name, args_name);
        out->instructions.push_back(instruction);
        return out;
    }
    void dump(int depth = 0)
    {
        for (int i = 0; i < depth; i++)
            cout << " ";
        cout << "i" << endl;
        args->dump(depth + 1);
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
        ThreeAd instruction = ThreeAd(name, '=', lhs_name, rhs_name);
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

    Function_name(string lhs, Expression *rhs) : lhs(new Variable(lhs)), rhs(rhs)
    {
    }

    BBlock *convert(BBlock *out)
    {
        // Write three address instructions into the block
        string lhs_name = lhs->convert(out);
        string rhs_name = rhs->convert(out);
        ThreeAd instruction = ThreeAd(name, 'F', lhs_name, rhs_name);
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
        condition->convert(out);
        BBlock *joinBlock = new BBlock();
        BBlock *tExit1 = new BBlock();
        BBlock *fExit1 = elseStatement ? new BBlock() : joinBlock;
        ifStatement->convert(out);
        out->fExit = fExit1;
        out->tExit = tExit1;

        tExit1 = ifStatement->convert(tExit1);
        tExit1->tExit = joinBlock;
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
        rep->convert(trueB);
        out->fExit = temp1;
        con->convert(temp1);
        out = temp1;
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
    Expression *max, *increment;
    Statement *state;
    Lesseq *compare;
    Add *i;

    For(Assignment *A, Expression *max, Expression *increment, Statement *state) : A(A), max(max), increment(increment), state(state) {}

    For(Assignment *A, Expression *max, Statement *state) : A(A), max(max), state(state) { increment = new Constant(1); }

    BBlock *convert(BBlock *out)
    {
        // Write three address instructions into the block
        ThreeAd instruction = ThreeAd("for", 'a', "", "");
        out->instructions.push_back(instruction);
        Lesseq *compare = new Lesseq(A->lhs, max);
        Add *i = new Add(A->lhs, increment);
        A->convert(out);
        max->convert(out);
        BBlock *Continue = new BBlock;
        BBlock *trueB = new BBlock;
        BBlock *temp1 = trueB;
        
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
