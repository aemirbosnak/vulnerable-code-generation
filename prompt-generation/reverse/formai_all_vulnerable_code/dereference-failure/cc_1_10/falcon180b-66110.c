//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

// Function to split a line into words
void split_line(char* line, char* words[]) {
    char* word = strtok(line, " ");
    int i = 0;
    while (word!= NULL) {
        strcpy(words[i], word);
        i++;
        word = strtok(NULL, " ");
    }
}

// Function to count the frequency of each word
void count_words(char* words[], int freq[]) {
    int i = 0;
    while (words[i]!= NULL) {
        freq[i] = 1;
        i++;
    }
}

// Function to print the word frequency
void print_freq(char* words[], int freq[], int num_words) {
    printf("Word frequency:\n");
    for (int i = 0; i < num_words; i++) {
        if (freq[i] > 0) {
            printf("%s: %d\n", words[i], freq[i]);
        }
    }
}

// Function to read the log file and count the word frequency
void analyze_log(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char words[MAX_WORD_LENGTH][MAX_WORD_LENGTH];
    int freq[MAX_WORD_LENGTH] = {0};
    int num_words = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        split_line(line, words);
        count_words(words, freq);
        num_words += strlen(line) - 1;
    }

    print_freq(words, freq, num_words);

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    analyze_log(argv[1]);

    return 0;
}