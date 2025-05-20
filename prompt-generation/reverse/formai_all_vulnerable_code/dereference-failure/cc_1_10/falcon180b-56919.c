//Falcon-180B DATASET v1.0 Category: Text processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORDS 100

typedef struct {
    char *word;
    int count;
} WordCount;

void print_word_counts(WordCount *word_counts, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;
    int word_count = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((read = getline(&line, &len, fp))!= -1) {
        char *word;
        int word_len;
        char *delim = " \t\n\r\f";

        word = strtok_r(line, delim, &word_len);
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Max number of words reached.\n");
                    break;
                }
                word_counts[num_words].word = strdup(word);
                word_counts[num_words].count = 1;
                num_words++;
            }
            word = strtok_r(NULL, delim, &word_len);
        }
        word_count++;
    }

    fclose(fp);

    if (num_words == 0) {
        printf("No words found.\n");
        return 1;
    }

    print_word_counts(word_counts, num_words);

    return 0;
}