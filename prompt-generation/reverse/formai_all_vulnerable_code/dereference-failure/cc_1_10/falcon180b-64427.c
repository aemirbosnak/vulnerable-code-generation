//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

int compare_wordcount(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_SIZE];
    WordCount *word_counts = NULL;
    int num_words = 0;

    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (num_words >= MAX_WORD_SIZE) {
                printf("Error: Too many unique words in log file.\n");
                fclose(file);
                return 1;
            }
            WordCount *wc = malloc(sizeof(WordCount));
            strncpy(wc->word, token, MAX_WORD_SIZE - 1);
            wc->word[MAX_WORD_SIZE - 1] = '\0';
            wc->count = 1;
            word_counts = realloc(word_counts, sizeof(WordCount) * ++num_words);
            memcpy(word_counts + num_words - 1, wc, sizeof(WordCount));
            free(wc);
            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    qsort(word_counts, num_words, sizeof(WordCount), compare_wordcount);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);
    return 0;
}