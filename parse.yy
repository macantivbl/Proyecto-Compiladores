//TEAM
%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines 
%define api.namespace {C0}
%define parser_class_name {Parser}

%code requires{
extern int numtype;

#include "Expresion.h"
namespace C0 {
    class Driver;
    class Scanner;      
}

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif
}

%parse-param { Scanner  &scanner  }
%parse-param { Driver  &driver  }

%code{
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

#include "Driver.hpp"

#undef yylex
#define yylex scanner.yylex
}

%define api.value.type variant
%define parse.assert

%token <std::string>    ID
%token <std::string>    NUMERO
%token <std::string>    CARACTER
%token <std::string>    STRING
%token                  IF ELSE WHILE SWITCH CASE FOR PRINT BREAK 
%token                  INT FLOAT DOUBLE VOID RETURN STRUCT CHAR
%token                  LKEY RKEY PYC COMA

%left                   ASIG /*=*/
%left                   OR /*||*/
%left                   AND /*&&*/
%left                   EQUAL DISTINCT /*== !=*/
%left                   LT GT  LTE GTE /* < > <= >=*/
%left                   MAS MENOS /* + -*/
%left                   MUL DIV MOD/* * / */
%left                   LCOR RCOR
%left                   NOT 
%left                   DOT
%left                   DOTS
%nonassoc               LPAR RPAR /* ( ) */
%nonassoc               IFX
%nonassoc               ELSE

%locations
%start program

%%
program 
    :
    declarations    
    ;

declarations
    : 
    declarations declaration
    | 
    %empty
    ;

declaration
    : 
    tipo decl_fun_var
    | 
    decl_struct        
    ;
    
decl_fun_var
    : 
    list_var PYC
	|
	decl_fun
    ;
    


list_var
    : list_var COMA var
    | var
    ;

var
    :
    ID 
    ;

type
    : 
    base arreglo
    |
    STRUCT ID
    ;
	
comp_arr
	:
	LCOR numero RCOR comp_arr
	|
	%empty
	;

base
    : 
    VOID{$$=0;}
    |
	CHAR{$$=1;}
    |
    INT{$$=2;}
    | 
	FLOAT{$$=3;}
	|
	DOUBLE{$$=4;}
    ;

arreglo
    : arreglo LCOR expresion RCOR
    | 
    LCOR expresion RCOR 
    ;

decl_struct
    : 
    STRUCT LKEY body_struct RKEY list_var PYC
	|
	STRUCT ID LKEY body_struct RKEY list_var PYC
    ;

body_struct
    : 
    body_struct decl_local
    | 
    decl_local
    ;

decl_local
    : 
    decl_var
	|
	decl_struct
    ;
    
decl_var
     :
	tipo list_var
     ;
     
bloqueSentencias
    : 
    sentencias
    | 
    %empty
    ;
    
    
sentencias
    :
    sentencias sentencia     
    | 
    sentencia
    ;

sentencia
    : 
    sentIf
    | 
    sentWhile
    | 
    sentAsig
    | 
    sentPutw
    | 
    sentPuts
    | 
    sentBreak
    | 
    sentProc
    | 
    sentReturn
    ;
     
sentReturn
    : RETURN expresion PYC
    ;

sentProc
    : 
    ID LPAR list_params RPAR PYC
    ;
	
decl_fun
    : 
    ID LPAR list_params RPAR LKEY decl_locales bloqueSentencias RKEY
    ;
    
list_params
    : 
    params
    | 
    %empty
    ;

params
    : 
    params COMA param
    | 
    param
    ;

param
    :
	type_param ID
    ;

lista_args
    : args
    | 
    %empty
    ;

args
    : 
    args COMA arg
    | 
    arg
    ;

arg
    : 
    base ID
    ;

expresion
    :
    expresion MAS expresion
    |
    expresion MENOS expresion
    |
    expresion MUL expresion
    |
    expresion DIV expresion
    |
    LPAR expresion RPAR
    |
    expresion MOD expresion
    |
    ID complemento | NUMERO | CARACTER
    ;
    
complemento
    : 
    DOT ID
    |
    array
    |
    LPAR list_params RPAR
    |
    %empty
    ;

array
    : 
    array LCOR expresion RCOR 
    | 
    LCOR expresion RCOR 
    ;
/* S-> S...S | ... | S...S| otro */
condicion     
    : 
    condicion OR condicion
    | 
    condicion AND condicion
    | 
    expresion EQUAL expresion
    | 
    expresion DISTINCT expresion
    | 
    expresion GT expresion
    | 
    expresion LT expresion
    | 
    expresion GTE expresion
    | 
    expresion LTE expresion
    | 
    NOT condicion
    | 
    LPAR condicion RPAR
    ;

sentIf
    : IF LPAR
    condicion    
    RPAR bloqueOSentencia
    sentElse    
    ;

sentElse
    : 
    ELSE bloqueOSentencia
    | 
    %empty %prec IFX
    ;

sentWhile
    : 
    WHILE LPAR
    condicion
    RPAR 
    bloqueOSentencia    
    ;
    
sentSwitch
    :
    SWITCH LPAR condicion RPAR LKEY body_switch RKEY
    ;
    
body_switch
    :
    caso body_switch 
    |
    predeterminado
    |
    %empty
    ;

caso
    :
    CASE expresion DOTS sentencia
    ;

local_decls
    : 
    local_decls local_decl
    | 
    %empty
    ;

local_decl
    : 
    base local_list PYC    
    ;

local_list
    : 
    local_list  COMA local
    | 
    local
    ;

local
    : 
    ID
    ;

expresion
    : 
    expresion MAS expresion 
    | 
    expresion MENOS expresion
    | 
    expresion MUL expresion
    | 
    expresion DIV expresion
    | 
    expresion MOD expresion
    | 
    LPAR expresion RPAR
    | 
    NUMERO
    |  
    ID complemento
    ;
    
predeterminado
    : 
    DEAFULT DOTS sentencia
    ;
    
sentFor
    :
    FOR LPAR sentAsig PYC condicion PYC sentAsig RPAR bloqueOSentencia
    ;
    
sentAsig
    : 
    left_part ASIG expresion PYC
    ;

left_part
    : 
    ID comp_struct
    | 
    ID array
    ;
    
comp_struct
    :
    comp_struct DOT ID
    |
    %empty
    ;

sentPutw
    :
    PRINT LPAR expresion
    RPAR PYC
    ;

sentPuts
    : 
    PRINT LPAR STRING
    RPAR PYC
    ;

sentBreak
    : BREAK    
    PYC
    ;
  
bloqueOSentencia
    : 
    LKEY bloqueSentencias RKEY
    | 
    sentencia
    ;

%%

void C0::Parser::error( const location_type &l, const std::string &err_message )
{
    cerr << "Error: " << err_message << " at " << l << endl;
}
