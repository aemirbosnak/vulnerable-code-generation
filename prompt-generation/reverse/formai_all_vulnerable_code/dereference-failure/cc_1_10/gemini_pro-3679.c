//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

struct node {
    char *name;
    size_t size;
    struct node *next;
};

struct node *head = NULL;
size_t total_size = 0;

static int cmp(const void *a, const void *b) {
    struct node *n1 = *(struct node **)a;
    struct node *n2 = *(struct node **)b;
    return n2->size - n1->size;
}

static void add_node(char *name, size_t size) {
    struct node *new_node = malloc(sizeof(struct node));
    if (!new_node) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    new_node->name = strdup(name);
    if (!new_node->name) {
        perror("strdup");
        exit(EXIT_FAILURE);
    }
    new_node->size = size;
    new_node->next = head;
    head = new_node;
    total_size += size;
}

static void traverse_directory(char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *new_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        if (!new_path) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        sprintf(new_path, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (lstat(new_path, &statbuf) == -1) {
            perror("lstat");
            exit(EXIT_FAILURE);
        }

        if (S_ISDIR(statbuf.st_mode)) {
            traverse_directory(new_path);
        } else if (S_ISREG(statbuf.st_mode)) {
            add_node(new_path, statbuf.st_size);
        }

        free(new_path);
    }

    closedir(dir);
}

static void print_report() {
    struct node **nodes = malloc(sizeof(struct node *) * total_size);
    if (!nodes) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    struct node *current = head;
    size_t i = 0;
    while (current) {
        nodes[i++] = current;
        current = current->next;
    }

    qsort(nodes, total_size, sizeof(struct node *), cmp);

    for (i = 0; i < total_size; i++) {
        printf("%s: %lu bytes\n", nodes[i]->name, nodes[i]->size);
        free(nodes[i]->name);
        free(nodes[i]);
    }

    free(nodes);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    traverse_directory(argv[1]);
    print_report();

    return EXIT_SUCCESS;
}