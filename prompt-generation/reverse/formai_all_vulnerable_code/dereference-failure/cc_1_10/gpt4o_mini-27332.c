//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define BUFFER_SIZE 1024
#define MAX_PATH_LENGTH 1024

void create_directory(const char *dir) {
    if (mkdir(dir, 0755) == -1) {
        perror("Error creating directory");
        exit(EXIT_FAILURE);
    }
}

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (src == NULL) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }
    
    FILE *dest = fopen(destination, "wb");
    if (dest == NULL) {
        fclose(src);
        perror("Error opening destination file");
        exit(EXIT_FAILURE);
    }
    
    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }
    
    fclose(src);
    fclose(dest);
}

void backup_files(const char *source_dir, const char *backup_dir) {
    DIR *dir = opendir(source_dir);
    if (dir == NULL) {
        perror("Error opening source directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {  // Check if it's a regular file
            char source_path[MAX_PATH_LENGTH];
            char backup_path[MAX_PATH_LENGTH];
            snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
            snprintf(backup_path, sizeof(backup_path), "%s/%s", backup_dir, entry->d_name);
            copy_file(source_path, backup_path);
            printf("Copied: %s -> %s\n", source_path, backup_path);
        }
    }
    
    closedir(dir);
}

void backup_directory(const char *source_dir, const char *backup_dir) {
    create_directory(backup_dir);
    backup_files(source_dir, backup_dir);
}

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <source_directory> <backup_directory>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *backup_dir = argv[2];
    
    backup_directory(source_dir, backup_dir);
    printf("Backup completed successfully!\n");

    return EXIT_SUCCESS;
}