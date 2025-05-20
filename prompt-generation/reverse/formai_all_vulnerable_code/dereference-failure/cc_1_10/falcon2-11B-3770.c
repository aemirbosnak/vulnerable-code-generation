//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the queue
typedef struct node {
    int data;
    struct node* next;
} node;

// Function to initialize the head node of the queue
node* init_queue(int data) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new element to the queue
node* enqueue(node* head, int data) {
    node* new_node = init_queue(data);
    new_node->next = head;
    return new_node;
}

// Function to remove and return the first element from the queue
node* dequeue(node* head) {
    if (head == NULL) {
        return NULL;
    }
    node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to print the elements in the queue
void print_queue(node* head) {
    node* curr = head;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    int nums[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        head = enqueue(head, nums[i]);
    }
    print_queue(head);
    head = dequeue(head);
    print_queue(head);
    head = dequeue(head);
    print_queue(head);
    head = dequeue(head);
    print_queue(head);
    head = dequeue(head);
    print_queue(head);
    return 0;
}