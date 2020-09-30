%{
#include<bits/stdc++.h>
#include<stdio.h>
#include "SymbolTable.h"
//#define YYSTYPE SymbolInfo*

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;
extern int line_count;
extern int error_count;
FILE *logout;	
FILE *errorFile;
string typeInfo;

SymbolTable table(7);

void yyerror(const char *s)
{
	//write your code
	fprintf(errorFile,"At line no. %d: %s\n",line_count,s);
	error_count++;
	return;
}


%}
%union{
symboInfo* symbol;
}

%token IF ELSE FOR WHILE DO BREAK CONTINUE INT FLOAT CHAR DOUBLE VOID RETURN SWITCH CASE DEFAULT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD 
%token SEMICOLON COMMA STRING NOT PRINTLN COMMENT INCOP DECOP ASSIGNOP BITOP
%token <symbol>ID 
%token <symbol>CONST_INT 
%token <symbol>CONST_FLOAT 
%token <symbol>CHAR_CONST
%token <symbol>ADDOP
%token <symbol>MULOP
%token <symbol>RELOP
%token <symbol>LOGICOP

%type <symbol>type_specifier 
%type <symbol>expression expression_statement
%type <symbol>logic_expression
%type <symbol>rel_expression
%type <symbol>simple_expression
%type <symbol>term
%type <symbol>unary_expression
%type <symbol>factor
%type <symbol>variable
%type <symbol>parameter_list
%type <symbol>declaration_list
%type <symbol>program
%type <symbol>unit
%type <symbol>func_declaration
%type <symbol>func_definition
%type <symbol>compound_statement
%type <symbol>var_declaration
%type <symbol>statements statement

%nonassoc less_than_else
%nonassoc ELSE
%error-verbose
%%
start : program
	{
		//write your code in this block in all the similar blocks below
		fprintf(logout,"\nAt line no. %d start : program\n",line_count);
	}
	;

program : program unit 
	{
		fprintf(logout,"\nAt line no. %d program : program unit\n",line_count);
		$$->symboPrint = $1->symboPrint +"\n"+ $2->symboPrint ;
		fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
	}

	| unit
	{
		fprintf(logout,"\nAt line no. %d program : unit\n",line_count);
		fprintf(logout,"%s\n\n",$$->symboPrint.c_str());
	}
	;
	
unit : var_declaration
	{
		fprintf(logout,"\nAt line no. %d unit : var_declaration\n",line_count);
	}
     | func_declaration
	{
		fprintf(logout,"\nAt line no. %d unit : func_declaration\n",line_count);
	}
     | func_definition
	{
		fprintf(logout,"\nAt line no. %d unit : func_definition\n",line_count);
	}
     ;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
			{
				fprintf(logout,"\nAt line no. %d func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n",line_count);
				//fprintf(logout,"\n%s %s( %s);\n",($1->getName()).c_str(),($2->getName()).c_str(),$4->getName().c_str());
				symboInfo *st1 = table.LookUpSymbol($2->getName(),"FUNC");
				//int st1 = table.LookUpSymbol($2->getName());
				if(st1 != NULL)
				{
					fprintf(errorFile,"Error at line %d : multiple declaration of %s \n",line_count,$2->getName().c_str());
					error_count++;		
				}
				else
				{		
					symboInfo* tmp = table.InsertSymbol($2->getName(),"FUNC");
					tmp->setTypeSpecifier($1->getName());
					$$->symboPrint = $1->getName() + " " +$2->getName() + "("+$4->symboPrint+")"+";" + "\n";
					fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
					printf("\n%s\n",tmp->getTypeSpecifier().c_str());
				} 
			}
				
		| type_specifier ID LPAREN RPAREN SEMICOLON
			{
				fprintf(logout,"\nAt line no. %d func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n",line_count);
				symboInfo *st1 = table.LookUpSymbol($2->getName(),"FUNC");
				//int st1 = table.LookUpSymbol($2->getName());
				if(st1 != NULL)
				{
					fprintf(errorFile,"Error at line %d : multiple declaration of \n",line_count);
					error_count++;		
				}
				else
				{		
					symboInfo* temp = table.InsertSymbol($2->getName(),"FUNC");
					temp->setTypeSpecifier($1->getName());
					$$->symboPrint = $1->getName() + " " +$2->getName() + "(" + ")" + ";";
					fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
					printf("Success");
				} 
			}
		;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement
		{
			fprintf(logout,"\nAt line no. %d : func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n",line_count);
			symboInfo *st1 = table.LookUpSymbol($2->getName(),"FUNC");
			//cout<<st1->getTypeSpecifier()<<"--hello";
				//int st1 = table.LookUpSymbol($2->getName());
			if(st1 != NULL)
			{
				if(st1->getFuncDefined())
				{					
					fprintf(errorFile,"Error at line %d : Function already defined\n",line_count);
					error_count++;
				}
				else if(st1->getTypeSpecifier() != $1->getName())
				{
					fprintf(errorFile,"\nError at line no. %d: Return type does not match\n",line_count);
					error_count++;	
				}
				else
				{
					st1->setFuncDefined();
					$$->symboPrint = $1->getName() + " " +$2->getName() + "("+$4->symboPrint+")"+ $6->symboPrint;
					fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
				}		
			}
			else
			{		
				symboInfo* temp = table.InsertSymbol($2->getName(),"FUNC");
				temp->setFuncDefined();
				temp->setTypeSpecifier($1->getName());
				$$->symboPrint = $1->getName() + " " + $2->getName() + "(" + $4->symboPrint + ")" + $6->symboPrint;
				fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
			} 
		}
		| type_specifier ID LPAREN RPAREN compound_statement
		{
			fprintf(logout,"\nAt line no. %d: func_definition : type_specifier ID LPAREN RPAREN compound_statement\n",line_count);
			symboInfo *st1 = table.LookUpSymbol($2->getName(),"FUNC");
				//int st1 = table.LookUpSymbol($2->getName());
			if(st1 != NULL)
			{
				if(st1->getFuncDefined())
				{					
					fprintf(errorFile,"Error at line %d : Function already defined\n",line_count);
					error_count++;
				}
				else if(st1->getTypeSpecifier()!= $1->getName())
				{
					fprintf(errorFile,"\nError at line no. %d: Return type does not match\n",line_count);
					error_count++;	
				}
				else
				{
					st1->setFuncDefined();
					$$->symboPrint = $1->getName() + " " +$2->getName() + "("+")"+ $5->symboPrint;
					fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
				}		
			}
			else
			{		
				symboInfo* temp = table.InsertSymbol($2->getName(),"FUNC");
				temp->setFuncDefined();
				temp->setTypeSpecifier($1->getName());
				$$->symboPrint = $1->getName() + " " +$2->getName() + "("+")"+ $5->symboPrint;
				fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
				printf("Success");
			} 
		}
 		;				


parameter_list  : parameter_list COMMA type_specifier ID
		{
			fprintf(logout,"\nAt line no. %d: parameter_list : parameter_list COMMA type_specifier ID\n",line_count);
			symboInfo *st1 = table.LookUpSymbol($4->getName(),"PARAM");
				//int st1 = table.LookUpSymbol($2->getName());
			if(st1 != NULL)
			{
				fprintf(errorFile,"Error at line %d : multiple declaration of %s\n",line_count,$4->getName().c_str());
				error_count++;		
			}
			else
			{		
				symboInfo* temp = table.InsertSymbol($4->getName(),"PARAM");
				temp->setTypeSpecifier($3->getName());
				$$->symboPrint = $1->symboPrint + "," + $3->getName()+" " +$4->getName();
				printf("Success \n");
				cout<<$$->symboPrint;
				fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
			} 
		}
			
		| parameter_list COMMA type_specifier
		{
			fprintf(errorFile,"Error at line %d : Wrong declaration\n",line_count);
			error_count++;
		}
 		| type_specifier ID
		{
			fprintf(logout,"\nAt line no. %d: parameter_list : type_specifier ID\n",line_count);
			symboInfo *temp = table.LookUpSymbol($2->getName(),"PARAM");
			if(temp == NULL)
			{
				symboInfo *temp = table.InsertSymbol($2->getName(),"PARAM");
				temp->setTypeSpecifier($1->getName());
				$$->symboPrint = $1->getName() +" " +$2->getName(); 
				printf("Success somewhere! ");
				cout<<$$->symboPrint;
				fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
			}
			else
			{
				fprintf(errorFile,"Error at line no. %d: Multiple declaration of %s\n",line_count,$2->getName().c_str());
				error_count++;
			}
		}	
		| type_specifier
		{
			fprintf(errorFile,"Error at line %d : Wrong declaration\n",line_count);
			error_count++;
		}
 		;

 		
compound_statement : LCURL {table.EnterScope();} statements{table.allScope();} RCURL{table.ExitScope();}
			{
				fprintf(logout,"\nAt line no. %d : compound_statement : LCURL statements RCURL\n",line_count);
			//	$$ = $2;
				$$->symboPrint ="\n{\n"+$3->symboPrint+"}\n";
				fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str()); 
			}
 		    | LCURL{table.EnterScope();} RCURL{table.allScope();table.ExitScope();}
			{
				fprintf(logout,"\nAt line no. %d : compound_statement : LCURL RCURL\n",line_count);
				$$->symboPrint ="{\n}\n";
				fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
			}
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON
		  {
			fprintf(logout,"\nAt line no. %d : var_declaration : type_specifier declaration_list SEMICOLON\n",line_count);
			$$->symboPrint = $1->getName() + " " + $2->symboPrint + ";" + "\n";
			fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
		  }
 		 ;
 		 
type_specifier	: INT
		{
			fprintf(logout,"\nAt line no. %d: type_specifier : INT\n",line_count);
			fprintf(logout,"%s\n\n","int");
			symboInfo *tmp = new symboInfo("int","INT");
			typeInfo = "INT";
			$$ = tmp;
		}
 		| FLOAT
		{
			fprintf(logout,"\nAt line no. %d: type_specifier : FLOAT\n",line_count);
			fprintf(logout,"float\n\n");
			symboInfo *tmp = new symboInfo("float","FLOAT");
			typeInfo = "FLOAT";
			$$ = tmp;
		}
 		| VOID
		{
			fprintf(logout,"\nAt line no. %d: type_specifier : VOID\n",line_count);
			fprintf(logout,"void\n\n");
			symboInfo *tmp = new symboInfo("void","VOID");
			typeInfo = "VOID";
			$$ = tmp;
		}
 		;
 		
declaration_list : declaration_list COMMA ID
			{
				fprintf(logout,"\nAt line no. %d: declaration_list : declaration_list COMMA ID\n",line_count);
				if(typeInfo.compare("VOID") == 0)
				{
					fprintf(errorFile,"Error at line no. %d: variable type cannot be void\n",line_count);
					error_count++;	
				}
				else
				{
					symboInfo *temp = table.LookUpSymbol($3->getName(),"ID");
					if(temp != NULL)
					{
						fprintf(errorFile,"Error at line no. %d: Multiple declaration of %s\n",line_count,$3->getName().c_str());
						error_count++;
					}
					else
					{
						symboInfo *ins = table.InsertSymbol($3->getName(),"ID");
						ins->setTypeSpecifier(typeInfo);
						$$->symboPrint = $1->symboPrint + " , " + $3->getName();
						fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
					}
				}
			}
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
			{
				fprintf(logout,"\nAt line no.%d : declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n",line_count);
				if(typeInfo.compare("VOID") == 0)
				{
					fprintf(errorFile,"Error at line no. %d: variable type cannot be void\n",line_count);
					error_count++;	
				}
				else
				{
					symboInfo *temp = table.LookUpSymbol($3->getName(),"ARRAY");
					if(temp != NULL)
					{
						fprintf(errorFile,"Error at line no. %d: Multiple declaration of %s\n",line_count,$3->getName().c_str());
						error_count++;
					}
					else
					{
						symboInfo *ins = table.InsertSymbol($3->getName(),"ARRAY");
						int araLen = atoi($5->getName().c_str());
						ins->setArrayLen(araLen);
						ins->setTypeSpecifier(typeInfo);
						if(typeInfo.compare("INT") == 0)
						{
							for(int i=ins->symboInt.size() ; i<ins->getArrayLen() ; i++)
							{
								ins->symboInt.push_back(0);
							}
						}
						else if(typeInfo.compare("FLOAT") == 0)
						{
							for(int i=ins->symboFloat.size() ; i<ins->getArrayLen() ; i++)
							{
								ins->symboFloat.push_back(0);
							}
						}
						else if(typeInfo.compare("CHAR") == 0)
						{
							for(int i=ins->symboChar.size() ; i<ins->getArrayLen() ; i++)
							{
								ins->symboChar.push_back('\0');
							}
						}
						$$->symboPrint = $1->symboPrint + " , " + $3->getName() + "["+$5->getName() +"]";
						fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str()); 
					}
				}
			}
 		  | ID
			{
				fprintf(logout,"At line no. %d: declaration_list : ID\n",line_count);
				if(typeInfo.compare("VOID") == 0)
				{
					fprintf(errorFile,"Error at line no. %d: variable type cannot be void\n",line_count);
					error_count++;	
				}
				else
				{
					symboInfo *temp = table.LookUpSymbol($1->getName(),"ID");
					if(temp != NULL)
					{
						fprintf(errorFile,"Error at line no. %d: Multiple declaration of %s\n",line_count,$1->getName().c_str());
						error_count++;
					}
					else
					{
						symboInfo *ins = table.InsertSymbol($1->getName(),"ID");
						ins->setTypeSpecifier(typeInfo);
						$$->symboPrint = $1->getName() ; 
						fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
					}
				}
			} 
 		  | ID LTHIRD CONST_INT RTHIRD
			{
				fprintf(logout,"\nAt line no.%d : declaration_list : ID LTHIRD CONST_INT RTHIRD\n",line_count);
				if(typeInfo.compare("VOID") == 0)
				{
					fprintf(errorFile,"Error at line no. %d: variable type cannot be void\n",line_count);
					error_count++;	
				}
				else
				{
					symboInfo *temp = table.LookUpSymbol($1->getName(),"ARRAY");
					if(temp != NULL)
					{
						fprintf(errorFile,"Error at line no. %d: Multiple declaration of %s\n",line_count,$1->getName().c_str());
						error_count++;
					}
					else
					{
						symboInfo *ins = table.InsertSymbol($1->getName(),"ARRAY");
						int araLen = atoi($3->getName().c_str());
						ins->setArrayLen(araLen);
						ins->setTypeSpecifier(typeInfo);
						if(typeInfo.compare("INT") == 0)
						{
							for(int i=ins->symboInt.size() ; i<ins->getArrayLen() ; i++)
							{
								ins->symboInt.push_back(0);
							}
						}
						else if(typeInfo.compare("FLOAT") == 0)
						{
							for(int i=ins->symboFloat.size() ; i<ins->getArrayLen() ; i++)
							{
								ins->symboFloat.push_back(0);
							}
						}
						else if(typeInfo.compare("CHAR") == 0)
						{
							for(int i=ins->symboChar.size() ; i<ins->getArrayLen() ; i++)
							{
								ins->symboChar.push_back('\0');
							}
						}
						$$->symboPrint = $1->getName() + "["+$3->getName()+"]";
						fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
					}
				}
			}
 		  ;
 		  
statements : statement
		{
			fprintf(logout,"\nAt line no. %d: statements : statement\n",line_count);
		}
			
	   | statements statement
		{
			fprintf(logout,"\nAt line no. %d: statements : statements statement\n",line_count);
			$$->symboPrint = $1->symboPrint + $2->symboPrint + "\n";
			fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
		}
	   ;
	   
statement : var_declaration
		{
			fprintf(logout,"\nAt line no. %d: statement : var_declaration\n",line_count);
		}
	  | expression_statement
		{
			fprintf(logout,"\nAt line no. %d: statement : expression_statement\n",line_count);
		}
	  | compound_statement
		{
			fprintf(logout,"\nAt line no. %d: statement : compound_statement\n",line_count);
		}	
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement
		{
			fprintf(logout,"\nAt line no. %d: statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n",line_count);
			$$ = $3;
			$$->symboPrint ="for( " + $3->symboPrint + $4->symboPrint + $5->symboPrint + ")" + $7->symboPrint; 
			fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
		}
	  | IF LPAREN expression RPAREN statement %prec less_than_else
		{
			fprintf(logout,"\nAt line no. %d: statement : IF LPAREN expression RPAREN statement\n",line_count);
			$$ = $3;
			$$->symboPrint ="if( " + $3->symboPrint + ")" + $5->symboPrint; 
			fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
		}
	  | IF LPAREN expression RPAREN statement ELSE statement
		{
			fprintf(logout,"\nAt line no. %d: statement : IF LPAREN expression RPAREN statement ELSE statement\n",line_count);
			$$ = $3;			
			$$->symboPrint ="if( " + $3->symboPrint + ")" +$5->symboPrint +"else"+ $7->symboPrint; 
			fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
		}
	  | WHILE LPAREN expression RPAREN statement
		{
			fprintf(logout,"\nAt line no. %d: statement : WHILE LPAREN expression RPAREN statement\n",line_count);
			$$ = $3;
			$$->symboPrint ="while( " + $3->symboPrint + ")" + $5->symboPrint; 
			fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
		}
	  | PRINTLN LPAREN ID RPAREN SEMICOLON
		{
			fprintf(logout,"\nAt line no. %d: statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n",line_count);
			$$ = $3;
			$$->symboPrint ="println( " + $3->getName() + ")" + ";\n"; 
			fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
		}
	  | RETURN expression SEMICOLON
		{
			fprintf(logout,"\nAt line no. %d: statement : RETURN expression SEMICOLON\n",line_count);
			$$ = $2;
			$$->symboPrint ="return " + $2->symboPrint + ";\n"; 
			fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
		}
	  ;
	  
expression_statement 	: SEMICOLON
			{
				fprintf(logout,"\nAt line no. %d: expression_statement : SEMICOLON\n",line_count);
				$$->symboPrint = ";";
			}			
			| expression SEMICOLON
			{
				fprintf(logout,"\nAt line no. %d: expression_statement : expression SEMICOLON\n",line_count);
				$$->symboPrint = $1->symboPrint + ";";
			} 
			;
	  
variable : ID
		{
			//cout<<"\nhow are you?";
			fprintf(logout,"\nAt line no. %d: variable : ID\n",line_count);
			symboInfo *var = table.LookUpSymbol($1->getName(),"ID");
			if(var == NULL)
			{
				fprintf(errorFile,"Error at line no. %d: %s does not exist!\n",line_count,$1->getName().c_str());
				error_count++;
			}
			else
			{
				//table.InsertSymbo($1->getName(),"ID");
				$$ = var;
				$$->symboPrint = $1->getName();
				fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
			}
		}
	 | ID LTHIRD expression RTHIRD
		{
			fprintf(logout,"\nAt line no. %d: variable : ID LTHIRD expression RTHIRD\n",line_count);
			symboInfo *ara = table.LookUpSymbol($1->getName(),"ARRAY");
			if(ara == NULL)
			{
				fprintf(errorFile,"Error at line %d: %s does not exists\n",line_count,$1->getName().c_str());	
				error_count++;
			}
			else{
				int araIndex = $3->integer;
				ara->symboIndex = araIndex;
				if(araIndex >= ara->getArrayLen())
				{
					fprintf(errorFile,"Error at line no. %d: Array index out of bound\n",line_count);
					error_count++;	
				}
			
				$$ = ara;
				$$->symboPrint = $1->getName() + "[" + $3->symboPrint + "]";
				fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
			}
		}			
	 ;
	 
 expression : logic_expression
		{
			fprintf(logout,"\nAt line no. %d : expression : logic_expression\n",line_count);
		}
	   | variable ASSIGNOP logic_expression
		{
			fprintf(logout,"\nAt line no. %d : expression : variable ASSIGNOP logic_expression\n",line_count);
			if($1->getType() == "ID")
			{
				if($1->getTypeSpecifier() == "INT")
				{
					if($3->getType() == "ARRAY")
					{
						if($3->getTypeSpecifier() == "INT")
						{
							$1->integer = $3->symboInt[$3->symboIndex];
							//cout<<"\njibon sundor  "<<$1->why;
						}
						else if($3->getTypeSpecifier() == "FLOAT")
						{
							fprintf(errorFile,"\nWarning at line no. %d: float value cannot be assigned to integer value\n",line_count);
							$1->integer = (int)($3->symboFloat[$3->symboIndex]);
						}
					}
					else
					{
						if($3->getTypeSpecifier() == "INT")
						{
							
							$1 = $3;
							cout<<"\n "<<$1->integer;
						}
						else if($3->getTypeSpecifier() == "FLOAT")
						{
							fprintf(errorFile,"\nWarning at line no. %d: float value cannot be assigned to integer value\n",line_count);
							$1->integer = (int)($3->floating);
						}
					}
				}
				else if($1->getTypeSpecifier() == "FLOAT")
				{
					if($3->getType() == "ARRAY")
					{
						if($3->getTypeSpecifier() == "FLOAT")
						{
							$1->floating = $3->symboFloat[$3->symboIndex];
						}	
						else if($3->getTypeSpecifier() == "INT")
						{
							fprintf(errorFile,"\nWarning at line no. %d: float value cannot be assigned to integer value\n",line_count);
							$1->floating = (float)($3->symboInt[$3->symboIndex]);
						}
					}
					else
					{
						if($3->getTypeSpecifier() == "FLOAT")
						{
							$1 = $3;
						}	
						else if($3->getTypeSpecifier() == "INT")
						{
							fprintf(errorFile,"\nWarning at line no. %d: float value cannot be assigned to integer value\n",line_count);
							$1->floating = (float)($3->integer);
						}
					}
				}
			}
			else if($1->getType() == "ARRAY")
			{
				if($1->getTypeSpecifier() == "INT")
				{
					if($3->getType() == "ARRAY")
					{
						if($3->getTypeSpecifier() == "INT")
						{
							$1->symboInt[$1->symboIndex] = $3->symboInt[$3->symboIndex];
							//cout<<"\njibon sundor  "<<$1->why;
						}
						else if($3->getTypeSpecifier() == "FLOAT")
						{
							fprintf(errorFile,"\nWarning at line no. %d: float value cannot be assigned to integer value\n",line_count);
							$1->symboInt[$1->symboIndex] = (int)($3->symboFloat[$3->symboIndex]);
						}
					}
					else
					{
						if($3->getTypeSpecifier() == "INT")
						{
							$1->symboInt[$1->symboIndex] = $3->integer;
							cout<<"\njibon sundor  ";
						}
						else if($3->getTypeSpecifier() == "FLOAT")
						{
							fprintf(errorFile,"\nWarning at line no. %d: float value cannot be assigned to integer value\n",line_count);
							$1->symboInt[$1->symboIndex] = (int)($3->floating);
						}
					}
				}
				else if($1->getTypeSpecifier() == "FLOAT")
				{
					if($3->getType() == "ARRAY")
					{
						if($3->getTypeSpecifier() == "FLOAT")
						{
							$1->symboFloat[$1->symboIndex] = $3->symboFloat[$3->symboIndex];
							//cout<<"\njibon sundor  "<<$1->why;
						}
						else if($3->getTypeSpecifier() == "INT")
						{
							fprintf(errorFile,"\nWarning at line no. %d: float value cannot be assigned to integer value\n",line_count);
							$1->symboFloat[$1->symboIndex] = (float)($3->symboInt[$3->symboIndex]);
						}
					}
					else
					{
						if($3->getTypeSpecifier() == "FLOAT")
						{
							$1->symboFloat[$1->symboIndex] = $3->floating;
							//cout<<"\njibon sundor  "<<$1->why;
						}
						else if($3->getTypeSpecifier() == "INT")
						{
							fprintf(errorFile,"\nWarning at line no. %d: float value cannot be assigned to integer value\n",line_count);
							$1->symboFloat[$1->symboIndex] = (float)($3->integer);
						}
					}
				}
			}
			$$->symboPrint = $1->symboPrint + " = " + $3->symboPrint;
			fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
		} 	
	   ;
			
logic_expression : rel_expression
			{
				fprintf(logout,"\nAt line no. %d : expression : logic_expression\n",line_count);
			} 	
		 | rel_expression LOGICOP rel_expression
			{
				fprintf(logout,"\nAt line no. %d : expression : rel_expression LOGICOP rel_expression\n",line_count);
				string str1 = $1->getType();
				string str3 = $3->getType();
				if((str1 == "ID" || str1 == "ARRAY") && (str3 == "ID" || str3 == "ARRAY"))
				{
					if($1->getTypeSpecifier() == "INT" && $3->getTypeSpecifier() == "INT")
					{
						$$->setTypeSpecifier("INT");
						$$->symboPrint = $1->symboPrint + $2->getName() + $3->symboPrint;
						fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
						cout<<"\n  logicop done\n";
					}
					else
					{ 
						fprintf(errorFile,"Error at line no. %d: Inavalid data type for Logical operation\n",line_count);
						error_count++;
					}
				}
				else if(str1 == "CONST_INT" && str3 == "CONST_INT")
				{
					$$->setTypeSpecifier("INT");
					$$->symboPrint = $1->symboPrint + $2->getName() + $3->symboPrint;
					fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
					cout<<"\n  logicop done again\n";
				}
				else
				{
					fprintf(errorFile,"Error at line no. %d: Inavalid data type for Logical operation\n",line_count);
					error_count++;
				}
			} 	
		 ;
			
rel_expression	: simple_expression
		{
			fprintf(logout,"\nAt line no. %d : rel_expression : simple_expression\n",line_count);
		} 
		| simple_expression RELOP simple_expression
		{
			fprintf(logout,"\nAt line no. %d : rel_expression : simple_expression RELOP simple_expression\n",line_count);
			string str1 = $1->getType();
			string str3 = $3->getType();
			if((str1 == "ID" || str1 == "ARRAY") && (str3 == "ID" || str3 == "ARRAY"))
			{
				if($1->getTypeSpecifier() == "INT" && $3->getTypeSpecifier() == "INT")
				{
					$$->setTypeSpecifier("INT");
					$$->symboPrint = $1->symboPrint + $2->getName() + $3->symboPrint;
					fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
					cout<<"\n  relop done\n";
				}
				else if($1->getTypeSpecifier() == "FLOAT" && $3->getTypeSpecifier() == "FLOAT")
				{
					$$->setTypeSpecifier("FLOAT");
					$$->symboPrint = $1->symboPrint + $2->getName() + $3->symboPrint;
					fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());	
				}
				else
				{ 
					fprintf(errorFile,"Error at line no. %d: Inavalid data type for Relative operation\n",line_count);
					error_count++;
				}
			}
			else if(str1 == "CONST_INT" && str3 == "CONST_INT")
			{
				$$->setTypeSpecifier("INT");
				$$->symboPrint = $1->symboPrint + $2->getName() + $3->symboPrint;
				fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
				cout<<"\n  relop done again\n";
			}
			else if(str1 == "CONST_FLOAT" && str3 == "CONST_FLOAT")
			{
				$$->setTypeSpecifier("FLOAT");
				$$->symboPrint = $1->symboPrint + $2->getName() + $3->symboPrint;
				fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
			}
			else
			{
				fprintf(errorFile,"Error at line no. %d: Inavalid data type for Relative operation\n",line_count);
				error_count++;
			}
		}	
		;
				
simple_expression : term 
			{
				fprintf(logout,"\nAt line no. %d: simple_expression : term\n",line_count);
			}
		  | simple_expression ADDOP term
			{
				fprintf(logout,"\nAt line no. %d: simple_expression : simple_expression ADDOP term\n",line_count);
				if($2->getName() == "+")
				{
					if($1->getType() == "ARRAY")
					{
						if($1->getTypeSpecifier() == "INT")
						{
							if($3->getType() == "ARRAY")
							{
								if($3->getTypeSpecifier() == "INT")
								{
									$$->integer = $1->symboInt[$1->symboIndex] + $3->symboInt[$3->symboIndex];
									$$->setTypeSpecifier("INT");
									cout<<$$->integer;
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch.Adding float with an integer\n",line_count);
									$$->integer = $1->symboInt[$1->symboIndex] + (int)($3->symboFloat[$3->symboIndex]);
									$$->setTypeSpecifier("INT");
								}
							}
							else
							{
								if($3->getTypeSpecifier() == "INT")
								{
									$$->integer = $1->symboInt[$1->symboIndex] + $3->integer;
									$$->setTypeSpecifier("INT");
									cout<<$$->integer;
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch.Adding float with an integer\n",line_count);
									$$->integer = $1->symboInt[$1->symboIndex] + (int)($3->floating);
									$$->setTypeSpecifier("INT");
								}
							}
						}
						else if($1->getTypeSpecifier() == "FLOAT")
						{
							if($3->getType() == "ARRAY")
							{
								if($3->getTypeSpecifier() == "FLOAT")
								{
									$$->floating = $1->symboFloat[$1->symboIndex] + $3->symboFloat[$3->symboIndex];
									$$->setTypeSpecifier("FLOAT");
									cout<<$$->floating;
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch.Adding integer with a float\n",line_count);
									$$->floating = $1->symboFloat[$1->symboIndex] + (float)($3->symboInt[$3->symboIndex]);
									$$->setTypeSpecifier("FLOAT");
								}
							}
							else
							{
								if($3->getTypeSpecifier() == "FLOAT")
								{
									$$->floating = $1->symboFloat[$1->symboIndex] + $3->floating;
									$$->setTypeSpecifier("FLOAT");
									cout<<$$->floating;
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch.Adding integer with a float\n",line_count);
									$$->floating = $1->symboFloat[$1->symboIndex] + (float)($3->integer);
									$$->setTypeSpecifier("FLOAT");
								}
							}
						}
					}
					else
					{
						if($1->getTypeSpecifier() == "INT")
						{
							if($3->getType() == "ARRAY")
							{
								if($3->getTypeSpecifier() == "INT")
								{
									$$->integer = $1->integer + $3->symboInt[$3->symboIndex];
									$$->setTypeSpecifier("INT");
									cout<<$$->integer;
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch.Adding float with an integer\n",line_count);
									$$->integer = $1->integer + (int)($3->symboFloat[$3->symboIndex]);
									$$->setTypeSpecifier("INT");
								}
							}
							else
							{
								if($3->getTypeSpecifier() == "INT")
								{
									$$->integer = $1->integer + $3->integer;
									$$->setTypeSpecifier("INT");
									cout<<$$->integer;
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch.Adding float with an integer\n",line_count);
									$$->integer = $1->integer + (int)($3->floating);
									$$->setTypeSpecifier("INT");
								}
							}
						}
						else if($1->getTypeSpecifier() == "FLOAT")
						{
							if($3->getType() == "ARRAY")
							{
								if($3->getTypeSpecifier() == "FLOAT")
								{
									$$->floating = $1->floating + $3->symboFloat[$3->symboIndex];
									$$->setTypeSpecifier("FLOAT");
									cout<<$$->floating;
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch.Adding integer with a float\n",line_count);
									$$->floating = $1->floating + (float)($3->symboInt[$3->symboIndex]);
									$$->setTypeSpecifier("FLOAT");
								}
							}
							else
							{
								if($3->getTypeSpecifier() == "FLOAT")
								{
									$$->floating = $1->floating + $3->floating;
									$$->setTypeSpecifier("FLOAT");
									cout<<$$->floating;
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch.Adding integer with a float\n",line_count);
									$$->floating = $1->floating + (float)($3->integer);
									$$->setTypeSpecifier("FLOAT");
								}
							}
						}
					}
				}
				else if($2->getName() == "-")
				{
					if($1->getType() == "ARRAY")
					{
						if($1->getTypeSpecifier() == "INT")
						{
							if($3->getType() == "ARRAY")
							{
								if($3->getTypeSpecifier() == "INT")
								{
									$$->integer = $1->symboInt[$1->symboIndex] - $3->symboInt[$3->symboIndex];
									$$->setTypeSpecifier("INT");
									cout<<$$->integer;
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch. Subtracting float from an integer\n",line_count);
									$$->integer = $1->symboInt[$1->symboIndex] - (int)($3->symboFloat[$3->symboIndex]);
									$$->setTypeSpecifier("INT");
								}
							}
							else
							{
								if($3->getTypeSpecifier() == "INT")
								{
									$$->integer = $1->symboInt[$1->symboIndex] - $3->integer;
									$$->setTypeSpecifier("INT");
									cout<<$$->integer;
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch. Subtracting float from an integer\n",line_count);
									$$->integer = $1->symboInt[$1->symboIndex] - (int)($3->floating);
									$$->setTypeSpecifier("INT");
								}
							}
						}
						else if($1->getTypeSpecifier() == "FLOAT")
						{
							if($3->getType() == "ARRAY")
							{
								if($3->getTypeSpecifier() == "FLOAT")
								{
									$$->floating = $1->symboFloat[$1->symboIndex] - $3->symboFloat[$3->symboIndex];
									$$->setTypeSpecifier("FLOAT");
									cout<<$$->floating;
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch. Subtracting integer from a float\n",line_count);
									$$->floating = $1->symboFloat[$1->symboIndex] - (float)($3->symboInt[$3->symboIndex]);
									$$->setTypeSpecifier("FLOAT");
								}
							}
							else
							{
								if($3->getTypeSpecifier() == "FLOAT")
								{
									$$->floating = $1->symboFloat[$1->symboIndex] - $3->floating;
									$$->setTypeSpecifier("FLOAT");
									cout<<$$->floating;
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch. Subtracting integer from a float\n",line_count);
									$$->floating = $1->symboFloat[$1->symboIndex] - (float)($3->integer);
									$$->setTypeSpecifier("FLOAT");
								}
							}
						}
					}
					else
					{
						if($1->getTypeSpecifier() == "INT")
						{
							if($3->getType() == "ARRAY")
							{
								if($3->getTypeSpecifier() == "INT")
								{
									$$->integer = $1->integer - $3->symboInt[$3->symboIndex];
									$$->setTypeSpecifier("INT");
									cout<<$$->integer;
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch. Subtracting float from an integer\n",line_count);
									$$->integer = $1->integer - (int)($3->symboFloat[$3->symboIndex]);
									$$->setTypeSpecifier("INT");
								}
							}
							else
							{
								if($3->getTypeSpecifier() == "INT")
								{
									$$->integer = $1->integer - $3->integer;
									$$->setTypeSpecifier("INT");
									cout<<$$->integer;
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch. Subtracting float from an integer\n",line_count);
									$$->integer = $1->integer - (int)($3->floating);
									$$->setTypeSpecifier("INT");
								}
							}
						}
						else if($1->getTypeSpecifier() == "FLOAT")
						{
							if($3->getType() == "ARRAY")
							{
								if($3->getTypeSpecifier() == "FLOAT")
								{
									$$->floating = $1->floating - $3->symboFloat[$3->symboIndex];
									$$->setTypeSpecifier("FLOAT");
									cout<<$$->floating;
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch. Subtracting integer from a float\n",line_count);
									$$->floating = $1->floating - (float)($3->symboInt[$3->symboIndex]);
									$$->setTypeSpecifier("FLOAT");
								}
							}
							else
							{
								if($3->getTypeSpecifier() == "FLOAT")
								{
									$$->floating = $1->floating - $3->floating;
									$$->setTypeSpecifier("FLOAT");
									cout<<$$->floating;
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch. Subtracting integer from a float\n",line_count);
									$$->floating = $1->floating - (float)($3->integer);
									$$->setTypeSpecifier("FLOAT");
								}
							}
						}
					}
				}
				$$->symboPrint = $1->symboPrint + $2->getName() + $3->symboPrint;
				fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
			}
						
		  ;
					
term :	unary_expression
	{
		fprintf(logout,"\n At line no. %d: term : unary_expression\n",line_count);
	}
     |  term MULOP unary_expression
	{
			fprintf(logout,"\n At line no. %d: term : term MULOP unary_expression\n",line_count);
				if($2->getName() == "*")
				{
					if($1->getType() == "ARRAY")
					{
						if($1->getTypeSpecifier() == "INT")
						{
							if($3->getType() == "ARRAY")
							{
								if($3->getTypeSpecifier() == "INT")
								{
									$$->integer = $1->symboInt[$1->symboIndex] * $3->symboInt[$3->symboIndex];
									$$->setTypeSpecifier("INT");
									cout<<$$->integer;
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch. Multiplying float with an integer\n",line_count);
									$$->integer = $1->symboInt[$1->symboIndex] * (int)($3->symboFloat[$3->symboIndex]);
									$$->setTypeSpecifier("INT");
								}
							}
							else
							{
								if($3->getTypeSpecifier() == "INT")
								{
									$$->integer = $1->symboInt[$1->symboIndex] * $3->integer;
									$$->setTypeSpecifier("INT");
									cout<<$$->integer;
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch. Multiplying float with an integer\n",line_count);
									$$->integer = $1->symboInt[$1->symboIndex] * (int)($3->floating);
									$$->setTypeSpecifier("INT");
								}
							}
						}
						else if($1->getTypeSpecifier() == "FLOAT")
						{
							if($3->getType() == "ARRAY")
							{
								if($3->getTypeSpecifier() == "FLOAT")
								{
									$$->floating = $1->symboFloat[$1->symboIndex] * $3->symboFloat[$3->symboIndex];
									$$->setTypeSpecifier("FLOAT");
									cout<<$$->floating;
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch. Multiplying integer with a float\n",line_count);
									$$->floating = $1->symboFloat[$1->symboIndex] * (float)($3->symboInt[$3->symboIndex]);
									$$->setTypeSpecifier("FLOAT");
								}
							}
							else
							{
								if($3->getTypeSpecifier() == "FLOAT")
								{
									$$->floating = $1->symboFloat[$1->symboIndex] * $3->floating;
									$$->setTypeSpecifier("FLOAT");
									cout<<$$->floating;
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch. Multiplying integer with a float\n",line_count);
									$$->floating = $1->symboFloat[$1->symboIndex] * (float)($3->integer);
									$$->setTypeSpecifier("FLOAT");
								}
							}
						}
					}
					else
					{
						if($1->getTypeSpecifier() == "INT")
						{
							if($3->getType() == "ARRAY")
							{
								if($3->getTypeSpecifier() == "INT")
								{
									$$->integer = $1->integer * $3->symboInt[$3->symboIndex];
									$$->setTypeSpecifier("INT");
									cout<<$$->integer;
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch. Multiplying float with an integer\n",line_count);
									$$->integer = $1->integer * (int)($3->symboFloat[$3->symboIndex]);
									$$->setTypeSpecifier("INT");
								}
							}
							else
							{
								if($3->getTypeSpecifier() == "INT")
								{
									$$->integer = $1->integer * $3->integer;
									$$->setTypeSpecifier("INT");
									cout<<$$->integer;
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch. Multiplying float with an integer\n",line_count);
									$$->integer = $1->integer * (int)($3->floating);
									$$->setTypeSpecifier("INT");
								}
							}
						}
						else if($1->getTypeSpecifier() == "FLOAT")
						{
							if($3->getType() == "ARRAY")
							{
								if($3->getTypeSpecifier() == "FLOAT")
								{
									$$->floating = $1->floating * $3->symboFloat[$3->symboIndex];
									$$->setTypeSpecifier("FLOAT");
									cout<<$$->floating;
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch. Multiplying integer with a float\n",line_count);
									$$->floating = $1->floating * (float)($3->symboInt[$3->symboIndex]);
									$$->setTypeSpecifier("FLOAT");
								}
							}
							else
							{
								if($3->getTypeSpecifier() == "FLOAT")
								{
									$$->floating = $1->floating * $3->floating;
									$$->setTypeSpecifier("FLOAT");
									cout<<$$->floating;
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch. Multiplying integer with a float\n",line_count);
									$$->floating = $1->floating * (float)($3->integer);
									$$->setTypeSpecifier("FLOAT");
								}
							}
						}
					}
				}
				else if($2->getName() == "/")
				{
					if($1->getType() == "ARRAY")
					{
						if($1->getTypeSpecifier() == "INT")
						{
							if($3->getType() == "ARRAY")
							{
								if($3->getTypeSpecifier() == "INT")
								{
									$$->integer = $1->symboInt[$1->symboIndex] / $3->symboInt[$3->symboIndex];
									$$->setTypeSpecifier("INT");
									cout<<$$->integer;
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch.Dividing float with an integer\n",line_count);
									$$->integer = $1->symboInt[$1->symboIndex] / (int)($3->symboFloat[$3->symboIndex]);
									$$->setTypeSpecifier("INT");
								}
							}
							else
							{
								if(($3->getType() == "CONST_INT" && $3->integer == 0) || ($3->getType() == "CONST_FLOAT" && $3->floating == 0))
								{
									fprintf(errorFile,"Error at line no. %d: Cannot divide by 0\n",line_count);
									error_count++;	
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									$$->integer = $1->symboInt[$1->symboIndex] / $3->integer;
									$$->setTypeSpecifier("INT");
									cout<<$$->integer;
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch.Dividing float with an integer\n",line_count);
									$$->integer = $1->symboInt[$1->symboIndex] / (int)($3->floating);
									$$->setTypeSpecifier("INT");
								}
							}
						}
						else if($1->getTypeSpecifier() == "FLOAT")
						{
							if($3->getType() == "ARRAY")
							{
								if($3->getTypeSpecifier() == "FLOAT")
								{
									$$->floating = $1->symboFloat[$1->symboIndex] / $3->symboFloat[$3->symboIndex];
									$$->setTypeSpecifier("FLOAT");
									cout<<$$->floating;
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch.Dividing integer with a float\n",line_count);
									$$->floating = $1->symboFloat[$1->symboIndex] / (float)($3->symboInt[$3->symboIndex]);
									$$->setTypeSpecifier("FLOAT");
								}
							}
							else
							{
								if(($3->getType() == "CONST_INT" && $3->integer == 0) || ($3->getType() == "CONST_FLOAT" && $3->floating == 0))
								{
									fprintf(errorFile,"Error at line no. %d: Cannot divide by 0\n",line_count);
									error_count++;	
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									$$->floating = $1->symboFloat[$1->symboIndex] / $3->floating;
									$$->setTypeSpecifier("FLOAT");
									cout<<$$->floating;
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch.Dividing integer with a float\n",line_count);
									$$->floating = $1->symboFloat[$1->symboIndex] / (float)($3->integer);
									$$->setTypeSpecifier("FLOAT");
								}
							}
						}
					}
					else
					{
						if($1->getTypeSpecifier() == "INT")
						{
							if($3->getType() == "ARRAY")
							{
								if($3->getTypeSpecifier() == "INT")
								{
									$$->integer = $1->integer / $3->symboInt[$3->symboIndex];
									$$->setTypeSpecifier("INT");
									cout<<$$->integer;
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch.Dividing float with an integer\n",line_count);
									$$->integer = $1->integer / (int)($3->symboFloat[$3->symboIndex]);
									$$->setTypeSpecifier("INT");
								}
							}
							else
							{
								if(($3->getType() == "CONST_INT" && $3->integer == 0) || ($3->getType() == "CONST_FLOAT" && $3->floating == 0))
								{
									fprintf(errorFile,"Error at line no. %d: Cannot divide by 0\n",line_count);
									error_count++;	
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									$$->integer = $1->integer / $3->integer;
									$$->setTypeSpecifier("INT");
									cout<<$$->integer;
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch.Dividing float with an integer\n",line_count);
									$$->integer = $1->integer / (int)($3->floating);
									$$->setTypeSpecifier("INT");
								}
							}
						}
						else if($1->getTypeSpecifier() == "FLOAT")
						{
							if($3->getType() == "ARRAY")
							{
								if($3->getTypeSpecifier() == "FLOAT")
								{
									$$->floating = $1->floating / $3->symboFloat[$3->symboIndex];
									$$->setTypeSpecifier("FLOAT");
									cout<<$$->floating;
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch.Dividing integer with a float\n",line_count);
									$$->floating = $1->floating / (float)($3->symboInt[$3->symboIndex]);
									$$->setTypeSpecifier("FLOAT");
								}
							}
							else
							{
								if(($3->getType() == "CONST_INT" && $3->integer == 0) || ($3->getType() == "CONST_FLOAT" && $3->floating == 0))
								{
									fprintf(errorFile,"Error at line no. %d: Cannot divide by 0\n",line_count);
									error_count++;	
								}
								else if($3->getTypeSpecifier() == "FLOAT")
								{
									$$->floating = $1->floating / $3->floating;
									$$->setTypeSpecifier("FLOAT");
									cout<<$$->floating;
								}
								else if($3->getTypeSpecifier() == "INT")
								{
									fprintf(errorFile,"Warning at line no. %d: Type mismatch.Dividing integer with a float\n",line_count);
									$$->floating = $1->floating / (float)($3->integer);
									$$->setTypeSpecifier("FLOAT");
								}
							}
						}
					}
				}
				else if($2->getName() == "%")
				{
					if($1->getTypeSpecifier() != "INT" || $3->getTypeSpecifier() != "INT")
					{
						fprintf(errorFile,"Error at line no. %d: Unsupported type for mod operation\n",line_count);
						error_count++;
					}
					else if($1->getType() == "ARRAY")
					{
						if($3->getType() == "ARRAY")
						{
							$$->integer = $1->symboInt[$1->symboIndex] % $3->symboInt[$3->symboIndex];
							$$->setTypeSpecifier("INT");
						}
						else
						{
							$$->integer = $1->symboInt[$1->symboIndex] % $3->integer;
							$$->setTypeSpecifier("INT");
						}
					}
					else
					{
						if($3->getType() == "ARRAY")
						{
							$$->integer = $1->integer % $3->symboInt[$3->symboIndex];
							$$->setTypeSpecifier("INT");
						}
						else
						{
							$$->integer = $1->integer % $3->integer;
							$$->setTypeSpecifier("INT");
						}
					}
				}
			$$->symboPrint = $1->symboPrint + $2->getName() + $3->symboPrint;
			fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
	}
     ;

unary_expression : ADDOP unary_expression
		{
			fprintf(logout,"\nAt line no. %d: unary_expression : ADDOP unary_expression\n",line_count);
			$$ = $2;
			$$->symboPrint = $1->getName() + $2->symboPrint;
			fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
		}  
		 | NOT unary_expression
			{
				fprintf(logout,"At line no. %d: unary_expression : NOT unary_expression\n",line_count);
				$$ = $2;
				$$->symboPrint = "^" + $2->symboPrint;
				fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
			} 
		 | factor
			{
				fprintf(logout,"\nAt line no. %d: unary_expression : factor\n",line_count);
			}
		 ;
	
factor	: variable
	{
		fprintf(logout,"\nAt line no. %d: factor : variable\n",line_count);
	}
	| ID LPAREN argument_list RPAREN
	{
		fprintf(logout,"nAt line no. %d: factor : ID LPAREN argument_list RPAREN\n",line_count);
		symboInfo *temp = table.LookUpSymbol($1->getName(),"FUNC");
		if(temp == NULL)
		{
			fprintf(errorFile,"Error at line no. %d: Function does not exist\n",line_count);
			error_count++;
		}
		else
		{
			if(temp->getTypeSpecifier() == "VOID")
			{
				fprintf(errorFile,"Error at line no. %d: Function returns void\n",line_count);
				error_count++;	
			}
			else
			{
				if(temp->getTypeSpecifier() == "INT")
				{
					$$->setTypeSpecifier("INT");
					//$$->symboPrint = $1->getName() +"(" + $3->symboPrint + ")";
					//fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
				}
				else if(temp->getTypeSpecifier() == "FLOAT")
				{
					$$->setTypeSpecifier("FLOAT");
					//$$->symboPrint = $1->getName() + "(" + $3->symboPrint + ")";
					//fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
				}
			}
		}
	}
	| LPAREN expression RPAREN
	{
		fprintf(logout,"\nAt line no. %d: factor : LPAREN expression RPAREN\n",line_count);
		$$ = $2;
		$$->symboPrint = "(" + $2->symboPrint + ")"; 
		fprintf(logout,"\n%s\n\n",$$->symboPrint.c_str());
	}
	| CONST_INT
	{
		fprintf(logout,"\nAt line no. %d: factor : CONST_INT\n",line_count);
		$1->setTypeSpecifier("INT");
		//$1->symboInt[0] = atoi($1->getName().c_str());
		$1->integer = atoi($1->getName().c_str());
		cout<<$1->getType();
		$$->symboPrint = $1->getName();
	} 
	| CONST_FLOAT
	{
		fprintf(logout,"\nAt line no. %d: factor : CONST_FLOAT\n",line_count);
		$1->setTypeSpecifier("FLOAT");
		$1->floating = atof($1->getName().c_str());
		$$->symboPrint = $1->getName();
	}
	| variable INCOP
	{
		fprintf(logout,"\nAt line no. %d: factor : variable INCOP\n",line_count);
		if($1->getType() == "ID")
		{
			if($1->getTypeSpecifier() == "INT") $1->integer = $1->integer + 1;
			else if($1->getTypeSpecifier() == "FLOAT") $1->integer = $1->integer + 1.0;
		}
		else if($1->getTypeSpecifier() == "ARRAY")
		{
			if($1->getTypeSpecifier() == "INT") $1->symboInt[$1->symboIndex] = $1->symboInt[$1->symboIndex] + 1;
			else if($1->getTypeSpecifier() == "FLOAT") $1->symboFloat[$1->symboIndex] = $1->symboFloat[$1->symboIndex] + 1.0;
		}
	} 
	| variable DECOP
	{
		fprintf(logout,"\nAt line no. %d: factor : variable DECOP\n",line_count);
		if($1->getType() == "ID")
		{
			if($1->getTypeSpecifier() == "INT") $1->integer = $1->integer - 1;
			else if($1->getTypeSpecifier() == "FLOAT") $1->integer = $1->integer - 1.0;
		}
		else if($1->getTypeSpecifier() == "ARRAY")
		{
			if($1->getTypeSpecifier() == "INT") $1->symboInt[$1->symboIndex] = $1->symboInt[$1->symboIndex] - 1;
			else if($1->getTypeSpecifier() == "FLOAT") $1->symboFloat[$1->symboIndex] = $1->symboFloat[$1->symboIndex] - 1.0;
		}
	} 
	;
	
argument_list : arguments
		{
			fprintf(logout,"\nAt line no %d: argument_list : arguments\n",line_count);
		}
			  |
			  ;
	
arguments : arguments COMMA logic_expression
		{
			fprintf(logout,"\nAt line no. %d: arguments : arguments COMMA logic_expression\n",line_count);
		}
	      | logic_expression
		{
			fprintf(logout,"\nAt line no. %d: arguments : logic_expression\n",line_count);
		}
	      ;
 
%%
int main(int argc,char *argv[])
{
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	if((yyin=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}
		

	logout= fopen("log.txt","w");
	errorFile= fopen("error.txt","w");
	
	yyparse();
	
	fprintf(logout,"\n Symbol Table: \n");
	table.allScope();

	fprintf(logout,"\n\nTotal Line: %d\n",line_count);
	fprintf(logout,"Total Error: %d\n",error_count);
	fclose(logout);
	fclose(errorFile);
	
	return 0;

}
