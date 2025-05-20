//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word;
    int count;
} word_freq;

int compare_word_freq(const void *a, const void *b) {
    const word_freq *wa = (const word_freq *)a;
    const word_freq *wb = (const word_freq *)b;
    return strcmp(wa->word, wb->word);
}

int main() {
    // Open the Romeo and Juliet text file
    FILE *fp = fopen("romeo_and_juliet.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the file into a buffer
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return EXIT_FAILURE;
    }
    fread(buffer, file_size, 1, fp);
    fclose(fp);

    // Split the buffer into words
    char *words[10000];
    int num_words = 0;
    char *word = strtok(buffer, " \n\t\r\v\f");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " \n\t\r\v\f");
    }

    // Count the frequency of each word
    word_freq word_freqs[10000];
    int num_word_freqs = 0;
    for (int i = 0; i < num_words; i++) {
        int found = 0;
        for (int j = 0; j < num_word_freqs; j++) {
            if (strcmp(words[i], word_freqs[j].word) == 0) {
                word_freqs[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            word_freqs[num_word_freqs].word = words[i];
            word_freqs[num_word_freqs].count = 1;
            num_word_freqs++;
        }
    }

    // Sort the word frequencies by word
    qsort(word_freqs, num_word_freqs, sizeof(word_freq), compare_word_freq);

    // Print the word frequencies
    for (int i = 0; i < num_word_freqs; i++) {
        printf("%s: %d\n", word_freqs[i].word, word_freqs[i].count);
    }

    // Free the allocated memory
    free(buffer);

    return EXIT_SUCCESS;
}