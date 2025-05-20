//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

Word *createWordList() {
    Word *head = malloc(sizeof(Word));
    head->word = malloc(20);
    head->next = NULL;
    return head;
}

void addWordToList(Word *head, char *word) {
    Word *newNode = malloc(sizeof(Word));
    newNode->word = malloc(20);
    newNode->next = NULL;
    strcpy(newNode->word, word);
    if (head->next) {
        head->next->next = newNode;
    } else {
        head->next = newNode;
    }
}

void playMemoryGame(Word *head) {
    srand(time(NULL));
    int index = rand() % MAX_WORDS;
    char *guessWord = head->next->word;
    printf("Guess the word: ");
    char guessLetter = getchar();
    while (guessLetter != guessWord[0] && guessLetter != guessWord[1]) {
        printf("Incorrect guess. Please try again: ");
        guessLetter = getchar();
    }
    printf("Congratulations! You guessed the word: %s\n", guessWord);
}

int main() {
    Word *head = createWordList();
    addWordToList(head, "apple");
    addWordToList(head, "banana");
    addWordToList(head, "orange");
    addWordToList(head, "mango");
    addWordToList(head, "pineapple");
    addWordToList(head, "grapes");
    addWordToList(head, "strawberry");
    playMemoryGame(head);
    return 0;
}