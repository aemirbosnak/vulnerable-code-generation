//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <math.h>

// Function to get size of directory recursively
long int getDirSize(char* dir_path) {
    DIR* directory = opendir(dir_path);
    struct dirent* file;
    struct stat file_stat;
    long int dir_size = 0;

    if (!directory) {
        perror("Directory does not exist");
        exit(EXIT_FAILURE);
    }

    while ((file = readdir(directory)) != NULL) {
        // Ignore . and .. directories
        if (strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0) {
            continue;
        }
        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, file->d_name);
        if (stat(file_path, &file_stat) < 0) {
            perror("Failed to get file stats");
            exit(EXIT_FAILURE);
        }
        if (S_ISDIR(file_stat.st_mode)) {  // If it's a directory
            dir_size += getDirSize(file_path);
        } else {  // If it's a file
            dir_size += file_stat.st_size;
        }
    }

    closedir(directory);
    return dir_size;
}

// Function to convert bytes to human readable format
void convertToReadable(long int bytes, char* buf) {
    char* size_units[] = {"B", "KB", "MB", "GB", "TB"};
    int size_index = 0;
    double size = bytes;

    while (size > 1024) {
        size /= 1024;
        size_index++;
    }

    sprintf(buf, "%.2f %s", size, size_units[size_index]);
}

int main() {
    char* dir_path = "/";  // Specify the directory path to analyze
    long int dir_size = getDirSize(dir_path);
    char size_str[16];
    convertToReadable(dir_size, size_str);

    printf("Size of directory %s is %s\n", dir_path, size_str);

    return 0;
}