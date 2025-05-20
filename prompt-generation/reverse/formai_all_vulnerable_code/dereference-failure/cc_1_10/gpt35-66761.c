//FormAI DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email {
    char name[50];
    char address[100];
    struct email* next;
};

typedef struct email email_t;

void add_email(email_t** head, char* name, char* address) {
    email_t* new_email = (email_t*)malloc(sizeof(email_t));
    strcpy(new_email->name, name);
    strcpy(new_email->address, address);
    new_email->next = *head;
    *head = new_email;
}

void print_emails(email_t* head) {
    if (head == NULL) {
        printf("No emails in the list.\n");
    } else {
        email_t* current = head;
        printf("Current Mailing List:\n");
        while (current != NULL) {
            printf("%s: %s\n", current->name, current->address);
            current = current->next;
        }
    }
}

void delete_email(email_t** head, char* address) {
    email_t* current = *head;
    email_t* prev = NULL;
    while (current != NULL && strcmp(current->address, address) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Email not found.\n");
    } else {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        printf("Deleted email: %s\n", current->address);
        free(current);
    }
}

int main() {
    email_t* head = NULL;
    char name[50];
    char address[100];
    int choice;
    do {
        printf("Menu:\n");
        printf("1. Add email\n");
        printf("2. Delete email\n");
        printf("3. Print list\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter address: ");
                scanf("%s", address);
                add_email(&head, name, address);
                printf("Email added.\n");
                break;
            case 2:
                printf("Enter address to delete: ");
                scanf("%s", address);
                delete_email(&head, address);
                break;
            case 3:
                print_emails(head);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    email_t* current = head;
    while (current != NULL) {
        email_t* next_email = current->next;
        free(current);
        current = next_email;
    }
    return 0;
}