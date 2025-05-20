//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Ken Thompson
#include <stdio.h>

unsigned short calculate_checksum(unsigned char* buffer, int length);

int main()
{
    FILE* file = fopen("example.txt", "rb");

    if (!file)
    {
        printf("Could not open file!");
        return 1;
    }

    // go to the end of the file to determine its size
    fseek(file, 0L, SEEK_END);
    int file_size = ftell(file);

    if (file_size == 0)
    {
        printf("File is empty!");
        return 1;
    }

    rewind(file); // go back to the beginning of the file

    unsigned char* buffer = (unsigned char*) malloc(file_size * sizeof(unsigned char));

    if (!buffer)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    // read the entire file into memory
    fread(buffer, file_size, 1, file);
    fclose(file);

    unsigned short checksum = calculate_checksum(buffer, file_size);

    printf("Checksum: %X", checksum);

    free(buffer);

    return 0;
}

unsigned short calculate_checksum(unsigned char* buffer, int length)
{
    unsigned short checksum = 0;

    while (length > 1)
    {
        checksum += *((unsigned short*) buffer);

        buffer += 2;
        length -= 2;
    }

    if (length == 1)
    {
        checksum += *((unsigned char*) buffer);
    }

    while (checksum >> 16)
    {
        checksum = (checksum & 0xFFFF) + (checksum >> 16);
    }

    return ~checksum;
}