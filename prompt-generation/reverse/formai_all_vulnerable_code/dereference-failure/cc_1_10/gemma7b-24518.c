//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
};

struct MailingList {
    struct Node* head;
    int size;
};

void insert(struct MailingList* list, char* name) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->next = NULL;
    strcpy(newNode->name, name);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* temp = list->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

void print(struct MailingList* list) {
    struct Node* temp = list->head;
    while (temp) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

int main() {
    struct MailingList* list = malloc(sizeof(struct MailingList));
    list->head = NULL;
    list->size = 0;

    insert(list, "John Doe");
    insert(list, "Jane Doe");
    insert(list, "Bill Smith");

    print(list);

    return 0;
}