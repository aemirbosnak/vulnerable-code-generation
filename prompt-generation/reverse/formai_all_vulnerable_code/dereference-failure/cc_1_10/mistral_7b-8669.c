//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

typedef struct string {
    char data[MAX_LENGTH];
    struct string *next;
} string_t;

// Function to check if a character is an alphanumeric character or not
int is_alnum(char c) {
    return (isalpha(c) || isdigit(c));
}

// Function to convert a string to lowercase
void to_lower(char *str) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
}

// Recursive self-referential function to check if a string is a palindrome
int is_palindrome_recursive(string_t *str) {
    if (str == NULL) {
        return 1;
    }

    if (str->next == NULL) {
        return 1;
    }

    if (str->next->next == NULL) {
        return str->data[0] == str->next->data[0];
    }

    to_lower(&(str->data[0]));
    to_lower(&(str->next->data[0]));

    return str->data[0] == str->next->data[0] ||
           is_palindrome_recursive(str->next->next) &&
           is_palindrome_recursive(str);
}

// Function to create a linked list of strings
void create_linked_list(string_t **head, char *str) {
    string_t *new_node = (string_t *) malloc(sizeof(string_t));

    if (*head == NULL) {
        *head = new_node;
        new_node->next = NULL;
        strcpy(new_node->data, str);
        return;
    }

    string_t *current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    new_node->next = NULL;
    strcpy(new_node->data, str);
}

// Function to check if a given string is a palindrome
int main(int argc, char *argv[]) {
    string_t *head = NULL;

    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    create_linked_list(&head, argv[1]);
    int result = is_palindrome_recursive(head);

    if (result) {
        printf("%s is a palindrome\n", argv[1]);
    } else {
        printf("%s is not a palindrome\n", argv[1]);
    }

    while (head != NULL) {
        string_t *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}