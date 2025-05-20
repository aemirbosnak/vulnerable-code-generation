//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 256

typedef struct WordNode {
    char* word;
    int count;
    struct WordNode* next;
} WordNode;

typedef struct WordList {
    WordNode* head;
    int size;
} WordList;

WordList* createWordList() {
    WordList* list = malloc(sizeof(WordList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void addWordToWordList(WordList* list, char* word) {
    WordNode* node = malloc(sizeof(WordNode));
    node->word = malloc(strlen(word) + 1);
    strcpy(node->word, word);
    node->count = 1;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        WordNode* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }

    list->size++;
}

void countWordsInFile(WordList* list, FILE* file) {
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", buffer) != EOF) {
        char* word = malloc(strlen(buffer) + 1);
        strcpy(word, buffer);

        addWordToWordList(list, word);
    }
}

void printWordCount(WordList* list) {
    WordNode* current = list->head;

    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

void freeWordList(WordList* list) {
    WordNode* current = list->head;

    while (current != NULL) {
        WordNode* next = current->next;
        free(current->word);
        free(current);
        current = next;
    }

    free(list);
}

int main() {
    FILE* file = fopen("text.txt", "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        return EXIT_FAILURE;
    }

    WordList* wordList = createWordList();

    countWordsInFile(wordList, file);
    printWordCount(wordList);

    freeWordList(wordList);
    fclose(file);

    return EXIT_SUCCESS;
}