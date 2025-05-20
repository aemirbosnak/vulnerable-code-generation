//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

char *beautify(char *input) {
    char *output = malloc(MAX_LINE_LENGTH);
    char *ptr = output;
    int indent_level = 0;

    for (char *c = input; *c!= 0; c++) {
        if (*c == '<') {
            indent_level++;
        } else if (*c == '>') {
            indent_level--;
        } else if (*c == '\n') {
            *ptr = 0;
            printf("%s", output);
            ptr = output;
            for (int i = 0; i < indent_level; i++) {
                strcat(ptr, "    ");
            }
        } else {
            strcat(ptr, c);
        }
        ptr += strlen(ptr);
        if (ptr - output >= MAX_LINE_LENGTH) {
            *ptr = 0;
            printf("%s", output);
            ptr = output;
        }
    }
    return output;
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s [input_file] [output_file]\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char *beautified_line = beautify(line);
        fprintf(output_file, "%s", beautified_line);
        free(beautified_line);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}