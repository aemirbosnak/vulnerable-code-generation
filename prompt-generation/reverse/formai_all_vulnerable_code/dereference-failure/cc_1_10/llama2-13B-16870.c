//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1024
#define CHAR_COUNT 5

struct word {
    char *word;
    size_t len;
};

struct stats {
    size_t total_words;
    size_t unique_words;
    size_t longest_word;
};

void process_text(char *text) {
    struct stats stats;
    struct word *words = calloc(1, sizeof(struct word));
    char *word = strtok(text, " ");

    while (word != NULL) {
        size_t len = strcspn(word, " ");
        if (len > 0) {
            words[stats.total_words].word = word;
            words[stats.total_words].len = len;
            stats.total_words++;
            if (stats.unique_words == 0 || strcmp(words[stats.unique_words - 1].word, word) != 0) {
                stats.unique_words++;
                if (len > stats.longest_word) {
                    stats.longest_word = len;
                }
            }
        }
        word = strtok(NULL, " ");
    }

    printf("Total words: %zu\n", stats.total_words);
    printf("Unique words: %zu\n", stats.unique_words);
    printf("Longest word: %zu\n", stats.longest_word);

    free(words);
}

int main() {
    char text[] = "The quick brown fox jumps over the lazy dog";
    process_text(text);
    return 0;
}