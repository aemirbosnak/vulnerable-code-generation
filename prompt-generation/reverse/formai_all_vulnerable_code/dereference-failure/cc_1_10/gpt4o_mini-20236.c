//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// A node in a linked list to store dictionary words
typedef struct DictNode {
    char word[MAX_WORD_LENGTH];
    struct DictNode *next;
} DictNode;

// Function to create a new dictionary node
DictNode* createDictNode(const char *word) {
    DictNode *newNode = (DictNode *)malloc(sizeof(DictNode));
    strncpy(newNode->word, word, MAX_WORD_LENGTH);
    newNode->next = NULL;
    return newNode;
}

// Function to free the linked list
void freeDict(DictNode *head) {
    DictNode *current = head;
    DictNode *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Function to insert a word into the dictionary
void insertWord(DictNode **head, const char *word) {
    DictNode *newNode = createDictNode(word);
    newNode->next = *head;
    *head = newNode;
}

// Function to check if a word exists in the dictionary
int checkWord(DictNode *head, const char *word) {
    DictNode *current = head;
    while (current != NULL) {
        if (strcasecmp(current->word, word) == 0) {
            return 1; // Word found
        }
        current = current->next;
    }
    return 0; // Word not found
}

// Function to load dictionary words from a file
DictNode* loadDictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    DictNode *head = NULL;
    char word[MAX_WORD_LENGTH];

    while (fgets(word, sizeof(word), file)) {
        word[strcspn(word, "\n")] = 0; // Remove newline character
        insertWord(&head, word);
    }

    fclose(file);
    return head;
}

// Function to print suggested corrections (here it just prints similar length words)
void suggestCorrections(DictNode *head, const char *word) {
    printf("Did you mean:\n");
    DictNode *current = head;
    while (current != NULL) {
        if (abs((int)(strlen(current->word) - strlen(word))) <= 1) {
            printf(" - %s\n", current->word);
        }
        current = current->next;
    }
}

// The main spell checking function
void spellCheck(DictNode *dictionary, const char *input) {
    char *token = strtok(input, " ");
    while (token != NULL) {
        if (!checkWord(dictionary, token)) {
            printf("Misspelled word: %s\n", token);
            suggestCorrections(dictionary, token);
        }
        token = strtok(NULL, " ");
    }
}

// Main function
int main() {
    printf("Welcome to the Enchanted Spell Checker!\n");
    printf("Loading dictionary...\n");

    DictNode *dictionary = loadDictionary("dictionary.txt");

    char input[1000];
    printf("Enter text to check (type 'exit' to leave):\n");
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strcasecmp(input, "exit") == 0) {
            break; // Exit the program
        }

        spellCheck(dictionary, input);
    }

    freeDict(dictionary);
    printf("Thank you for using the Enchanted Spell Checker!\n");
    return 0;
}