//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Node structure for linked list
typedef struct node {
    char word[100];
    struct node* next;
} node;

// Function declarations
void add_word(node** head, char* word);
void print_list(node* head);
int compare_strings(char* str1, char* str2);

// Main function
int main() {
    node* head = NULL;
    char input[100];
    char* token;

    // Prompt user for input
    printf("Enter a romantic message: ");
    fgets(input, sizeof(input), stdin);

    // Convert input to lowercase
    for (int i = 0; input[i]!= '\0'; i++) {
        input[i] = tolower(input[i]);
    }

    // Tokenize input
    token = strtok(input, " ");
    while (token!= NULL) {
        add_word(&head, token);
        token = strtok(NULL, " ");
    }

    // Print list of words
    printf("\nList of words:\n");
    print_list(head);

    return 0;
}

// Function to add a word to the linked list
void add_word(node** head, char* word) {
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->word, word);
    new_node->next = *head;
    *head = new_node;
}

// Function to print the linked list
void print_list(node* head) {
    while (head!= NULL) {
        printf("%s ", head->word);
        head = head->next;
    }
    printf("\n");
}

// Function to compare two strings (case-insensitive)
int compare_strings(char* str1, char* str2) {
    while (*str1!= '\0' && *str2!= '\0') {
        if (*str1!= *str2) {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }
    return 0;
}