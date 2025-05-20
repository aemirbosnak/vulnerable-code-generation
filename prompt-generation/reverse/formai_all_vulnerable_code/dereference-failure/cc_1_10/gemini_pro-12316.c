//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    char *phone;
};

struct Person *createPerson(char *name, char *phone) {
    struct Person *person = malloc(sizeof(struct Person));
    person->name = strdup(name);
    person->phone = strdup(phone);
    return person;
}

typedef struct Node {
    struct Person *person;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
} LinkedList;

void insertAtHead(LinkedList *list, struct Person *person) {
    Node *node = malloc(sizeof(Node));
    node->person = person;
    node->next = list->head;
    list->head = node;
    if (list->tail == NULL) {
        list->tail = node;
    }
}

void insertAtTail(LinkedList *list, struct Person *person) {
    Node *node = malloc(sizeof(Node));
    node->person = person;
    node->next = NULL;
    if (list->tail == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void deleteNode(LinkedList *list, Node *node) {
    if (node == list->head) {
        list->head = node->next;
        if (list->head == NULL) {
            list->tail = NULL;
        }
    } else {
        Node *prev = list->head;
        while (prev->next != node) {
            prev = prev->next;
        }
        prev->next = node->next;
        if (node == list->tail) {
            list->tail = prev;
        }
    }
    free(node->person->name);
    free(node->person->phone);
    free(node->person);
    free(node);
}

void printLinkedList(LinkedList *list) {
    Node *node = list->head;
    while (node != NULL) {
        printf("%s: %s\n", node->person->name, node->person->phone);
        node = node->next;
    }
}

int main() {
    LinkedList *phoneBook = malloc(sizeof(LinkedList));
    phoneBook->head = NULL;
    phoneBook->tail = NULL;
    
    insertAtHead(phoneBook, createPerson("Alice", "555-1212"));
    insertAtTail(phoneBook, createPerson("Bob", "555-1213"));
    insertAtHead(phoneBook, createPerson("Charlie", "555-1214"));
    
    printLinkedList(phoneBook);
    
    deleteNode(phoneBook, phoneBook->head);
    deleteNode(phoneBook, phoneBook->tail);
    
    printLinkedList(phoneBook);
    
    return 0;
}