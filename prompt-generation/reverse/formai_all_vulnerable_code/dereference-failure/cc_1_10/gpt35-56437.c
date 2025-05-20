//FormAI DATASET v1.0 Category: Data structures visualization ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// define the structure of a linked list node
struct LinkedList {
    int data;
    struct LinkedList* next;
};

// a function to print out the linked list
void printList(struct LinkedList* head) {
    struct LinkedList* node = head;
    printf("The Linked List: ");
    while(node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // dynamically allocate memory for nodes of the linked list
    struct LinkedList* head = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    struct LinkedList* second = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    struct LinkedList* third = (struct LinkedList*) malloc(sizeof(struct LinkedList));

    // initialize the data and pointers for each node
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // print out the original linked list
    printList(head);

    // create a new node and insert it at the beginning of the list
    struct LinkedList* newHead = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    newHead->data = 0;
    newHead->next = head;
    head = newHead;

    // print out the linked list with the newly inserted node
    printList(head);

    // delete the second node and update the pointers accordingly
    struct LinkedList* temp = head->next;
    head->next = head->next->next;
    free(temp);

    // print out the linked list with the deleted node
    printList(head);

    // free the memory allocated for the linked list nodes
    free(head);
    free(second);
    free(third);

    return 0;
}