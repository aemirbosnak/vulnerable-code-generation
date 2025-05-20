//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 100
#define LINE_LENGTH 256

struct subscriber {
    char name[50];
    char email[100];
    bool active;
};

struct subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(char *name, char *email) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Mailing list is full.\n");
        return;
    }

    strcpy(subscribers[num_subscribers].name, name);
    strcpy(subscribers[num_subscribers].email, email);
    subscribers[num_subscribers].active = true;
    num_subscribers++;
}

void remove_subscriber(int index) {
    if (index < 0 || index >= num_subscribers) {
        printf("Invalid index.\n");
        return;
    }

    subscribers[index].active = false;
}

void send_email(char *subject, char *message) {
    int i;

    printf("Sending email with subject: %s\n", subject);

    for (i = 0; i < num_subscribers; i++) {
        if (subscribers[i].active) {
            printf("To: %s <%s>\n", subscribers[i].name, subscribers[i].email);
            printf("Subject: %s\n", subject);
            printf("Message:\n%s\n", message);

            // Send email using a library or external service

            printf("Email sent to %s.\n", subscribers[i].name);
        }
    }
}

int main(int argc, char *argv[]) {
    char name[50];
    char email[100];
    int index;
    char subject[100];
    char message[LINE_LENGTH];

    if (argc < 3) {
        printf("Usage: %s [add|remove] [name] [email|index]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "add") == 0) {
        if (argc != 4) {
            printf("Usage: %s add [name] [email]\n", argv[0]);
            return 1;
        }

        strcpy(name, argv[2]);
        strcpy(email, argv[3]);

        add_subscriber(name, email);
    } else if (strcmp(argv[1], "remove") == 0) {
        if (argc != 3) {
            printf("Usage: %s remove [index]\n", argv[0]);
            return 1;
        }

        sscanf(argv[2], "%d", &index);

        remove_subscriber(index);
    } else {
        printf("Usage: %s [add|remove] [name] [email|index]\n", argv[0]);
        return 1;
    }

    // Example usage of send_email function
    strcpy(subject, "New MelodyMail newsletter!");
    strcpy(message, "Check out the latest news and deals.\n");
    send_email(subject, message);

    return 0;
}