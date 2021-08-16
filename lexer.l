%{
#include <string>
#include <iostream>
using namespace std;
int  numtype;


#include "Scanner.hpp"
#undef  YY_DECL
#define YY_DECL int C0::Scanner::yylex( C0::Parser::semantic_type * const lval, C0::Parser::location_type *location )

using token = C0::Parser::token;

#define YY_NO_UNISTD_H
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);
%}

%option debug
%option nodefault
%option yyclass="C0::Scanner"
%option c++

cadena \"([\x20-\x21\x23-\xFE])*\"
caracter \'([\x20-\x21\x23-\xFE])?\'
%s COMENTARIO
%%
%{          /** Code executed at the beginning of yylex **/
            yylval = lval;
%}

<INITIAL>{
[0-9]+       {
               yylval->build< std::string >( yytext );
			   numtype=2;
               return( token::NUMERO );
            }
			
[+-]?([0-9]*[.])?[0-9]       {
               yylval->build< std::string >( yytext );
			   numtype=3;
               return( token::NUMERO );
            }

^-?\d+(?:,\d+)?(?:[Ee][+-]?\d+)?$       {
               yylval->build< std::string >( yytext );
			   numtype=4;
               return( token::NUMERO );
            }			

"if"       {
               return( token::IF );
            }            


"else"       {
               return( token::ELSE );
            }            


"while"       {
               return( token::WHILE );
            } 

"switch"		{
					return( token::SWITCH);
			}

"case"			{
					return( token::CASE);
				}
			
"for"			{
					return( token::FOR);
				}
"print"       {
               return( token::PRINT );
            }            

"struct"       {
               return( token::STRUCT );
            } 

"int"       {
               return( token::INT );
            }    

"void"       {
               return( token::VOID );
            }    

"break"       {
               return( token::BREAK );
            }    

"return"       {
               return( token::RETURN );
            }
			
{caracter}       {
               return( token::CARACTER );
            }			

[a-zA-Z][a-zA-Z0-9_]*   {
               yylval->build< std::string >( yytext );
               return( token::ID );
            }

{cadena}    {
               yylval->build< std::string >( yytext );
               return( token::STRING );
            }
			
"("       {
               return( token::LPAR );
            }

")"       {
               return( token::RPAR );
            }

"{"       {
               return( token::LKEY );
            }            

"}"       {
               return( token::RKEY );
            } 

"["       {
               return( token::LCOR );
            }            

"]"       {
               return( token::RCOR );
            }  

";"       {
               return( token::PYC );
            }  

","       {
               return( token::COMA );
            }           

"."       {
               return( token::DOT );
            } 

":"       {
               return( token::DOTS );
            }

"+"       {
               return( token::MAS );
            }

"-"       {
               return( token::MENOS );
            }

"*"       {
               return( token::MUL );
            }

"/"       {
               return( token::DIV );
            }  

"%"       {
               return( token::MOD );
            }

"!"       {
               return( token::NOT );
            }  

">"       {
               return( token::GT );
            }

"<"       {
               return( token::LT );
            }

">="       {
               return( token::GTE );
            }

"<="       {
               return( token::LTE );
            }

"="       {
               return( token::ASIG );
            }

"=="       {
               return( token::EQUAL );
            }
"!="       {
               return( token::DISTINCT );
            }

"||"       {
               return( token::OR );
            }                   

"&&"        {
               return( token::AND );
            } 

"/*"        {
               BEGIN(COMENTARIO);
            }


\n          {
               /** Update line number **/
               loc->lines();               
            }

[ \t\r]     {}

.           {
               cout<<"ERROR LÉXICO: "<<yytext << endl;
            }
}

<COMENTARIO>{
"*/"       {
               BEGIN(INITIAL);
            }
[*/]        {}
[^*/]       {}
}      
%%

int yyFlexLexer::yywrap(){
   return 1;
}