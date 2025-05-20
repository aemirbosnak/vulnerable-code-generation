//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Structure to store file information
typedef struct FileInfo {
    char *name;
    off_t size;
    struct FileInfo *next;
} FileInfo;

// Function to recursively traverse a directory and collect file information
void traverseDirectory(char *path, FileInfo **head) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;

    // Open the directory
    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    // Iterate over the directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Ignore "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path of the entry
        char *fullPath = malloc(strlen(path) + strlen(entry->d_name) + 2);
        strcpy(fullPath, path);
        strcat(fullPath, "/");
        strcat(fullPath, entry->d_name);

        // Get the file stats
        if (lstat(fullPath, &statbuf) == -1) {
            perror("lstat");
            continue;
        }

        // If the entry is a directory, recursively traverse it
        if (S_ISDIR(statbuf.st_mode)) {
            traverseDirectory(fullPath, head);
        }
        // If the entry is a file, add it to the linked list
        else if (S_ISREG(statbuf.st_mode)) {
            FileInfo *newfileInfo = malloc(sizeof(FileInfo));
            newfileInfo->name = strdup(entry->d_name);
            newfileInfo->size = statbuf.st_size;
            newfileInfo->next = *head;
            *head = newfileInfo;
        }

        // Free the full path string
        free(fullPath);
    }

    // Close the directory
    closedir(dir);
}

// Function to print the file information in the linked list
void printFileInfo(FileInfo *head) {
    while (head != NULL) {
        printf("%s: %ld bytes\n", head->name, head->size);
        head = head->next;
    }
}

// Function to free the linked list
void freeFileInfo(FileInfo *head) {
    while (head != NULL) {
        FileInfo *next = head->next;
        free(head->name);
        free(head);
        head = next;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a linked list to store the file information
    FileInfo *head = NULL;

    // Traverse the directory and collect file information
    traverseDirectory(argv[1], &head);

    // Print the file information
    printFileInfo(head);

    // Free the linked list
    freeFileInfo(head);

    return EXIT_SUCCESS;
}