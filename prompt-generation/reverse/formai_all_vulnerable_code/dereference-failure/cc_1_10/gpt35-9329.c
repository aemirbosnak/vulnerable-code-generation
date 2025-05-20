//FormAI DATASET v1.0 Category: File Synchronizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

// Function signature
void sync_dir(char *, char *);
void sync_file(char *, char *);
bool is_dir(const char *);
bool is_file(const char *);
bool file_exists(const char *);
void copy_file(const char *, const char *);
void create_dir(const char *);

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <source-directory> <destination-directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Check that source and destination directories exist
    if (!is_dir(argv[1]) || !is_dir(argv[2])) {
        printf("Error: Invalid source or destination directory.\n");
        exit(EXIT_FAILURE);
    }

    // Call sync function
    sync_dir(argv[1], argv[2]);

    printf("Sync complete!\n");

    return 0;
}

// Recursively sync directories
void sync_dir(char *src, char *dest) {
    // Open source directory
    DIR *dir = opendir(src);
    if (dir == NULL) {
        printf("Error: Could not open source directory %s.\n", src);
        exit(EXIT_FAILURE);
    }

    // Create destination directory if it does not exist
    if (!is_dir(dest)) {
        create_dir(dest);
    }

    // Loop through directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Ignore hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Create full file paths for source and destination
        char src_path[PATH_MAX];
        snprintf(src_path, PATH_MAX, "%s/%s", src, entry->d_name);
        char dest_path[PATH_MAX];
        snprintf(dest_path, PATH_MAX, "%s/%s", dest, entry->d_name);

        // Check if it is a file or directory
        if (is_file(src_path)) {
            sync_file(src_path, dest_path);
        } else if (is_dir(src_path)) {
            sync_dir(src_path, dest_path);
        }
    }

    closedir(dir);
}

// Sync individual files
void sync_file(char *src, char *dest) {
    // Check if the file already exists
    if (file_exists(dest)) {
        // Check if source file is newer than destination file
        struct stat src_stat, dest_stat;
        if (stat(src, &src_stat) != 0 || stat(dest, &dest_stat) != 0) {
            printf("Error: Could not get file stats for %s or %s.\n", src, dest);
            exit(EXIT_FAILURE);
        }

        if (src_stat.st_mtime > dest_stat.st_mtime) {
            copy_file(src, dest);
        }
    } else {
        copy_file(src, dest);
    }
}

// Check if path is a directory
bool is_dir(const char *path) {
    struct stat path_stat;
    if (stat(path, &path_stat) != 0) {
        return false;
    }

    return S_ISDIR(path_stat.st_mode);
}

// Check if path is a file
bool is_file(const char *path) {
    struct stat path_stat;
    if (stat(path, &path_stat) != 0) {
        return false;
    }

    return S_ISREG(path_stat.st_mode);
}

// Check if file exists
bool file_exists(const char *path) {
    struct stat path_stat;
    if (stat(path, &path_stat) != 0) {
        return false;
    }

    return true;
}

// Copy file from source to destination
void copy_file(const char *src, const char *dest) {
    FILE *src_file = fopen(src, "rb");
    if (src_file == NULL) {
        printf("Error: Could not open source file %s.\n", src);
        exit(EXIT_FAILURE);
    }

    FILE *dest_file = fopen(dest, "wb");
    if (dest_file == NULL) {
        fclose(src_file);
        printf("Error: Could not open destination file %s.\n", dest);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFSIZ];
    size_t size;
    while ((size = fread(buffer, 1, BUFSIZ, src_file))) {
        fwrite(buffer, 1, size, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
}

// Create directory recursively
void create_dir(const char *path) {
    char tmp[PATH_MAX];
    snprintf(tmp, PATH_MAX, "%s", path);
    char *p = NULL;

    // Iterate through each directory level and create it if it does not exist
    for (p = tmp + 1; *p; p++) {
        if (*p == '/') {
            *p = '\0';
            mkdir(tmp, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
            *p = '/';
        }
    }

    mkdir(tmp, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}