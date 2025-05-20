//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Structure to store file information
typedef struct file_info {
    char *name;
    long size;
} file_info;

// Comparator function for sorting file information by size
int compare_file_info(const void *a, const void *b) {
    const file_info *fa = (const file_info *)a;
    const file_info *fb = (const file_info *)b;

    return (fb->size - fa->size);
}

// Function to get the file size
long get_file_size(const char *path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        return st.st_size;
    }
    return -1;
}

// Function to analyze the disk space
void analyze_disk_space(const char *path) {
    DIR *dir;
    struct dirent *ent;
    file_info *files;
    int num_files = 0;
    long total_size = 0;

    // Open the directory
    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    // Get all the files in the directory
    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        char *filepath = malloc(strlen(path) + strlen(ent->d_name) + 2);
        strcpy(filepath, path);
        strcat(filepath, "/");
        strcat(filepath, ent->d_name);

        long size = get_file_size(filepath);
        if (size == -1) {
            perror("stat");
            free(filepath);
            continue;
        }

        files = realloc(files, (num_files + 1) * sizeof(file_info));
        files[num_files].name = filepath;
        files[num_files].size = size;
        num_files++;
        total_size += size;
    }

    closedir(dir);

    // Sort the files by size
    qsort(files, num_files, sizeof(file_info), compare_file_info);

    // Print the results
    printf("Total size: %ld bytes\n", total_size);
    printf("Largest files:\n");
    for (int i = 0; i < num_files && i < 10; i++) {
        printf("%s: %ld bytes\n", files[i].name, files[i].size);
    }

    // Free the allocated memory
    for (int i = 0; i < num_files; i++) {
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