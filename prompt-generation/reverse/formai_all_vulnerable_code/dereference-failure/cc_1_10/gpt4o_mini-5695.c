//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 1000

// Define a node in the linked list
typedef struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(const char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->word, word, MAX_WORD_LENGTH);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a word into the linked list
void insert(Node** head, const char* word) {
    Node* newNode = createNode(word);
    newNode->next = *head;
    *head = newNode;
}

// Function to check if a word exists in the dictionary
int checkWord(Node* head, const char* word) {
    Node* current = head;
    while (current != NULL) {
        if (strcasecmp(current->word, word) == 0) {
            return 1; // Word found
        }
        current = current->next;
    }
    return 0; // Word not found
}

// Function to load the dictionary from a file
Node* loadDictionary(const char* filename) {
    Node* head = NULL;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening dictionary file.\n");
        return NULL;
    }
    
    char word[MAX_WORD_LENGTH];
    while (fgets(word, sizeof(word), file)) {
        word[strcspn(word, "\n")] = '\0'; // Remove newline
        insert(&head, word);
    }
    fclose(file);
    return head;
}

// Function to free the linked list
void freeDictionary(Node* head) {
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

// Function to process user input for spell checking
void processInput(Node* dictionary) {
    char input[MAX_WORD_LENGTH];

    printf("Enter words to check (type 'exit' to quit):\n");
    while (1) {
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            continue; // Handle input error
        }
        
        // Remove newline character
        input[strcspn(input, "\n")] = '\0';

        if (strcasecmp(input, "exit") == 0) {
            break; // Exit condition
        }

        if (checkWord(dictionary, input)) {
            printf("'%s' is spelled correctly.\n", input);
        } else {
            printf("'%s' is misspelled.\n", input);
        }
    }
}

// Main function
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <dictionary_file>\n", argv[0]);
        return 1;
    }

    Node* dictionary = loadDictionary(argv[1]);
    if (dictionary == NULL) {
        return 1; // Exit if dictionary loading failed
    }

    processInput(dictionary);
    
    freeDictionary(dictionary); // Free memory before exiting
    return 0; // Successful execution
}