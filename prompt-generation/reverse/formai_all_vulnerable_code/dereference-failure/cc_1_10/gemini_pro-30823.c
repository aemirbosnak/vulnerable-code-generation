//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char *word;
    int len;
} Word;

Word words[] = {
    { "aardvark", 8 },
    { "abacus", 5 },
    { "abbey", 5 },
    { "abbot", 5 },
    { "abdomen", 7 },
    { "abductor", 8 },
    { "ability", 6 },
    { "ablaze", 6 },
    { "able", 4 },
    { "ablution", 8 }
};

int num_words = sizeof(words) / sizeof(Word);

int test_speed(int num_words, int time_limit, int *total_chars, int *total_errors) {
    int i, j, c, t;
    char buffer[100];
    time_t start, end;

    printf("Type the following words as fast as you can:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i].word);
    }
    printf("\n\n");

    start = time(NULL);
    for (i = 0; i < num_words; i++) {
        printf("%s: ", words[i].word);
        scanf("%s", buffer);
        end = time(NULL);
        t = (int)(end - start);
        if (t > time_limit) {
            printf("Time limit exceeded!\n");
            return -1;
        }
        if (strcmp(buffer, words[i].word) != 0) {
            printf("Error: %s != %s\n", buffer, words[i].word);
            (*total_errors)++;
        } else {
            printf("Correct: %s\n", buffer);
        }
        (*total_chars) += words[i].len;
    }

    return 0;
}

int main(int argc, char **argv) {
    int num_words, time_limit, total_chars, total_errors;

    if (argc < 3) {
        printf("Usage: %s <num_words> <time_limit>\n", argv[0]);
        return 1;
    }

    num_words = atoi(argv[1]);
    time_limit = atoi(argv[2]);

    if (num_words < 1 || num_words > num_words) {
        printf("Error: invalid number of words\n");
        return 1;
    }

    if (time_limit < 1) {
        printf("Error: invalid time limit\n");
        return 1;
    }

    total_chars = 0;
    total_errors = 0;
    if (test_speed(num_words, time_limit, &total_chars, &total_errors) == 0) {
        printf("\nResults:\n");
        printf("Total characters: %d\n", total_chars);
        printf("Total errors: %d\n", total_errors);
        printf("Speed: %d characters per second\n", total_chars / time_limit);
    }

    return 0;
}