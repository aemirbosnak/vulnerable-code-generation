//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->next = NULL;

    if (head == NULL) {
        head = newWord;
    } else {
        head->next = newWord;
    }

    return head;
}

int translateCat(Word *head, char *query) {
    char *words[MAX_WORDS];
    int i = 0;

    while (head) {
        words[i++] = head->word;
        head = head->next;
    }

    for (i = 0; words[i] && strcmp(words[i], query) != 0; i++) {}

    if (words[i]) {
        printf("%s", words[i]);
    } else {
        printf("No match found");
    }

    return 0;
}

int main() {
    Word *head = NULL;

    insertWord(head, "Watson");
    insertWord(head, "Holmes");
    insertWord(head, "The");
    insertWord(head, "Great");
    insertWord(head, "Detective");

    translateCat(head, "The Great Detective");

    return 0;
}