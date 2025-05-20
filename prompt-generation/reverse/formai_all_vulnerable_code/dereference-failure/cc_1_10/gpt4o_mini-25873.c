//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate checksum using additive method
unsigned long calculate_checksum(const char *input) {
    unsigned long checksum = 0;
    while (*input) {
        checksum += (unsigned char)(*input);
        input++;
    }
    return checksum;
}

// Function to read the content from a file
char *read_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(file_size + 1);
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0'; // Null-terminate the buffer
    fclose(file);
    return buffer;
}

// Function to write checksum result to a file
void write_checksum(const char *filename, unsigned long checksum) {
    char output_filename[256];
    snprintf(output_filename, sizeof(output_filename), "%s.checksum", filename);
    
    FILE *output_file = fopen(output_filename, "w");
    if (!output_file) {
        perror("Failed to create checksum file");
        return;
    }

    fprintf(output_file, "Checksum for file %s: %lu\n", filename, checksum);
    fclose(output_file);
}

// Function to display usage information
void display_usage() {
    printf("Usage: checksum_calculator <filename>\n");
    printf("Calculates the checksum of the specified file and stores the result in a .checksum file.\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Validate command line arguments
    if (argc != 2) {
        display_usage();
        return EXIT_FAILURE;
    }

    // Get the filename from the input argument
    const char *filename = argv[1];

    // Read the contents of the file
    char *file_content = read_file(filename);
    if (!file_content) {
        return EXIT_FAILURE;
    }

    // Calculate the checksum of the file content
    unsigned long checksum = calculate_checksum(file_content);
    
    // Clean up allocated memory
    free(file_content);

    // Write the checksum to a file
    write_checksum(filename, checksum);
    printf("Checksum for file '%s' calculated and saved successfully.\n", filename);

    return EXIT_SUCCESS;
}