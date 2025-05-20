//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct Word {
    char word[MAX_WORDS];
    struct Word* next;
} Word;

Word* insertWord(Word* head, char* word) {
    Word* newNode = malloc(sizeof(Word));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int detectSpam(Word* head) {
    char* redFlags[] = {"free", "lottery", "miracle", "prize", "offer"};
    int redFlagsIndex = 0;

    for (Word* current = head; current; current = current->next) {
        for (int i = 0; i < redFlagsIndex; i++) {
            if (strcmp(current->word, redFlags[i]) == 0) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    Word* head = insertWord(NULL, "Hello, world!");
    insertWord(head, "Free prize!");
    insertWord(head, "Miracle offer!");

    if (detectSpam(head) == 1) {
        printf("Spam detected!");
    } else {
        printf("No spam detected.");
    }

    return 0;
}