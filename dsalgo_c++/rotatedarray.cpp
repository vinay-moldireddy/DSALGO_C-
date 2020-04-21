//17-4-2020
#include<iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) 
{ 
	if(arr[l]==x)
		return l;
	if(arr[r]==x)
		return r;
    if (r>=l) { 
        int mid=l+(r-l)/2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
        return binarySearch(arr, mid + 1, r, x); 
    } 
    return -1; 
} 

int main()
{
	int arr[100];
	int n;cin>>n;
	int head,tail;
	if(arr[0]>arr[n]) {head=n;tail=0;}
    else {head=0;tail=n;}
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		if(arr[i]>arr[i+1] && arr[i+1]<arr[i+2])
			{head=i+1,tail=i+2; break;}
		if(arr[i]<arr[i+1] && arr[i+1]>arr[i+2])
			{tail=i+1,head=i+2; break;}
	}

    cout<<head<<","<<tail<<endl;
	int s;cout<<"enter number to search:";cin>>s;


	if(head<tail) 
	{
		if(s<=arr[0])
			{
				cout<<binarySearch(arr,0,head,s);
			}
		else
			{
				cout<<binarySearch(arr,tail,n,s);
			}
	}
	else
		{
		if(s>=arr[0])
			{
				cout<<binarySearch(arr,0,tail,s);
			}
		else
			{
				cout<<binarySearch(arr,head,n,s);
			}
		}
}
