//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: all-encompassing
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100
#define WORDS_PER_LINE 20

typedef struct Word {
    char word[20];
    struct Word* next;
} Word;

Word* CreateWordList() {
    Word* head = NULL;
    head = malloc(sizeof(Word));
    head->next = NULL;
    return head;
}

void AddWordToWordList(Word* head, char* word) {
    Word* newWord = malloc(sizeof(Word));
    strcpy(newWord->word, word);
    newWord->next = NULL;

    if (head == NULL) {
        head = newWord;
    } else {
        head->next = newWord;
    }
}

int main() {
    Word* head = CreateWordList();
    AddWordToWordList(head, "apple");
    AddWordToWordList(head, "banana");
    AddWordToWordList(head, "cherry");
    AddWordToWordList(head, "orange");

    time_t start, end;
    start = clock();

    for (int i = 0; i < MAX_WORDS; i++) {
        for (int j = 0; j < WORDS_PER_LINE; j++) {
            printf("%s ", head->word);
            head = head->next;
        }
        printf("\n");
    }

    end = clock();
    int timeTaken = (int)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken: %d seconds\n", timeTaken);

    return 0;
}