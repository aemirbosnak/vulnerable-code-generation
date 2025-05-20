//FormAI DATASET v1.0 Category: Data recovery tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 // Maximum file size to be read

// Function to recover data from file
void recoverData(char *filename)
{
    FILE *file_ptr;
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;
    
    // Open file in read-only mode
    file_ptr = fopen(filename, "r");
    
    if (file_ptr == NULL)
    {
        fprintf(stderr, "Error: Cannot open file '%s'.\n", filename);
        exit(EXIT_FAILURE);
    }
    
    // Read file contents into buffer
    bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file_ptr);
    
    if (bytes_read == 0)
    {
        fprintf(stderr, "Error: File '%s' is empty.\n", filename);
        exit(EXIT_FAILURE);
    }
    
    // Close file
    fclose(file_ptr);
    
    // Print recovered data
    printf("Recovered data from file '%s':\n%s\n", filename, buffer);
}

int main()
{
    char filename[100];
    
    printf("Enter file name to recover data from: ");
    scanf("%s", filename);
    
    // Ensure file name is less than or equal to 100 characters
    if (strlen(filename) > 100)
    {
        fprintf(stderr, "Error: File name length exceeds limit.\n");
        exit(EXIT_FAILURE);
    }
    
    recoverData(filename);
    
    return 0;
}