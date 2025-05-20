//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/queue.h>
#include <sys/types.h>
#include <unistd.h>

// Define a linked list node
struct node {
    char *name;
    struct node *next;
};

// Define a linked list
struct list {
    struct node *head;
    struct node *tail;
};

// Initialize a linked list
void list_init(struct list *list) {
    list->head = NULL;
    list->tail = NULL;
}

// Add a node to a linked list
void list_add(struct list *list, char *name) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->name = name;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Free a linked list
void list_free(struct list *list) {
    struct node *current = list->head;

    while (current != NULL) {
        struct node *next = current->next;
        free(current->name);
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
}

// Get the size of a file
long get_file_size(char *path) {
    struct stat statbuf;

    if (stat(path, &statbuf) == 0) {
        return statbuf.st_size;
    } else {
        return -1;
    }
}

// Get the total size of a directory
long get_directory_size(char *path) {
    struct list list;
    long total_size = 0;

    list_init(&list);

    // Get all the files in the directory
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Get the full path to the file
        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 1);
        strcpy(full_path, path);
        strcat(full_path, "/");
        strcat(full_path, entry->d_name);

        // Get the size of the file
        long file_size = get_file_size(full_path);
        if (file_size != -1) {
            total_size += file_size;
        }

        // Add the file to the linked list
        list_add(&list, full_path);
    }

    closedir(dir);

    // Free the linked list
    list_free(&list);

    return total_size;
}

// Print the size of a file or directory
void print_size(char *path) {
    long size = get_file_size(path);

    if (size == -1) {
        long dir_size = get_directory_size(path);

        if (dir_size == -1) {
            printf("Cannot get size of %s\n", path);
        } else {
            printf("%ld bytes (%ld MB) - %s (directory)\n", dir_size, dir_size / 1024 / 1024, path);
        }
    } else {
        printf("%ld bytes (%ld MB) - %s (file)\n", size, size / 1024 / 1024, path);
    }
}

// Print the usage of the program
void print_usage() {
    printf("Usage: disk-space-analyzer <path>\n");
    printf("Example: disk-space-analyzer /home/user\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return 1;
    }

    char *path = argv[1];

    print_size(path);

    return 0;
}