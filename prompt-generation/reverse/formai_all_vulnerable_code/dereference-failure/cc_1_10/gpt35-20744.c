//FormAI DATASET v1.0 Category: Spell checking ; Style: interoperable
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50 //Maximum length of words we can handle

typedef struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node *next;
} Node;

typedef struct {
    Node *first;
    Node *last;
} LinkedList;

void addWordsToLinkedList(char *filePath, LinkedList *list) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Error: Unable to open %s\n", filePath);
        exit(1);
    }
    char currentWord[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", currentWord) != EOF) {
        Node *newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Error: Not enough memory to allocate new node.\n");
            exit(1);
        }
        strcpy(newNode->word, currentWord);
        newNode->next = NULL;
        if (list->first == NULL) {
            list->first = newNode;
            list->last = newNode;
        } else {
            list->last->next = newNode;
            list->last = newNode;
        }
    }
    fclose(file);
}

void lowercase(char *s) {
    for (; *s; ++s) *s = tolower(*s);
}

int checkSpelling(char *word, LinkedList *dictionary) {
    lowercase(word);
    for (Node *current = dictionary->first; current != NULL; current = current->next) {
        if (strcmp(current->word, word) == 0) {
            return 1; //Spelling is correct
        }
    }
    return 0; //Spelling is incorrect
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <dictionary file> <document file>\n", argv[0]);
        return 1;
    }
    LinkedList dictionary = {NULL, NULL};
    addWordsToLinkedList(argv[1], &dictionary);
    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Error: Unable to open %s\n", argv[2]);
        return 1;
    }
    char currentWord[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", currentWord) != EOF) {
        if (!checkSpelling(currentWord, &dictionary)) {
            printf("Misspelled word: %s\n", currentWord);
        }
    }
    fclose(file);
    return 0;
}