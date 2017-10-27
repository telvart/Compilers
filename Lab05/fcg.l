%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcg.yacc.h>

#define PREPROC 255

#define OPENPAREN 323
#define CLOSEPAREN 324
#define OPENCURLY 325
#define CLOSECURLY 326
#define OPENSQUARE 327
#define CLOSESQUARE 328
#define COMMA 329
#define SEMICOLON 330
#define SPACE 331

#define ID 257

#define INTVAL 258
#define DBLVAL 259
#define FLTVAL 260
#define STRVAL 261
#define CHARVAL 262

#define VOID 263
#define SHORT 264
#define LONG 265
#define DOUBLE 266
#define CHAR 267
#define INT 268
#define FLOAT 269

#define EQ 270
#define NE 271
#define GE 272
#define LE 273
#define GT 274
#define LT 275
#define ADD 276
#define SUB 277
#define MUL 278
#define DIV 279
#define MOD 280
#define OR 281
#define AND 282
#define BITOR 283
#define BITAND 284
#define BITXOR 285
#define NOT 286
#define COM 287
#define LSH 288
#define RSH 289
#define SET 290
#define SETADD 291
#define SETSUB 292
#define SETMUL 293
#define SETDIV 294
#define SETMOD 295
#define SETOR 296
#define SETAND 297
#define SETXOR 298
#define SETLSH 299
#define SETRSH 300

#define RETURN 301
#define DO 302
#define WHILE 303
#define FOR 304
#define SWITCH 305
#define CASE 306
#define DEFAULT 307
#define IF 308
#define ELSE 309
#define CONTINUE 310
#define BREAK 311
#define GOTO 312

#define UNSIGNED 313
#define TYPEDEF 314
#define STRUCT 315
#define UNION 316
#define CONST 317
#define STATIC 318
#define EXTERN 319
#define AUTO 320
#define REGISTER 321
#define SIZEOF 322




#ifndef NDEBUG
#    define DEBUGF(...) printf(__VA_ARGS__)
#else
#    define DEBUGF(...)
#endif
%}

%option       noyywrap nounput yylineno
%x            COMMENT

whitesp       [ \t\n\r]
nonwhitesp    [^ \t\n\r]
ident         [a-zA-Z][a-zA-Z0-9_]*
digit         [0-9]
hexdigit      [0-9a-fA-F]
octdigit      [0-7]

STRVAL \"(\\.|[^"])*\"
CHARVAL \'(\\.|[^'])*\'
INTVAL [0-9]+|"0x"[0-9]+|"0"[0-9]+
DBLVAL [0-9]+"."[0-9]+
FLTVAL [0-9]+"."[0-9]+f
PREPROC "#"

%%

%{
 /**************************************************************************
  * Scan miscellaneous C punctuation.
  *************************************************************************/
%}

"("         { DEBUGF( "(\n" ); return '('; }
")"         { DEBUGF( ")\n" ); return ')'; }
"{"         { DEBUGF( "{\n" ); return '{'; }
"}"         { DEBUGF( "}\n" ); return '}'; }
"["         { DEBUGF( "[\n" ); return '['; }
"]"         { DEBUGF( "]\n" ); return ']'; }
","         { DEBUGF( ",\n" ); return ','; }
";"         { DEBUGF( ";\n" ); return ';'; }

%{
 /**************************************************************************
  * Scan C identifiers.
  *************************************************************************/
%}

{ident}         { DEBUGF( "ID\n" ); yylval.id = strdup(yytext); return ID; }

%{
 /**************************************************************************
  * Scan C literal values including strings, character literals, integer
  * literals, and floating point literals.
  *************************************************************************/
%}

/*
"0x"{hexdigit}+ { DEBUGF( "INTVAL\n" ); return INTVAL; }
"0"{octdigit}*  { DEBUGF( "INTVAL\n" ); return INTVAL; }
[1-9]{digit}*   { DEBUGF( "INTVAL\n" ); return INTVAL; }
*/

%{
 /**************************************************************************
  * Scan a multi-line C comment using left context or a C single line
  * comment to the end of the line.
  *************************************************************************/
%}

"//".*                      { /* ignored */ }

"/*"                        { BEGIN COMMENT; }
<COMMENT>"*/"               { BEGIN 0; }
<COMMENT>([\n](\r)?)|.      { /* ignored */ }

%{
 /**************************************************************************
  * Scan white space in-between tokens and ignore it.
  *************************************************************************/
%}

{whitesp}+ { /* ignored */  }

%{
 /**************************************************************************
  * Anything else that matches is unexpected so print an error.
  *************************************************************************/
%}

. {
    fprintf( stderr, "Unexpected input at line %d: '%s'\n", yylineno, yytext );
    exit( 1 );
}
