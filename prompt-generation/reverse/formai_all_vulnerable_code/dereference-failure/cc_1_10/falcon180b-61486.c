//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    WordCount *words;
    int num_words;
} LogAnalysis;

void init_word_count(WordCount *wc) {
    wc->word = NULL;
    wc->count = 0;
}

void init_log_analysis(LogAnalysis *la) {
    la->words = NULL;
    la->num_words = 0;
}

void add_word(LogAnalysis *la, char *word) {
    WordCount *new_wc = malloc(sizeof(WordCount));
    init_word_count(new_wc);
    strncpy(new_wc->word, word, MAX_WORD_LENGTH);
    la->words = realloc(la->words, sizeof(WordCount) * (la->num_words + 1));
    la->words[la->num_words] = *new_wc;
    la->num_words++;
}

void count_words(LogAnalysis *la) {
    for (int i = 0; i < la->num_words; i++) {
        la->words[i].count = 0;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int index = find_word(la, word);
            if (index == -1) {
                add_word(la, word);
            } else {
                la->words[index].count++;
            }
            word = strtok(NULL, " ");
        }
    }
}

int find_word(LogAnalysis *la, char *word) {
    for (int i = 0; i < la->num_words; i++) {
        if (strcmp(la->words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void print_word_counts(LogAnalysis *la) {
    for (int i = 0; i < la->num_words; i++) {
        printf("%s: %d\n", la->words[i].word, la->words[i].count);
    }
}

int main() {
    LogAnalysis la;
    init_log_analysis(&la);

    count_words(&la);

    print_word_counts(&la);

    return 0;
}