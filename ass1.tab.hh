// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file ass1.tab.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_ASS1_TAB_HH_INCLUDED
# define YY_YY_ASS1_TAB_HH_INCLUDED
// "%code requires" blocks.
#line 5 "ass1.yy"

    #include "node.h"

#line 52 "ass1.tab.hh"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif


#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

namespace yy {
#line 186 "ass1.tab.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // stream
      // chunk
      // block
      // block2
      // argument
      // explist
      // explist2
      // stat
      // stat2
      // laststat
      // varlist
      // varlist2
      // variable
      // tableconstructor
      // functionCall
      // funcbody
      // exp
      // Boolean
      char dummy1[sizeof (Node)];

      // DO
      // ESTAT
      // UNTIL
      // IF
      // THEN
      // ELSE
      // FOR
      // FUNCTION
      // RETURN
      // BTRUE
      // BFALSE
      // REPEAT
      // NAME
      // WORD
      // STR
      // NUMBER
      // START_SQBKT
      // END_SQBKT
      // START_PARENTHESES
      // END_PARENTHESES
      // START_BRACKET
      // END_BRACKET
      // EQUAL
      // EQUALEQUAL
      // COMMA
      // SEMICOLON
      // PLUS
      // MINUS
      // STAR
      // SLASH
      // CARET
      // PERCENT
      // DOT
      // LESS
      // BIGGER
      // HASHTAG
      char dummy2[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END = 0,
        DO = 258,
        ESTAT = 259,
        UNTIL = 260,
        IF = 261,
        THEN = 262,
        ELSE = 263,
        FOR = 264,
        FUNCTION = 265,
        RETURN = 266,
        BTRUE = 267,
        BFALSE = 268,
        REPEAT = 269,
        NAME = 270,
        WORD = 271,
        STR = 272,
        NUMBER = 273,
        START_SQBKT = 274,
        END_SQBKT = 275,
        START_PARENTHESES = 276,
        END_PARENTHESES = 277,
        START_BRACKET = 278,
        END_BRACKET = 279,
        EQUAL = 280,
        EQUALEQUAL = 281,
        COMMA = 282,
        SEMICOLON = 283,
        PLUS = 284,
        MINUS = 285,
        STAR = 286,
        SLASH = 287,
        CARET = 288,
        PERCENT = 289,
        DOT = 290,
        LESS = 291,
        BIGGER = 292,
        HASHTAG = 293
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef signed char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Node&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Node& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
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
        value.template destroy< Node > ();
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type(token_type (tok))
      {
        YY_ASSERT (tok == token::END);
      }
#else
      symbol_type (int tok)
        : super_type(token_type (tok))
      {
        YY_ASSERT (tok == token::END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type(token_type (tok), std::move (v))
      {
        YY_ASSERT (tok == token::DO || tok == token::ESTAT || tok == token::UNTIL || tok == token::IF || tok == token::THEN || tok == token::ELSE || tok == token::FOR || tok == token::FUNCTION || tok == token::RETURN || tok == token::BTRUE || tok == token::BFALSE || tok == token::REPEAT || tok == token::NAME || tok == token::WORD || tok == token::STR || tok == token::NUMBER || tok == token::START_SQBKT || tok == token::END_SQBKT || tok == token::START_PARENTHESES || tok == token::END_PARENTHESES || tok == token::START_BRACKET || tok == token::END_BRACKET || tok == token::EQUAL || tok == token::EQUALEQUAL || tok == token::COMMA || tok == token::SEMICOLON || tok == token::PLUS || tok == token::MINUS || tok == token::STAR || tok == token::SLASH || tok == token::CARET || tok == token::PERCENT || tok == token::DOT || tok == token::LESS || tok == token::BIGGER || tok == token::HASHTAG);
      }
#else
      symbol_type (int tok, const std::string& v)
        : super_type(token_type (tok), v)
      {
        YY_ASSERT (tok == token::DO || tok == token::ESTAT || tok == token::UNTIL || tok == token::IF || tok == token::THEN || tok == token::ELSE || tok == token::FOR || tok == token::FUNCTION || tok == token::RETURN || tok == token::BTRUE || tok == token::BFALSE || tok == token::REPEAT || tok == token::NAME || tok == token::WORD || tok == token::STR || tok == token::NUMBER || tok == token::START_SQBKT || tok == token::END_SQBKT || tok == token::START_PARENTHESES || tok == token::END_PARENTHESES || tok == token::START_BRACKET || tok == token::END_BRACKET || tok == token::EQUAL || tok == token::EQUALEQUAL || tok == token::COMMA || tok == token::SEMICOLON || tok == token::PLUS || tok == token::MINUS || tok == token::STAR || tok == token::SLASH || tok == token::CARET || tok == token::PERCENT || tok == token::DOT || tok == token::LESS || tok == token::BIGGER || tok == token::HASHTAG);
      }
#endif
    };

    /// Build a parser object.
    parser ();
    virtual ~parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END ()
      {
        return symbol_type (token::END);
      }
#else
      static
      symbol_type
      make_END ()
      {
        return symbol_type (token::END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO (std::string v)
      {
        return symbol_type (token::DO, std::move (v));
      }
#else
      static
      symbol_type
      make_DO (const std::string& v)
      {
        return symbol_type (token::DO, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ESTAT (std::string v)
      {
        return symbol_type (token::ESTAT, std::move (v));
      }
#else
      static
      symbol_type
      make_ESTAT (const std::string& v)
      {
        return symbol_type (token::ESTAT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNTIL (std::string v)
      {
        return symbol_type (token::UNTIL, std::move (v));
      }
#else
      static
      symbol_type
      make_UNTIL (const std::string& v)
      {
        return symbol_type (token::UNTIL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (std::string v)
      {
        return symbol_type (token::IF, std::move (v));
      }
#else
      static
      symbol_type
      make_IF (const std::string& v)
      {
        return symbol_type (token::IF, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THEN (std::string v)
      {
        return symbol_type (token::THEN, std::move (v));
      }
#else
      static
      symbol_type
      make_THEN (const std::string& v)
      {
        return symbol_type (token::THEN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (std::string v)
      {
        return symbol_type (token::ELSE, std::move (v));
      }
#else
      static
      symbol_type
      make_ELSE (const std::string& v)
      {
        return symbol_type (token::ELSE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (std::string v)
      {
        return symbol_type (token::FOR, std::move (v));
      }
#else
      static
      symbol_type
      make_FOR (const std::string& v)
      {
        return symbol_type (token::FOR, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FUNCTION (std::string v)
      {
        return symbol_type (token::FUNCTION, std::move (v));
      }
#else
      static
      symbol_type
      make_FUNCTION (const std::string& v)
      {
        return symbol_type (token::FUNCTION, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (std::string v)
      {
        return symbol_type (token::RETURN, std::move (v));
      }
#else
      static
      symbol_type
      make_RETURN (const std::string& v)
      {
        return symbol_type (token::RETURN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BTRUE (std::string v)
      {
        return symbol_type (token::BTRUE, std::move (v));
      }
#else
      static
      symbol_type
      make_BTRUE (const std::string& v)
      {
        return symbol_type (token::BTRUE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BFALSE (std::string v)
      {
        return symbol_type (token::BFALSE, std::move (v));
      }
#else
      static
      symbol_type
      make_BFALSE (const std::string& v)
      {
        return symbol_type (token::BFALSE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REPEAT (std::string v)
      {
        return symbol_type (token::REPEAT, std::move (v));
      }
#else
      static
      symbol_type
      make_REPEAT (const std::string& v)
      {
        return symbol_type (token::REPEAT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NAME (std::string v)
      {
        return symbol_type (token::NAME, std::move (v));
      }
#else
      static
      symbol_type
      make_NAME (const std::string& v)
      {
        return symbol_type (token::NAME, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WORD (std::string v)
      {
        return symbol_type (token::WORD, std::move (v));
      }
#else
      static
      symbol_type
      make_WORD (const std::string& v)
      {
        return symbol_type (token::WORD, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STR (std::string v)
      {
        return symbol_type (token::STR, std::move (v));
      }
#else
      static
      symbol_type
      make_STR (const std::string& v)
      {
        return symbol_type (token::STR, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER (std::string v)
      {
        return symbol_type (token::NUMBER, std::move (v));
      }
#else
      static
      symbol_type
      make_NUMBER (const std::string& v)
      {
        return symbol_type (token::NUMBER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_START_SQBKT (std::string v)
      {
        return symbol_type (token::START_SQBKT, std::move (v));
      }
#else
      static
      symbol_type
      make_START_SQBKT (const std::string& v)
      {
        return symbol_type (token::START_SQBKT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_SQBKT (std::string v)
      {
        return symbol_type (token::END_SQBKT, std::move (v));
      }
#else
      static
      symbol_type
      make_END_SQBKT (const std::string& v)
      {
        return symbol_type (token::END_SQBKT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_START_PARENTHESES (std::string v)
      {
        return symbol_type (token::START_PARENTHESES, std::move (v));
      }
#else
      static
      symbol_type
      make_START_PARENTHESES (const std::string& v)
      {
        return symbol_type (token::START_PARENTHESES, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_PARENTHESES (std::string v)
      {
        return symbol_type (token::END_PARENTHESES, std::move (v));
      }
#else
      static
      symbol_type
      make_END_PARENTHESES (const std::string& v)
      {
        return symbol_type (token::END_PARENTHESES, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_START_BRACKET (std::string v)
      {
        return symbol_type (token::START_BRACKET, std::move (v));
      }
#else
      static
      symbol_type
      make_START_BRACKET (const std::string& v)
      {
        return symbol_type (token::START_BRACKET, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_BRACKET (std::string v)
      {
        return symbol_type (token::END_BRACKET, std::move (v));
      }
#else
      static
      symbol_type
      make_END_BRACKET (const std::string& v)
      {
        return symbol_type (token::END_BRACKET, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL (std::string v)
      {
        return symbol_type (token::EQUAL, std::move (v));
      }
#else
      static
      symbol_type
      make_EQUAL (const std::string& v)
      {
        return symbol_type (token::EQUAL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUALEQUAL (std::string v)
      {
        return symbol_type (token::EQUALEQUAL, std::move (v));
      }
#else
      static
      symbol_type
      make_EQUALEQUAL (const std::string& v)
      {
        return symbol_type (token::EQUALEQUAL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (std::string v)
      {
        return symbol_type (token::COMMA, std::move (v));
      }
#else
      static
      symbol_type
      make_COMMA (const std::string& v)
      {
        return symbol_type (token::COMMA, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (std::string v)
      {
        return symbol_type (token::SEMICOLON, std::move (v));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const std::string& v)
      {
        return symbol_type (token::SEMICOLON, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (std::string v)
      {
        return symbol_type (token::PLUS, std::move (v));
      }
#else
      static
      symbol_type
      make_PLUS (const std::string& v)
      {
        return symbol_type (token::PLUS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (std::string v)
      {
        return symbol_type (token::MINUS, std::move (v));
      }
#else
      static
      symbol_type
      make_MINUS (const std::string& v)
      {
        return symbol_type (token::MINUS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STAR (std::string v)
      {
        return symbol_type (token::STAR, std::move (v));
      }
#else
      static
      symbol_type
      make_STAR (const std::string& v)
      {
        return symbol_type (token::STAR, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SLASH (std::string v)
      {
        return symbol_type (token::SLASH, std::move (v));
      }
#else
      static
      symbol_type
      make_SLASH (const std::string& v)
      {
        return symbol_type (token::SLASH, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARET (std::string v)
      {
        return symbol_type (token::CARET, std::move (v));
      }
#else
      static
      symbol_type
      make_CARET (const std::string& v)
      {
        return symbol_type (token::CARET, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PERCENT (std::string v)
      {
        return symbol_type (token::PERCENT, std::move (v));
      }
#else
      static
      symbol_type
      make_PERCENT (const std::string& v)
      {
        return symbol_type (token::PERCENT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (std::string v)
      {
        return symbol_type (token::DOT, std::move (v));
      }
#else
      static
      symbol_type
      make_DOT (const std::string& v)
      {
        return symbol_type (token::DOT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS (std::string v)
      {
        return symbol_type (token::LESS, std::move (v));
      }
#else
      static
      symbol_type
      make_LESS (const std::string& v)
      {
        return symbol_type (token::LESS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BIGGER (std::string v)
      {
        return symbol_type (token::BIGGER, std::move (v));
      }
#else
      static
      symbol_type
      make_BIGGER (const std::string& v)
      {
        return symbol_type (token::BIGGER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HASHTAG (std::string v)
      {
        return symbol_type (token::HASHTAG, std::move (v));
      }
#else
      static
      symbol_type
      make_HASHTAG (const std::string& v)
      {
        return symbol_type (token::HASHTAG, v);
      }
#endif


  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    /// In theory \a t should be a token_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static token_number_type yytranslate_ (int t);

    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    /// For a symbol, its name in clear.
    static const char* const yytname_[];

    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      std::ptrdiff_t
      ssize () const YY_NOEXCEPT
      {
        return std::ptrdiff_t (size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Some specific tokens.
    static const token_number_type yy_error_token_ = 1;
    static const token_number_type yy_undef_token_ = 2;

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 245,     ///< Last index in yytable_.
      yynnts_ = 19,  ///< Number of nonterminal symbols.
      yyfinal_ = 33, ///< Termination state number.
      yyntokens_ = 39  ///< Number of tokens.
    };


  };

  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
    };
    const int user_token_number_max_ = 293;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
  {
    switch (this->type_get ())
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
        value.move< Node > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->type_get ())
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
        value.copy< Node > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
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
        value.move< Node > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

} // yy
#line 1983 "ass1.tab.hh"





#endif // !YY_YY_ASS1_TAB_HH_INCLUDED
