//FormAI DATASET v1.0 Category: Mailing list manager ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char email[50];
    struct Node* next;
} node_t;

node_t* create_node(char email[]) {
    node_t* node = (node_t*) malloc(sizeof(node_t));
    strcpy(node->email, email);
    node->next = NULL;
    return node;
}

void print_list(node_t* head) {
    node_t* current = head;
    while (current != NULL) {
        printf("%s -> ", current->email);
        current = current->next;
    }
    printf("NULL\n");
}

void insert_node(node_t** head, char email[]) {
    node_t* node = create_node(email);
    if (*head == NULL) {
        *head = node;
    } else {
        node_t* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

void delete_node(node_t** head, char email[]) {
    node_t* current = *head;
    node_t* previous = NULL;
    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Email not found in the list.\n");
    } else if (previous == NULL) {
        *head = current->next;
        printf("Email %s deleted from the list.\n", email);
        free(current);
    } else {
        previous->next = current->next;
        printf("Email %s deleted from the list.\n", email);
        free(current);
    }
}

void sort_list(node_t** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    node_t *left = *head;
    node_t *right = (*head)->next;
    while (right != NULL) {
        right = right->next;
        if (right != NULL) {
            left = left->next;
            right = right->next;
        }
    }
    right = left->next;
    left->next = NULL;
    left = *head;
    sort_list(&left);
    sort_list(&right);
    node_t *new_head = NULL;
    if (strcmp(left->email, right->email) < 0) {
        new_head = left;
        left = left->next;
    } else {
        new_head = right;
        right = right->next;
    }
    node_t* current = new_head;
    while (left && right) {
        if (strcmp(left->email, right->email) < 0) {
            current->next = left;
            left = left->next;
        } else {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }
    if (left) {
        current->next = left;
    } else {
        current->next = right;
    }
    *head = new_head;
}

int main() {
    node_t* head = NULL;
    char email[50];
    int option;

    do {
        printf("\n1. Add email to the list\n");
        printf("2. Delete email from the list\n");
        printf("3. Print current list\n");
        printf("4. Sort the list\n");
        printf("5. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter an email address to add: ");
                scanf("%s", email);
                insert_node(&head, email);
                break;
            case 2:
                printf("Enter an email address to delete: ");
                scanf("%s", email);
                delete_node(&head, email);
                break;
            case 3:
                printf("Current list:\n");
                print_list(head);
                break;
            case 4:
                printf("Sorting the list...\n");
                sort_list(&head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (option != 5);

    return 0;
}