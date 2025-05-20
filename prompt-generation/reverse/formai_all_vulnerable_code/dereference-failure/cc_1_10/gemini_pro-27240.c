//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

struct word_count {
    char *word;
    int count;
};

int compare_word_count(const void *a, const void *b) {
    const struct word_count *wa = a;
    const struct word_count *wb = b;

    return strcmp(wa->word, wb->word);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the entire file into memory
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    char *buffer = malloc(size + 1);
    if (!buffer) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    fread(buffer, size, 1, file);
    fclose(file);
    buffer[size] = '\0';

    // Split the file into words
    char *words[10000];
    int num_words = 0;
    char *word = strtok(buffer, " \n\t\r");
    while (word) {
        words[num_words++] = word;
        word = strtok(NULL, " \n\t\r");
    }

    // Count the number of occurrences of each word
    struct word_count word_counts[10000];
    int num_word_counts = 0;
    for (int i = 0; i < num_words; i++) {
        int found = 0;
        for (int j = 0; j < num_word_counts; j++) {
            if (strcmp(words[i], word_counts[j].word) == 0) {
                word_counts[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            word_counts[num_word_counts].word = words[i];
            word_counts[num_word_counts].count = 1;
            num_word_counts++;
        }
    }

    // Sort the word counts
    qsort(word_counts, num_word_counts, sizeof(struct word_count), compare_word_count);

    // Print the word counts
    for (int i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return EXIT_SUCCESS;
}