#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
typedef struct Node
{
    int data;
   struct Node* next ;
}Node;

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

 Node* merge(Node* head1,Node* head2)
 {
 	if(head1 == NULL)
 		return head2;
 	if(head2 == NULL)
 		return head1;

 	Node* head3 = (Node*)malloc(sizeof(Node));
 	head3 -> next = NULL;
 	 Node* start = head3;
 	while(head1 !=NULL && head2 != NULL)
 	{
 	    if(head1 -> data < head2 -> data)
 	    {
 	    	head3 -> next = head1;
 	    	head1 = head1 -> next;
 	    }	

 	    else
 	    {
 	    	head3 -> next = head2;
 	    	head2 = head2 -> next;
 	    }
 	    head3 = head3 -> next;
 	    printf("%d\n",head3 -> data);
 	}
 	if(head1 != NULL)
 	{
 		while(head1 != NULL)
 		{
 			head3 -> next = head1;
 			head1 = head1 -> next;
 			head3 = head3 -> next;
 		}
 	}

 	if(head2 != NULL)
 	{
 		while(head2 != NULL)
 		{
 			head3 -> next = head2;
 			head2 = head2 -> next;
 			head3 = head3 -> next;
 		}
 	}

 	return start -> next;
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
	Node* head1 = NULL;
	Node* head2 = NULL;
	insertAtLast(&head1,1);
	insertAtLast(&head1,2);
	insertAtLast(&head1,3);
	insertAtLast(&head1,5);
	insertAtLast(&head1,6);
	insertAtLast(&head2,3);
	insertAtLast(&head2,4);
	insertAtLast(&head2,7);
	insertAtLast(&head2,8);
	insertAtLast(&head2,9);
	Node* head3 = merge(head1,head2);
	print(head3);
}