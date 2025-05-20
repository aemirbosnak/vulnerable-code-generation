//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom data structure to represent a word
typedef struct Word {
    char *word;     // Pointer to the word string
    int count;      // Count of occurrences
    struct Word *next;  // Pointer to the next word in the linked list
} Word;

// Function to create a new word node
Word *createWordNode(char *word) {
    Word *newWord = (Word *) malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->count = 1;
    newWord->next = NULL;
    return newWord;
}

// Function to add a word to the linked list
void addWord(Word **head, char *word) {
    // If the head is NULL, create a new word node and set it as the head
    if (*head == NULL) {
        *head = createWordNode(word);
        return;
    }

    // Otherwise, traverse the linked list until we find the word or reach the end
    Word *current = *head;
    while (current != NULL) {
        // If the word is found, increment its count
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }

        // If we reach the end of the linked list, add the word as a new node
        if (current->next == NULL) {
            current->next = createWordNode(word);
            return;
        }

        // Otherwise, move to the next word in the linked list
        current = current->next;
    }
}

// Function to print the linked list of words
void printWords(Word *head) {
    Word *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

// Function to free the memory allocated for the linked list
void freeWords(Word *head) {
    Word *current = head;
    while (current != NULL) {
        Word *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}

int main() {
    // Initialize the head of the linked list to NULL
    Word *head = NULL;

    // Read a line of text from the user
    char line[1024];
    printf("Enter a line of text: ");
    fgets(line, 1024, stdin);

    // Tokenize the line of text into words
    char *token = strtok(line, " ");
    while (token != NULL) {
        // Add each word to the linked list
        addWord(&head, token);

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Print the linked list of words
    printf("Word Frequency:\n");
    printWords(head);

    // Free the memory allocated for the linked list
    freeWords(head);

    return 0;
}