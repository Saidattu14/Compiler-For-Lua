%skeleton "lalr1.cc"
%defines
%define api.value.type variant
%define api.token.constructor
%code requires{
    #include "node.h"
}
%code{
  #include <string>
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  Node root;
//   Environment e;
//   Interpreter inter;
  int Node::rId = 0;
}
%token <std::string> DO
%token <std::string> ESTAT
%token <std::string> UNTIL
%token <std::string> IF
%token <std::string> THEN
%token <std::string> ELSE
%token <std::string> FOR
%token <std::string> FUNCTION
%token <std::string> RETURN
%token <std::string> BTRUE
%token <std::string> BFALSE
%token <std::string> REPEAT
%token <std::string> NAME
%token <std::string> WORD
%token <std::string> STR
%token <std::string> NUMBER
%token <std::string> START_SQBKT
%token <std::string> END_SQBKT
%token <std::string> START_PARENTHESES
%token <std::string> END_PARENTHESES
%token <std::string> START_BRACKET
%token <std::string> END_BRACKET
%token <std::string> EQUAL
%token <std::string> EQUALEQUAL
%token <std::string> COMMA
%token <std::string> SEMICOLON
%token <std::string> PLUS
%token <std::string> MINUS
%token <std::string> STAR
%token <std::string> SLASH
%token <std::string> CARET
%token <std::string> PERCENT
%token <std::string> DOT
%token <std::string> LESS
%token <std::string> BIGGER
%token <std::string> HASHTAG
%left COMMA
%right EQUAL
%left EQUALEQUAL
%left LESS BIGGER
%left PLUS MINUS
%left STAR SLASH PERCENT
%right CARET
%left START_PARENTHESES END_PARENTHESES
%type <Node> stat
%type <Node> exp
%type <Node> Boolean
%type <Node> stream
%type <Node> block
%type <Node> block2
%type <Node> explist
%type <Node> explist2
%type <Node> functionCall
%type <Node> argument
%type <Node> variable
%type <Node> stat2
%type <Node> tableconstructor
%type <Node> varlist
%type <Node> varlist2
%type <Node> laststat
%type <Node> funcbody
%type <Node> chunk
%token END 0 "end of file"
%%
stream : chunk { $$ = Node("Stream", ""); $$.children.push_back($1); root = $$; }
      ;

chunk : block           { $$ = Node("Chunk", ""); $$.children.push_back($1); }
      | block laststat  { $$ = $1; $$.children.push_back($2); }
      ;

block : /*Empty*/     { $$ = Node("Block", "empty"); }
      | stat          { $$ = Node("Block", "has block"); $$.children.push_back($1); }
      | block2 stat   { $$ = $1; $$.children.push_back($2); }
      ;

block2 : stat           { $$ = Node("Block", ""); $$.children.push_back($1); }
       | block2 stat    { $$ = $1; $$.children.push_back($2); }
       ;

argument : START_PARENTHESES explist END_PARENTHESES   { $$ = $2; }
         | STR                         { $$ = Node("STRING", $1); }
         | tableconstructor            { $$ = $1; }
         ;

explist : exp                 { $$ = $1; }
        | explist2 COMMA exp  { $$ = $1; $$.children.push_back($3); }
        ;

explist2: exp                   { $$ = Node("Expressionlist", ""); $$.children.push_back($1); }
        | explist2 COMMA exp    { $$ = $1; $$.children.push_back($3); }
        ;

stat : functionCall                                               { $$ = $1; }
     | varlist EQUAL explist                                     { $$ = Node("EQUALS", $2); $$.children.push_back($1); $$.children.push_back($3); }
     | FOR NAME EQUAL exp COMMA exp DO chunk ESTAT       { $$ = Node("For loop", ""); $$.children.push_back(Node("NAME", $2)); $$.children.push_back($4); $$.children.push_back($6); $$.children.push_back($8); }
     | IF exp THEN chunk stat2 ESTAT                            { $$ = Node("IF", ""); $$.children.push_back($2); $$.children.push_back($4); $$.children.push_back($5); }
     | REPEAT chunk UNTIL exp                                     { $$ = Node("Repeat loop", ""); $$.children.push_back($2); $$.children.push_back($4);}
     | FUNCTION NAME funcbody                               { $$ = Node("FUNCTION", $2); $$.children.push_back($3); }
     ;

stat2 : /*EMPTY*/     { $$ = Node("Else", "No else"); }
      | ELSE chunk    { $$ = Node("Else", "Has else"); $$.children.push_back($2); }
      ;

laststat : RETURN explist { $$ = Node("Return", ""); $$.children.push_back($2); }
         ;

varlist : variable                { $$ = $1; }
        | varlist2 COMMA variable { $$ = $1; $$.children.push_back($3); }
        ;

varlist2 : variable                 { $$ = Node("Varlist", ""); $$.children.push_back($1); }
         | varlist2 COMMA variable  { $$ = $1; $$.children.push_back($3); }

variable : NAME                       { $$ = Node("Variable", $1); }
    |variable DOT NAME              { $$ = $1; $$.children.push_back(Node("NAME", $3)); }
    |NAME START_SQBKT exp END_SQBKT  { $$ = Node("ArrayVar", $1); $$.children.push_back($3); }
    ;

tableconstructor : START_BRACKET explist END_BRACKET { $$ = Node("Tableconstructor", ""); $$.children.push_back($2); }

functionCall : variable argument { $$ = Node("FunctionCall", ""); $1.children.push_back($2); $$.children.push_back($1); }
             ;

funcbody : START_PARENTHESES explist END_PARENTHESES chunk ESTAT { $$ = Node("Funcbody", ""); $$.children.push_back($2); $$.children.push_back($4); }
        ;

exp : NUMBER                                  { $$ = Node("NUMBER", $1); }
    | NAME                            { $$ = Node("NAME", $1); }
    | STR                                     { $$ = Node("STRING", $1); }
    | WORD   {$$=Node("STRING",$1); }
    | Boolean    {$$=$1;}
    | exp PLUS exp                          { $$ = Node("PLUS", $2);;$$.children.push_back($1); $$.children.push_back($3);}
    | exp MINUS exp                          {$$ = Node("MINUS", $2);;$$.children.push_back($1); $$.children.push_back($3);}
    | exp STAR exp                          {$$ = Node("STAR", $2);;$$.children.push_back($1); $$.children.push_back($3);}
    | exp SLASH exp                          {$$ = Node("SLASH", $2);;$$.children.push_back($1); $$.children.push_back($3);}
    | exp CARET exp                          {$$ = Node("CARET", $2);;$$.children.push_back($1); $$.children.push_back($3);}
    | exp PERCENT exp                          {$$ = Node("MODULUS", $2);;$$.children.push_back($1); $$.children.push_back($3);}
    | exp EQUALEQUAL exp                          {$$ = Node("EQUALEQUAL", $2);;$$.children.push_back($1); $$.children.push_back($3);}
    | exp LESS exp                          {$$ = Node("LESS", $2);;$$.children.push_back($1); $$.children.push_back($3);}
    | exp BIGGER exp                          {$$ = Node("GREATER", $2);;$$.children.push_back($1); $$.children.push_back($3);}
    
    | HASHTAG exp                            { $$ = Node("HASHTAG", $1);$$.children.push_back($2);}
    | functionCall                            { $$ = $1; }
    | tableconstructor                        { $$ = $1; }
    | NAME START_SQBKT exp END_SQBKT  { $$ = Node("ArrayVar", $1); $$.children.push_back($3); }
    | START_PARENTHESES exp END_PARENTHESES  {$$=$2;}
    ;

Boolean : BTRUE                                { $$ = Node("BTRUE", $1); }
    | BFALSE                               { $$ = Node("BFALSE", $1); }
    ;
