//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_LOG_SIZE 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordEntry;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    char log_file[MAX_LOG_SIZE];
    strcpy(log_file, argv[1]);

    FILE *log_fp = fopen(log_file, "r");
    if (log_fp == NULL) {
        fprintf(stderr, "Could not open log file '%s'.\n", log_file);
        return 1;
    }

    WordEntry *word_table = (WordEntry *) malloc(sizeof(WordEntry) * MAX_LOG_SIZE);
    int num_words = 0;

    char line[MAX_LOG_SIZE];
    while (fgets(line, MAX_LOG_SIZE, log_fp)!= NULL) {
        char *word = strtok(line, " \t\n");
        while (word!= NULL) {
            if (strlen(word) > MAX_WORD_LENGTH) {
                fprintf(stderr, "Word '%s' is too long.\n", word);
                continue;
            }

            if (word_table[num_words].word[0] == '\0') {
                strcpy(word_table[num_words].word, word);
                word_table[num_words].count = 1;
            } else {
                if (strcmp(word_table[num_words].word, word) == 0) {
                    word_table[num_words].count++;
                } else {
                    strcpy(word_table[num_words + 1].word, word);
                    word_table[num_words + 1].count = 1;
                    num_words++;
                }
            }

            word = strtok(NULL, " \t\n");
        }
    }

    fclose(log_fp);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_table[i].word, word_table[i].count);
    }

    free(word_table);

    return 0;
}