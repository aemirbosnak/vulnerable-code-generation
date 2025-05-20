//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KB 1024
#define MB KB*KB
#define GB KB*MB

struct directory {
    char name[256];
    long long size;
    struct directory *subdir;
    struct directory *next;
};

void print_size(long long size);
void analyze_dir(struct directory *root, char *path);
void add_file(struct directory *root, char *path, long long size);
void add_subdir(struct directory *root, char *path);

int main(void) {
    struct directory root;
    root.name[0] = '/';
    root.name[1] = '\0';
    root.size = 0;
    root.subdir = NULL;
    root.next = NULL;

    analyze_dir(&root, "/");

    struct directory *curr = &root;
    while (curr != NULL) {
        printf("%s: ", curr->name);
        print_size(curr->size);
        printf("\n");
        curr = curr->next;
    }

    return 0;
}

void analyze_dir(struct directory *root, char *path) {
    char cmd[256];
    sprintf(cmd, "du -sb %s", path);

    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        perror("popen");
        exit(EXIT_FAILURE);
    }

    char buf[1024];
    if (fgets(buf, sizeof(buf), fp) != NULL) {
        char *size_token = strtok(buf, "\t");
        char *path_token = strtok(NULL, "\t");

        long long size = atoll(size_token);
        root->size += size;

        if (path_token[strlen(path_token)-1] == '\n') {
            path_token[strlen(path_token)-1] = '\0';
        }

        if (root->subdir == NULL) {
            root->subdir = malloc(sizeof(struct directory));
            strcpy(root->subdir->name, path_token);
            root->subdir->size = 0;
            root->subdir->subdir = NULL;
            root->subdir->next = NULL;
            analyze_dir(root->subdir, path_token);
        } else {
            struct directory *curr = root->subdir;
            while (curr->next != NULL) {
                curr = curr->next;
            }

            curr->next = malloc(sizeof(struct directory));
            strcpy(curr->next->name, path_token);
            curr->next->size = 0;
            curr->next->subdir = NULL;
            curr->next->next = NULL;
            analyze_dir(curr->next, path_token);
        }
    }

    pclose(fp);
}

void add_file(struct directory *root, char *path, long long size) {
    root->size += size;

    char *dir_name = strrchr(path, '/');
    if (dir_name == NULL) {
        return;
    }

    dir_name++;

    if (root->subdir == NULL) {
        root->subdir = malloc(sizeof(struct directory));
        strcpy(root->subdir->name, dir_name);
        root->subdir->size = 0;
        root->subdir->subdir = NULL;
        root->subdir->next = NULL;
        add_file(root->subdir, path, size);
    } else {
        struct directory *curr = root->subdir;
        while (curr->next != NULL) {
            if (strcmp(curr->name, dir_name) == 0) {
                add_file(curr, path, size);
                return;
            }

            curr = curr->next;
        }

        if (strcmp(curr->name, dir_name) == 0) {
            add_file(curr, path, size);
        } else {
            curr->next = malloc(sizeof(struct directory));
            strcpy(curr->next->name, dir_name);
            curr->next->size = 0;
            curr->next->subdir = NULL;
            curr->next->next = NULL;
            add_file(curr->next, path, size);
        }
    }
}

void add_subdir(struct directory *root, char *path) {
    char *dir_name = strrchr(path, '/');
    if (dir_name == NULL) {
        return;
    }

    dir_name++;

    if (root->subdir == NULL) {
        root->subdir = malloc(sizeof(struct directory));
        strcpy(root->subdir->name, dir_name);
        root->subdir->size = 0;
        root->subdir->subdir = NULL;
        root->subdir->next = NULL;
    } else {
        struct directory *curr = root->subdir;
        while (curr->next != NULL) {
            if (strcmp(curr->name, dir_name) == 0) {
                return;
            }

            curr = curr->next;
        }

        if (strcmp(curr->name, dir_name) == 0) {
            return;
        } else {
            curr->next = malloc(sizeof(struct directory));
            strcpy(curr->next->name, dir_name);
            curr->next->size = 0;
            curr->next->subdir = NULL;
            curr->next->next = NULL;
        }
    }
}

void print_size(long long size) {
    if (size < KB) {
        printf("%lld bytes", size);
    } else if (size < MB) {
        printf("%.2f KB", (double) size / KB);
    } else if (size < GB) {
        printf("%.2f MB", (double) size / MB);
    } else {
        printf("%.2f GB", (double) size / GB);
    }
}