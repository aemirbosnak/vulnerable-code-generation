//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    char name[50];
    struct Node* next;
    struct Node* prev;
};

// Define the structure for the mailing list
struct List {
    struct Node* head;
    struct Node* tail;
    int size;
};

// Function to add a new subscriber to the mailing list
void addSubscriber(struct List* list, const char* name) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->prev = NULL;
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
    list->size++;
}

// Function to remove a subscriber from the mailing list
void removeSubscriber(struct List* list, const char* name) {
    struct Node* current = list->head;
    struct Node* previous = NULL;

    while (current!= NULL && strcmp(current->name, name)!= 0) {
        previous = current;
        current = current->next;
    }

    if (current!= NULL) {
        if (current->prev!= NULL) {
            current->prev->next = current->next;
        } else {
            list->head = current->next;
        }

        if (current->next!= NULL) {
            current->next->prev = current->prev;
        } else {
            list->tail = current->prev;
        }

        free(current);
        list->size--;
    } else {
        printf("Subscriber not found in the mailing list\n");
    }
}

// Function to print the mailing list
void printList(struct List* list) {
    struct Node* current = list->head;

    while (current!= NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    struct List list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;

    addSubscriber(&list, "John");
    addSubscriber(&list, "Jane");
    addSubscriber(&list, "Mike");

    printf("Mailing list:\n");
    printList(&list);

    removeSubscriber(&list, "Mike");

    printf("Mailing list after removing Mike:\n");
    printList(&list);

    return 0;
}