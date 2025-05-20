//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct Node {
    int data;
    struct Node *next;
};

struct List {
    struct Node *head;
    struct Node *tail;
};

void createList(struct List **list) {
    struct Node *node = malloc(sizeof(struct Node));
    node->data = 1;
    node->next = NULL;
    *list = malloc(sizeof(struct List));
    (*list)->head = node;
    (*list)->tail = node;
}

void appendToList(struct List **list, int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if ((*list)->tail == NULL) {
        (*list)->head = newNode;
        (*list)->tail = newNode;
    } else {
        (*list)->tail->next = newNode;
        (*list)->tail = newNode;
    }
}

void printList(struct List *list) {
    struct Node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct List *list1 = NULL, *list2 = NULL;
    createList(&list1);
    createList(&list2);

    // Distributed list operations
    appendToList(&list1, 2);
    appendToList(&list2, 3);

    // Merge lists
    struct Node *current1 = list1->head, *current2 = list2->head;
    struct Node *prev1 = NULL, *prev2 = NULL;
    while (current1 != NULL && current2 != NULL) {
        if (current1->data < current2->data) {
            prev1 = current1;
            current1 = current1->next;
        } else if (current1->data > current2->data) {
            prev2 = current2;
            current2 = current2->next;
        } else {
            prev1 = current1;
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    // Append remaining nodes
    if (prev1 != NULL) {
        prev1->next = current2;
    } else {
        list1->tail = current2;
    }

    // Print merged list
    printList(list1);

    return 0;
}