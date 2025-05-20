//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    system("clear");
    printf("C File Backup System\n");
    printf("------------------------\n");

    char filename[256];
    printf("Enter file name: ");
    scanf("%s", filename);

    struct stat stat_buf;
    stat(filename, &stat_buf);

    if (stat_buf.st_size > 100000)
    {
        printf("File size too large. Maximum size is 100 KB.\n");
        return 1;
    }

    char backup_filename[256];
    sprintf(backup_filename, "backup/%s.bak", filename);

    FILE *backup_file = fopen(backup_filename, "w");

    if (backup_file == NULL)
    {
        printf("Error backing up file.\n");
        return 1;
    }

    FILE *file_file = fopen(filename, "r");

    if (file_file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    unsigned char buffer[4096];

    while (!feof(file_file))
    {
        int read_bytes = read(fileno(file_file), buffer, 4096);
        fwrite(buffer, read_bytes, 1, backup_file);
    }

    fclose(file_file);
    fclose(backup_file);

    printf("File successfully backed up.\n");

    return 0;
}