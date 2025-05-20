//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: recursive
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

// Define the struct for storing file information
typedef struct file_info {
    char *name;
    long size;
    time_t mtime;
    struct passwd *owner;
    struct group *group;
} file_info;

// Function to compare two file_info structs by size, in descending order
int compare_file_info(const void *a, const void *b) {
    const file_info *fa = (const file_info *)a;
    const file_info *fb = (const file_info *)b;
    return fb->size - fa->size;
}

// Function to recursively analyze the disk space usage of a directory
long analyze_directory(const char *path) {
    long total_size = 0;

    // Open the directory
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    // Read the directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Ignore "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path of the entry
        char full_path[PATH_MAX];
        snprintf(full_path, PATH_MAX, "%s/%s", path, entry->d_name);

        // Get the file information
        struct stat statbuf;
        if (stat(full_path, &statbuf) != 0) {
            perror("stat");
            continue;
        }

        // Allocate memory for the file_info struct
        file_info *file_info = malloc(sizeof(file_info));
        if (file_info == NULL) {
            perror("malloc");
            continue;
        }

        // Store the file information in the struct
        file_info->name = strdup(entry->d_name);
        file_info->size = statbuf.st_size;
        file_info->mtime = statbuf.st_mtime;
        file_info->owner = getpwuid(statbuf.st_uid);
        file_info->group = getgrgid(statbuf.st_gid);

        // Add the file size to the total size
        total_size += file_info->size;

        // If the entry is a directory, recursively analyze it
        if (S_ISDIR(statbuf.st_mode)) {
            total_size += analyze_directory(full_path);
        }

        // Free the memory allocated for the file_info struct
        free(file_info->name);
        free(file_info);
    }

    // Close the directory
    closedir(dir);

    return total_size;
}

// Function to print the file information
void print_file_info(const file_info *file_info) {
    printf("%s\n", file_info->name);
    printf("Size: %ld bytes\n", file_info->size);
    printf("Modified: %s", ctime(&file_info->mtime));
    printf("Owner: %s\n", file_info->owner->pw_name);
    printf("Group: %s\n", file_info->group->gr_name);
    printf("\n");
}

// Function to print the disk space usage information
void print_disk_space_usage(const char *path, long total_size) {
    printf("Disk space usage for %s:\n", path);
    printf("Total size: %ld bytes\n", total_size);
    printf("\n");
}

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    // Analyze the disk space usage of the specified path
    long total_size = analyze_directory(argv[1]);

    // Print the disk space usage information
    print_disk_space_usage(argv[1], total_size);

    return 0;
}