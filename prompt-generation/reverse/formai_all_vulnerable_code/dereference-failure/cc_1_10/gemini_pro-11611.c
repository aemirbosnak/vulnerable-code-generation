//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

// Recursive function to traverse the directory tree and check for suspicious files
void check_directory(char *path) {
    DIR *dir;
    struct dirent *entry;

    // Open the directory
    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    // Read each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files and directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Check if the entry is a directory
        if (entry->d_type == DT_DIR) {
            // Recursively check the subdirectory
            char subpath[strlen(path) + strlen(entry->d_name) + 2];
            sprintf(subpath, "%s/%s", path, entry->d_name);
            check_directory(subpath);
        } else {
            // Check if the entry is a suspicious file
            if (check_file(path, entry->d_name)) {
                // Print the suspicious file
                printf("Suspicious file: %s/%s\n", path, entry->d_name);
            }
        }
    }

    // Close the directory
    closedir(dir);
}

// Function to check if a file is suspicious
int check_file(char *path, char *filename) {
    // Open the file
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 0;
    }

    // Read the file contents into a buffer
    char buffer[1024];
    int nbytes = read(fd, buffer, sizeof(buffer));
    if (nbytes == -1) {
        perror("read");
        close(fd);
        return 0;
    }

    // Close the file
    close(fd);

    // Check for suspicious content in the file
    if (strstr(buffer, "malware") != NULL) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char **argv) {
    // Check the command line arguments
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    // Check the directory for suspicious files
    check_directory(argv[1]);

    return 0;
}