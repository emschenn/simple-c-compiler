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
