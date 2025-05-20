//FormAI DATASET v1.0 Category: File Backup System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1024

char* get_timestamp() {
    time_t current_time = time(NULL);
    char* timestamp = malloc(sizeof(char) * 20);
    strftime(timestamp, 20, "%Y%m%d%H%M%S", localtime(&current_time));
    return timestamp;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // Get filename and extension
    char* filename = strdup(argv[1]);
    char* extension = strrchr(filename, '.');

    if (extension == NULL) {
        printf("Invalid filename. Must include extension.\n");
        exit(1);
    }

    // Get timestamp
    char* timestamp = get_timestamp();

    // Construct backup filename
    char* backup_filename = malloc(sizeof(char) * (strlen(filename) + strlen(timestamp) + 6));
    strncpy(backup_filename, filename, extension - filename);
    backup_filename[extension - filename] = '\0';
    strcat(backup_filename, "-");
    strcat(backup_filename, timestamp);
    strcat(backup_filename, ".bak");

    // Open files
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    FILE* backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL) {
        printf("Error creating backup file: %s\n", backup_filename);
        exit(1);
    }

    // Copy contents from original file to backup file
    char buffer[MAX_SIZE];
    size_t nread;
    while ((nread = fread(buffer, 1, MAX_SIZE, file)) > 0) {
        fwrite(buffer, 1, nread, backup_file);
    }

    // Close files and free memory
    fclose(file);
    fclose(backup_file);
    free(filename);
    free(backup_filename);
    free(timestamp);

    printf("Backup created: %s\n", backup_filename);

    return 0;
}