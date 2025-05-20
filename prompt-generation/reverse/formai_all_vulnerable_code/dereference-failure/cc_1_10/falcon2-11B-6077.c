//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
} List;

List* createList(void) {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void appendNode(List* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
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
    while (current!= NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    List* list = createList();
    
    appendNode(list, 10);
    appendNode(list, 20);
    appendNode(list, 30);
    
    printList(list);
    
    return 0;
}