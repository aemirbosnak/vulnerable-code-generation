//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the checksum
unsigned int calculate_checksum(const char *data) {
    unsigned int checksum = 0;
    int length = strlen(data);
    for (int i = 0; i < length; i++) {
        checksum += (unsigned char)data[i];
    }
    return checksum;
}

// Function to read input data from a file or STDIN
char *read_input_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open input file");
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
    
    size_t bytes_read = fread(buffer, sizeof(char), file_size, file);
    buffer[bytes_read] = '\0';
    
    fclose(file);
    return buffer;
}

// Function to display the checksum result
void display_checksum(const char *data, unsigned int checksum) {
    printf("Data: \"%s\"\n", data);
    printf("Checksum: %u\n", checksum);
}

// Main function
int main(int argc, char *argv[]) {
    char *data = NULL;
    
    // Check if the user provided a file name
    if (argc > 1) {
        data = read_input_file(argv[1]);
        if (!data) {
            return EXIT_FAILURE; // Error when reading file
        }
    } else {
        // Reading from standard input if no file is provided
        printf("Enter data for checksum calculation (EOF to end):\n");
        
        size_t buffer_size = 1024;
        data = (char *)malloc(buffer_size);
        
        if (!data) {
            perror("Failed to allocate memory for input");
            return EXIT_FAILURE;
        }
        
        ssize_t bytes_in = 0;
        while (fgets(data + bytes_in, buffer_size - bytes_in, stdin)) {
            bytes_in += strlen(data + bytes_in);
            if (bytes_in >= buffer_size - 1) {
                buffer_size *= 2; // Increase buffer size
                data = realloc(data, buffer_size);
                if (!data) {
                    perror("Failed to reallocate memory");
                    return EXIT_FAILURE;
                }
            }
        }
        data[bytes_in] = '\0'; // Null-terminate the string
    }

    // Calculate the checksum
    unsigned int checksum = calculate_checksum(data);
    
    // Display the result
    display_checksum(data, checksum);
    
    // Cleanup
    free(data);
    return EXIT_SUCCESS;
}