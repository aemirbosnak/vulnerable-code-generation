//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1000

struct file_node {
    char *name;
    int size;
    struct file_node *next;
} *head = NULL;

// Function to recursively traverse directories and analyze files
void traverse_dir(char *dir_path) {
    DIR *dir;
    struct dirent *dir_entry;
    struct stat dir_stats;
    char path[MAX_PATH_LENGTH];

    dir = opendir(dir_path);

    if(dir == NULL) {
        printf("Error: Unable to open directory '%s'\n", dir_path);
        exit(1);
    }

    while((dir_entry = readdir(dir)) != NULL) {
        // Skip current and parent directories
        if(strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0)
            continue;

        // Construct full path to entry
        snprintf(path, MAX_PATH_LENGTH, "%s/%s", dir_path, dir_entry->d_name);

        if(lstat(path, &dir_stats) == -1) {
            printf("Error: Unable to get file stats for '%s'\n", path);
            exit(1);
        }

        if(S_ISDIR(dir_stats.st_mode)) {
            // Entry is a directory, recursively traverse it
            traverse_dir(path);
        }
        else {
            // Entry is a file, add its size to linked list
            struct file_node *new_node = malloc(sizeof(struct file_node));
            new_node->name = strdup(path);
            new_node->size = dir_stats.st_size;
            new_node->next = NULL;

            if(head == NULL) {
                head = new_node;
            }
            else {
                struct file_node *curr_node = head;
                while(curr_node->next != NULL) {
                    curr_node = curr_node->next;
                }
                curr_node->next = new_node;
            }
        }
    }

    closedir(dir);
}

// Function to print file sizes in descending order
void print_results() {
    // Sort linked list by file size
    struct file_node *curr_node, *prev_node;
    int swapped = 1;
    while(swapped == 1) {
        swapped = 0;
        prev_node = NULL;
        curr_node = head;
        while(curr_node->next != NULL) {
            if(curr_node->size < curr_node->next->size) {
                struct file_node *next_node = curr_node->next;
                curr_node->next = next_node->next;
                next_node->next = curr_node;
                if(prev_node == NULL)
                    head = next_node;
                else
                    prev_node->next = next_node;
                swapped = 1;
            }
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
    }

    // Print sorted file sizes
    curr_node = head;
    while(curr_node != NULL) {
        printf("%-50s %10d bytes\n", curr_node->name, curr_node->size);
        curr_node = curr_node->next;
    }
}

int main(int argc, char **argv) {
    char *dir_path;
    struct stat dir_stats;

    // Check for valid command line arguments
    if(argc != 2) {
        printf("Usage: %s directory_path\n", argv[0]);
        exit(1);
    }

    dir_path = argv[1];

    if(lstat(dir_path, &dir_stats) == -1) {
        printf("Error: Unable to get file stats for '%s'\n", dir_path);
        exit(1);
    }

    if(!S_ISDIR(dir_stats.st_mode)) {
        printf("Error: '%s' is not a directory\n", dir_path);
        exit(1);
    }

    traverse_dir(dir_path);
    print_results();

    return 0;
}