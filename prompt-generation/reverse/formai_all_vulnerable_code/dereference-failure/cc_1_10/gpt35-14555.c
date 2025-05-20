//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a subscriber node
typedef struct Subscriber {
    char* email;
    struct Subscriber* next;
} Subscriber;

// Define a struct for the mailing list
typedef struct MailingList {
    char* name;
    Subscriber* head;
} MailingList;

// Function to add new subscriber to a mailing list
Subscriber* addSubscriber(Subscriber* head, char* email) {
    Subscriber* newSubscriber = (Subscriber*) malloc(sizeof(Subscriber));
    newSubscriber->email = strdup(email);
    newSubscriber->next = head;
    head = newSubscriber;
    return head;
}

// Function to create a new mailing list
MailingList* createMailingList(char* name) {
    MailingList* newMailingList = (MailingList*) malloc(sizeof(MailingList));
    newMailingList->name = strdup(name);
    newMailingList->head = NULL;
    return newMailingList;
}

// Function to check if a subscriber exists in a mailing list
int subscriberExists(Subscriber* head, char* email) {
    Subscriber* current = head;
    while(current != NULL) {
        if(strcmp(current->email, email) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Function to add a subscriber to a mailing list if they don't already exist
void addSubscriberToMailingList(MailingList* mailingList, char* email) {
    if(!subscriberExists(mailingList->head, email)) {
        mailingList->head = addSubscriber(mailingList->head, email);
        printf("Subscriber added to %s mailing list: %s\n", mailingList->name, email);
    } else {
        printf("Subscriber already exists in %s mailing list: %s\n", mailingList->name, email);
    }
}

// Function to print all subscribers in a mailing list
void printSubscribers(MailingList* mailingList) {
    printf("Subscribers in %s mailing list:\n", mailingList->name);
    Subscriber* current = mailingList->head;
    while(current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create two mailing lists
    MailingList* list1 = createMailingList("List 1");
    MailingList* list2 = createMailingList("List 2");
    
    // Add subscribers to mailing lists
    addSubscriberToMailingList(list1, "subscriber1@example.com");
    addSubscriberToMailingList(list1, "subscriber2@example.com");
    addSubscriberToMailingList(list1, "subscriber3@example.com");
    addSubscriberToMailingList(list2, "subscriber4@example.com");
    addSubscriberToMailingList(list2, "subscriber5@example.com");
    
    // Print subscribers in mailing lists
    printSubscribers(list1);
    printSubscribers(list2);
    
    return 0;
}