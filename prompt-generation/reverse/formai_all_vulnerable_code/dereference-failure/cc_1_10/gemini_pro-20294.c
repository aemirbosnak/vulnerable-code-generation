//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the checksum function
unsigned short checksum(unsigned char *data, unsigned int len) {
    unsigned short sum = 0;
    int i;

    // Iterate over the data
    for (i = 0; i < len; i++) {
        // Add the current byte to the sum
        sum += data[i];
    }

    // Return the sum
    return sum;
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check if the user has provided a filename
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the data
    unsigned char *data = malloc(file_size);
    if (data == NULL) {
        perror("malloc");
        return 1;
    }

    // Read the data from the file
    fread(data, 1, file_size, fp);

    // Close the file
    fclose(fp);

    // Calculate the checksum
    unsigned short checksum_value = checksum(data, file_size);

    // Print the checksum
    printf("Checksum: %04X\n", checksum_value);

    // Free the memory
    free(data);

    return 0;
}