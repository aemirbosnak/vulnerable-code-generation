//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_LENGTH 100

typedef struct {
    char email[MAX_LENGTH];
} Subscriber;

typedef struct {
    Subscriber *subscribers[MAX_EMAILS];
    int count;
} MailingList;

MailingList* createList() {
    MailingList *list = (MailingList*)malloc(sizeof(MailingList));
    list->count = 0;
    for (int i = 0; i < MAX_EMAILS; i++) {
        list->subscribers[i] = NULL;
    }
    return list;
}

int addSubscriber(MailingList *list, const char *email) {
    if (list->count >= MAX_EMAILS) return -1; // List full
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i]->email, email) == 0) {
            return 0; // Already subscribed
        }
    }
    Subscriber *new_sub = (Subscriber*)malloc(sizeof(Subscriber));
    strncpy(new_sub->email, email, MAX_LENGTH);
    list->subscribers[list->count++] = new_sub;
    return 1; // Successfully added
}

int removeSubscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i]->email, email) == 0) {
            free(list->subscribers[i]);
            list->subscribers[i] = list->subscribers[list->count - 1];
            list->subscribers[list->count - 1] = NULL;
            list->count--;
            return 1; // Successfully removed
        }
    }
    return 0; // Email not found
}

void displaySubscribers(MailingList *list) {
    printf("Current Subscribers (%d):\n", list->count);
    for (int i = 0; i < list->count; i++) {
        printf("%s\n", list->subscribers[i]->email);
    }
}

void cleanUp(MailingList *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->subscribers[i]);
    }
    free(list);
}

int main() {
    MailingList *myList = createList();
    char command[10], email[MAX_LENGTH];

    while (1) {
        printf("Enter command (add/remove/display/exit): ");
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            printf("Enter email to add: ");
            scanf("%s", email);
            int result = addSubscriber(myList, email);
            if (result == 1) {
                printf("Successfully added: %s\n", email);
            } else if (result == 0) {
                printf("Already subscribed: %s\n", email);
            } else {
                printf("Mailing list full. Unable to add: %s\n", email);
            }
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter email to remove: ");
            scanf("%s", email);
            int result = removeSubscriber(myList, email);
            if (result == 1) {
                printf("Successfully removed: %s\n", email);
            } else {
                printf("Email not found: %s\n", email);
            }
        } else if (strcmp(command, "display") == 0) {
            displaySubscribers(myList);
        } else if (strcmp(command, "exit") == 0) {
            cleanUp(myList);
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid command! Try again.\n");
        }
        printf("\n");
    }
    return 0;
}