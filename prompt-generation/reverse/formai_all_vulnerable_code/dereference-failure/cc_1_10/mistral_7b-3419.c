//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LEN 256

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <file_to_backup> <backup_file_name> <destination_directory>\n", argv[0]);
        return 1;
    }

    char file_to_backup[MAX_PATH_LEN];
    char backup_file_name[MAX_PATH_LEN];
    char destination_directory[MAX_PATH_LEN];
    strcpy(file_to_backup, argv[1]);
    strcpy(backup_file_name, argv[2]);
    strcpy(destination_directory, argv[3]);

    FILE *source_file = fopen(file_to_backup, "rb");
    if (!source_file) {
        perror("Error opening source file");
        return 1;
    }

    char *backup_file_path = (char *) malloc((strlen(destination_directory) + strlen(backup_file_name) + strlen(file_to_backup) + 3) * sizeof(char));
    strcpy(backup_file_path, destination_directory);
    strcat(backup_file_path, "/");
    strcat(backup_file_path, backup_file_name);

    FILE *backup_file = fopen(backup_file_path, "wb");
    if (!backup_file) {
        perror("Error opening backup file");
        free(backup_file_path);
        fclose(source_file);
        return 1;
    }

    char buffer[4096];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), source_file)) > 0) {
        if (fwrite(buffer, sizeof(char), bytes_read, backup_file) != bytes_read) {
            perror("Error writing to backup file");
            fclose(source_file);
            fclose(backup_file);
            free(backup_file_path);
            return 1;
        }
    }

    if (ferror(source_file)) {
        perror("Error reading from source file");
        fclose(backup_file);
        fclose(source_file);
        free(backup_file_path);
        return 1;
    }

    fclose(source_file);
    fclose(backup_file);
    free(backup_file_path);

    printf("File %s successfully backed up to %s\n", file_to_backup, backup_file_path);

    return 0;
}