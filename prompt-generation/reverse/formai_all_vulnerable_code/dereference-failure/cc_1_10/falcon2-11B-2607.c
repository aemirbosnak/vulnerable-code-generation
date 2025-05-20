//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    unsigned char signature[4] = {0x50, 0x4b, 0x03, 0x04};
    unsigned char buffer[1024];
    int bytes_read = fread(buffer, 1, sizeof(buffer), file);

    if (bytes_read == 0)
    {
        fprintf(stderr, "Error reading file: %s\n", argv[1]);
        return 1;
    }

    if (memcmp(buffer, signature, sizeof(buffer)) == 0)
    {
        printf("File is uncorrupted\n");
        return 0;
    }

    int corrupt_bytes = bytes_read % sizeof(buffer);
    int i;
    for (i = 0; i < corrupt_bytes; i++)
    {
        buffer[i] = signature[i];
    }

    fseek(file, 0, SEEK_SET);
    fwrite(buffer, 1, sizeof(buffer), file);

    fclose(file);

    return 0;
}