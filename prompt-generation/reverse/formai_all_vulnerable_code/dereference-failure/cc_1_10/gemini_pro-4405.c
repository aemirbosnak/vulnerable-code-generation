//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>
#include <unistd.h>

// Forward declarations
static long long int get_dir_size(const char *path);
static void print_sorted_results(const char **filenames, long long int *sizes, int num_files);

int main(int argc, char *argv[]) {
    // Check if the user provided a valid path
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the size of the specified path
    long long int size = get_dir_size(argv[1]);

    // Print the total size of the directory
    printf("Total size: %lld bytes\n", size);

    // Get a list of all the files in the specified path
    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Create an array to store the filenames and sizes
    const char **filenames = malloc(sizeof(char *) * 1024);
    long long int *sizes = malloc(sizeof(long long int) * 1024);
    int num_files = 0;

    // Iterate over the files in the directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Get the full path of the file
        char path[PATH_MAX];
        snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name);

        // Get the size of the file
        long long int size = get_dir_size(path);

        // Add the file to the array
        filenames[num_files] = strdup(entry->d_name);
        sizes[num_files] = size;
        num_files++;
    }

    // Sort the files by size
    print_sorted_results(filenames, sizes, num_files);

    // Clean up
    closedir(dir);
    for (int i = 0; i < num_files; i++) {
        free((void *)filenames[i]);
    }
    free(filenames);
    free(sizes);

    return EXIT_SUCCESS;
}

static long long int get_dir_size(const char *path) {
    long long int size = 0;

    // Get the file attributes
    struct stat st;
    if (stat(path, &st) == -1) {
        perror("stat");
        return -1;
    }

    // If the file is a directory, recursively get the size of its contents
    if (S_ISDIR(st.st_mode)) {
        DIR *dir = opendir(path);
        if (dir == NULL) {
            perror("opendir");
            return -1;
        }

        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            // Skip hidden files
            if (entry->d_name[0] == '.') {
                continue;
            }

            // Get the full path of the file
            char full_path[PATH_MAX];
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

            // Get the size of the file
            long long int file_size = get_dir_size(full_path);
            if (file_size == -1) {
                closedir(dir);
                return -1;
            }

            // Add the size of the file to the total size
            size += file_size;
        }

        closedir(dir);
    } else {
        // If the file is a regular file, just add its size to the total size
        size += st.st_size;
    }

    return size;
}

static void print_sorted_results(const char **filenames, long long int *sizes, int num_files) {
    // Sort the files by size
    for (int i = 0; i < num_files - 1; i++) {
        for (int j = i + 1; j < num_files; j++) {
            if (sizes[i] > sizes[j]) {
                // Swap the filenames and sizes
                const char *temp_filename = filenames[i];
                filenames[i] = filenames[j];
                filenames[j] = temp_filename;

                long long int temp_size = sizes[i];
                sizes[i] = sizes[j];
                sizes[j] = temp_size;
            }
        }
    }

    // Print the sorted results
    for (int i = 0; i < num_files; i++) {
        printf("%s: %lld bytes\n", filenames[i], sizes[i]);
    }
}