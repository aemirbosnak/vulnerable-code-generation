//FormAI DATASET v1.0 Category: HTML beautifier ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 2000

void print_usage() {
    printf("Usage: html_beautifier [input file] [output file]\n");
}

void beautify_html(char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE* output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    int indent_level = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input) != NULL) {
        if (strstr(line, "</") != NULL) {
            indent_level--;
        }

        for (int i = 0; i < indent_level; i++) {
            fprintf(output, "    ");
        }

        fprintf(output, "%s", line);

        if (strstr(line, "<") != NULL && strstr(line, "</") == NULL) {
            indent_level++;
        }
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_usage();
        exit(1);
    }

    char* input_file = argv[1];
    char* output_file = argv[2];

    beautify_html(input_file, output_file);

    printf("HTML beautification complete!\n");

    return 0;
}