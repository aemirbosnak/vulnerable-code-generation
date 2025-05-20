//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to scan file for virus signatures
void scanFile(char* filename)
{
    // Open file in read mode
    FILE *file = fopen(filename, "r");
    
    // Check if file exists
    if (file == NULL) {
        printf("%s is not found.\n", filename);
        return;
    }
    
    // Size of the file
    fseek(file, 0, SEEK_END);
    long int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // Maximum length of the signature
    const int SIGNATURE_LENGTH = 5;
    
    // Virus signatures
    char *signatures[] = {"virus", "trojan", "malware", "worm", "spyware"};
    
    // Iterate through the file to check for virus signatures
    long int i = 0;
    while (i < fileSize - SIGNATURE_LENGTH + 1)
    {
        char buffer[SIGNATURE_LENGTH];
        fread(buffer, SIGNATURE_LENGTH, 1, file);
        
        for (int j = 0; j < SIGNATURE_LENGTH; j++) {
            buffer[j] = tolower(buffer[j]);
        }
        
        for (int j = 0; j < sizeof(signatures) / sizeof(signatures[0]); j++)
        {
            if (strcmp(signatures[j], buffer) == 0)
            {
                printf("Virus signature '%s' detected in %s\n", signatures[j], filename);
                fclose(file);
                return;
            }
        }
        
        fseek(file, ++i, SEEK_SET);
    }
    
    // No virus signature found
    printf("%s is clean.\n", filename);
    
    // Close the file
    fclose(file);
}

int main()
{
    // Test cases
    scanFile("testfile.txt");
    scanFile("virusfile.exe");
    
    return 0;
}