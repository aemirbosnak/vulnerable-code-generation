//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_LEN 256

// Function to compare file sizes
int compare_file_size(const char *file1, const char *file2) {
    struct stat st1, st2;
    if (stat(file1, &st1) == -1 || stat(file2, &st2) == -1) {
        perror("stat");
        return -1;
    }
    
    return st1.st_size - st2.st_size;
}

// Function to copy a file from source to destination
void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    FILE *dst = fopen(destination, "wb");
    
    if (!src || !dst) {
        perror("File open error");
        return;
    }

    char buffer[4096];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, n, dst);
    }

    fclose(src);
    fclose(dst);
}

// Function to synchronize the files in destination directory with the source
void sync_files(const char *source_dir, const char *dest_dir) {
    DIR *dir = opendir(source_dir);
    struct dirent *entry;

    if (!dir) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the directories . and ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_file[MAX_LEN];
        char dest_file[MAX_LEN];

        snprintf(source_file, sizeof(source_file), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_file, sizeof(dest_file), "%s/%s", dest_dir, entry->d_name);
        
        struct stat sb;
        if (stat(source_file, &sb) == 0) {
            // If the source entry is a directory, we should sync recursively
            if (S_ISDIR(sb.st_mode)) {
                mkdir(dest_file, 0755);
                sync_files(source_file, dest_file);
            } else {
                // If the destination file does not exist or sizes differ, copy
                if (access(dest_file, F_OK) == -1 || compare_file_size(source_file, dest_file) != 0) {
                    printf("Copying %s to %s\n", source_file, dest_file);
                    copy_file(source_file, dest_file);
                }
            }
        }
    }
    
    closedir(dir);
}

// Print help message
void print_help(const char *prog_name) {
    printf("Usage: %s <source_directory> <destination_directory>\n", prog_name);
    printf("Synchronize contents of source_directory to destination_directory.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_help(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *dest_dir = argv[2];
    
    // Check if source directory exists
    if (access(source_dir, F_OK) == -1) {
        fprintf(stderr, "Source directory does not exist: %s\n", source_dir);
        return EXIT_FAILURE;
    }

    // Check if destination directory exists, if not create it
    if (access(dest_dir, F_OK) == -1) {
        printf("Destination directory does not exist. Creating: %s\n", dest_dir);
        if (mkdir(dest_dir, 0755) == -1) {
            perror("mkdir");
            return EXIT_FAILURE;
        }
    }

    // Start synchronizing files
    sync_files(source_dir, dest_dir);

    printf("File synchronization completed from %s to %s\n", source_dir, dest_dir);
    return EXIT_SUCCESS;
}