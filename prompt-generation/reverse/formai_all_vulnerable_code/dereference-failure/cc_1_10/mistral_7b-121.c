//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_BACKUP_FILE_NAME_LENGTH 128
#define BACKUP_EXTENSION ".bak"

void backup_file(char *file_name) {
    char backup_file_name[MAX_BACKUP_FILE_NAME_LENGTH];
    int source_file, backup_file;
    off_t file_size;
    char *buffer;

    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, BACKUP_EXTENSION);

    source_file = open(file_name, O_RDONLY);
    if (source_file < 0) {
        perror("Error opening file for backup: ");
        return;
    }

    file_size = lseek(source_file, 0, SEEK_END);
    buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Error allocating memory for file buffer: ");
        close(source_file);
        return;
    }

    lseek(source_file, 0, SEEK_SET);
    read(source_file, buffer, file_size);

    backup_file = open(backup_file_name, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (backup_file < 0) {
        perror("Error creating backup file: ");
        free(buffer);
        close(source_file);
        return;
    }

    write(backup_file, buffer, file_size);
    printf("File '%s' successfully backed up to '%s'\n", file_name, backup_file_name);

    free(buffer);
    close(source_file);
    close(backup_file);
}

int main(int argc, char **argv) {
    int i;

    if (argc < 2) {
        printf("Usage: %s <file_name>...\n", argv[0]);
        return 1;
    }

    for (i = 1; i < argc; i++) {
        backup_file(argv[i]);
    }

    return 0;
}