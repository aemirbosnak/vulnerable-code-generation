//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int count;
} WordCount;

int compare_strings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[100];
    char word[MAX_WORD_LENGTH];
    int word_length;
    int num_words = 0;
    WordCount *word_counts = malloc(sizeof(WordCount) * MAX_WORDS);

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, 100, file)!= NULL) {
        char *token = strtok(line, ",.!?;:\"'");
        while (token!= NULL) {
            word_length = strlen(token);
            if (word_length > MAX_WORD_LENGTH) {
                fprintf(stderr, "Warning: Word \"%s\" is too long (max length is %d)\n", token, MAX_WORD_LENGTH);
            } else {
                strcpy(word, token);
                word[word_length] = '\0';
                num_words++;
                WordCount *word_count = bsearch(word, word_counts, num_words, sizeof(WordCount), compare_strings);
                if (word_count == NULL) {
                    word_counts[num_words - 1] = (WordCount) {.word = strdup(word),.count = 1};
                } else {
                    word_count->count++;
                }
            }
            token = strtok(NULL, ",.!?;:\"'");
        }
    }

    qsort(word_counts, num_words, sizeof(WordCount), compare_strings);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);
    fclose(file);

    return 0;
}