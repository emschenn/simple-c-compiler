/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 4 "compiler_hw2.y"
extern int yylineno;
extern int yylex();
extern char* yytext;   /* Get current token from lex*/
extern char buf[256];  /* Get current code line from lex*/
extern char buf2[256];  /* Get current code line from lex*/
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
#line 36 "compiler_hw2.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int i_val;
    double f_val;
    char* string;
 /*  symbol symbol;*/
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 62 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define PRINT 257
#define IF 258
#define ELSE 259
#define FOR 260
#define SEMICOLON 261
#define NEWLINE 262
#define ADD 263
#define SUB 264
#define MUL 265
#define DIV 266
#define MOD 267
#define INC 268
#define DEC 269
#define MT 270
#define LT 271
#define MTE 272
#define LTE 273
#define EQ 274
#define NE 275
#define LSB 276
#define RSB 277
#define COMMA 278
#define QUOTA 279
#define WHILE 280
#define ASGN 281
#define ADDASGN 282
#define SUBASGN 283
#define MULASGN 284
#define DIVASGN 285
#define MODASGN 286
#define AND 287
#define OR 288
#define NOT 289
#define LB 290
#define RB 291
#define LCB 292
#define RCB 293
#define TRUE 294
#define FALSE 295
#define RET 296
#define CONT 297
#define BREAK 298
#define COMMENT 299
#define I_CONST 300
#define F_CONST 301
#define BOOL 302
#define INT 303
#define STRING 304
#define FLOAT 305
#define VOID 306
#define STR_CONST 307
#define ID 308
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,   24,   24,   24,   25,   25,    4,    4,
    4,    4,    4,    4,    4,    3,    3,    3,    3,    3,
    3,    3,   26,   26,   14,   15,   15,   15,   16,   16,
   18,   18,   18,   18,   18,   18,    9,   10,   10,   11,
   11,   11,   11,   11,   11,   27,   27,   27,   28,    2,
    2,    2,    6,    6,    6,    5,    5,    5,    7,    7,
   12,   12,   12,   13,   17,   17,   17,   17,   17,   17,
   17,   19,   19,   19,   20,   20,   20,   20,   21,   21,
   21,   22,   22,   22,   22,    8,    8,   23,   23,   23,
    1,    1,    1,    1,    1,
};
static const YYINT yylen[] = {                            2,
    2,    3,    0,    2,    3,    0,    2,    0,    1,    1,
    2,    2,    1,    1,    0,    1,    1,    2,    2,    1,
    1,    0,    1,    0,    6,    1,    3,    0,    1,    1,
    3,    3,    3,    3,    3,    3,    7,    8,   12,    2,
    3,    3,    3,    3,    3,    2,    4,    0,    3,    2,
    4,    0,    6,    4,    6,    4,    6,    6,    1,    1,
    7,    9,   13,    7,    3,    3,    3,    3,    3,    3,
    1,    3,    3,    1,    3,    3,    3,    1,    2,    2,
    1,    3,    1,    1,    1,    6,    6,    1,    1,    1,
    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         3,
    0,    0,    0,    0,   84,   85,   93,   91,   94,   92,
   95,    0,    0,    0,    9,   10,   13,   14,   59,   60,
    0,    0,    0,    0,    0,   81,    0,    0,   83,    0,
    0,    0,    0,    0,    0,    0,    0,    2,   23,    0,
    0,    0,    0,    0,    0,   12,   11,    0,    0,    0,
    0,    0,   79,   80,    0,    0,   82,    0,   32,   33,
   34,   35,   36,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   54,
   84,   85,   90,    0,    0,    0,    0,    6,    6,    0,
    0,   50,    0,    0,    0,    0,   55,   53,    0,    0,
    0,    0,    0,    0,    0,    0,   16,   17,   21,   20,
    0,    0,   64,   51,   37,    6,    0,    0,    0,    0,
    0,    5,   19,   18,    0,   38,    0,    0,   62,    0,
   88,   89,   29,    0,   26,   30,    0,    0,    0,    0,
    0,    0,    7,    8,    0,    0,   56,    0,    0,   40,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   27,
    0,    0,    0,   41,   42,   43,   44,   45,    0,   87,
   86,    0,   25,   58,   57,   39,   63,
};
static const YYINT yydgoto[] = {                          1,
  105,   87,  106,   14,  107,   15,  108,  109,   17,   18,
  140,   19,   20,  110,  134,  135,  111,  112,   23,   24,
   25,   26,  136,   95,  130,   46,    0,    0,
};
static const YYINT yysindex[] = {                         0,
  -68, -274, -270,  -13,    0,    0,    0,    0,    0,    0,
    0,  -40, -285, -237,    0,    0,    0,    0,    0,    0,
  227, -230, -204, -158, -203,    0,  -13,  -13,    0, -262,
  -13,  -13,  -13,  -13,  -13,  -13, -162,    0,    0,  -13,
  -13,  -13,  -13,  -13,  -13,    0,    0,  -13,  -13,  -13,
  -13,  -13,    0,    0, -107,  -21,    0,  116,    0,    0,
    0,    0,    0, -170, -169, -111, -204, -204, -204, -204,
 -204, -204, -158, -158, -203, -203, -203, -236, -199,    0,
    0,    0,    0,  476, -159, -191, -259,    0,    0, -137,
 -133,    0, -111, -256, -131, -104,    0,    0, -174, -127,
 -115, -140, -108,   55, -156, -106,    0,    0,    0,    0,
  227, -103,    0,    0,    0,    0,  -77, -245,  -98, -286,
 -244,    0,    0,    0,  798,    0, -136, -130,    0, -238,
    0,    0,    0, -217,    0,    0,  -84, -169, -206,  -80,
  -82,  -78,    0,    0, -286,  -76,    0,  530,  -74,    0,
  -73,  -56,  -47,  -46,  -44,  -75,  -43,  -42,  -41,    0,
  -32,  -23,  -15,    0,    0,    0,    0,    0,  -14,    0,
    0,  817,    0,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    7,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  206,    0,  425,    0,    0,    0,    0,    0,    0,
  781,    0,  416,  260,    1,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   -6,    0,    0,
    0,    0,    0,    0,    0, -207,  482,  536,  588,  640,
  692,  745,  312,  364,   53,  105,  157,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   -5,   -5,    0,    0,    0,    0,
  834,    0,  764, -223,    0, -160,    0,    0,    0,    0,
 -190,    0,    0,    0,    0,    0,   -5,    0, -234, -187,
    0,    0,    0,    0,   -5,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  834,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   -5,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    3,    0,    0,    0,    0,    0,  255,    0,    0,    0,
    0,  142,    0,    0,    0,  133,   -1,  278,  398,   38,
   72,  175,  -63,  -83,  136,  171,    0,    0,
};
#define YYTABLESIZE 1142
static const YYINT yytable[] = {                         21,
   78,   85,   30,   13,  100,   96,   15,   40,   41,   42,
   43,   44,   45,  131,  132,   27,  137,  117,   93,   28,
   83,  133,   37,  143,   38,   55,   56,    8,   57,   58,
   47,   94,  125,   83,   83,  101,  138,   83,   83,   83,
   83,   83,   83,   83,   83,   83,   83,   83,   83,   83,
   83,   83,   75,  144,  150,   88,   83,    8,   48,   49,
  145,  127,  128,   84,   53,   54,   24,   24,   86,   83,
   52,   24,   83,  146,  149,  172,   83,   83,   83,   83,
   83,   83,   83,   52,   83,   73,   74,  151,  152,   24,
   28,   80,   89,  153,  154,   99,    4,    4,   64,   24,
  155,   91,   24,   28,   76,   24,   50,   51,   52,   24,
   24,   24,   24,   24,   24,   24,   92,   24,   65,    4,
    4,   75,   76,   77,   97,  102,    2,   66,   98,    4,
   81,   82,    4,  114,  115,    4,  148,   83,   29,    4,
    4,    4,    4,    4,    4,    4,  116,    4,    3,  118,
  119,  121,  102,    2,  141,  122,   77,  124,    4,    2,
  142,  103,   40,   41,   42,   43,   44,   45,    5,    6,
    7,    8,    9,   10,   11,    3,  104,  147,  157,  102,
    2,  156,  158,   78,  161,    4,  163,  164,  113,    2,
    7,    8,    9,   10,   11,    5,    6,    7,    8,    9,
   10,   11,    3,  104,  165,   83,   59,   60,   61,   62,
   63,    3,    4,  166,  167,  126,  168,  169,  170,  171,
  143,    4,    5,    6,    7,    8,    9,   10,   11,  173,
  104,    5,    6,    7,    8,    9,   10,   11,  174,   12,
   31,   32,   33,   34,   35,   36,  175,  176,   40,   41,
   42,   43,   44,   45,   31,   16,   22,   78,   78,   74,
  129,   78,   78,   78,   78,   78,   78,   78,   15,   79,
   78,   78,   78,   78,   78,   78,    4,  160,   22,  159,
   78,  123,    0,    0,    0,    0,    5,    6,    0,    0,
   78,   78,    0,   78,   29,    0,   78,    0,    0,    0,
   78,   78,   78,   78,   78,   78,   78,    0,   78,   75,
   75,   72,    0,   75,   75,   75,   75,   75,   75,   75,
    0,    0,   75,   75,   75,   75,   75,   75,    0,    0,
    0,    0,   75,    0,    0,   31,   32,   33,   34,   35,
   36,    0,   75,   75,  120,   75,    0,    0,   75,    0,
    0,    0,   75,   75,   75,   75,   75,   75,   75,    0,
   75,   76,   76,   73,    0,   76,   76,   76,   76,   76,
   76,   76,    0,    0,   76,   76,   76,   76,   76,   76,
    0,    0,    0,    0,   76,   40,   41,   42,   43,   44,
   45,    0,    0,    0,   76,   76,    0,   76,    0,    0,
   76,    0,    0,    0,   76,   76,   76,   76,   76,   76,
   76,    0,   76,   77,   77,   71,    0,   77,   77,   77,
   77,   77,   77,   77,    1,    0,   77,   77,   77,   77,
   77,   77,    0,    0,    0,    0,   77,   67,   68,   69,
   70,   71,   72,    0,    0,    0,   77,   77,    0,   77,
    0,    0,   77,    0,    0,    0,   77,   77,   77,   77,
   77,   77,   77,   83,   77,    0,   83,   83,   83,   83,
   83,   83,   83,   83,   83,   83,   83,   83,   83,   83,
   83,   69,    0,    0,    0,   83,    0,   39,    0,    0,
    0,    0,    0,    0,    0,   83,   40,   41,   42,   43,
   44,   45,    0,    0,    0,   83,   83,   83,   83,   83,
   83,   83,    0,   83,    0,    0,   74,   74,    0,    0,
   74,   74,   74,   74,    0,    0,    0,    0,    0,   74,
   74,   74,   74,   74,   74,   70,    0,    0,    0,   74,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   74,
   74,    0,   74,    0,    0,   74,    0,    0,    0,   74,
   74,   74,   74,   74,   74,   74,    0,   74,   72,   72,
    0,    0,   72,   72,   72,   72,    0,    0,    0,    0,
    0,   72,   72,   72,   72,   72,   72,   66,    0,    0,
    0,   72,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   72,   72,    0,   72,    0,    0,   72,    0,    0,
    0,   72,   72,   72,   72,   72,   72,   72,    0,   72,
   73,   73,    0,    0,   73,   73,   73,   73,    0,    0,
    0,    0,    0,   73,   73,   73,   73,   73,   73,   67,
    0,    0,    0,   73,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   73,   73,    0,   73,    0,    0,   73,
    0,    0,    0,   73,   73,   73,   73,   73,   73,   73,
    0,   73,   71,   71,    0,    0,   71,   71,    0,    0,
    0,    0,    1,    0,    0,   71,   71,   71,   71,   71,
   71,   65,    0,    0,    0,   71,    0,    0,    0,    0,
    0,    0,    0,    0,    1,   71,   71,    0,   71,    0,
    0,   71,    0,    0,    1,   71,   71,   71,   71,   71,
   71,   71,    0,   71,    1,    1,    1,    1,    1,    1,
    1,    0,    1,    0,    0,    0,   90,    0,   69,   69,
    0,    0,   69,   69,   68,   40,   41,   42,   43,   44,
   45,   69,   69,   69,   69,   69,   69,    0,    0,    0,
    0,   69,    0,   61,    0,    0,    0,    0,    0,    0,
    0,   69,   69,    0,   69,    0,    0,   69,    0,    0,
   24,   69,   69,   69,   69,   69,   69,   69,    0,   69,
  162,    0,   70,   70,    0,    0,   70,   70,    0,   40,
   41,   42,   43,   44,   45,   70,   70,   70,   70,   70,
   70,    0,    0,    0,    0,   70,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   70,   70,    0,   70,    0,
    0,   70,    0,    0,    0,   70,   70,   70,   70,   70,
   70,   70,    0,   70,   66,   66,    0,    0,   66,   66,
    0,    0,    0,    0,    0,    0,    0,   66,   66,   66,
   66,   66,   66,    0,    0,    0,    0,   66,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   66,   66,    0,
   66,    0,    0,   66,    0,    0,    0,   66,   66,   66,
   66,   66,   66,   66,    0,   66,   67,   67,    0,    0,
   67,   67,    0,    0,    0,    0,    0,    0,    0,   67,
   67,   67,   67,   67,   67,    0,    0,    0,    0,   67,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   67,
   67,    0,   67,    0,    0,   67,    0,    0,    0,   67,
   67,   67,   67,   67,   67,   67,    0,   67,   65,   65,
    0,    0,   65,   65,    0,    0,    0,    0,    0,    0,
    0,   65,   65,   65,   65,   65,   65,    0,    0,    0,
    0,   65,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   65,   65,    0,   65,    0,    0,   65,    0,    0,
    0,   65,   65,   65,   65,   65,   65,   65,    0,   65,
    0,   68,   68,    0,    0,   68,   68,    0,    0,    0,
    0,    0,    0,    0,   68,   68,   68,   68,   68,   68,
   61,   61,    0,    0,   68,   61,    0,    0,    0,    0,
    0,    0,    0,    0,   68,   68,    0,   68,   24,    0,
   68,    0,   24,   61,   68,   68,   68,   68,   68,   68,
   68,    0,   68,   61,  102,    2,   61,    0,    0,   61,
   24,    0,    0,   61,   61,   61,   61,   61,   61,   61,
   24,   61,    0,  102,    2,    0,    0,    3,    0,    0,
   24,   24,   24,   24,   24,   24,   24,    4,   24,    0,
    6,    6,    0,  139,    0,    0,    3,    5,    6,    7,
    8,    9,   10,   11,    0,  104,    4,    0,    0,  177,
    0,    0,    0,    6,    0,    0,    5,    6,    7,    8,
    9,   10,   11,    6,  104,    0,    6,    0,    0,    0,
    0,    0,    0,    6,    6,    6,    6,    6,    6,    6,
    0,    6,
};
static const YYINT yycheck[] = {                          1,
    0,   65,    4,    1,  261,   89,    0,  270,  271,  272,
  273,  274,  275,  300,  301,  290,  261,  101,  278,  290,
  307,  308,  308,  262,  262,   27,   28,  262,  291,   31,
  261,  291,  116,  257,  258,  292,  281,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,  275,    0,  292,  261,  292,  280,  292,  263,  264,
  278,  307,  308,   65,  268,  269,  257,  258,   66,  293,
  278,  262,  296,  291,  138,  159,  300,  301,  302,  303,
  304,  305,  306,  291,  308,   48,   49,  294,  295,  280,
  278,  262,  292,  300,  301,   93,  257,  258,  261,  290,
  307,  261,  293,  291,    0,  296,  265,  266,  267,  300,
  301,  302,  303,  304,  305,  306,  308,  308,  281,  280,
  290,   50,   51,   52,  262,  257,  258,  290,  262,  290,
  300,  301,  293,  308,  262,  296,  138,  307,  308,  300,
  301,  302,  303,  304,  305,  306,  262,  308,  280,  290,
  259,  308,  257,  258,  291,  262,    0,  261,  290,  258,
  291,  293,  270,  271,  272,  273,  274,  275,  300,  301,
  302,  303,  304,  305,  306,  280,  308,  262,  261,  257,
  258,  262,  261,  291,  261,  290,  261,  261,  293,  258,
  302,  303,  304,  305,  306,  300,  301,  302,  303,  304,
  305,  306,  280,  308,  261,    0,   32,   33,   34,   35,
   36,  280,  290,  261,  261,  293,  261,  293,  262,  262,
  262,  290,  300,  301,  302,  303,  304,  305,  306,  262,
  308,  300,  301,  302,  303,  304,  305,  306,  262,  308,
  281,  282,  283,  284,  285,  286,  262,  262,  270,  271,
  272,  273,  274,  275,  261,    1,  262,  257,  258,    0,
  119,  261,  262,  263,  264,  265,  266,  267,  262,  291,
  270,  271,  272,  273,  274,  275,  290,  145,    1,  144,
  280,  111,   -1,   -1,   -1,   -1,  300,  301,   -1,   -1,
  290,  291,   -1,  293,  308,   -1,  296,   -1,   -1,   -1,
  300,  301,  302,  303,  304,  305,  306,   -1,  308,  257,
  258,    0,   -1,  261,  262,  263,  264,  265,  266,  267,
   -1,   -1,  270,  271,  272,  273,  274,  275,   -1,   -1,
   -1,   -1,  280,   -1,   -1,  281,  282,  283,  284,  285,
  286,   -1,  290,  291,  290,  293,   -1,   -1,  296,   -1,
   -1,   -1,  300,  301,  302,  303,  304,  305,  306,   -1,
  308,  257,  258,    0,   -1,  261,  262,  263,  264,  265,
  266,  267,   -1,   -1,  270,  271,  272,  273,  274,  275,
   -1,   -1,   -1,   -1,  280,  270,  271,  272,  273,  274,
  275,   -1,   -1,   -1,  290,  291,   -1,  293,   -1,   -1,
  296,   -1,   -1,   -1,  300,  301,  302,  303,  304,  305,
  306,   -1,  308,  257,  258,    0,   -1,  261,  262,  263,
  264,  265,  266,  267,    0,   -1,  270,  271,  272,  273,
  274,  275,   -1,   -1,   -1,   -1,  280,   40,   41,   42,
   43,   44,   45,   -1,   -1,   -1,  290,  291,   -1,  293,
   -1,   -1,  296,   -1,   -1,   -1,  300,  301,  302,  303,
  304,  305,  306,  258,  308,   -1,  261,  262,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  272,  273,  274,
  275,    0,   -1,   -1,   -1,  280,   -1,  261,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  290,  270,  271,  272,  273,
  274,  275,   -1,   -1,   -1,  300,  301,  302,  303,  304,
  305,  306,   -1,  308,   -1,   -1,  257,  258,   -1,   -1,
  261,  262,  263,  264,   -1,   -1,   -1,   -1,   -1,  270,
  271,  272,  273,  274,  275,    0,   -1,   -1,   -1,  280,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  290,
  291,   -1,  293,   -1,   -1,  296,   -1,   -1,   -1,  300,
  301,  302,  303,  304,  305,  306,   -1,  308,  257,  258,
   -1,   -1,  261,  262,  263,  264,   -1,   -1,   -1,   -1,
   -1,  270,  271,  272,  273,  274,  275,    0,   -1,   -1,
   -1,  280,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  290,  291,   -1,  293,   -1,   -1,  296,   -1,   -1,
   -1,  300,  301,  302,  303,  304,  305,  306,   -1,  308,
  257,  258,   -1,   -1,  261,  262,  263,  264,   -1,   -1,
   -1,   -1,   -1,  270,  271,  272,  273,  274,  275,    0,
   -1,   -1,   -1,  280,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  290,  291,   -1,  293,   -1,   -1,  296,
   -1,   -1,   -1,  300,  301,  302,  303,  304,  305,  306,
   -1,  308,  257,  258,   -1,   -1,  261,  262,   -1,   -1,
   -1,   -1,  258,   -1,   -1,  270,  271,  272,  273,  274,
  275,    0,   -1,   -1,   -1,  280,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  280,  290,  291,   -1,  293,   -1,
   -1,  296,   -1,   -1,  290,  300,  301,  302,  303,  304,
  305,  306,   -1,  308,  300,  301,  302,  303,  304,  305,
  306,   -1,  308,   -1,   -1,   -1,  261,   -1,  257,  258,
   -1,   -1,  261,  262,    0,  270,  271,  272,  273,  274,
  275,  270,  271,  272,  273,  274,  275,   -1,   -1,   -1,
   -1,  280,   -1,    0,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  290,  291,   -1,  293,   -1,   -1,  296,   -1,   -1,
    0,  300,  301,  302,  303,  304,  305,  306,   -1,  308,
  261,   -1,  257,  258,   -1,   -1,  261,  262,   -1,  270,
  271,  272,  273,  274,  275,  270,  271,  272,  273,  274,
  275,   -1,   -1,   -1,   -1,  280,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  290,  291,   -1,  293,   -1,
   -1,  296,   -1,   -1,   -1,  300,  301,  302,  303,  304,
  305,  306,   -1,  308,  257,  258,   -1,   -1,  261,  262,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  270,  271,  272,
  273,  274,  275,   -1,   -1,   -1,   -1,  280,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  290,  291,   -1,
  293,   -1,   -1,  296,   -1,   -1,   -1,  300,  301,  302,
  303,  304,  305,  306,   -1,  308,  257,  258,   -1,   -1,
  261,  262,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  270,
  271,  272,  273,  274,  275,   -1,   -1,   -1,   -1,  280,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  290,
  291,   -1,  293,   -1,   -1,  296,   -1,   -1,   -1,  300,
  301,  302,  303,  304,  305,  306,   -1,  308,  257,  258,
   -1,   -1,  261,  262,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  270,  271,  272,  273,  274,  275,   -1,   -1,   -1,
   -1,  280,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  290,  291,   -1,  293,   -1,   -1,  296,   -1,   -1,
   -1,  300,  301,  302,  303,  304,  305,  306,   -1,  308,
   -1,  257,  258,   -1,   -1,  261,  262,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  270,  271,  272,  273,  274,  275,
  257,  258,   -1,   -1,  280,  262,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  290,  291,   -1,  293,  258,   -1,
  296,   -1,  262,  280,  300,  301,  302,  303,  304,  305,
  306,   -1,  308,  290,  257,  258,  293,   -1,   -1,  296,
  280,   -1,   -1,  300,  301,  302,  303,  304,  305,  306,
  290,  308,   -1,  257,  258,   -1,   -1,  280,   -1,   -1,
  300,  301,  302,  303,  304,  305,  306,  290,  308,   -1,
  257,  258,   -1,  296,   -1,   -1,  280,  300,  301,  302,
  303,  304,  305,  306,   -1,  308,  290,   -1,   -1,  293,
   -1,   -1,   -1,  280,   -1,   -1,  300,  301,  302,  303,
  304,  305,  306,  290,  308,   -1,  293,   -1,   -1,   -1,
   -1,   -1,   -1,  300,  301,  302,  303,  304,  305,  306,
   -1,  308,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 308
#define YYUNDFTOKEN 339
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"PRINT","IF","ELSE","FOR",
"SEMICOLON","NEWLINE","ADD","SUB","MUL","DIV","MOD","INC","DEC","MT","LT","MTE",
"LTE","EQ","NE","LSB","RSB","COMMA","QUOTA","WHILE","ASGN","ADDASGN","SUBASGN",
"MULASGN","DIVASGN","MODASGN","AND","OR","NOT","LB","RB","LCB","RCB","TRUE",
"FALSE","RET","CONT","BREAK","COMMENT","I_CONST","F_CONST","BOOL","INT",
"STRING","FLOAT","VOID","STR_CONST","ID",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : program stat",
"program : program stat NEWLINE",
"program :",
"fprogram : fprogram fstat",
"fprogram : fprogram fstat NEWLINE",
"fprogram :",
"new_line : new_line NEWLINE",
"new_line :",
"stat : declaration",
"stat : compound_stat",
"stat : expr_asgn SEMICOLON",
"stat : expression_stat4 semicolon",
"stat : function_decl",
"stat : function_def",
"stat :",
"fstat : fdeclaration",
"fstat : compound_stat",
"fstat : expr_asgn SEMICOLON",
"fstat : expression_stat4 semicolon",
"fstat : function_call",
"fstat : print_func",
"fstat :",
"semicolon : SEMICOLON",
"semicolon :",
"function_call : ID LB parameter RB SEMICOLON NEWLINE",
"parameter : pass",
"parameter : parameter COMMA pass",
"parameter :",
"pass : ID",
"pass : initializer",
"expr_asgn : ID ASGN expression_stat4",
"expr_asgn : ID ADDASGN factor",
"expr_asgn : ID SUBASGN factor",
"expr_asgn : ID MULASGN factor",
"expr_asgn : ID DIVASGN factor",
"expr_asgn : ID MODASGN factor",
"function_decl : type ID LB argument RB SEMICOLON NEWLINE",
"function_def : type ID LB argument RB LCB fprogram RCB",
"function_def : type ID LB argument RB LCB NEWLINE fprogram return NEWLINE RCB NEWLINE",
"return : RET SEMICOLON",
"return : RET TRUE SEMICOLON",
"return : RET FALSE SEMICOLON",
"return : RET I_CONST SEMICOLON",
"return : RET F_CONST SEMICOLON",
"return : RET STR_CONST SEMICOLON",
"nargument : type ID",
"nargument : nargument COMMA type ID",
"nargument :",
"fdecl_bottom : RB SEMICOLON NEWLINE",
"argument : type ID",
"argument : argument COMMA type ID",
"argument :",
"declaration : type ID ASGN initializer SEMICOLON NEWLINE",
"declaration : type ID SEMICOLON NEWLINE",
"declaration : type ID ASGN expression_stat4 SEMICOLON NEWLINE",
"fdeclaration : type ID SEMICOLON NEWLINE",
"fdeclaration : type ID ASGN initializer SEMICOLON NEWLINE",
"fdeclaration : type ID ASGN expression_stat4 SEMICOLON NEWLINE",
"compound_stat : if_stat",
"compound_stat : while_stat",
"if_stat : IF LB expression_stat4 RB LCB fprogram RCB",
"if_stat : IF LB expression_stat4 RB LCB fprogram RCB ELSE if_stat",
"if_stat : IF LB expression_stat4 RB LCB fprogram RCB ELSE new_line LCB new_line fprogram RCB",
"while_stat : WHILE LB expression_stat4 RB LCB fprogram RCB",
"expression_stat4 : expression_stat4 EQ expression_stat3",
"expression_stat4 : expression_stat4 MTE expression_stat3",
"expression_stat4 : expression_stat4 LTE expression_stat3",
"expression_stat4 : expression_stat4 NE expression_stat3",
"expression_stat4 : expression_stat4 MT expression_stat3",
"expression_stat4 : expression_stat4 LT expression_stat3",
"expression_stat4 : expression_stat3",
"expression_stat3 : expression_stat3 ADD expression_stat2",
"expression_stat3 : expression_stat3 SUB expression_stat2",
"expression_stat3 : expression_stat2",
"expression_stat2 : expression_stat2 MUL expression_stat1",
"expression_stat2 : expression_stat2 DIV expression_stat1",
"expression_stat2 : expression_stat2 MOD expression_stat1",
"expression_stat2 : expression_stat1",
"expression_stat1 : expression_stat1 INC",
"expression_stat1 : expression_stat1 DEC",
"expression_stat1 : factor",
"factor : LB expression_stat4 RB",
"factor : ID",
"factor : I_CONST",
"factor : F_CONST",
"print_func : PRINT LB ID RB SEMICOLON NEWLINE",
"print_func : PRINT LB STR_CONST RB SEMICOLON NEWLINE",
"initializer : I_CONST",
"initializer : F_CONST",
"initializer : STR_CONST",
"type : INT",
"type : FLOAT",
"type : BOOL",
"type : STRING",
"type : VOID",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 529 "compiler_hw2.y"

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
#line 714 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 3:
#line 75 "compiler_hw2.y"
	{
       /* dump_symbol(global_table,0,globalno);*/
        globalno = 0;
    }
break;
case 9:
#line 94 "compiler_hw2.y"
	{
    	yyval.f_val = yystack.l_mark[0].f_val;
    }
break;
case 10:
#line 97 "compiler_hw2.y"
	{
    	yyval.f_val = yystack.l_mark[0].f_val;
    }
break;
case 11:
#line 100 "compiler_hw2.y"
	{
    	yyval.f_val = yystack.l_mark[-1].f_val;
    }
break;
case 12:
#line 103 "compiler_hw2.y"
	{
    	yyval.f_val = yystack.l_mark[-1].f_val;
    }
break;
case 13:
#line 106 "compiler_hw2.y"
	{
    	yyval.f_val = yystack.l_mark[0].f_val;
    }
break;
case 14:
#line 109 "compiler_hw2.y"
	{
        now_scope++;
        dump_symbol(symbol_table,1,symbolno);
        now_scope--;
        symbolno = 0;
    	yyval.f_val = yystack.l_mark[0].f_val;
    }
break;
case 15:
#line 116 "compiler_hw2.y"
	{ yyval.f_val = 0.1; }
break;
case 16:
#line 121 "compiler_hw2.y"
	{
	    yyval.f_val = yystack.l_mark[0].f_val;
    }
break;
case 17:
#line 124 "compiler_hw2.y"
	{
	    yyval.f_val = yystack.l_mark[0].f_val;
    }
break;
case 18:
#line 127 "compiler_hw2.y"
	{
	    yyval.f_val = yystack.l_mark[-1].f_val;
    }
break;
case 19:
#line 130 "compiler_hw2.y"
	{
	    yyval.f_val = yystack.l_mark[-1].f_val;
    }
break;
case 20:
#line 133 "compiler_hw2.y"
	{
    	yyval.f_val = yystack.l_mark[0].f_val;
    }
break;
case 21:
#line 136 "compiler_hw2.y"
	{
    	yyval.f_val = yystack.l_mark[0].f_val;
    }
break;
case 22:
#line 139 "compiler_hw2.y"
	{ yyval.f_val = 0.1; }
break;
case 25:
#line 148 "compiler_hw2.y"
	{
        if(lookup_symbol(global_table,yystack.l_mark[-5].string,globalno)==0){
            char t[50];
            sprintf(t,"Undeclared function %s",yystack.l_mark[-5].string);
            yyerror(t);
        }
    }
break;
case 26:
#line 158 "compiler_hw2.y"
	{
        yyval.f_val = 0.1;
    }
break;
case 27:
#line 161 "compiler_hw2.y"
	{
    
        yyval.f_val = 0.1;
    }
break;
case 29:
#line 169 "compiler_hw2.y"
	{
        yyval.f_val = 0.1;
    }
break;
case 30:
#line 172 "compiler_hw2.y"
	{
        yyval.f_val = 0.1;
    }
break;
case 31:
#line 178 "compiler_hw2.y"
	{
	    yyval.f_val = 0.1;
    }
break;
case 32:
#line 181 "compiler_hw2.y"
	{
	    yyval.f_val = 0.1;
    }
break;
case 33:
#line 184 "compiler_hw2.y"
	{
	    yyval.f_val = 0.1;
    }
break;
case 34:
#line 187 "compiler_hw2.y"
	{
	    yyval.f_val = 0.1;
    }
break;
case 35:
#line 190 "compiler_hw2.y"
	{
	    yyval.f_val = 0.1;
    }
break;
case 36:
#line 193 "compiler_hw2.y"
	{
  	    yyval.f_val = 0.1;
    }
break;
case 37:
#line 199 "compiler_hw2.y"
	{
        if(lookup_symbol(global_table,yystack.l_mark[-5].string,globalno)==0){
            symbol s = create_symbol(yystack.l_mark[-5].string,"function",yystack.l_mark[-6].string,0,"");
            s.func_def = 0;
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            char t[50];
            sprintf(t,"Redeclared function %s",yystack.l_mark[-5].string);
            yyerror(t);
        }
        yyval.f_val = 0.1;
    }
break;
case 38:
#line 216 "compiler_hw2.y"
	{
        if(lookup_symbol(global_table,yystack.l_mark[-6].string,globalno)==0){
           symbol s = create_symbol(yystack.l_mark[-6].string,"function",yystack.l_mark[-7].string,0,yystack.l_mark[-4].string);
            s.func_def = 1;
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            if(check_funcdef(global_table,yystack.l_mark[-6].string,globalno)==1){
                char t[50];
                sprintf(t,"Redeclared function %s",yystack.l_mark[-6].string);
                yyerror(t);
            }
        }
        yyval.f_val = 0.1;
    }
break;
case 39:
#line 232 "compiler_hw2.y"
	{
        if(lookup_symbol(global_table,yystack.l_mark[-10].string,globalno)==0){
           symbol s = create_symbol(yystack.l_mark[-10].string,"function",yystack.l_mark[-11].string,0,yystack.l_mark[-8].string);
            s.func_def = 1;
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            if(check_funcdef(global_table,yystack.l_mark[-10].string,globalno)==1){
                char t[50];
                sprintf(t,"Redeclared function %s",yystack.l_mark[-10].string);
                yyerror(t);
            }
        }
        yyval.f_val = 0.1;
    }
break;
case 40:
#line 268 "compiler_hw2.y"
	{
	    yyval.f_val = 0.1;
    }
break;
case 41:
#line 271 "compiler_hw2.y"
	{
	    yyval.f_val = 0.1;
    }
break;
case 42:
#line 274 "compiler_hw2.y"
	{
	    yyval.f_val = 0.1;
    }
break;
case 43:
#line 277 "compiler_hw2.y"
	{
	    yyval.f_val = 0.1;
    }
break;
case 44:
#line 280 "compiler_hw2.y"
	{
	    yyval.f_val = 0.1;
    }
break;
case 45:
#line 283 "compiler_hw2.y"
	{
	    yyval.f_val = 0.1;
    }
break;
case 46:
#line 289 "compiler_hw2.y"
	{}
break;
case 47:
#line 290 "compiler_hw2.y"
	{}
break;
case 50:
#line 299 "compiler_hw2.y"
	{
        symbol s = create_symbol(yystack.l_mark[0].string,"parameter",yystack.l_mark[-1].string,0,"");
        insert_symbol(symbol_table,s,symbolno);
        symbolno++;
        yyval.string = yystack.l_mark[-1].string;
    }
break;
case 51:
#line 305 "compiler_hw2.y"
	{
        symbol s = create_symbol(yystack.l_mark[0].string,"parameter",yystack.l_mark[-1].string,0,"");
        insert_symbol(symbol_table,s,symbolno);
        symbolno++;
        yyval.string = strcat(yystack.l_mark[-3].string,", ");
        yyval.string = strcat(yyval.string,yystack.l_mark[-1].string);
    }
break;
case 52:
#line 312 "compiler_hw2.y"
	{
        yyval.string = ""; 
    }
break;
case 53:
#line 318 "compiler_hw2.y"
	{
        if(lookup_symbol(global_table,yystack.l_mark[-4].string,globalno)==0){
            symbol s = create_symbol(yystack.l_mark[-4].string,"variable",yystack.l_mark[-5].string,0,"");
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            char t[50];
            sprintf(t,"Redeclared variable %s",yystack.l_mark[-4].string);
            yyerror(t);
        }
     	yyval.f_val = 0.1;
    }
break;
case 54:
#line 331 "compiler_hw2.y"
	{
        if(lookup_symbol(global_table,yystack.l_mark[-2].string,globalno)==0){
            symbol s = create_symbol(yystack.l_mark[-2].string,"variable",yystack.l_mark[-3].string,0,"");
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            char t[50];
            sprintf(t,"Redeclared variable %s",yystack.l_mark[-2].string);
            yyerror(t);
        }
    	yyval.f_val = 0.1;
    }
break;
case 55:
#line 344 "compiler_hw2.y"
	{
        if(lookup_symbol(global_table,yystack.l_mark[-4].string,globalno)==0){
            symbol s = create_symbol(yystack.l_mark[-4].string,"variable",yystack.l_mark[-5].string,0,"");
            insert_symbol(global_table,s,globalno);
            globalno++; 
        }
        else {
            char t[50];
            sprintf(t,"Redeclared variable %s",yystack.l_mark[-4].string);
            yyerror(t);
        }
      	yyval.f_val = 0.1;
    }
break;
case 56:
#line 360 "compiler_hw2.y"
	{
        if(lookup_symbol(symbol_table,yystack.l_mark[-2].string,symbolno)==0){
            symbol s = create_symbol(yystack.l_mark[-2].string,"variable",yystack.l_mark[-3].string,0,"");
            insert_symbol(symbol_table,s,symbolno);
            symbolno++; 
        }
        else {
            char t[50];
            sprintf(t,"Redeclared variable %s",yystack.l_mark[-2].string);
            yyerror(t);
        }
    	yyval.f_val = 0.1;
    }
break;
case 57:
#line 373 "compiler_hw2.y"
	{
        if(lookup_symbol(symbol_table,yystack.l_mark[-4].string,symbolno)==0){
            symbol s = create_symbol(yystack.l_mark[-4].string,"variable",yystack.l_mark[-5].string,0,"");
            insert_symbol(symbol_table,s,symbolno);
            symbolno++; 
        }
        else {
            char t[50];
            sprintf(t,"Redeclared variable %s",yystack.l_mark[-4].string);
            yyerror(t);
        }
      	yyval.f_val = 0.1;
    }
break;
case 58:
#line 386 "compiler_hw2.y"
	{
        if(lookup_symbol(symbol_table,yystack.l_mark[-4].string,symbolno)==0){
            symbol s = create_symbol(yystack.l_mark[-4].string,"variable",yystack.l_mark[-5].string,0,"");
            insert_symbol(symbol_table,s,symbolno);
            symbolno++; 
        }
        else {
            char t[50];
            sprintf(t,"Redeclared variable %s",yystack.l_mark[-4].string);
            yyerror(t);
        }
      	yyval.f_val = 0.1;
    }
break;
case 59:
#line 402 "compiler_hw2.y"
	{
	yyval.f_val = 0.1;
    }
break;
case 60:
#line 405 "compiler_hw2.y"
	{
	yyval.f_val = 0.1;
    }
break;
case 61:
#line 411 "compiler_hw2.y"
	{
	yyval.f_val = 0.1;
    }
break;
case 62:
#line 414 "compiler_hw2.y"
	{
	yyval.f_val = 0.1;
    }
break;
case 63:
#line 417 "compiler_hw2.y"
	{
	yyval.f_val = 0.1;
    }
break;
case 64:
#line 423 "compiler_hw2.y"
	{
	yyval.f_val = 0.1;
    }
break;
case 65:
#line 428 "compiler_hw2.y"
	{
	    if(yystack.l_mark[-2].f_val == yystack.l_mark[0].f_val) yyval.f_val = 1;
	    else yyval.f_val = 0;
    }
break;
case 66:
#line 432 "compiler_hw2.y"
	{
	    if(yystack.l_mark[-2].f_val >= yystack.l_mark[0].f_val) yyval.f_val = 1;
    	else yyval.f_val = 0;
    }
break;
case 67:
#line 436 "compiler_hw2.y"
	{
    	if(yystack.l_mark[-2].f_val <= yystack.l_mark[0].f_val) yyval.f_val = 1;
    	else yyval.f_val = 0;
    }
break;
case 68:
#line 440 "compiler_hw2.y"
	{
    	if(yystack.l_mark[-2].f_val != yystack.l_mark[0].f_val) yyval.f_val = 1;
    	else yyval.f_val = 0;
    }
break;
case 69:
#line 444 "compiler_hw2.y"
	{
    	if(yystack.l_mark[-2].f_val > yystack.l_mark[0].f_val) yyval.f_val = 1;
    	else yyval.f_val = 0;
    }
break;
case 70:
#line 448 "compiler_hw2.y"
	{
    	if(yystack.l_mark[-2].f_val < yystack.l_mark[0].f_val) yyval.f_val = 1;
    	else yyval.f_val = 0;
    }
break;
case 71:
#line 452 "compiler_hw2.y"
	{
	    yyval.f_val = 0.1;
    }
break;
case 72:
#line 458 "compiler_hw2.y"
	{ yyval.f_val = yystack.l_mark[-2].f_val + yystack.l_mark[0].f_val; }
break;
case 73:
#line 459 "compiler_hw2.y"
	{ yyval.f_val = yystack.l_mark[-2].f_val - yystack.l_mark[0].f_val; }
break;
case 74:
#line 460 "compiler_hw2.y"
	{
    	yyval.f_val = 0.1; 
    }
break;
case 75:
#line 466 "compiler_hw2.y"
	{ yyval.f_val = yystack.l_mark[-2].f_val * yystack.l_mark[0].f_val; }
break;
case 76:
#line 467 "compiler_hw2.y"
	{ yyval.f_val = yystack.l_mark[-2].f_val / yystack.l_mark[0].f_val; }
break;
case 77:
#line 468 "compiler_hw2.y"
	{ 
/*	if(float_flag == 1){*/
/*	  printf("error");*/
 	      yyval.f_val = 0.1;
/*	}*/
/*	else	*/
/*	  $$ = (int)$1 % (int)$3; */
    }
break;
case 78:
#line 476 "compiler_hw2.y"
	{ 
    	yyval.f_val = 0.1; 
    }
break;
case 79:
#line 482 "compiler_hw2.y"
	{ yyval.f_val = yyval.f_val + 1; }
break;
case 80:
#line 483 "compiler_hw2.y"
	{ yyval.f_val = yyval.f_val - 1; }
break;
case 81:
#line 484 "compiler_hw2.y"
	{ 
	    yyval.f_val = 0.1; 
    }
break;
case 82:
#line 490 "compiler_hw2.y"
	{ yyval.f_val = yystack.l_mark[-1].f_val; }
break;
case 83:
#line 491 "compiler_hw2.y"
	{ yyval.f_val = 0.3; }
break;
case 84:
#line 492 "compiler_hw2.y"
	{ yyval.f_val = 0.1; }
break;
case 85:
#line 493 "compiler_hw2.y"
	{ yyval.f_val = 0.2; }
break;
case 86:
#line 497 "compiler_hw2.y"
	{ 
        if(lookup_symbol(symbol_table,yystack.l_mark[-3].string,symbolno)==0){
            char t[50];
            sprintf(t,"Undeclared variable %s",yystack.l_mark[-3].string);
            yyerror(t);
        }       
        yyval.f_val = 0.1; 
    }
break;
case 87:
#line 505 "compiler_hw2.y"
	{ 
        yyval.f_val = 0.1;
    }
break;
case 88:
#line 511 "compiler_hw2.y"
	{ yyval.f_val = 0.1; }
break;
case 89:
#line 512 "compiler_hw2.y"
	{ 
	    yyval.f_val = 0.1; 
	    float_flag = 1;
    }
break;
case 90:
#line 516 "compiler_hw2.y"
	{ yyval.f_val = 0.1; }
break;
case 91:
#line 521 "compiler_hw2.y"
	{ yyval.string = yystack.l_mark[0].string; }
break;
case 92:
#line 522 "compiler_hw2.y"
	{ yyval.string = yystack.l_mark[0].string; }
break;
case 93:
#line 523 "compiler_hw2.y"
	{ yyval.string = yystack.l_mark[0].string; }
break;
case 94:
#line 524 "compiler_hw2.y"
	{ yyval.string = yystack.l_mark[0].string; }
break;
case 95:
#line 525 "compiler_hw2.y"
	{ yyval.string = yystack.l_mark[0].string; }
break;
#line 1503 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
