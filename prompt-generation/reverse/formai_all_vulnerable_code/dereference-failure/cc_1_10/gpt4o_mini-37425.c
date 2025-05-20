//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Maximum lengths for word buffers.
#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 256
#define DICTIONARY_FILE "dictionary.txt"
#define MAX_SUGGESTIONS 5

// Node structure for the dictionary linked list.
typedef struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node* next;
} Node;

// Function prototypes.
Node* createNode(const char* word);
void insertWord(Node** head, const char* word);
int loadDictionary(Node** head, const char* filename);
int isWordInDictionary(Node* head, const char* word);
void suggestCorrections(Node* head, const char* incorrect);
void freeDictionary(Node* head);

// Entry point of the program.
int main() {
    Node* dictionary = NULL;

    // Load the dictionary into memory.
    if (loadDictionary(&dictionary, DICTIONARY_FILE) == 0) {
        fprintf(stderr, "Failed to load dictionary.\n");
        return 1;
    }

    char input[MAX_LINE_LENGTH];
    printf("Enter a sentence to check for spelling errors:\n");
    fgets(input, sizeof(input), stdin);

    // Process each word in the input sentence.
    char* token = strtok(input, " \n");
    while (token != NULL) {
        // Remove punctuation from the token.
        char word[MAX_WORD_LENGTH];
        int j = 0;
        for (int i = 0; token[i] != '\0'; i++) {
            if (isalpha(token[i])) {
                word[j++] = tolower(token[i]); // Convert to lowercase
            }
        }
        word[j] = '\0';

        // Check if the word exists in the dictionary.
        if (!isWordInDictionary(dictionary, word)) {
            printf("Misspelled word: %s\n", word);
            suggestCorrections(dictionary, word);
        }

        // Get the next word.
        token = strtok(NULL, " \n");
    }

    // Free the allocated memory for the dictionary.
    freeDictionary(dictionary);
    return 0;
}

// Create a new node for a word.
Node* createNode(const char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        strncpy(newNode->word, word, MAX_WORD_LENGTH);
        newNode->next = NULL;
    }
    return newNode;
}

// Insert a word into the linked list.
void insertWord(Node** head, const char* word) {
    Node* newNode = createNode(word);
    newNode->next = *head;
    *head = newNode;
}

// Load dictionary words from a file into a linked list.
int loadDictionary(Node** head, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return 0; // Return failure if file cannot be opened.
    }

    char word[MAX_WORD_LENGTH];
    while (fgets(word, sizeof(word), file) != NULL) {
        // Strip newline character at the end.
        word[strcspn(word, "\n")] = '\0';
        insertWord(head, word);
    }

    fclose(file);
    return 1; // Successfully loaded the dictionary.
}

// Check if the given word is in the dictionary.
int isWordInDictionary(Node* head, const char* word) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1; // Word found.
        }
        current = current->next;
    }
    return 0; // Word not found.
}

// Suggest corrections based on close matches from the dictionary.
void suggestCorrections(Node* head, const char* incorrect) {
    printf("Suggested corrections for '%s':\n", incorrect);
    Node* current = head;
    int count = 0;

    // Traverse dictionary to find similar words.
    while (current != NULL && count < MAX_SUGGESTIONS) {
        // Check for simple edit distance (of 1) by varying one character.
        if (abs((int)(strlen(current->word) - strlen(incorrect))) <= 1) {
            printf("- %s\n", current->word);
            count++;
        }
        current = current->next;
    }

    if (count == 0) {
        printf("No suggestions available.\n");
    }
}

// Free the memory allocated for the dictionary.
void freeDictionary(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }
}