//FormAI DATASET v1.0 Category: Mailing list manager ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_EMAIL_LENGTH 1000

typedef struct Subscriber {
    char email[MAX_EMAIL_LENGTH];
    struct Subscriber* next;
} Subscriber;

typedef struct List {
    Subscriber* head;
    int count;
} List;

List* createList() {
    List* list = (List*) malloc(sizeof(List));
    list->head = NULL;
    list->count = 0;
    return list;
}

Subscriber* createSubscriber(char* email) {
    Subscriber* subscriber = (Subscriber*) malloc(sizeof(Subscriber));
    strncpy(subscriber->email, email, MAX_EMAIL_LENGTH - 1);
    subscriber->next = NULL;
    return subscriber;
}

void addSubscriber(List* list, char* email) {
    if (list->head == NULL) {
        list->head = createSubscriber(email);
    } else {
        Subscriber* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = createSubscriber(email);
    }
    list->count++;
}

void removeSubscriber(List* list, char* email) {
    Subscriber* current = list->head;
    Subscriber* previous = NULL;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            list->count--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void printList(List* list) {
    Subscriber* current = list->head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main() {
    List* list = createList();
    addSubscriber(list, "john@example.com");
    addSubscriber(list, "mary@example.com");
    addSubscriber(list, "bob@example.com");
    printf("Initial List:\n");
    printList(list);

    removeSubscriber(list, "mary@example.com");
    printf("List after removing mary@example.com:\n");
    printList(list);

    removeSubscriber(list, "bob@example.com");
    printf("List after removing bob@example.com:\n");
    printList(list);

    addSubscriber(list, "lisa@example.com");
    printf("List after adding lisa@example.com:\n");
    printList(list);

    return 0;
}