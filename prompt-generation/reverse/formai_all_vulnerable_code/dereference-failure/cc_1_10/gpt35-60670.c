//FormAI DATASET v1.0 Category: File Synchronizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to check if a file exists
int exists(const char *path) {
    struct stat stats;
    return stat(path, &stats) == 0;
}

// Function to recursively copy a directory
void copydir(const char *src, const char *dest) {
    // Open source directory and create destination directory
    DIR *srcdir = opendir(src);
    mkdir(dest, 0777);

    // Read source directory entries
    struct dirent *entry;
    while ((entry = readdir(srcdir))) {
        // Skip the . and .. entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct full paths for source and destination files
        char srcpath[1024], destpath[1024];
        snprintf(srcpath, sizeof(srcpath), "%s/%s", src, entry->d_name);
        snprintf(destpath, sizeof(destpath), "%s/%s", dest, entry->d_name);

        // Copy or recursively copy the file or directory
        if (entry->d_type == DT_DIR) {
            copydir(srcpath, destpath);
        } else {
            printf("Copying %s to %s...\n", srcpath, destpath);
            if (exists(destpath)) {
                printf("Destination file already exists, skipping\n");
            } else {
                FILE *srcfile = fopen(srcpath, "r");
                FILE *destfile = fopen(destpath, "w");
                int c;
                while ((c = fgetc(srcfile)) != EOF) {
                    fputc(c, destfile);
                }
                fclose(srcfile);
                fclose(destfile);
            }
        }
    }
    closedir(srcdir);
}

int main(int argc, char *argv[]) {
    // Check for correct number of command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source directory> <destination directory>\n", argv[0]);
        exit(1);
    }

    // Check that source directory exists
    if (!exists(argv[1])) {
        fprintf(stderr, "Error: Source directory %s does not exist\n", argv[1]);
        exit(1);
    }

    // Remove trailing slashes from source and destination directories
    char src[1024], dest[1024];
    strncpy(src, argv[1], sizeof(src));
    strncpy(dest, argv[2], sizeof(dest));
    if (src[strlen(src)-1] == '/') {
        src[strlen(src)-1] = '\0';
    }
    if (dest[strlen(dest)-1] == '/') {
        dest[strlen(dest)-1] = '\0';
    }

    // Copy the directory
    copydir(src, dest);

    return 0;
}