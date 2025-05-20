//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LINE 1024
#define FILENAME "example.txt"

int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer[MAX_LINE];
    char *end;
    int num;
    int ret;
    struct stat file_stat;

    // Open the file with error checking
    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read from the file with error checking
    while (fgets(buffer, MAX_LINE, fp) != NULL) {
        num = strtol(buffer, &end, 10);
        if (errno == ERANGE) {
            fprintf(stderr, "Invalid number: %s\n", buffer);
            exit(EXIT_FAILURE);
        }

        // Check if the number is even
        if (num % 2 != 0) {
            fprintf(stderr, "Invalid number: %d is odd\n", num);
            exit(EXIT_FAILURE);
        }

        // Print the number if it's even
        printf("Even number: %d\n", num);
    }

    // Check if the end of the file was reached
    if (feof(fp)) {
        printf("End of file reached\n");
    } else {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }

    // Close the file with error checking
    ret = fclose(fp);
    if (ret != 0) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    // Check file size with error checking
    ret = stat(FILENAME, &file_stat);
    if (ret != 0) {
        perror("Error getting file size");
        exit(EXIT_FAILURE);
    }

    printf("File size: %ld bytes\n", file_stat.st_size);

    return EXIT_SUCCESS;
}