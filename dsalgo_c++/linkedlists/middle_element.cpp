#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
	node(int a)
	{
		this->data=a;
		this->next=NULL;
	}
};
node* createnewll()
{
	int n;cout<<"number of n: ";cin>>n;
	int temp;cin>>temp;
	node* ll=new node(temp);
	node* head=ll;
	for(int i=1;i<n;i++)
	{
		cin>>temp;
		head->next=new node(temp);
		head=head->next;
	}
	return ll;
}
void printll(node* temp)
{
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int middleElement(node* head)
{
	node* single=head;
	node* doub=head;
	while(doub!=NULL && doub->next!=NULL)
	{
		doub=doub->next->next;
		single=single->next;
	}
	return single->data;
}

void reverse(node **head)
{
	node* temp=NULL;
	node* prev;
	node* nex=*head;

while(nex!=NULL)
{
	prev=temp;
	temp=nex;
	nex=temp->next;


	temp->next=prev;
}


	*head = temp;
}


void rotate(node** head,int n)
{
	if(*head==NULL)
		return;
	node *temp=*head;
	for(int i=0;i<n-1;i++)
		temp=temp->next;
	node *nthnode=temp;
	if(temp==NULL)
		return;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next = *head;
	*head = nthnode->next;
	nthnode->next = NULL;

}


node* reverseInGroups(node* head,int n)
{
	node* check=head;
	for(int i=0;i<n;i++)
	{
		if(check->next==NULL)
		{
			reverse(&head);
			return head;
		}
		check=check->next;
	}

	node* prev;
	node* nex=head;
	node* temp=NULL;
	for(int i=0;i<n;i++)
	{
		prev=temp;
		temp=nex;
		nex=nex->next;
 
		temp->next=prev;
	}

	head->next=reverseInGroups(nex,n);
	return temp;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		node* head=createnewll();
		//printll(temp);
		//cout<<middleElement(temp)<<endl;
		reverse(&head);
		printll(head);
		int r;cout<<"rotations:";cin>>r;
		rotate(&head,r);
		printll(head);
		cout<<"reverseBy:";cin>>r;
		head=reverseInGroups(head,r);
		printll(head);
	}
	return 0;
}