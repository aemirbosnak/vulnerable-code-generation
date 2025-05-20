//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define BUFFER_SIZE 1024

// Function to read data from a file
char *read_file(const char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the data
    char *data = malloc(file_size + 1);
    if (data == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    // Read the data from the file
    fread(data, 1, file_size, fp);
    data[file_size] = '\0';

    // Close the file
    fclose(fp);

    // Return the data
    return data;
}

// Function to write data to a file
int write_file(const char *filename, const char *data) {
    // Open the file
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Write the data to the file
    fwrite(data, 1, strlen(data), fp);

    // Close the file
    fclose(fp);

    return 0;
}

// Function to search for a string in a file
char *search_file(const char *filename, const char *search_string) {
    // Read the file into memory
    char *data = read_file(filename);
    if (data == NULL) {
        return NULL;
    }

    // Search for the string in the data
    char *result = strstr(data, search_string);

    // Free the memory allocated for the data
    free(data);

    // Return the result
    return result;
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        printf("Usage: %s <filename> <search_string>\n", argv[0]);
        return 1;
    }

    // Get the filename and search string from the command line arguments
    char *filename = argv[1];
    char *search_string = argv[2];

    // Search for the string in the file
    char *result = search_file(filename, search_string);

    // Check if the string was found
    if (result == NULL) {
        printf("String not found.\n");
    } else {
        printf("String found at offset %ld.\n", result - read_file(filename));
    }

    return 0;
}