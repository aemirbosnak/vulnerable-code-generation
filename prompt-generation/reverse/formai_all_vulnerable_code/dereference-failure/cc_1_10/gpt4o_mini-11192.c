//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to check if a file exists
int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// Function to compare two files
int compare_files(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");
    if (!f1 || !f2) {
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return -1; // Error opening files
    }

    int ch1, ch2;
    while ((ch1 = fgetc(f1)) != EOF && (ch2 = fgetc(f2)) != EOF) {
        if (ch1 != ch2) {
            fclose(f1);
            fclose(f2);
            return 0; // Files are different
        }
    }
    
    int result = (ch1 == EOF && ch2 == EOF) ? 1 : 0; // 1 if files are the same, 0 if different
    fclose(f1);
    fclose(f2);
    return result;
}

// Function to copy a file
void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    FILE *dest = fopen(destination, "wb");
    if (!src || !dest) {
        perror("Error opening file");
        if (src) fclose(src);
        if (dest) fclose(dest);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

// Function to synchronize files between source and destination
void synchronize(const char *src_dir, const char *dst_dir) {
    DIR *src = opendir(src_dir);
    if (!src) {
        perror("Error opening source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(src)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directories
        }

        char src_path[1024];
        char dst_path[1024];
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, entry->d_name);
        
        if (file_exists(dst_path)) {
            // Compare files if they exist in the destination
            if (compare_files(src_path, dst_path) == 0) {
                // Source file is different, copy it
                printf("Copying updated file: %s to %s\n", src_path, dst_path);
                copy_file(src_path, dst_path);
            }
        } else {
            // If the destination file does not exist, copy it
            printf("Copying new file: %s to %s\n", src_path, dst_path);
            copy_file(src_path, dst_path);
        }
    }

    closedir(src);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    synchronize(source_directory, destination_directory);

    printf("Synchronization completed.\n");
    return EXIT_SUCCESS;
}