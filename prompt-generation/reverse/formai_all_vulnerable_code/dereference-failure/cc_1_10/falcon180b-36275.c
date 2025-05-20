//Falcon-180B DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

void read_file(FILE *file, struct word_count *word_counts, int word_count_size) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= word_count_size) {
            printf("Error: Too many unique words.\n");
            exit(1);
        }

        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(word_counts[j].word, word) == 0) {
                word_counts[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(word_counts[i].word, word);
            word_counts[i].count = 1;
            i++;
        }
    }
}

void write_word_counts(struct word_count *word_counts, int word_count_size) {
    for (int i = 0; i < word_count_size; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *file;
    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    int word_count_size = 0;
    struct word_count *word_counts = malloc(MAX_WORDS * sizeof(struct word_count));

    read_file(file, word_counts, MAX_WORDS);
    write_word_counts(word_counts, word_count_size);

    free(word_counts);
    fclose(file);

    return 0;
}