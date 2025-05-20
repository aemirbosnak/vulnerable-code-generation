//FormAI DATASET v1.0 Category: File Synchronizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

/* Function to synchronize two directories */
void sync_directory(const char *src_dir, const char *dest_dir) {
    DIR *dp;
    struct dirent *dirp;
    struct stat src_stat, dest_stat;
    char src_path[1024], dest_path[1024];
    time_t t_src, t_dest;

    /* Open source directory */
    if ((dp = opendir(src_dir)) == NULL) {
        fprintf(stderr, "Unable to open directory: %s\n", src_dir);
        exit(EXIT_FAILURE);
    }

    /* Loop through files in source directory */
    while ((dirp = readdir(dp)) != NULL) {
        /* Ignore current and parent directories */
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0) {
            continue;
        }

        /* Build source and destination paths */
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, dirp->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, dirp->d_name);

        /* Get source file stats */
        if (stat(src_path, &src_stat) != 0) {
            fprintf(stderr, "Unable to get stats for file: %s\n", src_path);
            continue;
        }

        /* Check if file already exists in destination directory */
        if (stat(dest_path, &dest_stat) == 0) {
            /* Compare modification times */
            t_src = src_stat.st_mtime;
            t_dest = dest_stat.st_mtime;
            if (difftime(t_src, t_dest) < 0) {
                /* Source file is older, overwrite destination file */
                if (unlink(dest_path) != 0 && errno != ENOENT) {
                    fprintf(stderr, "Unable to delete file: %s\n", dest_path);
                    continue;
                }
                if (link(src_path, dest_path) != 0) {
                    fprintf(stderr, "Unable to link file: %s\n", dest_path);
                    continue;
                }
            }
        } else {
            /* File does not exist in destination directory, create link */
            if (link(src_path, dest_path) != 0) {
                fprintf(stderr, "Unable to link file: %s\n", dest_path);
                continue;
            }
        }
    }

    /* Close source directory */
    closedir(dp);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sync_directory(argv[1], argv[2]);

    return EXIT_SUCCESS;
}