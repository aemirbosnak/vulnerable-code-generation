//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    FILE *dest = fopen(destination, "wb");
    
    if (src == NULL) {
        fprintf(stderr, "Error opening source file: %s\n", source);
        exit(EXIT_FAILURE);
    }
    
    if (dest == NULL) {
        fclose(src);
        fprintf(stderr, "Error opening destination file: %s\n", destination);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
    printf("Copied %s to %s\n", source, destination);
}

void create_backup_folder(const char *backup_directory) {
    struct stat st = {0};

    if (stat(backup_directory, &st) == -1) {
        if (mkdir(backup_directory, 0700) != 0) {
            fprintf(stderr, "Failed to create backup directory: %s\n", backup_directory);
            exit(EXIT_FAILURE);
        }
        printf("Backup directory created: %s\n", backup_directory);
    } else {
        printf("Backup directory already exists: %s\n", backup_directory);
    }
}

void backup_files(const char *directory, const char *backup_directory) {
    struct dirent *de;
    DIR *dr = opendir(directory);

    if (dr == NULL) {
        fprintf(stderr, "Could not open directory: %s\n", directory);
        exit(EXIT_FAILURE);
    }

    while ((de = readdir(dr)) != NULL) {
        if (de->d_type == DT_REG) { // If it's a regular file
            char source_path[BUFFER_SIZE];
            char dest_path[BUFFER_SIZE];

            snprintf(source_path, sizeof(source_path), "%s/%s", directory, de->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", backup_directory, de->d_name);
            copy_file(source_path, dest_path);
        }
    }

    closedir(dr);
}

int main() {
    char source_directory[BUFFER_SIZE];
    char backup_directory[BUFFER_SIZE];

    printf("Enter the source directory to backup: ");
    fgets(source_directory, sizeof(source_directory), stdin);
    source_directory[strcspn(source_directory, "\n")] = 0; // Remove newline

    printf("Enter the backup directory: ");
    fgets(backup_directory, sizeof(backup_directory), stdin);
    backup_directory[strcspn(backup_directory, "\n")] = 0; // Remove newline

    create_backup_folder(backup_directory);
    backup_files(source_directory, backup_directory);

    printf("Backup completed successfully!\n");
    return 0;
}