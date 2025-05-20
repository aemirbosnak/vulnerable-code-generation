//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define WORD_DELIMITERS " \t\r\n,.?!;:\"()[]{}<>"

void process_line(const char *line, int *word_count) {
    char *token;
    char *line_copy = strdup(line); // Duplicate line to avoid modifying the original string
    if (line_copy == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line_copy, WORD_DELIMITERS);
    while (token != NULL) {
        (*word_count)++;
        token = strtok(NULL, WORD_DELIMITERS);
    }
    free(line_copy); // Free the duplicated string
}

void benchmark_text_processing(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int total_words = 0;
    clock_t start_time, end_time;

    start_time = clock(); // Start timing

    while (fgets(line, sizeof(line), file)) {
        process_line(line, &total_words);
    }

    end_time = clock(); // End timing

    fclose(file); // Close the file

    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Total words: %d\n", total_words);
    printf("Processing time: %.6f seconds\n", time_spent);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    benchmark_text_processing(argv[1]);
    return EXIT_SUCCESS;
}