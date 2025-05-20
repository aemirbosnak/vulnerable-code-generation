//FormAI DATASET v1.0 Category: Text Summarizer ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_LINES = 1000;
const int MAX_LENGTH = 1000;

// helper functions
int get_num_lines(char*);
char** split_text_into_lines(char*, int);

int main() {
    // get the text to summarize
    char text[MAX_LINES * MAX_LENGTH];
    printf("Enter the text to summarize:\n");
    fgets(text, MAX_LINES * MAX_LENGTH, stdin);

    // get the number of lines and split the text into individual lines
    int num_lines = get_num_lines(text);
    char** lines = split_text_into_lines(text, num_lines);

    // compute the length of each line
    int line_lengths[num_lines];
    for (int i = 0; i < num_lines; i++) {
        line_lengths[i] = strlen(lines[i]);
    }

    // compute the total length of the text
    int total_length = 0;
    for (int i = 0; i < num_lines; i++) {
        total_length += line_lengths[i];
    }

    // compute the average length of a line
    float avg_length = (float) total_length / num_lines;

    // create an array to hold the sums of word lengths for each line
    int word_sums[num_lines];
    for (int i = 0; i < num_lines; i++) {
        word_sums[i] = 0;
    }

    // compute the sum of word lengths for each line
    for (int i = 0; i < num_lines; i++) {
        char* line = lines[i];
        int line_len = strlen(line);
        int sum = 0;
        for (int j = 0; j < line_len; j++) {
            char c = line[j];
            if (c != ' ' && c != '\n' && c != '\t') {
                sum += 1;
            }
        }
        word_sums[i] = sum;
    }

    // determine which lines are above the average length and which lines have a high sum of word lengths
    int summary_indices[num_lines];
    int num_summary_lines = 0;
    for (int i = 0; i < num_lines; i++) {
        if (line_lengths[i] > 0.75 * avg_length || word_sums[i] > 0.75 * avg_length) {
            summary_indices[num_summary_lines] = i;
            num_summary_lines++;
        }
    }

    // print the summary
    printf("Summary:\n");
    for (int i = 0; i < num_summary_lines; i++) {
        printf("%s\n", lines[summary_indices[i]]);
    }

    // free memory
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }

    return 0;
}

// get the number of lines in a string
int get_num_lines(char* text) {
    int count = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (text[i] == '\n') {
            count++;
        }
    }
    return count + 1;
}

// split a string into individual lines
char** split_text_into_lines(char* text, int num_lines) {
    char** lines = malloc(sizeof(char*) * num_lines);
    char* token;
    int i = 0;
    token = strtok(text, "\n");
    while (token != NULL) {
        lines[i] = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(lines[i], token);
        i++;
        token = strtok(NULL, "\n");
    }
    return lines;
}