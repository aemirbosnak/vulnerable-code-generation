//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *word;
    int count;
} WordCount;

int compare_counts(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    if (wc1->count > wc2->count) {
        return -1;
    } else if (wc1->count < wc2->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordCount words[1000];
    int num_words = 0;
    int i;

    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char *token = strtok(line, " ");

        while (token!= NULL) {
            if (num_words >= 1000) {
                printf("Error: Exceeded maximum number of words.\n");
                exit(1);
            }

            strcpy(words[num_words].word, token);
            words[num_words].count = 1;
            num_words++;

            token = strtok(NULL, " ");
        }
    }

    fclose(input_file);

    qsort(words, num_words, sizeof(WordCount), compare_counts);

    printf("Word Counts:\n");

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}