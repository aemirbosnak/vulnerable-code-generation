//FormAI DATASET v1.0 Category: Linked list operations ; Style: authentic
#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
    int data; 
    struct node *next; 
}; 

void insertAtBeginning(struct node **head_ref, int new_data) 
{ 
    struct node *new_node = (struct node*) malloc(sizeof(struct node)); 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 

void insertAfter(struct node *prev_node, int new_data) 
{ 
    if (prev_node == NULL) 
    { 
        printf("The given previous node cannot be NULL"); 
        return; 
    } 
    struct node *new_node =(struct node*) malloc(sizeof(struct node)); 
    new_node->data = new_data; 
    new_node->next = prev_node->next; 
    prev_node->next = new_node; 
} 

void insertAtEnd(struct node **head_ref, int new_data) 
{ 
    struct node *new_node = (struct node*) malloc(sizeof(struct node)); 
    struct node *last = *head_ref; 
    new_node->data = new_data; 
    new_node->next = NULL;  
    if (*head_ref == NULL) 
    { 
        *head_ref = new_node; 
        return; 
    } 
    while (last->next != NULL) 
        last = last->next; 
    last->next = new_node; 
    return; 
} 

void deleteNode(struct node **head_ref, int key) 
{  
    struct node* temp = *head_ref, *prev; 
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next; 
        free(temp);                 
        return; 
    } 
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) return; 
    prev->next = temp->next; 
    free(temp);  
}

void searchNode(struct node* head, int key)
{  
    while (head != NULL)
    { 
        if (head->data == key)
        {
            printf("Found %d in the linked list\n", key);
            return;
        }
        head = head->next;
    }
    printf("%d not found in the linked list\n", key);
}

void printLinkedList(struct node *node) 
{ 
    while (node != NULL) 
    { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 

int main() 
{ 
    struct node* head = NULL; 
    
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 8);
    insertAfter(head->next, 6);

    printf("Initial linked list: ");
    printLinkedList(head); 
  
    deleteNode(&head, 3);
    printf("\nLinked list after deleting 3: ");
    printLinkedList(head);

    searchNode(head, 8);
    searchNode(head, 4);
  
    return 0; 
}