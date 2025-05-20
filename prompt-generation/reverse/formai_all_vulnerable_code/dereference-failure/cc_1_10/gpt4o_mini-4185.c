//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to compare two files
int compare_files(const char *file1, const char *file2) {
    FILE *f1, *f2;
    char ch1, ch2;

    f1 = fopen(file1, "r");
    f2 = fopen(file2, "r");

    if (f1 == NULL || f2 == NULL) {
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return -1; // Error opening files
    }

    while (1) {
        ch1 = fgetc(f1);
        ch2 = fgetc(f2);

        if (ch1 != ch2) {
            fclose(f1);
            fclose(f2);
            return 0; // Files are different
        }

        if (feof(f1) && feof(f2)) {
            fclose(f1);
            fclose(f2);
            return 1; // Files are the same
        }

        if (feof(f1) || feof(f2)) {
            fclose(f1);
            fclose(f2);
            return 0; // Files are different
        }
    }
}

// Function to synchronize two directories
void synchronize_directories(const char *src, const char *dest) {
    DIR *source_dir;
    struct dirent *entry;

    source_dir = opendir(src);
    if (source_dir == NULL) {
        perror("Unable to open source directory");
        return;
    }

    while ((entry = readdir(source_dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Ignore hidden files and directories
        }

        char src_path[1024];
        char dest_path[1024];
        snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

        struct stat sb;
        if (stat(src_path, &sb) == -1) {
            perror("stat failed");
            continue;
        }

        if (S_ISDIR(sb.st_mode)) {
            // Create directory if it does not exist in destination
            mkdir(dest_path, 0755);
            // Recursively synchronize the directory
            synchronize_directories(src_path, dest_path);
        } else if (S_ISREG(sb.st_mode)) {
            // If file does not exist in destination or differs, copy it
            if (access(dest_path, F_OK) == -1 || compare_files(src_path, dest_path) == 0) {
                FILE *src_file = fopen(src_path, "rb");
                FILE *dest_file = fopen(dest_path, "wb");

                if (src_file == NULL || dest_file == NULL) {
                    if (src_file) fclose(src_file);
                    if (dest_file) fclose(dest_file);
                    perror("Error opening file for copy");
                    continue;
                }

                char buffer[1024];
                size_t bytes;

                while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                    fwrite(buffer, 1, bytes, dest_file);
                }

                fclose(src_file);
                fclose(dest_file);
                printf("Copied: %s -> %s\n", src_path, dest_path);
            }
        }
    }

    closedir(source_dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    synchronize_directories(source_directory, destination_directory);
    
    printf("Synchronization completed from %s to %s.\n", source_directory, destination_directory);
    
    return EXIT_SUCCESS;
}