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

Node* reverse(Node* head)
{
	Node* prev = NULL;
	Node* next = NULL;
	Node* curr = head;
	while(curr != NULL)
	{
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}

	head = prev;
	return head;
}

int checkforPalindrome(Node* head)
{
	if(head -> next == NULL)
		return 1;
    Node* slow = head;
    Node* fast = head;
    while(slow -> next != NULL && fast -> next != NULL && 
     fast -> next -> next != NULL)
    {
    	slow = slow -> next;
    	fast = fast -> next -> next;
    }
    slow -> next = reverse(slow -> next);
    Node* curr1 = head;
    Node* curr2 = slow -> next;
    while(curr2 != NULL && curr1 -> data == curr2 -> data )
    {
    	printf("%d %d\n",curr1 -> data,curr2 -> data );
    	curr1 = curr1 -> next;
    	curr2 = curr2 -> next;
    }

    slow -> next = reverse(slow -> next);

    if(curr2 != NULL)
    	return 0;
    else
    	return 1;
    
}

int main()
{
	Node* head = NULL;
	insertAtLast(&head,1);
	insertAtLast(&head,2);
	insertAtLast(&head,3);
	insertAtLast(&head,4);
	insertAtLast(&head,3);
	insertAtLast(&head,5);
	insertAtLast(&head,1);
	print(head);
	int isPalindrome = checkforPalindrome(head);
	if(isPalindrome == 1)
		printf("It is Palindrome\n");
	else
		printf("It is not palindrome\n");
    print(head);
}