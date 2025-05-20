//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Symbolic constants for file types
#define FILE_TYPE_REGULAR 1
#define FILE_TYPE_DIRECTORY 2
#define FILE_TYPE_LINK 3
#define FILE_TYPE_CHARACTER 4
#define FILE_TYPE_BLOCK 5
#define FILE_TYPE_FIFO 6
#define FILE_TYPE_SOCKET 7

// Structure to store file information
typedef struct file_info {
    char *name;
    char *path;
    int type;
    time_t mtime;
    size_t size;
} file_info;

// Function to get file information
file_info *get_file_info(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
        return NULL;
    }

    file_info *info = malloc(sizeof(file_info));
    if (info == NULL) {
        return NULL;
    }

    info->name = strdup(path);
    if (info->name == NULL) {
        free(info);
        return NULL;
    }

    info->path = strdup(path);
    if (info->path == NULL) {
        free(info->name);
        free(info);
        return NULL;
    }

    info->type = 0;
    switch (statbuf.st_mode & S_IFMT) {
        case S_IFREG:
            info->type = FILE_TYPE_REGULAR;
            break;
        case S_IFDIR:
            info->type = FILE_TYPE_DIRECTORY;
            break;
        case S_IFLNK:
            info->type = FILE_TYPE_LINK;
            break;
        case S_IFCHR:
            info->type = FILE_TYPE_CHARACTER;
            break;
        case S_IFBLK:
            info->type = FILE_TYPE_BLOCK;
            break;
        case S_IFIFO:
            info->type = FILE_TYPE_FIFO;
            break;
        case S_IFSOCK:
            info->type = FILE_TYPE_SOCKET;
            break;
    }

    info->mtime = statbuf.st_mtime;
    info->size = statbuf.st_size;

    return info;
}

// Function to free file information
void free_file_info(file_info *info) {
    if (info == NULL) {
        return;
    }

    free(info->name);
    free(info->path);
    free(info);
}

// Function to copy a file
int copy_file(const char *src, const char *dest) {
    FILE *src_file = fopen(src, "rb");
    if (src_file == NULL) {
        return -1;
    }

    FILE *dest_file = fopen(dest, "wb");
    if (dest_file == NULL) {
        fclose(src_file);
        return -1;
    }

    char buffer[4096];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);

    return 0;
}

// Function to backup a file
int backup_file(const char *path) {
    // Get file information
    file_info *info = get_file_info(path);
    if (info == NULL) {
        return -1;
    }

    // Create backup directory if it doesn't exist
    char *backup_dir = ".backup";
    if (access(backup_dir, F_OK) != 0) {
        if (mkdir(backup_dir, 0755) != 0) {
            free_file_info(info);
            return -1;
        }
    }

    // Create backup file path
    char *backup_path = malloc(strlen(backup_dir) + strlen(info->name) + 2);
    if (backup_path == NULL) {
        free_file_info(info);
        return -1;
    }

    sprintf(backup_path, "%s/%s", backup_dir, info->name);

    // Copy file to backup
    int result = copy_file(path, backup_path);
    free(backup_path);
    free_file_info(info);
    return result;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file path>\n", argv[0]);
        return 1;
    }

    // Batch process files
    for (int i = 1; i < argc; i++) {
        if (backup_file(argv[i]) != 0) {
            fprintf(stderr, "Error backing up file: %s\n", argv[i]);
            return 1;
        }

        printf("File backed up: %s\n", argv[i]);
    }

    return 0;
}