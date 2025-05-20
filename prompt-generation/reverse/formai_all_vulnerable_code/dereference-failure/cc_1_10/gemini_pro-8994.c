//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 1024

int copy_file(const char *src, const char *dest) {
    int src_fd, dest_fd;
    char buf[BUFSIZE];
    ssize_t nread, nwritten;

    // Open the source file
    src_fd = open(src, O_RDONLY);
    if (src_fd < 0) {
        perror("open");
        return -1;
    }

    // Open the destination file
    dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("open");
        close(src_fd);
        return -1;
    }

    // Copy the file data
    while ((nread = read(src_fd, buf, BUFSIZE)) > 0) {
        nwritten = write(dest_fd, buf, nread);
        if (nwritten != nread) {
            perror("write");
            close(src_fd);
            close(dest_fd);
            return -1;
        }
    }

    if (nread < 0) {
        perror("read");
        close(src_fd);
        close(dest_fd);
        return -1;
    }

    // Close the files
    close(src_fd);
    close(dest_fd);

    return 0;
}

int sync_files(const char *src_dir, const char *dest_dir) {
    DIR *src_dirp, *dest_dirp;
    struct dirent *src_entry, *dest_entry;
    struct stat src_stat, dest_stat;
    int src_fd, dest_fd;
    char src_path[PATH_MAX], dest_path[PATH_MAX];

    // Open the source directory
    src_dirp = opendir(src_dir);
    if (src_dirp == NULL) {
        perror("opendir");
        return -1;
    }

    // Open the destination directory
    dest_dirp = opendir(dest_dir);
    if (dest_dirp == NULL) {
        perror("opendir");
        closedir(src_dirp);
        return -1;
    }

    // Iterate over the files in the source directory
    while ((src_entry = readdir(src_dirp)) != NULL) {
        if (strcmp(src_entry->d_name, ".") == 0 || strcmp(src_entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path of the source file
        snprintf(src_path, PATH_MAX, "%s/%s", src_dir, src_entry->d_name);

        // Get the full path of the destination file
        snprintf(dest_path, PATH_MAX, "%s/%s", dest_dir, src_entry->d_name);

        // Get the stat of the source file
        if (stat(src_path, &src_stat) < 0) {
            perror("stat");
            closedir(src_dirp);
            closedir(dest_dirp);
            return -1;
        }

        // Get the stat of the destination file
        if (stat(dest_path, &dest_stat) < 0) {
            // The destination file does not exist, so copy the source file
            if (copy_file(src_path, dest_path) < 0) {
                closedir(src_dirp);
                closedir(dest_dirp);
                return -1;
            }
        } else {
            // The destination file exists, so compare the stats
            if (src_stat.st_mtime > dest_stat.st_mtime) {
                // The source file is newer, so copy it to the destination
                if (copy_file(src_path, dest_path) < 0) {
                    closedir(src_dirp);
                    closedir(dest_dirp);
                    return -1;
                }
            }
        }
    }

    // Close the directories
    closedir(src_dirp);
    closedir(dest_dirp);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s src_dir dest_dir\n", argv[0]);
        return -1;
    }

    if (sync_files(argv[1], argv[2]) < 0) {
        return -1;
    }

    return 0;
}