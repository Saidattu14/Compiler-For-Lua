// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "ass1.tab.hh"


// Unqualified %code blocks.
#line 8 "ass1.yy"

  #include <string>
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  Node root;
//   Environment e;
//   Interpreter inter;
  int Node::rId = 0;

#line 55 "ass1.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 127 "ass1.tab.cc"


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 40: // stream
      case 41: // chunk
      case 42: // block
      case 43: // block2
      case 44: // argument
      case 45: // explist
      case 46: // explist2
      case 47: // stat
      case 48: // stat2
      case 49: // laststat
      case 50: // varlist
      case 51: // varlist2
      case 52: // variable
      case 53: // tableconstructor
      case 54: // functionCall
      case 55: // funcbody
      case 56: // exp
      case 57: // Boolean
        value.YY_MOVE_OR_COPY< Node > (YY_MOVE (that.value));
        break;

      case 3: // DO
      case 4: // ESTAT
      case 5: // UNTIL
      case 6: // IF
      case 7: // THEN
      case 8: // ELSE
      case 9: // FOR
      case 10: // FUNCTION
      case 11: // RETURN
      case 12: // BTRUE
      case 13: // BFALSE
      case 14: // REPEAT
      case 15: // NAME
      case 16: // WORD
      case 17: // STR
      case 18: // NUMBER
      case 19: // START_SQBKT
      case 20: // END_SQBKT
      case 21: // START_PARENTHESES
      case 22: // END_PARENTHESES
      case 23: // START_BRACKET
      case 24: // END_BRACKET
      case 25: // EQUAL
      case 26: // EQUALEQUAL
      case 27: // COMMA
      case 28: // SEMICOLON
      case 29: // PLUS
      case 30: // MINUS
      case 31: // STAR
      case 32: // SLASH
      case 33: // CARET
      case 34: // PERCENT
      case 35: // DOT
      case 36: // LESS
      case 37: // BIGGER
      case 38: // HASHTAG
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.type_get ())
    {
      case 40: // stream
      case 41: // chunk
      case 42: // block
      case 43: // block2
      case 44: // argument
      case 45: // explist
      case 46: // explist2
      case 47: // stat
      case 48: // stat2
      case 49: // laststat
      case 50: // varlist
      case 51: // varlist2
      case 52: // variable
      case 53: // tableconstructor
      case 54: // functionCall
      case 55: // funcbody
      case 56: // exp
      case 57: // Boolean
        value.move< Node > (YY_MOVE (that.value));
        break;

      case 3: // DO
      case 4: // ESTAT
      case 5: // UNTIL
      case 6: // IF
      case 7: // THEN
      case 8: // ELSE
      case 9: // FOR
      case 10: // FUNCTION
      case 11: // RETURN
      case 12: // BTRUE
      case 13: // BFALSE
      case 14: // REPEAT
      case 15: // NAME
      case 16: // WORD
      case 17: // STR
      case 18: // NUMBER
      case 19: // START_SQBKT
      case 20: // END_SQBKT
      case 21: // START_PARENTHESES
      case 22: // END_PARENTHESES
      case 23: // START_BRACKET
      case 24: // END_BRACKET
      case 25: // EQUAL
      case 26: // EQUALEQUAL
      case 27: // COMMA
      case 28: // SEMICOLON
      case 29: // PLUS
      case 30: // MINUS
      case 31: // STAR
      case 32: // SLASH
      case 33: // CARET
      case 34: // PERCENT
      case 35: // DOT
      case 36: // LESS
      case 37: // BIGGER
      case 38: // HASHTAG
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 40: // stream
      case 41: // chunk
      case 42: // block
      case 43: // block2
      case 44: // argument
      case 45: // explist
      case 46: // explist2
      case 47: // stat
      case 48: // stat2
      case 49: // laststat
      case 50: // varlist
      case 51: // varlist2
      case 52: // variable
      case 53: // tableconstructor
      case 54: // functionCall
      case 55: // funcbody
      case 56: // exp
      case 57: // Boolean
        value.copy< Node > (that.value);
        break;

      case 3: // DO
      case 4: // ESTAT
      case 5: // UNTIL
      case 6: // IF
      case 7: // THEN
      case 8: // ELSE
      case 9: // FOR
      case 10: // FUNCTION
      case 11: // RETURN
      case 12: // BTRUE
      case 13: // BFALSE
      case 14: // REPEAT
      case 15: // NAME
      case 16: // WORD
      case 17: // STR
      case 18: // NUMBER
      case 19: // START_SQBKT
      case 20: // END_SQBKT
      case 21: // START_PARENTHESES
      case 22: // END_PARENTHESES
      case 23: // START_BRACKET
      case 24: // END_BRACKET
      case 25: // EQUAL
      case 26: // EQUALEQUAL
      case 27: // COMMA
      case 28: // SEMICOLON
      case 29: // PLUS
      case 30: // MINUS
      case 31: // STAR
      case 32: // SLASH
      case 33: // CARET
      case 34: // PERCENT
      case 35: // DOT
      case 36: // LESS
      case 37: // BIGGER
      case 38: // HASHTAG
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 40: // stream
      case 41: // chunk
      case 42: // block
      case 43: // block2
      case 44: // argument
      case 45: // explist
      case 46: // explist2
      case 47: // stat
      case 48: // stat2
      case 49: // laststat
      case 50: // varlist
      case 51: // varlist2
      case 52: // variable
      case 53: // tableconstructor
      case 54: // functionCall
      case 55: // funcbody
      case 56: // exp
      case 57: // Boolean
        value.move< Node > (that.value);
        break;

      case 3: // DO
      case 4: // ESTAT
      case 5: // UNTIL
      case 6: // IF
      case 7: // THEN
      case 8: // ELSE
      case 9: // FOR
      case 10: // FUNCTION
      case 11: // RETURN
      case 12: // BTRUE
      case 13: // BFALSE
      case 14: // REPEAT
      case 15: // NAME
      case 16: // WORD
      case 17: // STR
      case 18: // NUMBER
      case 19: // START_SQBKT
      case 20: // END_SQBKT
      case 21: // START_PARENTHESES
      case 22: // END_PARENTHESES
      case 23: // START_BRACKET
      case 24: // END_BRACKET
      case 25: // EQUAL
      case 26: // EQUALEQUAL
      case 27: // COMMA
      case 28: // SEMICOLON
      case 29: // PLUS
      case 30: // MINUS
      case 31: // STAR
      case 32: // SLASH
      case 33: // CARET
      case 34: // PERCENT
      case 35: // DOT
      case 36: // LESS
      case 37: // BIGGER
      case 38: // HASHTAG
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 40: // stream
      case 41: // chunk
      case 42: // block
      case 43: // block2
      case 44: // argument
      case 45: // explist
      case 46: // explist2
      case 47: // stat
      case 48: // stat2
      case 49: // laststat
      case 50: // varlist
      case 51: // varlist2
      case 52: // variable
      case 53: // tableconstructor
      case 54: // functionCall
      case 55: // funcbody
      case 56: // exp
      case 57: // Boolean
        yylhs.value.emplace< Node > ();
        break;

      case 3: // DO
      case 4: // ESTAT
      case 5: // UNTIL
      case 6: // IF
      case 7: // THEN
      case 8: // ELSE
      case 9: // FOR
      case 10: // FUNCTION
      case 11: // RETURN
      case 12: // BTRUE
      case 13: // BFALSE
      case 14: // REPEAT
      case 15: // NAME
      case 16: // WORD
      case 17: // STR
      case 18: // NUMBER
      case 19: // START_SQBKT
      case 20: // END_SQBKT
      case 21: // START_PARENTHESES
      case 22: // END_PARENTHESES
      case 23: // START_BRACKET
      case 24: // END_BRACKET
      case 25: // EQUAL
      case 26: // EQUALEQUAL
      case 27: // COMMA
      case 28: // SEMICOLON
      case 29: // PLUS
      case 30: // MINUS
      case 31: // STAR
      case 32: // SLASH
      case 33: // CARET
      case 34: // PERCENT
      case 35: // DOT
      case 36: // LESS
      case 37: // BIGGER
      case 38: // HASHTAG
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 81 "ass1.yy"
               { yylhs.value.as < Node > () = Node("Stream", ""); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); root = yylhs.value.as < Node > (); }
#line 800 "ass1.tab.cc"
    break;

  case 3:
#line 84 "ass1.yy"
                        { yylhs.value.as < Node > () = Node("Chunk", ""); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); }
#line 806 "ass1.tab.cc"
    break;

  case 4:
#line 85 "ass1.yy"
                        { yylhs.value.as < Node > () = yystack_[1].value.as < Node > (); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); }
#line 812 "ass1.tab.cc"
    break;

  case 5:
#line 88 "ass1.yy"
                      { yylhs.value.as < Node > () = Node("Block", "empty"); }
#line 818 "ass1.tab.cc"
    break;

  case 6:
#line 89 "ass1.yy"
                      { yylhs.value.as < Node > () = Node("Block", "has block"); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); }
#line 824 "ass1.tab.cc"
    break;

  case 7:
#line 90 "ass1.yy"
                      { yylhs.value.as < Node > () = yystack_[1].value.as < Node > (); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); }
#line 830 "ass1.tab.cc"
    break;

  case 8:
#line 93 "ass1.yy"
                        { yylhs.value.as < Node > () = Node("Block", ""); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); }
#line 836 "ass1.tab.cc"
    break;

  case 9:
#line 94 "ass1.yy"
                        { yylhs.value.as < Node > () = yystack_[1].value.as < Node > (); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); }
#line 842 "ass1.tab.cc"
    break;

  case 10:
#line 97 "ass1.yy"
                                                       { yylhs.value.as < Node > () = yystack_[1].value.as < Node > (); }
#line 848 "ass1.tab.cc"
    break;

  case 11:
#line 98 "ass1.yy"
                                       { yylhs.value.as < Node > () = Node("STRING", yystack_[0].value.as < std::string > ()); }
#line 854 "ass1.tab.cc"
    break;

  case 12:
#line 99 "ass1.yy"
                                       { yylhs.value.as < Node > () = yystack_[0].value.as < Node > (); }
#line 860 "ass1.tab.cc"
    break;

  case 13:
#line 102 "ass1.yy"
                              { yylhs.value.as < Node > () = yystack_[0].value.as < Node > (); }
#line 866 "ass1.tab.cc"
    break;

  case 14:
#line 103 "ass1.yy"
                              { yylhs.value.as < Node > () = yystack_[2].value.as < Node > (); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); }
#line 872 "ass1.tab.cc"
    break;

  case 15:
#line 106 "ass1.yy"
                                { yylhs.value.as < Node > () = Node("Expressionlist", ""); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); }
#line 878 "ass1.tab.cc"
    break;

  case 16:
#line 107 "ass1.yy"
                                { yylhs.value.as < Node > () = yystack_[2].value.as < Node > (); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); }
#line 884 "ass1.tab.cc"
    break;

  case 17:
#line 110 "ass1.yy"
                                                                  { yylhs.value.as < Node > () = yystack_[0].value.as < Node > (); }
#line 890 "ass1.tab.cc"
    break;

  case 18:
#line 111 "ass1.yy"
                                                                 { yylhs.value.as < Node > () = Node("EQUALS", yystack_[1].value.as < std::string > ()); yylhs.value.as < Node > ().children.push_back(yystack_[2].value.as < Node > ()); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); }
#line 896 "ass1.tab.cc"
    break;

  case 19:
#line 112 "ass1.yy"
                                                         { yylhs.value.as < Node > () = Node("For loop", ""); yylhs.value.as < Node > ().children.push_back(Node("NAME", yystack_[7].value.as < std::string > ())); yylhs.value.as < Node > ().children.push_back(yystack_[5].value.as < Node > ()); yylhs.value.as < Node > ().children.push_back(yystack_[3].value.as < Node > ()); yylhs.value.as < Node > ().children.push_back(yystack_[1].value.as < Node > ()); }
#line 902 "ass1.tab.cc"
    break;

  case 20:
#line 113 "ass1.yy"
                                                                { yylhs.value.as < Node > () = Node("IF", ""); yylhs.value.as < Node > ().children.push_back(yystack_[4].value.as < Node > ()); yylhs.value.as < Node > ().children.push_back(yystack_[2].value.as < Node > ()); yylhs.value.as < Node > ().children.push_back(yystack_[1].value.as < Node > ()); }
#line 908 "ass1.tab.cc"
    break;

  case 21:
#line 114 "ass1.yy"
                                                                  { yylhs.value.as < Node > () = Node("Repeat loop", ""); yylhs.value.as < Node > ().children.push_back(yystack_[2].value.as < Node > ()); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ());}
#line 914 "ass1.tab.cc"
    break;

  case 22:
#line 115 "ass1.yy"
                                                            { yylhs.value.as < Node > () = Node("FUNCTION", yystack_[1].value.as < std::string > ()); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); }
#line 920 "ass1.tab.cc"
    break;

  case 23:
#line 118 "ass1.yy"
                      { yylhs.value.as < Node > () = Node("Else", "No else"); }
#line 926 "ass1.tab.cc"
    break;

  case 24:
#line 119 "ass1.yy"
                      { yylhs.value.as < Node > () = Node("Else", "Has else"); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); }
#line 932 "ass1.tab.cc"
    break;

  case 25:
#line 122 "ass1.yy"
                          { yylhs.value.as < Node > () = Node("Return", ""); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); }
#line 938 "ass1.tab.cc"
    break;

  case 26:
#line 125 "ass1.yy"
                                  { yylhs.value.as < Node > () = yystack_[0].value.as < Node > (); }
#line 944 "ass1.tab.cc"
    break;

  case 27:
#line 126 "ass1.yy"
                                  { yylhs.value.as < Node > () = yystack_[2].value.as < Node > (); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); }
#line 950 "ass1.tab.cc"
    break;

  case 28:
#line 129 "ass1.yy"
                                    { yylhs.value.as < Node > () = Node("Varlist", ""); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); }
#line 956 "ass1.tab.cc"
    break;

  case 29:
#line 130 "ass1.yy"
                                    { yylhs.value.as < Node > () = yystack_[2].value.as < Node > (); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); }
#line 962 "ass1.tab.cc"
    break;

  case 30:
#line 132 "ass1.yy"
                                      { yylhs.value.as < Node > () = Node("Variable", yystack_[0].value.as < std::string > ()); }
#line 968 "ass1.tab.cc"
    break;

  case 31:
#line 133 "ass1.yy"
                                    { yylhs.value.as < Node > () = yystack_[2].value.as < Node > (); yylhs.value.as < Node > ().children.push_back(Node("NAME", yystack_[0].value.as < std::string > ())); }
#line 974 "ass1.tab.cc"
    break;

  case 32:
#line 134 "ass1.yy"
                                     { yylhs.value.as < Node > () = Node("ArrayVar", yystack_[3].value.as < std::string > ()); yylhs.value.as < Node > ().children.push_back(yystack_[1].value.as < Node > ()); }
#line 980 "ass1.tab.cc"
    break;

  case 33:
#line 137 "ass1.yy"
                                                     { yylhs.value.as < Node > () = Node("Tableconstructor", ""); yylhs.value.as < Node > ().children.push_back(yystack_[1].value.as < Node > ()); }
#line 986 "ass1.tab.cc"
    break;

  case 34:
#line 139 "ass1.yy"
                                 { yylhs.value.as < Node > () = Node("FunctionCall", ""); yystack_[1].value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ()); yylhs.value.as < Node > ().children.push_back(yystack_[1].value.as < Node > ()); }
#line 992 "ass1.tab.cc"
    break;

  case 35:
#line 142 "ass1.yy"
                                                                 { yylhs.value.as < Node > () = Node("Funcbody", ""); yylhs.value.as < Node > ().children.push_back(yystack_[3].value.as < Node > ()); yylhs.value.as < Node > ().children.push_back(yystack_[1].value.as < Node > ()); }
#line 998 "ass1.tab.cc"
    break;

  case 36:
#line 145 "ass1.yy"
                                              { yylhs.value.as < Node > () = Node("NUMBER", yystack_[0].value.as < std::string > ()); }
#line 1004 "ass1.tab.cc"
    break;

  case 37:
#line 146 "ass1.yy"
                                      { yylhs.value.as < Node > () = Node("NAME", yystack_[0].value.as < std::string > ()); }
#line 1010 "ass1.tab.cc"
    break;

  case 38:
#line 147 "ass1.yy"
                                              { yylhs.value.as < Node > () = Node("STRING", yystack_[0].value.as < std::string > ()); }
#line 1016 "ass1.tab.cc"
    break;

  case 39:
#line 148 "ass1.yy"
             {yylhs.value.as < Node > ()=Node("STRING",yystack_[0].value.as < std::string > ()); }
#line 1022 "ass1.tab.cc"
    break;

  case 40:
#line 149 "ass1.yy"
                 {yylhs.value.as < Node > ()=yystack_[0].value.as < Node > ();}
#line 1028 "ass1.tab.cc"
    break;

  case 41:
#line 150 "ass1.yy"
                                            { yylhs.value.as < Node > () = Node("PLUS", yystack_[1].value.as < std::string > ());;yylhs.value.as < Node > ().children.push_back(yystack_[2].value.as < Node > ()); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ());}
#line 1034 "ass1.tab.cc"
    break;

  case 42:
#line 151 "ass1.yy"
                                             {yylhs.value.as < Node > () = Node("MINUS", yystack_[1].value.as < std::string > ());;yylhs.value.as < Node > ().children.push_back(yystack_[2].value.as < Node > ()); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ());}
#line 1040 "ass1.tab.cc"
    break;

  case 43:
#line 152 "ass1.yy"
                                            {yylhs.value.as < Node > () = Node("STAR", yystack_[1].value.as < std::string > ());;yylhs.value.as < Node > ().children.push_back(yystack_[2].value.as < Node > ()); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ());}
#line 1046 "ass1.tab.cc"
    break;

  case 44:
#line 153 "ass1.yy"
                                             {yylhs.value.as < Node > () = Node("SLASH", yystack_[1].value.as < std::string > ());;yylhs.value.as < Node > ().children.push_back(yystack_[2].value.as < Node > ()); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ());}
#line 1052 "ass1.tab.cc"
    break;

  case 45:
#line 154 "ass1.yy"
                                             {yylhs.value.as < Node > () = Node("CARET", yystack_[1].value.as < std::string > ());;yylhs.value.as < Node > ().children.push_back(yystack_[2].value.as < Node > ()); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ());}
#line 1058 "ass1.tab.cc"
    break;

  case 46:
#line 155 "ass1.yy"
                                               {yylhs.value.as < Node > () = Node("MODULUS", yystack_[1].value.as < std::string > ());;yylhs.value.as < Node > ().children.push_back(yystack_[2].value.as < Node > ()); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ());}
#line 1064 "ass1.tab.cc"
    break;

  case 47:
#line 156 "ass1.yy"
                                                  {yylhs.value.as < Node > () = Node("EQUALEQUAL", yystack_[1].value.as < std::string > ());;yylhs.value.as < Node > ().children.push_back(yystack_[2].value.as < Node > ()); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ());}
#line 1070 "ass1.tab.cc"
    break;

  case 48:
#line 157 "ass1.yy"
                                            {yylhs.value.as < Node > () = Node("LESS", yystack_[1].value.as < std::string > ());;yylhs.value.as < Node > ().children.push_back(yystack_[2].value.as < Node > ()); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ());}
#line 1076 "ass1.tab.cc"
    break;

  case 49:
#line 158 "ass1.yy"
                                              {yylhs.value.as < Node > () = Node("GREATER", yystack_[1].value.as < std::string > ());;yylhs.value.as < Node > ().children.push_back(yystack_[2].value.as < Node > ()); yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ());}
#line 1082 "ass1.tab.cc"
    break;

  case 50:
#line 160 "ass1.yy"
                                             { yylhs.value.as < Node > () = Node("HASHTAG", yystack_[1].value.as < std::string > ());yylhs.value.as < Node > ().children.push_back(yystack_[0].value.as < Node > ());}
#line 1088 "ass1.tab.cc"
    break;

  case 51:
#line 161 "ass1.yy"
                                              { yylhs.value.as < Node > () = yystack_[0].value.as < Node > (); }
#line 1094 "ass1.tab.cc"
    break;

  case 52:
#line 162 "ass1.yy"
                                              { yylhs.value.as < Node > () = yystack_[0].value.as < Node > (); }
#line 1100 "ass1.tab.cc"
    break;

  case 53:
#line 163 "ass1.yy"
                                      { yylhs.value.as < Node > () = Node("ArrayVar", yystack_[3].value.as < std::string > ()); yylhs.value.as < Node > ().children.push_back(yystack_[1].value.as < Node > ()); }
#line 1106 "ass1.tab.cc"
    break;

  case 54:
#line 164 "ass1.yy"
                                             {yylhs.value.as < Node > ()=yystack_[1].value.as < Node > ();}
#line 1112 "ass1.tab.cc"
    break;

  case 55:
#line 167 "ass1.yy"
                                               { yylhs.value.as < Node > () = Node("BTRUE", yystack_[0].value.as < std::string > ()); }
#line 1118 "ass1.tab.cc"
    break;

  case 56:
#line 168 "ass1.yy"
                                           { yylhs.value.as < Node > () = Node("BFALSE", yystack_[0].value.as < std::string > ()); }
#line 1124 "ass1.tab.cc"
    break;


#line 1128 "ass1.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -23;

  const signed char parser::yytable_ninf_ = -33;

  const short
  parser::yypact_[] =
  {
     115,     7,    -8,    -7,   115,    -3,    17,   -23,    15,   115,
     208,    -4,     2,    20,   -23,   -23,   -23,    99,   -23,   -23,
     -23,     7,     7,     7,    23,   -23,   -23,    78,   -23,     9,
       6,    27,     7,   -23,     7,   -23,   215,     7,    21,   -23,
       7,    37,   -23,   -23,     7,   134,    11,    26,   146,   179,
     115,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,   -23,     7,   106,   -23,   -23,   -21,    34,   -23,
     121,   -23,   -23,     7,    49,   202,    55,    55,    39,    39,
      39,    39,   211,   211,   158,    38,   179,   -23,   -23,    96,
     170,   115,    76,     7,   115,   -23,   -23,    45,    80,   115,
     -23,    92,   -23
  };

  const signed char
  parser::yydefact_[] =
  {
       5,     0,     0,     0,     5,    30,     0,     2,     3,     0,
       6,     0,     0,    26,    17,    55,    56,    37,    39,    38,
      36,     0,     0,     0,     0,    52,    51,     0,    40,     0,
       0,     0,     0,     1,     0,     4,     7,     0,     0,    11,
       0,     0,    34,    12,     0,     0,     0,     0,    13,    50,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,     0,     0,    25,    18,    27,     0,    31,
       0,    54,    33,     0,    23,    47,    41,    42,    43,    44,
      45,    46,    48,    49,     0,     0,    21,    32,    10,    53,
      14,     5,     0,     0,     5,    24,    20,     0,     0,     5,
      35,     0,    19
  };

  const signed char
  parser::yypgoto_[] =
  {
     -23,   -23,    -1,   -23,   -23,   -23,   -22,   -23,    50,   -23,
     -23,   -23,   -23,     0,   -11,     1,   -23,    10,   -23
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     6,     7,     8,     9,    42,    46,    47,    10,    92,
      35,    11,    12,    24,    25,    26,    62,    48,    28
  };

  const signed char
  parser::yytable_[] =
  {
      13,    14,    43,    31,    13,    14,   -29,    29,    30,    13,
      14,    27,    65,    43,    41,    66,    32,    33,    68,    15,
      16,    37,    17,    18,    19,    20,    34,    61,    21,    38,
      22,    45,    63,    49,    60,    72,     5,    39,    67,    85,
      39,    40,    64,    22,    40,    23,    22,   -28,    99,    74,
      13,    14,    69,    73,    70,    41,    88,    91,    41,    36,
      94,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    51,    56,    86,    52,    53,    54,    55,    56,    57,
      96,    58,    59,    90,   100,    50,    54,    55,    56,    57,
      95,    13,    14,    98,    13,    14,   102,     0,   101,    13,
      14,     0,     0,    97,    51,     0,     0,    52,    53,    54,
      55,    56,    57,   -32,    58,    59,   -30,   -32,    44,   -32,
     -30,     1,   -30,     0,     2,     3,    87,     0,     0,     4,
       5,   -32,    51,     0,   -30,    52,    53,    54,    55,    56,
      57,    89,    58,    59,     0,     0,     0,    51,     0,     0,
      52,    53,    54,    55,    56,    57,    71,    58,    59,     0,
      51,     0,     0,    52,    53,    54,    55,    56,    57,     0,
      58,    59,    51,   -15,     0,    52,    53,    54,    55,    56,
      57,     0,    58,    59,    51,    93,     0,    52,    53,    54,
      55,    56,    57,     0,    58,    59,    51,   -16,     0,    52,
      53,    54,    55,    56,    57,    51,    58,    59,    52,    53,
      54,    55,    56,    57,    -8,    58,    59,    -8,    -8,     0,
       0,    -9,    -8,    -8,    -9,    -9,     0,     0,     0,    -9,
      -9,    52,    53,    54,    55,    56,    57,     0,    58,    59,
      52,    53,    54,    55,    56,    57
  };

  const signed char
  parser::yycheck_[] =
  {
       0,     0,    13,     4,     4,     4,    27,    15,    15,     9,
       9,     1,    34,    24,    35,    37,    19,     0,    40,    12,
      13,    25,    15,    16,    17,    18,    11,    21,    21,    27,
      23,    21,     5,    23,    25,    24,    15,    17,    38,    61,
      17,    21,    32,    23,    21,    38,    23,    27,     3,    50,
      50,    50,    15,    27,    44,    35,    22,     8,    35,     9,
      22,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    26,    33,    63,    29,    30,    31,    32,    33,    34,
       4,    36,    37,    73,     4,     7,    31,    32,    33,    34,
      91,    91,    91,    94,    94,    94,     4,    -1,    99,    99,
      99,    -1,    -1,    93,    26,    -1,    -1,    29,    30,    31,
      32,    33,    34,    17,    36,    37,    17,    21,    19,    23,
      21,     6,    23,    -1,     9,    10,    20,    -1,    -1,    14,
      15,    35,    26,    -1,    35,    29,    30,    31,    32,    33,
      34,    20,    36,    37,    -1,    -1,    -1,    26,    -1,    -1,
      29,    30,    31,    32,    33,    34,    22,    36,    37,    -1,
      26,    -1,    -1,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    -1,    36,    37,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    26,    36,    37,    29,    30,
      31,    32,    33,    34,     6,    36,    37,     9,    10,    -1,
      -1,     6,    14,    15,     9,    10,    -1,    -1,    -1,    14,
      15,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      29,    30,    31,    32,    33,    34
  };

  const signed char
  parser::yystos_[] =
  {
       0,     6,     9,    10,    14,    15,    40,    41,    42,    43,
      47,    50,    51,    52,    54,    12,    13,    15,    16,    17,
      18,    21,    23,    38,    52,    53,    54,    56,    57,    15,
      15,    41,    19,     0,    11,    49,    47,    25,    27,    17,
      21,    35,    44,    53,    19,    56,    45,    46,    56,    56,
       7,    26,    29,    30,    31,    32,    33,    34,    36,    37,
      25,    21,    55,     5,    56,    45,    45,    52,    45,    15,
      56,    22,    24,    27,    41,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    45,    56,    20,    22,    20,
      56,     8,    48,    27,    22,    41,     4,    56,    41,     3,
       4,    41,     4
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    39,    40,    41,    41,    42,    42,    42,    43,    43,
      44,    44,    44,    45,    45,    46,    46,    47,    47,    47,
      47,    47,    47,    48,    48,    49,    50,    50,    51,    51,
      52,    52,    52,    53,    54,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    57
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     0,     1,     2,     1,     2,
       3,     1,     1,     1,     3,     1,     3,     1,     3,     9,
       6,     4,     3,     0,     2,     2,     1,     3,     1,     3,
       1,     3,     4,     3,     2,     5,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     4,     3,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "DO", "ESTAT", "UNTIL", "IF",
  "THEN", "ELSE", "FOR", "FUNCTION", "RETURN", "BTRUE", "BFALSE", "REPEAT",
  "NAME", "WORD", "STR", "NUMBER", "START_SQBKT", "END_SQBKT",
  "START_PARENTHESES", "END_PARENTHESES", "START_BRACKET", "END_BRACKET",
  "EQUAL", "EQUALEQUAL", "COMMA", "SEMICOLON", "PLUS", "MINUS", "STAR",
  "SLASH", "CARET", "PERCENT", "DOT", "LESS", "BIGGER", "HASHTAG",
  "$accept", "stream", "chunk", "block", "block2", "argument", "explist",
  "explist2", "stat", "stat2", "laststat", "varlist", "varlist2",
  "variable", "tableconstructor", "functionCall", "funcbody", "exp",
  "Boolean", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    81,    81,    84,    85,    88,    89,    90,    93,    94,
      97,    98,    99,   102,   103,   106,   107,   110,   111,   112,
     113,   114,   115,   118,   119,   122,   125,   126,   129,   130,
     132,   133,   134,   137,   139,   142,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     160,   161,   162,   163,   164,   167,   168
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1515 "ass1.tab.cc"

