//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SUBSCRIBERS 1000

typedef struct {
    char name[50];
    char email[100];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int subscriber_count = 0;

void add_subscriber(char *name, char *email) {
    if (subscriber_count >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full.\n");
        return;
    }
    strcpy(subscribers[subscriber_count].name, name);
    strcpy(subscribers[subscriber_count].email, email);
    subscriber_count++;
    printf("Subscriber added successfully.\n");
}

void remove_subscriber(char *name) {
    int i;
    for (i = 0; i < subscriber_count; i++) {
        if (strcmp(subscribers[i].name, name) == 0) {
            memmove(&subscribers[i], &subscribers[i + 1], sizeof(Subscriber) * (subscriber_count - i - 1));
            subscriber_count--;
            printf("Subscriber removed successfully.\n");
            return;
        }
    }
    printf("Subscriber not found.\n");
}

void send_email(char *subject, char *message) {
    int i;
    for (i = 0; i < subscriber_count; i++) {
        char email[100];
        strcpy(email, subscribers[i].email);
        printf("Sending email to %s:\nSubject: %s\nMessage:\n%s\n", subscribers[i].name, subject, message);
        // code to send email goes here
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <add|remove> <name> <email|name>\n", argv[0]);
        return 1;
    }

    char cmd = argv[1][0];
    if (cmd == 'a' || cmd == 'A') {
        add_subscriber(argv[2], argv[3]);
    } else if (cmd == 'r' || cmd == 'R') {
        remove_subscriber(argv[2]);
    } else {
        printf("Invalid command.\nUsage: %s <add|remove> <name> <email|name>\n", argv[0]);
        return 1;
    }

    return 0;
}