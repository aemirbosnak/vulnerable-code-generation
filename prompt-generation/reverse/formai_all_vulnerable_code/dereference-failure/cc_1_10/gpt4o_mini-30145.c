//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define BACKUP_DIR "backup"

// Function to create a directory if it doesn't exist
void create_backup_directory() {
    struct stat st = {0};

    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0700);
    }
}

// Function to copy a file from source to destination
int copy_file(const char *src, const char *dest) {
    FILE *source = fopen(src, "rb");
    if (!source) {
        perror("Failed to open source file");
        return -1;
    }

    FILE *destination = fopen(dest, "wb");
    if (!destination) {
        perror("Failed to open destination file");
        fclose(source);
        return -1;
    }

    char buffer[4096];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
    return 0;
}

// Function to backup files with a specific extension from the current directory
void backup_files(const char *extension) {
    DIR *dir;
    struct dirent *ent;
    char src[MAX_PATH];
    char dest[MAX_PATH];

    if ((dir = opendir(".")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strstr(ent->d_name, extension)) {
                snprintf(src, sizeof(src), "./%s", ent->d_name);
                snprintf(dest, sizeof(dest), "./%s/%s", BACKUP_DIR, ent->d_name);

                if (copy_file(src, dest) == 0) {
                    printf("Successfully backed up: %s to %s\n", src, dest);
                } else {
                    printf("Failed to back up: %s\n", src);
                }
            }
        }
        closedir(dir);
    } else {
        perror("Could not open directory");
        exit(EXIT_FAILURE);
    }
}

// Function to display the usage of the program
void display_usage() {
    printf("File Backup System\n");
    printf("Usage: ./backup <file_extension>\n");
    printf("Example: ./backup .txt\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage();
        return EXIT_FAILURE;
    }

    char *file_extension = argv[1];

    // Create the backup directory
    create_backup_directory();

    // Backup files with the specified extension
    backup_files(file_extension);

    return EXIT_SUCCESS;
}