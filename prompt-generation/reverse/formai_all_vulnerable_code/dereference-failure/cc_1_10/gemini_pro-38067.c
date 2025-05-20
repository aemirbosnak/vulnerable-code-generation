//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct {
    long long size;
    char *path;
} FileInfo;

int compareFileInfo(const void *a, const void *b) {
    FileInfo *file1 = (FileInfo *)a;
    FileInfo *file2 = (FileInfo *)b;
    return file2->size - file1->size;
}

int main() {
    // Get the current working directory.
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() failed");
        return EXIT_FAILURE;
    }

    // Create a directory stack to keep track of directories that have been visited.
    char **dirStack = malloc(sizeof(char *) * 100);
    int dirStackTop = -1;

    // Create a file info array to store information about the files in the current directory.
    FileInfo *fileInfoArray = malloc(sizeof(FileInfo) * 1000);
    int fileInfoArraySize = 0;

    // Push the current working directory onto the directory stack.
    dirStack[++dirStackTop] = strdup(cwd);

    // While there are directories on the stack, continue analyzing them.
    while (dirStackTop >= 0) {
        // Pop the top directory from the stack.
        char *dir = dirStack[dirStackTop--];

        // Open the directory.
        DIR *d = opendir(dir);
        if (d == NULL) {
            perror("opendir() failed");
            return EXIT_FAILURE;
        }

        // Iterate over the files in the directory.
        struct dirent *entry;
        while ((entry = readdir(d)) != NULL) {
            // Skip hidden files and directories.
            if (entry->d_name[0] == '.') {
                continue;
            }

            // Get the full path to the file.
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", dir, entry->d_name);

            // Get the file size.
            struct stat statbuf;
            if (stat(path, &statbuf) == -1) {
                perror("stat() failed");
                return EXIT_FAILURE;
            }

            // Add the file info to the array.
            fileInfoArray[fileInfoArraySize].size = statbuf.st_size;
            fileInfoArray[fileInfoArraySize].path = strdup(path);
            fileInfoArraySize++;
        }

        // Close the directory.
        closedir(d);

        // Free the directory path.
        free(dir);
    }

    // Sort the file info array by file size.
    qsort(fileInfoArray, fileInfoArraySize, sizeof(FileInfo), compareFileInfo);

    // Print the file info array.
    for (int i = 0; i < fileInfoArraySize; i++) {
        printf("%lld %s\n", fileInfoArray[i].size, fileInfoArray[i].path);
    }

    // Free the file info array.
    for (int i = 0; i < fileInfoArraySize; i++) {
        free(fileInfoArray[i].path);
    }
    free(fileInfoArray);

    // Free the directory stack.
    for (int i = 0; i <= dirStackTop; i++) {
        free(dirStack[i]);
    }
    free(dirStack);

    return EXIT_SUCCESS;
}