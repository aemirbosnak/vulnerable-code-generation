//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 255
#define MAX_MSG_LEN 1024

typedef struct MailList {
    char name[MAX_NAME_LEN];
    struct MailList* next;
    char message[MAX_MSG_LEN];
} MailList;

MailList* createMailList(char* name, char* message) {
    MailList* list = malloc(sizeof(MailList));
    list->next = NULL;
    strcpy(list->name, name);
    strcpy(list->message, message);
    return list;
}

void addToList(MailList* list, char* name, char* message) {
    MailList* newNode = createMailList(name, message);
    if (list) {
        list->next = newNode;
    } else {
        list = newNode;
    }
    list = newNode;
}

void printList(MailList* list) {
    while (list) {
        printf("Name: %s\n", list->name);
        printf("Message: %s\n", list->message);
        printf("\n");
        list = list->next;
    }
}

int main() {
    MailList* myList = NULL;
    addToList(myList, "John Doe", "Hello, world!");
    addToList(myList, "Jane Doe", "How are you?");
    addToList(myList, "Bob Smith", "Fine, thank you.");

    printList(myList);

    return 0;
}