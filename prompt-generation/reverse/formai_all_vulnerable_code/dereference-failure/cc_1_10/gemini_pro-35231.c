//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>

// Data structure to store the directory information
struct dir_info {
    char *name;
    long long size;
    struct dir_info *next;
};

// Function to add a directory to the linked list
void add_dir(struct dir_info **head, char *name, long long size) {
    struct dir_info *new_dir = malloc(sizeof(struct dir_info));
    new_dir->name = name;
    new_dir->size = size;
    new_dir->next = *head;
    *head = new_dir;
}

// Function to free the linked list
void free_list(struct dir_info *head) {
    struct dir_info *current = head;
    while (current != NULL) {
        struct dir_info *next = current->next;
        free(current->name);
        free(current);
        current = next;
    }
}

// Function to print the linked list
void print_list(struct dir_info *head) {
    struct dir_info *current = head;
    while (current != NULL) {
        printf("%s: %lld bytes\n", current->name, current->size);
        current = current->next;
    }
}

// Function to get the size of a directory
long long get_dir_size(char *path) {
    long long size = 0;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *new_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(new_path, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (stat(new_path, &statbuf) == -1) {
            perror("stat");
            free(new_path);
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            size += get_dir_size(new_path);
        } else {
            size += statbuf.st_size;
        }

        free(new_path);
    }

    closedir(dir);
    return size;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    char *path = argv[1];

    struct dir_info *head = NULL;
    long long size = get_dir_size(path);
    add_dir(&head, path, size);

    print_list(head);
    free_list(head);

    return 0;
}