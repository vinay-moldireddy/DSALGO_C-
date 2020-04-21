#include<iostream>
#include"hashtable.h"
using namespace std;

int main()
{
	Hashtable<int> price_menu;
	price_menu.insert("Bur",100);
	price_menu.insert("zza",150);
	price_menu.insert("pep ",50);
	price_menu.insert("chicken",150);
	price_menu.insert("chaap",110);
	price_menu.insert("wic",70);
    price_menu.prnt();

    int *price=price_menu.search("chaap");
    if(price==NULL){
    	cout<< "Not found";

    }
    else
    {
    	cout<<"Price is "<<*price<<endl;
    }
     
    price_menu.erase("chaap");
    price_menu.prnt();



    price_menu["Dosa"]=60;
    price_menu["Dosa"]+=10; 
    price_menu.prnt();
    cout<<"price of Dosa "<<price_menu["Dosa"]<<endl;   //will return T (price)
    return 0;
} 