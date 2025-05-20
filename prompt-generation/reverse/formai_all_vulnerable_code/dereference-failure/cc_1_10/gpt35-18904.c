//FormAI DATASET v1.0 Category: Linked list operations ; Style: real-life
#include <stdio.h> 
#include <stdlib.h> 

struct node { 
    int data; 
    struct node* next; 
}; 

void printList(struct node* n) { 
    while (n != NULL) { 
        printf(" %d ", n->data); 
        n = n->next; 
    } 
    printf("\n"); 
} 

void insertAtBeginning(struct node** head_ref, int new_data) { 
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 

void insertAtEnd(struct node** head_ref, int new_data) { 
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    struct node* last = *head_ref; 
    new_node->data = new_data; 
    new_node->next = NULL; 
    if (*head_ref == NULL) { 
        *head_ref = new_node; 
        return; 
    } 
    while (last->next != NULL) last = last->next; 
    last->next = new_node; 
    return; 
} 

void deleteNode(struct node** head_ref, int key) { 
    struct node *temp = *head_ref, *prev; 
    if (temp != NULL && temp->data == key) { 
        *head_ref = temp->next;    
        free(temp);  
        return; 
    } 
    while (temp != NULL && temp->data != key) { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) return; 
    prev->next = temp->next; 
    free(temp);  
} 

int searchList(struct node* head, int key) { 
    struct node* current = head;
    while (current != NULL) { 
        if (current->data == key) return 1; 
        current = current->next; 
    } 
    return 0; 
} 

int main() { 
    struct node* head = NULL; 
    insertAtEnd(&head, 7); 
    insertAtBeginning(&head, 1); 
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 2); 
    printf("Linked list: "); 
    printList(head); 
    deleteNode(&head, 6); 
    printf("Linked list after deletion of 6: "); 
    printList(head); 
    if (searchList(head, 1)) printf("Element 1 is present in the linked list\n"); 
    else printf("Element 1 is not present in the linked list\n"); 
    if (searchList(head, 8)) printf("Element 8 is present in the linked list\n"); 
    else printf("Element 8 is not present in the linked list\n"); 
    return 0; 
}