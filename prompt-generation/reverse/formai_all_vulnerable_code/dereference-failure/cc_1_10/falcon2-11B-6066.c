//Falcon2-11B DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char buffer[1024];
    char *data;

    // Open the file for writing
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file for writing\n");
        return 1;
    }

    // Create a buffer to store the data to be written to the file
    data = (char *) malloc(1024 * sizeof(char));

    // Fill the buffer with some random data
    srand(time(NULL));
    for (int i = 0; i < 1024; i++) {
        data[i] = 'A' + rand() % 26;
    }

    // Write the data to the file
    fwrite(data, sizeof(char), 1024, fp);
    fclose(fp);

    // Open the file for reading
    fp = fopen("output.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file for reading\n");
        return 1;
    }

    // Create a buffer to store the data read from the file
    data = (char *) malloc(1024 * sizeof(char));

    // Read the data from the file into the buffer
    fread(data, sizeof(char), 1024, fp);

    // Close the file
    fclose(fp);

    // Print the data from the buffer
    printf("Read data: %s\n", data);

    // Free the memory
    free(data);

    return 0;
}