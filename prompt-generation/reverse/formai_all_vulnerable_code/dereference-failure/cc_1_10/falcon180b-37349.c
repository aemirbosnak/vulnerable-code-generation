//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 100
#define MAX_BACKUP_DIR_LENGTH 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char backup_dir[MAX_BACKUP_DIR_LENGTH];
} file_backup_t;

void backup_file(char* filename, char* backup_dir) {
    char backup_filename[MAX_FILENAME_LENGTH];
    strcpy(backup_filename, backup_dir);
    strcat(backup_filename, "/");
    strcat(backup_filename, filename);

    FILE* backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL) {
        printf("Error: Could not open backup file %s\n", backup_filename);
        exit(1);
    }

    FILE* input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file %s\n", filename);
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, 1024, input_file)!= NULL) {
        fputs(buffer, backup_file);
    }

    fclose(input_file);
    fclose(backup_file);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <backup_dir>\n", argv[0]);
        exit(1);
    }

    char* input_file = argv[1];
    char* backup_dir = argv[2];

    backup_file(input_file, backup_dir);

    printf("Backup of %s to %s complete!\n", input_file, backup_dir);

    return 0;
}