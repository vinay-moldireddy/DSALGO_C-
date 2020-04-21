#include<iostream>
using namespace std;
class node{
public:
	int key;
	node* left;
	node* right;
};	

void printn(node* root)
{
	if(root==NULL)
		return;
	printn(root->left);
	cout<<root->key<<" ";
	printn(root->right);
	return;
}

int height(node* root)
{
	cout<<" .";
 	if(root==NULL)
 		return 0;
 	int h1=1+height(root->left);
 	int h2=1+height(root->right);
 	return max(h1,h2);
}

int diameter(node* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int opt1=diameter(root->left);
	int opt2=diameter(root->right);
	int opt3=height(root->left)+height(root->right);
	return max(max(opt1,opt2),opt3);
}
int main()
{	
	cout<<" ";
	node *root=new node;
	root->key=11;
	root->left= new node;
	root->right= new node;
	root->left->key=1;
	root->right->key=2;
	root->left->left=new node;
	root->left->left->key=3;
	root->left->left->left=new node;
	root->left->left->left->key=4;
    root->left->left->left->right=new node;
    root->left->left->left->right->key=10;
	root->right->left=new node;
	root->right->left->key=4;

	printn(root);
	cout<<"height :";
	cout<<height(root)<<endl;
	cout<<"diameter : ";
	cout<<diameter(root)<<endl;
	return 0;
}
