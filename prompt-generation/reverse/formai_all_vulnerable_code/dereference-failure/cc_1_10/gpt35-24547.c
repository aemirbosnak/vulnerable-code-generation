//FormAI DATASET v1.0 Category: Image Classification system ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    FILE *file;
    unsigned char *buffer;
    unsigned long fileLen;

    //Open file
    file = fopen(argv[1], "rb");
    if (!file)
    {
        fprintf(stderr, "Unable to open file %s", argv[1]);
        return 1;
    }

    //Get file length
    fseek(file, 0, SEEK_END);
    fileLen=ftell(file);
    fseek(file, 0, SEEK_SET);

    //Allocate memory
    buffer=(unsigned char *)malloc(fileLen+1);
    if (!buffer)
    {
        fprintf(stderr, "Memory error!");
        fclose(file);
        return 1;
    }

    //Read file contents into buffer
    fread(buffer, fileLen, 1, file);
    fclose(file);

    //Determine image type based on file contents
    if (strstr(buffer, "GIF87a") || strstr(buffer, "GIF89a"))
    {
        printf("%s is a GIF image.\n", argv[1]);
    }
    else if (strstr(buffer, "\xff\xd8\xff") == buffer)
    {
        printf("%s is a JPEG image.\n", argv[1]);
    }
    else if (strstr(buffer, "\x89PNG\r\n\x1a\n") == buffer)
    {
        printf("%s is a PNG image.\n", argv[1]);
    }
    else if (strstr(buffer, "BM") == buffer)
    {
        printf("%s is a BMP image.\n", argv[1]);
    }
    else
    {
        printf("%s is an unrecognized image format.\n", argv[1]);
    }

    free(buffer);
    return 0;
}