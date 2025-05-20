//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define FILE_EXTENSION ".txt"

void recover_file(const char *file_path, const char *recovery_dir) {
    char command[MAX_PATH_LENGTH + 256];
    char output_path[MAX_PATH_LENGTH];

    snprintf(output_path, sizeof(output_path), "%s/recovered_%s", recovery_dir, strrchr(file_path, '/') + 1);
    
    snprintf(command, sizeof(command), "cp %s %s", file_path, output_path);
    
    printf("Recovering: %s to %s\n", file_path, output_path);
    int result = system(command);
    
    if (result == -1) {
        printf("Error recovering %s\n", file_path);
    }
}

void scan_directory(const char *directory, const char *recovery_dir) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dir = opendir(directory);

    if (!dir) {
        perror("Directory open failed");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", directory, entry->d_name);
        
        // Ignore '.' and '..'
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            if (stat(full_path, &file_stat) == 0) {
                if (S_ISREG(file_stat.st_mode)) {
                    if (strstr(entry->d_name, FILE_EXTENSION) != NULL) {
                        recover_file(full_path, recovery_dir);
                    }
                } else if (S_ISDIR(file_stat.st_mode)) {
                    // Recursively scan subdirectories
                    scan_directory(full_path, recovery_dir);
                }
            }
        }
    }
    closedir(dir);
}

void create_recovery_directory(const char *recovery_dir) {
    struct stat st = {0};
    if (stat(recovery_dir, &st) == -1) {
        mkdir(recovery_dir, 0700);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <directory_to_scan> <recovery_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_to_scan = argv[1];
    const char *recovery_directory = argv[2];
    
    create_recovery_directory(recovery_directory);

    printf("Scanning directory: %s\n", directory_to_scan);
    scan_directory(directory_to_scan, recovery_directory);

    printf("Recovery process completed!\n");
    return EXIT_SUCCESS;
}