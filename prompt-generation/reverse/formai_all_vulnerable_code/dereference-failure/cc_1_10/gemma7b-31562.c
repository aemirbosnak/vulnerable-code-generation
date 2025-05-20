//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

typedef struct MailList {
    Node* head;
    int size;
} MailList;

void insert(MailList* list, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    list->size++;
}

void printList(MailList* list) {
    Node* temp = list->head;
    while (temp) {
        printf("%s ", temp->name);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    MailList* list = (MailList*)malloc(sizeof(MailList));
    list->head = NULL;
    list->size = 0;

    insert(list, "John Doe");
    insert(list, "Jane Doe");
    insert(list, "Peter Pan");

    printList(list);

    return 0;
}