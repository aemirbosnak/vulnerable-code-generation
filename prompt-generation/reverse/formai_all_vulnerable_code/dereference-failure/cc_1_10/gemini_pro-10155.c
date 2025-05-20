//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: puzzling
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

struct node {
    struct node *next;
    char *name;
    int size;
};

struct node *root;

void add_node(char *name, int size) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->name = strdup(name);
    new_node->size = size;
    new_node->next = root;
    root = new_node;
}

void free_list() {
    struct node *current = root;
    while (current) {
        struct node *next = current->next;
        free(current->name);
        free(current);
        current = next;
    }
    root = NULL;
}

void print_list() {
    struct node *current = root;
    while (current) {
        printf("%s: %d bytes\n", current->name, current->size);
        current = current->next;
    }
}

int calculate_size(char *path) {
    int size = 0;
    DIR *dir = opendir(path);
    if (dir) {
        struct dirent *entry;
        while ((entry = readdir(dir))) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            char full_path[strlen(path) + strlen(entry->d_name) + 2];
            sprintf(full_path, "%s/%s", path, entry->d_name);
            struct stat statbuf;
            if (stat(full_path, &statbuf) == 0) {
                if (S_ISDIR(statbuf.st_mode))
                    size += calculate_size(full_path);
                else
                    size += statbuf.st_size;
            }
        }
        closedir(dir);
    }
    return size;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    int size = calculate_size(argv[1]);
    printf("Total size: %d bytes\n", size);

    add_node(argv[1], size);
    print_list();
    free_list();

    return 0;
}