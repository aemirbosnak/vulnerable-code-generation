//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define CAT_MAX_WORDS 10

typedef struct CAT_WORD {
    char *word;
    struct CAT_WORD *next;
} CAT_WORD;

CAT_WORD *cat_word_insert(CAT_WORD *head, char *word)
{
    CAT_WORD *new_word = malloc(sizeof(CAT_WORD));
    new_word->word = strdup(word);
    new_word->next = NULL;

    if (head == NULL) {
        head = new_word;
    } else {
        head->next = new_word;
    }

    return head;
}

int cat_word_find(CAT_WORD *head, char *word)
{
    CAT_WORD *current = head;

    while (current) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }

        current = current->next;
    }

    return 0;
}

int main()
{
    CAT_WORD *head = NULL;

    head = cat_word_insert(head, "Meow");
    head = cat_word_insert(head, "Purr");
    head = cat_word_insert(head, "Meow");

    if (cat_word_find(head, "Meow") == 1) {
        printf("Meow is in the list.\n");
    }

    return 0;
}