//FormAI DATASET v1.0 Category: Data structures visualization ; Style: realistic
#include <stdio.h> 

typedef struct node 
{ 
    int data; 
    struct node *next; 
}Node; 

typedef struct list 
{ 
    Node *head; 
    int size; 
}List; 

void initialize(List *l) 
{ 
    l->head = NULL; 
    l->size = 0; 
} 

int insert(List *l, int index, int data) 
{ 
    if (index < 0 || index > l->size) 
    { 
        printf("Invalid index.\n"); 
        return -1; 
    } 

    Node *n = (Node *) malloc(sizeof(Node)); 
    n->data = data; 

    if (index == 0) 
    { 
        n->next = l->head; 
        l->head = n; 
    } 
    else 
    { 
        Node *temp = l->head; 

        for (int i = 0; i < index - 1; i++) 
        { 
            temp = temp->next; 
        } 

        n->next = temp->next; 
        temp->next = n; 
    } 

    l->size++; 

    return 0; 
} 

int removeItem(List *l, int index) 
{ 
    if (index < 0 || index >= l->size) 
    { 
        printf("Invalid index.\n"); 
        return -1; 
    } 

    if (index == 0) 
    { 
        Node *temp = l->head; 
        l->head = l->head->next; 
        free(temp); 
    } 
    else 
    { 
        Node *temp = l->head; 

        for (int i = 0; i < index - 1; i++) 
        { 
            temp = temp->next; 
        } 

        Node *toFree = temp->next; 
        temp->next = temp->next->next; 
        free(toFree); 
    } 

    l->size--; 

    return 0; 
} 

void printList(List *l) 
{ 
    Node *temp = l->head; 

    while (temp != NULL) 
    { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 

    printf("\n"); 
} 

int main(void) 
{ 
    List myLinkedList; 
    initialize(&myLinkedList); 

    insert(&myLinkedList, 0, 1); 
    insert(&myLinkedList, 1, 2); 
    insert(&myLinkedList, 2, 3); 

    printList(&myLinkedList); 

    removeItem(&myLinkedList, 1); 
    printList(&myLinkedList); 

    insert(&myLinkedList, 2, 4); 
    printList(&myLinkedList); 

    removeItem(&myLinkedList, 0); 
    printList(&myLinkedList); 

    return 0; 
}