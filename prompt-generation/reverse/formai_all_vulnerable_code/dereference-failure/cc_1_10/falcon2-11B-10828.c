//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>

// Global variables
int files_to_scan = 0;

void scan_directory(const char *path, int depth) {
    // Initialize the stat buffer
    struct stat st;

    // Open the directory
    DIR *dir;
    dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory: %s\n", strerror(errno));
        return;
    }

    // Traverse the directory
    struct dirent *entry;
    while ((entry = readdir(dir))!= NULL) {
        const char *entry_name = entry->d_name;
        if (strcmp(entry_name, ".") == 0 || strcmp(entry_name, "..") == 0) {
            continue;
        }

        // Check if the entry is a directory or a file
        struct stat st_entry;
        if (stat(path, &st) == -1) {
            perror("Error statting entry");
            continue;
        }
        if (S_ISDIR(st.st_mode)) {
            // Recursively scan the subdirectory
            scan_directory(path, depth + 1);
        } else {
            // Check if the entry is a regular file or a symbolic link
            if (stat(path, &st_entry) == -1) {
                perror("Error statting entry");
                continue;
            }
            if (S_ISLNK(st_entry.st_mode)) {
                // Check if the symbolic link points to an executable file
                char *exec_path = readlink("/proc/self/exe", NULL, 0);
                if (exec_path == NULL) {
                    perror("Error reading symbolic link");
                    continue;
                }
                if (strcmp(exec_path, entry_name) == 0) {
                    printf("Found a malicious file: %s\n", entry_name);
                    files_to_scan++;
                }
            } else {
                // Check if the entry is an executable file
                if (S_ISREG(st_entry.st_mode)) {
                    if (stat(entry_name, &st_entry) == -1) {
                        perror("Error statting entry");
                        continue;
                    }
                    if (S_ISREG(st_entry.st_mode)) {
                        if (S_ISSOCK(st_entry.st_mode) || S_ISFIFO(st_entry.st_mode)) {
                            printf("Found a malicious file: %s\n", entry_name);
                            files_to_scan++;
                        }
                    }
                }
            }
        }
    }

    // Close the directory
    closedir(dir);
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    // Scan the directory
    scan_directory(argv[1], 0);

    // Print the number of malicious files found
    if (files_to_scan == 0) {
        printf("No malicious files found\n");
    } else {
        printf("%d malicious files found\n", files_to_scan);
    }

    return 0;
}