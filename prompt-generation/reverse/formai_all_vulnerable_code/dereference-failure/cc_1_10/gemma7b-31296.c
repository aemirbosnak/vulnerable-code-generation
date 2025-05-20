//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1024

void backup_file(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return;
    }

    long file_size = 0;
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    char *buffer = malloc(file_size);
    if (buffer == NULL)
    {
        printf("Error allocating memory: %s\n", filename);
        return;
    }

    int read_size = fread(buffer, 1, file_size, fp);
    if (read_size != file_size)
    {
        printf("Error reading file: %s\n", filename);
        return;
    }

    fclose(fp);

    FILE *bp = fopen("backup.txt", "a");
    if (bp == NULL)
    {
        printf("Error opening file: backup.txt\n");
        return;
    }

    fprintf(bp, "%s\n", filename);
    fwrite(buffer, 1, file_size, bp);

    fclose(bp);

    free(buffer);
}

int main()
{
    backup_file("my_file.txt");
    backup_file("another_file.doc");

    return 0;
}