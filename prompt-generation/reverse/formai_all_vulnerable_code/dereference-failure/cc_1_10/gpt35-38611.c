//FormAI DATASET v1.0 Category: Data mining ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

// Define a struct to hold a word and its count
typedef struct {
    char* word;
    int count;
} WordCount;

// Define a function to read a line from a file and return a list of words
char** read_line(FILE* fp) {
    char* line = malloc(MAX_LINE_LENGTH * sizeof(char));
    fgets(line, MAX_LINE_LENGTH, fp);

    char** words = malloc(MAX_WORDS * sizeof(char*));
    int num_words = 0;

    char* word = strtok(line, " ");
    while (word != NULL) {
        words[num_words] = malloc(MAX_WORD_LENGTH * sizeof(char));
        strncpy(words[num_words], word, MAX_WORD_LENGTH);
        num_words++;

        word = strtok(NULL, " ");
    }

    free(line);
    return words;
}

int main() {
    
    // Open the input file
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    // Read the lines of the file and count the occurrence of each word
    char** words;
    int num_words = 0;
    WordCount* word_counts = malloc(MAX_WORDS * sizeof(WordCount));
    int num_word_counts = 0;

    while (!feof(input_file)) {
        words = read_line(input_file);

        for (int i = 0; i < num_words; i++) {
            // Check if word is already in word_counts array
            int word_index = -1;

            for (int j = 0; j < num_word_counts; j++) {
                if (strcmp(words[i], word_counts[j].word) == 0) {
                    word_index = j;
                    break;
                }
            }

            if (word_index != -1) {
                word_counts[word_index].count++;
            } else {
                word_counts[num_word_counts].word = malloc(MAX_WORD_LENGTH * sizeof(char));
                strncpy(word_counts[num_word_counts].word, words[i], MAX_WORD_LENGTH);
                word_counts[num_word_counts].count = 1;
                num_word_counts++;
            }
        }

        num_words++;
        free(words);
    }

    // Close the input file
    fclose(input_file);

    // Sort word_counts array by count in descending order using bubble sort
    for (int i = 0; i < num_word_counts - 1; i++) {
        for (int j = 0; j < num_word_counts - i - 1; j++) {
            if (word_counts[j].count < word_counts[j + 1].count) {
                WordCount temp = word_counts[j];
                word_counts[j] = word_counts[j + 1];
                word_counts[j + 1] = temp;
            }
        }
    }

    // Print the top 10 most common words
    for (int i = 0; i < 10; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    // Free dynamically allocated memory
    for (int i = 0; i < num_word_counts; i++) {
        free(word_counts[i].word);
    }
    free(word_counts);

    return 0;
}