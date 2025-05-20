//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORD_COUNT 10
#define LINE_LENGTH 120
#define FONT_SIZE 3

typedef struct Word {
    char *text;
    int len;
} Word;

Word *words;
int total_len;

void init_words() {
    int i;
    words = (Word *)calloc(WORD_COUNT, sizeof(Word));
    for (i = 0; i < WORD_COUNT; i++) {
        words[i].len = rand() % 30 + 20;
        words[i].text = (char *)calloc(words[i].len, sizeof(char));
        int j;
        for (j = 0; j < words[i].len; j++) {
            words[i].text[j] = 'a' + (rand() % 26);
        }
        total_len += words[i].len;
    }
}

void print_words(int *times) {
    int i, j;
    for (i = 0; i < WORD_COUNT; i++) {
        printf("\033[1;%dH", FONT_SIZE * (i / 10) + (i % 10) + 1);
        printf("%s", words[i].text);
        clock_t start = clock();
        for (j = 0; j < words[i].len; j++) {
            putchar(words[i].text[j]);
            fflush(stdout);
        }
        clock_t end = clock();
        times[i] = (int)((end - start) * 1000 / CLOCKS_PER_SEC);
    }
    printf("\n\n");
}

int main() {
    int *times, i;
    srand(time(NULL));
    init_words();
    times = (int *)calloc(WORD_COUNT, sizeof(int));
    clock_t start = clock();
    print_words(times);
    clock_t end = clock();

    double wpm = (double)total_len * 60.0 / ((end - start) * 1000.0 / CLOCKS_PER_SEC);
    printf("Typing speed: %.2f words per minute\n", wpm);

    free(words);
    for (i = 0; i < WORD_COUNT; i++) {
        free(words[i].text);
    }
    free(times);

    return 0;
}