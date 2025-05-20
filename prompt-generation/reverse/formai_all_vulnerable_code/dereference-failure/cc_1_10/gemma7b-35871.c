//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1024

void backup_file(char *filename)
{
    FILE *fp, *fp_backup;
    char *buffer, *backup_filename;
    int file_size, read_size, write_size;

    // Allocate memory for buffer and backup filename
    buffer = malloc(MAX_FILE_SIZE);
    backup_filename = malloc(MAX_FILE_SIZE);

    // Get the file size
    fp = fopen(filename, "r");
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);

    // Create a backup filename
    sprintf(backup_filename, "backup/%s.bak", filename);

    // Open a backup file
    fp_backup = fopen(backup_filename, "w");

    // Read and write data
    read_size = 0;
    while (read_size < file_size)
    {
        read_size += fread(buffer, 1, MAX_FILE_SIZE, fp);
        write_size = fwrite(buffer, 1, read_size, fp_backup);
    }

    // Close files
    fclose(fp);
    fclose(fp_backup);

    // Free memory
    free(buffer);
    free(backup_filename);
}

int main()
{
    char *filename;

    // Get the filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Backup the file
    backup_file(filename);

    // Print a success message
    printf("File backup successful!\n");

    return 0;
}