//Falcon-180B DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char **argv) {
    FILE *input_file = NULL;
    char input_line[MAX_LINE_LENGTH];
    WordCount *word_counts = NULL;
    int num_words = 0;
    int num_lines = 0;
    int max_word_length = 0;
    int max_count = 0;

    // Open the input file
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read each line of the input file
    while (fgets(input_line, MAX_LINE_LENGTH, input_file)!= NULL) {
        num_lines++;

        // Split the line into words
        char *word = strtok(input_line, " ");
        while (word!= NULL) {
            num_words++;

            // Check if the word is already in the word_counts array
            WordCount *existing_word_count = NULL;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(word, word_counts[i].word) == 0) {
                    existing_word_count = &word_counts[i];
                    break;
                }
            }

            // If the word is not in the array, add it with a count of 1
            if (existing_word_count == NULL) {
                word_counts = realloc(word_counts, sizeof(WordCount) * (num_words + 1));
                memset(&word_counts[num_words - 1], 0, sizeof(WordCount));
                strncpy(word_counts[num_words - 1].word, word, MAX_WORD_LENGTH);
                word_counts[num_words - 1].count = 1;
            } else {
                existing_word_count->count++;
            }

            // Update the maximum word length and count
            if (strlen(word) > max_word_length) {
                max_word_length = strlen(word);
            }
            if (existing_word_count->count > max_count) {
                max_count = existing_word_count->count;
            }

            word = strtok(NULL, " ");
        }
    }

    // Close the input file
    fclose(input_file);

    // Print the word counts
    printf("Word Counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%-30s %d\n", word_counts[i].word, word_counts[i].count);
    }

    // Print the total number of lines and words
    printf("\nTotal lines: %d\n", num_lines);
    printf("Total words: %d\n", num_words);

    // Print the maximum word length and count
    printf("Maximum word length: %d\n", max_word_length);
    printf("Maximum count: %d\n", max_count);

    return 0;
}