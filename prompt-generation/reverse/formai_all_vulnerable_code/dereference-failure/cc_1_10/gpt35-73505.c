//FormAI DATASET v1.0 Category: Data recovery tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // Get file name from command line argument
    if (argc < 2) {
        printf("Usage: %s <file name>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];

    // Open file for reading
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    // Determine file size
    fseek(file, 0L, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    // Allocate buffer for file contents
    char *data = (char *) malloc(file_size * sizeof(char));

    // Read file contents into buffer
    size_t bytes_read = fread(data, sizeof(char), file_size, file);
    if (bytes_read != file_size) {
        printf("Error: could not read file %s\n", filename);
        return 1;
    }

    // Check for corruption
    int corruption_count = 0;
    for (size_t i = 0; i < file_size; i++) {
        if (data[i] == '\0') {
            corruption_count++;
        }
    }

    // If file is corrupt, attempt data recovery
    if (corruption_count > 0) {
        printf("Warning: file %s is corrupt (%d null bytes)\n", filename, corruption_count);
        printf("Attempting data recovery...\n");

        // Replace null bytes with a random character
        for (size_t i = 0; i < file_size; i++) {
            if (data[i] == '\0') {
                data[i] = rand() % 256;
            }
        }

        // Save recovered data to new file
        char *new_filename = "recovered.dat";
        FILE *new_file = fopen(new_filename, "wb");
        if (new_file == NULL) {
            printf("Error: could not create file %s\n", new_filename);
            return 1;
        }

        fwrite(data, sizeof(char), file_size, new_file);
        fclose(new_file);

        printf("Data recovery successful. Recovered data saved to %s\n", new_filename);
    }
    else {
        printf("File %s is not corrupt\n", filename);
    }

    // Clean up
    free(data);
    fclose(file);

    return 0;
}