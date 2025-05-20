//FormAI DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

typedef struct pass_node {
    char password[MAX_LEN];
    struct pass_node* next;
} PasswordNode;

void add_password(PasswordNode* current_node) {
    char password_input[MAX_LEN];
    printf("Enter a password: ");
    fgets(password_input, MAX_LEN, stdin);

    // remove newline character
    password_input[strcspn(password_input, "\n")] = 0;

    if (strlen(password_input) == 0) {
        return;
    }

    // add password to linked list
    PasswordNode* new_node = (PasswordNode*)malloc(sizeof(PasswordNode));
    strncpy(new_node->password, password_input, MAX_LEN);
    new_node->next = NULL;
    current_node->next = new_node;

    // continue entering passwords recursively
    add_password(new_node);
}

void print_all_passwords(PasswordNode* current_node) {
    if (current_node == NULL) {
        printf("No passwords saved.\n");
        return;
    }

    printf("%s\n", current_node->password);

    if (current_node->next != NULL) {
        print_all_passwords(current_node->next);
    }
}

void free_all_memory(PasswordNode* current_node) {
    if (current_node == NULL) {
        return;
    }

    if (current_node->next != NULL) {
        free_all_memory(current_node->next);
    }

    free(current_node);
}

int main() {
    PasswordNode* head_node = (PasswordNode*)malloc(sizeof(PasswordNode));
    strncpy(head_node->password, "HEAD", MAX_LEN);
    head_node->next = NULL;

    printf("Password Manager\n");

    add_password(head_node);

    printf("\nHere are all the saved passwords:\n");
    print_all_passwords(head_node->next);

    free_all_memory(head_node->next);
    free(head_node);

    return 0;
}