//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the checksum of a given string
unsigned int calculate_checksum(const char *data) {
    unsigned int checksum = 0;
    while (*data) {
        checksum += (unsigned char)*data;  // Add the ASCII value of each character
        data++;
    }
    return checksum;
}

// Function to read input data from a file
char* read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }
    
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *content = (char *)malloc(length + 1);
    if (!content) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }
    
    fread(content, 1, length, file);
    content[length] = '\0'; // Null-terminate the string
    
    fclose(file);
    return content;
}

// Function to write the checksum to a file
void write_checksum_to_file(const char *filename, unsigned int checksum) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    
    fprintf(file, "Checksum: %u\n", checksum);
    fclose(file);
}

// Main program to execute checksum calculation
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    char *input_file = argv[1];
    char *output_file = argv[2];
    
    // Read content from the input file
    char *data = read_file(input_file);
    if (!data) return EXIT_FAILURE;

    // Calculate the checksum
    unsigned int checksum = calculate_checksum(data);
    printf("Calculated Checksum: %u\n", checksum);

    // Write the checksum to the output file
    write_checksum_to_file(output_file, checksum);

    // Clean up and exit
    free(data);
    printf("Checksum written to %s successfully.\n", output_file);
    return EXIT_SUCCESS;
}