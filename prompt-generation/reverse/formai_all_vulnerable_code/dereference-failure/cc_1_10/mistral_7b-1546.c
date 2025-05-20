//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char number[20];
    struct contact *next;
} contact;

contact *head = NULL;

void add_contact(char *name, char *number) {
    contact *new_contact = (contact *) malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->number, number);
    new_contact->next = head;
    head = new_contact;
    printf("Contact %s added to the phone book!\n", name);
}

contact *search_contact(char *name) {
    contact *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Contact %s found!\n", name);
            printf("Phone number: %s\n", current->number);
            return current;
        }
        current = current->next;
    }
    printf("Contact %s not found.\n", name);
    return NULL;
}

void delete_contact(char *name) {
    contact *current = head;
    contact *previous = NULL;
    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Contact %s not found.\n", name);
        return;
    }
    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    printf("Contact %s deleted from the phone book.\n", name);
}

int main() {
    char command[20], name[50], number[20];
    while (1) {
        printf("\nWelcome to the WhimsyWay Phone Book!\n");
        printf("Please enter a command: add, search, delete, or quit.\n");
        scanf("%s", command);
        if (strcmp(command, "quit") == 0) {
            break;
        }
        switch (command[0]) {
            case 'a':
                printf("Enter the name of the contact: ");
                scanf("%s", name);
                printf("Enter the phone number: ");
                scanf("%s", number);
                add_contact(name, number);
                break;
            case 's':
                printf("Enter the name of the contact to search for: ");
                scanf("%s", name);
                search_contact(name);
                break;
            case 'd':
                printf("Enter the name of the contact to delete: ");
                scanf("%s", name);
                delete_contact(name);
                break;
            default:
                printf("Invalid command. Please try again.\n");
        }
    }
    return 0;
}