//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hurray! Let's calculate the checksum of a file.\n");

    FILE *file;
    unsigned char *buffer;
    unsigned long fileLen;
    int checksum = 0;

    // open the file
    file = fopen("example.txt", "rb");
    if (!file)
    {
        printf("Oops! Can't open file. Please make sure the filename is correct.\n");
        return 1;
    }

    // get the filesize
    fseek(file, 0, SEEK_END);
    fileLen = ftell(file);
    rewind(file);

    // allocate memory for the buffer
    buffer = (unsigned char *)malloc(fileLen * sizeof(unsigned char));
    if (!buffer)
    {
        printf("Oops! Can't allocate memory for buffer.\n");
        return 1;
    }

    // read the file into the buffer
    fread(buffer, fileLen, 1, file);

    // calculate the checksum
    for (int i = 0; i < fileLen; i++)
    {
        checksum += (int)buffer[i];
    }

    // print the checksum
    printf("Yay! The checksum of the file is: %d\n", checksum);

    // free memory and close the file
    free(buffer);
    fclose(file);

    return 0;
}