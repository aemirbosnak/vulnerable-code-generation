//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_FILES 100

// File structure
struct File {
    char path[MAX_PATH];
    time_t last_modified;
};

// File list structure
struct FileList {
    struct File files[MAX_FILES];
    int count;
};

// Function to get the current time
time_t get_current_time() {
    time_t t;
    time(&t);
    return t;
}

// Function to compare two files based on their last modified time
int compare_files(const void *a, const void *b) {
    struct File *file1 = (struct File *)a;
    struct File *file2 = (struct File *)b;
    return file2->last_modified - file1->last_modified;
}

// Function to get the file list of a directory
struct FileList get_file_list(const char *path) {
    struct FileList file_list;
    file_list.count = 0;

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return file_list;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH];
        snprintf(full_path, MAX_PATH, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (stat(full_path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        if (!S_ISREG(statbuf.st_mode)) {
            continue;
        }

        struct File file;
        strcpy(file.path, full_path);
        file.last_modified = statbuf.st_mtime;

        file_list.files[file_list.count++] = file;
    }

    closedir(dir);

    // Sort the file list by last modified time
    qsort(file_list.files, file_list.count, sizeof(struct File), compare_files);

    return file_list;
}

// Function to back up a file
int backup_file(const char *path) {
    // Get the current time
    time_t current_time = get_current_time();

    // Create the backup directory if it doesn't exist
    char backup_dir[MAX_PATH];
    snprintf(backup_dir, MAX_PATH, "%s.bak", path);
    mkdir(backup_dir, 0755);

    // Get the file name and extension
    char *file_name = strrchr(path, '/');
    if (file_name == NULL) {
        file_name = (char *)path;
    } else {
        file_name++;
    }

    char *file_ext = strrchr(file_name, '.');
    if (file_ext == NULL) {
        file_ext = "";
    }

    // Create the backup file path
    char backup_file[MAX_PATH];
    snprintf(backup_file, MAX_PATH, "%s/%s_%.10ld%s", backup_dir, file_name, current_time, file_ext);

    // Copy the file
    FILE *src_file = fopen(path, "rb");
    if (src_file == NULL) {
        perror("fopen");
        return -1;
    }

    FILE *dst_file = fopen(backup_file, "wb");
    if (dst_file == NULL) {
        perror("fopen");
        fclose(src_file);
        return -1;
    }

    char buffer[4096];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);

    return 0;
}

// Function to back up a directory
int backup_directory(const char *path) {
    // Get the file list
    struct FileList file_list = get_file_list(path);

    // Back up each file
    for (int i = 0; i < file_list.count; i++) {
        if (backup_file(file_list.files[i].path) == -1) {
            return -1;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    const char *path = argv[1];

    // Check if the path is a file or directory
    struct stat statbuf;
    if (stat(path, &statbuf) == -1) {
        perror("stat");
        return 1;
    }

    if (S_ISREG(statbuf.st_mode)) {
        // Back up a file
        if (backup_file(path) == -1) {
            return 1;
        }
    } else if (S_ISDIR(statbuf.st_mode)) {
        // Back up a directory
        if (backup_directory(path) == -1) {
            return 1;
        }
    } else {
        printf("Error: '%s' is not a file or directory\n", path);
        return 1;
    }

    return 0;
}