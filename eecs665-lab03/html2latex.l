%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int list_type;
%}

%option       noyywrap nounput yylineno
%x            COMMENT PARA PRE OL UL LI BIG SMALL BOLD ITAL EMPH STRONG SUP SUB

%%

"<h1>"[^<]*"</h1>" {
    /**************************************************************************
     * Matched an HTML H1 header so print it out as a LateX section title.
     * The beginning and ending tags need to be stripped off before the
     * title can be formatted in LateX.
     *************************************************************************/
    yytext[yyleng-5] = 0;
    printf( "\\section{%s}", yytext+4 );
}

"<h2>"[^<]*"</h2>" {
  yytext[yyleng-5] = 0;
  printf("%s", yytext);
}

"<h3>"[^<]*"</h3>" {
  yytext[yyleng-5] = 0;
  printf("%s", yytext);
}

"<pre>" {
  printf("%s", yytext);
  BEGIN PRE;
}

<PRE>[a-zA-Z0-9\." "]* {
  printf("%s", yytext);
}

<PRE>"</pre>" {
  printf("%s", yytext);
  BEGIN 0;
}


"<p>" {
  printf("para");
  BEGIN PARA;
}

<PARA>[a-zA-Z0-9\." "]* {
  printf("%s", yytext);
}

<PARA>"</p>" {
  printf("%s/n", yytext);
  BEGIN 0;
}

<PARA>"<i>" {
  printf("%s", yytext);
  BEGIN ITAL;
}

<PARA>"<sup>" {
  printf("%s", yytext);
  BEGIN SUP;
}

<PARA>"<sub>" {
  printf("%s", yytext);
  BEGIN SUB;
}

<SUB>[a-zA-Z0-9\." "]* {
  printf("%s", yytext);
}

<SUB>"</sub>" {
  printf("%s", yytext);
  BEGIN PARA;
}

<SUP>[a-zA-Z0-9\." "]* {
  printf("%s", yytext);
}

<SUP>"</sup>" {
  printf("%s", yytext);
  BEGIN PARA;
}

<PARA>"<strong>" {
  printf("%s", yytext);
  BEGIN STRONG;
}

<STRONG>[a-zA-Z0-9\." "]* {
  printf("%s", yytext);
}

<STRONG>"</strong>" {
  printf("%s", yytext);
  BEGIN PARA;
}

<PARA>"<em>" {
  printf("%s", yytext);
  BEGIN EMPH;
}

<EMPH>[a-zA-Z0-9\." "]* {
  printf("%s", yytext);
}

<EMPH>"</em>" {
  printf("%s", yytext);
  BEGIN PARA;
}

<ITAL>[a-zA-Z0-9\." "]* {
  printf("%s", yytext);
}

<ITAL>"</i>" {
  printf("%s", yytext);
  BEGIN PARA;
}

<PARA>"<b>" {
  printf("%s", yytext);
  BEGIN BOLD;
}

<BOLD>[a-zA-Z0-9\." "]* {
  printf("%s", yytext);
}

<BOLD>"</b>" {
  printf("%s", yytext);
  BEGIN PARA;
}

<PARA>"<small>" {
  printf("%s", yytext);
  BEGIN SMALL;
}

<SMALL>[a-zA-Z0-9\." "]* {
  printf("%s", yytext);
}

<SMALL>"</small>" {
  printf("%s", yytext);
  BEGIN PARA;
}

<PARA>"<big>" {
  printf("%s", yytext);
  BEGIN BIG;
}

<BIG>[a-zA-Z0-9\." "]* {
  printf("%s", yytext);
}


<BIG>"</big>" {
  printf("%s", yytext);
  BEGIN PARA;
}



"<!--" {
    /**************************************************************************
     * Matched an HTML comment so print it out as a LateX comment. The
     * beginning and ending tags are stripped off before the LateX comment
     * is emitted.
     *************************************************************************/
    printf( "%% " );
    BEGIN COMMENT;
}

[ \t\n\r]+ {
    /**************************************************************************
     * Matched some whitespace that is not inside of an HTML tag. We
     * just ignore the whitespace.
     *************************************************************************/
}

. {
    /**************************************************************************
     * Matched something that we did not expect to see. Issue an error and
     * exit the program with a failure message.
     *************************************************************************/
    fprintf( stderr, "Unexpected input at line %d: '%s'\n", yylineno, yytext );
    exit( 1 );
}

<COMMENT>"-->" {
    /**************************************************************************
     * Matched an HTML end comment while parsing an HTML comment. Print out
     * a new line and resume normal parsing.
     *************************************************************************/
    printf( "\n" );
    BEGIN 0;
}

<COMMENT>[\n](\r)? {
    /**************************************************************************
     * Matched a newline and possible carriage return while parsing an HTML
     * comment. Print out a new line making sure to mark the next line as a
     * comment as well.
     *************************************************************************/
    printf( "\n%% " );
}

<COMMENT>[ \t] {
    /**************************************************************************
     * Matched some white space while parsing an HTML comment. Print out
     * the white space as is.
     *************************************************************************/
    printf( "%s", yytext );
}

<COMMENT>. {
    /**************************************************************************
     * Matched any other text while parsing an HTML comment. Print out
     * the text as is.
     *************************************************************************/
    printf( "%s", yytext );
}

%%

/**************************************************************************
 * The main function for the HTML to LateX converter. Here we do three
 * things:
 *  1. Print out the LateX document header.
 *  2. Invoke the lexer to print out the LateX document
 *  3. Print out the LateX footer.
 *************************************************************************/
int main( int argc, const char *argv[] ) {
    printf( "\\documentclass[12pt]{article}\n" );
    printf( "\\usepackage{fixltx2e}\n" );
    printf( "\n" );
    printf( "\\setlength{\\parindent}{0.0in}\n" );
    printf( "\\setlength{\\parskip}{0.125in}\n" );
    printf( "\n\n" );
    printf( "\\begin{document}\n" );
    yylex();
    printf( "\\end{document}\n" );
    return 0;
}
