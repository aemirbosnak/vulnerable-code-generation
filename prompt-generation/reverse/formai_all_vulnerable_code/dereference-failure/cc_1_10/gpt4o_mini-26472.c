//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 4096

void backup_file(const char *source_file) {
    char backup_file[MAX_PATH];
    snprintf(backup_file, sizeof(backup_file), "%s.bak", source_file);

    FILE *source = fopen(source_file, "rb");
    if (source == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE *backup = fopen(backup_file, "wb");
    if (backup == NULL) {
        perror("Error creating backup file");
        fclose(source);
        return;
    }

    char buffer[1024];
    size_t bytes;
    
    // Copy data
    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, backup);
    }

    fclose(source);
    fclose(backup);

    printf("Backup created for file: %s\n", source_file);
}

void backup_directory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char path[MAX_PATH];
            snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

            struct stat statbuf;
            if (stat(path, &statbuf) == -1) {
                perror("Error getting file stats");
                continue;
            }

            if (S_ISDIR(statbuf.st_mode)) {
                backup_directory(path);  // Recursive call for directories
            } else if (S_ISREG(statbuf.st_mode)) {
                backup_file(path);  // Backup the file
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    backup_directory(argv[1]);  // Start the backup process
    return EXIT_SUCCESS;
}