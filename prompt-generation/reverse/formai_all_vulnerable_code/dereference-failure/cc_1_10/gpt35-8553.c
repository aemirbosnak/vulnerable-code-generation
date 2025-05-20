//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    FILE *fp;

    char *line;
    ssize_t read;
    size_t len = 0;

    // Open CSV file
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Read header line
    if ((read = getline(&line, &len, fp)) != -1) {
        printf("CSV Header: %s", line);
    } else {
        fprintf(stderr, "Error: Failed to read header line.\n");
        exit(EXIT_FAILURE);
    }

    // Read data lines
    while ((read = getline(&line, &len, fp)) != -1) {
        char *token, *string, *tofree;
        tofree = string = strdup(line);

        // Extract tokens
        while ((token = strsep(&string, ","))) {
            printf("%s\t", token);
        }

        printf("\n");
        free(tofree);
    }

    // Cleanup
    fclose(fp);
    if (line) {
        free(line);
    }

    return 0;
}