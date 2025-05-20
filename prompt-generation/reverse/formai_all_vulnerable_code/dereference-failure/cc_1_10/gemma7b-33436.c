//Gemma-7B DATASET v1.0 Category: Data mining ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 100

typedef struct Word {
    char *word;
    int frequency;
    struct Word *next;
} Word;

Word *createWord(char *word, int frequency) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->frequency = frequency;
    newWord->next = NULL;
    return newWord;
}

void addWord(Word *head, char *word, int frequency) {
    Word *newWord = createWord(word, frequency);
    if (head == NULL) {
        head = newWord;
    } else {
        Word *currentWord = head;
        while (currentWord->next) {
            currentWord = currentWord->next;
        }
        currentWord->next = newWord;
    }
}

void printWords(Word *head) {
    Word *currentWord = head;
    while (currentWord) {
        printf("%s: %d\n", currentWord->word, currentWord->frequency);
        currentWord = currentWord->next;
    }
}

int main() {
    Word *head = NULL;
    addWord(head, "Surrealism", 5);
    addWord(head, "C", 3);
    addWord(head, "Data", 2);
    addWord(head, "Mining", 4);
    addWord(head, "Code", 2);
    addWord(head, "Surprises", 3);
    addWord(head, "No", 1);
    addWord(head, "Explanation", 2);
    printWords(head);

    return 0;
}