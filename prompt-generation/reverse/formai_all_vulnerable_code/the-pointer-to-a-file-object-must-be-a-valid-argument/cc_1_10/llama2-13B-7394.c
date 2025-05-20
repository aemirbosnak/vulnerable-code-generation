//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_FILES 10

// Structure to hold information about a single log file
typedef struct {
    char *filename;
    int num_lines;
    int num_words;
    int num_chars;
    int top_10[10];
} log_file_info_t;

// Function to parse a single log file and update the corresponding structure
void parse_log_file(log_file_info_t *info, char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    int i = 0;

    // Count the number of lines, words, and characters in the log file
    info->num_lines = 0;
    info->num_words = 0;
    info->num_chars = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        info->num_lines++;
        info->num_words++;
        info->num_chars += strlen(line);
    }

    // Count the top 10 most frequent words in the log file
    int freq[10];
    int j = 0;
    for (i = 0; i < info->num_lines; i++) {
        char *word = strtok(line, " ");
        while (word != NULL) {
            if (j < 10) {
                freq[j]++;
                word = strtok(NULL, " ");
            } else {
                break;
            }
        }
        j++;
    }

    // Update the top 10 most frequent words in the structure
    for (i = 0; i < 10; i++) {
        info->top_10[i] = freq[i];
    }

    // Close the file
    fclose(file);
}

// Function to print the report for a single log file
void print_report(log_file_info_t *info) {
    printf("Log File: %s\n", info->filename);
    printf("Number of lines: %d\n", info->num_lines);
    printf("Number of words: %d\n", info->num_words);
    printf("Number of characters: %d\n", info->num_chars);
    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s (%d times)\n", i + 1, info->top_10[i], info->top_10[i]);
    }
}

// Main function to parse all log files and print the report
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <log_file1> <log_file2> ...\n", argv[0]);
        return 1;
    }

    // Array to hold the log file information
    log_file_info_t log_files[MAX_LOG_FILES];

    // Parse each log file and update the corresponding structure
    for (int i = 0; i < argc; i++) {
        parse_log_file(log_files + i, argv[i]);
    }

    // Print the report for each log file
    for (int i = 0; i < argc; i++) {
        print_report(log_files + i);
    }

    return 0;
}