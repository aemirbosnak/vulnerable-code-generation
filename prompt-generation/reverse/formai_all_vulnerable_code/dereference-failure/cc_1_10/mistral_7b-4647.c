//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 100
#define WORD_LENGTH 40

typedef struct Word {
    char *word;
    int length;
} Word;

void generateWords(Word words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i].length = rand() % 10 + WORD_LENGTH;
        words[i].word = malloc(words[i].length + 1);
        for (int j = 0; j < words[i].length; j++) {
            words[i].word[j] = 'A' + (rand() % 26);
        }
        words[i].word[words[i].length] = '\0';
    }
}

void printWords(Word words[]) {
    printf("\n*** SHOCKED TYPING SPEED TEST ***\n\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        printf("%d. %s\n", i + 1, words[i].word);
    }
    printf("\nReady? Set? GO!\n\n");
}

int main() {
    srand(time(NULL));

    Word words[MAX_WORDS];
    generateWords(words);

    clock_t start, end;
    int total_typed = 0;
    int correct_typed = 0;
    int user_input;

    start = clock();

    for (int i = 0; i < MAX_WORDS; i++) {
        scanf("%s", &words[i].word);

        if (strcmp(words[i].word, words[i].word) == 0) {
            correct_typed++;
            total_typed += strlen(words[i].word);
        }
    }

    end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    double wpm = (double)total_typed / time_taken * 60;

    printf("\nYou typed %d characters correctly in %f seconds.\n", correct_typed, time_taken);
    printf("Your typing speed is %f words per minute.\n", wpm);

    for (int i = 0; i < MAX_WORDS; i++) {
        free(words[i].word);
    }

    return 0;
}