// A Bison parser, made by GNU Bison 3.7.5.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 29 "parser.yy"

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "Driver.hpp"

#undef yylex
#define yylex scanner.yylex

#line 57 "parser.tab.cc"


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

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "parser.yy"
namespace C0 {
#line 150 "parser.tab.cc"

  /// Build a parser object.
  Parser::Parser (Scanner  &scanner_yyarg, Driver  &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_condicion: // condicion
        value.copy< Expresion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_STRING: // STRING
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_condicion: // condicion
        value.move< Expresion > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_type: // type
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_condicion: // condicion
        value.YY_MOVE_OR_COPY< Expresion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_STRING: // STRING
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

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_condicion: // condicion
        value.move< Expresion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_condicion: // condicion
        value.copy< Expresion > (that.value);
        break;

      case symbol_kind::S_type: // type
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_STRING: // STRING
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_condicion: // condicion
        value.move< Expresion > (that.value);
        break;

      case symbol_kind::S_type: // type
        value.move< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

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
    YY_STACK_PRINT ();

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
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
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
      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_condicion: // condicion
        yylhs.value.emplace< Expresion > ();
        break;

      case symbol_kind::S_type: // type
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_STRING: // STRING
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // $@1: %empty
#line 67 "parser.yy"
          {
            driver.init();
    }
#line 741 "parser.tab.cc"
    break;

  case 3: // $@2: %empty
#line 71 "parser.yy"
    {
        driver.printSymTab();
    }
#line 749 "parser.tab.cc"
    break;

  case 8: // $@3: %empty
#line 87 "parser.yy"
    {
        driver.current_type=yystack_[0].value.as < int > ();
    }
#line 757 "parser.tab.cc"
    break;

  case 9: // declaracion: type $@3 ID PYC
#line 90 "parser.yy"
           {
        if(driver.isInSymbol(yystack_[1].value.as < std::string > ())){
            std::cout<<"Error variable ya declarada"<<std::endl;
        }else{
            driver.addSymbol(yystack_[1].value.as < std::string > ());
            driver.direcciones+=4;
            driver.setDir(yystack_[1].value.as < std::string > (), driver.direcciones);
            driver.setType(yystack_[1].value.as < std::string > (), driver.current_type);
            driver.setVar(yystack_[1].value.as < std::string > (),"var");
        }
    }
#line 773 "parser.tab.cc"
    break;

  case 10: // type: INT
#line 103 "parser.yy"
          {
        yylhs.value.as < int > ()=0;
    }
#line 781 "parser.tab.cc"
    break;

  case 11: // funcion: VOID ID LPAR RPAR LKEY bloqueSentencias RKEY
#line 110 "parser.yy"
    {          
        driver.printCI();
        driver.generateStrings();
        driver.translate();    
    }
#line 791 "parser.tab.cc"
    break;

  case 16: // expresion: expresion MAS expresion
#line 129 "parser.yy"
                              {yylhs.value.as < Expresion > ()=driver.add(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 797 "parser.tab.cc"
    break;

  case 17: // expresion: expresion MENOS expresion
#line 130 "parser.yy"
                               {yylhs.value.as < Expresion > ()=driver.sub(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 803 "parser.tab.cc"
    break;

  case 18: // expresion: expresion MUL expresion
#line 131 "parser.yy"
                             {yylhs.value.as < Expresion > ()=driver.mul(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 809 "parser.tab.cc"
    break;

  case 19: // expresion: expresion DIV expresion
#line 132 "parser.yy"
                             {yylhs.value.as < Expresion > ()=driver.div(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 815 "parser.tab.cc"
    break;

  case 20: // expresion: LPAR expresion RPAR
#line 133 "parser.yy"
                         { yylhs.value.as < Expresion > ()=yystack_[1].value.as < Expresion > ();}
#line 821 "parser.tab.cc"
    break;

  case 21: // expresion: NUMERO
#line 134 "parser.yy"
            {yylhs.value.as < Expresion > ()=driver.number(yystack_[0].value.as < std::string > ());}
#line 827 "parser.tab.cc"
    break;

  case 22: // expresion: ID
#line 135 "parser.yy"
        {yylhs.value.as < Expresion > ()=driver.ident(yystack_[0].value.as < std::string > ());}
#line 833 "parser.tab.cc"
    break;

  case 23: // expresion: expresion MAS expresion
#line 139 "parser.yy"
                              {yylhs.value.as < Expresion > ()=driver.add(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 839 "parser.tab.cc"
    break;

  case 24: // expresion: expresion MENOS expresion
#line 140 "parser.yy"
                               {yylhs.value.as < Expresion > ()=driver.sub(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 845 "parser.tab.cc"
    break;

  case 25: // expresion: expresion MUL expresion
#line 141 "parser.yy"
                             {yylhs.value.as < Expresion > ()=driver.mul(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 851 "parser.tab.cc"
    break;

  case 26: // expresion: expresion DIV expresion
#line 142 "parser.yy"
                             {yylhs.value.as < Expresion > ()=driver.div(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 857 "parser.tab.cc"
    break;

  case 27: // expresion: LPAR expresion RPAR
#line 143 "parser.yy"
                         { yylhs.value.as < Expresion > ()=yystack_[1].value.as < Expresion > ();}
#line 863 "parser.tab.cc"
    break;

  case 28: // expresion: NUMERO
#line 144 "parser.yy"
            {yylhs.value.as < Expresion > ()=driver.number(yystack_[0].value.as < std::string > ());}
#line 869 "parser.tab.cc"
    break;

  case 29: // expresion: ID
#line 145 "parser.yy"
        {yylhs.value.as < Expresion > ()=driver.ident(yystack_[0].value.as < std::string > ());}
#line 875 "parser.tab.cc"
    break;

  case 30: // expresion: expresion MAS expresion
#line 149 "parser.yy"
                              {yylhs.value.as < Expresion > ()=driver.add(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 881 "parser.tab.cc"
    break;

  case 31: // expresion: expresion MENOS expresion
#line 150 "parser.yy"
                               {yylhs.value.as < Expresion > ()=driver.sub(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 887 "parser.tab.cc"
    break;

  case 32: // expresion: expresion MUL expresion
#line 151 "parser.yy"
                             {yylhs.value.as < Expresion > ()=driver.mul(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 893 "parser.tab.cc"
    break;

  case 33: // expresion: expresion DIV expresion
#line 152 "parser.yy"
                             {yylhs.value.as < Expresion > ()=driver.div(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 899 "parser.tab.cc"
    break;

  case 34: // expresion: LPAR expresion RPAR
#line 153 "parser.yy"
                         { yylhs.value.as < Expresion > ()=yystack_[1].value.as < Expresion > ();}
#line 905 "parser.tab.cc"
    break;

  case 35: // expresion: NUMERO
#line 154 "parser.yy"
            {yylhs.value.as < Expresion > ()=driver.number(yystack_[0].value.as < std::string > ());}
#line 911 "parser.tab.cc"
    break;

  case 36: // expresion: ID
#line 155 "parser.yy"
        {yylhs.value.as < Expresion > ()=driver.ident(yystack_[0].value.as < std::string > ());}
#line 917 "parser.tab.cc"
    break;

  case 37: // expresion: expresion MAS expresion
#line 159 "parser.yy"
                              {yylhs.value.as < Expresion > ()=driver.add(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 923 "parser.tab.cc"
    break;

  case 38: // expresion: expresion MENOS expresion
#line 160 "parser.yy"
                               {yylhs.value.as < Expresion > ()=driver.sub(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 929 "parser.tab.cc"
    break;

  case 39: // expresion: expresion MUL expresion
#line 161 "parser.yy"
                             {yylhs.value.as < Expresion > ()=driver.mul(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 935 "parser.tab.cc"
    break;

  case 40: // expresion: expresion DIV expresion
#line 162 "parser.yy"
                             {yylhs.value.as < Expresion > ()=driver.div(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 941 "parser.tab.cc"
    break;

  case 41: // expresion: LPAR expresion RPAR
#line 163 "parser.yy"
                         { yylhs.value.as < Expresion > ()=yystack_[1].value.as < Expresion > ();}
#line 947 "parser.tab.cc"
    break;

  case 42: // expresion: NUMERO
#line 164 "parser.yy"
            {yylhs.value.as < Expresion > ()=driver.number(yystack_[0].value.as < std::string > ());}
#line 953 "parser.tab.cc"
    break;

  case 43: // expresion: ID
#line 165 "parser.yy"
        {yylhs.value.as < Expresion > ()=driver.ident(yystack_[0].value.as < std::string > ());}
#line 959 "parser.tab.cc"
    break;

  case 44: // condicion: condicion OR condicion
#line 169 "parser.yy"
                            {yylhs.value.as < Expresion > ()=driver._or(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 965 "parser.tab.cc"
    break;

  case 45: // condicion: condicion AND condicion
#line 170 "parser.yy"
                             {yylhs.value.as < Expresion > ()=driver._and(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 971 "parser.tab.cc"
    break;

  case 46: // condicion: expresion EQUAL expresion
#line 171 "parser.yy"
                               {yylhs.value.as < Expresion > ()=driver.equal(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 977 "parser.tab.cc"
    break;

  case 47: // condicion: expresion DISTINCT expresion
#line 172 "parser.yy"
                                  {yylhs.value.as < Expresion > ()=driver.distinct(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 983 "parser.tab.cc"
    break;

  case 48: // condicion: expresion GT expresion
#line 173 "parser.yy"
                            {yylhs.value.as < Expresion > ()=driver.gt(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 989 "parser.tab.cc"
    break;

  case 49: // condicion: expresion LT expresion
#line 174 "parser.yy"
                            {yylhs.value.as < Expresion > ()=driver.lt(yystack_[2].value.as < Expresion > (), yystack_[0].value.as < Expresion > ());}
#line 995 "parser.tab.cc"
    break;

  case 50: // condicion: LPAR condicion RPAR
#line 175 "parser.yy"
                         {yylhs.value.as < Expresion > ()=yystack_[1].value.as < Expresion > ();}
#line 1001 "parser.tab.cc"
    break;

  case 51: // $@4: %empty
#line 180 "parser.yy"
    {
        driver.numIf++;
        driver.iStack->push(driver.numIf);
    }
#line 1010 "parser.tab.cc"
    break;

  case 52: // $@5: %empty
#line 185 "parser.yy"
     {
         driver._if(yystack_[0].value.as < Expresion > (), driver.iStack->top());
         
     }
#line 1019 "parser.tab.cc"
    break;

  case 53: // $@6: %empty
#line 190 "parser.yy"
    {
        driver._goto("Lei",driver.iStack->top());
        driver._label("Le", driver.iStack->top());
    }
#line 1028 "parser.tab.cc"
    break;

  case 54: // sentIf: IF LPAR $@4 condicion $@5 RPAR LKEY bloqueSentencias RKEY $@6 sentElse
#line 195 "parser.yy"
    {
        driver._label("Lei", driver.iStack->top());
        driver.iStack->pop();
    }
#line 1037 "parser.tab.cc"
    break;

  case 57: // $@7: %empty
#line 208 "parser.yy"
    {
        driver.numWhile++;
        driver.wStack->push(driver.numWhile);
        driver._label("Lw", driver.wStack->top());

    }
#line 1048 "parser.tab.cc"
    break;

  case 58: // $@8: %empty
#line 215 "parser.yy"
     {
        driver._while(yystack_[0].value.as < Expresion > (), driver.wStack->top());
     }
#line 1056 "parser.tab.cc"
    break;

  case 59: // $@9: %empty
#line 219 "parser.yy"
    {
        driver.numWhile2++;
    }
#line 1064 "parser.tab.cc"
    break;

  case 60: // $@10: %empty
#line 223 "parser.yy"
     {
        driver.numWhile2--;
     }
#line 1072 "parser.tab.cc"
    break;

  case 61: // sentWhile: WHILE LPAR $@7 condicion $@8 RPAR LKEY $@9 bloqueSentencias $@10 RKEY
#line 227 "parser.yy"
     {
        driver._goto("Lw", driver.wStack->top());
        driver._label("Lew", driver.wStack->top());
        driver.wStack->pop();
     }
#line 1082 "parser.tab.cc"
    break;

  case 62: // $@11: %empty
#line 236 "parser.yy"
    {
        if(!driver.isInSymbol(yystack_[0].value.as < std::string > ())){
            std::cout<<"Error la varaible no fue declarada es:"<<yystack_[0].value.as < std::string > ()<<endl;
        }
    }
#line 1092 "parser.tab.cc"
    break;

  case 63: // sentAsig: ID $@11 ASIG expresion PYC
#line 242 "parser.yy"
    {
        driver.asign(yystack_[4].value.as < std::string > (), yystack_[1].value.as < Expresion > ());
    }
#line 1100 "parser.tab.cc"
    break;

  case 64: // $@12: %empty
#line 250 "parser.yy"
    {
        driver.writew(yystack_[0].value.as < Expresion > ());
    }
#line 1108 "parser.tab.cc"
    break;

  case 66: // $@13: %empty
#line 258 "parser.yy"
    {
        driver.writes(yystack_[0].value.as < std::string > (), driver.numString);
        driver.numString++;
    }
#line 1117 "parser.tab.cc"
    break;

  case 68: // $@14: %empty
#line 267 "parser.yy"
    {
        if(driver.numWhile2 <=0)              
            cout<<"Error no se puede poner un break sin while"<<endl;
    }
#line 1126 "parser.tab.cc"
    break;


#line 1130 "parser.tab.cc"

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
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

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
    YY_STACK_PRINT ();
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
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const signed char Parser::yypact_ninf_ = -57;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
     -10,    10,     9,    15,   -57,     4,   -57,   -57,    15,   -57,
     -57,    13,   -10,   -57,    36,    33,   -57,    41,    35,   -57,
     -57,    52,    53,    54,    55,   -57,    56,    35,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,    62,   -57,   -57,    79,    -2,
      69,   -57,   -57,    -2,     8,     8,   -57,   -57,   -57,    -2,
      49,   -57,    -8,     8,    39,   -13,   -13,    57,    43,    -2,
      -2,    -2,    -2,    58,   -57,    29,     6,    -2,    -2,    -2,
      -2,     8,     8,    59,    60,    74,   -57,    51,    51,   -57,
     -57,    75,   -57,    49,    49,    49,    49,    73,   -57,    80,
      81,   -57,   -57,    35,   -57,    78,    35,   -57,   -57,    89,
      82,    84,   -57,   -57,    35,    85,   -57
  };

  const signed char
  Parser::yydefact_[] =
  {
       2,     0,     0,     0,     5,     0,     1,    10,     3,     7,
       8,     0,     0,     6,     0,     0,     4,     0,    13,     9,
      62,     0,     0,     0,     0,    68,     0,    12,    70,    71,
      72,    73,    74,    75,    15,     0,    51,    57,     0,     0,
       0,    11,    14,     0,     0,     0,    66,    22,    21,     0,
      64,    69,     0,     0,     0,    52,    58,     0,     0,     0,
       0,     0,     0,     0,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    16,    17,    18,
      19,     0,    50,    46,    47,    49,    48,    44,    45,     0,
       0,    67,    65,    13,    59,     0,    13,    53,    60,    56,
       0,     0,    54,    61,    13,     0,    55
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -57,   -57,   -57,   -57,   -57,    91,   -57,   -57,    90,   -56,
     -57,   -39,   -38,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,    76
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     2,     3,    12,     8,     9,    14,    10,     4,    26,
      27,    54,    55,    28,    44,    73,    99,   102,    29,    45,
      74,    96,   100,    30,    35,    31,    63,    32,    57,    33,
      40,    34
  };

  const signed char
  Parser::yytable_[] =
  {
      50,    47,    48,     1,    52,    71,    72,    56,    64,     6,
      58,    47,    48,     5,    65,    66,    59,    60,    61,    62,
      77,    78,    79,    80,    71,    72,    49,     7,    83,    84,
      85,    86,    11,    87,    88,    82,    53,    95,    20,    17,
      98,    21,    15,    22,    23,    24,    25,    18,   105,    67,
      68,    69,    70,    59,    60,    61,    62,    19,    76,    67,
      68,    69,    70,    59,    60,    61,    62,    59,    60,    61,
      62,    41,    76,    59,    60,    61,    62,    61,    62,    43,
      36,    37,    38,    39,    46,    51,    75,    81,    89,    90,
      91,    92,    72,    97,    93,    94,   101,   103,   104,    13,
     106,     0,    16,    42
  };

  const signed char
  Parser::yycheck_[] =
  {
      39,     3,     4,    13,    43,    18,    19,    45,    16,     0,
      49,     3,     4,     3,    53,    53,    24,    25,    26,    27,
      59,    60,    61,    62,    18,    19,    28,    12,    67,    68,
      69,    70,    28,    71,    72,    29,    28,    93,     3,     3,
      96,     6,    29,     8,     9,    10,    11,    14,   104,    20,
      21,    22,    23,    24,    25,    26,    27,    16,    29,    20,
      21,    22,    23,    24,    25,    26,    27,    24,    25,    26,
      27,    15,    29,    24,    25,    26,    27,    26,    27,    17,
      28,    28,    28,    28,     5,    16,    29,    29,    29,    29,
      16,    16,    19,    15,    14,    14,     7,    15,    14,     8,
      15,    -1,    12,    27
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    13,    31,    32,    38,     3,     0,    12,    34,    35,
      37,    28,    33,    35,    36,    29,    38,     3,    14,    16,
       3,     6,     8,     9,    10,    11,    39,    40,    43,    48,
      53,    55,    57,    59,    61,    54,    28,    28,    28,    28,
      60,    15,    61,    17,    44,    49,     5,     3,     4,    28,
      41,    16,    41,    28,    41,    42,    42,    58,    41,    24,
      25,    26,    27,    56,    16,    41,    42,    20,    21,    22,
      23,    18,    19,    45,    50,    29,    29,    41,    41,    41,
      41,    29,    29,    41,    41,    41,    41,    42,    42,    29,
      29,    16,    16,    14,    14,    39,    51,    15,    39,    46,
      52,     7,    47,    15,    14,    39,    15
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    30,    32,    33,    31,    31,    34,    34,    36,    35,
      37,    38,    39,    39,    40,    40,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    42,    42,    42,    42,    42,    42,
      42,    44,    45,    46,    43,    47,    47,    49,    50,    51,
      52,    48,    54,    53,    56,    55,    58,    57,    60,    59,
      61,    61,    61,    61,    61,    61
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     0,     0,     4,     1,     2,     1,     0,     4,
       1,     7,     1,     0,     2,     1,     3,     3,     3,     3,
       3,     1,     1,     3,     3,     3,     3,     3,     1,     1,
       3,     3,     3,     3,     3,     1,     1,     3,     3,     3,
       3,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     0,     0,     0,    11,     4,     0,     0,     0,     0,
       0,    11,     0,     5,     0,     6,     0,     6,     0,     3,
       1,     1,     1,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUMERO",
  "STRING", "IF", "ELSE", "WHILE", "PUTS", "PUTW", "BREAK", "INT", "VOID",
  "LKEY", "RKEY", "PYC", "ASIG", "OR", "AND", "EQUAL", "DISTINCT", "LT",
  "GT", "MAS", "MENOS", "MUL", "DIV", "LPAR", "RPAR", "$accept", "program",
  "$@1", "$@2", "declaraciones", "declaracion", "$@3", "type", "funcion",
  "bloqueSentencias", "sentencias", "expresion", "condicion", "sentIf",
  "$@4", "$@5", "$@6", "sentElse", "sentWhile", "$@7", "$@8", "$@9",
  "$@10", "sentAsig", "$@11", "sentPutw", "$@12", "sentPuts", "$@13",
  "sentBreak", "$@14", "sentencia", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,    67,    67,    71,    67,    76,    81,    82,    87,    86,
     103,   109,   118,   119,   123,   125,   129,   130,   131,   132,
     133,   134,   135,   139,   140,   141,   142,   143,   144,   145,
     149,   150,   151,   152,   153,   154,   155,   159,   160,   161,
     162,   163,   164,   165,   169,   170,   171,   172,   173,   174,
     175,   180,   185,   190,   179,   202,   203,   208,   215,   219,
     223,   207,   236,   235,   250,   249,   258,   257,   267,   266,
     275,   276,   277,   278,   279,   280
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
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

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
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
      25,    26,    27,    28,    29
    };
    // Last valid token kind.
    const int code_max = 284;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 5 "parser.yy"
} // C0
#line 1560 "parser.tab.cc"

#line 282 "parser.yy"


void C0::Parser::error( const location_type &l, const std::string &err_message )
{
    cerr << "Error: " << err_message << " at " << l << endl;
}
