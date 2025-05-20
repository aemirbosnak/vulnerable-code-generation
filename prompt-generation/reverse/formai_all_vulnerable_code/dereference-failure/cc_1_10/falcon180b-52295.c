//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 1000

// Function to compare two file paths
int compare_file_paths(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

// Function to print the disk space usage in a directory
void print_disk_space_usage(const char *path) {
    struct dirent **namelist;
    int count;

    // Get the list of files in the directory
    count = scandir(path, &namelist, NULL, NULL);

    // Sort the list of files by name
    qsort(namelist, count, sizeof(struct dirent *), compare_file_paths);

    // Print the disk space usage for each file
    for (int i = 0; i < count; i++) {
        struct stat file_stat;
        char file_path[MAX_FILE_NAME_LENGTH];

        sprintf(file_path, "%s/%s", path, namelist[i]->d_name);
        stat(file_path, &file_stat);

        printf("%s (%d bytes)\n", namelist[i]->d_name, file_stat.st_size);
    }

    // Free the list of files
    for (int i = 0; i < count; i++) {
        free(namelist[i]);
    }
    free(namelist);
}

// Function to get the disk space usage for a directory and its subdirectories
void get_disk_space_usage(const char *path) {
    DIR *dir;
    struct dirent *ent;
    char subdir_path[MAX_FILE_NAME_LENGTH];

    dir = opendir(path);

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                sprintf(subdir_path, "%s/%s", path, ent->d_name);
                get_disk_space_usage(subdir_path);
            } else {
                print_disk_space_usage(path);
            }
        }

        closedir(dir);
    }
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    get_disk_space_usage(argv[1]);

    return 0;
}