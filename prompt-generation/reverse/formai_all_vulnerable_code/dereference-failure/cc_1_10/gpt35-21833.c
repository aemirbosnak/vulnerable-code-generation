//FormAI DATASET v1.0 Category: Data recovery tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

void recoverData(FILE *file, char *filename)
{
    char buffer[MAX_FILE_SIZE];
    size_t fileSize = 0;
    
    // Read file into buffer
    fileSize = fread(buffer, sizeof(char), MAX_FILE_SIZE, file);
    
    // Identify signature of file
    char jpgSignature[] = {0xff, 0xd8, 0xff, 0xe0};
    char pngSignature[] = {0x89, 0x50, 0x4E, 0x47};
    
    for (int i = 0; i < fileSize; i++)
    {
        // Look for JPG signature
        if (memcmp(&buffer[i], jpgSignature, sizeof(jpgSignature)) == 0)
        {
            // Create new file with .jpg extension
            char newFilename[strlen(filename) + 5];
            sprintf(newFilename, "%s.jpg", filename);
            FILE *newFile = fopen(newFilename, "wb");
            
            // Write contents to new file
            fwrite(&buffer[i], sizeof(char), fileSize - i, newFile);
            
            // Close new file
            fclose(newFile);
            
            // Terminate function
            return;
        }
        
        // Look for PNG signature
        if (memcmp(&buffer[i], pngSignature, sizeof(pngSignature)) == 0)
        {
            // Create new file with .png extension
            char newFilename[strlen(filename) + 5];
            sprintf(newFilename, "%s.png", filename);
            FILE *newFile = fopen(newFilename, "wb");
            
            // Write contents to new file
            fwrite(&buffer[i], sizeof(char), fileSize - i, newFile);
            
            // Close new file
            fclose(newFile);
            
            // Terminate function
            return;
        }
    }
    
    // If no signature found, print error message
    printf("Error: Signature not found in file.\n");
}

int main(int argc, char *argv[])
{
    // Open file
    FILE *file = fopen(argv[1], "rb");
    
    if (file == NULL)
    {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    
    // Create copy of filename without extension
    char *filename = strdup(argv[1]);
    char *dot = strrchr(filename, '.');
    if (dot)
    {
        *dot = '\0';
    }
    
    // Call data recovery function
    recoverData(file, filename);
    
    // Close file and free memory
    fclose(file);
    free(filename);
    
    return 0;
}