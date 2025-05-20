//FormAI DATASET v1.0 Category: Linked list operations ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
typedef struct node * Nodeptr;
Nodeptr CreateNode(int value)
{
    Nodeptr temp=(Nodeptr) malloc(sizeof(struct node)); // allocating the memory for the node
    temp->data=value; // storing the value in the node
    temp->next=NULL; // the next field is empty since it does not point to any node
    return temp; // returning the newly created node
}
void InsertNode(Nodeptr *head, int value)
{
    Nodeptr newnode=CreateNode(value); // creating a node for the value
    if(*head==NULL) // if the list is empty
    {
        *head=newnode; // head points to the first node
    }
    else
    {
        Nodeptr current=*head; // creating a pointer to point the current node
        while(current->next!=NULL) // traversing the list until you reach the last node
        {
            current=current->next;
        }
        current->next=newnode; // the last node's next pointer points to the newly created node
    }
}
void DeleteNode(Nodeptr *head, int value)
{
    Nodeptr prev=*head; // creating a pointer to point the previous node
    Nodeptr current=*head; // creating a pointer to point the current node
    while(current!=NULL) // traversing the list until you reach the last node
    {
        if(current->data==value) // if the current node's data matches the value
        {
            if(current==*head) // if the current node is the first node
            {
                *head=current->next; // head points to the second node
                free(current); // freeing up the memory of the current node
                return;
            }
            else
            {
                prev->next=current->next; // the previous node's next pointer points to the current node's next pointer
                free(current); // freeing up the memory of the current node
                return;
            }
        }
        else
        {
            prev=current; // moving the previous pointer to the current node
            current=current->next; // moving the current pointer to the next node
        }
    }
    printf("\nThe value not found in the list\n");
}
void DisplayList(Nodeptr *head)
{
    if(*head==NULL) // if the list is empty
    {
        printf("\nList is empty\n");
    }
    else
    {
        Nodeptr current=*head; // creating a pointer to point the current node
        printf("\nThe list contains: ");
        while(current!=NULL) // traversing the list until you reach the last node
        {
            printf("%d ",current->data); // printing the current node's data
            current=current->next; // moving the current pointer to the next node
        }
        printf("\n");
    }
}
int main()
{
    Nodeptr head=NULL; // initially the list is empty
    int value,choice;
    while(1)
    {
        printf("\nEnter your choice:\n");
        printf("1. Add a value\n");
        printf("2. Delete a value\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        scanf("%d",&choice); // scanning the choice
        switch(choice)
        {
            case 1: printf("\nEnter the value to be added: ");
                    scanf("%d",&value); // scanning the value to be added
                    InsertNode(&head,value); // calling the InsertNode function to insert the node
                    break;
            case 2: printf("\nEnter the value to be deleted: ");
                    scanf("%d",&value); // scanning the value to be deleted
                    DeleteNode(&head,value); // calling the DeleteNode function to delete the node
                    break;
            case 3: DisplayList(&head); // calling the DisplayList function to display the list of values
                    break;
            case 4: exit(0); // terminating the program
            default: printf("\nInvalid choice\n");
        }
    }
    return 0;
}