//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int is_palindrome(char *line) {
    int length = strlen(line);
    for (int i = 0; i < length / 2; i++) {
        if (line[i]!= line[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

void read_file(char *filename, char **lines) {
    FILE *file;
    char buffer[MAX_LINE_LENGTH];
    int line_count = 0;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: unable to open file %s\n", filename);
        exit(1);
    }
    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        lines[line_count++] = strdup(buffer);
    }
    fclose(file);
}

void write_file(char *filename, char **lines) {
    FILE *file;
    int i;
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: unable to open file %s\n", filename);
        exit(1);
    }
    for (i = 0; lines[i]!= NULL; i++) {
        fprintf(file, "%s\n", lines[i]);
    }
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s [input_file] [output_file]\n", argv[0]);
        exit(1);
    }
    char *input_filename = argv[1];
    char *output_filename = argv[2];
    char **lines;
    int line_count;
    read_file(input_filename, &lines);
    line_count = 0;
    while (lines[line_count]!= NULL) {
        if (is_palindrome(lines[line_count])) {
            fprintf(stdout, "%s\n", lines[line_count]);
            write_file(output_filename, &lines[line_count]);
        }
        line_count++;
    }
    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }
    free(lines);
    return 0;
}