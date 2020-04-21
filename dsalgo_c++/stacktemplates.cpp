#include <iostream>
#include <vector>
using namespace std;

//template<template T,template U>  
template<typename T,template U>  //can use any number of templates

class Stack
{
	vector<T> v;
	vector<U> v2;
public:
	void push(T data){
		v.push_back(data);
	}
	bool empty(){
		return v.size()==0;
	}
	void pop(){
		if(!empty()){
			v.pop_back();
		}
	}
	T top(){
		return v[v.size()-1];
	}
};

int main(){
	Stack<char> s;
	for(int i=60;i<=75;i++){
		s.push(i);
	}

	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
} 