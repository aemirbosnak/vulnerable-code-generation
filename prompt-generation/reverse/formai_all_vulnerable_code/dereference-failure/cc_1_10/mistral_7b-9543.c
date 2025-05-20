//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 256
#define MAX_FILE_NAME 100
#define BACKUP_EXTENSION ".bak"

void create_backup_file(char *file_path, char *backup_file_path);
void write_to_backup(FILE *input_file, FILE *output_file, char *file_name);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char file_path[MAX_PATH];
    strcpy(file_path, argv[1]);

    char backup_file_path[MAX_PATH];
    strcpy(backup_file_path, file_path);
    strcat(backup_file_path, BACKUP_EXTENSION);

    create_backup_file(file_path, backup_file_path);

    FILE *input_file = fopen(file_path, "r");
    FILE *output_file = fopen(backup_file_path, "w");

    if (input_file == NULL || output_file == NULL)
    {
        printf("Error opening files.\n");
        return 1;
    }

    write_to_backup(input_file, output_file, file_path);

    fclose(input_file);
    fclose(output_file);

    printf("File backup created: %s\n", backup_file_path);

    return 0;
}

void create_backup_file(char *file_path, char *backup_file_path)
{
    FILE *backup_file = fopen(backup_file_path, "w");

    if (backup_file != NULL)
    {
        fclose(backup_file);
    }
    else
    {
        perror("Error creating backup file.");
        return;
    }
}

void write_to_backup(FILE *input_file, FILE *output_file, char *file_name)
{
    char buffer[1024];
    size_t bytes_read;

    do
    {
        bytes_read = fread(buffer, sizeof(char), sizeof(buffer), input_file);

        if (bytes_read > 0)
        {
            fwrite(buffer, sizeof(char), bytes_read, output_file);
        }
    } while (bytes_read > 0);
}