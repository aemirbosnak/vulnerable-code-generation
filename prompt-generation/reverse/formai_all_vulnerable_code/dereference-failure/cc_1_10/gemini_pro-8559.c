//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Define a struct to store file information
typedef struct file_info {
    char *name;
    size_t size;
} file_info;

// Function to compare two file_info structs by size
int compare_file_info(const void *a, const void *b) {
    const file_info *fa = (const file_info *)a;
    const file_info *fb = (const file_info *)b;
    return (fa->size > fb->size) - (fa->size < fb->size);
}

// Function to get the file size of a given file
size_t get_file_size(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
        perror("stat");
        return 0;
    }
    return statbuf.st_size;
}

// Function to analyze the disk space usage of a given directory
void analyze_disk_space(const char *path) {
    // Open the directory
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    // Create an array to store the file information
    file_info *files = NULL;
    size_t num_files = 0;

    // Iterate over the directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the file path
        char *file_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(file_path, "%s/%s", path, entry->d_name);

        // Get the file size
        size_t file_size = get_file_size(file_path);

        // Add the file information to the array
        files = realloc(files, (num_files + 1) * sizeof(file_info));
        files[num_files].name = file_path;
        files[num_files].size = file_size;
        num_files++;
    }

    // Close the directory
    closedir(dir);

    // Sort the file information array by size
    qsort(files, num_files, sizeof(file_info), compare_file_info);

    // Print the file information
    for (size_t i = 0; i < num_files; i++) {
        printf("%s: %zu bytes\n", files[i].name, files[i].size);
    }

    // Free the memory allocated for the file information array
    for (size_t i = 0; i < num_files; i++) {
        free(files[i].name);
    }
    free(files);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    analyze_disk_space(argv[1]);

    return EXIT_SUCCESS;
}