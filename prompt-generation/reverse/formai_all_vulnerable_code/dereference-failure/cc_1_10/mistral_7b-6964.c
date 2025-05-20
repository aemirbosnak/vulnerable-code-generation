//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_SUBSCRIBER_NAME_LENGTH 50
#define EMAIL_LENGTH 100

typedef struct {
    char name[MAX_SUBSCRIBER_NAME_LENGTH];
    char email[EMAIL_LENGTH];
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber(const char* name, const char* email) {
    if (num_subscribers >= MAX_SUBSCRIBERS) {
        printf("Error: Max number of subscribers reached.\n");
        return;
    }

    strcpy(subscribers[num_subscribers].name, name);
    strcpy(subscribers[num_subscribers].email, email);
    num_subscribers++;
}

void remove_subscriber(int index) {
    if (index < 0 || index >= num_subscribers) {
        printf("Error: Invalid index.\n");
        return;
    }

    num_subscribers--;
    memmove(&subscribers[index], &subscribers[index + 1], sizeof(Subscriber) * (num_subscribers - index));
}

void print_subscribers() {
    printf("Subscribers:\n");
    for (int i = 0; i < num_subscribers; i++) {
        printf("%s (%s)\n", subscribers[i].name, subscribers[i].email);
    }
}

int main(int argc, char* argv[]) {
    char command[50];
    int index;

    if (argc < 2) {
        printf("Usage: %s [add|remove] [name] [email]\n", argv[0]);
        return 1;
    }

    strcpy(command, argv[1]);

    if (strcmp(command, "add") == 0) {
        if (argc < 4) {
            printf("Error: Missing name or email for add command.\n");
            return 1;
        }

        add_subscriber(argv[2], argv[3]);
        printf("Subscriber added successfully.\n");
    } else if (strcmp(command, "remove") == 0) {
        if (argc < 3) {
            printf("Error: Missing index for remove command.\n");
            return 1;
        }

        index = atoi(argv[2]);
        remove_subscriber(index);
        printf("Subscriber removed successfully.\n");
    } else {
        printf("Error: Invalid command. Use add or remove.\n");
        return 1;
    }

    print_subscribers();

    return 0;
}