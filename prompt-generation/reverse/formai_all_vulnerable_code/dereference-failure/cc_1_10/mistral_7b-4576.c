//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 256
#define BUF_SIZE 4096

struct node {
    char name[MAX_PATH_LENGTH];
    int size;
    int is_dir;
    struct node *parent;
    struct node *next;
};

void print_tree(struct node *root, int level) {
    struct node *current = root;
    int len = strlen(current->name);

    for (int i = 0; i < level; i++) {
        printf("/-");
    }

    if (current->is_dir) {
        printf("/%s/", current->name);
    } else {
        printf("/%s (%.2f%%, %ld bytes)", current->name, (float)current->size / (float)(1024 * 1024) * 100, current->size);
    }

    if (current->next != NULL) {
        print_tree(current->next, level + 1);
    }
}

void dfs(struct node *current, struct node *parent, int *total) {
    DIR *dir;
    struct dirent *entry;
    struct stat info;
    char path[MAX_PATH_LENGTH];

    if (current->is_dir) {
        if ((dir = opendir(current->name)) != NULL) {
            while ((entry = readdir(dir)) != NULL) {
                snprintf(path, MAX_PATH_LENGTH, "%s/%s", current->name, entry->d_name);
                struct node *new_node = (struct node *)malloc(sizeof(struct node));

                strcpy(new_node->name, path);
                new_node->parent = current;
                new_node->size = 0;
                new_node->is_dir = 1;

                if (entry->d_type == DT_DIR) {
                    new_node->next = NULL;
                    dfs(new_node, new_node, total);
                    current->next = new_node;
                } else {
                    if (stat(path, &info) == 0) {
                        new_node->size = info.st_size;
                        new_node->next = NULL;
                        current->next = new_node;
                        *total += new_node->size;
                    }
                }
            }
            closedir(dir);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    struct node *root = (struct node *)malloc(sizeof(struct node));
    strcpy(root->name, ".");
    root->parent = NULL;
    root->size = 0;
    root->is_dir = 1;
    root->next = NULL;

    int total_size = 0;
    dfs(root, root, &total_size);

    printf("\nTotal size of %s: %ld bytes\n", argv[1], total_size);
    print_tree(root, 0);

    while (root != NULL) {
        struct node *temp = root;
        root = root->next;
        free(temp);
    }

    return 0;
}