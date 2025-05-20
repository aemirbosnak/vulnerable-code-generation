//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SUBSCRIBERS 1000
#define LINE_LENGTH 255

typedef struct Subscriber {
    char name[50];
    char email[100];
    struct Subscriber *next;
} Subscriber;

Subscriber *mailing_list = NULL;

void add_subscriber(char *name, char *email) {
    Subscriber *new_subscriber = (Subscriber *) malloc(sizeof(Subscriber));
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->next = mailing_list;
    mailing_list = new_subscriber;
}

void remove_subscriber(char *email) {
    Subscriber *current = mailing_list;
    Subscriber *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                mailing_list = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void print_mailing_list() {
    Subscriber *current = mailing_list;

    printf("\nMailing List:\n");
    while (current != NULL) {
        printf("%s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

void process_command(char *command) {
    char name[50], email[100];
    char *token;

    token = strtok(command, " ");
    if (strcmp(token, "add") == 0) {
        token = strtok(NULL, " ");
        strcpy(name, token);
        token = strtok(NULL, " ");
        strcpy(email, token);
        add_subscriber(name, email);
    } else if (strcmp(token, "remove") == 0) {
        token = strtok(NULL, " ");
        strcpy(email, token);
        remove_subscriber(email);
    } else if (strcmp(token, "print") == 0) {
        print_mailing_list();
    }
}

int main() {
    char line[LINE_LENGTH];

    while (fgets(line, LINE_LENGTH, stdin) != NULL) {
        if (line[0] != '\0') {
            process_command(line);
        }
    }

    return 0;
}