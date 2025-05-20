//FormAI DATASET v1.0 Category: Data mining ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int value;
    struct Node* next;
};

void push(struct Node** head_ref, int new_value);
void printList(struct Node* head);

int main() {
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    printf("Original List: ");
    printList(head);

    // Remove outlier values using data mining techniques
    struct Node* ptr1 = head;
    while (ptr1 != NULL && ptr1->next != NULL) {
        struct Node* ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (abs(ptr1->value - ptr2->next->value) > 3) {
                struct Node* temp = ptr2->next;
                ptr2->next = temp->next;
                free(temp);
            }
            else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    printf("\nList after removing outliers: ");
    printList(head);

    return 0;
}

// Function to add new node at the beginning of a singly linked list
void push(struct Node** head_ref, int new_value) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->value = new_value;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
}