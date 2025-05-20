//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to get the size of a directory
long long get_dir_size(const char *path) {
    DIR *dir;
    struct dirent *ent;
    long long total_size = 0;

    // Open the directory
    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    // Iterate over the directory entries
    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        // Get the size of the file or directory
        struct stat st;
        char full_path[PATH_MAX];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, ent->d_name);
        if (lstat(full_path, &st) == -1) {
            perror("lstat");
            closedir(dir);
            return -1;
        }

        // Add the size to the total
        if (S_ISDIR(st.st_mode)) {
            total_size += get_dir_size(full_path);
        } else {
            total_size += st.st_size;
        }
    }

    // Close the directory
    closedir(dir);

    return total_size;
}

int main() {
    long long total_size = get_dir_size(".");
    if (total_size == -1) {
        return EXIT_FAILURE;
    }

    // Print the total size
    printf("Total size: %lld bytes\n", total_size);

    return EXIT_SUCCESS;
}