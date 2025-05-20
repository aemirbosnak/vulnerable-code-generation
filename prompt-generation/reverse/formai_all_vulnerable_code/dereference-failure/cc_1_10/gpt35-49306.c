//FormAI DATASET v1.0 Category: Linked list operations ; Style: authentic
#include<stdio.h>  
#include<stdlib.h>  

typedef struct node //creating a structure of node  
{  
    int data;  
    struct node *next;  //pointer to the next node  
} node;  

void addNode(node **headptr, int data) //addNode function to add a new Node  
{  
    node *newnode, *temp;  
    temp = *headptr;  
    newnode = (node *)malloc(sizeof(node));  
    newnode->data = data;  
    newnode->next = NULL;  

    if (*headptr == NULL)  //if linked list is empty  
    {  
        *headptr = newnode;  
    }  
    else  
    {  
        while (temp->next != NULL)  
        {  
            temp = temp->next;  
        }  
        temp->next = newnode;  
    }  
}  

void deleteNode(node **headptr, int data) //deleteNode function to delete a Node  
{  
    node *prevnode, *cur;  
    cur = *headptr;  
    
    if(cur!= NULL && cur->data == data)  //if the node to be deleted is head node  
    {  
        *headptr = cur->next;  
        free(cur);  
        return;  
    }  
    
    while(cur != NULL && cur->data != data) //traversing to find the node to be deleted  
    {  
        prevnode = cur;  
        cur = cur->next;  
    }  
    
    if(cur == NULL) return;  //if the node is not present in the list  
     
    prevnode->next = cur->next;  //deleting the node  
    free(cur);  
}  

void displayList(node **headptr) //displayList function to display the Linked List  
{  
    node *temp = *headptr;  
    if (temp == NULL)  
    {  
        printf("The Linked List is empty.\n");  
    }  
    else  
    {  
        while (temp != NULL)  
        {  
            printf("%d ", temp->data);  
            temp = temp->next;  
        }  
        printf("\n");  
    }  
}  

int main()  //main function  
{  
    node *head = NULL;   //initially the Linked List is empty  
    int choice, data;  
    while (1)  
    {  
        printf("\nChoose the option you want to perform:\n");  
        printf("1. Add a Node\n2. Delete a Node\n3. Display the Linked List\n4. Exit Program\n");  
        scanf("%d", &choice);  
        switch (choice)  
        {  
        case 1:  
            printf("Enter the data of the new node: ");  
            scanf("%d", &data);  
            addNode(&head, data);  
            break;  
        case 2:  
            printf("Enter the data of the node to be deleted: ");  
            scanf("%d", &data);  
            deleteNode(&head, data);  
            break;  
        case 3:  
            displayList(&head);  
            break;  
        case 4:  
            printf("Exiting.\n\n");  
            exit(0);  
        default:  
            printf("Invalid Choice.\n");  
            break;  
        }  
    }  
    return 0;  
}