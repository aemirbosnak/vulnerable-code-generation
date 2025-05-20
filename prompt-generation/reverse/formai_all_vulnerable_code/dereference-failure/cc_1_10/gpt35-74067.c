//FormAI DATASET v1.0 Category: HTML beautifier ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void remove_leading_space(char* line) {
    int i = 0;
    while (line[i] == ' ' || line[i] == '\t') {
        i++;
    }
    memmove(line, line + i, strlen(line) - i + 1);
}

void add_indentation(FILE* output_file, int indentation_level) {
    int i;
    for (i = 0; i < indentation_level; i++) {
        fprintf(output_file, "\t");
    }
}

int main() {
    char input_file_name[50];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);

    FILE* input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Failed to open the input file.");
        return 0;
    }

    char output_file_name[50];
    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);

    FILE* output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Failed to open the output file.");
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    int indentation_level = 0;

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        remove_leading_space(line);

        if (strstr(line, "</") != NULL) {
            indentation_level--;
        }

        add_indentation(output_file, indentation_level);
        fputs(line, output_file);

        if (strstr(line, "/>") == NULL && strstr(line, "</") == NULL && strstr(line, "<") != NULL) {
            indentation_level++;
        }
    }

    fclose(input_file);
    fclose(output_file);

    printf("Beautification complete.");

    return 0;
}