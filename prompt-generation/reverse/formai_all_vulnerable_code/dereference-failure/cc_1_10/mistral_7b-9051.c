//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIST_SIZE 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct Subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct Subscriber *next;
} Subscriber;

typedef struct MailingList {
    Subscriber *head;
    Subscriber *tail;
    int size;
} MailingList;

void initMailingList(MailingList *ml) {
    ml->head = NULL;
    ml->tail = NULL;
    ml->size = 0;
}

bool isEmpty(MailingList ml) {
    return ml.size == 0;
}

void addSubscriber(MailingList *ml, const char *name, const char *email) {
    Subscriber *newSubscriber = (Subscriber *) malloc(sizeof(Subscriber));
    strcpy(newSubscriber->name, name);
    strcpy(newSubscriber->email, email);
    newSubscriber->next = NULL;

    if (isEmpty(*ml)) {
        ml->head = newSubscriber;
        ml->tail = newSubscriber;
    } else {
        ml->tail->next = newSubscriber;
        ml->tail = newSubscriber;
    }

    ml->size++;
}

void removeSubscriber(MailingList *ml, const char *email) {
    Subscriber *current = ml->head;
    Subscriber *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                ml->head = current->next;
            } else {
                previous->next = current->next;
            }

            free(current);
            ml->size--;
            break;
        }
        previous = current;
        current = current->next;
    }
}

void printMailingList(const MailingList ml) {
    Subscriber *current = ml.head;

    printf("Mailing List (%d subscribers)\n", ml.size);
    while (current != NULL) {
        printf("%s <%s>\n", current->name, current->email);
        current = current->next;
    }
}

int main() {
    MailingList myList;
    initMailingList(&myList);

    addSubscriber(&myList, "John Doe", "john.doe@example.com");
    addSubscriber(&myList, "Jane Smith", "jane.smith@example.com");
    addSubscriber(&myList, "Bob Johnson", "bob.johnson@example.com");

    printMailingList(myList);

    removeSubscriber(&myList, "jane.smith@example.com");
    printMailingList(myList);

    return 0;
}