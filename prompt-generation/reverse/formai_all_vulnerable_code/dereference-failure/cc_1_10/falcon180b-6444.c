//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *text;
    int length;
} Line;

void add_line(Line **lines, int *num_lines, char *text) {
    int length = strlen(text);
    Line *new_line = (Line *)malloc(sizeof(Line));
    new_line->text = (char *)malloc(length + 1);
    strcpy(new_line->text, text);
    new_line->length = length;
    (*lines)[*num_lines] = *new_line;
    (*num_lines)++;
}

void print_lines(Line *lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i].text);
    }
}

int main() {
    FILE *input_file;
    char *input_filename = "input.html";
    char *output_filename = "output.html";
    char line[MAX_LINE_LENGTH];
    Line *lines = NULL;
    int num_lines = 0;

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        add_line(&lines, &num_lines, line);
    }

    fclose(input_file);

    FILE *output_file;
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    for (int i = 0; i < num_lines; i++) {
        if (lines[i].length > 0) {
            fprintf(output_file, "%s\n", lines[i].text);
        }
    }

    fclose(output_file);

    return 0;
}