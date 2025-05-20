//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

int compare_word_counts(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    if (wc1->count > wc2->count) {
        return -1;
    } else if (wc1->count < wc2->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *log_file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_LINE_LENGTH];
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    log_file = fopen("logfile.txt", "r");

    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        char *token = strtok(line, " ");

        while (token!= NULL) {
            strcpy(word, token);
            int i;

            for (i = 0; i < num_words; i++) {
                if (strcmp(word_counts[i].word, word) == 0) {
                    word_counts[i].count++;
                    break;
                }
            }

            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Error: Too many unique words in log file.\n");
                    exit(1);
                }

                strcpy(word_counts[num_words].word, word);
                word_counts[num_words].count = 1;
                num_words++;
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(log_file);

    qsort(word_counts, num_words, sizeof(WordCount), compare_word_counts);

    printf("Word Counts:\n");

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}