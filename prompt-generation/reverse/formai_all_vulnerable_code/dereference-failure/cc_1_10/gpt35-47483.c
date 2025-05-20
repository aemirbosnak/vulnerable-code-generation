//FormAI DATASET v1.0 Category: Data recovery tool ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1048576    // Maximum size in bytes of the file to be recovered
#define MAX_FILENAME_LENGTH 256  // Maximum length of the filename

unsigned char buffer[MAX_FILE_SIZE];  // Buffer to hold the file data

int main()
{
    FILE *file_ptr;   // Pointer to the file to be recovered
    char filename[MAX_FILENAME_LENGTH];  // String to hold the filename
    
    printf("Enter the name of the file to be recovered: ");
    scanf("%s", filename);
    
    file_ptr = fopen(filename, "rb");  // Open the file in binary mode for reading
    
    if (file_ptr == NULL)  // Check if the file exists
    {
        printf("Error: Unable to open the file.\n");
        exit(1);
    }
    
    fseek(file_ptr, 0, SEEK_END);  // Move the file pointer to the end of the file
    int file_size = ftell(file_ptr);  // Get the file size in bytes by finding the current position of the file pointer
    rewind(file_ptr);  // Move the file pointer back to the beginning of the file
    
    if (file_size > MAX_FILE_SIZE)  // Check if the file is too large
    {
        printf("Error: The file is too large.\n");
        exit(1);
    }
    
    fread(buffer, sizeof(char), file_size, file_ptr);  // Read the file data into the buffer
    fclose(file_ptr);  // Close the file
    
    FILE *recovery_file_ptr;   // Pointer to the file to be recovered
    char recovery_filename[MAX_FILENAME_LENGTH];  // String to hold the filename
    
    printf("Enter a name for the recovered file: ");
    scanf("%s", recovery_filename);
    
    recovery_file_ptr = fopen(recovery_filename, "wb");  // Open a new file in binary mode for writing
    
    if (recovery_file_ptr == NULL)  // Check if the file creation was successful
    {
        printf("Error: Unable to create the file.\n");
        exit(1);
    }
    
    fwrite(buffer, sizeof(char), file_size, recovery_file_ptr);  // Write the file data to the new file
    fclose(recovery_file_ptr);  // Close the new file
    
    printf("File recovery successful.\n");
    
    return 0;
}