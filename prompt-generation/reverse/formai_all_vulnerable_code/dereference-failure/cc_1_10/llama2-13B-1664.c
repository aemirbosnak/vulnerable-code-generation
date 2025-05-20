//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MIN_WORD_LEN 3

struct word {
    char *text;
    size_t len;
};

struct stats {
    size_t words;
    size_t char_count;
    double avg_word_len;
};

int main() {
    // Generate a random text for testing
    char *text = "The quick brown fox jumps over the lazy dog";
    size_t text_len = strlen(text);

    // Create a list of words
    struct word *words = malloc(text_len * sizeof(struct word));
    size_t i = 0;
    for (; i < text_len; i++) {
        if (isalpha(text[i])) {
            words[i].text = &text[i];
            words[i].len = 1;
        }
    }

    // Count the number of words
    struct stats stats;
    stats.words = 0;
    stats.char_count = 0;
    stats.avg_word_len = 0;
    for (i = 0; i < text_len; i++) {
        if (words[i].text != NULL) {
            stats.words++;
            stats.char_count += words[i].len;
            stats.avg_word_len += words[i].len;
        }
    }

    // Print the statistics
    printf("Word Count Statistics:\n");
    printf("Total Words: %zu\n", stats.words);
    printf("Total Characters: %zu\n", stats.char_count);
    printf("Average Word Length: %f\n", stats.avg_word_len / stats.words);

    // Free memory
    free(words);

    return 0;
}

// Function to check if a character is alphabetic
int isalpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}