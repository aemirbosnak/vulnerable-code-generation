//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 255

typedef unsigned char Byte;

Byte calculate_checksum(Byte* data, size_t size)
{
    Byte checksum = 0;
    
    for (size_t i = 0; i < size; ++i)
    {
        checksum = (checksum << 1) | (checksum >> 7);
        checksum += data[i];
    }
    
    return checksum;
}

int main()
{
    printf("Welcome to the Cyberpunk Checksum Calculator!\n");
    printf("Please enter the name of the file to calculate the checksum for:\n");
    
    char filename[MAX_BUFFER_SIZE];
    fgets(filename, MAX_BUFFER_SIZE, stdin);
    filename[strcspn(filename, "\n")] = 0;
    
    FILE* file = fopen(filename, "rb");
    
    if (file == NULL)
    {
        printf("ERROR: Failed to open file \"%s\"\n", filename);
        return EXIT_FAILURE;
    }
    
    fseek(file, 0L, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0L, SEEK_SET);
    
    Byte* buffer = (Byte*) malloc(sizeof(Byte) * file_size);
    
    fread(buffer, sizeof(Byte), file_size, file);
    fclose(file);
    
    Byte checksum = calculate_checksum(buffer, file_size);
    
    printf("The checksum for file \"%s\" is: %d\n", filename, checksum);
    
    free(buffer);
    
    return EXIT_SUCCESS;
}