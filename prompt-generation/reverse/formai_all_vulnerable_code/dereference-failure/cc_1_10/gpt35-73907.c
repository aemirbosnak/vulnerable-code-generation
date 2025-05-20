//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Define maximum word length
#define MAX_WORD_LENGTH 50

// Define maximum number of words in input file
#define MAX_NUM_WORDS 1000

// Define structure to store word frequency count
typedef struct WordFreq {
    char word[MAX_WORD_LENGTH];
    int freq;
} WordFreq;

// Function to strip whitespace from both ends of a string
char* strip(char* str) {
    char* end;

    while (isspace(*str)) {
        str++;
    }

    if (*str == 0) {
        return str;
    }

    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end--;
    }
    *(end + 1) = 0;

    return str;
}

// Function to read words from a file and compute their frequency counts
int compute_word_freq(char* filename, WordFreq** word_freq) {
    int num_words = 0;
    char line[MAX_WORD_LENGTH];
    char* word;

    // Open input file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Allocate memory for word frequency count array
    *word_freq = malloc(MAX_NUM_WORDS * sizeof(WordFreq));

    // Initialize word frequency count array with zero counts
    for (int i = 0; i < MAX_NUM_WORDS; i++) {
        (*word_freq)[i].word[0] = '\0';
        (*word_freq)[i].freq = 0;
    }

    // Read words from input file and compute frequency counts
    while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
        word = strtok(line, " \t\n");

        while (word != NULL) {
            // Strip whitespace and punctuation from word
            word = strip(word);
            for (int i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                    break;
                } else {
                    word[i] = tolower(word[i]);
                }
            }

            // Add word to frequency count array
            if (strlen(word) > 0) {
                int i;
                for (i = 0; i < num_words; i++) {
                    if (strcmp((*word_freq)[i].word, word) == 0) {
                        (*word_freq)[i].freq++;
                        break;
                    }
                }
                if (i == num_words) {
                    strncpy((*word_freq)[i].word, word, MAX_WORD_LENGTH);
                    (*word_freq)[i].freq++;
                    num_words++;
                }
            }

            word = strtok(NULL, " \t\n");
        }
    }

    fclose(fp);

    return num_words;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    WordFreq* word_freq;
    int num_words = compute_word_freq(argv[1], &word_freq);

    // Sort array by frequency count
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (word_freq[j].freq > word_freq[i].freq) {
                WordFreq tmp = word_freq[i];
                word_freq[i] = word_freq[j];
                word_freq[j] = tmp;
            }
        }
    }

    // Print word frequency count array
    printf("Word    Frequency\n");
    printf("----    ---------\n");
    for (int i = 0; i < num_words; i++) {
        printf("%-7s %d\n", word_freq[i].word, word_freq[i].freq);
    }

    // Free memory
    free(word_freq);

    return 0;
}