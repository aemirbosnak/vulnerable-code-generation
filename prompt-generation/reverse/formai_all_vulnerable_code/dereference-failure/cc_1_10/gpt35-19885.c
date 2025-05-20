//FormAI DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 255

char* generate_backup_filename(const char* filename) {
    char* backup_filename = malloc(sizeof(char) * (MAX_FILENAME_LENGTH + 1));
    memset(backup_filename, 0, sizeof(char) * (MAX_FILENAME_LENGTH + 1));

    time_t current_time;
    time(&current_time);
    struct tm* time_info = localtime(&current_time);

    char timestamp[20] = { 0 };
    strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", time_info);

    int len = snprintf(backup_filename, MAX_FILENAME_LENGTH + 1, "%s-%s.bak", filename, timestamp);
    if (len > MAX_FILENAME_LENGTH) {
        printf("Warning! Filename too long. Truncating...\n");
        backup_filename[MAX_FILENAME_LENGTH - 1] = '\0';
    }

    return backup_filename;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: backup <filename>\n");
        return 1;
    }

    const char* filename = argv[1];

    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: could not open file: %s\n", filename);
        return 2;
    }

    char* backup_filename = generate_backup_filename(filename);
    FILE* backup_file = fopen(backup_filename, "wb");
    if (!backup_file) {
        printf("Error: could not create backup file: %s\n", backup_filename);
        fclose(file);
        free(backup_filename);
        return 3;
    }

    size_t nread = 0;
    char buffer[1024];

    while ((nread = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        size_t nwritten = fwrite(buffer, 1, nread, backup_file);
        if (nwritten != nread) {
            printf("Error: could not write to backup file: %s\n", backup_filename);
            fclose(file);
            fclose(backup_file);
            free(backup_filename);
            return 4;
        }
    }

    fclose(file);
    fclose(backup_file);
    free(backup_filename);

    printf("Backup successful!\n");

    return 0;
}