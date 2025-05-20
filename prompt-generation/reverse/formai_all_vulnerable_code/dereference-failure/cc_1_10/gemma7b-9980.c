//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000

typedef struct CAT_WORD {
    char word[256];
    struct CAT_WORD* next;
} CAT_WORD;

CAT_WORD* InsertWord(CAT_WORD* head, char* word) {
    CAT_WORD* newWord = malloc(sizeof(CAT_WORD));
    strcpy(newWord->word, word);
    newWord->next = NULL;

    if (head == NULL) {
        head = newWord;
    } else {
        head->next = newWord;
    }

    return head;
}

void TranslateCat(CAT_WORD* head, char* source, char* target) {
    char* sourceWords = strtok(source, " ");
    char* targetWords = strtok(target, " ");

    while (sourceWords) {
        CAT_WORD* wordNode = head;

        while (wordNode) {
            if (strcmp(sourceWords, wordNode->word) == 0) {
                printf("%s ", targetWords);
            }
            wordNode = wordNode->next;
        }

        sourceWords = strtok(NULL, " ");
    }

    printf("\n");
}

int main() {
    CAT_WORD* head = NULL;
    InsertWord(head, "Meow");
    InsertWord(head, "Purr");
    InsertWord(head, "Meow");

    TranslateCat(head, "Meow Purr", "Woof Bark");

    return 0;
}