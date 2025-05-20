//Falcon-180B DATASET v1.0 Category: Data mining ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    struct word_count *wc1 = (struct word_count *)a;
    struct word_count *wc2 = (struct word_count *)b;

    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *input_file;
    char line[MAX_WORD_LENGTH];
    char *word;
    int num_words = 0;
    struct word_count *word_counts = malloc(MAX_WORDS * sizeof(struct word_count));

    input_file = fopen("input.txt", "r");

    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        word = strtok(line, " ");

        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: maximum number of words exceeded.\n");
                exit(1);
            }

            strcpy(word_counts[num_words].word, word);
            word_counts[num_words].count = 1;

            num_words++;

            word = strtok(NULL, " ");
        }
    }

    qsort(word_counts, num_words, sizeof(struct word_count), compare_words);

    printf("Word\tCount\n");

    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);

    return 0;
}