//Falcon-180B DATASET v1.0 Category: Educational ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    fgets(line, MAX_LINE_LENGTH, file);
    line[strcspn(line, "\n")] = '\0';
    return line;
}

void write_line(FILE *file, const char *line) {
    fprintf(file, "%s\n", line);
}

int is_palindrome(const char *str) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (tolower(str[i])!= tolower(str[j])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Unable to open input file\n");
        return 1;
    }

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        fprintf(stderr, "Unable to open output file\n");
        return 1;
    }

    char *line;
    while ((line = read_line(input_file))!= NULL) {
        if (is_palindrome(line)) {
            write_line(output_file, line);
        }
        free(line);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}