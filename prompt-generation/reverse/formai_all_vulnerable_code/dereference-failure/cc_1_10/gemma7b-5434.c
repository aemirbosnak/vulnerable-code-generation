//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

struct MailList {
    Node* head;
    int size;
};

void insertNode(struct MailList* list, char* name) {
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

void printNodes(struct MailList* list) {
    Node* temp = list->head;
    while (temp) {
        printf("%s ", temp->name);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct MailList* list = (struct MailList*)malloc(sizeof(struct MailList));
    list->head = NULL;
    list->size = 0;

    insertNode(list, "John Doe");
    insertNode(list, "Jane Doe");
    insertNode(list, "Peter Pan");

    printNodes(list);

    return 0;
}