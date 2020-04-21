#include<iostream>
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
			return index;
		}
	}

public:
	Hashtable(int ts=7){	//hashtable constructor 
		table_size=ts;
		table=new Node<T>*[table_size];
		int current_size=0;
		for(int i=0;i<table_size;i++)
		{
			table[i]=NULL;
		}

		void insert(string key,T val)
		{
			int index=hashfn(key);
			Node<T>* n= new Node<T>(key,val);
			n->next=table[index];
			table[index]=n;
			current_size++;

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
			}
		}
		// T search(string key){

		// }
		// void erase(){

		// }
}
};                         

int main()
{

	return 0;
}