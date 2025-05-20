//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: Alan Turing
/*
 * AlanTuringMLM - A simple C mailing list manager.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIST_SIZE 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

Subscriber list[MAX_LIST_SIZE];
int subscribers_count = 0;

void add_subscriber(const char *name, const char *email) {
    if (subscribers_count >= MAX_LIST_SIZE) {
        printf("Error: Mailing list is full.\n");
        return;
    }
    strcpy(list[subscribers_count].name, name);
    strcpy(list[subscribers_count].email, email);
    subscribers_count++;
}

void remove_subscriber(const char *email) {
    int i;
    bool found = false;

    for (i = 0; i < subscribers_count; i++) {
        if (strcmp(list[i].email, email) == 0) {
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Error: Subscriber not found.\n");
        return;
    }

    for (; i < subscribers_count - 1; i++) {
        list[i] = list[i + 1];
    }

    subscribers_count--;
}

void print_subscribers() {
    int i;

    printf("\nSubscribers:\n");

    for (i = 0; i < subscribers_count; i++) {
        printf("%s (%s)\n", list[i].name, list[i].email);
    }
}

int main() {
    const char *name, *email;
    int choice;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Print subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_subscriber(name, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                remove_subscriber(email);
                break;
            case 3:
                print_subscribers();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}