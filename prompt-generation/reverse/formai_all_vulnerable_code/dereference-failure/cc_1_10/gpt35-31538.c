//FormAI DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

//Node structure
struct Node {
    int data;
    struct Node* next;
};

//Function to insert a node at the beginning of the linked list
void insert_at_beginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

//Function to insert a node at the end of the linked list
void insert_at_end(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

//Function to delete a node from linked list
void delete_node(struct Node **head_ref, int key) 
{ 
    struct Node* temp = *head_ref, *prev; 
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
    if (temp == NULL) 
    {
        printf("Cannot delete, node does not exist. ");
        return; 
    }
    prev->next = temp->next; 
    free(temp); 
} 

//Function to print linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
} 

int main() {
    struct Node* head = NULL;
    printf("Welcome to the Puzzling Linked List!\n");
    printf("Please enter the number of nodes in the linked list: ");
    int n,i;
    scanf("%d", &n);
    printf("Great! Now please enter %d values (positive integers only): \n", n);

    for (i=0;i<n;i++){
        int value;
        scanf("%d", &value);
        if (i % 2 == 0)
            insert_at_beginning(&head,value);
        else
            insert_at_end(&head,value);
    }

    printf("\nLinked List: ");
    printList(head);

    printf("\n\nHmm, looks like we have some duplicates in the linked list...\n");
    printf("Please enter a value to delete from the linked list: ");
    int delete_val;
    scanf("%d", &delete_val);
    delete_node(&head,delete_val);

    printf("\nLinked List after deletion: ");
    printList(head);

    printf("\n\nLooks like you solved the puzzle, congratulations!");
    return 0;
}