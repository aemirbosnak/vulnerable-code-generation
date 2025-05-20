//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

// Function to get the size of a file in bytes
long long get_file_size(const char *file_path) {
    struct stat statbuf;
    if (stat(file_path, &statbuf) == -1) {
        perror("stat");
        return -1;
    }
    return statbuf.st_size;
}

// Function to get the total size of a directory and all its subdirectories
long long get_dir_size(const char *dir_path) {
    long long total_size = 0;

    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char file_path[strlen(dir_path) + strlen(entry->d_name) + 2];
        sprintf(file_path, "%s/%s", dir_path, entry->d_name);

        struct stat statbuf;
        if (stat(file_path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            total_size += get_dir_size(file_path);
        } else {
            total_size += statbuf.st_size;
        }
    }

    closedir(dir);

    return total_size;
}

int main() {
    // Get the C drive letter
    char drive_letter = 'C';

    // Get the total size of the C drive
    long long drive_size = get_dir_size(drive_letter);

    // Print the total size of the C drive
    printf("Total size of the %c drive: %lld bytes\n", drive_letter, drive_size);

    return 0;
}