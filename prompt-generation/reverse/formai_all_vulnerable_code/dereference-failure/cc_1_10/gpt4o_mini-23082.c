//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
unsigned int calculate_checksum(const char *data);
void display_usage(const char *program_name);
void process_file(const char *filename);
void free_resources(char *data_buffer);

int main(int argc, char *argv[]) {
    // Check for command line arguments
    if (argc < 2) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Process each file provided as argument
    for (int i = 1; i < argc; i++) {
        const char *filename = argv[i];
        process_file(filename);
    }

    return EXIT_SUCCESS;
}

void display_usage(const char *program_name) {
    printf("Usage: %s <file1> <file2> ... <fileN>\n", program_name);
    printf("Calculates and displays the checksum for each specified file.\n");
}

void process_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Allocate a buffer to hold file data
    char *data_buffer = NULL;
    size_t data_length = 0;
    
    // Read the file content into a buffer
    fseek(file, 0, SEEK_END);
    data_length = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    data_buffer = malloc(data_length);
    if (!data_buffer) {
        perror("Failed to allocate memory for file data");
        fclose(file);
        return;
    }

    fread(data_buffer, 1, data_length, file);
    fclose(file);

    // Calculate the checksum for the data
    unsigned int checksum = calculate_checksum(data_buffer);
    
    // Output the result
    printf("Checksum for '%s': %u\n", filename, checksum);

    // Free allocated memory
    free_resources(data_buffer);
}

unsigned int calculate_checksum(const char *data) {
    unsigned int checksum = 0;
    size_t length = strlen(data);

    for (size_t i = 0; i < length; i++) {
        checksum += (unsigned char)data[i];
    }
    
    return checksum;
}

void free_resources(char *data_buffer) {
    free(data_buffer);
}