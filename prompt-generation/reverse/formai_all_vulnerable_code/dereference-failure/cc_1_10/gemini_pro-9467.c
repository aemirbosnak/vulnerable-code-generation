//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _WordNode {
    char* word;
    int count;
    struct _WordNode* next;
} WordNode;

WordNode* createWordNode(char* word) {
    WordNode* node = (WordNode*)malloc(sizeof(WordNode));
    node->word = strdup(word);
    node->count = 1;
    node->next = NULL;
    return node;
}

void insertWord(WordNode** head, char* word) {
    WordNode* prev = NULL;
    WordNode* curr = *head;

    while (curr != NULL && strcmp(curr->word, word) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        if (prev == NULL) {
            *head = createWordNode(word);
        } else {
            prev->next = createWordNode(word);
        }
    } else {
        curr->count++;
    }
}

void printWordList(WordNode* head) {
    while (head != NULL) {
        printf("%s: %d\n", head->word, head->count);
        head = head->next;
    }
}

void freeWordList(WordNode* head) {
    while (head != NULL) {
        WordNode* next = head->next;
        free(head->word);
        free(head);
        head = next;
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    WordNode* head = NULL;

    char word[1024];
    while (fscanf(file, "%s", word) != EOF) {
        insertWord(&head, word);
    }

    fclose(file);

    printWordList(head);

    freeWordList(head);

    return 0;
}