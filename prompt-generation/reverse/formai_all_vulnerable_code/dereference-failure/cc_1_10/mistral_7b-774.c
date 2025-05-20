//MISTRAL-7B DATASET v1.0 Category: File Synchronizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define BUFFER_SIZE 128

typedef struct {
    char line[MAX_LINE_LENGTH];
    int line_number;
} Line;

void print_differences(FILE *file1, FILE *file2) {
    Line buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    int i, j, lines_read1 = 0, lines_read2 = 0;

    while (fgets(buffer1[lines_read1].line, MAX_LINE_LENGTH, file1) != NULL &&
           fgets(buffer2[lines_read2].line, MAX_LINE_LENGTH, file2) != NULL) {
        lines_read1++;
        lines_read2++;

        if (strcmp(buffer1[lines_read1 - 1].line, buffer2[lines_read2 - 1].line) != 0) {
            printf("\033[1;31mDifference at line %d in file1:\033[0m\n%s\n",
                   buffer1[lines_read1 - 1].line_number, buffer1[lines_read1 - 1].line);

            printf("\033[1;31mDifference at line %d in file2:\033[0m\n%s\n",
                   buffer2[lines_read2 - 1].line_number, buffer2[lines_read2 - 1].line);

            while (fgets(buffer2[lines_read2].line, MAX_LINE_LENGTH, file2) != NULL &&
                   strcmp(buffer1[lines_read1].line, buffer2[lines_read2].line) != 0) {
                printf("\033[1;31m      + in file2:\033[0m %s", buffer2[lines_read2].line);
                lines_read2++;
            }

            while (fgets(buffer1[lines_read1].line, MAX_LINE_LENGTH, file1) != NULL &&
                   strcmp(buffer1[lines_read1].line, buffer2[lines_read2 - 1].line) != 0) {
                printf("\033[1;31m      - in file1:\033[0m %s", buffer1[lines_read1].line);
                lines_read1++;
            }

            if (lines_read1 >= BUFFER_SIZE || lines_read2 >= BUFFER_SIZE) {
                printf("\033[1;31mError: buffer overflow\033[0m");
                break;
            }
        }
    }

    if (feof(file1) || feof(file2)) {
        if (ferror(file1)) {
            perror("Error reading file1");
            exit(EXIT_FAILURE);
        }

        if (ferror(file2)) {
            perror("Error reading file2");
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");

    if (file1 == NULL || file2 == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    print_differences(file1, file2);

    fclose(file1);
    fclose(file2);

    return EXIT_SUCCESS;
}