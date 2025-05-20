//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Structure to hold data and its position in the queue
struct node {
    int data;
    struct node* next;
};

// Function to create a new node and add it at the front of the queue
struct node* create_node(int d) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = d;
    new_node->next = NULL;
    return new_node;
}

// Function to add an element at the back of the queue
void enqueue(struct node** head_ref, int new_data) {
    struct node* new_node = create_node(new_data);
    
    // If the queue is empty, make the new node as the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    // Otherwise, traverse till the end and add the new node
    struct node* last = *head_ref;
    while (last->next!= NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to remove an element from the front of the queue
int dequeue(struct node** head_ref) {
    if (*head_ref == NULL) {
        return -1;
    }
    int data = (*head_ref)->data;
    struct node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
    return data;
}

// Function to check the front element of the queue
int peek(struct node* head) {
    if (head == NULL) {
        return -1;
    }
    return head->data;
}

int main() {
    struct node* head = NULL;
    
    // Add elements to the queue
    enqueue(&head, 1);
    enqueue(&head, 2);
    enqueue(&head, 3);
    
    // Print the elements of the queue
    printf("Elements in the queue: ");
    while (head!= NULL) {
        printf("%d ", peek(head));
        head = head->next;
    }
    printf("\n");
    
    // Remove elements from the queue
    printf("Removing elements from the queue:\n");
    printf("Deleted element: %d\n", dequeue(&head));
    printf("Deleted element: %d\n", dequeue(&head));
    printf("Deleted element: %d\n", dequeue(&head));
    
    return 0;
}