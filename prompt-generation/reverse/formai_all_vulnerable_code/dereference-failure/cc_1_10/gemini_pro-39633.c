//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Our custom file size struct
typedef struct {
    char *name;
    size_t size;
} FileSize;

// Function to compare FileSize structs by size
int compareFileSize(const void *a, const void *b) {
    const FileSize *fa = (const FileSize *)a;
    const FileSize *fb = (const FileSize *)b;
    return (fa->size - fb->size);
}

int main() {
    // Variables to store the total and max file size
    size_t totalSize = 0;
    size_t maxSize = 0;

    // Array to store the file sizes
    FileSize *files = NULL;
    int numFiles = 0;

    // Queue to traverse the file system
    char **queue = NULL;
    int queueSize = 0;
    int queueFront = 0;
    int queueRear = 0;

    // Enqueue the root directory
    queue = realloc(queue, sizeof(char *) * (queueSize + 1));
    queue[queueRear++] = strdup("/");
    queueSize++;

    // While the queue is not empty
    while (queueFront < queueRear) {
        // Dequeue the front of the queue
        char *dir = queue[queueFront++];
        queueSize--;

        // Open the directory
        DIR *d = opendir(dir);
        if (d == NULL) {
            perror("opendir");
            exit(EXIT_FAILURE);
        }

        // Read the directory entries
        struct dirent *entry;
        while ((entry = readdir(d)) != NULL) {
            // Ignore . and ..
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            // Get the full path of the file
            char *path = malloc(strlen(dir) + strlen(entry->d_name) + 2);
            sprintf(path, "%s/%s", dir, entry->d_name);

            // Get the file size
            struct stat st;
            if (lstat(path, &st) == -1) {
                perror("lstat");
                exit(EXIT_FAILURE);
            }

            // If the file is a directory, add it to the queue
            if (S_ISDIR(st.st_mode)) {
                queue = realloc(queue, sizeof(char *) * (queueSize + 1));
                queue[queueRear++] = strdup(path);
                queueSize++;
            } else {
                // If the file is not a directory, add it to the list of files
                files = realloc(files, sizeof(FileSize) * (numFiles + 1));
                files[numFiles].name = strdup(path);
                files[numFiles].size = st.st_size;
                numFiles++;

                // Update the total and max file size
                totalSize += st.st_size;
                if (st.st_size > maxSize) {
                    maxSize = st.st_size;
                }
            }

            // Free the path
            free(path);
        }

        // Close the directory
        closedir(d);
    }

    // Free the queue
    for (int i = 0; i < queueSize; i++) {
        free(queue[i]);
    }
    free(queue);

    // Sort the files by size
    qsort(files, numFiles, sizeof(FileSize), compareFileSize);

    // Print the total and max file size
    printf("Total size: %zu bytes\n", totalSize);
    printf("Max file size: %zu bytes\n", maxSize);

    // Print the list of files
    for (int i = 0; i < numFiles; i++) {
        printf("%s: %zu bytes\n", files[i].name, files[i].size);

        // Free the file name
        free(files[i].name);
    }

    // Free the list of files
    free(files);

    return 0;
}