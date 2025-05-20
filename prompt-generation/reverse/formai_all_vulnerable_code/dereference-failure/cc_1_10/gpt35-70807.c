//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Claude Shannon
/* Program to analyze disk space usage */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

/* Define constants */
#define BUFSIZE 1024

/* Define functions */
int analyze_dir(const char* dirpath);

/* Program starts here */
int main(int argc, char* argv[]) {
    /* Check command-line arguments */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Analyze directory */
    analyze_dir(argv[1]);

    return 0;
}

/* Function to analyze a directory */
int analyze_dir(const char* dirpath) {
    /* Declare variables */
    DIR* dir;
    struct dirent* entry;
    struct stat statbuf;
    char path[BUFSIZE];
    int size, total_size = 0;

    /* Open directory */
    if ((dir = opendir(dirpath)) == NULL) {
        perror("opendir");
        return -1;
    }

    /* Loop over directory entries */
    while ((entry = readdir(dir)) != NULL) {
        /* Ignore "." and ".." entries */
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        /* Build full path to entry */
        snprintf(path, BUFSIZE, "%s/%s", dirpath, entry->d_name);

        /* Get file status */
        if (lstat(path, &statbuf) == -1) {
            perror("lstat");
            continue;
        }

        /* If entry is a directory, analyze it */
        if (S_ISDIR(statbuf.st_mode)) {
            size = analyze_dir(path);
            total_size += size;
        }
        /* If entry is a regular file, add its size to the total */
        else if (S_ISREG(statbuf.st_mode)) {
            size = (int) statbuf.st_size;
            total_size += size;
        }
    }

    /* Close directory */
    closedir(dir);

    /* Print size of directory */
    printf("%s: %d bytes\n", dirpath, total_size);

    /* Return total size */
    return total_size;
}