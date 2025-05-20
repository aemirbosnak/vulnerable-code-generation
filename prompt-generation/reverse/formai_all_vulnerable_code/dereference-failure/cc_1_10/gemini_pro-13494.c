//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for node
typedef struct node {
    char data;
    struct node *next;
} node;

// Function to reverse the linked list
node *reverse_list(node *head) {
    node *prev = NULL;
    node *current = head;
    node *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to compare two strings
int compare_strings(char *str1, char *str2) {
    int i;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2) {
        return 0;
    }

    for (i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }

    return 1;
}

// Function to check if a string is palindrome using linked list
int is_palindrome_linkedList(char *str) {
    node *head = NULL;
    node *tail = NULL;
    int i;
    int len = strlen(str);

    // Create a linked list from the string
    for (i = 0; i < len; i++) {
        node *new_node = (node *) malloc(sizeof(node));
        new_node->data = str[i];
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            tail->next = new_node;
        }

        tail = new_node;
    }

    // Reverse the linked list
    head = reverse_list(head);

    // Create a string from the reversed linked list
    char *reversed_str = (char *) malloc(len + 1);
    i = 0;
    while (head != NULL) {
        reversed_str[i] = head->data;
        i++;
        head = head->next;
    }
    reversed_str[i] = '\0';

    // Compare the original string with the reversed string
    int result = compare_strings(str, reversed_str);

    // Free the memory
    free(reversed_str);

    return result;
}

// Function to check if a string is palindrome using recursion
int is_palindrome_recursion(char *str, int start, int end) {
    if (start >= end) {
        return 1;
    }

    if (str[start] != str[end]) {
        return 0;
    }

    return is_palindrome_recursion(str, start + 1, end - 1);
}

// Function to check if a string is palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    int i;

    // Remove all spaces and convert to lowercase
    char *new_str = (char *) malloc(len + 1);
    int j = 0;
    for (i = 0; i < len; i++) {
        if (str[i] != ' ') {
            new_str[j] = tolower(str[i]);
            j++;
        }
    }
    new_str[j] = '\0';

    // Check if the new string is palindrome
    int result = is_palindrome_recursion(new_str, 0, strlen(new_str) - 1);

    // Free the memory
    free(new_str);

    return result;
}

// Main function
int main() {
    char str[] = "Racecar";

    if (is_palindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}