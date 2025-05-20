//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_LINE 1024

struct dir_ent {
    char name[1024];
    struct dir_ent *next;
};

struct dir_ent *root;

void init_dir(void) {
    root = NULL;
}

void add_dir(char *path) {
    struct dir_ent *new_ent = malloc(sizeof(struct dir_ent));
    strcpy(new_ent->name, path);
    new_ent->next = root;
    root = new_ent;
}

void del_dir(char *path) {
    struct dir_ent *cur = root;
    struct dir_ent *prev = NULL;

    while (cur != NULL) {
        if (strcmp(cur->name, path) == 0) {
            if (prev == NULL) {
                root = cur->next;
            } else {
                prev->next = cur->next;
            }
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

int main(void) {
    init_dir();

    char path[MAX_PATH];
    char line[MAX_LINE];

    while (1) {
        printf("> ");
        fgets(path, MAX_PATH, stdin);
        char *ptr = strchr(path, '\n');
        if (ptr != NULL) {
            *ptr = '\0';
        }

        add_dir(path);

        printf("Added directory: %s\n", path);

        printf("Remove directory (enter 'q' to quit): ");
        fgets(line, MAX_LINE, stdin);

        if (strcmp(line, "q") == 0) {
            break;
        }

        del_dir(line);
    }

    return 0;
}