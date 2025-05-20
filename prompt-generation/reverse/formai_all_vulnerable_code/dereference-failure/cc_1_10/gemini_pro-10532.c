//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define ERRBUF_SIZE 1024

/*
 * Custom error handling function that takes a filename and a line number as arguments
 * and prints the error message corresponding to the global errno variable.
 */
void handle_error(const char *filename, int line) {
    char errbuf[ERRBUF_SIZE];

    /* Get the error message corresponding to the global errno variable. */
    strerror_r(errno, errbuf, ERRBUF_SIZE);

    /* Print the error message along with the filename and line number. */
    fprintf(stderr, "Error in %s:%d: %s\n", filename, line, errbuf);

    /* Exit the program with an error code. */
    exit(EXIT_FAILURE);
}

/*
 * Function to demonstrate how to handle errors using a custom error handling function.
 */
void test_error_handling() {
    FILE *fp;

    /* Try to open a file that does not exist. */
    fp = fopen("nonexistent_file.txt", "r");

    /* If the file could not be opened, handle the error. */
    if (fp == NULL) {
        handle_error(__FILE__, __LINE__);
    }

    /* ... */

    /* Close the file. */
    fclose(fp);
}

/*
 * Main function.
 */
int main() {
    test_error_handling();

    return 0;
}