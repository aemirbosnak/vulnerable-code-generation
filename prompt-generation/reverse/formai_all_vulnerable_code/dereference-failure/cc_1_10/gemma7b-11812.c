//Gemma-7B DATASET v1.0 Category: File handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[256];
    char buffer[4096];
    int read_size, write_size;

    printf("Enter file name:");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    printf("Enter read size:");
    scanf("%d", &read_size);

    printf("Enter write size:");
    scanf("%d", &write_size);

    read_size = fread(buffer, read_size, 1, fp);

    if (read_size > 0)
    {
        printf("Data read: %d bytes\n", read_size);
        printf("Enter write size:");
        scanf("%d", &write_size);

        write_size = fwrite(buffer, write_size, 1, fp);

        if (write_size > 0)
        {
            printf("Data written: %d bytes\n", write_size);
            printf("File modified successfully.\n");
        }
        else
        {
            perror("Error writing file");
            exit(1);
        }
    }
    else
    {
        perror("Error reading file");
        exit(1);
    }

    fclose(fp);

    return 0;
}