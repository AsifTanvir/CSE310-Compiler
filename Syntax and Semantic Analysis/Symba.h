#include<bits/stdc++.h>

using namespace std;

//int maxLength = 99999;
int line_count=1;
int error_count = 0;

FILE *logout;
FILE *errorFile;

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

    int LookUp(string name)
    {
        int k = hashF1(name);
        symboInfo *temp = new symboInfo("","");
        temp = table[k];
        int i =0 ;
        while (temp != NULL)
        {
            if (temp->getName().compare(name) == 0){
                    cout<<" found at position "<<k<<" , "<<i<<endl;
                    return 1;
            }
            temp = temp->next ;
            i++;
        }
        //cout<<"Not found"<<endl;
        return 0;
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
            cout<<"  "<<i<<" --->  ";
            while(temp!= NULL)
            {
                if(temp->getName().compare("") == 0) break;
                cout<< "< "<<temp->getName()<<" : "<<temp->getType()<<" >  ";
                temp = temp->next;
            }
            cout<<"\n";
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
        //scopeTable *st = new scopeTable(bucket,pos);// pos is the id of the new scopeTable
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
        if(sTable->LookUp(name) == 1)
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
        if(sTable->LookUp(name) == 0)
        {
            cout<<" Not found\n"<<name<<" not found"<<endl;
            return false;
        }
        sTable->deleteInfo(name);
        return true;
    }

    int LookUpSymbol(string name)
    {
        if(sTable == NULL) return false;
        if(sTable->LookUp(name) == 1)
        {
            return 1;
        }
        else
        {
            scopeTable *temp = new scopeTable(bucket,pos);
            temp = sTable;
            while(temp != NULL)
            {
                if(temp->LookUp(name) == 1) return 1;
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
            cout<<"\n Scope table #"<< inst<<endl;
            temp->print();
            temp = temp->parentScope;
            inst--;
        }
    }

};
