//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 2048

void read_file(char *filename) {
    FILE *fp;
    char buffer[MAX_LINE];
    int line_number = 0;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, MAX_LINE, fp) != NULL) {
        line_number++;
        printf("Line %d: %s", line_number, buffer);
    }

    fclose(fp);
}

void write_file(char *filename, char *data) {
    FILE *fp;

    fp = fopen(filename, "w");

    if (fp == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%s", data);
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <read|write> <filename> <data|line_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *operation = argv[1];
    char *filename = argv[2];

    if (strcmp(operation, "read") == 0) {
        read_file(filename);
    } else if (strcmp(operation, "write") == 0) {
        if (argc != 5) {
            printf("Usage: %s write <filename> <data>\n", argv[0]);
            exit(EXIT_FAILURE);
        }

        char *data = argv[4];
        write_file(filename, data);
    } else {
        printf("Invalid operation. Use read or write.\n");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}