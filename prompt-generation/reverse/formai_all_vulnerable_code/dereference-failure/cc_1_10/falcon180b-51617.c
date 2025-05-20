//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_DEPTH 1000
#define BUFFER_SIZE 1024

typedef struct {
    char *path;
    int depth;
    size_t size;
} dir_t;

void traverse_directory(const char *path, int depth) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error: could not open directory %s\n", path);
        return;
    }

    dir_t *stack[MAX_DEPTH];
    int top = 0;

    stack[top++] = (dir_t *)malloc(sizeof(dir_t));
    stack[top - 1]->path = strdup(path);
    stack[top - 1]->depth = depth;
    stack[top - 1]->size = 0;

    while (1) {
        struct dirent *ent = readdir(dir);
        if (ent == NULL) {
            break;
        }

        if (ent->d_type == DT_DIR) {
            char *child_path = malloc(strlen(path) + strlen(ent->d_name) + 2);
            sprintf(child_path, "%s/%s", path, ent->d_name);

            if (top >= MAX_DEPTH) {
                printf("Error: directory tree too deep\n");
                break;
            }

            stack[top++] = (dir_t *)malloc(sizeof(dir_t));
            stack[top - 1]->path = strdup(child_path);
            stack[top - 1]->depth = depth + 1;
            stack[top - 1]->size = 0;
        } else {
            stack[top - 1]->size += ent->d_reclen;
        }
    }

    while (top > 0) {
        dir_t *current = stack[--top];
        current->size += current->depth * sizeof(char) + strlen(current->path) + 1;
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    char *path = argv[1];
    traverse_directory(path, 0);

    return 0;
}