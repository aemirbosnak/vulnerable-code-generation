//Falcon-180B DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_NUM_LINES 1000

typedef struct {
    char* line;
    int line_num;
} Line;

void read_file(const char* filename, Line* lines, int* num_lines) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        exit(1);
    }

    int line_num = 0;
    while (fgets(lines[line_num].line, MAX_LINE_LENGTH, file)!= NULL) {
        line_num++;
        if (line_num >= MAX_NUM_LINES) {
            printf("Error: File %s is too large.\n", filename);
            exit(1);
        }
    }

    fclose(file);
    *num_lines = line_num;
}

void write_file(const char* filename, Line* lines, int num_lines) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", filename);
        exit(1);
    }

    for (int i = 0; i < num_lines; i++) {
        fputs(lines[i].line, file);
        free(lines[i].line);
    }

    fclose(file);
}

void sort_lines(Line* lines, int num_lines) {
    for (int i = 0; i < num_lines - 1; i++) {
        for (int j = i + 1; j < num_lines; j++) {
            if (strcmp(lines[i].line, lines[j].line) > 0) {
                char* temp = lines[i].line;
                lines[i].line = lines[j].line;
                lines[j].line = temp;

                int temp_num = lines[i].line_num;
                lines[i].line_num = lines[j].line_num;
                lines[j].line_num = temp_num;
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    char* input_filename = argv[1];
    char* output_filename = argv[2];

    Line lines[MAX_NUM_LINES];
    int num_lines;

    read_file(input_filename, lines, &num_lines);

    sort_lines(lines, num_lines);

    write_file(output_filename, lines, num_lines);

    printf("File sorted successfully.\n");

    return 0;
}