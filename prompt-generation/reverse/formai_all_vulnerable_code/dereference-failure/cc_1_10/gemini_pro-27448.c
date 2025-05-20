//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phone_book {
    char name[50];
    char number[20];
    struct phone_book *next;
} phone_book;

phone_book *head = NULL;

void add_contact(char *name, char *number) {
    phone_book *new_contact = (phone_book *)malloc(sizeof(phone_book));
    strcpy(new_contact->name, name);
    strcpy(new_contact->number, number);
    new_contact->next = NULL;

    if (head == NULL) {
        head = new_contact;
    } else {
        phone_book *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_contact;
    }
}

void search_contact(char *name) {
    phone_book *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Name: %s\n", current->name);
            printf("Number: %s\n", current->number);
            return;
        }
        current = current->next;
    }
    printf("Contact not found.\n");
}

void delete_contact(char *name) {
    phone_book *current = head;
    phone_book *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Contact not found.\n");
}

void print_phone_book() {
    phone_book *current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Number: %s\n\n", current->number);
        current = current->next;
    }
}

int main() {
    int choice;
    char name[50];
    char number[20];

    while (1) {
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Print Phone Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf(" %s", name);
                printf("Enter number: ");
                scanf(" %s", number);
                add_contact(name, number);
                break;
            case 2:
                printf("Enter name: ");
                scanf(" %s", name);
                search_contact(name);
                break;
            case 3:
                printf("Enter name: ");
                scanf(" %s", name);
                delete_contact(name);
                break;
            case 4:
                print_phone_book();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}