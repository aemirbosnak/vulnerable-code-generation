//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Definition of Linked List node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a Linked List
struct Node* createList(int* data, int size) {
    struct Node* head = NULL;
    for (int i = 0; i < size; i++) {
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->data = data[i];
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Function to traverse the Linked List in reverse order
void reverseTraversal(struct Node* head) {
    struct Node* current = head;
    struct Node* previous = NULL;
    while (current != NULL) {
        if (previous == NULL) {
            printf("%d ", current->data);
        } else {
            printf("%d %d ", current->data, previous->data);
        }
        previous = current;
        current = current->next;
    }
    printf("\n");
}

// Function to find the middle node of the Linked List
struct Node* findMiddle(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    struct Node* previous = NULL;
    while (current != NULL) {
        count++;
        previous = current;
        current = current->next;
    }
    count /= 2;
    previous = head;
    while (count-- > 0) {
        previous = previous->next;
    }
    return previous;
}

// Function to swap the first and last nodes of the Linked List
struct Node* swapFirstLast(struct Node* head) {
    struct Node* first = head;
    struct Node* last = head->next;
    first->next = last->next;
    last->next = head;
    head = first;
    return head;
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);
    struct Node* head = createList(data, size);
    reverseTraversal(head);
    struct Node* middle = findMiddle(head);
    swapFirstLast(head);
    reverseTraversal(head);
    return 0;
}