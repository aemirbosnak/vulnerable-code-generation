//FormAI DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50

int compare(const void * a, const void * b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    char *text = "This is a sample text document. It contains words and sentences. Some words are repeated, while others only appear once.";
    int word_count = 0, sentence_count = 0, char_count = 0;
    int occurrence_counts[MAX_WORD_LEN] = {0};
    char words[MAX_WORD_LEN][MAX_WORD_LEN] = {0};

    // Tokenize the text into words
    char *token = strtok(text, " ");
    while (token != NULL) {
        // Process each word
        int len = strlen(token);
        if (len > MAX_WORD_LEN) {
            printf("Error: Word '%s' is too long! Maximum word length is %d.\n", token, MAX_WORD_LEN);
            return 1;
        }
        // Strip off any non-alphanumeric characters from the word
        char *clean_word = calloc(len + 1, sizeof(char));
        int j = 0;
        for (int i = 0; i < len; i++) {
            if (isalnum(token[i])) {
                clean_word[j] = tolower(token[i]);
                j++;
            }
        }
        // Add the cleaned word to our arrays
        if (j > 0) {
            word_count++;
            strcpy(words[word_count - 1], clean_word);
            occurrence_counts[j - 1]++;
            char_count += j;
            if (strchr(token, '.') || strchr(token, '?') || strchr(token, '!')) {
                sentence_count++;
            }
        }
        free(clean_word);

        token = strtok(NULL, " ");
    }

    // Sort the occurrence counts in descending order
    qsort(occurrence_counts, MAX_WORD_LEN, sizeof(int), compare);

    // Print some statistics
    printf("Word count: %d\n", word_count);
    printf("Sentence count: %d\n", sentence_count);
    printf("Character count: %d\n", char_count);
    printf("Most common word lengths:");
    for (int i = 0; i < MAX_WORD_LEN; i++) {
        if (occurrence_counts[i] > 0) {
            printf(" %d (%d)", i + 1, occurrence_counts[i]);
        }
    }
    printf("\n");

    int num_unique_words = 0;
    char unique_words[MAX_WORD_LEN][MAX_WORD_LEN] = {0};
    for (int i = 0; i < word_count; i++) {
        int is_unique = 1;
        for (int j = 0; j < i; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            strcpy(unique_words[num_unique_words], words[i]);
            num_unique_words++;
        }
    }

    printf("Unique words (%d total):\n", num_unique_words);
    for (int i = 0; i < num_unique_words; i++) {
        printf("%d. %s\n", i + 1, unique_words[i]);
    }

    return 0;
}