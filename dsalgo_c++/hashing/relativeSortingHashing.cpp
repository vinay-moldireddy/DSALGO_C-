//
//  relativeSortingHashing.cpp
//  
//
//  Created by Vinay Kumar Reddy on 17/04/20.
//

#include <iostream>
#include<iterator>
#include<unordered_map>
using namespace std;
void sortRest(int A[],int s,int n)
{
    for(int i=s;i<n;i++)
    {
        for(int j=s;j<n-i;j++)
        {
            if(A[j]<A[j+1])
            {
                int p;
                p=A[j];
                A[j]=A[j+1];
                A[j+1]=p;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}
void relativeSorting(int A[],int B[],int n,int m)
{
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++)
    {
        if(mp.find(A[i])!=mp.end())
        {
            mp[A[i]]=mp[A[i]]+1;
        }
        else
        {
            mp.insert(make_pair(A[i],1));
        }
    }
    int k=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<mp[B[i]];j++,k++)
        {
            A[k]=B[i];
        }
        mp.erase(B[i]);
    }
    int s=k;
    for(auto a:mp)
    {
        A[k]=a.first;
        k++;
    }
    sortRest(A,s,n);
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";

}
int main()
{
    int n,m;
    cin>>n>>m;
    int A[100],B[100];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>B[i];
    }
    relativeSorting(A,B,n,m);
    
}
