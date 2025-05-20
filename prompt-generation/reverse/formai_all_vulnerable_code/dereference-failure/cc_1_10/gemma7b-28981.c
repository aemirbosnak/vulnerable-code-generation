//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

struct MailList {
    Node* head;
    Node* tail;
    int size;
};

void insert(struct MailList* list, char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size++;
}

void print(struct MailList* list) {
    Node* current = list->head;
    while (current) {
        printf("%s ", current->name);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct MailList* list = malloc(sizeof(struct MailList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    insert(list, "John Doe");
    insert(list, "Jane Doe");
    insert(list, "Jack Doe");

    print(list);

    return 0;
}