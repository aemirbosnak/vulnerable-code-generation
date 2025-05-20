//FormAI DATASET v1.0 Category: Mailing list manager ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure that represents an individual subscriber
struct subscriber {
    char name[50];
    char email[100];
    struct subscriber* next;
};

// Function to create a new subscriber node
struct subscriber* create_subscriber(char* name, char* email) {
    struct subscriber* new_node = (struct subscriber*) malloc(sizeof(struct subscriber));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = NULL;
    return new_node;
}

// Function to add a subscriber to the mailing list
void add_to_list(struct subscriber** head_ref, char* name, char* email) {
    struct subscriber* new_node = create_subscriber(name, email);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        struct subscriber* current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    printf("Subscriber added successfully!\n");
}

// Function to print the entire mailing list
void print_list(struct subscriber* head) {
    if (head == NULL) {
        printf("Mailing list is currently empty.\n");
    } else {
        printf("Mailing list:\n");
        struct subscriber* current = head;
        while (current != NULL) {
            printf("Name: %s, Email: %s\n", current->name, current->email);
            current = current->next;
        }
    }
}

// Function to remove a subscriber from the mailing list
void remove_from_list(struct subscriber** head_ref, char* email) {
    struct subscriber* current = *head_ref;
    struct subscriber* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (prev == NULL) {
                *head_ref = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Subscriber removed successfully!\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Subscriber not found on the list.\n");
}

// Function to read user input and call appropriate functions
void handle_user_input(struct subscriber** head_ref) {
    char name[50], email[100];
    char choice;
    printf("Select an option:\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. Print Mailing List\n");
    printf("4. Quit\n");
    printf("> ");
    scanf(" %c", &choice);
    switch (choice) {
        case '1':
            printf("Enter subscriber name: ");
            scanf(" %[^\n]s", name);
            printf("Enter subscriber email: ");
            scanf(" %[^\n]s", email);
            add_to_list(head_ref, name, email);
            break;
        case '2':
            printf("Enter subscriber email: ");
            scanf(" %[^\n]s", email);
            remove_from_list(head_ref, email);
            break;
        case '3':
            print_list(*head_ref);
            break;
        case '4':
            printf("Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Main function
int main() {
    struct subscriber* head = NULL;
    while (1) {
        handle_user_input(&head);
    }
    return 0;
}