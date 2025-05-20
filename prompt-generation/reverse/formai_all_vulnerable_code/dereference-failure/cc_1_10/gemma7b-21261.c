//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_ Mailing_LIST_SIZE 100

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

typedef struct MailingList {
    Node* head;
    int size;
} MailingList;

MailingList* CreateMailingList() {
    MailingList* list = malloc(sizeof(MailingList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void AddToMailingList(MailingList* list, char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

void PrintMailingList(MailingList* list) {
    Node* current = list->head;
    while (current) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    MailingList* list = CreateMailingList();
    AddToMailingList(list, "John Doe");
    AddToMailingList(list, "Jane Doe");
    AddToMailingList(list, "Mike Smith");
    PrintMailingList(list);

    return 0;
}