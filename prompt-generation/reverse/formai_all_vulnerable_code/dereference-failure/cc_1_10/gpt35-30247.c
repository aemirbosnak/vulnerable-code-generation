//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 25 /* Maximum word length to track */

/* Node to hold each word and its frequency */
typedef struct word_node {
    char word[MAX_WORD_LENGTH];
    int frequency;
    struct word_node* next;
} WordNode;

/* Function to add a new word node to the linked list */
void add_word_node(WordNode** head, char* word) {
    if (*head == NULL) {
        /* If the list is empty, create the first node */
        *head = malloc(sizeof(WordNode));
        strcpy((*head)->word, word);
        (*head)->frequency = 1;
        (*head)->next = NULL;
    } else {
        /* Search for the word in the list */
        WordNode* current = *head;
        WordNode* previous = NULL;
        while (current != NULL && strcmp(current->word, word) < 0) {
            previous = current;
            current = current->next;
        }
        if (current != NULL && strcmp(current->word, word) == 0) {
            /* If the word is already in the list, increment its frequency */
            current->frequency++;
        } else {
            /* If the word is not in the list, create a new node and insert it alphabetically */
            WordNode* new_node = malloc(sizeof(WordNode));
            strcpy(new_node->word, word);
            new_node->frequency = 1;
            new_node->next = current;
            if (previous != NULL) {
                previous->next = new_node;
            } else {
                *head = new_node;
            }
        }
    }
}

int main() {
    /* Initialize the linked list */
    WordNode* head = NULL;

    /* Open the input file */
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    /* Loop through the file character by character */
    char current_char;
    int current_word_length = 0;
    char current_word[MAX_WORD_LENGTH];
    while ((current_char = fgetc(input_file)) != EOF) {
        if (isalpha(current_char)) {
            /* If the character is alphabetic, add it to the current word */
            current_word[current_word_length++] = tolower(current_char);
            if (current_word_length >= MAX_WORD_LENGTH) {
                printf("Error: Maximum word length exceeded.\n");
                return 1;
            }
        } else if (current_word_length > 0) {
            /* If the character is not alphabetic and the current word is not empty, add it to the list */
            current_word[current_word_length] = '\0';
            add_word_node(&head, current_word);
            current_word_length = 0;
        }
    }

    /* Print the word frequencies */
    WordNode* current_node = head;
    while (current_node != NULL) {
        printf("%s: %d\n", current_node->word, current_node->frequency);
        current_node = current_node->next;
    }

    /* Close the input file and free the memory used by the linked list */
    fclose(input_file);
    current_node = head;
    while (current_node != NULL) {
        WordNode* next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    return 0;
}