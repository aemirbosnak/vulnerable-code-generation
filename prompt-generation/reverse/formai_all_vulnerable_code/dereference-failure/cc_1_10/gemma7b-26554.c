//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main() {

    char buffer[MAX_BUFFER_SIZE];
    char *c_meta_data = NULL;
    char *c_meta_data_ptr = NULL;
    int i = 0;
    int c_meta_data_size = 0;

    // Read the file containing the text with C metadata
    FILE *file = fopen("text.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Allocate memory for the C metadata
    c_meta_data = malloc(MAX_BUFFER_SIZE);
    if (c_meta_data == NULL) {
        perror("Error allocating memory");
        return EXIT_FAILURE;
    }

    // Read the file contents into the buffer
    int read_bytes = fread(buffer, 1, MAX_BUFFER_SIZE, file);
    if (read_bytes == 0) {
        perror("Error reading file");
        return EXIT_FAILURE;
    }

    // Search for the C metadata in the text
    c_meta_data_ptr = strstr(buffer, "C:");
    if (c_meta_data_ptr != NULL) {
        // Extract the C metadata and store it in the c_meta_data pointer
        c_meta_data_size = strlen(c_meta_data_ptr) + 1;
        c_meta_data = realloc(c_meta_data, c_meta_data_size);
        memcpy(c_meta_data, c_meta_data_ptr, c_meta_data_size);
    }

    // Print the C metadata
    if (c_meta_data_size > 0) {
        printf("C metadata:\n");
        printf("%s\n", c_meta_data);
    } else {
        printf("No C metadata found.\n");
    }

    // Free the memory allocated for the C metadata
    free(c_meta_data);

    // Close the file
    fclose(file);

    return EXIT_SUCCESS;
}