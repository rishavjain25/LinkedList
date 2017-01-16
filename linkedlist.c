#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
typedef struct Node
{
    int data;
   struct Node* next ;
}Node;

void deleteAtBegin(Node** head)
{
    if(*head == NULL)
    	return;
    Node* temp = *head;
    (*head) = (*head) -> next;
    free(temp);
}

void deleteAtLast(Node** head)
{
    if(*head == NULL)
    	return;
    Node* current = *head;
    while(current -> next != NULL && current -> next -> next != NULL)
    {
        current = current -> next;
    }
    if(current -> next == NULL)
    	*head = NULL;
    else
    {
    	Node* temp = current -> next;
    	current -> next = NULL;
        free(temp);
    }
}

void deleteAtPosition(Node** head,int p)
{
    if(*head == NULL)
    	return;
    if(p == 1)
    {
    	Node* temp = *head;
    	(*head) = (*head) -> next;
        free(temp);
    }

    int count = countNodes(*head);
    
    if(p > count)
    {
    	puts("Invalid position");
    	return;
    }

    int position = 1;
    Node* current = *head;
    while(position < p -1)
    {
        position++;
        current = current -> next;
    }

    Node* temp = current -> next;
    current->next = current -> next -> next;
    free(temp);

}

void insertAtBegin(Node** head,int data)
{
   Node* new = (Node*)malloc(sizeof(Node));
   new -> data = data;
   new -> next = NULL;
   if((*head) == NULL)
       (*head) = new;
   else
   {
       new -> next = (*head);
       *head = new; 
   }   
   return; 
}

void insertAtLast(Node** head,int data)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = data;
	new->next = NULL;
	if(*head == NULL)
		*head = new;
	else{
		Node* current = *head;
		while(current -> next != NULL)
			current = current -> next;
        current -> next = new;
 	}
 	return;
}

int countNodes(Node* head)
{
	int count = 0;
	while(head != NULL){
		count++;
	    head = head -> next;
	}

	return count;
}

void insertAtPosition(Node** head,int p,int data)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new -> data = data;
	new -> next = NULL;
	int count = countNodes(*head);
	if(p == 1)
	{
		new -> next = *head;
		*head = new;
		return;
	}
	if( p > count + 1)
	{
		printf("Not a valid position\n");
	    return;
	}

	int position = 1;
	Node* current = *head;
	while(position < p-1)
	{
		position++;
		current = current -> next;
	}
	new ->next = current->next;
	current ->next = new;
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

void swapNodes(int x,int y,Node** head)
{
	if( x == y) return;
    Node* prevx = NULL, *currx = *head;
    while(currx && currx -> data != x)
    {
    	currx = currx -> next;
    }

    Node* prevy = NULL, *curry = *head;
    while(curry && curry -> data != y)
    {
    	curry = curry -> next;
    }

    if(currx == NULL || curry == NULL)
    	return;

    if(prevx == NULL)
    	*head = curry;
    else
    	prevx -> next = curry;

    if(prevy == NULL)
    	*head = currx;
    else
    	prevy -> next = currx;

    Node* temp = curry -> next;
    curry -> next = currx -> next;
    currx -> next = temp;
}

/* void swapNodes(Node** head,int a,int b)
{
	if(*head == NULL)
		return;
	
	//find a
	Node* acurrent = *head;
	bool A_at_Head = false;
    if(acurrent -> data == a)
    {
    	A_at_Head = true;
    }
    else{

    while(acurrent -> next != NULL && acurrent -> next -> data != a)
    {
    	acurrent = acurrent->next;
    }

    if(acurrent -> next == NULL)
    {
        //a not found
        return;
    
    }
    }

    //find b
    Node* bcurrent = *head;
    bool B_at_Head = false;
    if(bcurrent -> data == b)
    {
    	B_at_Head = true;
    }
    else{

    	while(bcurrent -> next != NULL && bcurrent -> next -> data != b)
    	{
    		bcurrent = bcurrent -> next;
    	}

    	if(bcurrent -> next == NULL)
    	{
    	    //b not found
    		return;
        }
    }

    //now swap both nodes

    if(A_at_Head == true)
    {
    	Node* temp = bcurrent -> next -> next;
        bcurrent -> next -> next = (*head) -> next;
        (*head) -> next = temp;
        temp = bcurrent -> next;
        bcurrent -> next = *head;
        *head = temp;
    }

}*/

Node* reverse(Node** head)
{
	Node* prev = NULL;
	Node* next = NULL;
	Node* curr = *head;
	while(curr != NULL)
	{
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}

	*head = prev;
}

int main()
{
    Node* head = NULL;
    insertAtBegin(&head,1);
    insertAtBegin(&head,2);
    insertAtBegin(&head,3);
    insertAtBegin(&head,4);
    insertAtBegin(&head,5);
    insertAtBegin(&head,6);
    print(head);
    reverse(&head);
    print(head);

}
