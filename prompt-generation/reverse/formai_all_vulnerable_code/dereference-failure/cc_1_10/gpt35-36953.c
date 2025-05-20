//FormAI DATASET v1.0 Category: Linked list operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Define the structure for our linked list
struct Node{
    int data;
    struct Node* next;
};

// Define a function to insert data into the list
void insert(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Define a function to sort the list in ascending order
void sortList(struct Node *head){
    struct Node *i, *j;
    int temp;
    for(i = head; i != NULL; i = i->next){
        for(j = i->next; j != NULL; j = j->next){
            if(i->data > j->data){
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Define a function to delete a node from the list
void deleteNode(struct Node **head_ref, int key){
    struct Node* temp = *head_ref, *prev;

    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return;

    prev->next = temp->next;

    free(temp);
}

// Define a function to print the list
void printList(struct Node* node){
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(){
    // Create a head node and insert some data
    struct Node* head = NULL;
    insert(&head, 12);
    insert(&head, 4);
    insert(&head, 8);
    insert(&head, 9);

    // Print the original list
    printf("Original list: ");
    printList(head);

    // Sort the list in ascending order
    sortList(head);

    // Print the sorted list
    printf("\nSorted list: ");
    printList(head);

    // Delete a node from the list
    deleteNode(&head, 8);

    // Print the modified list
    printf("\nModified list: ");
    printList(head);

    return 0;
}