//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE 100000
#define MAX_BUFFER_SIZE 1024

// Global variables
FILE *file_ptr;
char buffer[MAX_BUFFER_SIZE];
int bytes_read = 0;
int bytes_written = 0;

// Function to open a file in write mode
void open_file(const char *file_name)
{
    file_ptr = fopen(file_name, "w");
    if (file_ptr == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
}

// Function to read a file line by line
void read_file(const char *file_name)
{
    file_ptr = fopen(file_name, "r");
    if (file_ptr == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, MAX_BUFFER_SIZE, file_ptr) != NULL) {
        // Process the line here
        printf("%s\n", buffer);
    }

    fclose(file_ptr);
}

// Function to write a file line by line
void write_file(const char *file_name)
{
    file_ptr = fopen(file_name, "a");
    if (file_ptr == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, MAX_BUFFER_SIZE, stdin) != NULL) {
        fputs(buffer, file_ptr);
        bytes_written += strlen(buffer);
    }

    fclose(file_ptr);
}

int main()
{
    // Open a file in write mode
    open_file("example.txt");

    // Write some data to the file
    write_file("This is a test file written by me.\n");

    // Read the file line by line
    read_file("example.txt");

    // Calculate the file size
    printf("File size: %d bytes\n", bytes_written);

    // Close the file
    fclose(file_ptr);

    return 0;
}