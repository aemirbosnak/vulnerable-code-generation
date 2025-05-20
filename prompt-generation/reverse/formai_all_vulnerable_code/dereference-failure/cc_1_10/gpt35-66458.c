//FormAI DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50 // Maximum length of a word

/**
 * Linked List node to store a word and its frequency
 */
typedef struct WordNode {
    char *word;
    int frequency;
    struct WordNode *next;
} WordNode;

/**
 * Utility function to normalize a word by converting uppercase to lowercase
 */
void normalizeWord(char *word) {
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        word[i] = tolower(word[i]);
    }
}

/**
 * Utility function to add a word to the linked list
 */
WordNode* addWordToList(WordNode *head, char *word) {
    WordNode *node = (WordNode*) malloc(sizeof(WordNode));
    node->word = (char*) malloc(strlen(word) + 1);
    strcpy(node->word, word);
    node->frequency = 1;
    node->next = head;
    return node;
}

/**
 * Utility function to get the frequency of a word in the linked list
 */
int getWordFrequency(WordNode *head, char *word) {
    for (WordNode *current = head; current != NULL; current = current->next) {
        if (strcmp(current->word, word) == 0) {
            return current->frequency;
        }
    }
    return 0;
}

/**
 * Utility function to iterate over all words in a line and add them to the linked list
 */
WordNode* addWordsInLine(WordNode *head, char *line) {
    char *word = strtok(line, " ");
    while (word != NULL) {
        normalizeWord(word);
        int frequency = getWordFrequency(head, word);
        if (frequency == 0) {
            head = addWordToList(head, word);
        } else {
            for (WordNode *current = head; current != NULL; current = current->next) {
                if (strcmp(current->word, word) == 0) {
                    current->frequency++;
                    break;
                }
            }
        }
        word = strtok(NULL, " ");
    }
    return head;
}

/**
 * Function to check a file for spelling mistakes and output the results to another file
 */
void spellCheckFile(char *inputFileName, char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("Error: could not open file.\n");
        return;
    }

    WordNode *wordList = NULL;
    char line[MAX_WORD_LENGTH * 10];
    while (fgets(line, MAX_WORD_LENGTH * 10, inputFile) != NULL) {
        wordList = addWordsInLine(wordList, line);
    }

    fprintf(outputFile, "Mistakes found in file: %s\n\n", inputFileName);
    int errorsFound = 0;
    for (WordNode *current = wordList; current != NULL; current = current->next) {
        if (current->frequency == 1) {
            fprintf(outputFile, "- %s\n", current->word);
            errorsFound++;
        }
    }

    if (errorsFound == 0) {
        fprintf(outputFile, "No spelling mistakes found.\n");
    }
    printf("Spell check completed.\n");

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    char inputFileName[] = "input.txt";
    char outputFileName[] = "output.txt";

    spellCheckFile(inputFileName, outputFileName);

    return 0;
}