//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define BUFFER_SIZE 256

typedef struct Subscriber {
    char email[BUFFER_SIZE];
} Subscriber;

typedef struct MailingList {
    Subscriber *subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

typedef enum {
    ADD, REMOVE, LIST, SEND, EXIT
} Command;

void add_subscriber(MailingList *list);
void remove_subscriber(MailingList *list);
void list_subscribers(MailingList *list);
void send_message(MailingList *list);
Command get_command();

int main() {
    MailingList *list = (MailingList *)malloc(sizeof(MailingList));
    list->count = 0;

    Command command;
    while (1) {
        command = get_command();

        switch (command) {
            case ADD:
                add_subscriber(list);
                break;
            case REMOVE:
                remove_subscriber(list);
                break;
            case LIST:
                list_subscribers(list);
                break;
            case SEND:
                send_message(list);
                break;
            case EXIT:
                printf("Exiting the Mailing List Manager.\n");
                for (int i = 0; i < list->count; i++) {
                    free(list->subscribers[i]);
                }
                free(list);
                return 0;
            default:
                printf("Invalid command.\n");
                break;
        }
    }
}

Command get_command() {
    int choice;
    printf("\nMailing List Manager\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. List Subscribers\n");
    printf("4. Send Message\n");
    printf("5. Exit\n");
    printf("Enter command: ");
    scanf("%d", &choice);
    return (Command)(choice - 1);
}

void add_subscriber(MailingList *list) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full! Cannot add more subscribers.\n");
        return;
    }
    list->subscribers[list->count] = (Subscriber *)malloc(sizeof(Subscriber));
    printf("Enter email address: ");
    scanf("%s", list->subscribers[list->count]->email);
    list->count++;
    printf("Subscriber added.\n");
}

void remove_subscriber(MailingList *list) {
    char email[BUFFER_SIZE];
    printf("Enter email address to remove: ");
    scanf("%s", email);
    
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i]->email, email) == 0) {
            free(list->subscribers[i]);
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->subscribers[--list->count] = NULL;
            printf("Subscriber removed.\n");
            return;
        }
    }
    printf("Subscriber not found.\n");
}

void list_subscribers(MailingList *list) {
    printf("Current subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->subscribers[i]->email);
    }
}

void send_message(MailingList *list) {
    char message[BUFFER_SIZE];
    printf("Enter your message: ");
    getchar(); // Consume newline character left by previous scanf
    fgets(message, sizeof(message), stdin);
    printf("Sending message to subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("To: %s\nMessage: %s\n", list->subscribers[i]->email, message);
    }
}