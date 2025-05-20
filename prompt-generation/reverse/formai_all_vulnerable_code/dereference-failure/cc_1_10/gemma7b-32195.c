//Gemma-7B DATASET v1.0 Category: Error handling ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    char name[MAX_SIZE];
    int age;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} List;

List* createList() {
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void addToTail(List* list, char* name, int age) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void printList(List* list) {
    Node* current = list->head;
    while (current) {
        printf("%s (%d) ", current->name, current->age);
        current = current->next;
    }
    printf("\n");
}

int main() {
    List* list = createList();

    addToTail(list, "Romeo", 18);
    addToTail(list, "Juliet", 16);
    addToTail(list, "Tybalt", 20);
    addToTail(list, "Benvolio", 19);

    printList(list);

    return 0;
}