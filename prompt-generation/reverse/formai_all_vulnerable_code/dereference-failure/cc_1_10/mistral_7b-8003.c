//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILENAME_LENGTH 100
#define BACKUP_SUFFIX "_backup"

void backup_file(const char *source_file_path) {
    char destination_file_path[MAX_PATH_LENGTH];
    FILE *source_file, *destination_file;
    int bytes_read;

    strcpy(destination_file_path, source_file_path);
    strcat(destination_file_path, BACKUP_SUFFIX);

    source_file = fopen(source_file_path, "rb");
    if (source_file == NULL) {
        perror("Error opening source file:");
        return;
    }

    destination_file = fopen(destination_file_path, "wb");
    if (destination_file == NULL) {
        perror("Error creating backup file:");
        fclose(source_file);
        return;
    }

    while ((bytes_read = fread(destination_file, 1, 1, source_file)) > 0) {
        if (ferror(destination_file)) {
            perror("Error writing to backup file:");
            fclose(source_file);
            fclose(destination_file);
            return;
        }
    }

    if (ferror(source_file)) {
        perror("Error reading source file:");
        fclose(destination_file);
        fclose(source_file);
        return;
    }

    fclose(source_file);
    fclose(destination_file);

    printf("File '%s' backed up successfully to '%s'\n", source_file_path, destination_file_path);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source_file>\n", argv[0]);
        return 1;
    }

    backup_file(argv[1]);

    return 0;
}