# Flex
Flex is a tool for generating scanners: programs which recognize lexical patterns in text. flex reads the given input files (or its standard input if no file names are given) for a description of the scanner to generate. The description is in the form of pairs of regular expressions and C code, called rules. flex generates as output a C source file, `lex.yy.c', which defines a routine yylex.


To install flex run command sudo apt-get install flex

# Bison
Bison is a general-purpose parser generator that converts a grammar description (Bison Grammar Files) for an LALR(1) context-free grammar into a C program to parse that grammar. The Bison parser is a bottom-up parser. It tries, by shifts and reductions, to reduce the entire input down to a single grouping whose symbol is the grammar's start-symbol.

To install bison run command sudo apt-get install bison

# Makefile

To install Make run command sudo apt install make

# CPP compiler

To install CPP run command sudo apt install g++

# TO clean

run command make clean

# To test the compiler

run make clean


run make



./int test.lua for interpreter
./comp test.lua for compiler

The code of the lua language is converted into c program and presented in target.cc file

