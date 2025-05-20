//FormAI DATASET v1.0 Category: File Synchronizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

// This is a basic file synchronizer which uses system calls to copy files from one directory to another.

void sync_files(char *src_dir, char *dest_dir)
{
    DIR *src, *dest;
    struct dirent *entry;
    struct stat statbuf;
    char *src_path = malloc(256*sizeof(char));
    char *dest_path = malloc(256*sizeof(char));
    char buf[BUFSIZ];
    ssize_t nread;
    int src_fd, dest_fd;

    src = opendir(src_dir);
    dest = opendir(dest_dir);

    if (src == NULL) {
        perror("Unable to open source directory");
        exit(EXIT_FAILURE);
    }

    if (dest == NULL) {
        perror("Unable to open destination directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(src)) != NULL) {
        sprintf(src_path, "%s/%s", src_dir, entry->d_name);
        sprintf(dest_path, "%s/%s", dest_dir, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            sync_files(src_path, dest_path); // recursive call for subdirectories
        }
        else {
            src_fd = open(src_path, O_RDONLY);
            if (src_fd == -1) {
                perror("Unable to open source file");
            }

            if (fstat(src_fd, &statbuf) == -1) {
                perror("Unable to get file status");
            }

            dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, statbuf.st_mode);
            if (dest_fd == -1) {
                perror("Unable to open destination file");
            }

            while ((nread = read(src_fd, buf, BUFSIZ)) > 0) {
                if (write(dest_fd, buf, nread) != nread) {
                    perror("Unable to write to destination file");
                }
            }

            if (nread == -1) {
                perror("Error reading source file");
            }

            if (close(src_fd) == -1) {
                perror("Unable to close source file");
            }

            if (close(dest_fd) == -1) {
                perror("Unable to close destination file");
            }
        }
    }

    if (closedir(src) == -1) {
        perror("Unable to close source directory");
        exit(EXIT_FAILURE);
    }

    if (closedir(dest) == -1) {
        perror("Unable to close destination directory");
        exit(EXIT_FAILURE);
    }

    free(src_path);
    free(dest_path);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [source directory] [destination directory]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sync_files(argv[1], argv[2]);

    printf("Files synchronized successfully!\n");
    return 0;
}