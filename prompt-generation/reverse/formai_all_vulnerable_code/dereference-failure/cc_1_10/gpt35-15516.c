//FormAI DATASET v1.0 Category: File Backup System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BACKUP_FILES 10

void print_header(const char* filename);
int backup_file(const char* filename, const char* backup_path);

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* filename = argv[1];
    char backup_path[MAX_FILENAME_LENGTH];

    snprintf(backup_path, sizeof(backup_path), "%s.backup", filename);

    int num_backups = backup_file(filename, backup_path);

    printf("Created %d backups of %s\n", num_backups, filename);

    return 0;
}

void print_header(const char* filename) {
    time_t current_time;
    time(&current_time);

    printf("Backup of %s at %s\n", filename, ctime(&current_time));
}

int backup_file(const char* filename, const char* backup_path) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    FILE* backup_file = fopen(backup_path, "w");

    if (backup_file == NULL) {
        fprintf(stderr, "Error creating backup file %s: %s\n", backup_path, strerror(errno));
        exit(EXIT_FAILURE);
    }

    print_header(filename);

    char buffer[MAX_FILENAME_LENGTH];

    int num_backups = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        fputs(buffer, backup_file);
    }

    fclose(file);
    fclose(backup_file);

    return num_backups;
}