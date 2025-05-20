//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
};

struct MailList {
    struct Node* head;
    struct Node* tail;
    int size;
};

void insertAtTail(struct MailList* list, char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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

int main() {
    struct MailList* list = (struct MailList*)malloc(sizeof(struct MailList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    insertAtTail(list, "John Doe");
    insertAtTail(list, "Jane Doe");
    insertAtTail(list, "Peter Pan");

    struct Node* current = list->head;
    while (current) {
        printf("%s\n", current->name);
        current = current->next;
    }

    return 0;
}