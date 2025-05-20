//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

// A node in a linked list
typedef struct node {
    char *word;
    int count;
    struct node *next;
} node_t;

// Create a new node
node_t *new_node(char *word) {
    node_t *node = malloc(sizeof(node_t));
    node->word = strdup(word);
    node->count = 1;
    node->next = NULL;
    return node;
}

// Destroy a linked list
void destroy_list(node_t *head) {
    while (head) {
        node_t *next = head->next;
        free(head->word);
        free(head);
        head = next;
    }
}

// Insert a word into a linked list
void insert_word(node_t **head, char *word) {
    // Create a new node
    node_t *node = new_node(word);

    // If the list is empty, make the new node the head
    if (!*head) {
        *head = node;
        return;
    }

    // Otherwise, insert the new node at the beginning of the list
    node->next = *head;
    *head = node;
}

// Count the number of occurrences of each word in a string
node_t *count_words(char *str) {
    // Tokenize the string
    char *words[MAX_WORDS];
    int num_words = 0;
    char *token = strtok(str, " ");
    while (token && num_words < MAX_WORDS) {
        words[num_words++] = strdup(token);
        token = strtok(NULL, " ");
    }

    // Count the number of occurrences of each word
    node_t *head = NULL;
    for (int i = 0; i < num_words; i++) {
        // Convert the word to lowercase
        for (int j = 0; j < strlen(words[i]); j++) {
            words[i][j] = tolower(words[i][j]);
        }

        // Insert the word into the linked list
        insert_word(&head, words[i]);
    }

    // Free the tokens
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }

    return head;
}

// Print the words and their counts
void print_words(node_t *head) {
    while (head) {
        printf("%s: %d\n", head->word, head->count);
        head = head->next;
    }
}

int main() {
    // Get the input string
    char str[1000];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Count the words
    node_t *head = count_words(str);

    // Print the words and their counts
    print_words(head);

    // Destroy the linked list
    destroy_list(head);

    return 0;
}