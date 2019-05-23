/*	Definition section */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "share.h"	/* header file generated by bison */
extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
extern char buf2[256];  // Get current code line from lex
int yerror;
/*int now_scope = 0; 
int float_flag = 0;
typedef struct symbol{
    char name[20];
    char kind[20];
    char type[10];
    int scope;
    char attribute[20];
    int func_def;
}symbol;
symbol global_table[30];
symbol symbol_table[30];
int symbolno = 0;
int globalno = 0;

Symbol table function - you can add new function if needed. 
in lookup_symbol(symbol *t,char *name,int n);
int check_funcdef(symbol *t,char *name,int n);
symbol create_symbol(char *name,char *kind,char *type,int scope,char *attribute);
void insert_symbol(symbol *t,symbol s,int i);
void dump_symbol(symbol *t,int scope,int n);*/
%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */

%union {
    int i_val;
    double f_val;
    char* string;
 //  symbol symbol;
}

/* Token without return */
%token PRINT 
%token IF ELSE FOR
%token SEMICOLON
%token ADD SUB MUL DIV MOD INC DEC MT LT MTE LTE EQ NE LSB RSB COMMA
%token QUOTA PRINT WHILE ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT LB RB LCB RCB TRUE FALSE RET CONT BREAK COMMENT

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string> BOOL INT STRING FLOAT VOID STR_CONST ID

/* Nonterminal with return, which need to sepcify type */
%type <string> type argument func_id id
%type <f_val> fstat stat fdeclaration declaration compound_stat print_func 
%type <f_val> function_decl function_def return
%type <f_val> if_stat while_stat direct_function_call function_call parameter pass 
%type <f_val> expression_stat4 expr_asgn
%type <f_val> expression_stat3 expression_stat2 expression_stat1 factor
%type <f_val> initializer

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program stat{ 
//dump_symbol(global_table,0,globalno); 
    }
/*    | program stat NEWLINE {  }*/
    | {
       // dump_symbol(global_table,0,globalno);
        globalno = 0;
    }
;

fprogram
    : fprogram fstat
    |
;


stat
    : declaration {
    	$$ = $1;
    }
    | compound_stat {
    	$$ = $1;
    }
    | expr_asgn{
    	$$ = $1;
    }
    | expression_stat4 semicolon{
    	$$ = $1;
    }
    | function_decl {
    	$$ = $1;
    } 
    | function_def {
       // dump = 1;
//        now_scope++;
    	$$ = $1;
    }
    | { $$ = 0.1; } 
;


fstat
    : fdeclaration{
	    $$ = $1;
    }
    | compound_stat {
	    $$ = $1;
    }
    | expr_asgn{
	    $$ = $1;
    }
    | expression_stat4 semicolon{
	    $$ = $1;
    }
    | direct_function_call{
    	$$ = $1;
    }
    | print_func  {
    	$$ = $1;
    }
    | { $$ = 0.1; } 
;

semicolon
    : SEMICOLON
    |
;

direct_function_call
    : func_id LB parameter RB SEMICOLON{
        if(lookup_symbol(global_table,$1,globalno,0,0)==0){
            error = 1;
            sprintf(errorm,"Undeclared function %s",$1);
        }
    }    
;


function_call
    : func_id LB parameter RB {
        if(lookup_symbol(global_table,$1,globalno,0,0)==0){
            error = 1;
            sprintf(errorm,"Undeclared function %s",$1);
        }
    }
;

func_id
    : ID {
        if(lookup_symbol(global_table,$1,globalno,0,0)==0){
            error = 1;
            sprintf(errorm,"Undeclared function %s",$1);
        }
        $$ = $1; 
    }
;

parameter
    : pass {
        $$ = 0.1;
    }
    | parameter COMMA pass{
    
        $$ = 0.1;
    }
    | expression_stat4{
        $$ = 0.1;
    }
;

pass
    : id {
        $$ = 0.1;
    }
    | initializer {
        $$ = 0.1;
    } 
;   

expr_asgn
    : id ASGN expression_stat4 SEMICOLON{
	    $$ = 0.1;
    }
   | id ADDASGN factor SEMICOLON{
	    $$ = 0.1;
    }
    | id SUBASGN factor SEMICOLON {
	    $$ = 0.1;
    }
    | id MULASGN factor SEMICOLON {
	    $$ = 0.1;
    }
    | id DIVASGN factor SEMICOLON{
	    $$ = 0.1;
    }
    | id MODASGN factor SEMICOLONE {
  	    $$ = 0.1;
    }
;

function_decl
    : type ID LB argument RB SEMICOLON{
        if(lookup_symbol(global_table,$2,globalno,0,1)==0){
            symbol s = create_symbol($2,"function",$1,0,$4);
            s.func_def = 0;
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            error = 1;
            sprintf(errorm,"Redeclared function %s",$2);
        }
        memset(symbol_table,0,sizeof symbol_table);
        symbolno = 0;
        $$ = 0.1;
    }
;

function_def
    : type ID LB argument RB LCB fprogram RCB {
        if(lookup_symbol(global_table,$2,globalno,0,1)==0){
           symbol s = create_symbol($2,"function",$1,0,$4);
            s.func_def = 1;
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            if(check_funcdef(global_table,$2,globalno)==1){
                error = 1;
                sprintf(errorm,"Redeclared function %s",$2);
            }
       }
        $$ = 0.1;
    }
    | type ID LB argument RB LCB fprogram return RCB{
        if(lookup_symbol(global_table,$2,globalno,0,1)==0){
           symbol s = create_symbol($2,"function",$1,0,$4);
            s.func_def = 1;
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            if(check_funcdef(global_table,$2,globalno)==1){
                error = 1;
                sprintf(errorm,"Redeclared function %s",$2);
            }
       }
        $$ = 0.1;
    }
;

return
    : RET SEMICOLON {
	    $$ = 0.1;
    }
    | RET TRUE SEMICOLON {
	    $$ = 0.1;
    }
    | RET FALSE SEMICOLON {
	    $$ = 0.1;
    }
    | RET I_CONST SEMICOLON {
	    $$ = 0.1;
    }
    | RET F_CONST SEMICOLON {
	    $$ = 0.1;
    }
    | RET expression_stat4 SEMICOLON{
	    $$ = 0.1;
    }
    | RET STR_CONST SEMICOLON{
	    $$ = 0.1;
    }
;

argument
    : type ID {
        symbol s = create_symbol($2,"parameter",$1,1,"");
        insert_symbol(symbol_table,s,symbolno);
        symbolno++;
        $$ = $1;
    }
    | argument COMMA type ID {
        symbol s = create_symbol($4,"parameter",$3,1,"");
        insert_symbol(symbol_table,s,symbolno);
        symbolno++;
        $$ = strcat($1,", ");
        $$ = strcat($$,$3);
    }
    | {
        $$ = ""; 
    }
;

declaration
    : type ID ASGN initializer SEMICOLON {
        if(lookup_symbol(global_table,$2,globalno,0,1)==0){
            symbol s = create_symbol($2,"variable",$1,0,"");
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            error = 1;
            sprintf(errorm,"Redeclared variable %s",$2);
        }
     	$$ = 0.1;
    }
    | type ID SEMICOLON{
        if(lookup_symbol(global_table,$2,globalno,0,1)==0){
            symbol s = create_symbol($2,"variable",$1,0,"");
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            error = 1;
            sprintf(errorm,"Redeclared variable %s",$2);
        }
    	$$ = 0.1;
    }
    | type ID ASGN expression_stat4 SEMICOLON{
        if(lookup_symbol(global_table,$2,globalno,0,1)==0){
            symbol s = create_symbol($2,"variable",$1,0,"");
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            error = 1;
            sprintf(errorm,"Redeclared variable %s",$2);
        }
      	$$ = 0.1;
    }
;

fdeclaration
    : type ID SEMICOLON{
        if(lookup_symbol(symbol_table,$2,symbolno,now_scope,1)==0){
            symbol s = create_symbol($2,"variable",$1,now_scope,"");
            insert_symbol(symbol_table,s,symbolno);
            symbolno++; 
        }
        else {
            error = 1;
            sprintf(errorm,"Redeclared variable %s",$2);
        }
    	$$ = 0.1;
    }
    | type ID ASGN initializer SEMICOLON{
        if(lookup_symbol(symbol_table,$2,symbolno,now_scope,1)==0){
            symbol s = create_symbol($2,"variable",$1,now_scope,"");
            insert_symbol(symbol_table,s,symbolno);
            symbolno++; 
        }
        else {
            error = 1;
            sprintf(errorm,"Redeclared variable %s",$2);
         }
      	$$ = 0.1;
    }
   | type ID ASGN expression_stat4 SEMICOLON{
        if(lookup_symbol(symbol_table,$2,symbolno,now_scope,1)==0){
            symbol s = create_symbol($2,"variable",$1,now_scope,"");
            insert_symbol(symbol_table,s,symbolno);
            symbolno++; 
        }
        else {
            error = 1;
            sprintf(errorm,"Redeclared variable %s",$2);
        }
      	$$ = 0.1;
    }
;

compound_stat
    : if_stat {

       // dump = 1;
	    $$ = 0.1;
    }
    | while_stat {
       // dump = 1;
	    $$ = 0.1;
    }
;

if_stat
    : IF LB expression_stat4 RB LCB fprogram RCB {
	    $$ = 0.1;
    }
    | IF LB expression_stat4 RB LCB fprogram RCB else_stat {
	    $$ = 0.1;
    }
    | IF LB expression_stat4 RB LCB fprogram RCB elseif_stat {
	    $$ = 0.1;
    }
;

else_stat
    : ELSE LCB fprogram RCB {
       // dump = 1;
    }
;

elseif_stat
    : ELSE IF LB expression_stat4 RB LCB fprogram RCB else_stat {
        //dump = 1;
    }
    | ELSE IF LB expression_stat4 RB LCB fprogram RCB elseif_stat {
       // dump = 1;
    }
;

while_stat
    : WHILE LB expression_stat4 RB LCB fprogram RCB {
	$$ = 0.1;
    }
;

expression_stat4
    : expression_stat4 EQ expression_stat3 {
	    if($1 == $3) $$ = 1;
	    else $$ = 0;
    }
    | expression_stat4 MTE expression_stat3 {
	    if($1 >= $3) $$ = 1;
    	else $$ = 0;
    }
    | expression_stat4 LTE expression_stat3 {
    	if($1 <= $3) $$ = 1;
    	else $$ = 0;
    }
    | expression_stat4 NE expression_stat3 {
    	if($1 != $3) $$ = 1;
    	else $$ = 0;
    }
    | expression_stat4 MT expression_stat3 {
    	if($1 > $3) $$ = 1;
    	else $$ = 0;
    }
    | expression_stat4 LT expression_stat3 {
    	if($1 < $3) $$ = 1;
    	else $$ = 0;
    }
    | expression_stat3 {
	    $$ = 0.1;
    }
;

expression_stat3
    : expression_stat3 ADD expression_stat2 { $$ = $1 + $3; }
    | expression_stat3 SUB expression_stat2 { $$ = $1 - $3; }
    | expression_stat2 {
    	$$ = 0.1; 
    }
;

expression_stat2
    : expression_stat2 MUL expression_stat1 { $$ = $1 * $3; }
    | expression_stat2 DIV expression_stat1 { $$ = $1 / $3; }
    | expression_stat2 MOD expression_stat1 { 
//	if(float_flag == 1){
//	  printf("error");
 	      $$ = 0.1;
//	}
//	else	
//	  $$ = (int)$1 % (int)$3; 
    }
    | expression_stat1 { 
    	$$ = 0.1; 
    }
;

expression_stat1
    : expression_stat1 INC { $$ = $$ + 1; }
    | expression_stat1 DEC { $$ = $$ - 1; }
    | factor { 
	    $$ = 0.1; 
    }
;

factor
    : LB expression_stat4 RB { $$ = $2; }
    | ID {         
        if(lookup_symbol(symbol_table,$1,symbolno,now_scope,0)==0){
            error = 1;
            sprintf(errorm,"Undeclared variable %s",$1);
        }       
        $$ = 0.3; 
    };
    | I_CONST { $$ = 0.1; }
    | F_CONST { $$ = 0.2; }
    | function_call { $$ = 0.1; }
;

id
    :ID {         
        if(lookup_symbol(symbol_table,$1,symbolno,now_scope,0)==0){
            error = 1;
            sprintf(errorm,"Undeclared variable %s",$1);
        }
        $$ = $1;
    }   
;

print_func
    : PRINT LB ID RB SEMICOLON { 
        if(lookup_symbol(symbol_table,$3,symbolno,now_scope,0)==0){
            error = 1;
            sprintf(errorm,"Undeclared variable %s",$3);
        }       
        $$ = 0.1; 
    }
    | PRINT LB STR_CONST RB SEMICOLON { 
        $$ = 0.1;
    }
;

initializer
    : I_CONST { $$ = 0.1; }
    | F_CONST { 
	    $$ = 0.1; 
	    float_flag = 1;
    }
    | STR_CONST { $$ = 0.1; }
;

/* actions can be taken when meet the token or rule */
type
    : INT { $$ = $1; }
    | FLOAT { $$ = $1; }
    | BOOL  { $$ = $1; }
    | STRING { $$ = $1; }
    | VOID { $$ = $1; }
;

%%

/* C code section */
int main(int argc, char** argv)
{
    error = 0;
    yerror = 0;
    dump = 0;
    yylineno = 0;
    now_scope = 0;
    symbolno = 0;
    globalno = 0; 
    yyparse();
    if(yerror==0) { 
        dump_symbol(global_table,0,globalno);
        printf("\nTotal lines: %d \n",yylineno);
    }
    return 0;
}

void serror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

void yyerror(char *s)
{
    yerror = 1;
    yylineno++;
    printf("%d: %s\n",yylineno,buf);
    if(error==1)
        serror(errorm);
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

int lookup_symbol(symbol *t,char *name,int n,int scope,int d){
    int i;
    if(d == 0){  //undeclare
        for(i=0; i<n; i++){	
	        if(strcmp(t[i].name,name)==0)
	            return 1;
        }   
    }
    else{    //redeclar
        for(i=0; i<n; i++){	
	        if(strcmp(t[i].name,name)==0)
                if(t[i].scope==scope)
	                return 1;
        }
    }
    return 0;
}

int check_funcdef(symbol *t,char *name,int n){
    int i;
    for(i=0; i<n; i++){	
	    if(strcmp(t[i].name,name)==0)
            if(t[i].func_def==1)
	            return 1;
    }
    return 0;
}

symbol create_symbol(char *name,char *kind,char *type,int scope,char *attribute){
    symbol s;
    strcpy(s.name,name);
    strcpy(s.kind,kind);
    strcpy(s.type,type);
    s.scope = scope;
    strcpy(s.attribute,attribute);
    return s;
}
void insert_symbol(symbol* t,symbol s,int i){
    strcpy(t[i].name,s.name);
    strcpy(t[i].kind,s.kind);
    strcpy(t[i].type,s.type);
    t[i].scope = s.scope;
    strcpy(t[i].attribute,s.attribute);
}

void dump_symbol(symbol* t,int scope,int n) {
    int yes = 0; 
    int i,j=0;
    for(i=0; i<n; i++){
        if(t[i].scope==scope)
            yes = 1;
    }
    if(yes == 1){
        printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
        for(i=0; i<n; i++){
            if(t[i].scope == scope){
                if(strcmp(t[i].attribute,"")==0)
    	            printf("%-10d%-10s%-12s%-10s%-10d\n",j,t[i].name,t[i].kind,t[i].type,t[i].scope);
                else
    	            printf("%-10d%-10s%-12s%-10s%-10d%s\n",j,t[i].name,t[i].kind,t[i].type,t[i].scope,t[i].attribute);
                j++;
                memset(&t[i],0,sizeof(t[i]));
            }
        }
        printf("\n");
    }
}
