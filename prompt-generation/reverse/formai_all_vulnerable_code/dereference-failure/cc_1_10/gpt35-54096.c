//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

/*
 * File Synchronizer in C - By [Your Name]
 *
 * This program synchronizes two directories by copying new and modified
 * files from one directory to the other. Deletions are not propagated.
 * The directories are identified by two command-line arguments.
 */

char *source_dir, *dest_dir;

void sync_file(const char *filename) {
    int r;
    char src_path[256], dest_path[256];
    struct stat src_stat, dest_stat;
    FILE *src_file, *dest_file;

    sprintf(src_path, "%s/%s", source_dir, filename);
    sprintf(dest_path, "%s/%s", dest_dir, filename);

    // check if the file exists in source directory
    if (access(src_path, F_OK) != 0) {
        printf("File does not exist in source: %s\n", src_path);
        return;
    }

    // get file stats in source directory
    r = stat(src_path, &src_stat);
    if (r != 0) {
        printf("Could not stat file in source: %s (%s)\n", src_path, strerror(errno));
        return;
    }

    // get file stats in destination directory
    r = stat(dest_path, &dest_stat);
    if (r != 0 && errno != ENOENT) {
        printf("Could not stat file in destination: %s (%s)\n", dest_path, strerror(errno));
        return;
    }

    // check if file needs to be synced
    if (r == 0 && src_stat.st_mtime <= dest_stat.st_mtime) {
        printf("File is up-to-date: %s\n", src_path);
        return;
    }

    // open source file for reading
    src_file = fopen(src_path, "r");
    if (src_file == NULL) {
        printf("Could not open file in source for reading: %s (%s)\n", src_path, strerror(errno));
        return;
    }

    // create destination directory if it does not exist
    if (errno == ENOENT) {
        r = mkdir(dest_dir, 0755);
        if (r != 0) {
            printf("Could not create destination directory: %s (%s)\n", dest_dir, strerror(errno));
            fclose(src_file);
            return;
        }
        printf("Created destination directory: %s\n", dest_dir);
    }

    // open destination file for writing
    dest_file = fopen(dest_path, "w");
    if (dest_file == NULL) {
        printf("Could not open file in destination for writing: %s (%s)\n", dest_path, strerror(errno));
        fclose(src_file);
        return;
    }

    // copy file from source to destination
    printf("Syncing file: %s\n", src_path);
    char buffer[1024];
    size_t length;
    while ((length = fread(buffer, 1, sizeof (buffer), src_file)) > 0) {
        fwrite(buffer, 1, length, dest_file);
    }

    // close files
    fclose(src_file);
    fclose(dest_file);
}

void sync_dir() {
    DIR *dirp;
    struct dirent *dp;

    // open source directory
    dirp = opendir(source_dir);
    if (dirp == NULL) {
        printf("Could not open source directory: %s (%s)\n", source_dir, strerror(errno));
        return;
    }

    // iterate over all files in directory
    while ((dp = readdir(dirp)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }
        sync_file(dp->d_name);
    }

    // close directory
    closedir(dirp);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s source_dir dest_dir\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    source_dir = argv[1];
    dest_dir = argv[2];

    sync_dir();

    return 0;
}