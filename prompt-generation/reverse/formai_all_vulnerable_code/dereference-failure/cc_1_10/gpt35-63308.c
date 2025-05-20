//FormAI DATASET v1.0 Category: HTML beautifier ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

bool is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

void remove_whitespace(char* str) {
    int i, j = 0;
    for (i = 0; str[i]; i++) {
        if (!is_whitespace(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void beautify_html(FILE* input_file, FILE* output_file) {
    char current_line[MAX_LINE_LENGTH];
    char previous_line[MAX_LINE_LENGTH];
    bool inside_tag = false;
    int indent_level = 0;

    while (fgets(current_line, MAX_LINE_LENGTH, input_file) != NULL) {
        remove_whitespace(current_line);

        if (strcmp(current_line, "") == 0) {
            continue;
        }

        if (strstr(current_line, "</") != NULL) {
            indent_level--;
        }

        if (inside_tag) {
            fprintf(output_file, "\n");
        }

        for (int i = 0; i < indent_level; i++) {
            fprintf(output_file, "\t");
        }

        fprintf(output_file, "%s", current_line);

        if (strstr(current_line, "/>") != NULL) {
            continue;
        }

        if (strstr(current_line, "<") != NULL && strstr(current_line, "</") == NULL) {
            indent_level++;
        }

        inside_tag = (strstr(current_line, "/>") == NULL && strstr(current_line, "</") == NULL);
        strcpy(previous_line, current_line);
    }

    fprintf(output_file, "\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Invalid number of arguments. Usage: html_beautifier input_file output_file\n");
        return 1;
    }

    char* input_file_path = argv[1];
    char* output_file_path = argv[2];

    FILE* input_file = fopen(input_file_path, "r");
    FILE* output_file = fopen(output_file_path, "w");

    if (input_file == NULL) {
        printf("Could not open input file %s\n", input_file_path);
        return 1;
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}