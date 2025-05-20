//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Jonny's Special Linked List Nodes
struct Node {
    int data;
    struct Node* next;
};

// A Magical beginning function to create a new node 
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Tie two nodes together sweetly
void appendNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = new_node;
}

// Crazy function that prints the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Ghostly function to play with nodes and delete by key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;

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

// An Epic function that reverses the linked list
void reverseList(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    }
    *head_ref = prev;
}

// Where the fun begins
int main() {
    struct Node* head = NULL;

    printf("Creating a dazzling linked list...\n");
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);
    
    printf("Our glorious list looks like this:\n");
    printList(head);
    
    printf("Let's delete number 3 from our list, shall we?\n");
    deleteNode(&head, 3);
    
    printf("Now our list shines brighter:\n");
    printList(head);
    
    printf("Time to reverse this magic!\n");
    reverseList(&head);
    
    printf("The enchanted list is now reversed:\n");
    printList(head);
    
    printf("One last touch! Adding some more numbers...\n");
    appendNode(&head, 6);
    appendNode(&head, 7);
    
    printf("Our final masterpiece is:\n");
    printList(head);
    
    // Free the allocated memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("Memory cleaned up, all done!\n");
    return 0;
}