//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_SIZE 100

void my_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void read_line(FILE *fp, char *line, size_t size) {
    size_t bytes_read = 0;
    if (getline(&line, &size, fp) < 0) {
        if (errno != EOF) {
            my_error("Error reading line: ");
        }
    }
    if (strlen(line) >= MAX_LINE_SIZE - 1) {
        my_error("Line too long: ");
        free(line);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    int sum = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        my_error("Error opening file: ");
    }

    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        int num;
        char *endptr;

        num = strtol(line, &endptr, 10);
        if (errno == ERANGE) {
            my_error("Invalid number: ");
            fclose(fp);
            exit(EXIT_FAILURE);
        }

        if (errno != 0) {
            my_error("Error converting string to number: ");
            fclose(fp);
            exit(EXIT_FAILURE);
        }

        sum += num;
    }

    fclose(fp);

    printf("Sum of numbers in file: %d\n", sum);

    return EXIT_SUCCESS;
}