//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_file(FILE* file, WordCount* word_counts) {
    char line[MAX_WORD_LENGTH];
    char* word_start = NULL;
    size_t line_length = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        line_length = strlen(line);
        char* word_end = line + line_length - 1;

        while (isspace(*word_start)) {
            word_start++;
        }

        while (isspace(*word_end)) {
            word_end--;
        }

        if (word_start < word_end) {
            strncpy(word_counts->word, word_start, MAX_WORD_LENGTH);
            word_counts->count++;
        }
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordCount word_counts[MAX_WORD_LENGTH];
    int num_words = 0;

    read_file(file, word_counts);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    fclose(file);
    return 0;
}