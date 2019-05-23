#ifndef SHARE_H
#define SHARE_H
int now_scope ; 
int float_flag ;
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
char errorm[30];
int symbolno ;
int globalno ;
int error;
int dump;
/* Symbol table function - you can add new function if needed. */
void serror(char *s);
int lookup_symbol(symbol *t,char *name,int n,int scope,int d);
int check_funcdef(symbol *t,char *name,int n);
symbol create_symbol(char *name,char *kind,char *type,int scope,char *attribute);
void insert_symbol(symbol *t,symbol s,int i);
void dump_symbol(symbol *t,int scope,int n);
#endif
