//double hashing hash1(key) hash2(key)
//hash1(key)=key%maxlength hash2(key)=prime-(key%prime)

#include<iostream>
using namespace std;
#define table_size 13
#define prime 7
class doublehash
{
	int *hashtable;
	int curr_size;
	public:
		bool isfull()
		{
			return(curr_size==table_size);
		}
		int hash1(int key)
		{
			return (key % table_size);
		}
		int hash2(int key)
		{
			return (prime-(key % prime));
		}
		doublehash()
		{
			hashtable=new int[table_size];
			curr_size=0;
   			for(int i=0;i<table_size;i++)
   			{
   				hashtable[i]=-1;
   			}
   		}
        void inserthash(int key)
        {
        	if(isfull())
        		return;
        	int index = hash1(key);
        	if(hashtable[index]!=-1)
        	{
        		int index2=hash2(key);
        		int i=1;
        		while(1)
        		{
        			int newindex=(index+(i*index2)) % table_size;
        			if(hashtable[newindex]==-1)
        			{
        				hashtable[newindex]=key;
        				break;
        			}
        			i++;
        		}
        
        	}
        	else
        		hashtable[index]=key;
        	curr_size++;
        }
        
        void displayHash()
        {
        	for(int i=0;i<table_size;i++)
        	{
        		if(hashtable[i]!=-1)
        			cout<<i<<" ---> "<<hashtable[i]<<endl;
        		else
        			cout<<i<<endl;
        	}
        }
   
   };



int main()
{
	int a[]={19,27,36,10,64};
	int n=sizeof(a)/sizeof(int);
	doublehash h;
	for(int i=0;i<n;i++)
		h.inserthash(a[i]);
	h.displayHash();
	return 0;
}
   
   
   
   
   
   
   
   
   
   
   
   






