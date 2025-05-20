//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 512
#define BUFFER_SIZE 1024

void compute_file_hash(FILE *file, unsigned long *hash) {
    int byte;
    *hash = 0;
    while ((byte = fgetc(file)) != EOF) {
        *hash = (*hash * 31) + byte;
    }
    rewind(file);
}

int compare_files(const char *src_path, const char *dest_path) {
    FILE *src_file = fopen(src_path, "rb");
    FILE *dest_file = fopen(dest_path, "rb");
    if (!src_file || !dest_file) {
        if (src_file) fclose(src_file);
        if (dest_file) fclose(dest_file);
        return -1; // Error opening files
    }

    unsigned long src_hash, dest_hash;
    compute_file_hash(src_file, &src_hash);
    compute_file_hash(dest_file, &dest_hash);

    fclose(src_file);
    fclose(dest_file);
    return (src_hash == dest_hash) ? 1 : 0; // 1 if equal, 0 if different
}

void copy_file(const char *src_path, const char *dest_path) {
    FILE *src_file = fopen(src_path, "rb");
    FILE *dest_file = fopen(dest_path, "wb");
    if (!src_file || !dest_file) {
        perror("Error opening files for copying");
        if (src_file) fclose(src_file);
        if (dest_file) fclose(dest_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
}

void synchronize_files(const char *src_dir, const char *dest_dir) {
    struct dirent *entry;
    DIR *src_directory = opendir(src_dir);
    if (!src_directory) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(src_directory)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files
        
        char src_path[MAX_PATH_LENGTH];
        char dest_path[MAX_PATH_LENGTH];
        snprintf(src_path, MAX_PATH_LENGTH, "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, MAX_PATH_LENGTH, "%s/%s", dest_dir, entry->d_name);

        struct stat src_stat, dest_stat;
        if (stat(src_path, &src_stat) == -1) {
            perror("Error getting source file status");
            continue;
        }

        int exists = stat(dest_path, &dest_stat);
        
        if (exists == -1) {
            // File doesn't exist in destination, copy it
            printf("Copying new file: %s to %s\n", src_path, dest_path);
            copy_file(src_path, dest_path);
        } else {
            // File exists, compare it
            if (compare_files(src_path, dest_path) == 0) {
                printf("Updating file: %s to %s\n", src_path, dest_path);
                copy_file(src_path, dest_path);
            } else {
                printf("Files are identical: %s <-> %s\n", src_path, dest_path);
            }
        }
    }
    closedir(src_directory);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *destination_dir = argv[2];
    
    // Print the directories being synchronized
    printf("Synchronizing:\nSource Directory: %s\nDestination Directory: %s\n", source_dir, destination_dir);
    
    synchronize_files(source_dir, destination_dir);
    return EXIT_SUCCESS;
}