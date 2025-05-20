//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backup_system(char *filename)
{
    FILE *fp, *fp_backup;
    char *backup_filename;
    int size, i;

    backup_filename = (char *)malloc(strlen(filename) + 10);
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fp_backup = fopen(backup_filename, "w");
    if (fp_backup == NULL)
    {
        printf("Error opening file: %s\n", backup_filename);
        fclose(fp);
        exit(1);
    }

    size = 0;
    i = 0;
    while (!feof(fp))
    {
        char buffer[1024];
        int read_size = fread(buffer, 1, 1024, fp);
        fwrite(buffer, 1, read_size, fp_backup);
        size += read_size;
        i++;
    }

    fclose(fp);
    fclose(fp_backup);

    printf("File %s successfully backed up. Total size: %d bytes, %d lines\n", filename, size, i);
}

int main()
{
    backup_system("my_file.txt");
    return 0;
}