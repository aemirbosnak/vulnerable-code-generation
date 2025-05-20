//Falcon-180B DATASET v1.0 Category: Data mining ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

int compare_frequency(const void *a, const void *b) {
    WordFrequency *x = (WordFrequency *)a;
    WordFrequency *y = (WordFrequency *)b;
    return x->frequency - y->frequency;
}

int main() {
    FILE *file;
    char line[MAX_SIZE];
    char *word;
    int word_count = 0;
    int line_count = 0;
    int max_word_length = 0;
    WordFrequency *word_frequencies = (WordFrequency *)malloc(sizeof(WordFrequency) * 1000);
    memset(word_frequencies, 0, sizeof(WordFrequency) * 1000);

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_SIZE, file)!= NULL) {
        line_count++;
        word = strtok(line, " ");
        while (word!= NULL) {
            int word_length = strlen(word);
            if (word_length > max_word_length) {
                max_word_length = word_length;
            }
            word_count++;
            word_frequencies[word_count - 1].word = word;
            word_frequencies[word_count - 1].frequency++;
            word = strtok(NULL, " ");
        }
    }

    fclose(file);

    qsort(word_frequencies, word_count, sizeof(WordFrequency), compare_frequency);

    printf("Total words: %d\n", word_count);
    printf("Longest word length: %d\n", max_word_length);
    printf("Top 10 most frequent words:\n");

    for (int i = 0; i < 10 && i < word_count; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
    }

    free(word_frequencies);

    return 0;
}