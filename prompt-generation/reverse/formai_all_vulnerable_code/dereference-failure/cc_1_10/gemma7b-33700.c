//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct alien_word {
    char word[20];
    struct alien_word* next;
} alien_word;

 alien_word* insert_word(alien_word* head, char* word)
{
    alien_word* new_word = malloc(sizeof(alien_word));
    strcpy(new_word->word, word);
    new_word->next = NULL;

    if (head == NULL) {
        head = new_word;
    } else {
        head->next = new_word;
    }

    return head;
}

 alien_word* search_word(alien_word* head, char* word)
{
    while (head) {
        if (strcmp(head->word, word) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

int main()
{
    alien_word* head = NULL;
    head = insert_word(head, "K'nor");
    head = insert_word(head, "Zork");
    head = insert_word(head, "Thrak");

    alien_word* found_word = search_word(head, "Zork");

    if (found_word) {
        printf("%s\n", found_word->word);
    } else {
        printf("Word not found\n");
    }

    return 0;
}