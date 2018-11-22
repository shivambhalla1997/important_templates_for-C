#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* Insert_Node(struct Node* head, int new_data)  // Insert node in the beggining of the Linked list
{
    struct Node* new_Node=(struct Node*)malloc(sizeof(struct Node));
    new_Node->data=new_data;
    if(head==NULL)
    {
        head=new_Node;
    }
    else
    {
        new_Node->next=head;
        head=new_Node;
    }
    return head;
}

void print_Linked_List_type_1(struct Node* head) // print the linked list with recursion 
{`
    if(head==NULL)
    return;
    cout<<head->data;
    print_Linked_List_type_1(head->next);
    return ;
}

void print_Linked_List_reverse_type_1(struct Node* head) // print the reverse linked list with recursion 
{
    if(head==NULL)
    return;
    print_Linked_List_reverse_type_1(head->next);
    cout<<head->data;
    return;
}

void print_Linked_List_type_2(struct Node* head) // print the LL without recusrion
{
    while(head!=NULL)
    {
        cout<<head->data;
        head=head->next;
    }
    return;
}

struct Node* Insert_Node_At_Nth_position(struct Node* head, int data, int position)
{
    struct Node* new_Node=(struct Node*)malloc(sizeof(struct Node));  // generating a new Node
    new_Node->data=data;
    struct Node* new_head=head;
    while(new_head!=NULL && position>0)
    {
        new_head=new_head->next;
        position--;
    }
    
}

int main()              // main function
{
    struct Node* head;
    head=NULL;
    head=Insert_Node(head,3);
    head=Insert_Node(head,5);
    head=Insert_Node(head,7);
    head=Insert_Node(head,9);
    print_Linked_List_reverse_type_1(head);
  return 0;  
}
