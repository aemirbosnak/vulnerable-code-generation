//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORD_LEN 20
#define MIN_FREQ 1
#define THRESHOLD 5

typedef struct {
    char *word;
    int freq;
} word_t;

void print_top_words(word_t *words, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (words[i].freq >= THRESHOLD) {
            printf("%s: %d\n", words[i].word, words[i].freq);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <log_file> <threshold>\n", argv[0]);
        return 1;
    }

    char *log_file = argv[1];
    int threshold = atoi(argv[2]);

    // Open the log file
    FILE *log_file_ptr = fopen(log_file, "r");
    if (log_file_ptr == NULL) {
        perror("Error opening log file");
        return 2;
    }

    // Read the log file and count the frequency of each word
    word_t *words = calloc(1, sizeof(word_t));
    int num_words = 0;
    char line[1024];
    while (fgets(line, 1024, log_file_ptr)) {
        char *word = line;
        while (*word != '\0' && isalnum(*word)) {
            word_t new_word;
            new_word.word = word;
            new_word.freq = 1;
            words = realloc(words, (num_words + 1) * sizeof(word_t));
            words[num_words] = new_word;
            num_words++;
            word += strcspn(word, " ");
        }
    }

    // Print the top words
    print_top_words(words, num_words);

    // Free memory
    free(words);

    return 0;
}