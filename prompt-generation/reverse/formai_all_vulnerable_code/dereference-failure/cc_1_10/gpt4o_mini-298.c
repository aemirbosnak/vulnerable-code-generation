//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LEN 1024
#define BUFFER_SIZE 1024

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    FILE *dest = fopen(destination, "wb");
    if (src == NULL || dest == NULL) {
        perror("File open error");
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t n;
    while ((n = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, n, dest);
    }
    fclose(src);
    fclose(dest);
    printf("Copied: %s to %s\n", source, destination);
}

int compare_files(const char *file1, const char *file2) {
    struct stat stat1, stat2;
    
    if (stat(file1, &stat1) < 0 || stat(file2, &stat2) < 0) {
        return -1; // Error occurred
    }

    if (stat1.st_size != stat2.st_size) {
        return 0; // Files are different in size
    }

    FILE *f1 = fopen(file1, "rb");
    FILE *f2 = fopen(file2, "rb");
    if (f1 == NULL || f2 == NULL) {
        perror("File open error");
        return -1;
    }

    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    size_t n1, n2;

    while ((n1 = fread(buffer1, 1, BUFFER_SIZE, f1)) > 0 &&
           (n2 = fread(buffer2, 1, BUFFER_SIZE, f2)) > 0) {
        if (n1 != n2 || memcmp(buffer1, buffer2, n1) != 0) {
            fclose(f1);
            fclose(f2);
            return 0; // Files are different
        }
    }

    fclose(f1);
    fclose(f2);
    return 1; // Files are identical
}

void synchronize_directories(const char *source_dir, const char *dest_dir) {
    DIR *sdir = opendir(source_dir);
    struct dirent *entry;

    if (sdir == NULL) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(sdir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char source_path[MAX_PATH_LEN];
            char dest_path[MAX_PATH_LEN];
            snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);
            
            struct stat sb;
            if (stat(source_path, &sb) < 0) {
                perror("Stat error");
                continue;
            }

            if (S_ISREG(sb.st_mode)) { // Regular file
                if (access(dest_path, F_OK) != 0 || compare_files(source_path, dest_path) == 0) {
                    copy_file(source_path, dest_path);
                }
            }
            // You can add more file types handling (directories, symlinks) if needed
        }
    }
    closedir(sdir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Synchronizing files from %s to %s...\n", argv[1], argv[2]);
    synchronize_directories(argv[1], argv[2]);
    printf("Synchronization complete.\n");

    return EXIT_SUCCESS;
}