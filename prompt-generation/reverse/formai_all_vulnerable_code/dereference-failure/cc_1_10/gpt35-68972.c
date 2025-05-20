//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define DEFAULT_THRESHOLD 10

void print_usage(char* program_name);
int read_word(FILE* input_file, char* word_buffer);
int compare_word(const void* a, const void* b);
int count_words(FILE* input_file, char** words, int max_words);
void print_word_frequencies(char** words, int* frequencies, int num_words, int threshold);

int main(int argc, char** argv) {
    char* input_file_path = NULL;
    int threshold = DEFAULT_THRESHOLD;
    int i;

    // Parse command-line arguments
    for (i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            // Option
            if (argv[i][1] == 't') {
                // Word frequency threshold
                if (i == argc - 1) {
                    fprintf(stderr, "Error: -t option missing threshold value\n");
                    print_usage(argv[0]);
                    return 1;
                }
                threshold = atoi(argv[i+1]);
                i++;
            } else {
                fprintf(stderr, "Error: Unknown option %s\n", argv[i]);
                print_usage(argv[0]);
                return 1;
            }
        } else {
            // Input file path
            if (input_file_path != NULL) {
                fprintf(stderr, "Error: Only one input file can be specified\n");
                print_usage(argv[0]);
                return 1;
            }
            input_file_path = argv[i];
        }
    }

    if (input_file_path == NULL) {
        fprintf(stderr, "Error: No input file specified\n");
        print_usage(argv[0]);
        return 1;
    }

    // Open input file
    FILE* input_file = fopen(input_file_path, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Unable to open input file %s\n", input_file_path);
        return 1;
    }

    // Allocate word buffers
    char** words = malloc(sizeof(char*) * MAX_WORD_LENGTH);
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        words[i] = malloc(sizeof(char) * (i+1));
    }

    // Count words and frequencies
    int num_words = count_words(input_file, words, MAX_WORD_LENGTH);
    int* frequencies = calloc(num_words, sizeof(int));
    for (i = 0; i < num_words; i++) {
        frequencies[i] = 1;
        int j;
        for (j = i+1; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                frequencies[i]++;
                frequencies[j] = -1;
            }
        }
    }

    // Sort words by frequency
    qsort(words, num_words, sizeof(char*), compare_word);

    // Print word frequencies
    print_word_frequencies(words, frequencies, num_words, threshold);

    // Clean up
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        free(words[i]);
    }
    free(words);
    free(frequencies);
    fclose(input_file);

    return 0;
}

void print_usage(char* program_name) {
    printf("Usage: %s [-t threshold] input_file\n", program_name);
}

int read_word(FILE* input_file, char* word_buffer) {
    char c;
    int i = 0;
    while ((c = fgetc(input_file)) != EOF) {
        if (isspace(c)) {
            if (i == 0) {
                continue;
            } else {
                break;
            }
        }
        if (i >= MAX_WORD_LENGTH - 1) {
            fprintf(stderr, "Error: Maximum word length exceeded\n");
            exit(1);
        }
        word_buffer[i++] = tolower(c);
    }
    word_buffer[i] = '\0';
    return i;
}

int compare_word(const void* a, const void* b) {
    const char* const* a_str = a;
    const char* const* b_str = b;
    int a_freq = strlen(*a_str);
    int b_freq = strlen(*b_str);
    if (a_freq < b_freq) {
        return 1;
    } else if (a_freq > b_freq) {
        return -1;
    } else {
        return strcmp(*a_str, *b_str);
    }
}

int count_words(FILE* input_file, char** words, int max_words) {
    int num_words = 0;
    while (num_words < max_words && read_word(input_file, words[num_words]) > 0) {
        num_words++;
    }
    return num_words;
}

void print_word_frequencies(char** words, int* frequencies, int num_words, int threshold) {
    int i;
    printf("%-30s %s\n", "Word", "Frequency");
    printf("----------------------------------------\n");
    for (i = 0; i < num_words; i++) {
        if (frequencies[i] >= threshold) {
            printf("%-30s %d\n", words[i], frequencies[i]);
        }
    }
}