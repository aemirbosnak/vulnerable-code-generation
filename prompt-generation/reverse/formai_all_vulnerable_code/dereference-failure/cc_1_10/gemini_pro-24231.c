//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>

// Compare two files for equality
int compare_files(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "rb");
    FILE *f2 = fopen(file2, "rb");

    if (f1 == NULL || f2 == NULL) {
        return -1;  // Error opening files
    }

    // Get file sizes
    fseek(f1, 0, SEEK_END);
    long size1 = ftell(f1);
    fseek(f1, 0, SEEK_SET);

    fseek(f2, 0, SEEK_END);
    long size2 = ftell(f2);
    fseek(f2, 0, SEEK_SET);

    // Check if file sizes are equal
    if (size1 != size2) {
        fclose(f1);
        fclose(f2);
        return -2;  // File sizes are different
    }

    // Read files and compare byte by byte
    unsigned char buf1[4096];
    unsigned char buf2[4096];
    while (size1 > 0) {
        long read1 = fread(buf1, 1, sizeof(buf1), f1);
        long read2 = fread(buf2, 1, sizeof(buf2), f2);

        if (read1 != read2 || memcmp(buf1, buf2, read1) != 0) {
            fclose(f1);
            fclose(f2);
            return -3;  // Files are different
        }

        size1 -= read1;
    }

    fclose(f1);
    fclose(f2);
    return 0;  // Files are equal
}

// Synchronize files within a directory
void synchronize_directory(const char *source, const char *destination) {
    // Create destination directory if it doesn't exist
    struct stat st;
    if (stat(destination, &st) != 0 || !S_ISDIR(st.st_mode)) {
        mkdir(destination, 0755);
    }

    // Iterate over files in source directory
    DIR *dir = opendir(source);
    if (dir == NULL) {
        return;  // Error opening directory
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files and directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0 || entry->d_name[0] == '.') {
            continue;
        }

        // Get source file path
        char source_file[PATH_MAX];
        snprintf(source_file, sizeof(source_file), "%s/%s", source, entry->d_name);

        // Get destination file path
        char destination_file[PATH_MAX];
        snprintf(destination_file, sizeof(destination_file), "%s/%s", destination, entry->d_name);

        // Determine file type
        struct stat file_stat;
        if (stat(source_file, &file_stat) != 0) {
            continue;  // Error getting file status
        }

        // Handle file types
        if (S_ISDIR(file_stat.st_mode)) {
            // Recursively synchronize directory
            synchronize_directory(source_file, destination_file);
        } else if (S_ISREG(file_stat.st_mode)) {
            // Compare files
            int result = compare_files(source_file, destination_file);

            if (result == 0) {
                // Files are equal, skip copying
                continue;
            } else if (result == -2 || result == -3) {
                // Files are different, copy from source to destination
                FILE *f1 = fopen(source_file, "rb");
                FILE *f2 = fopen(destination_file, "wb");

                if (f1 == NULL || f2 == NULL) {
                    continue;  // Error opening files
                }

                unsigned char buf[4096];
                while (!feof(f1)) {
                    long read = fread(buf, 1, sizeof(buf), f1);
                    fwrite(buf, 1, read, f2);
                }

                fclose(f1);
                fclose(f2);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source destination\n", argv[0]);
        return EXIT_FAILURE;
    }

    synchronize_directory(argv[1], argv[2]);

    return EXIT_SUCCESS;
}