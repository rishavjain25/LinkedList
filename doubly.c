#include<stdio.h>
#include<malloc.h>
//implementing doubly linked list

typedef struct Node
{
    struct Node* prev;
	int data;
	struct Node* next;
}Node;

int countNodes(Node* head)
{
	int count = 0;
	while(head != NULL){
		count++;
	    head = head -> next;
	}

	return count;
}

void insertAtBegin(Node** head,int data)
{
    Node* new = (Node*)malloc(sizeof(Node));
    new -> prev = NULL;
    new -> data = data;
    new -> next = NULL;
	if((*head) == NULL)
	{
	   *head = new;
	}
	else{
		new -> next = *head;
		(*head) -> prev = new;
		*head = new;
	}
	return;
}

void insertAtLast(Node** head,int data)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new -> prev = NULL;
	new -> data = data;
	new -> next = NULL;
	if((*head) == NULL)
		*head = new;
	else{
		Node* current = *head;
		while(current -> next != NULL)
			current = current -> next;
		new -> prev = current;
		current -> next = new;
	}
}

void insertAtPosition(Node** head,int data,int p)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new -> data = data;
	new -> prev = NULL;
	new -> next = NULL;
	int count = countNodes(*head);
	if( p > count + 1)
		return;
	if( p == 1)
	{
		new -> next = *head;
		if((*head) != NULL )
			(*head) -> prev = new;
	  	*head = new;
	     return;
	}
    Node* current = *head;
    int position = 1;
    while(position < p-1 )
    {
    	position++;
    	current = current -> next;
    }
    new -> next = current -> next;
    if(current -> next != NULL)
        current -> next -> prev = new;
    
    new -> prev = current;
    current -> next = new;
    return;
}

void print(Node* head)
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head -> next; 
    }
    puts("..");
    return;
}

int main()
{
    Node* head = NULL;	
    insertAtBegin(&head,1);
    insertAtBegin(&head,2);
    insertAtPosition(&head,3,3);
    insertAtPosition(&head,10,2);
    print(head);
}