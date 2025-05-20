//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char phone[20];
    struct user *next;
} user;

user *head = NULL;

void add_contact(int user_id, char name[], char phone[]) {
    user *new_user = (user *) malloc(sizeof(user));
    new_user->id = user_id;
    strcpy(new_user->name, name);
    strcpy(new_user->phone, phone);
    new_user->next = head;
    head = new_user;
}

void delete_contact(int user_id) {
    user *current = head;
    user *previous = NULL;

    while (current != NULL) {
        if (current->id == user_id) {
            if (previous == NULL) {
                head = current->next;
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

void search_contacts(int user_id) {
    user *current = head;

    while (current != NULL) {
        if (current->id == user_id) {
            printf("Name: %s\n", current->name);
            printf("Phone: %s\n", current->phone);
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Contact not found.\n");
    }
}

int main() {
    int choice, user_id, id;
    char name[50], phone[20];

    while (1) {
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter user ID: ");
                scanf("%d", &user_id);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                add_contact(user_id, name, phone);
                break;
            case 2:
                printf("Enter user ID to delete: ");
                scanf("%d", &user_id);
                delete_contact(user_id);
                break;
            case 3:
                printf("Enter user ID to search: ");
                scanf("%d", &id);
                search_contacts(id);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}