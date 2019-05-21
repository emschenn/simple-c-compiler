/*	Definition section */

%{
extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
extern char buf2[256];  // Get current code line from lex
int now_scope = 0; 
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

/* Symbol table function - you can add new function if needed. */
int lookup_symbol(symbol *t,char *name,int n);
int check_funcdef(symbol *t,char *name,int n);
symbol create_symbol(char *name,char *kind,char *type,int scope,char *attribute);
void insert_symbol(symbol *t,symbol s,int i);
void dump_symbol(symbol *t,int scope,int n);
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
%token NEWLINE
%token ADD SUB MUL DIV MOD INC DEC MT LT MTE LTE EQ NE LSB RSB COMMA
%token QUOTA PRINT WHILE ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT LB RB LCB RCB TRUE FALSE RET CONT BREAK COMMENT

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string> BOOL INT STRING FLOAT VOID STR_CONST ID

/* Nonterminal with return, which need to sepcify type */
%type <string> type argument
%type <f_val> fstat stat fdeclaration declaration compound_stat print_func 
%type <f_val> function_decl function_def return
%type <f_val> if_stat while_stat function_call parameter pass 
%type <f_val> expression_stat4 expr_asgn
%type <f_val> expression_stat3 expression_stat2 expression_stat1 factor
%type <f_val> initializer

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program stat
    | program stat NEWLINE
    | {
       // dump_symbol(global_table,0,globalno);
        globalno = 0;
    }
;

fprogram
    : fprogram fstat
    | fprogram fstat NEWLINE
    |
;


new_line
    : new_line NEWLINE
    |
;

stat
    : declaration {
    	$$ = $1;
    }
    | compound_stat {
    	$$ = $1;
    }
    | expr_asgn SEMICOLON{
    	$$ = $1;
    }
    | expression_stat4 semicolon{
    	$$ = $1;
    }
    | function_decl {
    	$$ = $1;
    } 
    | function_def {
        now_scope++;
        dump_symbol(symbol_table,1,symbolno);
        now_scope--;
        symbolno = 0;
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
    | expr_asgn SEMICOLON{
	    $$ = $1;
    }
    | expression_stat4 semicolon{
	    $$ = $1;
    }
    | function_call {
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

function_call
    : ID LB parameter RB SEMICOLON NEWLINE {
        if(lookup_symbol(global_table,$1,globalno)==0){
            char t[50];
            sprintf(t,"Undeclared function %s",$1);
            yyerror(t);
        }
    }
;

parameter
    : pass {
        $$ = 0.1;
    }
    | parameter COMMA pass{
    
        $$ = 0.1;
    }
    |
;

pass
    : ID {
        $$ = 0.1;
    }
    | initializer {
        $$ = 0.1;
    } 
;   

expr_asgn
    : ID ASGN expression_stat4 {
	    $$ = 0.1;
    }
    | ID ADDASGN factor {
	    $$ = 0.1;
    }
    | ID SUBASGN factor {
	    $$ = 0.1;
    }
    | ID MULASGN factor {
	    $$ = 0.1;
    }
    | ID DIVASGN factor {
	    $$ = 0.1;
    }
    | ID MODASGN factor {
  	    $$ = 0.1;
    }
;

function_decl
    : type ID LB argument RB SEMICOLON NEWLINE{
        if(lookup_symbol(global_table,$2,globalno)==0){
            symbol s = create_symbol($2,"function",$1,0,"");
            s.func_def = 0;
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            char t[50];
            sprintf(t,"Redeclared function %s",$2);
            yyerror(t);
        }
        $$ = 0.1;
    }
;

function_def
    : type ID LB argument RB LCB fprogram RCB {
        if(lookup_symbol(global_table,$2,globalno)==0){
           symbol s = create_symbol($2,"function",$1,0,$4);
            s.func_def = 1;
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            if(check_funcdef(global_table,$2,globalno)==1){
                char t[50];
                sprintf(t,"Redeclared function %s",$2);
                yyerror(t);
            }
        }
        $$ = 0.1;
    }
    | type ID LB argument RB LCB NEWLINE fprogram return NEWLINE RCB NEWLINE{
        if(lookup_symbol(global_table,$2,globalno)==0){
           symbol s = create_symbol($2,"function",$1,0,$4);
            s.func_def = 1;
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            if(check_funcdef(global_table,$2,globalno)==1){
                char t[50];
                sprintf(t,"Redeclared function %s",$2);
                yyerror(t);
            }
        }
        $$ = 0.1;
    }
/*    | type ID LB argument RB new_line LCB new_line fprogram return RCB {
        printf("1\n");
        if(lookup_symbol(global_table,$2,globalno)==0){
            symbol s = create_symbol($2,"function",$1,0,$4);
            s.func_def = 1;
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            if(check_funcdef(global_table,$2,globalno)==1){
                char t[50];
                sprintf(t,"Redeclared function %s",$2);
                yyerror(t);
            }
        }
        $$ = 0.1;
    }*/
;

return
    : RET SEMICOLON{
	    $$ = 0.1;
    }
    | RET TRUE SEMICOLON {
	    $$ = 0.1;
    }
    | RET FALSE SEMICOLON{
	    $$ = 0.1;
    }
    | RET I_CONST SEMICOLON{
	    $$ = 0.1;
    }
    | RET F_CONST SEMICOLON{
	    $$ = 0.1;
    }
    | RET STR_CONST SEMICOLON{
	    $$ = 0.1;
    }
;

nargument 
    : type ID {}
    | nargument COMMA type ID {}
    |
;

fdecl_bottom
    : RB SEMICOLON NEWLINE 
;

argument
    : type ID {
        symbol s = create_symbol($2,"parameter",$1,0,"");
        insert_symbol(symbol_table,s,symbolno);
        symbolno++;
        $$ = $1;
    }
    | argument COMMA type ID {
        symbol s = create_symbol($4,"parameter",$3,0,"");
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
    : type ID ASGN initializer SEMICOLON NEWLINE {
        if(lookup_symbol(global_table,$2,globalno)==0){
            symbol s = create_symbol($2,"variable",$1,0,"");
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            char t[50];
            sprintf(t,"Redeclared variable %s",$2);
            yyerror(t);
        }
     	$$ = 0.1;
    }
    | type ID SEMICOLON NEWLINE{
        if(lookup_symbol(global_table,$2,globalno)==0){
            symbol s = create_symbol($2,"variable",$1,0,"");
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            char t[50];
            sprintf(t,"Redeclared variable %s",$2);
            yyerror(t);
        }
    	$$ = 0.1;
    }
    | type ID ASGN expression_stat4 SEMICOLON NEWLINE{
        if(lookup_symbol(global_table,$2,globalno)==0){
            symbol s = create_symbol($2,"variable",$1,0,"");
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            char t[50];
            sprintf(t,"Redeclared variable %s",$2);
            yyerror(t);
        }
      	$$ = 0.1;
    }
;

fdeclaration
    : type ID SEMICOLON NEWLINE{
        if(lookup_symbol(symbol_table,$2,symbolno)==0){
            symbol s = create_symbol($2,"variable",$1,0,"");
            insert_symbol(symbol_table,s,symbolno);
            symbolno++; 
        }
        else {
            char t[50];
            sprintf(t,"Redeclared variable %s",$2);
            yyerror(t);
        }
    	$$ = 0.1;
    }
    | type ID ASGN initializer SEMICOLON NEWLINE{
        if(lookup_symbol(symbol_table,$2,symbolno)==0){
            symbol s = create_symbol($2,"variable",$1,0,"");
            insert_symbol(symbol_table,s,symbolno);
            symbolno++; 
        }
        else {
            char t[50];
            sprintf(t,"Redeclared variable %s",$2);
            yyerror(t);
        }
      	$$ = 0.1;
    }
   | type ID ASGN expression_stat4 SEMICOLON NEWLINE{
        if(lookup_symbol(symbol_table,$2,symbolno)==0){
            symbol s = create_symbol($2,"variable",$1,0,"");
            insert_symbol(symbol_table,s,symbolno);
            symbolno++; 
        }
        else {
            char t[50];
            sprintf(t,"Redeclared variable %s",$2);
            yyerror(t);
        }
      	$$ = 0.1;
    }
;

compound_stat
    : if_stat {
	$$ = 0.1;
    }
    | while_stat {
	$$ = 0.1;
    }
;

if_stat
    : IF LB expression_stat4 RB LCB fprogram RCB {
	$$ = 0.1;
    }
    | IF LB expression_stat4 RB LCB fprogram RCB ELSE if_stat {
	$$ = 0.1;
    }
    | IF LB expression_stat4 RB LCB fprogram RCB ELSE new_line LCB new_line fprogram RCB {
	$$ = 0.1;
    }
;

while_stat
    : WHILE LB expression_stat4 RB LCB fprogram RCB {
	$$ = 0.1;
    }

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
    | ID { $$ = 0.3; }
    | I_CONST { $$ = 0.1; }
    | F_CONST { $$ = 0.2; }
;

print_func
    : PRINT LB ID RB SEMICOLON NEWLINE { 
        if(lookup_symbol(symbol_table,$3,symbolno)==0){
            char t[50];
            sprintf(t,"Undeclared variable %s",$3);
            yyerror(t);
        }       
        $$ = 0.1; 
    }
    | PRINT LB STR_CONST RB SEMICOLON NEWLINE { 
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
    yylineno = 0;
    
    yyparse();
    
    dump_symbol(global_table,0,globalno);
    printf("\nTotal lines: %d \n",yylineno);

    return 0;
}

void yyerror(char *s)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno, buf2);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
}

int lookup_symbol(symbol *t,char *name,int n){
    int i;
    for(i=0; i<n; i++){	
	    if(strcmp(t[i].name,name)==0)
	        return 1;
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
    printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n",
           "Index", "Name", "Kind", "Type", "Scope", "Attribute");
    int i;
    for(i=0; i<n; i++){
        if(strcmp(t[i].attribute,"")==0)
    	    printf("%-10d%-10s%-12s%-10s%-10d\n",i,t[i].name,t[i].kind,t[i].type,scope);
        else
    	    printf("%-10d%-10s%-12s%-10s%-10d%s\n",i,t[i].name,t[i].kind,t[i].type,scope,t[i].attribute);
    /*    t[i].name = ""; 
        t[i].kind = ""; 
        t[i].type = "";
        t[i].scope = -1;
        t[i].attribute = "";
    */
    }
    memset(t,0,sizeof(t));
    printf("\n");
}
