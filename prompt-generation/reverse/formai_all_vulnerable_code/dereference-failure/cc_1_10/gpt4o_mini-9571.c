//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define DICT_SIZE 1000
#define LINE_SIZE 256

typedef struct WordNode {
    char word[MAX_WORD_LEN];
    struct WordNode *next;
} WordNode;

WordNode *dictionary = NULL;
int dictWordCount = 0;

// Function to create a new word node
WordNode* createNode(const char* word) {
    WordNode* newNode = (WordNode*) malloc(sizeof(WordNode));
    strncpy(newNode->word, word, MAX_WORD_LEN);
    newNode->next = NULL;
    return newNode;
}

// Function to add a word to the dictionary
void addWord(const char* word) {
    WordNode* newNode = createNode(word);
    newNode->next = dictionary;
    dictionary = newNode;
    dictWordCount++;
}

// Function to check if a word is in the dictionary
int isWordInDictionary(const char* word) {
    WordNode* current = dictionary;
    while (current != NULL) {
        if (strcasecmp(current->word, word) == 0) {
            return 1; // Word found
        }
        current = current->next;
    }
    return 0; // Word not found
}

// Function to suggest corrections for a misspelled word
void suggestCorrections(const char* word) {
    printf("Did you mean? ");
    for (int i = 0; i < dictWordCount; i++) {
        if (abs((int)strlen(word) - (int)strlen(dictionary->word)) < 2) {
            printf("%s ", dictionary->word);
        }
        dictionary = dictionary->next;
    }
    printf("\n");
}

// Function to read the dictionary from a file
void loadDictionary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word) != EOF) {
        addWord(word);
    }
    
    fclose(file);
}

// Function for surreal spell checking
void surrealSpellCheck(const char* text) {
    char line[LINE_SIZE];
    FILE* input = fopen(text, "r");
    if (!input) {
        perror("Could not open input file for spell checking");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, LINE_SIZE, input)) {
        char *token = strtok(line, " ,.;!?()[]{}\"\n");
        while (token != NULL) {
            // Check each word in the line
            if (!isWordInDictionary(token)) {
                printf("Unicorn hooves! The word '%s' is a chameleon in the garden of language!\n", token);
                suggestCorrections(token);
            }
            token = strtok(NULL, " ,.;!?()[]{}\"\n");
        }
    }
    
    fclose(input);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* dictionaryFile = argv[1];
    char* textFile = argv[2];

    loadDictionary(dictionaryFile);
    surrealSpellCheck(textFile);

    // Cleanup the dictionary
    while (dictionary) {
        WordNode* temp = dictionary;
        dictionary = dictionary->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}