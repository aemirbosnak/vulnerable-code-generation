//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node of a doubly linked list
struct Node {
    char *data;
    struct Node *next;
    struct Node *prev;
};

// Doubly linked list
struct LinkedList {
    struct Node *head;
    struct Node *tail;
};

// Initialize a doubly linked list
struct LinkedList *createLinkedList() {
    struct LinkedList *list = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Insert a node at the beginning of a doubly linked list
void insertAtBeginning(struct LinkedList *list, char *data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = strdup(data);
    node->next = list->head;
    node->prev = NULL;
    if (list->head != NULL) {
        list->head->prev = node;
    }
    list->head = node;
    if (list->tail == NULL) {
        list->tail = node;
    }
}

// Insert a node at the end of a doubly linked list
void insertAtEnd(struct LinkedList *list, char *data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = strdup(data);
    node->next = NULL;
    node->prev = list->tail;
    if (list->tail != NULL) {
        list->tail->next = node;
    }
    list->tail = node;
    if (list->head == NULL) {
        list->head = node;
    }
}

// Delete a node from a doubly linked list
void deleteNode(struct LinkedList *list, struct Node *node) {
    if (node == NULL) {
        return;
    }
    if (node == list->head) {
        list->head = node->next;
    }
    if (node == list->tail) {
        list->tail = node->prev;
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    free(node->data);
    free(node);
}

// Free a doubly linked list
void freeLinkedList(struct LinkedList *list) {
    struct Node *node = list->head;
    while (node != NULL) {
        struct Node *next = node->next;
        deleteNode(list, node);
        node = next;
    }
    free(list);
}

// Print a doubly linked list
void printLinkedList(struct LinkedList *list) {
    struct Node *node = list->head;
    while (node != NULL) {
        printf("%s\n", node->data);
        node = node->next;
    }
}

int main() {
    // Create a linked list of skills
    struct LinkedList *skills = createLinkedList();
    insertAtEnd(skills, "C Programming");
    insertAtEnd(skills, "Data Structures");
    insertAtEnd(skills, "Algorithms");
    insertAtEnd(skills, "Object-Oriented Programming");
    insertAtEnd(skills, "Software Design");

    // Create a linked list of experiences
    struct LinkedList *experiences = createLinkedList();
    insertAtEnd(experiences, "Software Engineer Intern at Google");
    insertAtEnd(experiences, "Research Assistant at Stanford University");
    insertAtEnd(experiences, "Teaching Assistant at Harvard University");

    // Create a linked list of educations
    struct LinkedList *educations = createLinkedList();
    insertAtEnd(educations, "Master of Science in Computer Science from Stanford University");
    insertAtEnd(educations, "Bachelor of Science in Computer Science from Harvard University");

    // Print the resume
    printf("**Skills**\n");
    printLinkedList(skills);
    printf("\n**Experiences**\n");
    printLinkedList(experiences);
    printf("\n**Educations**\n");
    printLinkedList(educations);

    // Free the linked lists
    freeLinkedList(skills);
    freeLinkedList(experiences);
    freeLinkedList(educations);

    return 0;
}