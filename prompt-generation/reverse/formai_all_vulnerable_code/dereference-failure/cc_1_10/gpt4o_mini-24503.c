//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 256

typedef struct {
    char *line;
    int word_count;
} Line;

void initialize_lines(Line *lines) {
    for (int i = 0; i < MAX_LINES; i++) {
        lines[i].line = malloc(MAX_LINE_LENGTH * sizeof(char));
        lines[i].word_count = 0;
    }
}

void free_lines(Line *lines) {
    for (int i = 0; i < MAX_LINES; i++) {
        free(lines[i].line);
    }
}

int count_words(const char *line) {
    int count = 0;
    char *token;
    char *temp_line = strdup(line);
    token = strtok(temp_line, " \t\n");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \t\n");
    }
    free(temp_line);
    return count;
}

void summarize_text(Line *lines, int line_count) {
    FILE *output_file = fopen("summary.txt", "w");
    if (output_file == NULL) {
        perror("Failed to open output file");
        return;
    }

    fprintf(output_file, "--- Text Summary ---\n\n");
    for (int i = 0; i < line_count; i++) {
        if (lines[i].word_count > 5) { // Only include lines with more than 5 words
            fprintf(output_file, "%s\n", lines[i].line);
        }
    }

    fclose(output_file);
}

void read_lines(FILE *input_file, Line *lines, int *line_count) {
    char buffer[MAX_LINE_LENGTH];
    
    while (fgets(buffer, sizeof(buffer), input_file) != NULL && *line_count < MAX_LINES) {
        strcpy(lines[*line_count].line, buffer);
        lines[*line_count].word_count = count_words(buffer);
        (*line_count)++;
    }
}

void display_summary(Line *lines, int line_count) {
    printf("--- Text Summary ---\n\n");
    for (int i = 0; i < line_count; i++) {
        if (lines[i].word_count > 5) {
            printf("%s", lines[i].line);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Failed to open input file");
        return EXIT_FAILURE;
    }

    Line *lines = malloc(MAX_LINES * sizeof(Line));
    initialize_lines(lines);

    int line_count = 0;
    read_lines(input_file, lines, &line_count);
    fclose(input_file);

    summarize_text(lines, line_count);
    display_summary(lines, line_count);

    free_lines(lines);
    free(lines);

    return EXIT_SUCCESS;
}