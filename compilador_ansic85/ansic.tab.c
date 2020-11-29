/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ansic.y"

    #include <stdio.h>    
	#include<stdlib.h>

	#include<iostream>
	#include<iomanip>
	#include<fstream>
	#include<string>
	#include<cstring>
	#include<list>

	
	
	using namespace std;

	extern int yylex(void);
	extern void yyerror(const char *);
	extern FILE *yyin;
	

	/*Definir los tipos de variables*/
	enum VARTYPES{
		VOIDVAL = 1,
		CHARVAL,
		UCHARVAL,
		SCHARVAL,
		SHORTVAL,
		USHORTVAL,
		INTVAL,
		UINTVAL,
		LONGVAL,
		ULONGVAL,
		FVAL,
		DOUBLEVAL,
		LDOUBLEVAL,
		STRVAL,
		STRUCVAL,
		UNIONVAL,
		ENUMVAL,
		TYPENM
	};

	struct symrec{
		std::string name; /*name of symbol*/
		int size;	/*Indicar el tamano en bytes que ocupa de espacio la variable*/
		int init;	/*si el simbolo es inicializado*/
		int typ;	/*indicar tipo de la variable o funcion*/
		int offset;	/*offset en bloque de datos donde estan los datos de la variable*/
		struct{		/*Guardar informacion sobre argumentos de entrada de una funcion*/
			int func_type;	/*Indicar el tipo de valor de retorno*/
			std::list<struct symrec *> *sym_table;
		} func_desc;
	};

	typedef struct symrec symrec;

	typedef std::list<symrec *> symboltable;

	symboltable *sym_table = NULL;

	/*Tabla de variables locales (para bloque entre {})*/
	symboltable *localsyms = NULL;
	/*Tabla de variables locales de funcion siendo analizada*/
	symrec *curr_func = NULL;

	/*Implementar stack de ambitos de variables como lista (tiene metodos push y pop)*/
	std::list<std::list<symrec *> *> scopes;
	/*
	0 ambito de variables globales
	1 indica ambito de variables locales de funcion
	2 indica ambito de variables locales de bloque
	3 indica ambito de variables locales de bloque anidado
	...
	*/
	int currscope = 0; /*Para saber en que ambito estamos*/

	int data_offset = 0; /*offset inicial en bloque de dattos*/
	unsigned char datablock[64*1024]; /*Bloque de datos de 64 KB*/

	typedef union VALUE{
		char charval;
		int intval;
		float floatval;
		double doubleval;
	} VALUE;

	typedef struct CONST_DATA{
		VALUE val;
		int typ;
	} CONST_DATA;

	typedef struct CASE_DATA{
		VALUE val;
		int typ;
		int addr;
	} CASE_DATA;

	typedef struct VAR_DATA{
	std::string *name;
	VALUE val;
	int init;
	int typ;
	int op;
	symrec *var;
	symrec *var2;
	std::list<int> *truelist;
	std::list<int> *falselist;
	std::list<VAR_DATA *> *arglist;
	} VAR_DATA;

	enum TYPE_SPECIFIERS{
		VOID_SPEC		= 0x0000001,
		CHAR_SPEC		= 0x0000002,
		SHORT_SPEC		= 0x0000004,
		INT_SPEC		= 0x0000005,
		LONG_SPEC		= 0x0000010,
		FLOAT_SPEC		= 0x0000020,
		DOUBLE_SPEC		= 0x0000040,
		STRING_SPEC		= 0x0000080,
		STRUCT_SPEC		= 0x0000100,
		UNION_SPEC		= 0x0000200,
		ENUM_SPEC		= 0x0000400,
		TYPENAME_SPEC	= 0x0000800,
		VAR_SPEC		= 0x0001000,
		ARRAY_SPEC		= 0x0002000,
		FUNC_SPEC		= 0x0004000,
		SIGNED_SPEC		= 0x0008000,
		UNSIGNED_SPEC	= 0x0010000,
		CONST_SPEC		= 0x0020000,
		VOLATILE_SPEC	= 0x0040000,
		STATIC_SPEC		= 0x0080000,
		TYPEDEF_SPEC	= 0x0100000,
		EXTERN_SPEC		= 0x0200000,
		AUTO_SPEC		= 0x0400000,
		REGISTER_SPEC	= 0x0800000,
		POINTER_SPEC	= 0x1000000,
		ARG_SPEC		= 0x2000000,
		ARGELLIP_SPEC	= 0x4000000,
	};
	
	enum ASSIGN_TYPES{
		EQ_ASSIGN_OP = 1,
		MUL_ASSIGN_OP,
		DIV_ASSIGN_OP,
		MOD_ASSIGN_OP,
		ADD_ASSIGN_OP,
		SUB_ASSIGN_OP,
		LEFT_ASSIGN_OP,
		RIGHT_ASSIGN_OP,
		AND_ASSIGN_OP,
		XOR_ASSIGN_OP,
		OR_ASSIGN_OP
	};

	enum OP_TYPES{
		PLUS_OP = 1,
		ADDR_OP,
		MINUS_OP,
		DEREF_OP,
		TWOCOMP_OP,
		NOT_OP
	};

	/*Codigos de representacion intermedia*/
	enum code_ops{	STORE_IR, STOREA_IR, LOADA_IR, IF_EQ_IR, IF_NE_IR, IF_LT_IR, IF_GT_IR, IF_LE_IR, IF_GE_IR, GOTO_IR,
					ADD_IR, SUB_IR, MULT_IR, DIV_IR,
					MINUS_IR, MOD_IR, INC_IR, DEC_IR, ADDRESS_IR,
					DEREF_IR, TWOCOMP_IR, NOT_IR, INT_IR, FLOAT_IR, CHAR_IR,
					LSHIFT_IR, RSHIFT_IR, AND_IR, XOR_IR, OR_IR, RET_IR, PROC_IR, ENDPROC_IR, CALL_IR, PARAM_IR
		
	};

	typedef struct {
		enum code_ops op;
		symrec *arg1;
		symrec *arg2;
		symrec *result;
	} quad;

	/*Codigo intermedio*/
	quad code[9999];
	int nextinstr = 0; /*Initial offset in code array*/

	struct labrec{
		std::string name;	/*Name of label*/
		int instr;	/*Instruction offset*/
	};
	std::list<labrec *> lab_table;

	#include "symdef.h"
	#include "genlib.h"

#line 263 "ansic.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONSTANT = 259,
    STRING_LITERAL = 260,
    SIZEOF = 261,
    PTR_OP = 262,
    INC_OP = 263,
    DEC_OP = 264,
    LEFT_OP = 265,
    RIGHT_OP = 266,
    LE_OP = 267,
    GE_OP = 268,
    EQ_OP = 269,
    NE_OP = 270,
    AND_OP = 271,
    OR_OP = 272,
    MUL_ASSIGN = 273,
    DIV_ASSIGN = 274,
    MOD_ASSIGN = 275,
    ADD_ASSIGN = 276,
    SUB_ASSIGN = 277,
    LEFT_ASSIGN = 278,
    RIGHT_ASSIGN = 279,
    AND_ASSIGN = 280,
    XOR_ASSIGN = 281,
    OR_ASSIGN = 282,
    TYPE_NAME = 283,
    TYPEDEF = 284,
    EXTERN = 285,
    STATIC = 286,
    AUTO = 287,
    REGISTER = 288,
    CHAR = 289,
    SHORT = 290,
    INT = 291,
    LONG = 292,
    SIGNED = 293,
    UNSIGNED = 294,
    FLOAT = 295,
    DOUBLE = 296,
    CONST = 297,
    VOLATILE = 298,
    VOID = 299,
    STRUCT = 300,
    UNION = 301,
    ENUM = 302,
    ELLIPSIS = 303,
    CASE = 304,
    DEFAULT = 305,
    IF = 306,
    ELSE = 307,
    SWITCH = 308,
    WHILE = 309,
    DO = 310,
    FOR = 311,
    GOTO = 312,
    CONTINUE = 313,
    BREAK = 314,
    RETURN = 315,
    NO_ELSE = 316
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 196 "ansic.y"

    /*struct {char cval;int ival;double dval;int typ;} val;*/
	struct{
		union{
			char cval;
			char *str;
			char *name;
			int ival;
			float fval;
			double dval;
		};
		int type;
	} token;
	VAR_DATA *id_data;
	std::list<VAR_DATA *> *idlist;
	int scsp;
	int qual;
	int asop;
	int instr;
	int typ;
	int op;
	std::list<int> *sqlist;
	VAR_DATA sym; /*para poner datos sobre una variable ya declarada*/
	struct{
		std::list<int> *breaklist;
		std::list<int> *nextlist;
		std::list<CASE_DATA *> *caselist;
	} lists;

#line 407 "ansic.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1285

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  219
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  372

#define YYUNDEFTOK  2
#define YYMAXUTOK   316


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,     2,     2,     2,    75,    68,     2,
      62,    63,    69,    70,    67,    71,    66,    74,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    81,    83,
      76,    82,    77,    80,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,    78,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,    79,    85,    72,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   293,   293,   304,   334,   351,   355,   356,   357,   365,
     380,   381,   382,   399,   419,   428,   437,   438,   450,   462,
     504,   518,   536,   537,   538,   539,   540,   541,   545,   546,
     550,   551,   558,   565,   575,   576,   584,   594,   595,   596,
     600,   601,   608,   615,   622,   631,   637,   638,   639,   643,
     644,   648,   649,   653,   654,   658,   659,   669,   670,   680,
     681,   685,   688,   810,   811,   812,   813,   814,   815,   816,
     817,   818,   819,   820,   824,   825,   829,   835,   836,   859,
     863,   866,   870,   873,   877,   883,   888,   895,   896,   903,
     906,   909,   912,   915,   921,   922,   923,   924,   925,   926,
     927,   928,   929,   930,   931,   932,   936,   937,   938,   942,
     943,   947,   948,   952,   956,   960,   965,   969,   977,   978,
     982,   983,   984,   988,   989,   990,   994,   995,   999,  1000,
    1004,  1007,  1013,  1014,  1018,  1025,  1026,  1027,  1028,  1034,
    1035,  1043,  1044,  1045,  1046,  1050,  1051,  1056,  1057,  1061,
    1068,  1077,  1084,  1085,  1089,  1090,  1094,  1097,  1101,  1102,
    1103,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,
    1119,  1120,  1121,  1125,  1126,  1129,  1132,  1136,  1136,  1145,
    1150,  1153,  1156,  1162,  1163,  1171,  1178,  1182,  1185,  1189,
    1195,  1196,  1200,  1201,  1211,  1215,  1220,  1235,  1242,  1247,
    1253,  1287,  1295,  1302,  1310,  1323,  1324,  1325,  1331,  1337,
    1346,  1347,  1351,  1352,  1356,  1357,  1357,  1376,  1377,  1377
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "NO_ELSE", "'('", "')'", "'['", "']'",
  "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'",
  "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'",
  "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "N", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "P", "statement", "$@1", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "logic_expression", "M", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "$@2", "$@3", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    40,    41,    91,    93,    46,    44,    38,    42,
      43,    45,   126,    33,    47,    37,    60,    62,    94,   124,
      63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF (-335)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-216)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     909,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,    30,    57,    20,  -335,   124,  1238,  1238,  -335,    31,
    -335,  1238,  1238,    69,    23,   819,  -335,  -335,   -55,    24,
     -17,  -335,  -335,    20,  -335,   -48,  -335,  1062,  -335,  -335,
     -32,  1036,  -335,  -335,   124,  1082,     2,   954,   603,    69,
    -335,  -335,    24,    13,   -43,  -335,  -335,  -335,  -335,    57,
    -335,   461,  1082,     2,  1036,  1036,   984,  -335,    54,  1036,
      16,   317,  -335,  -335,  -335,  -335,  -335,   161,    59,    67,
    -335,    92,  -335,  -335,  -335,   724,   745,   745,   582,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,   224,  -335,   769,
    -335,   113,     9,   199,    52,   204,    95,    96,   116,   168,
     -11,  -335,   127,   -37,   769,    24,  -335,  -335,   461,   221,
    -335,  -335,  -335,  -335,  -335,  1004,  -335,  -335,  -335,   769,
     -13,  -335,   134,  -335,   154,   769,   175,   141,  -335,  -335,
    -335,   187,   250,   177,   189,   509,  -335,  -335,  -335,    -9,
    -335,  -335,  -335,   388,   188,  -335,  -335,  -335,  -335,   864,
     627,  -335,   162,  -335,   140,  -335,  1217,  -335,   274,   582,
    -335,   769,  -335,  -335,    93,   107,   215,   276,  -335,  -335,
     653,   769,   277,  -335,   769,   769,   769,   769,   769,   769,
     769,   769,   769,   769,   769,   769,   769,   769,   769,   769,
    -335,  -335,   769,  -335,  -335,  -335,  -335,  -335,   -35,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
     769,  -335,  -335,    54,  -335,   769,   493,   200,  -335,   769,
     220,   223,   493,   532,   206,  -335,  -335,  -335,    -6,   769,
    -335,     2,  -335,   207,  -335,   493,  -335,   228,   231,  -335,
     230,   140,  1181,   674,  -335,  -335,  -335,   234,  -335,  1139,
     172,  -335,   769,  -335,  -335,    99,  -335,   185,  -335,  -335,
    -335,  -335,   113,   113,     9,     9,   199,   199,   199,   199,
      52,    52,   204,    95,    96,   769,   769,    51,   406,  -335,
    -335,  -335,  -335,  -335,  -335,   493,   232,   237,   769,   769,
     248,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,   241,  -335,   242,  -335,  -335,  -335,   769,  -335,
     116,   168,   769,  -335,  -335,   493,  -335,  -335,   105,   245,
    -335,   532,  -335,  -335,  -335,  -335,  -335,   493,   493,  -335,
     249,  -335,   258,  -335,   493,   769,   698,  -335,  -335,   251,
     493,   149,  -335,   233,  -335,  -335,   493,  -335,  -335,  -335,
     493,  -335
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   134,   105,    89,    90,    91,    92,    93,    95,    96,
      97,    98,   101,   102,    99,   100,   130,   131,    94,   109,
     110,     0,     0,   141,   213,     0,    79,    81,   103,     0,
     104,    83,   218,   133,     0,     0,   210,   212,   125,     0,
       0,   145,   143,   142,    77,     0,    85,    87,    80,    82,
     108,     0,    84,   190,     0,     0,     0,     0,     0,   132,
       1,   211,     0,   128,     0,   126,   135,   146,   144,     0,
      78,     0,     0,     0,     0,   115,     0,   111,     0,   117,
      87,   175,   191,   217,   219,   154,   140,   153,     0,   147,
     149,     0,     2,     3,     4,     0,     0,     0,     0,   137,
      22,    23,    24,    25,    26,    27,     6,    16,    28,     0,
      30,    34,    37,    40,    46,    49,    51,    53,    55,    57,
      59,    76,     0,     0,     0,     0,   123,    86,     0,    28,
      61,   170,    88,   214,   216,     0,   114,   107,   112,     0,
       0,   118,   120,   116,     2,     0,     0,     0,   197,    45,
      45,     0,     0,     0,     0,     0,   194,   186,    74,     0,
     177,   192,   176,   175,    45,   179,   180,   181,   182,     0,
       0,   151,   158,   152,   159,   138,     0,   139,     0,     0,
      20,     0,    17,    18,     0,   156,     0,     0,    12,    13,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45,    45,     0,   136,   124,   129,   127,   173,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    63,
       0,   106,   121,     0,   113,     0,   175,     0,    45,     0,
       0,     0,   175,     0,     0,   206,   207,   208,     0,     0,
     195,     0,   188,    45,   187,   175,   166,     0,     0,   162,
       0,   160,     0,     0,   148,   150,   155,     0,     5,     0,
     158,   157,     0,    11,     8,     0,    14,     0,    10,    31,
      32,    33,    35,    36,    38,    39,    43,    44,    41,    42,
      47,    48,    50,    52,    54,     0,     0,     0,     0,   171,
      62,   119,   122,   183,    45,   175,   196,     0,     0,     0,
       0,    45,   205,   209,    75,   178,   189,   193,   167,   161,
     163,   168,     0,   164,     0,    21,    29,     9,     0,     7,
      56,    58,     0,   172,   174,   175,   185,    45,     0,     0,
      45,     0,   169,   165,    15,    60,   184,   175,   175,    45,
       0,    45,   198,   200,   175,     0,     0,   197,   201,     0,
     175,     0,    45,     0,   203,   197,   175,   202,    45,   199,
     175,   204
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -335,  -335,  -335,  -335,   -58,  -335,   -93,    64,    28,    63,
      65,   -53,   106,   109,   110,    34,    35,  -335,   -57,   -69,
    -335,   -87,   -46,    18,    14,  -335,   261,  -335,   122,  -335,
    -335,   253,   -51,   -62,  -335,   100,  -335,   270,   209,    32,
      22,   -19,   -15,  -335,   -54,  -335,   159,  -335,   157,   -80,
    -160,  -123,  -335,  -335,   -42,  -335,  -335,   -52,   -38,   174,
    -221,  -299,  -334,  -335,  -335,  -335,  -335,   303,  -335,  -335,
    -335
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   106,   107,   275,   129,   109,   110,   111,   112,   113,
     114,   255,   115,   116,   117,   118,   119,   120,   130,   158,
     230,   159,   122,    53,    54,    45,    46,    26,    27,    28,
      29,    76,    77,    78,   140,   141,    30,    64,    65,    31,
      32,    33,    34,    43,   257,    89,    90,    91,   186,   258,
     174,   132,   218,   160,   161,   251,   162,    83,    55,   164,
     165,   307,   240,   166,   167,   168,    35,    36,    37,    73,
      56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,   121,   131,    88,    84,   217,   211,   173,    42,    72,
     339,   184,   261,   136,    25,    59,   193,   143,    24,    69,
     133,   134,   311,   362,   125,   138,     1,    63,    68,    62,
     125,   368,   298,    38,    50,    70,   185,   180,   182,   183,
      48,    49,   126,   163,    40,    52,    66,    47,   214,    25,
     299,   108,    74,    24,   233,    41,   359,     1,   249,   131,
       1,   249,    16,    17,   201,   202,   108,   121,   248,   212,
     234,    87,   172,    82,   250,    67,    80,   313,   215,   197,
     198,   108,   121,    79,   138,    22,    81,   108,   121,    23,
      82,    80,   184,   232,   184,   124,   241,   242,    71,   237,
     142,   279,   280,   281,   277,   271,    79,    79,    79,   171,
     261,    79,   108,   121,    39,    51,    22,   185,   249,    22,
     351,   276,   175,    23,   260,   297,    23,     1,   203,   204,
      79,    57,   332,    58,   176,   139,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   306,    59,   172,   177,   268,   295,   296,   178,
     249,   300,   327,   207,     1,     1,   328,    79,   348,   269,
     270,   170,   249,    75,   208,   334,    23,   108,   121,   326,
     314,    82,   194,    87,   210,   305,    22,   195,   196,   302,
      87,    40,   213,    23,   303,   209,    75,    75,    75,   315,
     310,    75,   262,   239,   263,   108,   121,    44,   322,   199,
     200,    79,   365,   317,   108,   235,   249,   324,   205,   206,
      75,   338,   306,   169,   169,   170,   170,   284,   285,   131,
      23,   187,   188,   189,   269,   236,   170,   108,   108,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   243,
     329,   335,   249,   244,   270,   142,   238,    75,   341,   344,
     245,   282,   283,   336,   286,   287,   288,   289,   306,   361,
     290,   291,   246,   254,   108,   345,    87,   266,   272,   273,
     278,   304,   308,    87,   347,   309,   190,   350,   191,   312,
     192,   318,   316,   346,   319,   320,   354,   325,   356,   249,
     337,    75,   340,   229,   342,   352,   353,   343,   349,   366,
     357,   355,   358,   292,   363,   370,   367,   293,   364,   294,
     144,    93,    94,    95,   369,    96,    97,   135,   371,   330,
     127,   331,   123,   301,   216,   265,   267,   253,    61,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,   145,   146,   147,     0,
     148,   149,   150,   151,   152,   153,   154,   155,     0,    98,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   144,    93,    94,    95,     0,    96,    97,     0,     0,
     156,     0,   157,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,     0,    96,    97,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,   145,   146,   147,
       0,   148,   149,   150,   151,   152,   153,   154,   155,     0,
      98,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,     0,     0,    92,    93,    94,    95,    98,    96,
      97,   156,     0,   252,   100,   101,   102,   103,   104,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   333,     0,     0,     0,     0,   144,    93,    94,    95,
       0,    96,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    94,    95,     0,    96,    97,     0,
       0,     0,     0,    98,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,    92,    93,    94,    95,     0,
      96,    97,   145,   146,   147,   128,   148,   149,   150,   151,
     152,   153,   154,   155,     0,    98,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,     0,     0,     0,
       0,    98,     0,     0,     0,     0,   156,   100,   101,   102,
     103,   104,   105,     0,     0,    92,    93,    94,    95,     0,
      96,    97,   247,     0,    98,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,    92,    93,    94,    95,
       2,    96,    97,     0,     0,   156,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      92,    93,    94,    95,     0,    96,    97,     0,     0,     0,
       0,     0,     0,     0,    98,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,    92,    93,    94,    95,
       0,    96,    97,     0,     0,    98,     0,     0,    99,     0,
       0,   100,   101,   102,   103,   104,   105,    92,    93,    94,
      95,     0,    96,    97,     0,     0,     0,     0,     0,    98,
       0,     0,   259,     0,     0,   100,   101,   102,   103,   104,
     105,    92,    93,    94,    95,     0,    96,    97,     0,     0,
       0,     0,     0,     0,     0,    98,   274,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,    92,    93,    94,
      95,     0,    96,    97,     0,     0,    98,     0,     0,   323,
       0,     0,   100,   101,   102,   103,   104,   105,    92,    93,
      94,    95,     0,    96,    97,     0,     0,     0,     0,     0,
      98,   360,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,    92,    93,    94,    95,     0,    96,    97,     0,
       0,     0,     0,     0,     0,     0,   179,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,    60,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   256,   170,     0,
       0,     0,     0,    23,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     0,    86,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     2,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,   137,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,   231,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    71,     0,  -215,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   269,   256,   170,     0,     0,     0,     0,    23,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   321,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   264,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
      58,    58,    71,    57,    56,   128,    17,    87,    23,    47,
     309,    98,   172,    75,     0,    34,   109,    79,     0,    67,
      72,    73,   243,   357,    67,    76,     3,     3,    43,    84,
      67,   365,    67,     3,     3,    83,    98,    95,    96,    97,
      26,    27,    85,    81,    22,    31,    63,    25,    85,    35,
      85,   109,    84,    35,    67,    23,   355,     3,    67,   128,
       3,    67,    42,    43,    12,    13,   124,   124,   155,    80,
      83,    57,    87,    55,    83,    43,    54,    83,   124,    70,
      71,   139,   139,    51,   135,    62,    84,   145,   145,    69,
      72,    69,   179,   139,   181,    82,   149,   150,    82,   145,
      78,   194,   195,   196,   191,   185,    74,    75,    76,    87,
     270,    79,   170,   170,    84,    84,    62,   179,    67,    62,
     341,   190,    63,    69,   170,   212,    69,     3,    76,    77,
      98,    62,    81,    64,    67,    81,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   239,   172,   169,    63,    63,   210,   211,    67,
      67,   230,    63,    68,     3,     3,    67,   135,    63,    62,
     185,    64,    67,    51,    78,   298,    69,   235,   235,   272,
     249,   163,    69,   169,    16,   238,    62,    74,    75,   235,
     176,   169,    65,    69,   236,    79,    74,    75,    76,   251,
     242,    79,    62,    62,    64,   263,   263,    83,   262,    10,
      11,   179,    63,   255,   272,    81,    67,   263,    14,    15,
      98,   308,   309,    62,    62,    64,    64,   199,   200,   298,
      69,     7,     8,     9,    62,    81,    64,   295,   296,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    62,
      65,   304,    67,     3,   269,   233,    81,   135,   311,   328,
      83,   197,   198,   305,   201,   202,   203,   204,   355,   356,
     205,   206,    83,    85,   332,   332,   262,     3,    63,     3,
       3,    81,    62,   269,   337,    62,    62,   340,    64,    83,
      66,    63,    85,   335,    63,    65,   349,    63,   351,    67,
      63,   179,    54,    82,    63,   347,   348,    65,    63,   362,
      52,    62,   354,   207,    63,   368,    83,   208,   360,   209,
       3,     4,     5,     6,   366,     8,     9,    74,   370,   295,
      69,   296,    62,   233,   125,   176,   179,   163,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      73,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      83,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,    -1,    -1,     3,     4,     5,     6,    62,     8,
       9,    83,    -1,    85,    68,    69,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,     3,     4,     5,     6,    -1,
       8,     9,    49,    50,    51,    84,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    83,    68,    69,    70,
      71,    72,    73,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    83,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,     3,     4,     5,     6,
      28,     8,     9,    -1,    -1,    83,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    62,    -1,    -1,    65,    -1,
      -1,    68,    69,    70,    71,    72,    73,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    65,    -1,    -1,    68,    69,    70,    71,    72,
      73,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    73,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    62,    -1,    -1,    65,
      -1,    -1,    68,    69,    70,    71,    72,    73,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      62,    63,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    73,     0,
      -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    63,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    85,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    85,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    64,    -1,    -1,    -1,    -1,    69,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    62,    69,   109,   110,   113,   114,   115,   116,
     122,   125,   126,   127,   128,   152,   153,   154,     3,    84,
     126,   125,   128,   129,    83,   111,   112,   126,   110,   110,
       3,    84,   110,   109,   110,   144,   156,    62,    64,   127,
       0,   153,    84,     3,   123,   124,    63,   125,   128,    67,
      83,    82,   144,   155,    84,   114,   117,   118,   119,   125,
     126,    84,   109,   143,   143,     3,    63,   110,   130,   131,
     132,   133,     3,     4,     5,     6,     8,     9,    62,    65,
      68,    69,    70,    71,    72,    73,    87,    88,    90,    91,
      92,    93,    94,    95,    96,    98,    99,   100,   101,   102,
     103,   104,   108,   123,    82,    67,    85,   112,    84,    90,
     104,   105,   137,   143,   143,   117,   119,    85,   118,    81,
     120,   121,   126,   119,     3,    49,    50,    51,    53,    54,
      55,    56,    57,    58,    59,    60,    83,    85,   105,   107,
     139,   140,   142,   144,   145,   146,   149,   150,   151,    62,
      64,   126,   128,   135,   136,    63,    67,    63,    67,    62,
      90,    62,    90,    90,   107,   119,   134,     7,     8,     9,
      62,    64,    66,    92,    69,    74,    75,    70,    71,    10,
      11,    12,    13,    76,    77,    14,    15,    68,    78,    79,
      16,    17,    80,    65,    85,   108,   124,   137,   138,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    82,
     106,    85,   108,    67,    83,    81,    81,   108,    81,    62,
     148,    97,    97,    62,     3,    83,    83,    83,   107,    67,
      83,   141,    85,   145,    85,    97,    63,   130,   135,    65,
     108,   136,    62,    64,    48,   132,     3,   134,    63,    62,
     128,   135,    63,     3,    63,    89,   105,   107,     3,    92,
      92,    92,    93,    93,    94,    94,    95,    95,    95,    95,
      96,    96,    98,    99,   100,    97,    97,   107,    67,    85,
     105,   121,   108,   140,    81,    97,   107,   147,    62,    62,
     140,   146,    83,    83,   105,   143,    85,   140,    63,    63,
      65,    63,   130,    65,   108,    63,    92,    63,    67,    65,
     101,   102,    81,    85,   137,    97,   140,    63,   107,   147,
      54,    97,    63,    65,   105,   104,   140,    97,    63,    63,
      97,   146,   140,   140,    97,    62,    97,    52,   140,   147,
      63,   107,   148,    63,   140,    63,    97,    83,   148,   140,
      97,   140
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    91,    91,    91,    92,    92,
      93,    93,    93,    93,    94,    94,    94,    95,    95,    95,
      96,    96,    96,    96,    96,    97,    98,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   107,   107,   108,   109,   109,   110,
     110,   110,   110,   110,   110,   111,   111,   112,   112,   113,
     113,   113,   113,   113,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   115,   116,
     116,   117,   117,   118,   119,   119,   119,   119,   120,   120,
     121,   121,   121,   122,   122,   122,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   127,   127,   127,   127,
     127,   128,   128,   128,   128,   129,   129,   130,   130,   131,
     131,   132,   132,   132,   133,   133,   134,   134,   135,   135,
     135,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     137,   137,   137,   138,   138,   139,   140,   141,   140,   140,
     140,   140,   140,   142,   142,   142,   143,   143,   143,   143,
     144,   144,   145,   145,   146,   146,   147,   148,   149,   149,
     149,   150,   150,   150,   150,   151,   151,   151,   151,   151,
     152,   152,   153,   153,   154,   155,   154,   154,   156,   154
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     0,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     4,     1,     4,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       2,     1,     2,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     1,
       1,     1,     2,     3,     2,     1,     2,     1,     1,     3,
       1,     2,     3,     4,     5,     2,     1,     3,     1,     3,
       1,     1,     2,     1,     1,     3,     4,     3,     4,     4,
       3,     1,     2,     2,     3,     1,     2,     1,     3,     1,
       3,     2,     2,     1,     1,     3,     1,     2,     1,     1,
       2,     3,     2,     3,     3,     4,     2,     3,     3,     4,
       1,     3,     4,     1,     3,     0,     1,     0,     3,     1,
       1,     1,     1,     3,     5,     4,     2,     3,     3,     4,
       1,     2,     1,     3,     1,     2,     1,     0,     6,    10,
       6,     7,     9,     8,    11,     3,     2,     2,     2,     3,
       1,     2,     1,     1,     4,     0,     4,     3,     0,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 293 "ansic.y"
                                                                                                                        {
																		printf("primary_expression : IDENTIFIER\n");
																		(yyval.sym).name = new string((yyvsp[0].token.name)); /*La cadena string que contiene el nombre de la variable*/
																		symrec *s = getsym((yyval.sym).name);
																		if(s == NULL){
																			printf("Variable %s", (yyvsp[0].token.name));
																			yyerror("not declared!");
																		}
																		(yyval.sym).var = s; /*La variavle de la tabla de simbolos que se encontro con getsym()*/
																		(yyval.sym).typ = s->typ; /*El tipo se obtuvo de la tabla de simbolos*/
																	}
#line 2181 "ansic.tab.c"
    break;

  case 3:
#line 304 "ansic.y"
                                                                                                                                {	printf("primary_expression : CONSTANT\n");
																		symrec *s;
																		std::string *name;
																		switch((yyvsp[0].token.type)){
																			case INTVAL:
																				name = newtemp();	/*crear una variable temporal*/
																				s = putsym(name, INTVAL | CONST_SPEC);
																				(yyval.sym).val.intval = (yyvsp[0].token.ival);
																				*(int *)(datablock+s->offset) = (yyvsp[0].token.ival);
																				(yyval.sym).typ = s->typ;
																				(yyval.sym).var = s;
																				break;
																			case DOUBLEVAL:
																				name = newtemp();	/*crear una variable temporal*/
																				s = putsym(name, DOUBLEVAL | CONST_SPEC);
																				(yyval.sym).val.doubleval = (yyvsp[0].token.dval);
																				*(double *)(datablock+s->offset) = (yyvsp[0].token.ival);
																				(yyval.sym).typ = s->typ;
																				(yyval.sym).var = s;
																				break;
																			case CHARVAL:
																				name = newtemp();	/*crear una variable temporal*/
																				s = putsym(name, CHARVAL | CONST_SPEC);
																				(yyval.sym).val.charval = (yyvsp[0].token.cval);
																				*(char *)(datablock+s->offset) = (yyvsp[0].token.ival);
																				(yyval.sym).typ = s->typ;
																				(yyval.sym).var = s;
																				break;
																		}
																	}
#line 2216 "ansic.tab.c"
    break;

  case 4:
#line 334 "ansic.y"
                                                                                                                        {	printf("primary_expression : STRING_LITERAL\n");
																		/*Crear variable temporal para guardar cadena*/
																		std::string *name = newtemp();
																		symrec *s;
																		/*Agregar variable temporal a tabla de simbolos*/
																		s = putsym(name, STRVAL | CONST_SPEC);
																		/*Determinar tamano de cadena*/
																		s->size = strlen((yyvsp[0].token.name))+1;
																		/*Copiar cadena a bloque de datos datablock*/
																		memcpy(datablock+s->offset, (yyvsp[0].token.name), s->size);
																		/*Incrementar valor de posicion libre en bloque de datos*/
																		data_location(s->size);
																		/*Propagar atributos de variable temporal al nodo padre primary_expression*/
																		(yyval.sym).name =name;
																		(yyval.sym).typ = s->typ;
																		(yyval.sym).var = s;
																	}
#line 2238 "ansic.tab.c"
    break;

  case 5:
#line 351 "ansic.y"
                                                                                                                {(yyval.sym) = (yyvsp[-1].sym);}
#line 2244 "ansic.tab.c"
    break;

  case 6:
#line 355 "ansic.y"
                                                                                                                {(yyval.sym) = (yyvsp[0].sym);}
#line 2250 "ansic.tab.c"
    break;

  case 7:
#line 356 "ansic.y"
                                                                                                {}
#line 2256 "ansic.tab.c"
    break;

  case 8:
#line 357 "ansic.y"
                                                                                                        {
																		symrec *s;
																		std::string *name = newtemp();
																		s = putsym(name, (yyvsp[-2].sym).typ & 0x1F);
																		(yyval.sym).typ = s->typ;
																		gencode(CALL_IR, (yyvsp[-2].sym).var, nullptr, s);
																		(yyval.sym).var = s;
																	}
#line 2269 "ansic.tab.c"
    break;

  case 9:
#line 365 "ansic.y"
                                                                                {
																		symrec *s, *s2, *s3;
																		std::list<VAR_DATA *>::reverse_iterator it;
																		std::string *name = newtemp();
																		s = putsym(name, (yyvsp[-3].sym).typ & 0x1F);
																		(yyval.sym).typ = s->typ;
																		for(it = (yyvsp[-1].sym).arglist->rbegin(); it != (yyvsp[-1].sym).arglist->rend(); it++){
																			gencode(PARAM_IR, (*it)->var, nullptr, nullptr);
																		}
																		s3 = new symrec();
																		s3->name = "";
																		s3->offset = (yyvsp[-1].sym).arglist->size();
																		gencode(CALL_IR, (yyvsp[-3].sym).var, s3, s);
																		(yyval.sym).var = s;
																	}
#line 2289 "ansic.tab.c"
    break;

  case 10:
#line 380 "ansic.y"
                                                                                                        {}
#line 2295 "ansic.tab.c"
    break;

  case 11:
#line 381 "ansic.y"
                                                                                                {}
#line 2301 "ansic.tab.c"
    break;

  case 12:
#line 382 "ansic.y"
                                                                                                                {
																		if((yyvsp[-1].sym).typ & VAR_SPEC){
																			/*Crear variable temporal para guardar valor de postfix_expression antes de incremento*/
																			std::string *name = newtemp();
																			symrec *s;
																			/*Agregar variable temporal a tabla de simbolos*/
																			s = putsym(name, (yyvsp[-1].sym).typ);
																			/*Generar instruccion de codigo intermedio para asignacion*/
																			gencode(STORE_IR, (yyvsp[-1].sym).var, nullptr, s);
																			gencode(INC_IR, (yyvsp[-1].sym).var, nullptr, (yyvsp[-1].sym).var);
																			(yyval.sym).name = name;
																			(yyval.sym).typ = (yyvsp[-1].sym).typ;
																			(yyval.sym).var = s;
																		}
																		else
																			yyerror("Error : Operand of increment operator must be an variable name\n");
																	}
#line 2323 "ansic.tab.c"
    break;

  case 13:
#line 399 "ansic.y"
                                                                                                                {
																		if((yyvsp[-1].sym).typ & VAR_SPEC){
																			/*Crear variable temporal para guardar valor de postfix_expression antes de incremento*/
																			std::string *name = newtemp();
																			symrec *s;
																			/*Agregar variable temporal a tabla de simbolos*/
																			s = putsym(name, (yyvsp[-1].sym).typ);
																			/*Generar instruccion de codigo intermedio para asignacion*/
																			gencode(STORE_IR, (yyvsp[-1].sym).var, nullptr, s);
																			gencode(DEC_IR, (yyvsp[-1].sym).var, nullptr, (yyvsp[-1].sym).var);
																			(yyval.sym).name = name;
																			(yyval.sym).typ = (yyvsp[-1].sym).typ;
																			(yyval.sym).var = s;
																		}
																		else
																			yyerror("Error : Operand of decrement operator must be an variable name\n");
																	}
#line 2345 "ansic.tab.c"
    break;

  case 14:
#line 419 "ansic.y"
                                                                                                                {
																		std::list<VAR_DATA *> *newlist = new std::list<VAR_DATA *>();
																		VAR_DATA *newstruc = new VAR_DATA();
																		*newstruc = (yyvsp[0].sym);
																		newlist->push_back(newstruc);
																		(yyval.sym).name = new std::string();
																		(yyval.sym).typ = 0;
																		(yyval.sym).arglist = newlist;
																	}
#line 2359 "ansic.tab.c"
    break;

  case 15:
#line 428 "ansic.y"
                                                                                {
																		VAR_DATA *newstruc = new VAR_DATA();
																		*newstruc = (yyvsp[0].sym);
																		(yyval.sym) = (yyvsp[-2].sym);
																		(yyval.sym).arglist->push_back(newstruc);
																	}
#line 2370 "ansic.tab.c"
    break;

  case 16:
#line 437 "ansic.y"
                                                                                                                {(yyval.sym) = (yyvsp[0].sym);}
#line 2376 "ansic.tab.c"
    break;

  case 17:
#line 438 "ansic.y"
                                                                                                                {
																		if((yyvsp[0].sym).typ & VAR_SPEC){
																			/*Generar instruccion de codigo intermedio para incremento*/
																			gencode(INC_IR, (yyvsp[0].sym).var, nullptr, (yyvsp[0].sym).var);
																			/*Propagar atributos de variable temporal al nodo padre postfix_expression*/
																			(yyval.sym).name = (yyvsp[0].sym).name;
																			(yyval.sym).typ = (yyvsp[0].sym).typ;
																			(yyval.sym).var = (yyvsp[0].sym).var;
																		}
																		else
																			yyerror("Error : Operand of increment operator must be an variable name\n");
																	}
#line 2393 "ansic.tab.c"
    break;

  case 18:
#line 450 "ansic.y"
                                                                                                                {
																		if((yyvsp[0].sym).typ & VAR_SPEC){
																			/*Generar instruccion de codigo intermedio para incremento*/
																			gencode(DEC_IR, (yyvsp[0].sym).var, nullptr, (yyvsp[0].sym).var);
																			/*Propagar atributos de variable temporal al nodo padre postfix_expression*/
																			(yyval.sym).name = (yyvsp[0].sym).name;
																			(yyval.sym).typ = (yyvsp[0].sym).typ;
																			(yyval.sym).var = (yyvsp[0].sym).var;
																		}
																		else
																			yyerror("Error : Operand of decrement operator must be an variable name\n");
																	}
#line 2410 "ansic.tab.c"
    break;

  case 19:
#line 462 "ansic.y"
                                                                                                        {	printf("unary_expression : unary_operator cast_expression\n");
																		std::string *name;
																		symrec *s;
																		if((yyvsp[-1].op) == PLUS_OP){
																			(yyval.sym) = (yyvsp[0].sym);
																		}			
																		name = newtemp();
																		/*Generar instruccion de codigo intermedio*/
																		switch((yyvsp[-1].op)){
																			case ADDR_OP:
																				s = putsym(name, INTVAL);
																				gencode(ADDRESS_IR, (yyvsp[0].sym).var, nullptr, s);
																				(yyval.sym).typ = INTVAL;
																				break;
																			case DEREF_OP:
																				if(!ispointer((yyvsp[0].sym).typ))
																					yyerror("Error: Operand must be a ponter!\n");
																				s = putsym(name, (yyvsp[0].sym).typ & ~POINTER_SPEC);
																				gencode(DEREF_IR, (yyvsp[0].sym).var, nullptr, s);
																				(yyval.sym).typ = (yyvsp[0].sym).typ;
																				break;
																			case MINUS_OP:
																				s = putsym(name, (yyvsp[0].sym).typ);
																				gencode(MINUS_IR, (yyvsp[0].sym).var, nullptr, s);
																				(yyval.sym).typ = (yyvsp[0].sym).typ;
																				break;
																			case TWOCOMP_OP:
																				s = putsym(name, INTVAL);
																				gencode(TWOCOMP_IR, (yyvsp[0].sym).var, nullptr, s);
																				(yyval.sym).typ = INTVAL;
																				break;
																			case NOT_OP:
																				s = putsym(name, INTVAL);
																				gencode(NOT_IR, (yyvsp[0].sym).var, nullptr, s);
																				(yyval.sym).truelist = (yyvsp[0].sym).falselist;
																				(yyval.sym).falselist = (yyvsp[0].sym).truelist;
																				(yyval.sym).typ = INTVAL;
																				break;
																		}
																		(yyval.sym).name = name;
																		(yyval.sym).var = s;
																	}
#line 2457 "ansic.tab.c"
    break;

  case 20:
#line 504 "ansic.y"
                                                                                                                {
																		printf("unary_expression : SIZEOF unary_expression\n");
																		/*Crear variable temporal para guardar valor tamano de unary_expression*/
																		std::string *name = newtemp();
																		symrec *s;
																		/*Agregar variable temporal a tabla de simbolos*/
																		s = putsym(name, INTVAL | CONST_SPEC);
																		/*Copiar tamano de unary_expression en bloque de datos datablock*/
																		*(int *)(datablock+s->offset) = getsizeof((yyvsp[0].sym).typ);
																		/*Propagar atributos de postfix_expression al nodo padre unary_expression*/
																		(yyval.sym).name = name;
																		(yyval.sym).typ = INTVAL | CONST_SPEC;
																		(yyval.sym).var = s;
																	}
#line 2476 "ansic.tab.c"
    break;

  case 21:
#line 518 "ansic.y"
                                                                                                                {	
																		printf("unary_expression : SIZEOF '(' type_name ')'\n");
																		/*Crear variable temporal para guardar valor tamano de unary_expression*/
																		std::string *name = newtemp();
																		symrec *s;
																		/*Agregar variable temporal a tabla de simbolos*/
																		s = putsym(name, INTVAL | CONST_SPEC);
																		/*Copiar tamano de unary_expression en bloque de datos datablock*/
																		*(int *)(datablock+s->offset) = getsizeof((yyvsp[-1].typ));
																		/*Propagar atributos de postfix_expression al nodo padre unary_expression*/
																		(yyval.sym).name = name;
																		(yyval.sym).typ = INTVAL | CONST_SPEC;
																		(yyval.sym).var = s;
																	
																	}
#line 2496 "ansic.tab.c"
    break;

  case 22:
#line 536 "ansic.y"
                        {(yyval.op) = ADDR_OP;}
#line 2502 "ansic.tab.c"
    break;

  case 23:
#line 537 "ansic.y"
                        {(yyval.op) = DEREF_OP;}
#line 2508 "ansic.tab.c"
    break;

  case 24:
#line 538 "ansic.y"
                        {(yyval.op) = PLUS_OP;}
#line 2514 "ansic.tab.c"
    break;

  case 25:
#line 539 "ansic.y"
                        {(yyval.op) = MINUS_OP;}
#line 2520 "ansic.tab.c"
    break;

  case 26:
#line 540 "ansic.y"
                        {(yyval.op) = TWOCOMP_OP;}
#line 2526 "ansic.tab.c"
    break;

  case 27:
#line 541 "ansic.y"
                        {(yyval.op) = NOT_OP;}
#line 2532 "ansic.tab.c"
    break;

  case 28:
#line 545 "ansic.y"
                                                                        {}
#line 2538 "ansic.tab.c"
    break;

  case 29:
#line 546 "ansic.y"
                                                        {}
#line 2544 "ansic.tab.c"
    break;

  case 30:
#line 550 "ansic.y"
                                                                                                                                {(yyval.sym) = (yyvsp[0].sym);}
#line 2550 "ansic.tab.c"
    break;

  case 31:
#line 551 "ansic.y"
                                                                                                {	std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																			symrec *s;
																			s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																			gencode(MULT_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																			(yyval.sym).name = name;
																			(yyval.sym).var = s;
																		}
#line 2562 "ansic.tab.c"
    break;

  case 32:
#line 558 "ansic.y"
                                                                                                {	std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																			symrec *s;
																			s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																			gencode(DIV_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																			(yyval.sym).name = name;
																			(yyval.sym).var = s;
																		}
#line 2574 "ansic.tab.c"
    break;

  case 33:
#line 565 "ansic.y"
                                                                                                {	std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																			symrec *s;
																			s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																			gencode(MOD_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																			(yyval.sym).name = name;
																			(yyval.sym).var = s;
																			}
#line 2586 "ansic.tab.c"
    break;

  case 34:
#line 575 "ansic.y"
                                                                                                                        {(yyval.sym) = (yyvsp[0].sym);}
#line 2592 "ansic.tab.c"
    break;

  case 35:
#line 576 "ansic.y"
                                                                                                {
																			std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																			symrec *s;
																			s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																			gencode(ADD_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																			(yyval.sym).name = name;
																			(yyval.sym).var = s;
																		}
#line 2605 "ansic.tab.c"
    break;

  case 36:
#line 584 "ansic.y"
                                                                                                {	std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																			symrec *s;
																			s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																			gencode(SUB_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																			(yyval.sym).name = name;
																			(yyval.sym).var = s;
																		}
#line 2617 "ansic.tab.c"
    break;

  case 37:
#line 594 "ansic.y"
                                                                                                                        {(yyval.sym) = (yyvsp[0].sym);}
#line 2623 "ansic.tab.c"
    break;

  case 38:
#line 595 "ansic.y"
                                                                                                {}
#line 2629 "ansic.tab.c"
    break;

  case 39:
#line 596 "ansic.y"
                                                                                                {}
#line 2635 "ansic.tab.c"
    break;

  case 40:
#line 600 "ansic.y"
                                                                                                                                {(yyval.sym) = (yyvsp[0].sym);}
#line 2641 "ansic.tab.c"
    break;

  case 41:
#line 601 "ansic.y"
                                                                                                {
																			symrec *s1 = (yyvsp[-2].sym).var, *s2 = (yyvsp[0].sym).var;
																			(yyval.sym).truelist = makelist(nextinstr);
																			gencode(IF_LT_IR, s1, s2, nullptr);
																			(yyval.sym).falselist = makelist(nextinstr);
																			gencode(GOTO_IR);
																		}
#line 2653 "ansic.tab.c"
    break;

  case 42:
#line 608 "ansic.y"
                                                                                                {
																			symrec *s1 = (yyvsp[-2].sym).var, *s2 = (yyvsp[0].sym).var;
																			(yyval.sym).truelist = makelist(nextinstr);
																			gencode(IF_GT_IR, s1, s2, nullptr);
																			(yyval.sym).falselist = makelist(nextinstr);
																			gencode(GOTO_IR);
																		}
#line 2665 "ansic.tab.c"
    break;

  case 43:
#line 615 "ansic.y"
                                                                                                {	
																			symrec *s1 = (yyvsp[-2].sym).var, *s2 = (yyvsp[0].sym).var;
																			(yyval.sym).truelist = makelist(nextinstr);
																			gencode(IF_LE_IR, s1, s2, nullptr);
																			(yyval.sym).falselist = makelist(nextinstr);
																			gencode(GOTO_IR);
																			}
#line 2677 "ansic.tab.c"
    break;

  case 44:
#line 622 "ansic.y"
                                                                                                {
																			symrec *s1 = (yyvsp[-2].sym).var, *s2 = (yyvsp[0].sym).var;
																			(yyval.sym).truelist = makelist(nextinstr);
																			gencode(IF_LT_IR, s1, s2, nullptr);
																			(yyval.sym).falselist = makelist(nextinstr);
																			gencode(GOTO_IR);
																		}
#line 2689 "ansic.tab.c"
    break;

  case 45:
#line 631 "ansic.y"
                {/*Retornar direccion de siguiente intruccion de IR*/
					(yyval.instr) = nextinstr;
				}
#line 2697 "ansic.tab.c"
    break;

  case 46:
#line 637 "ansic.y"
                                                                                                                        {(yyval.sym) = (yyvsp[0].sym);}
#line 2703 "ansic.tab.c"
    break;

  case 47:
#line 638 "ansic.y"
                                                                                                {}
#line 2709 "ansic.tab.c"
    break;

  case 48:
#line 639 "ansic.y"
                                                                                                {}
#line 2715 "ansic.tab.c"
    break;

  case 49:
#line 643 "ansic.y"
                                                                                                                        {(yyval.sym) = (yyvsp[0].sym);}
#line 2721 "ansic.tab.c"
    break;

  case 50:
#line 644 "ansic.y"
                                                                                                        {}
#line 2727 "ansic.tab.c"
    break;

  case 51:
#line 648 "ansic.y"
                                                                                                                                {(yyval.sym) = (yyvsp[0].sym);}
#line 2733 "ansic.tab.c"
    break;

  case 52:
#line 649 "ansic.y"
                                                                                                {}
#line 2739 "ansic.tab.c"
    break;

  case 53:
#line 653 "ansic.y"
                                                                                                                        {(yyval.sym) = (yyvsp[0].sym);}
#line 2745 "ansic.tab.c"
    break;

  case 54:
#line 654 "ansic.y"
                                                                                        {}
#line 2751 "ansic.tab.c"
    break;

  case 55:
#line 658 "ansic.y"
                                                                                                                        {(yyval.sym) = (yyvsp[0].sym);}
#line 2757 "ansic.tab.c"
    break;

  case 56:
#line 659 "ansic.y"
                                                                                        {
																			backpatch((yyvsp[-3].sym).truelist, (yyvsp[-1].instr));
																			(yyval.sym).truelist = (yyvsp[0].sym).truelist;
																			(yyval.sym).falselist = (yyvsp[-3].sym).falselist;
																			(yyval.sym).falselist->merge(*((yyvsp[0].sym).falselist));
																			(yyval.sym).typ = INTVAL;
																		}
#line 2769 "ansic.tab.c"
    break;

  case 57:
#line 669 "ansic.y"
                                                                                                                        {(yyval.sym) = (yyvsp[0].sym);}
#line 2775 "ansic.tab.c"
    break;

  case 58:
#line 670 "ansic.y"
                                                                                        {
																			backpatch((yyvsp[-3].sym).falselist, (yyvsp[-1].instr));
																			(yyval.sym).falselist = (yyvsp[0].sym).falselist;
																			(yyval.sym).truelist = (yyvsp[-3].sym).truelist;
																			(yyval.sym).truelist->merge(*((yyvsp[0].sym).truelist));
																			(yyval.sym).typ = INTVAL;
																		}
#line 2787 "ansic.tab.c"
    break;

  case 59:
#line 680 "ansic.y"
                                                                                                                        {(yyval.sym) = (yyvsp[0].sym);}
#line 2793 "ansic.tab.c"
    break;

  case 60:
#line 681 "ansic.y"
                                                                                {}
#line 2799 "ansic.tab.c"
    break;

  case 61:
#line 685 "ansic.y"
                                                                                                                        {	printf("assignment_expression : conditional_expression\n");
																			(yyval.sym) = (yyvsp[0].sym);
																		}
#line 2807 "ansic.tab.c"
    break;

  case 62:
#line 688 "ansic.y"
                                                                                {
																			printf("assignment_expression : unary_expression assignment_operator assignment_expression\n");
																			/*Verifica si hat saltos pendientes en assignment_expression
																			Si los hay, asigna el valor logico 0 o 1*/
																			if((yyvsp[0].sym).truelist || (yyvsp[0].sym).falselist){
																				std::string *name = newtemp(); /*Nueva variable tempotal*/
																				symrec *s1, *s0;
																				s0 = putsym(name, INTVAL | CONST_SPEC);
																				*(int*)(datablock+s0->offset) = 0;
																				name = newtemp();
																				s1 = putsym(name, INTVAL | CONST_SPEC);
																				*(int*)(datablock+s1->offset) = 1;
																				name = newtemp();
																				(yyvsp[0].sym).var = putsym(name, INTVAL | VAR_SPEC);
																				(yyvsp[0].sym).typ = INTVAL | VAR_SPEC;
																				(yyvsp[0].sym).name = name;
																				backpatch((yyvsp[0].sym).truelist, nextinstr);
																				gencode(STORE_IR, s1, nullptr, (yyvsp[0].sym).var);
																				gencode(GOTO_IR, nullptr, nullptr, nextinstr+2);
																				backpatch((yyvsp[0].sym).falselist, nextinstr);
																				gencode(STORE_IR, s0, nullptr, (yyvsp[0].sym).var);
																			}
																			switch((yyvsp[-1].asop)){
																				case EQ_ASSIGN_OP:
																					if(!isarray((yyvsp[-2].sym).typ))
																						gencode(STORE_IR, (yyvsp[0].sym).var, nullptr, (yyvsp[-2].sym).var);
																					break;
																				case MUL_ASSIGN_OP:
																					if(!isarray((yyvsp[-2].sym).typ)){
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																						gencode(MULT_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																					}
																					break;
																				case DIV_ASSIGN_OP:
																					if(!isarray((yyvsp[-2].sym).typ)){
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																						gencode(DIV_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																					}
																					break;
																				case MOD_ASSIGN_OP:
																					if(!isarray((yyvsp[-2].sym).typ)){
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																						gencode(MOD_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																					}
																					break;
																				case ADD_ASSIGN_OP:
																					if(!isarray((yyvsp[-2].sym).typ)){
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																						gencode(ADD_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																					}
																					break;
																				case SUB_ASSIGN_OP:
																					if(!isarray((yyvsp[-2].sym).typ)){
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																						gencode(SUB_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																					}
																					break;
																				case LEFT_ASSIGN_OP:
																					if(!isarray((yyvsp[-2].sym).typ)){
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																						gencode(LSHIFT_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																					}
																					break;
																				case RIGHT_ASSIGN_OP:
																					if(!isarray((yyvsp[-2].sym).typ)){
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																						gencode(RSHIFT_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																					}
																					break;
																				case AND_ASSIGN_OP:
																					if(!isarray((yyvsp[-2].sym).typ)){
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																						gencode(AND_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																					}
																					break;
																				case XOR_ASSIGN_OP:
																					if(!isarray((yyvsp[-2].sym).typ)){
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																						gencode(XOR_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																					}
																					break;
																				case OR_ASSIGN_OP:
																					if(!isarray((yyvsp[-2].sym).typ)){
																						std::string *name = newtemp(); /*Crear nueva variable temporal para resultado*/
																						symrec *s;
																						s = putsym(name, gettype((yyvsp[-2].sym).typ, (yyvsp[0].sym).typ) & ~CONST_SPEC | VAR_SPEC);
																						gencode(OR_IR, (yyvsp[-2].sym).var, (yyvsp[0].sym).var, s);
																						gencode(STORE_IR, s, nullptr, (yyvsp[-2].sym).var);
																					}
																					break;
																			}
																		}
#line 2931 "ansic.tab.c"
    break;

  case 63:
#line 810 "ansic.y"
                                                {(yyval.asop) = EQ_ASSIGN_OP;}
#line 2937 "ansic.tab.c"
    break;

  case 64:
#line 811 "ansic.y"
                                        {(yyval.asop) = MUL_ASSIGN_OP;}
#line 2943 "ansic.tab.c"
    break;

  case 65:
#line 812 "ansic.y"
                                        {(yyval.asop) = DIV_ASSIGN_OP;}
#line 2949 "ansic.tab.c"
    break;

  case 66:
#line 813 "ansic.y"
                                        {(yyval.asop) = MOD_ASSIGN_OP;}
#line 2955 "ansic.tab.c"
    break;

  case 67:
#line 814 "ansic.y"
                                        {(yyval.asop) = ADD_ASSIGN_OP;}
#line 2961 "ansic.tab.c"
    break;

  case 68:
#line 815 "ansic.y"
                                        {(yyval.asop) = SUB_ASSIGN_OP;}
#line 2967 "ansic.tab.c"
    break;

  case 69:
#line 816 "ansic.y"
                                        {(yyval.asop) = LEFT_ASSIGN_OP;}
#line 2973 "ansic.tab.c"
    break;

  case 70:
#line 817 "ansic.y"
                                        {(yyval.asop) = RIGHT_ASSIGN_OP;}
#line 2979 "ansic.tab.c"
    break;

  case 71:
#line 818 "ansic.y"
                                        {(yyval.asop) = AND_ASSIGN_OP;}
#line 2985 "ansic.tab.c"
    break;

  case 72:
#line 819 "ansic.y"
                                        {(yyval.asop) = XOR_ASSIGN_OP;}
#line 2991 "ansic.tab.c"
    break;

  case 73:
#line 820 "ansic.y"
                                                {(yyval.asop) = OR_ASSIGN_OP;}
#line 2997 "ansic.tab.c"
    break;

  case 74:
#line 824 "ansic.y"
                                                                                        {(yyval.sym) = (yyvsp[0].sym);}
#line 3003 "ansic.tab.c"
    break;

  case 75:
#line 825 "ansic.y"
                                                                        {}
#line 3009 "ansic.tab.c"
    break;

  case 76:
#line 829 "ansic.y"
                                                                                        {	printf("constant_expression : conditional_expression\n");
															(yyval.sym) = (yyvsp[0].sym);
														}
#line 3017 "ansic.tab.c"
    break;

  case 77:
#line 835 "ansic.y"
                                                                                {printf("declaration : declaration_specifiers ';'\n");}
#line 3023 "ansic.tab.c"
    break;

  case 78:
#line 836 "ansic.y"
                                                                {	printf("declaration : declaration_specifiers init_declarator_list ';'\n");
															std::list<VAR_DATA *>::iterator it;
															int typ = get_type((yyvsp[-2].sqlist));
															/*cout << "Declaring variables : " << endl;
															cout << "Type : " << typ << "\n";*/
															for(it = (yyvsp[-1].idlist)->begin(); it != (yyvsp[-1].idlist)->end(); it++){
																symrec *s;
																/*cout << *(*it)->name << endl;*/
																if(isarray((*it)->typ))
																	installarray((*it)->name,typ | VAR_SPEC | ((*it)->typ & ~0x1F), (*it)->val.intval);
																else
																	if(isfunction((*it)->typ))
																		s = install((*it)->name, typ | FUNC_SPEC | ((*it)->typ & ~0x1F));
																		else{
																			s = install((*it)->name, typ | VAR_SPEC | ((*it)->typ & ~0x1F));
																			if((*it)->init)
																				gencode(STORE_IR, (*it)->var, nullptr, s);
																		}
															}
														}
#line 3048 "ansic.tab.c"
    break;

  case 79:
#line 859 "ansic.y"
                                                                                        {	std::list<int> *newlist = new std::list<int>;
															newlist->push_back((yyvsp[0].scsp));
															(yyval.sqlist) = newlist;
														}
#line 3057 "ansic.tab.c"
    break;

  case 80:
#line 863 "ansic.y"
                                                                {	(yyval.sqlist) = (yyvsp[0].sqlist);
															(yyval.sqlist)->push_back((yyvsp[-1].scsp));
														}
#line 3065 "ansic.tab.c"
    break;

  case 81:
#line 866 "ansic.y"
                                                                                                {	std::list<int> *newlist = new std::list<int>;
															newlist->push_back((yyvsp[0].token.type));
															(yyval.sqlist) = newlist;
														}
#line 3074 "ansic.tab.c"
    break;

  case 82:
#line 870 "ansic.y"
                                                                        {	(yyval.sqlist) = (yyvsp[0].sqlist);
															(yyval.sqlist)->push_back((yyvsp[-1].token.type));
														}
#line 3082 "ansic.tab.c"
    break;

  case 83:
#line 873 "ansic.y"
                                                                                                {	std::list<int> *newlist = new std::list<int>;
															newlist->push_back((yyvsp[0].qual));
															(yyval.sqlist) = newlist;
														}
#line 3091 "ansic.tab.c"
    break;

  case 84:
#line 877 "ansic.y"
                                                                        {	(yyval.sqlist) = (yyvsp[0].sqlist);
															(yyval.sqlist)->push_back((yyvsp[-1].qual));
														}
#line 3099 "ansic.tab.c"
    break;

  case 85:
#line 883 "ansic.y"
                                                                                                {	std::list<VAR_DATA *> *newlist = new std::list<VAR_DATA *>;
															VAR_DATA *newstruc = (yyvsp[0].id_data);
															newlist->push_back(newstruc);
															(yyval.idlist) = newlist;
														}
#line 3109 "ansic.tab.c"
    break;

  case 86:
#line 888 "ansic.y"
                                                                        {	VAR_DATA *newstruc = (yyvsp[0].id_data);
															(yyval.idlist) = (yyvsp[-2].idlist);
															(yyval.idlist)->push_back(newstruc);
														}
#line 3118 "ansic.tab.c"
    break;

  case 87:
#line 895 "ansic.y"
                                                                                                {	(yyval.id_data) = (yyvsp[0].id_data);}
#line 3124 "ansic.tab.c"
    break;

  case 88:
#line 896 "ansic.y"
                                                                                {	(yyval.id_data) = (yyvsp[-2].id_data);
															(yyval.id_data)->init = 1;
															(yyval.id_data)->var = (yyvsp[0].sym).var;
														}
#line 3133 "ansic.tab.c"
    break;

  case 89:
#line 903 "ansic.y"
                                                                                                        {
															(yyval.scsp) = TYPENAME_SPEC;
														}
#line 3141 "ansic.tab.c"
    break;

  case 90:
#line 906 "ansic.y"
                                                                                                        {
															(yyval.scsp) = EXTERN_SPEC;
														}
#line 3149 "ansic.tab.c"
    break;

  case 91:
#line 909 "ansic.y"
                                                                                                        {
															(yyval.scsp) = STATIC_SPEC;
														}
#line 3157 "ansic.tab.c"
    break;

  case 92:
#line 912 "ansic.y"
                                                                                                        {
															(yyval.scsp) = AUTO_SPEC;
														}
#line 3165 "ansic.tab.c"
    break;

  case 93:
#line 915 "ansic.y"
                                                                                                        {
															(yyval.scsp) = REGISTER_SPEC;
														}
#line 3173 "ansic.tab.c"
    break;

  case 94:
#line 921 "ansic.y"
                                                                {(yyval.token.type) = VOID_SPEC;}
#line 3179 "ansic.tab.c"
    break;

  case 95:
#line 922 "ansic.y"
                                                                {(yyval.token.type) = CHAR_SPEC;}
#line 3185 "ansic.tab.c"
    break;

  case 96:
#line 923 "ansic.y"
                                                                {(yyval.token.type) = SHORT_SPEC;}
#line 3191 "ansic.tab.c"
    break;

  case 97:
#line 924 "ansic.y"
                                                                {(yyval.token.type) = INT_SPEC;}
#line 3197 "ansic.tab.c"
    break;

  case 98:
#line 925 "ansic.y"
                                                                {(yyval.token.type) = LONG_SPEC;}
#line 3203 "ansic.tab.c"
    break;

  case 99:
#line 926 "ansic.y"
                                                                {(yyval.token.type) = FLOAT_SPEC;}
#line 3209 "ansic.tab.c"
    break;

  case 100:
#line 927 "ansic.y"
                                                                {(yyval.token.type) = DOUBLE_SPEC;}
#line 3215 "ansic.tab.c"
    break;

  case 101:
#line 928 "ansic.y"
                                                                {(yyval.token.type) = SIGNED_SPEC;}
#line 3221 "ansic.tab.c"
    break;

  case 102:
#line 929 "ansic.y"
                                                                {(yyval.token.type) = UNSIGNED_SPEC;}
#line 3227 "ansic.tab.c"
    break;

  case 103:
#line 930 "ansic.y"
                                                {}
#line 3233 "ansic.tab.c"
    break;

  case 104:
#line 931 "ansic.y"
                                                        {(yyval.token.type) = ENUM_SPEC;}
#line 3239 "ansic.tab.c"
    break;

  case 105:
#line 932 "ansic.y"
                                                                {(yyval.token.type) = TYPENAME_SPEC;}
#line 3245 "ansic.tab.c"
    break;

  case 114:
#line 956 "ansic.y"
                                                                                {
																(yyval.sqlist) = (yyvsp[0].sqlist);
																(yyval.sqlist)->push_back((yyvsp[-1].token.type));
															}
#line 3254 "ansic.tab.c"
    break;

  case 115:
#line 960 "ansic.y"
                                                                                                        {
																std::list<int> *newlist = new std::list<int>;
																newlist->push_back((yyvsp[0].token.type));
																(yyval.sqlist) = newlist;
															}
#line 3264 "ansic.tab.c"
    break;

  case 116:
#line 965 "ansic.y"
                                                                                {
																(yyval.sqlist) = (yyvsp[0].sqlist);
																(yyval.sqlist)->push_back((yyvsp[-1].qual));
															}
#line 3273 "ansic.tab.c"
    break;

  case 117:
#line 969 "ansic.y"
                                                                                                        {
																std::list<int> *newlist = new std::list<int>;
																newlist->push_back((yyvsp[0].qual));
																(yyval.sqlist) = newlist;
															}
#line 3283 "ansic.tab.c"
    break;

  case 130:
#line 1004 "ansic.y"
                                                                                                        {
															(yyval.qual) = CONST_SPEC;
														}
#line 3291 "ansic.tab.c"
    break;

  case 131:
#line 1007 "ansic.y"
                                                                                                        {
															(yyval.qual) = VOLATILE_SPEC;
														}
#line 3299 "ansic.tab.c"
    break;

  case 132:
#line 1013 "ansic.y"
                                                                                        {(yyval.id_data) = (yyvsp[0].id_data);}
#line 3305 "ansic.tab.c"
    break;

  case 133:
#line 1014 "ansic.y"
                                                                                                {(yyval.id_data) = (yyvsp[0].id_data);}
#line 3311 "ansic.tab.c"
    break;

  case 134:
#line 1018 "ansic.y"
                                                                                                {
															/*printf("IDENTIFIER = %s\n", $1);*/
															printf("direct_declarator : IDENTIFIER\n");
															VAR_DATA *newsym = new VAR_DATA();
															newsym->name = new string((yyvsp[0].token.name));
															(yyval.id_data) = newsym;
														}
#line 3323 "ansic.tab.c"
    break;

  case 135:
#line 1025 "ansic.y"
                                                                                        {printf("direct_declarator : '(' declarator ')'\n");}
#line 3329 "ansic.tab.c"
    break;

  case 136:
#line 1026 "ansic.y"
                                                                {printf("direct_declarator : direct_declarator '[' constant_expression ']'\n");}
#line 3335 "ansic.tab.c"
    break;

  case 137:
#line 1027 "ansic.y"
                                                                                        {printf("direct_declarator : direct_declarator '(' parameter_type_list ')'\n");}
#line 3341 "ansic.tab.c"
    break;

  case 138:
#line 1028 "ansic.y"
                                                                {	printf("direct_declarator : direct_declarator '(' parameter_type_list ')'\n");
															(yyval.id_data) = (yyvsp[-3].id_data);
															(yyval.id_data)->typ |= FUNC_SPEC;
															(yyval.id_data)->arglist = (yyvsp[-1].idlist);
															(yyval.id_data)->init = 0;
														}
#line 3352 "ansic.tab.c"
    break;

  case 139:
#line 1034 "ansic.y"
                                                                        {printf("direct_declarator : direct_declarator '(' identifier_list ')'\n");}
#line 3358 "ansic.tab.c"
    break;

  case 140:
#line 1035 "ansic.y"
                                                                                        {
															printf("direct_declarator : direct_declarator '(' ')'\n");
															(yyval.id_data) = (yyvsp[-2].id_data);
															(yyval.id_data)->typ |= FUNC_SPEC;
														}
#line 3368 "ansic.tab.c"
    break;

  case 147:
#line 1056 "ansic.y"
                                                                                                                {(yyval.idlist) = (yyvsp[0].idlist);}
#line 3374 "ansic.tab.c"
    break;

  case 148:
#line 1057 "ansic.y"
                                                                                                {}
#line 3380 "ansic.tab.c"
    break;

  case 149:
#line 1061 "ansic.y"
                                                                                                        {
																	std::list<VAR_DATA *> *newlist = new std::list<VAR_DATA *>;
																	VAR_DATA *newstruc = new VAR_DATA();
																	*newstruc = (yyvsp[0].sym);
																	newlist->push_back(newstruc);
																	(yyval.idlist) = newlist;
																}
#line 3392 "ansic.tab.c"
    break;

  case 150:
#line 1068 "ansic.y"
                                                                                        {
																	(yyval.idlist) = (yyvsp[-2].idlist);
																	VAR_DATA *newstruc = new VAR_DATA();
																	*newstruc = (yyvsp[0].sym);
																	(yyval.idlist)->push_back(newstruc);
																}
#line 3403 "ansic.tab.c"
    break;

  case 151:
#line 1077 "ansic.y"
                                                                                                {
																	(yyval.sym).name = (yyvsp[0].id_data)->name;
																	if(!isarray((yyvsp[0].id_data)->typ))
																		(yyval.sym).typ = get_type((yyvsp[-1].sqlist));
																	else
																		(yyval.sym).typ = (yyval.sym).typ = get_type((yyvsp[-1].sqlist)) | ARRAY_SPEC;
																}
#line 3415 "ansic.tab.c"
    break;

  case 152:
#line 1084 "ansic.y"
                                                                                {}
#line 3421 "ansic.tab.c"
    break;

  case 153:
#line 1085 "ansic.y"
                                                                                                        {}
#line 3427 "ansic.tab.c"
    break;

  case 156:
#line 1094 "ansic.y"
                                                                                                        {	printf("type_name : specifier_qualifier_list\n");
																	(yyval.typ) = get_type((yyvsp[0].sqlist));
																}
#line 3435 "ansic.tab.c"
    break;

  case 157:
#line 1097 "ansic.y"
                                                                                {printf("type_name : specifier_qualifier_list abstract_declarator\n");}
#line 3441 "ansic.tab.c"
    break;

  case 170:
#line 1119 "ansic.y"
                                                                                                        {(yyval.sym) = (yyvsp[0].sym);}
#line 3447 "ansic.tab.c"
    break;

  case 171:
#line 1120 "ansic.y"
                                                                                                        {}
#line 3453 "ansic.tab.c"
    break;

  case 172:
#line 1121 "ansic.y"
                                                                                                {}
#line 3459 "ansic.tab.c"
    break;

  case 176:
#line 1132 "ansic.y"
                                                                                        {
														(yyval.lists) = (yyvsp[0].lists);
														(yyval.lists).nextlist = NULL;
													}
#line 3468 "ansic.tab.c"
    break;

  case 177:
#line 1136 "ansic.y"
                                                                                                        {
														enter_scope();
													}
#line 3476 "ansic.tab.c"
    break;

  case 178:
#line 1139 "ansic.y"
                                                                                {
		  												printf("statement : compound_statement\n");
														printlocalvars();
														exit_scope();
														(yyval.lists) = (yyvsp[0].lists);
											 		}
#line 3487 "ansic.tab.c"
    break;

  case 179:
#line 1145 "ansic.y"
                                                                                {
														(yyval.lists).nextlist = NULL;
														(yyval.lists).breaklist = NULL;
														(yyval.lists).caselist = NULL;
													}
#line 3497 "ansic.tab.c"
    break;

  case 180:
#line 1150 "ansic.y"
                                                                                {
														(yyval.lists) = (yyvsp[0].lists);
													}
#line 3505 "ansic.tab.c"
    break;

  case 181:
#line 1153 "ansic.y"
                                                                                {
														(yyval.lists) = (yyvsp[0].lists);
													}
#line 3513 "ansic.tab.c"
    break;

  case 182:
#line 1156 "ansic.y"
                                                                                        {
														(yyval.lists) = (yyvsp[0].lists);
													}
#line 3521 "ansic.tab.c"
    break;

  case 183:
#line 1162 "ansic.y"
                                                                                {}
#line 3527 "ansic.tab.c"
    break;

  case 184:
#line 1163 "ansic.y"
                                                                {	
														(yyval.lists).breaklist = (yyvsp[0].lists).breaklist;
														if(!isconstant((yyvsp[-3].sym).typ))
															yyerror("Error : CASE expression must be constant\n");
														if(!isintegral((yyvsp[-3].sym).typ))
															yyerror("Error : CASE expression must be integral constant\n");
														(yyval.lists).caselist = makecaselist((yyvsp[-3].sym).val, (yyvsp[-3].sym).typ, (yyvsp[-1].instr));
													}
#line 3540 "ansic.tab.c"
    break;

  case 185:
#line 1171 "ansic.y"
                                                                                {	
														(yyval.lists).breaklist = (yyvsp[0].lists).breaklist;
														(yyval.lists).caselist = makecaselist((yyvsp[-1].instr));
													}
#line 3549 "ansic.tab.c"
    break;

  case 186:
#line 1178 "ansic.y"
                                                                                                {	printf("compound_statement : '{' '}'\n");
														(yyval.lists).breaklist = NULL;
														(yyval.lists).nextlist = NULL;
													}
#line 3558 "ansic.tab.c"
    break;

  case 187:
#line 1182 "ansic.y"
                                                                                {	printf("compound_statement : '{' statement_list '}'\n");
														(yyval.lists) = (yyvsp[-1].lists);
													}
#line 3566 "ansic.tab.c"
    break;

  case 188:
#line 1185 "ansic.y"
                                                                                {	printf("compound_statement : '{' declaration_list '}'\n");
														(yyval.lists).breaklist = NULL;
														(yyval.lists).nextlist = NULL;
													}
#line 3575 "ansic.tab.c"
    break;

  case 189:
#line 1189 "ansic.y"
                                                                {	printf("compound_statement : '{' declaration_list statement_list '}'\n");
														(yyval.lists) = (yyvsp[-1].lists);
													}
#line 3583 "ansic.tab.c"
    break;

  case 192:
#line 1200 "ansic.y"
                                                                                                {(yyval.lists) = (yyvsp[0].lists);}
#line 3589 "ansic.tab.c"
    break;

  case 193:
#line 1201 "ansic.y"
                                                                        {
														backpatch((yyvsp[-2].lists).nextlist, (yyvsp[-1].instr));
														(yyval.lists) = (yyvsp[-2].lists);
														(yyval.lists).nextlist = (yyvsp[0].lists).nextlist;
														(yyval.lists).breaklist = merge((yyvsp[-2].lists).breaklist, (yyvsp[0].lists).breaklist);
														(yyval.lists).caselist = merge((yyvsp[-2].lists).caselist, (yyvsp[0].lists).caselist);
													}
#line 3601 "ansic.tab.c"
    break;

  case 194:
#line 1211 "ansic.y"
                                                                                                {	printf("expression_statement : ';'\n");
														(yyval.sym).truelist = nullptr;
														(yyval.sym).falselist = nullptr;
													}
#line 3610 "ansic.tab.c"
    break;

  case 195:
#line 1215 "ansic.y"
                                                                                        {	printf("expression_statement : expression ';'\n");
														(yyval.sym) = (yyvsp[-1].sym);
													}
#line 3618 "ansic.tab.c"
    break;

  case 196:
#line 1220 "ansic.y"
                                                                        {
														(yyval.sym) = (yyvsp[0].sym);
														/*Verificar si expression es comparacion u operacion logica*/
														if((yyvsp[0].sym).truelist == nullptr || (yyvsp[0].sym).falselist == nullptr){
															std::string *name = newtemp(); /*Nueva variable temporal*/
															symrec *s0;
															s0 = putsym(name, INTVAL | CONST_SPEC);
															*(int *)(datablock+s0->offset) = 0;
															(yyval.sym).truelist = makelist(nextinstr);
															gencode(IF_NE_IR, (yyvsp[0].sym).var, s0, nullptr);
															(yyval.sym).falselist = makelist(nextinstr);
															gencode(GOTO_IR);
														}
													}
#line 3637 "ansic.tab.c"
    break;

  case 197:
#line 1235 "ansic.y"
              { /*Retornar direccion de siguiente instruccion de IR y dejar hueco para poner la instruccion de salto*/
				(yyval.lists).nextlist = makelist(nextinstr);
				gencode(GOTO_IR);
				}
#line 3646 "ansic.tab.c"
    break;

  case 198:
#line 1242 "ansic.y"
                                                                                                                        {
																						backpatch((yyvsp[-3].sym).truelist, (yyvsp[-1].instr));
																						(yyval.lists).nextlist = merge((yyvsp[-3].sym).falselist, (yyvsp[0].lists).nextlist);
																						(yyval.lists).breaklist = (yyvsp[0].lists).breaklist;
																					}
#line 3656 "ansic.tab.c"
    break;

  case 199:
#line 1247 "ansic.y"
                                                                                                                        {
																						backpatch((yyvsp[-7].sym).truelist, (yyvsp[-5].instr));
																						backpatch((yyvsp[-7].sym).falselist, (yyvsp[-1].instr));
																						(yyval.lists).nextlist = merge((yyvsp[-4].lists).nextlist, (yyvsp[-2].lists).nextlist, (yyvsp[0].lists).nextlist);
																						(yyval.lists).breaklist = merge((yyvsp[-4].lists).breaklist, (yyvsp[0].lists).breaklist);
																					}
#line 3667 "ansic.tab.c"
    break;

  case 200:
#line 1253 "ansic.y"
                                                                                                                                {
																						if(isintegral((yyvsp[-2].sym).typ))
																							yyerror("Error : switch expression must be integral\n");
																						(yyvsp[0].lists).breaklist = merge((yyvsp[0].lists).breaklist, makelist(nextinstr));
																						gencode(GOTO_IR);
																						backpatch((yyvsp[-4].lists).nextlist, nextinstr);
																						std::list<CASE_DATA *>::iterator it;
																						if((yyvsp[0].lists).caselist != NULL){
																							for(it = (yyvsp[0].lists).caselist->begin(); it != (yyvsp[0].lists).caselist->end(); it++){
																								int addr = (*it)->addr;
																								int typ = (*it)->typ;
																								if(typ == VOIDVAL)
																									gencode(GOTO_IR, addr);
																								else{
																									std::string *name = newtemp();
																									symrec *s = putsym(name, INTVAL | CONST_SPEC);
																									symrec *s1 = (yyvsp[-2].sym).var;
																									*(int *)((char *)datablock+s->offset) = (*it)->val.intval;
																									if(isconstant((yyvsp[-2].sym).typ)){
																										name = newtemp();
																										s1 = putsym(name, INTVAL | CONST_SPEC);
																										*(int *)((char *)datablock+s1->offset) = (yyvsp[-2].sym).val.intval;
																									}
																									gencode(IF_EQ_IR, s, s1, addr);
																								}
																							}
																						}
																						backpatch((yyvsp[0].lists).breaklist, nextinstr);
																						(yyval.lists).breaklist = NULL;
																						(yyval.lists).nextlist = NULL;
																					}
#line 3703 "ansic.tab.c"
    break;

  case 201:
#line 1287 "ansic.y"
                                                                                                                        {	printf("iteration_statement : WHILE '(' expression ')' statement\n");
																						backpatch((yyvsp[0].lists).nextlist, (yyvsp[-5].instr));
																						backpatch((yyvsp[-3].sym).truelist, (yyvsp[-1].instr));
																						(yyval.lists).nextlist = (yyvsp[-3].sym).falselist;
																						gencode(GOTO_IR, (yyvsp[-5].instr));
																						backpatch((yyvsp[0].lists).breaklist, nextinstr);
																						(yyval.lists).breaklist = NULL;
																					}
#line 3716 "ansic.tab.c"
    break;

  case 202:
#line 1295 "ansic.y"
                                                                                                                {	printf("iteration_statement : DO statement WHILE '(' expression ')' ';'\n");
																						backpatch((yyvsp[-2].sym).truelist, (yyvsp[-7].instr));
																						backpatch((yyvsp[-6].lists).nextlist, (yyvsp[-4].instr));
																						backpatch((yyvsp[-6].lists).breaklist, nextinstr);
																						(yyval.lists).breaklist = NULL;
																						(yyval.lists).nextlist = (yyvsp[-2].sym).falselist;
																					}
#line 3728 "ansic.tab.c"
    break;

  case 203:
#line 1302 "ansic.y"
                                                                                                {	printf("iteration_statement : FOR '(' expression_statement expression_statement ')' statement\n");
																						backpatch((yyvsp[-3].sym).truelist, (yyvsp[-2].instr));
																						backpatch((yyvsp[0].lists).nextlist, (yyvsp[-4].instr));
																						(yyval.lists).nextlist = (yyvsp[-3].sym).falselist;
																						gencode(GOTO_IR, (yyvsp[-4].instr));
																						backpatch((yyvsp[0].lists).breaklist, nextinstr);
																						(yyval.lists).breaklist = NULL;
																					}
#line 3741 "ansic.tab.c"
    break;

  case 204:
#line 1311 "ansic.y"
                                                                                                                                                        {	printf("iteration_statement : FOR '(' expression_statement expression_statement expression ')' statement\n");
	  																					backpatch((yyvsp[-6].sym).truelist, (yyvsp[-1].instr));	/*Completar saltos en verdadero de comparacion a N3*/
																						backpatch((yyvsp[0].lists).nextlist, (yyvsp[-5].instr));	/*Completar saltos de statement a N2*/
																						backpatch((yyvsp[-2].lists).nextlist, (yyvsp[-7].instr));		/*Completar saltos de Ma N1*/
																						(yyval.lists).nextlist = (yyvsp[-6].sym).falselist;		/*Propagar saltos en falso de comparacion*/
																						gencode(GOTO_IR, (yyvsp[-5].instr));			/*Insertar salto a N2*/
																						backpatch((yyvsp[0].lists).breaklist, nextinstr);
																						(yyval.lists).breaklist = NULL;
																					}
#line 3755 "ansic.tab.c"
    break;

  case 205:
#line 1323 "ansic.y"
                                                                                                                                                {}
#line 3761 "ansic.tab.c"
    break;

  case 206:
#line 1324 "ansic.y"
                                                                                                                                                        {}
#line 3767 "ansic.tab.c"
    break;

  case 207:
#line 1325 "ansic.y"
                                                                                                                                                                {
																						(yyval.lists).breaklist = makelist(nextinstr);
																						(yyval.lists).nextlist = NULL;
																						(yyval.lists).caselist = NULL;
																						gencode(GOTO_IR);
																					}
#line 3778 "ansic.tab.c"
    break;

  case 208:
#line 1331 "ansic.y"
                                                                                                                                                        {
																						gencode(RET_IR);
																						(yyval.lists).breaklist = NULL;
																						(yyval.lists).nextlist = NULL;
																						(yyval.lists).caselist = NULL;
																					}
#line 3789 "ansic.tab.c"
    break;

  case 209:
#line 1337 "ansic.y"
                                                                                                                                                {
																						gencode(RET_IR, (yyvsp[-1].sym).var, nullptr, nullptr);
																						(yyval.lists).breaklist = NULL;
																						(yyval.lists).nextlist = NULL;
																						(yyval.lists).caselist = NULL;
																					}
#line 3800 "ansic.tab.c"
    break;

  case 210:
#line 1346 "ansic.y"
                                                                        {printf("translation_unit--external_declaration	\n");}
#line 3806 "ansic.tab.c"
    break;

  case 211:
#line 1347 "ansic.y"
                                                        {printf("translation_unit--translation_unit external_declaration	\n");}
#line 3812 "ansic.tab.c"
    break;

  case 212:
#line 1351 "ansic.y"
                                        {printf("external declaration--function_definition\n");}
#line 3818 "ansic.tab.c"
    break;

  case 213:
#line 1352 "ansic.y"
                                                {printf("external declaration--declaration\n");}
#line 3824 "ansic.tab.c"
    break;

  case 214:
#line 1356 "ansic.y"
                                                                                        {printf("function_definition : declaration_specifiers declarator declaration_list compound_statement\n");}
#line 3830 "ansic.tab.c"
    break;

  case 215:
#line 1357 "ansic.y"
                                                                                                                                {
																					int typ = get_type((yyvsp[-1].sqlist)) | (yyvsp[0].id_data)->typ;
																					curr_func = install((yyvsp[0].id_data)->name, typ);
																					gencode(PROC_IR, curr_func);
																					localsyms = new symboltable();
																					enter_scope();
																					installarg((yyvsp[0].id_data)->arglist);
																					/*Iniciar nueva tabla de etiquetas*/
																					lab_table.clear();
																					setargs();
																				}
#line 3846 "ansic.tab.c"
    break;

  case 216:
#line 1368 "ansic.y"
                                                                                                                                        {
																					
																					printf("function_definition : declaration_specifiers declarator compound_statement\n");
																					printlocalvars();
																					exit_scope();
																					curr_func->func_desc.sym_table = localsyms;
																					gencode(ENDPROC_IR, curr_func);
																				}
#line 3859 "ansic.tab.c"
    break;

  case 217:
#line 1376 "ansic.y"
                                                                                                                {printf("function_definition : declarator declaration_list compound_statement\n");}
#line 3865 "ansic.tab.c"
    break;

  case 218:
#line 1377 "ansic.y"
                                                                                                                                                {
																					int typ = (yyvsp[0].id_data)->typ;
																					curr_func = install((yyvsp[0].id_data)->name, typ);
																					gencode(PROC_IR, curr_func);
																					localsyms = new symboltable();
																					enter_scope();
																					/*Iniciar nueva tabla de etiquetas*/
																					lab_table.clear();
																					setargs();
																				}
#line 3880 "ansic.tab.c"
    break;

  case 219:
#line 1387 "ansic.y"
                                                                                                                                        {
		  																			printf("function_definition : declarator compound_statement\n");
																					printlocalvars();
																					exit_scope();
																					curr_func->func_desc.sym_table = localsyms;
																					gencode(ENDPROC_IR, curr_func);
																				}
#line 3892 "ansic.tab.c"
    break;


#line 3896 "ansic.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1396 "ansic.y"


void yyerror(const char *message){
    printf("\nError: %s at line %d clumn %d\n",message, yylloc.first_line+1, yylloc.first_column+1);
    exit(1);
}


int main(int argc, char *argv[]){

	string fname;	/*Para guardar nombre de archivo compilandose*/
	/*Crear tabla de simbolos globales*/
	sym_table = new symboltable();
	cout<<"Compilador de C version 0.3\n";
	if(argc > 1){
		yyin = fopen(argv[1],"r");
		fname = argv[1];
	}
	else{
		cout<<"Uso: "<< argv[0] <<" <filename>\n";
		return (0);
	}
	yyparse();
	printvars();
	print_icode();
	print_code(fname);
	return 0;
}
