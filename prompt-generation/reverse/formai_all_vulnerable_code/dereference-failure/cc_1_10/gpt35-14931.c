//FormAI DATASET v1.0 Category: Spell checking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_FILE "dictionary.txt"

// Define a Linked List Node struct for the dictionary
typedef struct dict_node {
    char word[MAX_WORD_LENGTH];
    struct dict_node *next;
} DictNode;

// Function to insert a new dictionary entry
void insertEntry(DictNode **headRef, char *word) {
    DictNode *newNode = (DictNode*) malloc(sizeof(DictNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    snprintf(newNode->word, MAX_WORD_LENGTH, "%s", word);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to load the dictionary file into a Linked List
void loadDictionary(DictNode **dictHead) {
    FILE *fp = fopen(DICTIONARY_FILE, "r");
    if (!fp) {
        printf("Error loading dictionary file!\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fgets(word, MAX_WORD_LENGTH, fp)) {
        // Remove newline character
        int len = strlen(word);
        if (len > 0 && word[len-1] == '\n') {
            word[len-1] = '\0';
        }
        insertEntry(dictHead, word);
    }

    fclose(fp);
}

// Function to free up the dictionary Linked List after use
void freeDictionary(DictNode *dictHead) {
    DictNode *curr = dictHead;
    while (curr) {
        DictNode *temp = curr;
        curr = curr->next;
        free(temp);
    }
}

// Function to check if a given word exists in the dictionary
bool isValidWord(DictNode *dictHead, const char *word) {
    DictNode *curr = dictHead;
    while (curr) {
        if (strcasecmp(curr->word, word) == 0) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// Function to print a given word with ASCII art highlighting the incorrect letter
void printWordWithHighlight(const char *word, int errorIdx) {
    printf("      ");
    for (int i = 0; i < strlen(word); i++) {
        if (i == errorIdx) {
            printf("  ^^^  ");
        } else {
            printf("       ");
        }
    }
    printf("\n");

    printf("      ");
    for (int i = 0; i < strlen(word); i++) {
        printf("|     |");
    }
    printf("\n");

    printf("      ");
    for (int i = 0; i < strlen(word); i++) {
        printf("|  %c  |", toupper(word[i]));
    }
    printf("\n");

    printf("      ");
    for (int i = 0; i < strlen(word); i++) {
        printf("|_____|");
    }
    printf("\n");
}

int main() {
    DictNode *dictHead = NULL;
    loadDictionary(&dictHead);

    char input[MAX_WORD_LENGTH];
    printf("Welcome to the Cyberpunk Spell Check!\n");
    printf("Type in your word and I will check if it is spelled correctly.\n");

    while (true) {
        printf("\n> ");
        fgets(input, MAX_WORD_LENGTH, stdin);

        // Remove newline character
        int len = strlen(input);
        if (len > 0 && input[len-1] == '\n') {
            input[len-1] = '\0';
        }

        if (isValidWord(dictHead, input)) {
            printf("Correct! \"%s\" is a valid word.\n", input);
        } else {
            printf("Incorrect! \"%s\" is not a valid word.\n", input);

            // Find the first incorrect letter
            int errorIdx = -1;
            for (int i = 0; i < strlen(input); i++) {
                if (!isalpha(input[i]) || (isupper(input[i]) && i != 0)) {
                    // Non-alpha or capitalized mid-word letter is not allowed
                    errorIdx = i;
                    break;
                }
                if (i == 0 && !isupper(input[i])) {
                    // First letter must be capitalized
                    errorIdx = i;
                    break;
                }
            }

            if (errorIdx != -1) {
                printWordWithHighlight(input, errorIdx);
            }
        }
    }

    freeDictionary(dictHead);
    return 0;
}