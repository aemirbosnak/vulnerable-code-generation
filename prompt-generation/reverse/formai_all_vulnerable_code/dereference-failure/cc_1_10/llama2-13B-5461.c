//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>

#define BUFFER_SIZE 4096
#define MAX_PATH 1024

// Structure to hold file information
typedef struct {
    char name[MAX_PATH];
    size_t size;
    time_t mod_time;
} file_info_t;

// Function to read a file and return its contents as a string
char* read_file(const char* path) {
    // Open the file in read mode
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the file contents
    char* contents = calloc(1, size + 1);
    if (contents == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    // Read the file into the allocated memory
    size_t bytes_read = fread(contents, 1, size, file);
    if (bytes_read != size) {
        perror("Error reading file");
        free(contents);
        fclose(file);
        return NULL;
    }

    // Close the file
    fclose(file);

    return contents;
}

// Function to write a file and return its contents as a string
char* write_file(const char* path, const char* contents) {
    // Open the file in write mode
    FILE* file = fopen(path, "w");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Write the contents to the file
    size_t bytes_written = fwrite(contents, 1, strlen(contents), file);
    if (bytes_written != strlen(contents)) {
        perror("Error writing file");
        fclose(file);
        return NULL;
    }

    // Close the file
    fclose(file);

    return contents;
}

int main() {
    // Get the current time
    time_t now = time(NULL);

    // Create a directory for the files
    if (mkdir("files", 0755) != 0) {
        perror("Error creating directory");
        return 1;
    }

    // Create a list of files to write
    char* files[] = {"file1.txt", "file2.txt", "file3.txt"};
    size_t files_count = sizeof(files) / sizeof(files[0]);

    // Loop through the files and write them to the directory
    for (size_t i = 0; i < files_count; i++) {
        char* file_name = files[i];
        char* contents = "This is a sample file\n";

        // Write the file to the directory
        char* written_contents = write_file(file_name, contents);
        if (written_contents == NULL) {
            perror("Error writing file");
            return 1;
        }

        // Print the contents of the file
        printf("File %s contains:\n%s\n", file_name, written_contents);

        // Wait for 1 second to avoid overwriting the file too quickly
        sleep(1);
    }

    // Loop through the files and read them from the directory
    for (size_t i = 0; i < files_count; i++) {
        char* file_name = files[i];
        char* contents = read_file(file_name);
        if (contents == NULL) {
            perror("Error reading file");
            return 1;
        }

        // Print the contents of the file
        printf("File %s contains:\n%s\n", file_name, contents);

        // Free the memory allocated for the file contents
        free(contents);
    }

    return 0;
}