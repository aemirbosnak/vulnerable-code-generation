//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare_strings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void print_word_counts(WordCount *word_counts, int num_words) {
    qsort(word_counts, num_words, sizeof(WordCount), compare_strings);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *log_file = fopen("example.log", "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    WordCount word_counts[1000]; // Assume there won't be more than 1000 unique words
    int num_words = 0;

    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            if (num_words >= 1000) {
                printf("Too many unique words in log file.\n");
                fclose(log_file);
                return 1;
            }

            WordCount *existing_word = bsearch(word, word_counts, num_words, sizeof(WordCount), compare_strings);
            if (existing_word!= NULL) {
                existing_word->count++;
            } else {
                strncpy(word_counts[num_words].word, word, MAX_WORD_LENGTH);
                word_counts[num_words].count = 1;
                num_words++;
            }

            word = strtok(NULL, " ");
        }
    }

    fclose(log_file);
    print_word_counts(word_counts, num_words);

    return 0;
}