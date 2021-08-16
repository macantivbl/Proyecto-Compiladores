%require "3.0.4"
%skeleton "lalr1.cc"
%defines
%define api.token.raw
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires{
    #include <string>
    using namespace std;
    class Parser1;
}

%param {Parser1& parse1}

%locations
%define parse.trace
%define parse.error simple
%define parse.lac full

%code{
    #include "Parser1.hh"
}

%define api.token.prefix {TOK_}
%token 
    ASIG "="
    MENOS "-"
    MAS "+"
    MUL "*"
    DIV "/"
    LPAR "("
    RPAR ")"
    PYC ";"
    COMA    ","
    OR  "||"
    AND "&&"
    MAYOR   ">"
    MENOR   "<"
    IGUAL   "=="
    DISTIN  "!="
    LKEY    "{"
    RKEY    "}"
    INT "int"
    IF  "if"
    ELSE    "else"
    WHILE   "while"
    PUTS    "puts"
    PUTW    "putw"
    BREAK   "break"
;

%token <string> ID "id"
%token <string> NUMERO "numero"
%token <string> STRING "string"

%printer {yyo <<$$;}<*>;

%start program;
%%


program: declaraciones funcion | funcion;

declaraciones: declaraciones declaracion | declaracion;

declaracion: INT ID PYC;

funcion: INT ID LPAR LKEY bloqueoSentencias RKEY;

bloqueoSentencias: sentencias | %empty;

sentencias: sentencias sentencia | sentencia;

%left "+" "-";
%left "/" "*";
expresion: expresion "+" expresion
    | expresion "-" expresion
    | expresion "*" expresion
    | expresion "/" expresion
    | LPAR expresion RPAR
    | "numero"
    | "id";

%left "||";
%left "&&";
%left "<" ">";
%left "==" "!=";
condicion: condicion "||" condicion
        | condicion "&&" condicion
        | expresion ">" expresion
        | expresion "<" expresion
        | expresion "==" expresion
        | expresion "!=" expresion
        | LPAR condicion RPAR
        ;

sentIF: IF LPAR condicion RPAR LKEY bloqueoSentencias RKEY sentElse ;

sentElse: ELSE LKEY bloqueoSentencias RKEY | %empty;

sentWhile: WHILE LPAR condicion RPAR LKEY bloqueoSentencias RKEY;

sentAsig: ID ASIG expresion PYC;

sentPutw: PUTW LPAR expresion RPAR PYC;

sentPuts: PUTS LPAR STRING RPAR PYC;

sentBreak: BREAK PYC;

sentencia: sentIF
            | sentWhile
            | sentAsig
            | sentPutw
            | sentPuts
            | sentBreak;

%%
void yy::parser::error(const location_type& l, const string &m){
    cerr<<l<<": "<<m<<endl;
}