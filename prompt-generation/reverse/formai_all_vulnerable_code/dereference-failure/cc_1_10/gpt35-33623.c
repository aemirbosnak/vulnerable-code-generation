//FormAI DATASET v1.0 Category: Data structures visualization ; Style: portable
#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int data;
    struct node *next;
};
 
void create_list(struct node **head, int n)
{
    struct node *new_node, *last;
    int data, i;
 
    printf("Enter the data value: ");
    scanf("%d", &data);
 
    *head = (struct node*) malloc(sizeof(struct node));
 
    (*head)->data = data;
    (*head)->next = NULL;
 
    last = *head;
 
    for(i=2; i<=n; i++)
    {
        printf("Enter the data value: ");
        scanf("%d", &data);
 
        new_node = (struct node*) malloc(sizeof(struct node));
 
        new_node->data = data;
        new_node->next = NULL;
 
        last->next = new_node;
        last = new_node;
    }
}
 
void display_list(struct node *head)
{
    struct node *temp;
 
    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
 
    temp = head;
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
 
int main()
{
    int n;
    struct node *head = NULL;
 
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
 
    create_list(&head, n);
 
    printf("\nThe created list is: \n");
    display_list(head);
 
    return 0;
}