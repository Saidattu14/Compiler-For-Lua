%top{
	#include "ass1.tab.hh"
	#define YY_DECL yy::parser::symbol_type yylex()
}
%option noyywrap nounput batch noinput
%%
"do" { return yy::parser::make_DO(yytext); }
"end" { return yy::parser::make_ESTAT(yytext); }
"until" { return yy::parser::make_UNTIL(yytext); }
"if"  { return yy::parser::make_IF(yytext); }
"then" { return yy::parser::make_THEN(yytext); }
"else" { return yy::parser::make_ELSE(yytext); }
"for"  { return yy::parser::make_FOR(yytext); }
"function" { return yy::parser::make_FUNCTION(yytext); }
"return" { return yy::parser::make_RETURN(yytext); }
"false" { return yy::parser::make_BFALSE(yytext); }
"true" { return yy::parser::make_BTRUE(yytext); }
"repeat" { return yy::parser::make_REPEAT(yytext); }

[A-Za-z]+ { return yy::parser::make_NAME(yytext); }
\"[^"]*\" { yytext++; yytext[strlen(yytext)-1] = '\0';return yy::parser::make_STR(yytext); }
[0-9]* { return yy::parser::make_NUMBER(yytext); }

[\[] { return yy::parser::make_START_SQBKT(yytext); }
[\]] { return yy::parser::make_END_SQBKT(yytext); }
[(] { return yy::parser::make_START_PARENTHESES(yytext); }
[)] { return yy::parser::make_END_PARENTHESES(yytext); }
[{] { return yy::parser::make_START_BRACKET(yytext); }
[}] { return yy::parser::make_END_BRACKET(yytext); }
[=] { return yy::parser::make_EQUAL(yytext); }
"==" { return yy::parser::make_EQUALEQUAL(yytext); }
[,] { return yy::parser::make_COMMA(yytext); }
\n 
[;] { return yy::parser::make_SEMICOLON(yytext); }
[ \t] 
[+] { return yy::parser::make_PLUS(yytext); }
[-] { return yy::parser::make_MINUS(yytext); }
[*] { return yy::parser::make_STAR(yytext); }
[/] { return yy::parser::make_SLASH(yytext); }
[\^] { return yy::parser::make_CARET(yytext); }
[%] { return yy::parser::make_PERCENT(yytext); }
[.] { return yy::parser::make_DOT(yytext); }
[<] { return yy::parser::make_LESS(yytext); }
[>] { return yy::parser::make_BIGGER(yytext); }
[#] { return yy::parser::make_HASHTAG(yytext); }
<<EOF>>	{ return yy::parser::make_END(); }
%%
