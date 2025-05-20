//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 10000000 // 10MB
#define BUFFER_SIZE 1024

typedef struct {
    char filename[100];
    char backup_filename[200];
    time_t timestamp;
} BackupFile;

void backup_file(char* filename) {
    BackupFile backup_file;
    strcpy(backup_file.filename, filename);
    strcat(backup_file.backup_filename, ".bak");
    strcat(backup_file.backup_filename, filename);
    time(&backup_file.timestamp);

    FILE* backup_fp = fopen(backup_file.backup_filename, "wb");
    if (backup_fp == NULL) {
        printf("Error: could not create backup file\n");
        exit(1);
    }

    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file for reading\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, backup_fp);
    }

    fclose(fp);
    fclose(backup_fp);

    printf("File backed up successfully: %s\n", backup_file.backup_filename);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage:./backup_system <filename>\n");
        return 1;
    }

    backup_file(argv[1]);

    return 0;
}