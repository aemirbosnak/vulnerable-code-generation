//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} word_count_t;

int compare_word_counts(const void *a, const void *b) {
    const word_count_t *wa = (const word_count_t *)a;
    const word_count_t *wb = (const word_count_t *)b;

    return wb->count - wa->count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the text file into a string.
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    char *text = malloc(file_size + 1);
    if (text == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return EXIT_FAILURE;
    }

    fread(text, file_size, 1, fp);
    fclose(fp);
    text[file_size] = '\0';

    // Tokenize the text into words.
    char *words[MAX_WORDS];
    int num_words = 0;

    char *token = strtok(text, " ,.-?!\n");
    while (token != NULL && num_words < MAX_WORDS) {
        words[num_words++] = token;
        token = strtok(NULL, " ,.-?!\n");
    }

    // Count the occurrences of each word.
    word_count_t word_counts[MAX_WORDS];
    int num_unique_words = 0;

    for (int i = 0; i < num_words; i++) {
        char *word = words[i];

        // Convert the word to lowercase.
        for (int j = 0; j < strlen(word); j++) {
            word[j] = tolower(word[j]);
        }

        // Check if the word is already in the word_counts array.
        int found = 0;
        for (int j = 0; j < num_unique_words; j++) {
            if (strcmp(word, word_counts[j].word) == 0) {
                word_counts[j].count++;
                found = 1;
                break;
            }
        }

        // If the word is not in the word_counts array, add it.
        if (!found) {
            strcpy(word_counts[num_unique_words].word, word);
            word_counts[num_unique_words].count = 1;
            num_unique_words++;
        }
    }

    // Sort the word_counts array by count in descending order.
    qsort(word_counts, num_unique_words, sizeof(word_count_t), compare_word_counts);

    // Print the top 10 words and their counts.
    printf("Top 10 words:\n");
    for (int i = 0; i < 10 && i < num_unique_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(text);

    return EXIT_SUCCESS;
}