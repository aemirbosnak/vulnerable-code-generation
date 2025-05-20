//FormAI DATASET v1.0 Category: Phone Book ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_NUM_LENGTH 10

struct contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUM_LENGTH];
    struct contact *next;
};

void add_contact(struct contact **head, char *name, char *number);
void print_contacts(struct contact *head);
void search_contact(struct contact *head, char *name);
void delete_contact(struct contact **head, char *name);

int main() {
    struct contact *head = NULL;
    int choice;
    char name[MAX_NAME_LENGTH], number[MAX_NUM_LENGTH];

    while (1) {
        printf("Phone Book\n");
        printf("1. Add Contact\n");
        printf("2. Print Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                add_contact(&head, name, number);
                break;
            case 2:
                print_contacts(head);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                search_contact(head, name);
                break;
            case 4:
                printf("Enter name to delete: ");
                scanf("%s", name);
                delete_contact(&head, name);
                break;
            case 5:
                printf("Exiting program...");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void add_contact(struct contact **head, char *name, char *number) {
    struct contact *new_contact = (struct contact*) malloc(sizeof(struct contact));
    strncpy(new_contact->name, name, MAX_NAME_LENGTH);
    strncpy(new_contact->number, number, MAX_NUM_LENGTH);
    new_contact->next = *head;
    *head = new_contact;
    printf("%s added to phone book!\n", name);
}

void print_contacts(struct contact *head) {
    if (head == NULL) {
        printf("Phone book is empty!\n");
        return;
    }

    struct contact *curr = head;
    printf("%-20s %s\n", "Name", "Number");
    while (curr != NULL) {
        printf("%-20s %s\n", curr->name, curr->number);
        curr = curr->next;
    }
}

void search_contact(struct contact *head, char *name) {
    struct contact *curr = head;
    while (curr != NULL) {
        if (strncmp(curr->name, name, MAX_NAME_LENGTH) == 0) {
            printf("%-20s %s\n", "Name", "Number");
            printf("%-20s %s\n", curr->name, curr->number);
            return;
        }
        curr = curr->next;
    }
    printf("Contact not found.\n");
}

void delete_contact(struct contact **head, char *name) {
    struct contact *curr = *head;
    struct contact *prev = NULL;

    while (curr != NULL) {
        if (strncmp(curr->name, name, MAX_NAME_LENGTH) == 0) {
            if (prev == NULL) {
                *head = curr->next;
            } else {
                prev->next = curr->next;
            }
            
            free(curr);
            printf("%s deleted from phone book!\n", name);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Contact not found.\n");
}