//FormAI DATASET v1.0 Category: Spell checking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// structure to hold dictionary words
typedef struct node {
    char word[50];
    struct node *next;
} node_t;

// function to add word to the dictionary
void add_word_to_dictionary(node_t **head, char *word) {
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    strcpy(new_node->word, word);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node; // if the dictionary is empty
    } else {
        node_t *current_node = *head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node; // append new word to the dictionary
    }
}

// function to print the dictionary
void print_dictionary(node_t *head) {
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%s\n", current_node->word);
        current_node = current_node->next;
    }
}

// function to check if the word is present in the dictionary
int is_word_present_in_dictionary(node_t *head, char *word) {
    node_t *current_node = head;
    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

// function to check the spelling of the input text
void spell_check(node_t *dictionary, char *text) {
    char *token = strtok(text, " ");
    while (token != NULL) {
        if (!is_word_present_in_dictionary(dictionary, token)) {
            printf("'%s' is spelled incorrectly\n", token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    node_t *dictionary = NULL;
    add_word_to_dictionary(&dictionary, "apple");
    add_word_to_dictionary(&dictionary, "banana");
    add_word_to_dictionary(&dictionary, "orange");

    printf("Dictionary:\n");
    print_dictionary(dictionary);

    char input_text[100];
    printf("Enter some text to spell check: ");
    fgets(input_text, 100, stdin);
    input_text[strcspn(input_text, "\n")] = 0; // remove newline character from input

    spell_check(dictionary, input_text);

    return 0;
}