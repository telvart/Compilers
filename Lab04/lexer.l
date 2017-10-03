%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Define the tokens that you want to return from your lex as follows
#define PREPROC 255

#define OPENPAREN 323
#define CLOSEPAREN 324
#define OPENCURLY 325
#define CLOSECURLY 326
#define OPENSQUARE 327
#define CLOSESQUARE 328
#define COMMA 329
#define SEMICOLON 330

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

%}

%option noyywrap nounput yylineno
%x COMMENT

ID [a-zA-Z][a-zA-Z0-9_]*
STRVAL \"(\\.|[^"])*\"
INTVAL [0-9]*

%%
"//" {
    /****************************************
    * Matching with Single line comments in our
    * C code
    ******************************************/
    BEGIN COMMENT;
}

<COMMENT>[\n](\r)? {
    /****************************************
    * A new line indicates end of a single
    * line comment in C
    ****************************************/

    BEGIN 0;
}

<COMMENT>[ \t] {
    /****************************************
    * Lexer ignores the comments section
    * by Ignoring anything inside a comment
    ****************************************/
}

<COMMENT>. {
}


"void" {
  printf("VOID\n");
  return VOID;
}

"char" {
  printf("CHAR\n");
  return CHAR;
}

"short" {
  printf("SHORT\n");
  return SHORT;
}

"int" {
  printf("INT\n");
  return INT;
}

"long" {
  printf("LONG\n");
  return LONG;
}

"float" {
  printf("FLOAT\n");
  return FLOAT;
}

"double" {
  printf("DOUBLE\n");
  return DOUBLE;
}

"return" {
  printf("RETURN\n");
  return RETURN;
}

"do" {
  printf("DO\n");
  return DO;
}

"while" {
  printf("WHILE\n");
  return WHILE;
}

"for" {
  printf("FOR\n");
  return FOR;
}

"switch" {
  printf("SWITCH\n");
  return SWITCH;
}

"case" {
  printf("CASE\n");
  return CASE;
}

"default" {
  printf("DEFAULT\n");
  return DEFAULT;
}

"|" {

"if" {
  printf("IF\n");
  return IF;
}

"else" {
  printf("ELSE\n");
  return ELSE;
}

"continue" {
  printf("CONTINUE\n");
  return CONTINUE;
}

"break" {
  printf("BREAK\n");
  return BREAK;
}

"goto" {
  printf("GOTO\n");
  return GOTO;
}

"unsigned" {
  printf("UNSIGNED\n");
  return UNSIGNED;
}

"typedef" {
  printf("TYPEDEF\n");
  return TYPEDEF;
}

"struct" {
  printf("STRUCT\n");
  return STRUCT;
}

"union" {
  printf("UNION\n");
  return UNION;
}

"const" {
  printf("CONST\n");
  return CONST;
}

"static" {
  printf("STATIC\n");
  return STATIC;
}

"extern" {
  printf("EXTERN\n");
  return EXTERN;
}

"auto" {
  printf("AUTO\n");
  return AUTO;
}

"register" {
  printf("REGISTER\n");
  return REGISTER;
}

"sizeof" {
  printf("SIZEOF\n");
  return SIZEOF;
}

"==" {
  printf("EQ\n");
  return EQ;
}

"!=" {
  printf("NE\n");
  return NE;
}

">=" {
  printf("GE\n");
  return GE;
}

"<=" {
  printf("LE\n");
  return LE;
}

">" {
  printf("GT\n");
  return GT;
}

"<" {
  printf("LT\n");
  return LT;
}

"+" {
  printf("ADD\n");
  return ADD;
}

"-" {
  printf("SUB\n");
  return SUB;
}

"*" {
  printf("MUL\n");
  return MUL;

"|" {
}

"/" {
  printf("DIV\n");
  return DIV;
}

"%" {
  printf("MOD\n");
  return MOD;
}

"||" {
  printf("OR\n");
  return OR;
}

"&&" {
  printf("AND\n");
  return AND;
}

"|" {
  printf("BITOR\n");
  return BITOR;
}

"&" {
  printf("BITAND\n");
  return BITAND;
}

"^" {
  printf("BITXOR\n");
  return BITXOR;
}

"!" {
  printf("NOT\n");
  return NOT;
}

"~" {
  printf("COM\n");
  return COM;
}

"<<" {
  printf("LSH\n");
  return LSH;
}

">>" {
  printf("RSH\n");
  return RSH;
}

"=" {
  printf("SET\n");
  return SET;
}

"+=" {
  printf("SETADD\n");
  return SETADD;
}

"-=" {
  printf("SETSUB\n");
  return SETSUB;
}

"*=" {
  printf("SETMUL\n");
  return SETMUL;
}

"/=" {
  printf("SETDIV\n");
  return SETDIV;
}

"%=" {
  printf("SETMOD\n");
  return SETMOD;
}

"|=" {
  printf("SETOR\n");
  return SETOR;
}

"&=" {
  printf("SETAND\n");
  return SETAND;
}

"^=" {
  printf("SETXOR\n");
  return SETXOR;
}

"<<=" {
  printf("SETLSH\n");
  return SETLSH;
}

">>=" {
  printf("SETRSH\n");
  return SETRSH;
}



{ID} {
    /**************************************
    * If an identifier is matched, then
    * print ID and return a token ID
    **************************************/

    printf("ID\n");
    return ID;
}

{INTVAL} {
  printf("INTVAL\n");
  return INTVAL;
}

{STRVAL} {
  printf("STRVAL\n");
  return STRVAL;
}

%%
int main(int argc, const char* argv[]) {
    /*Make a call to yylex() recursively. Whenever yylex() is called, it scans
    tokens from the global input file yyin (which defaults to stdin). It
    continues until it either reaches an end-of-file (at which point it returns
    the value 0) or one of its actions executes a return statement.*/

    int running = 1;
    int result;
    while(running)
    {
      result = yylex();
      if (result == 0)
      {
        running = 0;
      }
    }

    return 0;
}
