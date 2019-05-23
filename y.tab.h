#define PRINT 257
#define IF 258
#define ELSE 259
#define FOR 260
#define SEMICOLON 261
#define ADD 262
#define SUB 263
#define MUL 264
#define DIV 265
#define MOD 266
#define INC 267
#define DEC 268
#define MT 269
#define LT 270
#define MTE 271
#define LTE 272
#define EQ 273
#define NE 274
#define LSB 275
#define RSB 276
#define COMMA 277
#define QUOTA 278
#define WHILE 279
#define ASGN 280
#define ADDASGN 281
#define SUBASGN 282
#define MULASGN 283
#define DIVASGN 284
#define MODASGN 285
#define AND 286
#define OR 287
#define NOT 288
#define LB 289
#define RB 290
#define LCB 291
#define RCB 292
#define TRUE 293
#define FALSE 294
#define RET 295
#define CONT 296
#define BREAK 297
#define COMMENT 298
#define I_CONST 299
#define F_CONST 300
#define BOOL 301
#define INT 302
#define STRING 303
#define FLOAT 304
#define VOID 305
#define STR_CONST 306
#define ID 307
#define SEMICOLONE 308
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
extern YYSTYPE yylval;
