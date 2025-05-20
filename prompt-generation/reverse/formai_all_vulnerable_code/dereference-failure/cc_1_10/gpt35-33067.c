//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MB (1024 * 1024)

struct Folder {
    char *name;
    double size;
    struct Folder *parent;
    struct Folder *child;
    struct Folder *next;
};

struct Folder *make_folder(char *name, struct Folder *parent) {
    struct Folder *folder = malloc(sizeof(struct Folder));
    folder->name = name;
    folder->size = 0;
    folder->parent = parent;
    folder->child = NULL;
    folder->next = NULL;
    return folder;
}

void destroy_folder(struct Folder *folder) {
    if (folder == NULL)
        return;
    destroy_folder(folder->next);
    destroy_folder(folder->child);
    free(folder->name);
    free(folder);
}

void add_folder(struct Folder *parent, struct Folder *child) {
    child->parent = parent;
    child->next = parent->child;
    parent->child = child;
}

void add_size(struct Folder *folder, double size) {
    while (folder != NULL) {
        folder->size += size;
        folder = folder->parent;
    }
}

int print_folder(struct Folder *folder, int depth, int max_depth) {
    int total = 1;
    printf("%*s%s: %.1lf MB\n", depth * 2, "", folder->name, folder->size / MB);
    if (depth < max_depth) {
        struct Folder *child = folder->child;
        while (child != NULL) {
            total += print_folder(child, depth + 1, max_depth);
            child = child->next;
        }
    }
    return total;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s directory\n", argv[0]);
        return 1;
    }

    struct Folder *root = make_folder("root", NULL);

    char *path = malloc(strlen(argv[1]) + 2);
    sprintf(path, "%s/", argv[1]);

    int len = strlen(path);
    for (int i = len - 1; i >= 0; i--) {
        if (path[i] == '/') {
            path[i] = '\0';
            struct Folder *parent = root;
            int j = i + 1;
            while (path[j] != '\0') {
                struct Folder *child = parent->child;
                while (child != NULL && strcmp(child->name, path + j) != 0)
                    child = child->next;
                if (child == NULL)
                    child = make_folder(strdup(path + j), parent);
                add_folder(parent, child);
                parent = child;
                while (path[j] != '\0' && path[j] != '/')
                    j++;
            }
        }
    }

    struct stat buf;
    if (stat(argv[1], &buf) != 0) {
        perror(argv[1]);
        return 1;
    }
    add_size(root, buf.st_size);

    char *command = malloc(len + 11);
    sprintf(command, "du -bs %s", argv[1]);

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror(command);
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *size_str = strtok(line, "\t ");
        char *path = strtok(NULL, "\n");
        if (path != NULL) {
            struct Folder *folder = root->child;
            while (folder != NULL && strcmp(folder->name, path) != 0)
                folder = folder->next;
            if (folder != NULL) {
                double size = atof(size_str);
                add_size(folder, size);
            } else {
                fprintf(stderr, "Error: file not found: %s\n", path);
            }
        }
    }

    int total = print_folder(root, 0, 2);
    printf("%d folders and files scanned.\n", total);

    pclose(fp);
    free(command);
    free(path);
    destroy_folder(root);

    return 0;
}