//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB

int main() {
    // Open the file
    FILE *file = fopen("book.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the file contents
    char *file_contents = malloc(file_size + 1); // +1 for the null-terminator
    if (file_contents == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Read the file contents
    size_t bytes_read = fread(file_contents, 1, file_size, file);
    if (bytes_read != file_size) {
        perror("Error reading file");
        fclose(file);
        free(file_contents);
        return EXIT_FAILURE;
    }

    // Null-terminate the file contents
    file_contents[file_size] = '\0';

    // Close the file
    fclose(file);

    // Print the file contents
    printf("%s", file_contents);

    // Free the memory
    free(file_contents);

    return EXIT_SUCCESS;
}