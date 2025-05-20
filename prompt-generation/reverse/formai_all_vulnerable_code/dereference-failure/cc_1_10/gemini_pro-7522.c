//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

// Define the maximum length of the file path
#define MAX_PATH_LENGTH 256

// Define the structure to store the directory information
typedef struct directory_info {
    char name[MAX_PATH_LENGTH];
    long size;
    struct directory_info *next;
} directory_info;

// Create a new directory info node
directory_info *new_directory_info(char *name, long size) {
    directory_info *node = (directory_info *)malloc(sizeof(directory_info));
    strcpy(node->name, name);
    node->size = size;
    node->next = NULL;
    return node;
}

// Insert a new directory info node into the list
void insert_directory_info(directory_info **head, directory_info *node) {
    if (*head == NULL) {
        *head = node;
    } else {
        directory_info *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

// Free the directory info list
void free_directory_info_list(directory_info *head) {
    directory_info *current = head;
    while (current != NULL) {
        directory_info *next = current->next;
        free(current);
        current = next;
    }
}

// Get the size of a file
long get_file_size(char *path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        return st.st_size;
    } else {
        return -1;
    }
}

// Get the size of a directory
long get_directory_size(char *path) {
    long size = 0;
    DIR *dir = opendir(path);
    if (dir != NULL) {
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            char subpath[MAX_PATH_LENGTH];
            snprintf(subpath, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);
            if (entry->d_type == DT_REG) {
                size += get_file_size(subpath);
            } else if (entry->d_type == DT_DIR) {
                size += get_directory_size(subpath);
            }
        }
        closedir(dir);
    }
    return size;
}

// Print the directory information list
void print_directory_info_list(directory_info *head) {
    directory_info *current = head;
    while (current != NULL) {
        printf("%s: %ld bytes\n", current->name, current->size);
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    // Check if the user provided a path
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the path from the user
    char *path = argv[1];

    // Get the directory size
    long size = get_directory_size(path);

    // Create a new directory info node
    directory_info *node = new_directory_info(path, size);

    // Insert the directory info node into the list
    directory_info *head = NULL;
    insert_directory_info(&head, node);

    // Print the directory information list
    print_directory_info_list(head);

    // Free the directory info list
    free_directory_info_list(head);

    return EXIT_SUCCESS;
}