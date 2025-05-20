//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: protected
#define WIZARD_OF_WORDZ

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

struct Word {
    char *text;
    size_t length;
};

struct Node {
    struct Word word;
    struct Node *next;
};

struct List {
    struct Node *head;
};

void addWord(struct List *list, char *word) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->word.text = word;
    newNode->word.length = strlen(word);
    newNode->next = list->head;
    list->head = newNode;
}

void printList(struct List *list) {
    struct Node *current = list->head;

    while (current != NULL) {
        printf("%s (%zu)\n", current->word.text, current->word.length);
        current = current->next;
    }
}

int main() {
    struct List list;

    addWord(&list, "wizard");
    addWord(&list, "of");
    addWord(&list, "wordz");

    printList(&list);

    return 0;
}