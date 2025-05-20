//FormAI DATASET v1.0 Category: Data recovery tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to recover lost data from a corrupted file
void recover_data(char *filename) {
    FILE *fp;
    char buffer[1024];
    size_t bytes_read;
    char *data = NULL;
    size_t size = 0;
 
    fp = fopen(filename, "rb"); // Open the file in binary read mode
 
    if(fp == NULL) {
        printf("Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
 
    while((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), fp)) > 0) {
        size += bytes_read;
        data = realloc(data, size);
        if(data == NULL) {
            printf("Unable to allocate memory\n");
            exit(EXIT_FAILURE);
        }
        strcat(data, buffer);
    }
 
    if(ferror(fp)) { // Check for file read error
        printf("Error reading file %s\n", filename);
        free(data);
        exit(EXIT_FAILURE);
    }
 
    fclose(fp);
 
    // Now the lost data has been recovered. You can do whatever you want with it.
    printf("Recovered data from file %s:\n%s\n", filename, data);
    free(data); // Free the dynamically allocated memory
}

int main() {
    char filename[100];
 
    printf("Enter the name of the file to recover data from: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove the trailing newline character
 
    recover_data(filename);
 
    return 0;
}