//Falcon-180B DATASET v1.0 Category: Text processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    WordCount *word_counts = calloc(MAX_WORDS, sizeof(WordCount));
    int num_words = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Failed to open input file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        token = strtok(line, " \t\r\n\f\v");
        while (token!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Error: Too many unique words.\n");
                    fclose(file);
                    return 1;
                }
                word_counts[num_words].word = strdup(token);
                word_counts[num_words].count = 1;
                num_words++;
            }
            token = strtok(NULL, " \t\r\n\f\v");
        }
    }

    fclose(file);

    printf("Word counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);
    return 0;
}