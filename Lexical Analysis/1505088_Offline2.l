%option noyywrap
%x stringType

%{
#include<bits/stdc++.h>

using namespace std;
int line_count=1;
char ch[9999];
char *ch_ptr;
int i=0;
int j=0;
int cnt=0;
int error_count = 0;

FILE *logout;
FILE *tokenout;	

class symboInfo{
    string name;
    string type;
public:
    symboInfo(string nam, string typ)
    {
        this->name = nam;
        this->type = typ;
        this->next = NULL;
    }

    void setName(string name)
    {
        this->name = name;
        this->next = NULL;
    }
    void setType(string type)
    {
        this->type = type;
    }
    string getName()
    {
        return name;
    }
    string getType()
    {
        return type;
    }
    symboInfo *next;
};

class scopeTable{
    symboInfo **table;
    int id;
    int length;
public:
    scopeTable *parentScope;
    scopeTable(int maxLength , int iD)
    {
        this->length = maxLength;
        table = new symboInfo*[maxLength];
        for(int i =0 ; i < maxLength ; i++)
        {
            table[i] = new symboInfo("","");
        }
        this->id = iD;
        this->parentScope = NULL;
    }

    ~scopeTable()
    {
        for(int i =0  ; i< length ; i++)
        {
            delete table[i];
        }
        delete[] table;
        delete[] parentScope;
    }

     int hashF1(string str)            ///DJB2 function
    {
        unsigned long hsh = 5381;

        for(int i =0 ; i< str.size() ; i++)
        {
            hsh = hsh*33 + int(str[i]);
        }
        return hsh%(length);
    }

    bool Insert(string str,string type)
    {
        int j = hashF1(str);
        int pstn = 0;
        //cout<<"\n"<<j;
        symboInfo *newNode ,*temp;
        newNode = new symboInfo("","");
        temp = new symboInfo("","");
        newNode->setName(str);
        newNode->setType(type);

        if(table[j]->getName() == "")
        {
            table[j]=  newNode;
        }
        else
        {
            temp = table[j];
            while(temp->next!=NULL)
            {
                temp = temp->next;
                pstn++;
            }
            temp->next = newNode;
            pstn++;
        }
        cout<< " Inserted in ScopeTable# "<< id<<" at position "<<j <<" , "<<pstn<<endl;;
        return true;
    }

    symboInfo* LookUp(string name)
    {
        int k = hashF1(name);
        symboInfo *temp = new symboInfo("","");
        temp = table[k];
        int i =0 ;
        while (temp != NULL)
        {
            if (temp->getName().compare(name) == 0){
                    cout<<" found at position "<<k<<" , "<<i<<endl;
                    return temp;
            }
            temp = temp->next ;
            i++;
        }
        return NULL;
    }

    bool deleteInfo(string name)
    {
        int i = hashF1(name);
        symboInfo *temp , *bef;
        temp = new symboInfo("","");
        bef = new symboInfo("","");
        int mj = 0;
        temp = table[i];
        if(temp->getName().compare(name) == 0)
        {
            //table[i]->setName("");
            table[i] = table[i]->next;
            cout<<"\n Deleted entry at: "<< i <<","<<0 <<" from current scopeTable"<<endl;
            return true;
        }
        else
        {
            while(temp != NULL)
            {
                if(temp->getName().compare(name) == 0) break;
                bef = temp;
                temp = temp->next;
                mj++;
            }
            if(temp == NULL) return false;
            bef->next = temp->next;
            free(temp);
            cout<<"\n Deleted entry at: "<< i <<","<<mj <<" from current scopeTable"<<endl;
            return true;
        }
    }

    void print()
    {
        symboInfo *temp = new symboInfo("","");
        for(int i =0 ; i<length ; i++)
        {
            temp = table[i];
            //cout<<"  "<<i<<" --->  ";
	    if(temp->getName().compare("") == 0) continue;
	    fprintf(logout,"  %d --->  ",i);
            while(temp!= NULL)
            {
                if(temp->getName().compare("") == 0) break;
                //cout<< "< "<<temp->getName()<<" : "<<temp->getType()<<" >  ";
		fprintf(logout,"< %s : %s > ",temp->getName().c_str(),temp->getType().c_str());
                temp = temp->next;
            }
            //cout<<"\n";
	    fprintf(logout,"\n");
        }
    }

};

class SymbolTable{
    scopeTable *sTable;
    int pos;
    int bucket;
public:
    SymbolTable(int length)
    {
        this->bucket = length;
        this->pos = 1;
        sTable = new scopeTable(bucket,pos);
    }

    void EnterScope()
    {
        pos++;
        scopeTable *st = new scopeTable(bucket,pos);// pos is the id of the new scopeTable
        scopeTable *temp = new scopeTable(bucket,pos);
        temp = sTable;
        st->parentScope = temp;
        sTable = st;
        cout<<" New ScopeTable with id #"<< pos<< " created"<<endl;
    }

    void ExitScope()
    {
        if(sTable == NULL)
        {
            cout<<" No scopeTable remaining"<<endl;
            return;
        }
        scopeTable *temp = new scopeTable(bucket,pos);
        temp = sTable;
        sTable = sTable->parentScope;
        cout<<" ScopeTable with id " <<pos <<" removed" <<endl;
        pos--;
        free(temp);
    }

    bool InsertSymbol(string name , string type)
    {
        if(sTable == NULL) return false;
        if(sTable->LookUp(name) != NULL)
        {
            cout<<" Already exists!!!"<<endl;
            return false;
        }
        sTable->Insert(name,type);
        return true;
        //cout<<"Inserted in ScopeTable# "<<pos <<
    }

    bool RemoveSymbol(string name)
    {
        if(sTable == NULL) return false;
        if(sTable->LookUp(name) == NULL)
        {
            cout<<" Not found\n"<<name<<" not found"<<endl;
            return false;
        }
        sTable->deleteInfo(name);
        return true;
    }

    symboInfo* LookUpSymbol(string name)
    {
	symboInfo *temp1 = new symboInfo("","");
        if(sTable == NULL) return NULL;
	temp1 = sTable->LookUp(name);
        if(temp1 != NULL)
        {
            return temp1;
        }
        else
        {
            scopeTable *temp = new scopeTable(bucket,pos);
            temp = sTable;
            while(temp != NULL)
            {
                if(temp->LookUp(name) != NULL) return temp->LookUp(name);
                temp = temp->parentScope;
            }
            cout<<" Not found"<<endl;
        }
    }

    void currentScope()
    {
        if(sTable == NULL) return;
        cout<<"\n Scope table #"<< pos<<endl;
        sTable->print();
    }

    void allScope()
    {
        scopeTable *temp = new scopeTable(bucket,pos);
        temp = sTable;
        int inst = pos;
        while(temp!=NULL)
        {
            //cout<<"\n Scope table #"<< inst<<endl;
	    fprintf(logout,"\n Scope table #%d\n",inst);
            temp->print();
            temp = temp->parentScope;
            inst--;
        }
    }

};

//hello

SymbolTable st(7);


%}

WHITESPACE [ \t\f\r\v]+
NEWLINE \n
SINGLE_COM '\\[tnafrvb0\']'
UNRECOG '\\[^tnafrvb0\']'

%%
{NEWLINE} { line_count++ ;}
{WHITESPACE}	{}


"if"	{
			fprintf(tokenout,"<IF>");
			fprintf(logout,"Line no %d: TOKEN <IF> Lexeme %s found\n",line_count,yytext);
		}
		
"else"	{
			fprintf(tokenout,"<ELSE>");
			fprintf(logout,"Line no %d: TOKEN <ELSE> Lexeme %s found\n",line_count,yytext);
		}

"for"	{
			fprintf(tokenout,"<FOR>");
			fprintf(logout,"Line no %d: TOKEN <FOR> Lexeme %s found\n",line_count,yytext);
		}
		
"while"	{
			fprintf(tokenout,"<WHILE>");
			fprintf(logout,"Line no %d: TOKEN <WHILE> Lexeme %s found\n",line_count,yytext);
		}
 

"do"	{
			fprintf(tokenout,"<DO>");
			fprintf(logout,"Line no %d: TOKEN <DO> Lexeme %s found\n",line_count,yytext);
		}
		
"break"	{
			fprintf(tokenout,"<BREAK>");
			fprintf(logout,"Line no %d: TOKEN <BREAK> Lexeme %s found\n",line_count,yytext);
		}

"int"	{
			fprintf(tokenout,"<INT>");
			fprintf(logout,"Line no %d: TOKEN <INT> Lexeme %s found\n",line_count,yytext);
		}
		
"char"	{
			fprintf(tokenout,"<CHAR>");
			fprintf(logout,"Line no %d: TOKEN <CHAR> Lexeme %s found\n",line_count,yytext);
		}

"float"	{
			fprintf(tokenout,"<FLOAT>");
			fprintf(logout,"Line no %d: TOKEN <FLOAT> Lexeme %s found\n",line_count,yytext);
		}
		
"double"	{
			fprintf(tokenout,"<DOUBLE>");
			fprintf(logout,"Line no %d: TOKEN <DOUBLE> Lexeme %s found\n",line_count,yytext);
		}

"void"	{
			fprintf(tokenout,"<VOID>");
			fprintf(logout,"Line no %d: TOKEN <VOID> Lexeme %s found\n",line_count,yytext);
		}
		
"return"	{
			fprintf(tokenout,"<RETURN>");
			fprintf(logout,"Line no %d: TOKEN <RETURN> Lexeme %s found\n",line_count,yytext);
		}

"switch"	{
			fprintf(tokenout,"<SWITCH>");
			fprintf(logout,"Line no %d: TOKEN <SWITCH> Lexeme %s found\n",line_count,yytext);
		}
		
"case"	{
			fprintf(tokenout,"<CASE>");
			fprintf(logout,"Line no %d: TOKEN <CASE> Lexeme %s found\n",line_count,yytext);
		}

"default"	{
			fprintf(tokenout,"<DEFAULT>");
			fprintf(logout,"Line no %d: TOKEN <DEFAULT> Lexeme %s found\n",line_count,yytext);
		}
		
"continue"	{
			fprintf(tokenout,"<CONTINUE>");
			fprintf(logout,"Line no %d: TOKEN <CONTINUE> Lexeme %s found\n",line_count,yytext);
		}

[-]?[0-9]+	{
			fprintf(tokenout,"<CONST_INT , %s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <CONST_INT> Lexeme %s found\n",line_count,yytext);
			st.InsertSymbol(string(yytext),"CONST_INT");
			st.allScope();
		}
([0-9]*\.[0-9]+)([Ee][-+]?[0-9]+)?	{
				fprintf(tokenout,"<CONST_FLOAT , %s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_FLOAT> Lexeme %s found\n",line_count,yytext);
				st.InsertSymbol(string(yytext),"CONST_FLOAT");
				st.allScope();	
			}

{SINGLE_COM}	{
				fprintf(tokenout,"<CHAR_CONST,%c%c>",yytext[1],yytext[2]);
				fprintf(logout,"Line no %d: TOKEN <CHAR_CONST> Lexeme %c%c found\n",line_count,yytext[1],yytext[2]);
				st.InsertSymbol(string(yytext),"CHAR_CONST");
				st.allScope();
		}
{UNRECOG}|'\''	{
			st.LookUpSymbol(string(yytext));
			fprintf(logout,"Error on line no %d: Unrecognized character %s\n",line_count,yytext);
			error_count++;
		}


'[.]|'\\'	{
			fprintf(logout,"Error on line no %d: Unfinished character %s\n",line_count,yytext);
			error_count++;
		}

'.'	{
			fprintf(tokenout,"<CHAR_CONST,%c>",yytext[1]);
			fprintf(logout,"Line no %d: TOKEN <CHAR_CONST> Lexeme %c found\n",line_count,yytext[1]);
			st.InsertSymbol(string(yytext),"CHAR_CONST");
			st.allScope();
		}

[a-zA-Z_][a-zA-Z0-9_]*	{
				fprintf(tokenout,"<ID , %s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <ID> Lexeme %s found\n",line_count,yytext);
				st.InsertSymbol(string(yytext),"ID");
				st.allScope();
			}

"+"|"-"		{
			fprintf(tokenout,"<ADDOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ADDOP> Lexeme %s found\n",line_count,yytext);
			st.InsertSymbol(string(yytext),"ADDOP");
			st.allScope();
		}

"*"|"/"|"%"		{
				fprintf(tokenout,"<MULOP,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <MULOP> Lexeme %s found\n",line_count,yytext);
				st.InsertSymbol(string(yytext),"MULOP");
				st.allScope();
		}
"++"|"--"	{
			fprintf(tokenout,"<INCOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <INCOP> Lexeme %s found\n",line_count,yytext);
			st.InsertSymbol(string(yytext),"INCOP");
			st.allScope();
		}

"<"|"<="|">"|">="|"=="|"!="	{
					fprintf(tokenout,"<RELOP,%s>",yytext);
					fprintf(logout,"Line no %d: TOKEN <RELOP> Lexeme %s found\n",line_count,yytext);
					st.InsertSymbol(string(yytext),"RELOP");
					st.allScope();
				}

"="		{
			fprintf(tokenout,"<ASSIGNOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ASSIGNOP> Lexeme %s found\n",line_count,yytext);
			st.InsertSymbol(string(yytext),"ASSIGNOP");
			st.allScope();
		}

"&&"|"||"	{
			fprintf(tokenout,"<LOGICOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LOGICOP> Lexeme %s found\n",line_count,yytext);
			st.InsertSymbol(string(yytext),"LOGICOP");
			st.allScope();
		}

"<<"|">>"|"&"|"|"|"^"	{
				fprintf(tokenout,"<BITOP,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <BITOP> Lexeme %s found\n",line_count,yytext);
				st.InsertSymbol(string(yytext),"BITOP");
				st.allScope();
		}

"!"		{
			fprintf(tokenout,"<NOT,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <NOT> Lexeme %s found\n",line_count,yytext);
			st.InsertSymbol(string(yytext),"NOT");
			st.allScope();
		}
"("		{
			fprintf(tokenout,"<LPAREN,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LPAREN> Lexeme %s found\n",line_count,yytext);
		}
")"		{
			fprintf(tokenout,"<RPAREN,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RPAREN> Lexeme %s found\n",line_count,yytext);
		}
"{"		{
			fprintf(tokenout,"<LCURL,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LCURL> Lexeme %s found\n",line_count,yytext);
		}
"}"		{
			fprintf(tokenout,"<RCURL,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RCURL> Lexeme %s found\n",line_count,yytext);
		}
"["		{
			fprintf(tokenout,"<LTHIRD,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LTHIRD> Lexeme %s found\n",line_count,yytext);
		}
"]"		{
			fprintf(tokenout,"<RTHIRD,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RTHIRD> Lexeme %s found\n",line_count,yytext);
		}
","		{
			fprintf(tokenout,"<COMMA,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <COMMA> Lexeme %s found\n",line_count,yytext);
		}
";"		{
			fprintf(tokenout,"<SEMICOLON,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <SEMICOLON> Lexeme %s found\n",line_count,yytext);
		}



"/*"([^*]|(\*+[^*/]))*[\*]+"/"	{
					for(int l = 0; l<yyleng ; l++){if(yytext[l] == '\n') line_count++;}
					fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s found\n",line_count,yytext);
			}
"//".*	{
				for(int l = 0; l<yyleng ; l++){if(yytext[l] == '\n') line_count++;}
				fprintf(logout,"Line no %d: Token <COMMENT> Lexeme %s found\n",line_count,yytext);
		}

\"		{
			BEGIN(stringType);
			//cnt = line_count;
		}
<stringType>\n	{
			for(int l = 0; l<yyleng ; l++){if(yytext[l] == '\n') line_count++;}
			fprintf(logout,"Error on line %d: unfinished string\n",line_count);
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
			fprintf(tokenout,"<STRING,%s>",ch);
			fprintf(logout,"Line no %d: TOKEN <STRING> Lexeme %s found\n",line_count,ch);
			i =0 ;
		}

			
[0-9]*\.+[0-9]+.+	{
				fprintf(logout,"Error on line no %d: Too many decimal points error %s!!\n",line_count,yytext);
				error_count++;
		}


[0-9]+[Ee][-+]?(\.*[0-9]*\.*[0-9]*)*	{

				fprintf(logout,"Error on line no %d: Ill formed numbers %s!!\n",line_count,yytext);
				error_count++;
		}
				
([0-9]+|[0-9]*\.[0-9]+)[a-zA-Z]+	{
						fprintf(logout,"Error on Line no %d: Invalid Suffix or prefix\n",line_count);
						error_count++;
				}

'[a-zA-Z0-9]+[a-zA-Z0-9]+'		{
			fprintf(logout,"Error on line no %d: Multi character constant error %s\n",line_count++,yytext);
			error_count++;
		}
	
"/*"([^*]|(\*+[^*/]))*	{
				fprintf(logout,"Error on line %d: Unfinished Comment\n",line_count++);
				error_count++;		
		}
			
%%

int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	logout= fopen("log.txt","w");
	tokenout= fopen("token.txt","w");

	yyin= fin;
	yylex();
	fprintf(logout,"Total Line: %d\n",line_count);
	fprintf(logout,"Total Error: %d\n",error_count);
	//st.allScope();
	fclose(yyin);
	fclose(tokenout);
	fclose(logout);
	return 0;
}
