//Falcon-180B DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char data[MAX_LINE_LENGTH];
    int length;
} Line;

void read_file(FILE* file, Line* lines, int* line_count) {
    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        lines[*line_count] = (Line) {
           .data = strdup(buffer),
           .length = strlen(buffer)
        };
        (*line_count)++;
    }
}

void write_file(FILE* file, Line* lines, int line_count) {
    for (int i = 0; i < line_count; i++) {
        fprintf(file, "%s\n", lines[i].data);
    }
}

void reverse_lines(Line* lines, int line_count) {
    for (int i = 0; i < line_count / 2; i++) {
        Line temp = lines[i];
        lines[i] = lines[line_count - i - 1];
        lines[line_count - i - 1] = temp;
    }
}

int main() {
    char input_filename[100];
    char output_filename[100];

    printf("Enter input file name: ");
    scanf("%s", input_filename);

    printf("Enter output file name: ");
    scanf("%s", output_filename);

    FILE* input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    int line_count = 0;
    Line* lines = malloc(sizeof(Line) * 1000); // Allocate memory for up to 1000 lines

    read_file(input_file, lines, &line_count);

    reverse_lines(lines, line_count);

    FILE* output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    write_file(output_file, lines, line_count);

    fclose(input_file);
    fclose(output_file);

    printf("File reversed successfully!\n");

    return 0;
}