//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

typedef struct WordNode {
    char word[BUFFER_SIZE];
    int count;
    struct WordNode *next;
} WordNode;

WordNode *head = NULL;

WordNode* createNode(const char *word) {
    WordNode *newNode = (WordNode *)malloc(sizeof(WordNode));
    if(newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->word, word, BUFFER_SIZE);
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

void insertWord(const char *word) {
    WordNode *current = head;
    WordNode *prev = NULL;

    while (current != NULL && strcmp(current->word, word) < 0) {
        prev = current;
        current = current->next;
    }
    
    if (current != NULL && strcmp(current->word, word) == 0) {
        current->count++;
        return;
    } 
    
    WordNode *newNode = createNode(word);
    if (prev == NULL) {
        newNode->next = head;
        head = newNode;
    } else {
        newNode->next = current;
        prev->next = newNode;
    }
}

void printWordCounts() {
    WordNode *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

void freeMemory() {
    WordNode *current = head;
    while (current != NULL) {
        WordNode *temp = current;
        current = current->next;
        free(temp);
    }
}

void processInput(FILE *file) {
    char buffer[BUFFER_SIZE];
    while (fscanf(file, "%1023s", buffer) == 1) {
        insertWord(buffer);
    }
}

void countWordsInFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    processInput(file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    countWordsInFile(argv[1]);
    printf("Word Count Results:\n");
    printWordCounts();
    freeMemory();
    
    return EXIT_SUCCESS;
}