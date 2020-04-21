#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char str[10];
    struct node* next;
    struct node* back;
}node;
node* insert(node* head)
{
    node* trav = head;
    node* temp=(node*)malloc(sizeof(node));
    printf("name\n");
    scanf("%s",temp->str);
    while(trav->next!=NULL)
    {
        trav=trav->next;
    }
    trav->next=temp;
    temp->next=NULL;
    temp->back=trav;
    return temp;
}

void Printll(node* head)
{
    node* temp=head;
    while(temp->next!=NULL)
    {
        printf("%s\n",temp->str);
        temp=temp->next;
    }
    printf("%s\n",temp->str);
}

void Printlltail(node* tail)
{
    node* temp=tail;
    while(temp->back!=NULL)
    {
        printf("%s\n",temp->str);
        temp=temp->back;
    }
    printf("%s\n",temp->str);
}

void Swap(node* head)
{
    node *curr=head->next->next;
    node *prev = head;
    head = head->next; 
    head->next = prev;
    head->next->next=curr;
       // char temp[100];
       // memcpy(temp, a->str, sizeof(a->str));
       // memcpy(a->str, b->str, sizeof(b->str));
       // memcpy(b->str, temp, sizeof(temp));
}
        // node* subsort(node* temp)
        // {
        //     if(temp->next==0)
        //     {
        //         return temp;
        //     }
        //     else
        //     {
        //     int a = (temp->str)[0];
        //     int b = (temp->next->str)[0];
        //     printf("%d\n", a);
        //     printf("%d\n", b);
        //     printf("...");
        //     if(a>=b)

        //     { 
        //            printf("swapped\n");
        //            node *curr=temp->next->next;
        //            node *prev = temp; 
        //            temp = temp->next; 
        //            temp->next = prev;
        //            temp->next->next=curr;

        //            prev=temp;
        //            curr=temp->next->back;
        //            temp->next->back=prev;
        //            temp->back=curr;
        //            temp->next->next->back=temp->next;

        //     }

        //     subsort(temp->next);
        //     return temp;
        //    }
           
        //  }
int Length(node* curr)
{
    int len=0;
    while(curr!=NULL)
    {
        curr=curr->next;
        len++;
    }
    return len;
}
node* bubblesort(node* temp2,int p,int length)
{
    if(temp2==NULL)
    {
        return NULL;
    }
    node* curr;
    node* prev;
    node* head=temp2;
    int constant=length;
    for(int i=1; i<length; i++)
    {        
        curr=head;
        prev=NULL;
        while(constant-1)
        {
            constant--;
            node *n=curr->next;
            int a=(curr->str)[p];
            int b=(n->str)[p];
            printf("%d\n%d\n\n\n", a,b);



            if(a>b)
            {
                if(prev==NULL)
                {
                    printf("esdjffh\n");
                    curr->next=n->next;
                    n->next=curr;
                    prev=n;
                    head=n;
                    printf("dfhfhlsfhlsdfh\n");
                }
                else
                {
                    printf("entered to swap");
                    curr->next=n->next;
                    n->next=curr;
                    prev->next=n;
                    prev=n;
                }


            }

            else
            {
                prev=curr;
                curr=curr->next;
            }
            
        }
    }
    node *temp=head;
    node* forfun;
    printf("completed a level of swap\n");
    if(temp2!=NULL)
    {
        printf("entered into recursion statement\n");
        for(int i=0;i<length;i++)
        {
            int asdf=0;
        while(temp->next && (temp->str)[p]==(temp->next->str)[p])
        {
            if(asdf==0)
                 forfun =temp;
            temp=temp->next;
            asdf++;
            length++;
        }

        temp2=bubblesort(forfun,p++,asdf);
        }
    }

    return head;
    
}

int main()
{
    node *head;
    node *tail;
    head=(node*)malloc(sizeof(node));
    tail=head;
    printf("enter string\n");
    scanf("%s",head->str);
    head->next=NULL;
    head->back=NULL;
    tail=insert(head);
    tail=insert(head);
    tail=insert(head);
    printf("\n\n\n\n");
    Printll(head);
    printf("\n\n\n\n");
    //Swap(head,head->next);
    int length=Length(head);
    head=bubblesort(head,0,length);
    // node *curr=head->next->next;
    // node *prev = head; 
    // head = head->next; 
    // head->next = prev;
    // head->next->next=curr;
    
    //  Printll(head);
    Printll(head);
    // node *a;
    // node *b;
    // a=(node*)malloc(sizeof(node));
    // b=(node*)malloc(sizeof(node));
    // scanf("%s",a->str);
    // scanf("%s",b->str);
    // swap(a,b);
    // printf("%s\n",a->str);
    // printf("%s\n",b->str);
    // int n=(a->str)[0];
    // printf("%d\n",n);

}