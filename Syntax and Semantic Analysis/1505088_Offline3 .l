%x stringType
%{
//#include "Symba.h"
#include "SymbolTable.h"
//#include "SymbolInfo.h"
#include "y.tab.h"

extern YYSTYPE yylval;
extern SymbolTable *table;
void yyerror(char *);

//int line_count=1;
//int error_count=0;
char ch[9999];
char *ch_ptr;
int i=0;
int j=0;
int cnt=0;


%}

digit [0-9]
letter [A-Za-z]
delim [ \t\r\f\v]
newline \n
ws [delim]+
id (_|{letter})(_|{letter}|{digit})*
integer {digit}+
number {digit}*(\.{digit}+)?(E[+-]?{digit}+)?
ADDOP [+-] 
MULOP [*/%]
SCHAR '\\[tnafrvb0\']'
UNRECOG '\\[^tnafrvb0\']'

%%
{delim}+ {}
{newline} {line_count++;}
"if" {return IF;}
"else" {return ELSE;}
"for" {return FOR;}
"while" {return WHILE;}
"do" {return DO;}
"break" {return BREAK;}
"int" {return INT;}
"float" {return FLOAT;}
"double" {return DOUBLE;}
"char" {return CHAR;}
"return" {return RETURN;}
"void" {return VOID;}
"main"	{return MAIN;}
"switch" {return SWITCH;}
"case" {return CASE;}
"default" {return DEFAULT;}
"continue" {return CONTINUE;}
"println"	{return PRINTLN;}

{ADDOP} { 
			symboInfo *s= new  symboInfo(yytext, (char *)"ADDOP");
			yylval = (YYSTYPE)s;
			return ADDOP;
		}


{MULOP}	{
			symboInfo *s= new  symboInfo(yytext, (char *)"MULOP");
			yylval = (YYSTYPE)s;
			return MULOP;
		}

"<<"|">>"|"&"|"|"|"^"	{return BITOP;}

"=" 	{return ASSIGNOP;}

">" |
"<" |
">=" |
"<=" |
"==" |
"!=" {
		symboInfo *s= new  symboInfo(yytext, (char *)"RELOP");
		yylval = (YYSTYPE)s;
		return RELOP;
	}

"&&"	|
"||"	{
			symboInfo *s= new  symboInfo(yytext, (char *)"LOGICOP");
			yylval = (YYSTYPE)s;
			return LOGICOP;
		}
"!"		{	return NOT; }


";" 	{ return SEMICOLON;}
"," 	{return COMMA;}
"(" 	{return LPAREN;}
")" 	{return RPAREN;}
"{" 	{return LCURL;}
"}" 	{return RCURL;}
"[" 	{return LTHIRD;}
"]" 	{return RTHIRD;}
"++" 	{return INCOP;}
"--" 	{return DECOP;}



{integer}	{
				symboInfo *s= new  symboInfo(yytext, (char *)"CONST_INT");
				yylval = (YYSTYPE)s;
				return CONST_INT;
			}
{number} 	{	
				symboInfo *s= new  symboInfo(yytext, (char *)"CONST_FLOAT");
				yylval = (YYSTYPE)s;
				return CONST_FLOAT; 
			}
{id} 		{	 
				
				symboInfo *s= table->lookup(yytext);
				if(s==NULL)
				{					
					s= new symboInfo(yytext, (char *)"ID");
				}
				yylval = (YYSTYPE)s;
							
				return ID;
			}
{SCHAR}	{
				symboInfo *s= new  symboInfo(yytext, (char *)"CHAR_CONST");
				yylval = (YYSTYPE)s;
				return CHAR_CONST;
				//st.allScope();
		}
{UNRECOG}|'\''	{
			//fprintf(logout,"Error on line no %d: Unrecognized character %s\n",line_count,yytext);
			error_count++;
		}


'[.]|'\\'	{
			//fprintf(logout,"Error on line no %d: Unfinished character %s\n",line_count,yytext);
			error_count++;
		}

'.'	{
			symboInfo *s= new  symboInfo(yytext, (char *)"CHAR_CONST");
			yylval = (YYSTYPE)s;
			return CHAR_CONST;
		}
\"		{
			BEGIN(stringType);
			//cnt = line_count;
		}
<stringType>\n	{
			for(int l = 0; l<yyleng ; l++){if(yytext[l] == '\n') line_count++;}
			//fprintf(logout,"Error on line %d: unfinished string\n",line_count);
			error_count++;
			BEGIN(INITIAL);	
			//line_count++;
		}
<stringType>\\n	{
			ch[i++] = '\n';
			for(int l = 0; i<yyleng ; l++){if(yytext[l] == '\n') line_count++;}
		}
<stringType>\\t	{
			ch[i++] = '\t';
		}
<stringType>\\f	{
			ch[i++] = '\f';
		}


<stringType>\\b	{
			ch[i++] = '\b';
		}
<stringType>\\(.|\n)	{
				ch[i++] = yytext[1];
			}
<stringType>[^\\\n\"]+	{
				//char ptr[] = yytext;
				for(int n = 0; n<yyleng ; n++){if(yytext[n] == '\n') line_count++;}
				while(yytext[j] != '\0')
				{
					ch[i++] = yytext[j++];

				}
				j =0;
			}
<stringType>\"	{
			BEGIN(INITIAL);
			ch[i++] = '\0';
			i =0 ;
			return STRING;
		}


"/*"([^*]|(\*+[^*/]))*[\*]+"/"	{
					for(int l = 0; l<yyleng ; l++){if(yytext[l] == '\n') line_count++;}
					return COMMENT;
					//fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s found\n",line_count,yytext);
			}
"//".*	{
				for(int l = 0; l<yyleng ; l++){if(yytext[l] == '\n') line_count++;}
				return COMMENT;
				//fprintf(logout,"Line no %d: Token <COMMENT> Lexeme %s found\n",line_count,yytext);
		}

[0-9]*\.+[0-9]+.+	{
				//fprintf(logout,"Error on line no %d: Too many decimal points error %s!!\n",line_count,yytext);
				error_count++;
		}


[0-9]+[Ee][-+]?(\.*[0-9]*\.*[0-9]*)*	{

				//fprintf(logout,"Error on line no %d: Ill formed numbers %s!!\n",line_count,yytext);
				error_count++;
		}
				
([0-9]+|[0-9]*\.[0-9]+)[a-zA-Z]+	{
						//fprintf(logout,"Error on Line no %d: Invalid Suffix or prefix\n",line_count);
						error_count++;
				}

'[a-zA-Z0-9]+[a-zA-Z0-9]+'		{
			//fprintf(logout,"Error on line no %d: Multi character constant error %s\n",line_count++,yytext);
			error_count++;
		}
	
"/*"([^*]|(\*+[^*/]))*	{
				//fprintf(logout,"Error on line %d: Unfinished Comment\n",line_count++);
				error_count++;		
		}


%%

int yywrap(void)
{
	return 1;
}





