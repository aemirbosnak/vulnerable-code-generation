//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct WordNode {
    char *word;
    int count;
    struct WordNode *next;
} WordNode;

typedef struct WordList {
    WordNode *head;
    WordNode *tail;
    int size;
} WordList;

WordList *createWordList() {
    WordList *list = malloc(sizeof(WordList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void destroyWordList(WordList *list) {
    WordNode *node = list->head;
    while (node != NULL) {
        WordNode *next = node->next;
        free(node->word);
        free(node);
        node = next;
    }
    free(list);
}

void addWordToList(WordList *list, char *word) {
    WordNode *node = malloc(sizeof(WordNode));
    node->word = strdup(word);
    node->count = 1;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

int getWordCount(WordList *list, char *word) {
    WordNode *node = list->head;
    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            return node->count;
        }
        node = node->next;
    }
    return 0;
}

void printWordList(WordList *list) {
    WordNode *node = list->head;
    while (node != NULL) {
        printf("%s: %d\n", node->word, node->count);
        node = node->next;
    }
}

int main() {
    WordList *list = createWordList();
    char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";
    char *words = strtok(text, " .");
    while (words != NULL) {
        addWordToList(list, words);
        words = strtok(NULL, " .");
    }
    printWordList(list);
    destroyWordList(list);
    return 0;
}