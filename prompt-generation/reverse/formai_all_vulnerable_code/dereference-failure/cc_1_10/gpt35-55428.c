//FormAI DATASET v1.0 Category: File Backup System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void backup(char *, char *);

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <source directory> <backup directory>\n", argv[0]);
        return 1;
    }
    backup(argv[1], argv[2]);
    return 0;
}

void backup(char *src, char *dest) {
    DIR *dir;
    struct dirent *ent;
    struct stat statbuf;
    char path[1024];

    // Open the source directory
    if ((dir = opendir(src)) == NULL) {
        printf("Error opening directory %s\n", src);
        return;
    }

    // Ensure the backup directory exists
    mkdir(dest, 0777);

    // Traverse the source directory
    while ((ent = readdir(dir)) != NULL) {
        // Ignore the "." and ".." directories
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        // Build the full path of the file or directory
        sprintf(path, "%s/%s", src, ent->d_name);

        // Get the file or directory attributes
        if (lstat(path, &statbuf) == -1) {
            printf("Error getting file attributes for %s\n", path);
            continue;
        }

        // Recursively backup directories
        if (S_ISDIR(statbuf.st_mode)) {
            backup(path, dest);
        }

        // Backup regular files
        else if (S_ISREG(statbuf.st_mode)) {
            // Build the destination path
            sprintf(path, "%s/%s", dest, ent->d_name);

            // Open the source file for reading
            FILE *src_file = fopen(src, "rb");
            if (src_file == NULL) {
                printf("Error opening source file %s\n", path);
                continue;
            }

            // Open the destination file for writing
            FILE *dest_file = fopen(dest, "wb");
            if (dest_file == NULL) {
                printf("Error opening destination file %s\n", path);
                fclose(src_file);
                continue;
            }

            // Copy the file
            int ch;
            while ((ch = fgetc(src_file)) != EOF) {
                fputc(ch, dest_file);
            }

            // Close the files
            fclose(src_file);
            fclose(dest_file);
        }
    }

    // Close the directory
    closedir(dir);
}