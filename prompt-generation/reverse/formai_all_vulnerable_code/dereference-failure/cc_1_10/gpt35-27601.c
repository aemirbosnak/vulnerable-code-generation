//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

/*
This program analyzes the C: drive on Windows and displays the size of 
each directory and subdirectory in descending order. It also displays
the total size of the drive and the percentage of space used.
*/

// Function to calculate size of directory
long int calculate_directory_size(char *directory_path) {
    DIR *directory;
    struct dirent *entry;
    struct stat file_stat;
    long int size = 0;

    directory = opendir(directory_path);

    if (directory == NULL) {
        printf("Unable to open directory %s\n", directory_path);
        return 0;
    }

    while ((entry = readdir(directory)) != NULL) {
        if ((strcmp(entry->d_name, ".") != 0) && (strcmp(entry->d_name, "..") != 0)) {
            char full_path[1024];
            sprintf(full_path, "%s/%s", directory_path, entry->d_name);

            if (lstat(full_path, &file_stat) == 0) {
                if (S_ISDIR(file_stat.st_mode)) {
                    size += calculate_directory_size(full_path);
                } else {
                    size += file_stat.st_size;
                }
            } else {
                printf("Unable to calculate size of %s\n", full_path);
            }
        }
    }

    closedir(directory);
    return size;
}

int main() {
    long int total_size = calculate_directory_size("/mnt/c");
    printf("Total drive size: %ld bytes\n", total_size);

    DIR *directory;
    struct dirent *entry;
    struct stat file_stat;
    long int size;
    char directory_path[1024];

    directory = opendir("/mnt/c");

    if (directory == NULL) {
        printf("Unable to open directory /mnt/c\n");
        return 1;
    }

    printf("\nDisk space usage:\n");

    // Array to hold directories and their sizes
    char directories[1000][1024];
    long int directory_sizes[1000];
    int num_directories = 0;

    while ((entry = readdir(directory)) != NULL) {
        if ((strcmp(entry->d_name, ".") != 0) && (strcmp(entry->d_name, "..") != 0)) {
            sprintf(directory_path, "/mnt/c/%s", entry->d_name);

            if (lstat(directory_path, &file_stat) == 0) {
                if (S_ISDIR(file_stat.st_mode)) {
                    size = calculate_directory_size(directory_path);
                    strcpy(directories[num_directories], directory_path);
                    directory_sizes[num_directories] = size;
                    num_directories++;
                }
            } else {
                printf("Unable to calculate size of %s\n", directory_path);
            }
        }
    }

    // Sort directories by size in descending order
    int i, j;
    long int temp_size;
    char temp_directory[1024];

    for (i = 0; i < num_directories - 1; i++) {
        for (j = 0; j < num_directories - i - 1; j++) {
            if (directory_sizes[j] < directory_sizes[j+1]) {
                temp_size = directory_sizes[j];
                strcpy(temp_directory, directories[j]);
                directory_sizes[j] = directory_sizes[j+1];
                strcpy(directories[j], directories[j+1]);
                directory_sizes[j+1] = temp_size;
                strcpy(directories[j+1], temp_directory);
            }
        }
    }

    // Display directory sizes
    float percent_used;
    for (i = 0; i < num_directories; i++) {
        printf("%s: %ld bytes\n", directories[i], directory_sizes[i]);
        percent_used = (float) directory_sizes[i] / total_size * 100;
        printf("\t%.2f%% of disk space used\n", percent_used);
    }

    // Calculate and display percentage of space used on drive
    percent_used = (float) total_size / 1024 / 1024 / 1024 * 100;
    printf("\n%.2f%% of disk space used on C: drive\n", percent_used);

    closedir(directory);

    return 0;
}