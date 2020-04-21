#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
template<typename T>
class Node{

public:
	string key;
	T value;
	Node<T>* next;
 
	Node(string key, T val){		//constructor 
		this->key=key;
		this->value=val;
		next=NULL;
	}
	~Node(){
		if(next!=NULL){
			delete next;
		}
	}
};
template<typename T>
class Hashtable{
	Node<T>** table;				//table variable is pointer pointing to arrayof pointers
	int current_size;
	int table_size;

	int hashfn(string key){			//we put hashfunction in privete so that only hash table can access it.
		int index=0;
		int p=1;
		for(int i=0;i<key.length();i++)
		{
			index=index+ (key[i]+p)%table_size;
			index=index%table_size;
			p=(p*27)% table_size;
		}
		return index;
	}
	void rehash(){
		Node<T>** oldTable = table;
		table_size=2*table_size;
		table = new Node<T>*[table_size];
		for(int i=0;i<table_size;i++){
			table[i]=NULL;
		}
		current_size=0;
		//shift elements from old to new table
		for(int i=0;i<(table_size/2);i++){
			Node<T>*temp=oldTable[i];
			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp=temp->next;
			}
			if(oldTable[i]!=NULL){		//recursive distructor call
				delete oldTable[i];  
			}
		}
		delete [] oldTable; 
	}

public:
	Hashtable(int ts=7){	//hashtable constructor 
		table_size=ts;
		table=new Node<T>*[table_size];
		current_size=0;
		for(int i=0;i<table_size;i++)
		{
			table[i]=NULL;
		}
        }
		void insert(string key,int val)
		{
			int index=hashfn(key);
			Node<T>* n= new Node<T>(key,val);
			n->next=table[index];
			table[index]=n;
			current_size++;
			float lf=current_size/(1.0*table_size);
			if(lf>0.7)
				{

					rehash();
				}

		}
		void prnt()
		{
			for(int i=0;i<table_size;i++){
				cout<<"Bucket "<<i<<" ->";
				Node<T>*temp=table[i];
				while(temp!=NULL){
					cout<<temp->key<<"-->"; 
					temp=temp->next;
				}
				cout<<"\n";
			}
		}

		T* search(string key){
			int index=hashfn(key);
			Node<T>*temp=table[index];
			while(temp!=NULL)
			{
				if(temp->key==key){
					return &(temp->value);
				}
				temp=temp->next;
			}
			return NULL;

		}

		T& operator[](string key){
			T * f=search(key);
			if(f==NULL){
				T garbage;
				insert(key,garbage);
				f=search(key);
			}
			return *f;
		}
		void erase(string key){
			int index=hashfn(key);
			Node<T>*temp=table[index];
			Node<T>*prev=table[index];
			if(table[index]->key==key)
			{
				table[index]=table[index]->next;
				free(temp);
				return;
			}
			while(table[index]->next!=NULL)
			{
				if(table[index]->next->key==key){
					table[index]->next=table[index]->next->next;
					free(table[index]->next);
					temp->next=table[index]->next;
					table[index]=temp;
					cout<<"......."<<endl;
					return;
				}
				table[index]=table[index]->next;
			}

		}

};                         