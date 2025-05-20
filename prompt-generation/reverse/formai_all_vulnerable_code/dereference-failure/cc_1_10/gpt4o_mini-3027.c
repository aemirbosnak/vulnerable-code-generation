//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 512
#define DICTIONARY_FILE "dictionary.txt"

typedef struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node *next;
} Node;

Node *dictionary = NULL;

void loadDictionary() {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_WORD_LENGTH];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
        Node *newNode = (Node *)malloc(sizeof(Node));
        strcpy(newNode->word, buffer);
        newNode->next = dictionary;
        dictionary = newNode;
    }
    fclose(file);
}

int isWordInDictionary(const char *word) {
    Node *current = dictionary;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1; // Word found
        }
        current = current->next;
    }
    return 0; // Word not found
}

void freeDictionary() {
    Node *current = dictionary;
    Node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

void checkSpellingInFile(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open input file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            // Clean token for punctuation
            char cleanedWord[MAX_WORD_LENGTH];
            int j = 0;
            for (int i = 0; token[i] != '\0'; i++) {
                if (isalpha(token[i])) {
                    cleanedWord[j++] = tolower(token[i]);
                }
            }
            cleanedWord[j] = '\0';

            if (strlen(cleanedWord) > 0 && !isWordInDictionary(cleanedWord)) {
                printf("Misspelled word: %s\n", cleanedWord);
            }
            token = strtok(NULL, " \t\n");
        }
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    loadDictionary();
    checkSpellingInFile(argv[1]);
    freeDictionary();

    return EXIT_SUCCESS;
}