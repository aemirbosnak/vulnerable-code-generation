//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Subscriber {
    char email[100];
    struct Subscriber *next;
} Subscriber;

typedef struct MailingList {
    char listName[50];
    Subscriber *subscribers;
    struct MailingList *next;
} MailingList;

MailingList *head = NULL;

// Function to create a new mailing list
MailingList* createList(const char *name) {
    MailingList *newList = malloc(sizeof(MailingList));
    strcpy(newList->listName, name);
    newList->subscribers = NULL;
    newList->next = NULL;
    return newList;
}

// Function to add a mailing list
void addMailingList(const char *name) {
    MailingList *newList = createList(name);
    newList->next = head;
    head = newList;
    printf("Mailing list '%s' created.\n", name);
}

// Function to add a subscriber to a mailing list
void addSubscriber(const char *listName, const char *email) {
    MailingList *list = head;
    while (list) {
        if (strcmp(list->listName, listName) == 0) {
            Subscriber *newSubscriber = malloc(sizeof(Subscriber));
            strcpy(newSubscriber->email, email);
            newSubscriber->next = list->subscribers;
            list->subscribers = newSubscriber;
            printf("Subscriber '%s' added to list '%s'.\n", email, listName);
            return;
        }
        list = list->next;
    }
    printf("Mailing list '%s' not found!\n", listName);
}

// Function to display all subscribers in a mailing list
void displaySubscribers(const char *listName) {
    MailingList *list = head;
    while (list) {
        if (strcmp(list->listName, listName) == 0) {
            Subscriber *sub = list->subscribers;
            printf("Subscribers in list '%s':\n", listName);
            while (sub) {
                printf("- %s\n", sub->email);
                sub = sub->next;
            }
            return;
        }
        list = list->next;
    }
    printf("Mailing list '%s' not found!\n", listName);
}

// Function to delete a subscriber from a mailing list
void deleteSubscriber(const char *listName, const char *email) {
    MailingList *list = head;
    while (list) {
        if (strcmp(list->listName, listName) == 0) {
            Subscriber *current = list->subscribers;
            Subscriber *prev = NULL;
            while (current) {
                if (strcmp(current->email, email) == 0) {
                    if (prev) {
                        prev->next = current->next;
                    } else {
                        list->subscribers = current->next;
                    }
                    free(current);
                    printf("Subscriber '%s' removed from list '%s'.\n", email, listName);
                    return;
                }
                prev = current;
                current = current->next;
            }
            printf("Subscriber '%s' not found in list '%s'.\n", email, listName);
            return;
        }
        list = list->next;
    }
    printf("Mailing list '%s' not found!\n", listName);
}

// Function to free all allocated memory
void freeMemory() {
    MailingList *list = head;
    while (list) {
        Subscriber *sub = list->subscribers;
        while (sub) {
            Subscriber *temp = sub;
            sub = sub->next;
            free(temp);
        }
        MailingList *tempList = list;
        list = list->next;
        free(tempList);
    }
}

int main() {
    addMailingList("Developers");
    addMailingList("Designers");
    addSubscriber("Developers", "dev1@example.com");
    addSubscriber("Developers", "dev2@example.com");
    addSubscriber("Designers", "des1@example.com");

    displaySubscribers("Developers");
    displaySubscribers("Designers");

    deleteSubscriber("Developers", "dev1@example.com");
    displaySubscribers("Developers");

    // Free memory before end
    freeMemory();
    return 0;
}