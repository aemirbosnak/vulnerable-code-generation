//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

// Max file path length
#define MAX_PATH_LEN 1024

// Max file size
#define MAX_FILE_SIZE 1024 * 1024

// Max number of files in a directory
#define MAX_FILES_IN_DIR 1024

// File synchronizer struct
typedef struct {
    char *src_path;
    char *dst_path;
    int src_fd;
    int dst_fd;
    off_t src_offset;
    off_t dst_offset;
    size_t src_size;
    size_t dst_size;
} file_synchronizer;

// Initialize file synchronizer
file_synchronizer *file_synchronizer_init(char *src_path, char *dst_path) {
    file_synchronizer *fs = malloc(sizeof(file_synchronizer));
    fs->src_path = strdup(src_path);
    fs->dst_path = strdup(dst_path);
    fs->src_fd = open(src_path, O_RDONLY);
    fs->dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC);
    fs->src_offset = 0;
    fs->dst_offset = 0;
    fs->src_size = lseek(fs->src_fd, 0, SEEK_END);
    fs->dst_size = lseek(fs->dst_fd, 0, SEEK_END);
    return fs;
}

// Destroy file synchronizer
void file_synchronizer_destroy(file_synchronizer *fs) {
    close(fs->src_fd);
    close(fs->dst_fd);
    free(fs->src_path);
    free(fs->dst_path);
    free(fs);
}

// Synchronize file
int file_synchronizer_sync(file_synchronizer *fs) {
    char buf[MAX_FILE_SIZE];
    ssize_t nread;
    while ((nread = read(fs->src_fd, buf, sizeof(buf))) > 0) {
        if (write(fs->dst_fd, buf, nread) != nread) {
            return -1;
        }
        fs->src_offset += nread;
        fs->dst_offset += nread;
    }
    if (nread < 0) {
        return -1;
    }
    return 0;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src_path> <dst_path>\n", argv[0]);
        return 1;
    }

    file_synchronizer *fs = file_synchronizer_init(argv[1], argv[2]);
    if (!fs) {
        fprintf(stderr, "Error initializing file synchronizer\n");
        return 1;
    }

    if (file_synchronizer_sync(fs) != 0) {
        fprintf(stderr, "Error synchronizing file\n");
        file_synchronizer_destroy(fs);
        return 1;
    }

    file_synchronizer_destroy(fs);

    return 0;
}