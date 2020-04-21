#include<iostream>
#include<queue>
using namespace std;
class Node
{
public:
	int key;
	Node* left;
	Node* right;
};

Node* newNode(int data)
{
	Node* temp= new Node;
	temp->key=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void inorder(Node* root)
{
	if(!root)
		return;
	inorder(root->left);
	cout<<root->key<<"  ";
	inorder(root->right);
} 

void preorder(Node* root)
{
	if(!root)
		return;
	cout<<root->key<<"  ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node* root)
{
	if(!root)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->key<<"  ";
}

//we need to delete deepest node since we copide deepest node key
void deleteDeepest(Node* root, Node* d_node)
{
	queue<Node*> q; 
    q.push(root); 
  
    // Do level order traversal until last node 
    struct Node* temp; 			
    while (!q.empty()) { 	
        temp = q.front(); 
        q.pop(); 
        if (temp == d_node) { 
            temp = NULL; 
            delete (d_node); 
            return; 
        } 
        if (temp->right) { 
            if (temp->right == d_node) { 
                temp->right = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp->right); 
        } 
  
        if (temp->left) { 
            if (temp->left == d_node) { 
                temp->left = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp->left); 
        } 
    } 

}

Node* del(Node* root,int key)
{
	if(root==NULL)
		return NULL;
	if(root->left==NULL && root->right==NULL)
	{
		if(root->key==key)
			return NULL;
		else 
			return root;
	}

	//level order traversal to find key

	queue<Node*> q;
	q.push(root);
	Node* temp;
	Node* key_node=NULL;
	while(!q.empty())
	{
		temp=q.front();
		q.pop();

		if(temp->key==key)
			key_node=temp;
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	if(key_node!=NULL)
	{
		int x=temp->key;
		deleteDeepest(root,temp);
		key_node->key=x;

	}
	return root;

}
void insert(Node* temp, int key)
{
	queue<Node* > q;
	q.push(temp);
	while(!q.empty()){
		Node* temp=q.front();
		q.pop();
		if(!temp->left)
		{
			temp->left=newNode(key);
			break;
		}
		else q.push(temp->left);
		if(!temp->right)
		{
			temp->right=newNode(key);
			break;
		}
		else q.push(temp->right);
	}
}

void levelordertraversal(Node* temp)
{
	while(temp==NULL)
	{
		return;
	}
	queue<Node* > q;
	q.push(temp);
	while(!q.empty())
	{
		Node* temp= q.front();
		cout<<temp->key<<"  ";
		q.pop();
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
		
	}
}



int main()
{	
	Node* root= newNode(1);
	// root->left=newNode(2);
	// root->right=newNode(3);
	// root->left->left=newNode(4);	
	// root->left->right=newNode(5);
	// inorder(root);
	// cout<<"\n";
	// insert(root,6);
	// insert(root,7);
	// insert(root,8);
	// inorder(root);
	// cout<<"\n";
	// root=del(root,1);
	// cout<<"\n";
	// root=del(root,5);
	inordersert(root,2);
	insert(root,3);
	insert(root,4);
	insert(root,5);
	insert(root,6);
	inorder(root);
	cout<<"\n";
	levelordertraversal(root);
	cout<<"\n";
	root=del(root,3);
	inorder(root);

}