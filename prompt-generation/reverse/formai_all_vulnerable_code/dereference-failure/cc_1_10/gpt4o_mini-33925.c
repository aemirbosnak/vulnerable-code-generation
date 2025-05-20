//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void sync_file(const char *src_file, const char *tgt_file) {
    int src_fd, tgt_fd;
    char buffer[1024];
    ssize_t bytes_read, bytes_written;

    src_fd = open(src_file, O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        return;
    }
    
    tgt_fd = open(tgt_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (tgt_fd < 0) {
        perror("Error opening target file");
        close(src_fd);
        return;
    }

    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        bytes_written = write(tgt_fd, buffer, bytes_read);
        if (bytes_written < 0) {
            perror("Error writing to target file");
            break;
        }
    }

    if (bytes_read < 0) {
        perror("Error reading from source file");
    }

    printf("Synchronized: %s to %s\n", src_file, tgt_file);

    close(src_fd);
    close(tgt_fd);
}

void sync_directory(const char *src_dir, const char *tgt_dir) {
    struct dirent *entry;
    DIR *dp;
    char src_path[1024], tgt_path[1024];

    dp = opendir(src_dir);
    if (dp == NULL) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
            snprintf(tgt_path, sizeof(tgt_path), "%s/%s", tgt_dir, entry->d_name);
            
            struct stat statbuf;
            if (stat(src_path, &statbuf) != 0) {
                perror("Could not stat source file");
                continue;
            }

            if (S_ISDIR(statbuf.st_mode)) {
                mkdir(tgt_path, 0755);
                printf("Creating directory: %s\n", tgt_path);
                sync_directory(src_path, tgt_path);
            } else if (S_ISREG(statbuf.st_mode)) {
                sync_file(src_path, tgt_path);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <target_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *src_dir = argv[1];
    const char *tgt_dir = argv[2];

    struct stat statbuf;
    
    if (stat(src_dir, &statbuf) != 0 || !S_ISDIR(statbuf.st_mode)) {
        fprintf(stderr, "Source directory not valid or does not exist!\n");
        return EXIT_FAILURE;
    }
    
    if (stat(tgt_dir, &statbuf) != 0) {
        if (mkdir(tgt_dir, 0755) != 0) {
            perror("Could not create target directory");
            return EXIT_FAILURE;
        }
        printf("Created target directory: %s\n", tgt_dir);
    }

    printf("Starting synchronization from '%s' to '%s'...\n", src_dir, tgt_dir);
    sync_directory(src_dir, tgt_dir);
    printf("Synchronization complete! 🎉\n");
    
    return EXIT_SUCCESS;
}