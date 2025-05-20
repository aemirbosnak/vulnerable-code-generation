//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} WordCount;

int compare_wordcounts(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

void print_wordcounts(WordCount *wordcounts, int num_wordcounts) {
    qsort(wordcounts, num_wordcounts, sizeof(WordCount), compare_wordcounts);

    for (int i = 0; i < num_wordcounts; i++) {
        printf("%s: %d\n", wordcounts[i].word, wordcounts[i].count);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    FILE *logfile;
    WordCount wordcounts[100];
    int num_wordcounts = 0;

    logfile = fopen("apocalypse.log", "r");

    if (logfile == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, logfile)!= NULL) {
        char *token = strtok(line, " ");

        while (token!= NULL) {
            if (num_wordcounts >= 100) {
                printf("Error: too many unique words in log file.\n");
                exit(1);
            }

            if (strlen(token) > MAX_WORD_LENGTH) {
                printf("Error: word '%s' is too long.\n", token);
                exit(1);
            }

            strcpy(wordcounts[num_wordcounts].word, token);
            wordcounts[num_wordcounts].count = 1;
            num_wordcounts++;

            token = strtok(NULL, " ");
        }
    }

    fclose(logfile);

    print_wordcounts(wordcounts, num_wordcounts);

    return 0;
}