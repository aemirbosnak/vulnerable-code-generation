//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WORD_COUNT_MAX 10000
#define WORD_COUNT_INC 100

int main() {
    int words_count = 0;
    char word[100];
    char sentence[500];
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    printf("Welcome to the C Word Count Tool!\n");
    printf("Please enter a sentence or a paragraph: ");
    fgets(sentence, 500, stdin);

    // Tokenize the sentence
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        words_count++;
        token = strtok(NULL, " ");
    }

    // Calculate the average word length
    int avg_word_len = 0;
    for (int i = 0; i < words_count; i++) {
        avg_word_len += strlen(word);
        word[0] = '\0';
    }
    avg_word_len /= words_count;

    // Print the results
    printf("Word count: %d\n", words_count);
    printf("Average word length: %d\n", avg_word_len);

    // Calculate the word frequency
    int freq[WORD_COUNT_MAX];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < words_count; i++) {
        freq[word[i] - 'a']++;
    }

    // Print the word frequency
    printf("Word frequency:\n");
    for (int i = 0; i < WORD_COUNT_MAX; i++) {
        printf("%c %d\n", i + 'a', freq[i]);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed_time =
        (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
    printf("Elapsed time: %f seconds\n", elapsed_time);

    return 0;
}