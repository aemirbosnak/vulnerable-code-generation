//FormAI DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the linked list
typedef struct node {
    char password[50];
    struct node * next;
} Node;

// Function declarations
void add_password(Node ** list, char * password);
void delete_password(Node ** list, char * password);
void print_list(Node * list);

int main() {
    Node * password_list = NULL;
    char option;

    printf("Welcome to the Password Manager!\n");

    do {
        printf("\nPlease select an option:\n");
        printf("a) Add a password\n");
        printf("b) Delete a password\n");
        printf("c) View all passwords\n");
        printf("x) Exit\n");

        scanf(" %c", &option);

        switch(option) {
            case 'a':
                // Add a password
                printf("\nEnter the password you want to add: ");
                char new_password[50];
                scanf(" %s", new_password);
                add_password(&password_list, new_password);
                printf("\nPassword added successfully!\n");
                break;
            case 'b':
                // Delete a password
                printf("\nEnter the password you want to delete: ");
                char password_to_delete[50];
                scanf(" %s", password_to_delete);
                delete_password(&password_list, password_to_delete);
                printf("\nPassword deleted successfully!\n");
                break;
            case 'c':
                // View all passwords
                printf("\nHere are all the passwords:\n");
                print_list(password_list);
                break;
            case 'x':
                // Exit
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option, please try again.\n");
                break;
        }
    } while(option != 'x');

    return 0;
}

void add_password(Node ** list, char * password) {
    // Create a new node for the password
    Node * new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->password, password);
    new_node->next = NULL;

    // Add the new node to the end of the list
    if (*list == NULL) {
        // If the list is empty, make the new node the head
        *list = new_node;
    } else {
        // Find the end of the list
        Node * current_node = *list;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        // Add the new node to the end
        current_node->next = new_node;
    }
}

void delete_password(Node ** list, char * password) {
    // Find the node with the password
    Node * current_node = *list;
    Node * previous_node = NULL;
    while (current_node != NULL && strcmp(current_node->password, password) != 0) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    // If the node was found, delete it
    if (current_node != NULL) {
        if (previous_node == NULL) {
            // If the node is the head of the list, update the head pointer
            *list = current_node->next;
        } else {
            // Otherwise, update the previous node's next pointer
            previous_node->next = current_node->next;
        }
        // Free the memory used by the deleted node
        free(current_node);
    }
}

void print_list(Node * list) {
    Node * current_node = list;
    while (current_node != NULL) {
        printf("%s\n", current_node->password);
        current_node = current_node->next;
    }
}