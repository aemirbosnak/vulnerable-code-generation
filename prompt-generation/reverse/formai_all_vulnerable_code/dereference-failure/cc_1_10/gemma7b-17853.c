//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100

typedef struct Word {
    char word[20];
    struct Word* next;
} Word;

Word* head = NULL;

void insertWord(char* word) {
    Word* newWord = malloc(sizeof(Word));
    strcpy(newWord->word, word);
    newWord->next = NULL;

    if (head == NULL) {
        head = newWord;
    } else {
        head->next = newWord;
        head = newWord;
    }
}

void printWords() {
    Word* currentWord = head;
    while (currentWord) {
        printf("%s ", currentWord->word);
        currentWord = currentWord->next;
    }
    printf("\n");
}

int main() {
    time_t start, end;
    char word[20];

    insertWord("Hello");
    insertWord("World");
    insertWord("!");

    printWords();

    start = time(NULL);
    printf("Type a word: ");
    scanf("%s", word);
    insertWord(word);

    end = time(NULL);

    printWords();

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}