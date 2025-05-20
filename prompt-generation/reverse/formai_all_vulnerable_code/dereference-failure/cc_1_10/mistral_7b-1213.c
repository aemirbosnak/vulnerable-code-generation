//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define WORD_LENGTH 30
#define BUFFER_SIZE 1024

typedef struct Word {
    char* word;
    int length;
} Word;

Word* createWords(int count) {
    Word* words = malloc(count * sizeof(Word));

    for (int i = 0; i < count; ++i) {
        words[i].length = rand() % (WORD_LENGTH / 2) + WORD_LENGTH / 2;
        words[i].word = malloc(words[i].length + 1);
        for (int j = 0; j < words[i].length; ++j) {
            words[i].word[j] = 'a' + rand() % 26;
        }
        words[i].word[words[i].length] = '\0';
    }

    return words;
}

void printWords(Word* words, int count) {
    for (int i = 0; i < count; ++i) {
        printf("%s ", words[i].word);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    srand(time(NULL));

    Word* words = createWords(MAX_WORDS);

    clock_t start = clock();
    char buffer[BUFFER_SIZE];

    printf("Type the following words as fast as you can:\n");
    printWords(words, MAX_WORDS);

    for (int i = 0; i < MAX_WORDS; ++i) {
        fgets(buffer, BUFFER_SIZE, stdin);
        for (int j = 0; j < words[i].length; ++j) {
            if (buffer[j] != words[i].word[j]) {
                printf("Incorrect: %s %s\n", words[i].word, buffer);
                break;
            }
            if (j == words[i].length - 1) {
                printf("Correct! ");
            }
        }
    }

    clock_t end = clock();
    double time_spent = (end - start) * 1000.0 / CLOCKS_PER_SEC;

    printf("Time spent: %f ms\n", time_spent);

    for (int i = 0; i < MAX_WORDS; ++i) {
        free(words[i].word);
    }
    free(words);

    return 0;
}