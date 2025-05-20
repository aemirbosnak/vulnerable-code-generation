//FormAI DATASET v1.0 Category: Mailing list manager ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

// Structure for storing subscriber details
struct SubscriberInfo {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct SubscriberInfo* next;
};

// Linked list for storing subscribers
struct SubscriberList {
    struct SubscriberInfo* head;
    int count;
};

// Function to create a new subscriber info node
struct SubscriberInfo* createSubscriber(char* name, char* email) {
    struct SubscriberInfo* newSubscriber = (struct SubscriberInfo*) malloc(sizeof(struct SubscriberInfo));
    strncpy(newSubscriber->name, name, MAX_NAME_LENGTH);
    strncpy(newSubscriber->email, email, MAX_EMAIL_LENGTH);
    newSubscriber->next = NULL;
    return newSubscriber;
}

// Function to add a subscriber to the list
void addSubscriber(struct SubscriberList* list, char* name, char* email) {
    struct SubscriberInfo* newSubscriber = createSubscriber(name, email);
    if (list->head == NULL) {
        list->head = newSubscriber;
    } else {
        struct SubscriberInfo* currentSubscriber = list->head;
        while (currentSubscriber->next != NULL) {
            currentSubscriber = currentSubscriber->next;
        }
        currentSubscriber->next = newSubscriber;
    }
    list->count++;
}

// Function to remove a subscriber from the list
void removeSubscriber(struct SubscriberList* list, char* email) {
    if (list->head == NULL) {
        return;
    }
    if (strcmp(list->head->email, email) == 0) {
        struct SubscriberInfo* temp = list->head;
        list->head = temp->next;
        free(temp);
        list->count--;
        return;
    }
    struct SubscriberInfo* currentSubscriber = list->head->next;
    struct SubscriberInfo* previousSubscriber = list->head;
    while (currentSubscriber != NULL) {
        if (strcmp(currentSubscriber->email, email) == 0) {
            previousSubscriber->next = currentSubscriber->next;
            free(currentSubscriber);
            list->count--;
            return;
        }
        previousSubscriber = currentSubscriber;
        currentSubscriber = currentSubscriber->next;
    }
}

// Function to print all subscribers
void printSubscribers(struct SubscriberList* list) {
    printf("There are currently %d subscribers:\n", list->count);
    struct SubscriberInfo* currentSubscriber = list->head;
    while (currentSubscriber != NULL) {
        printf("%s <%s>\n", currentSubscriber->name, currentSubscriber->email);
        currentSubscriber = currentSubscriber->next;
    }
}

int main() {
    struct SubscriberList list = { NULL, 0 };
    addSubscriber(&list, "John Smith", "johnsmith@example.com");
    addSubscriber(&list, "Jane Doe", "janedoe@example.com");
    printSubscribers(&list);
    removeSubscriber(&list, "johnsmith@example.com");
    printSubscribers(&list);
    return 0;
}