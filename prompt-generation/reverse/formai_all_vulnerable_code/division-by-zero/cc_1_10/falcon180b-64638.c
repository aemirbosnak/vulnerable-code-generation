//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50
#define MAX_TIME 60
#define WPM_FACTOR 5

struct word {
    char word[MAX_WORD_LEN];
    int len;
};

void load_words(struct word *words, int num_words) {
    FILE *fp;
    char line[MAX_WORD_LEN];

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    for (int i = 0; i < num_words; i++) {
        if (fgets(line, MAX_WORD_LEN, fp) == NULL) {
            printf("Error: not enough words in words.txt\n");
            exit(1);
        }

        words[i].len = strlen(line);
        strcpy(words[i].word, line);
    }

    fclose(fp);
}

void display_word(struct word word) {
    for (int i = 0; i < word.len; i++) {
        printf("%c", word.word[i]);
    }
}

void start_timer(int *start_time) {
    *start_time = time(NULL);
}

int stop_timer(int start_time) {
    time_t end_time = time(NULL);
    return end_time - start_time;
}

int main() {
    struct word words[MAX_WORDS];
    int num_words, start_time, end_time, elapsed_time, wpm;

    printf("Enter number of words to type (1-%d): ", MAX_WORDS);
    scanf("%d", &num_words);

    load_words(words, num_words);

    start_timer(&start_time);

    for (int i = 0; i < num_words; i++) {
        printf("Word %d: ", i + 1);
        display_word(words[i]);
        printf("\n");
    }

    end_time = stop_timer(start_time);
    elapsed_time = end_time / WPM_FACTOR;
    wpm = (int) (MAX_WORD_LEN * num_words / (elapsed_time * 60));

    printf("\nWords per minute: %d\n", wpm);

    return 0;
}