//Falcon-180B DATASET v1.0 Category: Educational ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} word_count_t;

int main(int argc, char *argv[]) {
    FILE *input_file = fopen("input.txt", "r");
    char line[MAX_LINE_LENGTH];
    char *token;
    word_count_t *word_counts = malloc(MAX_WORDS * sizeof(word_count_t));
    int num_words = 0;

    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            for (int i = 0; i < num_words; i++) {
                if (strcmp(token, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (num_words >= MAX_WORDS) {
                printf("Error: too many unique words.\n");
                exit(1);
            }
            word_counts[num_words].word = strdup(token);
            word_counts[num_words].count = 1;
            num_words++;
            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(input_file);

    printf("Word counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);
    return 0;
}