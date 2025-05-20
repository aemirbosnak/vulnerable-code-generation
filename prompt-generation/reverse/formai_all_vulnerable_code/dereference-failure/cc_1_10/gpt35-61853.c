//FormAI DATASET v1.0 Category: File Backup System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_BUFFER_SIZE   1024

void backup_file(char *file_path, char *backup_path)
{
    FILE *src_file;
    FILE *dst_file;
    char buffer[MAX_BUFFER_SIZE];
    size_t bytes_read;

    src_file = fopen(file_path, "rb");
    if (!src_file)
    {
        fprintf(stderr, "Error opening file '%s': %s\n", file_path, strerror(errno));
        exit(EXIT_FAILURE);
    }

    dst_file = fopen(backup_path, "wb");
    if (!dst_file)
    {
        fprintf(stderr, "Error creating backup file '%s': %s\n", backup_path, strerror(errno));
        fclose(src_file);
        exit(EXIT_FAILURE);
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) != 0)
        fwrite(buffer, 1, bytes_read, dst_file);

    fclose(src_file);
    fclose(dst_file);

    printf("File '%s' backed up successfully to '%s'\n", file_path, backup_path);
}

int main(int argc, char **argv)
{
    char file_path[MAX_FILE_NAME_LEN];
    char backup_path[MAX_FILE_NAME_LEN];

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <file_path> <backup_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strncpy(file_path, argv[1], sizeof(file_path));
    file_path[sizeof(file_path) - 1] = '\0';

    strncpy(backup_path, argv[2], sizeof(backup_path));
    backup_path[sizeof(backup_path) - 1] = '\0';

    backup_file(file_path, backup_path);

    return 0;
}