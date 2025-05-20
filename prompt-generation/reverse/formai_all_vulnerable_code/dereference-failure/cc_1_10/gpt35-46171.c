//FormAI DATASET v1.0 Category: File Synchronizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 1024

const char* SYNC_DIR = "/path/to/sync/directory";
const char* DEST_DIR = "/path/to/destination/directory";

void read_from_file(int source_fd, int dest_fd, char* buffer, ssize_t bytes_to_read);
void write_to_file(int source_fd, int dest_fd, char* buffer, ssize_t bytes_read);

int main(int argc, char* argv[]) {
    int sync_dir_fd, dest_dir_fd;
    char buffer[BUF_SIZE];
    ssize_t bytes_read;
    struct stat sync_dir_stat, dest_dir_stat;
    
    // Check if sync directory and destination directory exist
    sync_dir_fd = open(SYNC_DIR, O_RDONLY);
    if (sync_dir_fd == -1) {
        printf("Error opening sync directory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    if (fstat(sync_dir_fd, &sync_dir_stat) == -1) {
        printf("Error getting sync directory stats: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    dest_dir_fd = open(DEST_DIR, O_RDONLY);
    if (dest_dir_fd == -1) {
        printf("Error opening destination directory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    if (fstat(dest_dir_fd, &dest_dir_stat) == -1) {
        printf("Error getting destination directory stats: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    if (sync_dir_stat.st_dev == dest_dir_stat.st_dev && sync_dir_stat.st_ino == dest_dir_stat.st_ino) {
        printf("Error: sync directory and destination directory cannot be the same!\n");
        exit(EXIT_FAILURE);
    }
    
    while ((bytes_read = read(sync_dir_fd, buffer, BUF_SIZE)) > 0) {
        write_to_file(sync_dir_fd, dest_dir_fd, buffer, bytes_read);
    }
    
    if (bytes_read == -1) {
        printf("Error reading sync directory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    if (close(sync_dir_fd) == -1) {
        printf("Error closing sync directory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    if (close(dest_dir_fd) == -1) {
        printf("Error closing destination directory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    printf("Sync complete!\n");
    
    return 0;
}

void read_from_file(int source_fd, int dest_fd, char* buffer, ssize_t bytes_to_read) {
    ssize_t bytes_read = read(source_fd, buffer, bytes_to_read);
    if (bytes_read == -1) {
        printf("Error reading from file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    write_to_file(source_fd, dest_fd, buffer, bytes_read);
}

void write_to_file(int source_fd, int dest_fd, char* buffer, ssize_t bytes_read) {
    ssize_t bytes_written = write(dest_fd, buffer, bytes_read);
    if (bytes_written == -1) {
        printf("Error writing to file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    if (bytes_written != bytes_read) {
        printf("Error writing to file: incomplete write\n");
        exit(EXIT_FAILURE);
    }
}