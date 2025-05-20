//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

typedef struct node {
    char *path;
    size_t size;
    struct node *next;
} node_t;

typedef struct list {
    node_t *head;
    node_t *tail;
} list_t;

void list_init(list_t *list) {
    list->head = NULL;
    list->tail = NULL;
}

void list_add(list_t *list, char *path, size_t size) {
    node_t *new_node = malloc(sizeof(node_t));
    if (!new_node) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    new_node->path = strdup(path);
    if (!new_node->path) {
        perror("strdup");
        exit(EXIT_FAILURE);
    }

    new_node->size = size;
    new_node->next = NULL;

    if (!list->head) {
        list->head = new_node;
    } else {
        list->tail->next = new_node;
    }

    list->tail = new_node;
}

void list_free(list_t *list) {
    node_t *current = list->head;
    while (current) {
        node_t *next = current->next;
        free(current->path);
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
}

int main(int argc, char *argv[]) {
    list_t list;
    list_init(&list);

    char *path = argv[1];
    if (!path) {
        path = ".";
    }

    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            char *new_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
            if (!new_path) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }

            sprintf(new_path, "%s/%s", path, entry->d_name);

            main(argc, new_path);

            free(new_path);
        } else {
            char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
            if (!full_path) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }

            sprintf(full_path, "%s/%s", path, entry->d_name);

            struct stat statbuf;
            if (lstat(full_path, &statbuf) == -1) {
                perror("lstat");
                exit(EXIT_FAILURE);
            }

            list_add(&list, full_path, statbuf.st_size);

            free(full_path);
        }
    }

    closedir(dir);

    node_t *current = list.head;
    while (current) {
        printf("%s: %lu\n", current->path, current->size);
        current = current->next;
    }

    list_free(&list);

    return EXIT_SUCCESS;
}