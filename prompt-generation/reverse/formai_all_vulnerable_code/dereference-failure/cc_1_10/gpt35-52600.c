//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_VIRUS_SIGNATURE_LENGTH 32

int main()
{
    char filename[MAX_FILENAME_LENGTH];
    char signature[MAX_VIRUS_SIGNATURE_LENGTH];
    int signature_length;
    
    printf("Enter the filename to scan: ");
    scanf("%s", filename);
    
    printf("Enter the virus signature to search for: ");
    scanf("%s", signature);
    signature_length = strlen(signature);
    
    FILE* file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Could not open file: %s\n", filename);
        return 1;
    }
    
    fseek(file, 0, SEEK_END);
    long int file_size = ftell(file);
    rewind(file);
    
    char* buffer = (char*)calloc(1, file_size);
    fread(buffer, file_size, 1, file);
    fclose(file);
    
    int virus_found = 0;
    for (int i = 0; i < file_size - signature_length; i++)
    {
        if (memcmp(buffer + i, signature, signature_length) == 0)
        {
            printf("Virus signature found at offset %d\n", i);
            virus_found = 1;
            break;
        }
    }
    
    free(buffer);
    
    if (!virus_found)
    {
        printf("No viruses found\n");
    }
    
    return 0;
}