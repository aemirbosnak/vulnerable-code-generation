//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define DICT_SIZE 1000
#define MAX_LINE_LENGTH 256

// Structure to hold the dictionary
typedef struct {
    char *words[DICT_SIZE];
    int size;
} Dictionary;

// Function prototypes
void loadDictionary(Dictionary *dict, const char *filePath);
void checkSpelling(Dictionary *dict, const char *text);
int isInDictionary(Dictionary *dict, const char *word);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Dictionary dict = {.size = 0};
    loadDictionary(&dict, argv[1]);
    
    FILE *textFile = fopen(argv[2], "r");
    if (textFile == NULL) {
        perror("Error opening text file");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), textFile)) {
        checkSpelling(&dict, line);
    }

    fclose(textFile);
    // Free the allocated dictionary memories
    for (int i = 0; i < dict.size; i++) {
        free(dict.words[i]);
    }
    return EXIT_SUCCESS;
}

void loadDictionary(Dictionary *dict, const char *filePath) {
    FILE *dictFile = fopen(filePath, "r");
    if (dictFile == NULL) {
        perror("Error opening dictionary file");
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fgets(word, sizeof(word), dictFile) && dict->size < DICT_SIZE) {
        word[strcspn(word, "\n")] = 0; // Remove the newline character
        dict->words[dict->size] = malloc(strlen(word) + 1);
        strcpy(dict->words[dict->size], word);
        dict->size++;
    }
    fclose(dictFile);
}

void checkSpelling(Dictionary *dict, const char *text) {
    char *token;
    char textCopy[MAX_LINE_LENGTH];
    strcpy(textCopy, text);
    
    token = strtok(textCopy, " \n");
    while (token != NULL) {
        if (!isInDictionary(dict, token)) {
            printf("Misspelled: %s\n", token);
        }
        token = strtok(NULL, " \n");
    }
}

int isInDictionary(Dictionary *dict, const char *word) {
    for (int i = 0; i < dict->size; i++) {
        if (strcasecmp(dict->words[i], word) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}