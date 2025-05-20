//FormAI DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mailing_list {
    char name[50];
    char email[50];
    struct mailing_list *next;
};

struct mailing_list *head = NULL;
struct mailing_list *tail = NULL;

void add_contact() {
    struct mailing_list *new_contact = (struct mailing_list*) malloc(sizeof(struct mailing_list));
    printf("Enter name: ");
    scanf("%s", new_contact->name);
    printf("Enter email: ");
    scanf("%s", new_contact->email);
    new_contact->next = NULL;
    if (head == NULL) {
        head = new_contact;
        tail = new_contact;
    } else {
        tail->next = new_contact;
        tail = new_contact;
    }
    printf("%s added to mailing list.\n", new_contact->name);
}

void delete_contact() {
    char name[50];
    printf("Enter name of contact to delete: ");
    scanf("%s", name);
    struct mailing_list *current = head;
    struct mailing_list *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current == head) {
                head = current->next;
            } else if (current == tail) {
                previous->next = NULL;
                tail = previous;
            } else {
                previous->next = current->next;
            }
            printf("%s deleted.\n", name);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("%s not found.\n", name);
}

void print_list() {
    struct mailing_list *current = head;
    if (current == NULL) {
        printf("Mailing list is empty.\n");
    } else {
        while (current != NULL) {
            printf("%s: %s\n", current->name, current->email);
            current = current->next;
        }
    }
}

int main() {
    printf("Mailing List Manager\n");
    printf("====================\n");
    int choice;
    do {
        printf("\n1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                delete_contact();
                break;
            case 3:
                print_list();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    struct mailing_list *current = head;
    struct mailing_list *previous = NULL;
    while (current != NULL) {
        previous = current;
        current = current->next;
        free(previous);
    }
    return 0;
}