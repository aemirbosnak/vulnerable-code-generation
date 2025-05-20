//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *word;
    int count;
} word_t;

void load_log(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    char buffer[MAX_LOG_LENGTH];
    word_t *words = calloc(1, sizeof(word_t));

    while (fgets(buffer, MAX_LOG_LENGTH, file)) {
        char *token = strtok(buffer, " ");

        // Ignore empty tokens
        if (!token) continue;

        // Check if the token is a word we haven't seen before
        if (!words->word || strcmp(token, words->word) != 0) {
            words = realloc(words, (words->count + 1) * sizeof(word_t));
            words[words->count].word = token;
            words[words->count].count = 1;
            words->count++;
        } else {
            words[words->count].count++;
        }
    }

    fclose(file);
}

void print_stats(word_t *words) {
    int max_count = 0;
    char *max_word = NULL;

    for (int i = 0; i < words->count; i++) {
        if (words[i].count > max_count) {
            max_count = words[i].count;
            max_word = words[i].word;
        }
    }

    printf("Most common word: %s (%d times)\n", max_word, max_count);
}

int main() {
    word_t *words = NULL;

    load_log("example.log");
    print_stats(words);

    return 0;
}