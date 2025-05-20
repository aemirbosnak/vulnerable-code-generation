//FormAI DATASET v1.0 Category: File Synchronizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFSIZE 4096

// Function to recursively copy directories and files
void copy_files(const char* source_path, const char* dest_path) {
    DIR *dir;
    struct dirent *entry;
    char source_file[PATH_MAX], dest_file[PATH_MAX];

    // Open the source directory
    if ((dir = opendir(source_path)) == NULL) {
        fprintf(stderr, "Error: Unable to open directory %s - %s\n", source_path, strerror(errno));
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip . and .. directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(source_file, sizeof(source_file), "%s/%s", source_path, entry->d_name);
        snprintf(dest_file, sizeof(dest_file), "%s/%s", dest_path, entry->d_name);

        struct stat statbuf;
        if (stat(source_file, &statbuf) == -1) {
            fprintf(stderr, "Error: Unable to stat file %s - %s\n", source_file, strerror(errno));
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) { // recursive copy for directories
            if (mkdir(dest_file, statbuf.st_mode) == -1 && errno != EEXIST) {
                fprintf(stderr, "Error: Unable to create directory %s - %s\n", dest_file, strerror(errno));
                continue;
            }

            copy_files(source_file, dest_file);
        } else { // copy file
            int srcfd, destfd;
            ssize_t n;
            char buf[BUFSIZE];

            srcfd = open(source_file, O_RDONLY);
            if (srcfd == -1) {
                fprintf(stderr, "Error: Unable to open file %s - %s\n", source_file, strerror(errno));
                continue;
            }

            destfd = open(dest_file, O_CREAT | O_WRONLY | O_TRUNC, statbuf.st_mode);
            if (destfd == -1) {
                fprintf(stderr, "Error: Unable to create file %s - %s\n", dest_file, strerror(errno));
                close(srcfd);
                continue;
            }

            while ((n = read(srcfd, buf, sizeof(buf))) > 0) {
                if (write(destfd, buf, n) != n) {
                    fprintf(stderr, "Error: Unable to write file %s - %s\n", dest_file, strerror(errno));
                    close(srcfd);
                    close(destfd);
                    continue;
                }
            }

            if (n == -1) {
                fprintf(stderr, "Error: Unable to read file %s - %s\n", source_file, strerror(errno));
            }

            close(srcfd);
            close(destfd);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [SOURCE DIRECTORY] [DESTINATION DIRECTORY]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char source_path[PATH_MAX], dest_path[PATH_MAX];
    realpath(argv[1], source_path);
    realpath(argv[2], dest_path);

    struct stat statbuf;
    if (stat(source_path, &statbuf) == -1) {
        fprintf(stderr, "Error: Unable to stat file %s - %s\n", source_path, strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (!S_ISDIR(statbuf.st_mode)) {
        fprintf(stderr, "Error: %s is not a directory\n", source_path);
        exit(EXIT_FAILURE);
    }

    if (mkdir(dest_path, statbuf.st_mode) == -1 && errno != EEXIST) {
        fprintf(stderr, "Error: Unable to create directory %s - %s\n", dest_path, strerror(errno));
        exit(EXIT_FAILURE);
    }

    copy_files(source_path, dest_path);

    printf("Files synced successfully!\n");

    return 0;
}