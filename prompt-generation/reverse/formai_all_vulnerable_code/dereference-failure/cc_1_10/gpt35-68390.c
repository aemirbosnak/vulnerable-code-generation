//FormAI DATASET v1.0 Category: HTML beautifier ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_SPACES 10

char* remove_leading_whitespace(char* line) {
    int i = 0;
    while (line[i] == ' ' || line[i] == '\t') {
        i++;
    }
    return &line[i];
}

char* remove_trailing_whitespace(char* line) {
    int i = strlen(line) - 1;
    while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' || line[i] == '\r') {
        i--;
    }
    line[i + 1] = '\0';
    return line;
}

int count_leading_spaces(char* line) {
    int i = 0;
    while (line[i] == ' ' || line[i] == '\t') {
        i++;
    }
    return i;
}

void add_spaces(char* line, int num_spaces) {
    int i;
    for (i = 0; i < num_spaces; i++) {
        strcat(line, " ");
    }
}

void print_line(char* line) {
    int i = 0;
    int num_spaces = count_leading_spaces(line);
    if (num_spaces > MAX_SPACES) {
        num_spaces = MAX_SPACES;
    }
    add_spaces(line, num_spaces);
    printf("%s\n", line);
}

void beautify_html(FILE* input_file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        char* new_line = remove_leading_whitespace(line);
        new_line = remove_trailing_whitespace(new_line);
        print_line(new_line);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_html_file>\n", argv[0]);
        exit(1);
    }
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Could not open file: %s\n", argv[1]);
        exit(1);
    }
    beautify_html(input_file);
    fclose(input_file);
    return 0;
}