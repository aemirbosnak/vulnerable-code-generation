//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *input_file;
    char filename[50];
    char buffer[BUFFER_SIZE];
    char *data;
    int filesize;
    int checksum;

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the input file
    input_file = fopen(filename, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Get the file size
    fseek(input_file, 0, SEEK_END);
    filesize = ftell(input_file);
    rewind(input_file);

    // Allocate memory for the file data
    data = (char *) malloc(filesize);
    if (data == NULL) {
        printf("Error: Could not allocate memory for file data.\n");
        exit(1);
    }

    // Read the file data into memory
    fread(data, filesize, 1, input_file);

    // Calculate the checksum
    checksum = 0;
    for (int i = 0; i < filesize; i++) {
        checksum += data[i];
    }

    // Close the input file
    fclose(input_file);

    // Display the checksum
    printf("Checksum: %d\n", checksum);

    // Free the memory allocated for the file data
    free(data);

    return 0;
}