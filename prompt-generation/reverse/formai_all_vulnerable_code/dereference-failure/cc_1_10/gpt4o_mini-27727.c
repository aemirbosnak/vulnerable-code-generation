//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_CORRECTIONS 5

typedef struct WordNode {
    char word[MAX_WORD_LENGTH];
    struct WordNode *next;
} WordNode;

typedef struct Dictionary {
    WordNode *head;
    int count;
} Dictionary;

Dictionary *createDictionary() {
    Dictionary *dict = (Dictionary *)malloc(sizeof(Dictionary));
    if (dict == NULL) {
        fprintf(stderr, "Memory allocation failed for dictionary.\n");
        exit(EXIT_FAILURE);
    }
    dict->head = NULL;
    dict->count = 0;
    return dict;
}

void freeDictionary(Dictionary *dict) {
    WordNode *current = dict->head;
    WordNode *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(dict);
}

int addWord(Dictionary *dict, const char *word) {
    WordNode *newNode = (WordNode *)malloc(sizeof(WordNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed for new word.\n");
        return 0;
    }
    strncpy(newNode->word, word, MAX_WORD_LENGTH);
    newNode->next = dict->head;
    dict->head = newNode;
    dict->count++;
    return 1;
}

int isWordInDictionary(Dictionary *dict, const char *word) {
    WordNode *current = dict->head;
    while (current != NULL) {
        if (strcasecmp(current->word, word) == 0) {
            return 1; // Found in dictionary
        }
        current = current->next;
    }
    return 0;
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void suggestCorrections(Dictionary *dict, const char *word) {
    printf("Suggestions for '%s':\n", word);
    int suggestions = 0;

    for (WordNode *current = dict->head; current != NULL; current = current->next) {
        if (suggestions >= MAX_CORRECTIONS) {
            break;
        }
        if (strncmp(current->word, word, strlen(word) - 1) == 0) {
            printf(" - %s\n", current->word);
            suggestions++;
        }
    }
    if (suggestions == 0) {
        printf("No suggestions available.\n");
    }
}

void spellCheck(Dictionary *dict, const char *text) {
    char word[MAX_WORD_LENGTH];
    const char *ptr = text;
    int index = 0;

    while (*ptr) {
        if (isalnum(*ptr)) {
            word[index++] = *ptr;
        } else {
            if (index > 0) {
                word[index] = '\0';
                if (!isWordInDictionary(dict, word)) {
                    printf("Misspelled word: '%s'\n", word);
                    suggestCorrections(dict, word);
                }
                index = 0;
            }
        }
        ptr++;
    }

    if (index > 0) {
        word[index] = '\0';
        if (!isWordInDictionary(dict, word)) {
            printf("Misspelled word: '%s'\n", word);
            suggestCorrections(dict, word);
        }
    }
}

void loadDictionary(Dictionary *dict, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening dictionary file '%s'.\n", filename);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fgets(word, sizeof(word), file)) {
        word[strcspn(word, "\n")] = 0;  // Remove newline character
        addWord(dict, word);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Dictionary *dict = createDictionary();
    loadDictionary(dict, argv[1]);

    FILE *textFile = fopen(argv[2], "r");
    if (!textFile) {
        fprintf(stderr, "Error opening text file '%s'.\n", argv[2]);
        freeDictionary(dict);
        return EXIT_FAILURE;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), textFile)) {
        spellCheck(dict, buffer);
    }

    fclose(textFile);
    freeDictionary(dict);
    return EXIT_SUCCESS;
}