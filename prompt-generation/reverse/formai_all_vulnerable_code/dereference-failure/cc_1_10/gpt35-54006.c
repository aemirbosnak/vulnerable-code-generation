//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Donald Knuth
/* Donald Knuth style C Checksum Calculator Example Program */
/* By: [Your Name] */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the checksum function */
int checksum(char *string, int length) {
    int sum = 0, i;
    for (i = 0; i < length; i++) {
        sum += string[i];
    }
    return sum;
}

int main(int argc, char **argv) {
    /* Declare variables */
    char *filename, *buffer;
    int length, sum;

    /* Check if filename was provided */
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    /* Open the file */
    filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    /* Calculate the length of the file */
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);

    /* Allocate memory for the buffer */
    buffer = malloc(length + 1);

    /* Read the file into the buffer */
    fread(buffer, 1, length, file);

    /* Close the file */
    fclose(file);

    /* Calculate the checksum */
    sum = checksum(buffer, length);

    printf("Checksum for file %s is: %d\n", filename, sum);

    /* Free the memory allocated for the buffer */
    free(buffer);

    return 0;
}