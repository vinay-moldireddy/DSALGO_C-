//algorithm 
//we take an array and strore all the ugly numbers one by one
//unlike we do in normal method by checking each and every number from 1 to n;

//ugly[] array starting with 1;
//next uglynumber is calculated my minimum of next multiple of 2 , 3 , 5;

#include<iostream>
#include<algorithm>
using namespace std;
unsigned getnthuglynum(unsigned n)
{
	unsigned ugly[1000]={0};
	unsigned i2,i3,i5; //to use as index for array
	unsigned next_multiple_of_2 =2;
	unsigned next_multiple_of_3 =3;
	unsigned next_multiple_of_5 =5;
	unsigned next_ugly_no =1;
	ugly[0]=next_ugly_no;
	for(unsigned i=1;i<n;i++)
	{
		next_ugly_no=std::min(next_multiple_of_2, std::min(next_multiple_of_3, next_multiple_of_5));
		ugly[i]=next_ugly_no;
		if(next_ugly_no==next_multiple_of_2)
		{
			i2=i2+1;
			next_multiple_of_2=ugly[i2]*2;
		}
		if(next_ugly_no==next_multiple_of_3)
		{
			i3=i3+1;
			next_multiple_of_3=ugly[i3]*3;
		}
		if(next_ugly_no==next_multiple_of_5)
		{
			i5=i5+1;
			next_multiple_of_5=ugly[i5]*5;
		}
	}
	return next_ugly_no;
}
int main()
{
	unsigned n;
	cin>>n;
	cout<<getnthuglynum(n)<<endl;
	return 0;
}