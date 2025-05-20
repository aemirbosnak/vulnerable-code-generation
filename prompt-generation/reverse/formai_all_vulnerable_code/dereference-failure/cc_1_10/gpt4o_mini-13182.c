//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct Subscriber {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_NAME_LENGTH];
    struct Subscriber *next;
} Subscriber;

typedef struct MailingList {
    Subscriber *head;
} MailingList;

MailingList *createMailingList() {
    MailingList *list = (MailingList *)malloc(sizeof(MailingList));
    list->head = NULL;
    return list;
}

Subscriber *createSubscriber(const char *email, const char *name) {
    Subscriber *new_subscriber = (Subscriber *)malloc(sizeof(Subscriber));
    strncpy(new_subscriber->email, email, MAX_EMAIL_LENGTH);
    strncpy(new_subscriber->name, name, MAX_NAME_LENGTH);
    new_subscriber->next = NULL;
    return new_subscriber;
}

void addSubscriber(MailingList *list, const char *email, const char *name) {
    Subscriber *new_subscriber = createSubscriber(email, name);
    new_subscriber->next = list->head;
    list->head = new_subscriber;
    printf("Subscriber added: %s (%s)\n", name, email);
}

void removeSubscriber(MailingList *list, const char *email) {
    Subscriber *current = list->head;
    Subscriber *previous = NULL;
    
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Subscriber removed: %s\n", email);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Subscriber not found: %s\n", email);
}

void listSubscribers(MailingList *list) {
    Subscriber *current = list->head;
    printf("Mailing List Subscribers:\n");
    while (current != NULL) {
        printf(" - %s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

void freeMailingList(MailingList *list) {
    Subscriber *current = list->head;
    Subscriber *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

void sendEmailToSubscriber(const char *email, const char *subject, const char *body) {
    printf("Sending email to: %s\n", email);
    printf("Subject: %s\n", subject);
    printf("Body:\n%s\n", body);
}

void sendEmail(MailingList *list, const char *subject, const char *body) {
    Subscriber *current = list->head;
    while (current != NULL) {
        sendEmailToSubscriber(current->email, subject, body);
        current = current->next;
    }
}

int main() {
    MailingList *list = createMailingList();
    int choice;
    char email[MAX_EMAIL_LENGTH], name[MAX_NAME_LENGTH], subject[100], body[256];

    while (1) {
        printf("\nMailing List Manager:\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. List Subscribers\n");
        printf("4. Send Email\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter email: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                strtok(email, "\n"); // Remove trailing newline

                printf("Enter name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                strtok(name, "\n"); // Remove trailing newline
                
                addSubscriber(list, email, name);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                strtok(email, "\n"); // Remove trailing newline

                removeSubscriber(list, email);
                break;
            case 3:
                listSubscribers(list);
                break;
            case 4:
                printf("Enter email subject: ");
                fgets(subject, sizeof(subject), stdin);
                strtok(subject, "\n");
                
                printf("Enter email body: ");
                fgets(body, sizeof(body), stdin);
                strtok(body, "\n");

                sendEmail(list, subject, body);
                break;
            case 5:
                freeMailingList(list);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}