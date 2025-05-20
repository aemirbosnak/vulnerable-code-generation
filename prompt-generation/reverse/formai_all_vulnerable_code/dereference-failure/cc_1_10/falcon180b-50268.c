//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void* a, const void* b) {
    const struct word_count* word_a = (const struct word_count*)a;
    const struct word_count* word_b = (const struct word_count*)b;

    return strcasecmp(word_a->word, word_b->word);
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    char buffer[MAX_WORD_LENGTH];
    int num_words = 0;
    struct word_count* word_counts = (struct word_count*)malloc(MAX_WORDS * sizeof(struct word_count));

    while (fscanf(input_file, "%s", buffer) == 1) {
        if (num_words >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            exit(1);
        }

        int word_length = strlen(buffer);
        if (word_length >= MAX_WORD_LENGTH) {
            printf("Maximum word length exceeded.\n");
            exit(1);
        }

        strcpy(word_counts[num_words].word, buffer);
        word_counts[num_words].count = 1;
        num_words++;
    }

    fclose(input_file);

    qsort(word_counts, num_words, sizeof(struct word_count), compare_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);
    return 0;
}