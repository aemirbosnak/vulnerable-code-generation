//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LOG_LEN 1024
#define MAX_WORD_LEN 32

typedef struct {
    char *word;
    int count;
} word_t;

typedef struct {
    word_t *words;
    int count;
} log_t;

void init_log(log_t *log) {
    log->words = (word_t *)calloc(1, sizeof(word_t));
    log->count = 0;
}

void add_word(log_t *log, char *word) {
    word_t *new_word = (word_t *)calloc(1, sizeof(word_t));
    new_word->word = word;
    new_word->count = 1;
    if (log->count >= MAX_WORD_LEN) {
        log->words = (word_t *)realloc(log->words, (log->count + 1) * sizeof(word_t));
    }
    log->words[log->count] = *new_word;
    log->count++;
}

void print_log(log_t *log) {
    int i;
    for (i = 0; i < log->count; i++) {
        printf("%d: %s\n", i, log->words[i].word);
    }
}

int main() {
    log_t log;
    init_log(&log);

    add_word(&log, "Hello");
    add_word(&log, "World");
    add_word(&log, "C");
    add_word(&log, "Programming");

    print_log(&log);

    return 0;
}