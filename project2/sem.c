# include <stdio.h>
# include "cc.h"
# include "semutil.h"
# include "sem.h"
# include "sym.h"

extern int formalnum;
extern char formaltypes[];
extern int localnum;
extern char localtypes[];
extern int localwidths[];

int numlabels = 0;                      /* total labels in file */
int numblabels = 0;                     /* toal backpatch labels in file */

char typeAsChar(int s_mode)
{
  if(s_mode == T_INT)
    return 'i';
  else
    return 'f';
}

int nextLabelNum()
{
  return ++numlabels;
}

int nextLabelbNum()
{
  return ++numblabels;
}

/*
 * backpatch - backpatch list of quadruples starting at p with k
 */
void backpatch(struct sem_rec *p, int k)
{
   //fprintf(stderr, "sem: backpatch not implemented\n");
   printf("B%d=L%d\n", p->s_place, k);
}

/*
 * bgnstmt - encountered the beginning of a statement
 */
void bgnstmt()
{
  extern int lineno;

  printf("bgnstmt %d\n", lineno);
  //   fprintf(stderr, "sem: bgnstmt not implemented\n");
}

/*
 * call - procedure invocation
 */
struct sem_rec *call(char *f, struct sem_rec *args)
{
   //fprintf(stderr, "sem: call not implemented\n");
   int argc = 0;

   while(args)
   {
     printf("arg%c t%d\n", typeAsChar(args->s_mode), args->s_place);
     args = args->back.s_link;
     argc++;
   }
   printf("t%d := global %s\n", nexttemp(), f);

   struct id_entry* temp;
   int returnType = T_INT;
   if((temp = lookup(f, 2)) != NULL)
    returnType = temp->i_type;

   printf("t%d := f%c t%d %d\n", nexttemp(), typeAsChar(returnType), currtemp(), argc);

   struct sem_rec* temp2 = node(currtemp(), returnType, NULL, NULL);
   return temp2;
}

/*
 * ccand - logical and
 */
struct sem_rec *ccand(struct sem_rec *e1, int m, struct sem_rec *e2)
{
   //fprintf(stderr, "sem: ccand not implemented\n");
   //return ((struct sem_rec *) NULL);
   struct sem_rec* temp = gen("&&", e1, e2, e1->s_mode);
   printf("bt t%d B%d\n", temp->s_place, nextLabelbNum());
   printf("br B%d\n", nextLabelbNum());

   backpatch(e1->back.s_true, m);
   temp->back.s_true = e2->back.s_true;
   temp->s_false = merge(e1->s_false, e2->s_false);

   return node(0, 0, node(numblabels-1, 0, NULL, NULL), node(numblabels, 0, NULL, NULL));
}

/*
 * ccexpr - convert arithmetic expression to logical expression
 */
struct sem_rec *ccexpr(struct sem_rec *e)
{
   struct sem_rec *temp;

   if(e != NULL){

     temp = gen("!=", e, cast(con("0"), e->s_mode), e->s_mode);

     printf("bt t%d B%d\n", temp->s_place, ++numblabels);
     printf("br B%d\n", ++numblabels);
     return (node(0, 0,
		  node(numblabels-1, 0, (struct sem_rec *) NULL,
		       (struct sem_rec *) NULL),
		  node(numblabels, 0, (struct sem_rec *) NULL,
		       (struct sem_rec *) NULL)));
   }
   else
     fprintf(stderr, "Argument sem_rec is NULL\n");
}

/*
 * ccnot - logical not
 */
struct sem_rec *ccnot(struct sem_rec *e)
{
  // fprintf(stderr, "sem: ccnot not implemented\n");
  struct sem_rec* temp = gen("!", e, cast(con("0"), e->s_mode), e->s_mode);
  printf("bt t%d B%d\n", temp->s_place, nextLabelbNum());
  printf("br B%d\n", nextLabelbNum());

  return (node(0, 0, node(numblabels-1, 0, NULL, NULL), node(numblabels, 0, NULL, NULL)));
}

/*
 * ccor - logical or
 */
struct sem_rec *ccor(struct sem_rec *e1, int m, struct sem_rec *e2)
{
   //fprintf(stderr, "sem: ccor not implemented\n");

   struct sem_rec* temp = gen("||", e1, e2, e1->s_mode);
   printf("bt t%d B%d\n", temp->s_place, nextLabelbNum());
   printf("br B%d\n", nextLabelbNum());

   backpatch(e1->back.s_true, m);
   temp->back.s_true = e2->back.s_true;
   temp->s_false = merge(e1->s_false, e2->s_false);

    //fprintf(stderr, "sem: ccand not implemented\n");
    return node(0, 0, node(numblabels-1, 0, NULL, NULL), node(numblabels, 0, NULL, NULL));

}

/*
 * con - constant reference in an expression
 */
struct sem_rec *con(char *x)
{
  struct id_entry *p;

  if((p = lookup(x, 0)) == NULL) {
    p = install(x, 0);
    p->i_type = T_INT;
    p->i_scope = GLOBAL;
    p->i_defined = 1;
  }

  /* print the quad t%d = const */
  printf("t%d := %s\n", nexttemp(), x);

  /* construct a new node corresponding to this constant generation
     into a temporary. This will allow this temporary to be referenced
     in an expression later*/
  return node(currtemp(), p->i_type, NULL, NULL);
}

/*
 * dobreak - break statement
 */
void dobreak()
{
   //fprintf(stderr, "sem: dobreak not implemented\n");
   n();
}

/*
 * docontinue - continue statement
 */
void docontinue()
{
   //fprintf(stderr, "sem: docontinue not implemented\n");
   n();
}

/*
 * dodo - do statement
 */
void dodo(int m1, int m2, struct sem_rec *e, int m3)
{
   //fprintf(stderr, "sem: dodo not implemented\n");
   backpatch(e->back.s_true, m1);
   backpatch(e->s_false, m2);
}

/*
 * dofor - for statement
 */
void dofor(int m1, struct sem_rec *e2, int m2, struct sem_rec *n1,
           int m3, struct sem_rec *n2, int m4)
{
   //fprintf(stderr, "sem: dofor not implemented\n");
   backpatch(e2->back.s_true, m3);
   backpatch(e2->s_false, m4);
   backpatch(n1, m1);
   backpatch(n2, m2);
}

/*
 * dogoto - goto statement
 */
void dogoto(char *id)
{
   //fprintf(stderr, "sem: dogoto not implemented\n");
   n();
}

/*
 * doif - one-arm if statement
 */
void doif(struct sem_rec *e, int m1, int m2)
{
   //fprintf(stderr, "sem: doif not implemented\n");
   backpatch(e->back.s_true, m1);
   backpatch(e->s_false, m2);
}

/*
 * doifelse - if then else statement
 */
void doifelse(struct sem_rec *e, int m1, struct sem_rec *n,
                         int m2, int m3)
{
   //fprintf(stderr, "sem: doifelse not implemented\n");
   backpatch(e->back.s_true, m1);
   backpatch(n, m2);
   backpatch(e->s_false, m3);
}

/*
 * doret - return statement
 */
void doret(struct sem_rec *e)
{
   //fprintf(stderr, "sem: doret not implemented\n");
   printf("ret%c t%d\n", typeAsChar(e->s_mode), currtemp());
}

/*
 * dowhile - while statement
 */
void dowhile(int m1, struct sem_rec *e, int m2, struct sem_rec *n,
             int m3)
{
   //fprintf(stderr, "sem: dowhile not implemented\n");
   backpatch(e->back.s_true, m2);
   backpatch(e->s_false, m3);
   backpatch(n, m1);
}

/*
 * endloopscope - end the scope for a loop
 */
void endloopscope(int m)
{
   //fprintf(stderr, "sem: endloopscope not implemented\n");
   leaveblock();
}

/*
 * exprs - form a list of expressions
 */
struct sem_rec *exprs(struct sem_rec *l, struct sem_rec *e)
{
   //fprintf(stderr, "sem: exprs not implemented\n");
   struct sem_rec* temp = merge(l, e);
   return temp;
   //return ((struct sem_rec *) NULL);
}

/*
 * fhead - beginning of function body
 */
void fhead(struct id_entry *p)
{
   //fprintf(stderr, "sem: fhead not implemented\n");
   for(int i=0; i<formalnum; i++)
   {
     if(formaltypes[i] == 'i')
      printf("formal 4\n");
     else
      printf("formal 8\n");
   }
   for(int i=0; i<localnum; i++)
   {
     if(localtypes[i] == 'i')
      printf("localloc 4\n");
     else
      printf("localloc 8\n");
   }
}

/*
 * fname - function declaration
 */
struct id_entry *fname(int t, char *id)
{

  printf("func %s\n", id);
  enterblock();
  struct id_entry* temp = dclr(id, t, 4);
  //fprintf(stderr, "sem: fname not implemented\n");
  return temp;
}

/*
 * ftail - end of function body
 */
void ftail()
{
   //fprintf(stderr, "sem: ftail not implemented\n");
   printf("fend\n");
   leaveblock();
}

/*
 * id - variable reference
 */
struct sem_rec *id(char *x)
{
   struct id_entry *p;

   if ((p = lookup(x, 0)) == NULL) {
      yyerror("undeclared identifier");
      p = install(x, -1);
      p->i_type = T_INT;
      p->i_scope = LOCAL;
      p->i_defined = 1;
   }
   if (p->i_scope == GLOBAL)
      printf("t%d := global %s\n", nexttemp(), x);
   else if (p->i_scope == LOCAL)
      printf("t%d := local %d\n", nexttemp(), p->i_offset);
   else if (p->i_scope == PARAM) {
      printf("t%d := param %d\n", nexttemp(), p->i_offset);
      if (p->i_type & T_ARRAY) {
         (void) nexttemp();
         printf("t%d := @i t%d\n", currtemp(), currtemp()-1);
      }
   }

   /* add the T_ADDR to know that it is still an address */
   return (node(currtemp(), p->i_type|T_ADDR, (struct sem_rec *) NULL,
                (struct sem_rec *) NULL));
}

/*
 * index - subscript
 */
struct sem_rec *tom_index(struct sem_rec *x, struct sem_rec *i)
{
  return (gen("[]", x, cast(i, T_INT), x->s_mode&~(T_ARRAY)));
}

/*
 * labeldcl - process a label declaration
 */
void labeldcl(char *id)
{
   //fprintf(stderr, "sem: labeldcl not implemented\n");
   backpatch(n(), m());
}

/*
 * m - generate label and return next temporary number
 */
int m()
{
   //fprintf(stderr, "sem: m not implemented\n");
   printf("label L%d\n", nextLabelNum());
   return numlabels;
}

/*
 * n - generate goto and return backpatch pointer
 */
struct sem_rec *n()
{
   //fprintf(stderr, "sem: n not implemented\n");
   printf("br B%d\n", nextLabelbNum());

   return node(numblabels, 0, NULL, NULL);
}

/*
 * op1 - unary operators
 */
struct sem_rec *op1(char *op, struct sem_rec *y)
{
  if (*op == '@' && !(y->s_mode&T_ARRAY)){
    /* get rid of T_ADDR if it is being dereferenced so can handle
       T_DOUBLE types correctly */
    y->s_mode &= ~T_ADDR;
    return (gen(op, (struct sem_rec *) NULL, y, y->s_mode));
  }
  else if ((y->s_mode == T_DOUBLE) && (*op == '~'))
  {
    y = cast(y, T_INT);
    return gen(op, 0, y, T_INT);
  }

  return (gen(op, NULL, y, y->s_mode));

}

/*
 * op2 - arithmetic operators
 */
struct sem_rec *op2(char *op, struct sem_rec *x, struct sem_rec *y)
{
   //fprintf(stderr, "sem: op2 not implemented\n");
   struct sem_rec* temp = y;
   if((x->s_mode & T_DOUBLE) && !(y->s_mode & T_DOUBLE))
   {
     printf("t%d := cvf t%d\n", nexttemp(), y->s_place);
     temp = node(currtemp(), T_DOUBLE, NULL, NULL);
   }
   else if((x->s_mode & T_INT) && !(y->s_mode & T_INT))
   {
     printf("t%d := cvi t%d\n", nexttemp(), y->s_place);
     temp = node(currtemp(), T_INT, NULL, NULL);
   }
   return gen(op, x, temp, temp->s_mode);
}

/*
 * opb - bitwise operators
 */
struct sem_rec *opb(char *op, struct sem_rec *x, struct sem_rec *y)
{
   //fprintf(stderr, "sem: opb not implemented\n");
   //return ((struct sem_rec *) NULL);
   return gen(op, x, y, y->s_mode);
}

/*
 * rel - relational operators
 */
struct sem_rec *rel(char *op, struct sem_rec *x, struct sem_rec *y)
{
   //fprintf(stderr, "sem: rel not implemented\n");

   struct sem_rec* temp = y;
   if((x->s_mode & T_DOUBLE) && !(y->s_mode & T_DOUBLE))
   {
     printf("t%d := cvf t%d\n", nexttemp(), y->s_place);
     temp = node(currtemp(), T_DOUBLE, NULL, NULL);
   }
   else if((x->s_mode & T_INT) && !(y->s_mode & T_INT))
   {
     printf("t%d := cvi t%d\n", nexttemp(), y->s_place);
     temp = node(currtemp(), T_INT, NULL, NULL);
   }

   struct sem_rec* temp2 = gen(op, x, temp, x->s_mode);
   printf("bt t%d B%d\n", temp2->s_place, nextLabelbNum());
   printf("br B%d\n", nextLabelbNum());

   temp2->back.s_true = node(numblabels-1, temp2->s_mode, NULL, NULL);
   temp2->s_false = node(numblabels, temp2->s_mode, NULL, NULL);

   return temp2;
}

/*
 * set - assignment operators
 */
struct sem_rec *set(char *op, struct sem_rec *x, struct sem_rec *y)
{
  /* assign the value of expression y to the lval x */
  struct sem_rec *p, *cast_y;

  if(x==NULL || y==NULL){
    fprintf(stderr, "sem: set not implemented\n");
    return((struct sem_rec *) NULL);
  }
  if(*op != '\0')
  {
    struct sem_rec* temp = op1("@", x);
    y = gen(op, temp, y, x->s_mode);
  }

  /* if for type consistency of x and y */
  cast_y = y;
  if((x->s_mode & T_DOUBLE) && !(y->s_mode & T_DOUBLE)){

    /*cast y to a double*/
    printf("t%d = cvf t%d\n", nexttemp(), y->s_place);
    cast_y = node(currtemp(), T_DOUBLE, NULL, NULL);
  }
  else if((x->s_mode & T_INT) && !(y->s_mode & T_INT)){

    /*convert y to integer*/
    printf("t%d = cvi t%d\n", nexttemp(), y->s_place);
    cast_y = node(currtemp(), T_INT, NULL, NULL);
  }

  /*output quad for assignment*/
  if(x->s_mode & T_DOUBLE)
    printf("t%d := t%d =f t%d\n", nexttemp(),
	   x->s_place, cast_y->s_place);
  else
    printf("t%d := t%d =i t%d\n", nexttemp(),
	   x->s_place, cast_y->s_place);

  /*create a new node to allow just created temporary to be referenced later */
  return(node(currtemp(), (x->s_mode&~(T_ARRAY)), NULL, NULL));
}

/*
 * startloopscope - start the scope for a loop
 */
void startloopscope()
{
   //fprintf(stderr, "sem: startloopscope not implemented\n");
   enterblock();
}

/*
 * string - generate code for a string
 */
struct sem_rec *string(char *s)
{
   //fprintf(stderr, "sem: string not implemented\n");
   printf("t%d := %s\n", nexttemp(), s);
   struct sem_rec* temp = node(currtemp(), T_STR, 0, 0);
   return temp;
}



/************* Helper Functions **************/

/*
 * cast - force conversion of datum y to type t
 */
struct sem_rec *cast(struct sem_rec *y, int t)
{
   if (t == T_DOUBLE && y->s_mode != T_DOUBLE)
      return (gen("cv", (struct sem_rec *) NULL, y, t));
   else if (t != T_DOUBLE && y->s_mode == T_DOUBLE)
      return (gen("cv", (struct sem_rec *) NULL, y, t));
   else
      return (y);
}

/*
 * gen - generate and return quadruple "z := x op y"
 */
struct sem_rec *gen(char *op, struct sem_rec *x, struct sem_rec *y, int t)
{
   if (strncmp(op, "arg", 3) != 0 && strncmp(op, "ret", 3) != 0)
      printf("t%d := ", nexttemp());
   if (x != NULL && *op != 'f')
      printf("t%d ", x->s_place);
   printf("%s", op);
   if (t & T_DOUBLE && (!(t & T_ADDR) || (*op == '[' && *(op+1) == ']'))) {
      printf("f");
      if (*op == '%')
         yyerror("cannot %% floating-point values");
   }
   else
      printf("i");
   if (x != NULL && *op == 'f')
      printf(" t%d %d", x->s_place, y->s_place);
   else if (y != NULL)
      printf(" t%d", y->s_place);
   printf("\n");
   return (node(currtemp(), t, (struct sem_rec *) NULL,
           (struct sem_rec *) NULL));
}
