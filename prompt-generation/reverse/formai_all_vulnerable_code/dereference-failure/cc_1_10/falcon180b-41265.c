//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    int indentation;
} Line;

void print_line(Line line) {
    printf("%*s%s\n", line.indentation, "", line.line);
}

void indent(int amount) {
    printf("%*s", amount, "");
}

int main(int argc, char **argv) {
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen("output.html", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    int indentation = 0;
    Line current_line = {0};
    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, input_file)!= NULL) {
        if (buffer[0] == '<') {
            indentation++;
        } else if (buffer[0] == '>') {
            indentation--;
        }
        if (indentation >= 0) {
            strcat(current_line.line, buffer);
        } else {
            print_line(current_line);
            strcpy(current_line.line, buffer);
        }
    }
    print_line(current_line);

    fclose(input_file);
    fclose(output_file);

    return 0;
}