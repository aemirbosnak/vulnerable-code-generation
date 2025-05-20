//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct Subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct Subscriber* next;
} Subscriber;

Subscriber* head = NULL;

void print_list() {
    Subscriber* current = head;
    printf("Subscribers:\n");
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->email);
        current = current->next;
    }
}

int add_subscriber(char* name, char* email) {
    Subscriber* new_subscriber = (Subscriber*) malloc(sizeof(Subscriber));
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->next = head;
    head = new_subscriber;
    return 1;
}

int remove_subscriber(char* name, char* email) {
    Subscriber* current = head;
    Subscriber* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0 && strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return 1;
        }
        previous = current;
        current = current->next;
    }

    return 0;
}

int main() {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    add_subscriber("Alice", "alice@example.com");
    add_subscriber("Bob", "bob@example.com");

    print_list();

    remove_subscriber("Alice", "alice@example.com");

    print_list();

    return 0;
}