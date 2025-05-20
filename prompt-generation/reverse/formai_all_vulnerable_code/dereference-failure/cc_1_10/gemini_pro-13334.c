//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

typedef struct node {
    char *name;
    struct node *next;
} node_t;

node_t *head = NULL;

void add_node(char *name) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->name = strdup(name);
    new_node->next = head;
    head = new_node;
}

void print_list() {
    node_t *current = head;
    while (current != NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

void free_list() {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->name);
        free(current);
        current = next;
    }
    head = NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *directory = argv[1];
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *path = malloc(strlen(directory) + strlen(entry->d_name) + 2);
        strcpy(path, directory);
        strcat(path, "/");
        strcat(path, entry->d_name);

        struct stat statbuf;
        if (lstat(path, &statbuf) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            add_node(path);
        } else {
            printf("%s: %ld bytes\n", path, statbuf.st_size);
        }

        free(path);
    }

    closedir(dir);

    print_list();
    free_list();

    return EXIT_SUCCESS;
}