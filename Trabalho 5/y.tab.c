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
#line 1 "mini_js.y"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Atributos {
    vector<string> c;
};

#define YYSTYPE Atributos

int yylex();
int yyparse();
void yyerror( const char* );

vector<string> concatena( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, string b );

string gera_label( string prefixo );

vector<string> resolve_enderecos( vector<string> );

void print( vector<string> );

void atributos( Atributos );
void attr( Atributos );

string trim( char* );
vector<string> split( string );

vector<string> aux;
map<string, int> vars;

vector<string> funcs;

int linha = 1;
int qtd_pars = 0;

vector<vector<string>> elements;
vector<vector<string>> pars;


#line 119 "y.tab.c"

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
    ID = 258,
    DOUBLE = 259,
    STRING = 260,
    IG = 261,
    MAIG = 262,
    MEIG = 263,
    TRUE = 264,
    FALSE = 265,
    LET = 266,
    VAR = 267,
    CONST = 268,
    IF = 269,
    ELSE = 270,
    FOR = 271,
    WHILE = 272,
    FUNCTION = 273,
    FUNC_ANON = 274,
    RETURN = 275,
    ASM = 276,
    APS = 277,
    ARROW = 278
  };
#endif
/* Tokens.  */
#define ID 258
#define DOUBLE 259
#define STRING 260
#define IG 261
#define MAIG 262
#define MEIG 263
#define TRUE 264
#define FALSE 265
#define LET 266
#define VAR 267
#define CONST 268
#define IF 269
#define ELSE 270
#define FOR 271
#define WHILE 272
#define FUNCTION 273
#define FUNC_ANON 274
#define RETURN 275
#define ASM 276
#define APS 277
#define ARROW 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
typedef yytype_uint8 yy_state_t;

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   516

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

#define YYUNDEFTOK  2
#define YYMAXUTOK   278


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
       2,     2,     2,     2,     2,     2,     2,    31,     2,     2,
      33,    34,    29,    27,    35,    28,    40,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    32,
      25,    24,    26,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    65,    65,    68,    71,    72,    75,    76,    77,    78,
      79,    82,    84,    87,    90,    96,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   120,   121,   124,   127,   132,   133,   134,   137,
     140,   165,   168,   171,   174,   179,   182,   185,   186,   187,
     188,   191,   192,   195,   196,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   210,   211,   212,   213,   216,   223,
     226,   230,   236,   242,   243,   246,   247,   250,   251,   252
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "DOUBLE", "STRING", "IG", "MAIG",
  "MEIG", "TRUE", "FALSE", "LET", "VAR", "CONST", "IF", "ELSE", "FOR",
  "WHILE", "FUNCTION", "FUNC_ANON", "RETURN", "ASM", "APS", "ARROW", "'='",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "';'", "'('", "')'",
  "','", "'{'", "'}'", "'['", "']'", "'.'", "':'", "$accept", "RAIZ", "S",
  "CMDs", "CMD", "E", "D", "D_", "B", "B_", "D_LINHA", "D_LINHA_", "LV_",
  "LVALUE", "P", "O", "ATRIB", "F", "CF", "ARRAY", "FA", "FARROW", "P_",
  "ELS", "H", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    61,    60,    62,    43,    45,    42,
      47,    37,    59,    40,    41,    44,   123,   125,    91,    93,
      46,    58
};
# endif

#define YYPACT_NINF (-106)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-78)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     166,     9,  -106,  -106,  -106,  -106,    13,   -20,   -13,    24,
      30,     4,   282,    72,   222,     0,    93,    81,  -106,  -106,
     166,   431,  -106,    45,   -16,  -106,  -106,  -106,  -106,  -106,
    -106,    59,    51,   242,  -106,    52,    50,    63,   282,   166,
     282,    56,    -1,   202,    58,  -106,    -4,   446,    65,  -106,
     373,    49,  -106,    64,  -106,   306,    61,  -106,  -106,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,  -106,
     282,   262,   282,   282,   101,  -106,   282,  -106,  -106,   336,
      71,  -106,    13,   282,   388,   282,   402,    33,   282,    72,
     130,  -106,  -106,  -106,   202,  -106,  -106,  -106,   282,  -106,
     282,  -106,   473,   473,   473,   473,   473,    10,    10,  -106,
    -106,  -106,   485,  -106,    74,   485,   299,    32,   485,   282,
    -106,  -106,   485,   202,   458,   202,   202,    75,   347,  -106,
      -6,    69,  -106,   362,  -106,  -106,    32,  -106,  -106,    95,
     282,  -106,  -106,   202,    72,  -106,   110,  -106,   202,   417,
    -106,  -106,  -106,  -106,   202,  -106
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    46,    55,    56,    57,    58,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       5,     0,    52,    28,    29,    30,    31,    60,    61,    62,
      63,     0,     0,     0,    46,     0,    33,    35,     0,     0,
       0,     0,    44,     0,     0,    40,    46,     0,     0,    78,
       0,     0,    39,     0,    69,    76,     0,     1,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       0,     0,     0,     0,     0,    45,     0,     7,    65,    74,
       0,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    70,    38,     0,     9,    79,    59,     0,    51,
       0,    68,    20,    18,    19,    16,    17,    22,    23,    21,
      24,    25,    26,    67,     0,    27,     0,    50,    72,     0,
      64,    32,    34,     0,     0,     0,     0,     0,    43,    42,
      46,     0,    71,    54,    75,    66,    49,    48,    73,    11,
       0,    12,    14,     0,     0,    36,     0,    47,     0,     0,
      15,    41,    53,    10,     0,    13
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -106,  -106,  -106,   -11,     5,   -12,    35,  -106,   -80,   -32,
      -7,   -79,  -106,    -5,  -105,  -106,   -28,  -106,  -106,  -106,
    -106,  -106,   -53,    14,  -106
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    17,    18,    19,    91,    21,    35,    36,    92,    22,
      44,    45,    23,    24,    75,    25,    53,    26,    27,    28,
      29,    30,    80,    56,    31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,    37,    50,    51,    55,    20,    48,    42,    72,    58,
     129,    93,   137,    38,   132,    32,    34,   -77,   114,   -77,
      39,    79,    73,    88,    74,    20,    84,    33,    86,    33,
      32,   147,   -77,    41,    89,    98,    42,    52,    43,    66,
      67,    68,    33,   139,    85,   141,   142,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    40,   112,    79,
     115,   116,    93,   150,   118,   151,   138,   126,   153,    70,
      73,   122,    74,   124,   155,    42,   128,    37,    71,   131,
     127,    57,    76,    77,    81,    82,   133,    83,    55,    87,
      98,    93,    94,    93,    93,    20,    46,     2,     3,    96,
     101,    99,     4,     5,   117,   120,   145,    79,   135,   143,
     148,    93,    11,    51,   134,    13,    93,   121,   152,     0,
       0,     0,    93,     0,     0,     0,    14,     0,   149,    15,
       0,    16,    54,   130,     2,     3,     0,     0,     0,     4,
       5,     6,     0,     0,     7,     0,     8,     9,    10,    11,
      12,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     0,    15,    52,    16,     1,
       2,     3,     0,     0,     0,     4,     5,     6,     0,     0,
       7,     0,     8,     9,    10,    11,    12,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       0,     0,    15,     0,    16,     1,     2,     3,     0,     0,
       0,     4,     5,     6,     0,     0,     7,     0,     8,     9,
      10,    11,    12,     0,    13,    46,     2,     3,     0,     0,
       0,     4,     5,     0,     0,    14,     0,     0,    90,     0,
      16,    11,     0,     0,    13,    46,     2,     3,     0,     0,
       0,     4,     5,     0,     0,    14,    49,     0,    15,     0,
      16,    11,     0,     0,    13,    46,     2,     3,     0,     0,
       0,     4,     5,     0,     0,    14,    78,     0,    15,     0,
      16,    11,     0,     0,    13,    46,     2,     3,     0,     0,
       0,     4,     5,     0,     0,    14,   113,     0,    15,     0,
      16,    11,     0,     0,    13,    59,    60,    61,     0,     0,
       0,     0,    59,    60,    61,    14,     0,     0,    15,     0,
      16,     0,     0,     0,    62,    63,    64,    65,    66,    67,
      68,    62,    63,    64,    65,    66,    67,    68,   136,     0,
       0,   100,    59,    60,    61,     0,     0,     0,     0,     0,
       0,     0,     0,    59,    60,    61,     0,     0,     0,     0,
       0,    62,    63,    64,    65,    66,    67,    68,    59,    60,
      61,   119,    62,    63,    64,    65,    66,    67,    68,    59,
      60,    61,   144,     0,     0,     0,     0,    62,    63,    64,
      65,    66,    67,    68,    59,    60,    61,   146,    62,    63,
      64,    65,    66,    67,    68,     0,     0,    97,    59,    60,
      61,     0,     0,    62,    63,    64,    65,    66,    67,    68,
       0,     0,   123,    59,    60,    61,     0,    62,    63,    64,
      65,    66,    67,    68,     0,     0,   125,    59,    60,    61,
       0,     0,    62,    63,    64,    65,    66,    67,    68,     0,
       0,   154,    59,    60,    61,     0,    62,    63,    64,    65,
      66,    67,    68,    69,    59,    60,    61,     0,     0,     0,
       0,    62,    63,    64,    65,    66,    67,    68,    95,   -78,
     -78,   -78,     0,    62,    63,    64,    65,    66,    67,    68,
     140,    59,    60,    61,     0,     0,     0,     0,   -78,   -78,
      64,    65,    66,    67,    68,     0,     0,     0,     0,     0,
      62,    63,    64,    65,    66,    67,    68
};

static const yytype_int16 yycheck[] =
{
      12,     6,    14,     3,    16,     0,    13,     3,    24,    20,
      89,    43,   117,    33,    94,    21,     3,    23,    71,    23,
      33,    33,    38,    24,    40,    20,    38,    33,    40,    33,
      21,   136,    23,     3,    35,    41,     3,    37,    34,    29,
      30,    31,    33,   123,    39,   125,   126,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    33,    70,    71,
      72,    73,    94,   143,    76,   144,   119,    34,   148,    24,
      38,    83,    40,    85,   154,     3,    88,    82,    33,    90,
      87,     0,    23,    32,    32,    35,    98,    24,   100,    33,
      41,   123,    34,   125,   126,    90,     3,     4,     5,    34,
      39,    37,     9,    10,     3,    34,    37,   119,    34,    34,
      15,   143,    19,     3,   100,    22,   148,    82,   146,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    33,    -1,   140,    36,
      -1,    38,    39,     3,     4,     5,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    14,    -1,    16,    17,    18,    19,
      20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    36,    37,    38,     3,
       4,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      14,    -1,    16,    17,    18,    19,    20,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    36,    -1,    38,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,    -1,    14,    -1,    16,    17,
      18,    19,    20,    -1,    22,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    -1,    -1,    33,    -1,    -1,    36,    -1,
      38,    19,    -1,    -1,    22,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    -1,    -1,    33,    34,    -1,    36,    -1,
      38,    19,    -1,    -1,    22,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    -1,    -1,    33,    34,    -1,    36,    -1,
      38,    19,    -1,    -1,    22,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    -1,    -1,    33,    34,    -1,    36,    -1,
      38,    19,    -1,    -1,    22,     6,     7,     8,    -1,    -1,
      -1,    -1,     6,     7,     8,    33,    -1,    -1,    36,    -1,
      38,    -1,    -1,    -1,    25,    26,    27,    28,    29,    30,
      31,    25,    26,    27,    28,    29,    30,    31,    39,    -1,
      -1,    35,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    30,    31,     6,     7,
       8,    35,    25,    26,    27,    28,    29,    30,    31,     6,
       7,     8,    35,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    31,     6,     7,     8,    35,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    34,     6,     7,
       8,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    34,     6,     7,     8,    -1,    25,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,     6,     7,     8,
      -1,    -1,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    34,     6,     7,     8,    -1,    25,    26,    27,    28,
      29,    30,    31,    32,     6,     7,     8,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,     6,
       7,     8,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,     6,     7,     8,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      25,    26,    27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     9,    10,    11,    14,    16,    17,
      18,    19,    20,    22,    33,    36,    38,    43,    44,    45,
      46,    47,    51,    54,    55,    57,    59,    60,    61,    62,
      63,    66,    21,    33,     3,    48,    49,    55,    33,    33,
      33,     3,     3,    34,    52,    53,     3,    47,    52,    34,
      47,     3,    37,    58,    39,    47,    65,     0,    45,     6,
       7,     8,    25,    26,    27,    28,    29,    30,    31,    32,
      24,    33,    24,    38,    40,    56,    23,    32,    34,    47,
      64,    32,    35,    24,    47,    46,    47,    33,    24,    35,
      36,    46,    50,    51,    34,    32,    34,    34,    41,    37,
      35,    39,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    34,    64,    47,    47,     3,    47,    35,
      34,    48,    47,    34,    47,    34,    34,    52,    47,    53,
       3,    45,    50,    47,    65,    34,    39,    56,    64,    50,
      32,    50,    50,    34,    35,    37,    35,    56,    15,    47,
      50,    53,    58,    50,    34,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    45,    45,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    48,    48,    49,    49,    50,    50,    50,    51,
      52,    53,    53,    53,    53,    54,    55,    56,    56,    56,
      56,    57,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    60,    60,    60,    60,    61,    61,
      62,    62,    63,    64,    64,    65,    65,    66,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     3,     3,     3,
       7,     5,     5,     8,     5,     6,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     3,     1,     3,     1,     3,     1,     1,     2,
       1,     5,     3,     3,     1,     2,     1,     4,     3,     3,
       2,     3,     1,     5,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     4,     3,     4,     3,     3,     2,
       3,     4,     3,     3,     1,     3,     1,     1,     2,     3
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 65 "mini_js.y"
            { print( yyvsp[0].c + "." ); }
#line 1555 "y.tab.c"
    break;

  case 3:
#line 68 "mini_js.y"
            { print( resolve_enderecos( yyvsp[0].c + "." + funcs ) ); }
#line 1561 "y.tab.c"
    break;

  case 4:
#line 71 "mini_js.y"
                    { yyval.c = yyvsp[-1].c + yyvsp[0].c; }
#line 1567 "y.tab.c"
    break;

  case 5:
#line 72 "mini_js.y"
                    { yyval.c = yyvsp[0].c; }
#line 1573 "y.tab.c"
    break;

  case 6:
#line 75 "mini_js.y"
                                    { yyval.c = yyvsp[-1].c + "^"; }
#line 1579 "y.tab.c"
    break;

  case 7:
#line 76 "mini_js.y"
                                    { yyval.c = yyvsp[-2].c + "@" + yyvsp[-1].c + "^"; }
#line 1585 "y.tab.c"
    break;

  case 8:
#line 77 "mini_js.y"
                                    { yyval.c = yyvsp[-1].c; }
#line 1591 "y.tab.c"
    break;

  case 9:
#line 78 "mini_js.y"
                                    { yyval.c = aux + yyvsp[-1].c + "'&retorno'" + "@" + "~"; }
#line 1597 "y.tab.c"
    break;

  case 10:
#line 79 "mini_js.y"
                                    { string r = gera_label( "IF_ELSE" ); 
                                      string s = gera_label( "IF_CONTINUE" ); 
                                      yyval.c = yyvsp[-4].c + "!" + r + "?" + yyvsp[-2].c + s + "#" + (":" + r) + yyvsp[0].c + (":" + s); }
#line 1605 "y.tab.c"
    break;

  case 11:
#line 82 "mini_js.y"
                                    { string r = gera_label( "ENDIF" ); 
                                      yyval.c = yyvsp[-2].c + "!" + r + "?" + yyvsp[0].c + (":" + r); }
#line 1612 "y.tab.c"
    break;

  case 12:
#line 84 "mini_js.y"
                                    { string r = gera_label( "WHILE" ); 
                                      string s = gera_label( "ENDWHILE" ); 
                                      yyval.c = aux + (":" + r) + yyvsp[-2].c + "!" + s + "?" + yyvsp[0].c + r + "#" + (":" + s); }
#line 1620 "y.tab.c"
    break;

  case 13:
#line 87 "mini_js.y"
                                    { string r = gera_label( "TESTFOR" );
                                      string s = gera_label( "ENDFOR" ); 
                                      yyval.c = yyvsp[-5].c + (":" + r) + yyvsp[-4].c + "!" + s + "?" + yyvsp[0].c + yyvsp[-2].c + "^" + r + "#" + (":" + s); }
#line 1628 "y.tab.c"
    break;

  case 14:
#line 90 "mini_js.y"
                                    { string r = gera_label( yyvsp[-3].c[0] ); 
                                      vector<string> retorna = aux + "undefined" + "@" + "'&retorno'" + "@" + "~"; 
                                      funcs = funcs + (":" + r) + yyvsp[0].c + retorna;
                                      vector<string> end_decl = yyvsp[-3].c + "&" + yyvsp[-3].c + "{}" + "=" + "'&funcao'" + r + "[=]" + "^";
                                      yyval.c = end_decl; 
                                      qtd_pars = 0; }
#line 1639 "y.tab.c"
    break;

  case 15:
#line 96 "mini_js.y"
                                    { string r = gera_label( yyvsp[-4].c[0] );
                                      vector<string> retorna = aux + "undefined" + "@" + "'&retorno'" + "@" + "~";
                                      funcs = funcs + (":" + r) + yyvsp[-2].c + yyvsp[0].c + retorna;
                                      yyval.c = yyvsp[-4].c + "&" + yyvsp[-4].c + "{}" + "=" + "'&funcao'" + r + "[=]" + "^"; }
#line 1648 "y.tab.c"
    break;

  case 16:
#line 102 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + yyvsp[0].c + "<"; }
#line 1654 "y.tab.c"
    break;

  case 17:
#line 103 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + yyvsp[0].c + ">"; }
#line 1660 "y.tab.c"
    break;

  case 18:
#line 104 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + yyvsp[0].c + ">="; }
#line 1666 "y.tab.c"
    break;

  case 19:
#line 105 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + yyvsp[0].c + "<="; }
#line 1672 "y.tab.c"
    break;

  case 20:
#line 106 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + yyvsp[0].c + "=="; }
#line 1678 "y.tab.c"
    break;

  case 21:
#line 107 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + yyvsp[0].c + "*"; }
#line 1684 "y.tab.c"
    break;

  case 22:
#line 108 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + yyvsp[0].c + "+"; }
#line 1690 "y.tab.c"
    break;

  case 23:
#line 109 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + yyvsp[0].c + "-"; }
#line 1696 "y.tab.c"
    break;

  case 24:
#line 110 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + yyvsp[0].c + "/"; }
#line 1702 "y.tab.c"
    break;

  case 25:
#line 111 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + yyvsp[0].c + "%"; }
#line 1708 "y.tab.c"
    break;

  case 26:
#line 112 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + yyvsp[0].c + "[=]"; }
#line 1714 "y.tab.c"
    break;

  case 27:
#line 113 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + yyvsp[0].c + "="; }
#line 1720 "y.tab.c"
    break;

  case 28:
#line 114 "mini_js.y"
                  { yyval.c = yyvsp[0].c + "[@]"; }
#line 1726 "y.tab.c"
    break;

  case 29:
#line 115 "mini_js.y"
                  { yyval.c = yyvsp[0].c + "@"; }
#line 1732 "y.tab.c"
    break;

  case 30:
#line 116 "mini_js.y"
                  { yyval = yyvsp[0]; }
#line 1738 "y.tab.c"
    break;

  case 32:
#line 120 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1744 "y.tab.c"
    break;

  case 34:
#line 124 "mini_js.y"
                    { yyval.c = yyvsp[-2].c + "&" + yyvsp[-2].c + yyvsp[0].c + "=" + "^";
                      vars[yyvsp[-2].c[0]] = linha;
                    }
#line 1752 "y.tab.c"
    break;

  case 35:
#line 127 "mini_js.y"
                    { yyval.c = yyvsp[0].c + "&";
                      vars[yyvsp[0].c[0]] = linha;
                    }
#line 1760 "y.tab.c"
    break;

  case 36:
#line 132 "mini_js.y"
                  { yyval.c = yyvsp[-1].c; }
#line 1766 "y.tab.c"
    break;

  case 37:
#line 133 "mini_js.y"
                  { yyval.c = yyvsp[0].c; }
#line 1772 "y.tab.c"
    break;

  case 38:
#line 134 "mini_js.y"
                  { yyval.c = aux; }
#line 1778 "y.tab.c"
    break;

  case 40:
#line 140 "mini_js.y"
                    {   vector<string> decl_par;
                        int tam = pars.size() / 2;

                        for( int i = 0; i < tam; i++ ) {
                          vector<string> defaultValue = pars.back();
                          pars.pop_back();

                          vector<string> id = pars.back();
                          pars.pop_back();

                          if ( defaultValue.size() == 0 ) {
                            decl_par = decl_par + id + "&" + id + "arguments" + "@" + to_string(i) + "[@]" + "=" + "^";
                          } else {
                            string r = gera_label( "IF_ELSE" );
                            string s = gera_label( "IF_CONTINUE" );

                            vector<string> def = aux + "arguments" + "@" + to_string(i) + "[@]" + "undefined" + "@" + "==" + "!" + r + "?" + id + "&" + id + defaultValue + "=" + "^";
                            vector<string> notDef = aux + s + "#" + (":" + r) + id + "&" + id + "arguments" + "@" + to_string(i) + "[@]" + "=" + "^" + (":" + s);
                            decl_par = decl_par + def + notDef;
                          }
                        }
                        pars.clear();
                        yyval.c = decl_par; }
#line 1806 "y.tab.c"
    break;

  case 41:
#line 165 "mini_js.y"
                                      { pars.push_back(yyvsp[-4].c);
                                        pars.push_back(yyvsp[-2].c);
                                        yyval.c = yyvsp[-4].c + yyvsp[-2].c + yyvsp[0].c; }
#line 1814 "y.tab.c"
    break;

  case 42:
#line 168 "mini_js.y"
                                      { pars.push_back(yyvsp[-2].c);
                                        pars.push_back(aux);
                                        yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1822 "y.tab.c"
    break;

  case 43:
#line 171 "mini_js.y"
                                      { pars.push_back(yyvsp[-2].c);
                                        pars.push_back(yyvsp[0].c);
                                        yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1830 "y.tab.c"
    break;

  case 44:
#line 174 "mini_js.y"
                                      { pars.push_back(yyvsp[0].c);
                                        pars.push_back(aux);
                                        yyval.c = yyvsp[0].c; }
#line 1838 "y.tab.c"
    break;

  case 45:
#line 179 "mini_js.y"
                  { yyval.c = yyvsp[-1].c + "@" + yyvsp[0].c; }
#line 1844 "y.tab.c"
    break;

  case 46:
#line 182 "mini_js.y"
                  { yyval.c = yyvsp[0].c; }
#line 1850 "y.tab.c"
    break;

  case 47:
#line 185 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + "[@]" + yyvsp[0].c; }
#line 1856 "y.tab.c"
    break;

  case 48:
#line 186 "mini_js.y"
                  { yyval.c = yyvsp[-1].c + "[@]" + yyvsp[0].c; }
#line 1862 "y.tab.c"
    break;

  case 49:
#line 187 "mini_js.y"
                  { yyval.c = yyvsp[-1].c; }
#line 1868 "y.tab.c"
    break;

  case 50:
#line 188 "mini_js.y"
                  { yyval.c = yyvsp[0].c; }
#line 1874 "y.tab.c"
    break;

  case 51:
#line 191 "mini_js.y"
                  { yyval.c = aux + "{}" + yyvsp[-1].c; }
#line 1880 "y.tab.c"
    break;

  case 52:
#line 192 "mini_js.y"
                  { yyval.c = aux + "{}"; }
#line 1886 "y.tab.c"
    break;

  case 53:
#line 195 "mini_js.y"
                              { yyval.c = yyvsp[-4].c + yyvsp[-2].c + "[<=]" + yyvsp[0].c; }
#line 1892 "y.tab.c"
    break;

  case 54:
#line 196 "mini_js.y"
                              { yyval.c = yyvsp[-2].c + yyvsp[0].c + "[<=]"; }
#line 1898 "y.tab.c"
    break;

  case 55:
#line 199 "mini_js.y"
                  { yyval.c = yyvsp[0].c; }
#line 1904 "y.tab.c"
    break;

  case 56:
#line 200 "mini_js.y"
                  { yyval.c = yyvsp[0].c; }
#line 1910 "y.tab.c"
    break;

  case 57:
#line 201 "mini_js.y"
                  { yyval.c = yyvsp[0].c; }
#line 1916 "y.tab.c"
    break;

  case 58:
#line 202 "mini_js.y"
                  { yyval.c = yyvsp[0].c; }
#line 1922 "y.tab.c"
    break;

  case 59:
#line 203 "mini_js.y"
                  { yyval = yyvsp[-1]; }
#line 1928 "y.tab.c"
    break;

  case 60:
#line 204 "mini_js.y"
                  { yyval = yyvsp[0]; }
#line 1934 "y.tab.c"
    break;

  case 61:
#line 205 "mini_js.y"
                  { yyval = yyvsp[0]; }
#line 1940 "y.tab.c"
    break;

  case 62:
#line 206 "mini_js.y"
                  { yyval = yyvsp[0]; }
#line 1946 "y.tab.c"
    break;

  case 63:
#line 207 "mini_js.y"
                  { yyval = yyvsp[0]; }
#line 1952 "y.tab.c"
    break;

  case 64:
#line 210 "mini_js.y"
                      { yyval.c = yyvsp[-1].c + to_string(qtd_pars) + yyvsp[-3].c + "@" + "$"; qtd_pars = 0; }
#line 1958 "y.tab.c"
    break;

  case 65:
#line 211 "mini_js.y"
                      { yyval.c = aux + "0" + yyvsp[-2].c + "@" + "$"; }
#line 1964 "y.tab.c"
    break;

  case 66:
#line 212 "mini_js.y"
                      { yyval.c = yyvsp[-1].c + to_string(qtd_pars) + yyvsp[-3].c + "[@]" + "$"; qtd_pars = 0; }
#line 1970 "y.tab.c"
    break;

  case 67:
#line 213 "mini_js.y"
                      { yyval.c = aux + "0" + yyvsp[-2].c + "[@]" + "$"; }
#line 1976 "y.tab.c"
    break;

  case 68:
#line 216 "mini_js.y"
                      { yyval.c = aux + "[]";
                        int tam = elements.size();
                        for ( int i = 0; i < tam; i++ ) {
                          yyval.c = yyval.c + to_string(i) + elements.back() + "[<=]";
                          elements.pop_back();
                        }
                      }
#line 1988 "y.tab.c"
    break;

  case 69:
#line 223 "mini_js.y"
                      { yyval.c = aux + "[]"; }
#line 1994 "y.tab.c"
    break;

  case 70:
#line 226 "mini_js.y"
                                  { string r = gera_label( "FUNCANON" ); 
                                    vector<string> retorna = aux + "undefined" + "@" + "'&retorno'" + "@" + "~";
                                    funcs = funcs + (":" + r) + yyvsp[0].c + retorna;
                                    yyval.c = aux + "{}" + "'&funcao'" + r + "[<=]"; }
#line 2003 "y.tab.c"
    break;

  case 71:
#line 230 "mini_js.y"
                                  { string r = gera_label( "FUNCANON" );
                                    vector<string> retorna = aux + "undefined" + "@" + "'&retorno'" + "@" + "~";
                                    funcs = funcs + (":" + r) + yyvsp[-2].c + yyvsp[0].c + retorna;
                                    yyval.c = aux + "{}" + "'&funcao'" + r + "[<=]"; }
#line 2012 "y.tab.c"
    break;

  case 72:
#line 236 "mini_js.y"
                            { string r = gera_label( "FUNCANON" ); 
                              vector<string> retorna = aux + yyvsp[0].c + "'&retorno'" + "@" + "~";
                              funcs = funcs + (":" + r) + yyvsp[-2].c + retorna;
                              yyval.c = aux + "{}" + "'&funcao'" + r + "[<=]"; }
#line 2021 "y.tab.c"
    break;

  case 73:
#line 242 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + yyvsp[0].c; qtd_pars++; }
#line 2027 "y.tab.c"
    break;

  case 74:
#line 243 "mini_js.y"
                  { yyval.c = yyvsp[0].c; qtd_pars++; }
#line 2033 "y.tab.c"
    break;

  case 75:
#line 246 "mini_js.y"
                  { elements.push_back(yyvsp[-2].c); }
#line 2039 "y.tab.c"
    break;

  case 76:
#line 247 "mini_js.y"
                  { elements.push_back(yyvsp[0].c); }
#line 2045 "y.tab.c"
    break;

  case 77:
#line 250 "mini_js.y"
                      { yyval.c = yyvsp[0].c + "&" + yyvsp[0].c + "arguments" + "@" + "0" + "[@]" + "=" + "^"; }
#line 2051 "y.tab.c"
    break;

  case 78:
#line 251 "mini_js.y"
                      { yyval.c = aux; }
#line 2057 "y.tab.c"
    break;

  case 79:
#line 252 "mini_js.y"
                      { yyval.c = yyvsp[-1].c; }
#line 2063 "y.tab.c"
    break;


#line 2067 "y.tab.c"

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 255 "mini_js.y"


#include "lex.yy.c"

vector<string> concatena( vector<string> a, vector<string> b ) {
  for ( int i = 0; i < b.size(); i++ ) 
    a.push_back( b[i] );
  return a;
}

vector<string> operator+( vector<string> a, vector<string> b ) {
  return concatena( a , b );
}

vector<string> operator+( vector<string> a, string b ) {
  a.push_back( b );
  return a;
}

string gera_label( string prefixo ) {
  static int n = 0;
  return prefixo + "_" + to_string( ++n ) + ":";
}

vector<string> resolve_enderecos( vector<string> entrada ) {
  map<string,int> label;
  vector<string> saida;

  for ( int i = 0; i < entrada.size(); i++ ) {
    if ( entrada[i][0] == ':' )
      label[entrada[i].substr(1)] = saida.size();
    else
      saida.push_back( entrada[i] );
  }

  for ( int i = 0; i < saida.size(); i++ ) {
    if( label.count( saida[i] ) > 0)
      saida[i] = to_string( label[saida[i]] );
  }

  return saida;
}

void atributos( Atributos a ) {
  string var = a.c[0];

  if( vars.count( var ) == 1 ) {
    cout << "Erro: a variável '" << var << "' já foi declarada na linha " << vars[var] << "." << endl;
    exit(1);
  }
}

void attr( Atributos a ) {
  string var = a.c[0];

  if( vars.count( var ) == 0 ) {
    cout << "Erro: a variável '" << var << "' não foi declarada." << endl;
    exit(1);
  }
}

Atributos gera_operador(  Atributos s1,
                          Atributos s3,
                          Atributos s2 ) {
    Atributos ss;

    ss.c = s1.c + s3.c + s2.c;

    return ss;
}

void print( vector<string> v ) {
  for ( int i = 0; i < v.size(); i++ ) {
    cout << v[i] << " ";
  }
}

string trim( char* c ) {
  string temp = c;
  return temp.erase( temp.size() - 1, temp.size() );
}

vector<string> split( string v ) {
  vector<std::string> tokens;
  size_t s = 0, e = 0;

  while( ( e = v.find(" ", s)) != string::npos ) {
    tokens.push_back( v.substr( s, e - s ) );
    s = e + 1;
  }

  tokens.push_back( v.substr( s ) );
  return tokens;
}

void yyerror( const char* st ) {
  puts( st );
  printf( "ERRO DE COMPILAÇÃO (linha %d) Proximo a: %s\n", linha, yytext );
  exit( 1 );
}

int main( int argc, char* argv[] ) {
  yyparse();
  return 0;
}
