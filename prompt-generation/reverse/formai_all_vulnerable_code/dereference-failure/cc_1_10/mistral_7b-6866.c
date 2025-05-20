//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 10
#define WORD_LENGTH 30
#define NUM_ROUNDS 5

typedef struct Word {
    char* word;
    int length;
} Word;

void generateWords(Word* words) {
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i].length = rand() % WORD_LENGTH + 1;
        words[i].word = (char*) malloc(words[i].length + 1);
        for (int j = 0; j < words[i].length; j++)
            words[i].word[j] = 'a' + (rand() % 26);
        words[i].word[words[i].length] = '\0';
    }
}

void printWord(Word word) {
    for (int i = 0; i < word.length; i++)
        printf("%c", word.word[i]);
    printf(" ");
}

int main() {
    srand(time(NULL));
    Word words[MAX_WORDS];
    generateWords(words);

    printf("\n---------- WELCOME TO THE ULTRA-EXCITING C TYPING SPEED TEST ----------\n");
    printf("--------------------------------------------------------------------\n");
    printf("------------------- PUT ON YOUR TYPING SHOES AND GET READY --------------\n");
    printf("--------------------------------------------------------------------\n");

    clock_t start, end;
    double elapsed_time;
    int round_count = 1;

    for (int round = 0; round < NUM_ROUNDS; round++) {
        printf("\nROUND %d:\n", round_count++);

        for (int i = 0; i < MAX_WORDS; i++) {
            printf("\nType the following word: ");
            printWord(words[i]);
            fflush(stdout); // Flush the output buffer to ensure the word is displayed before starting the timer

            start = clock();
            scanf("%s", words[i].word);
            end = clock();

            elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Time taken: %.6f seconds\n", elapsed_time);
        }
        printf("\n--------------------------------------------------------------------\n");
    }

    printf("\n---------- CONGRATULATIONS! YOU HAVE FINISHED THE TEST ---------------\n");
    printf("--------------------------------------------------------------------\n");

    for (int i = 0; i < MAX_WORDS; i++)
        free(words[i].word);

    return 0;
}