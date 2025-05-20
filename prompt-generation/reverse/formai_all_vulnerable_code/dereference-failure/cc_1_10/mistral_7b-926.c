//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct HeapNode {
    char path[1024];
    off_t size;
    struct HeapNode *left, *right;
} HeapNode;

HeapNode *heap = NULL;

off_t traverse(const char *path, off_t size) {
    DIR *dir;
    struct dirent *entry;
    struct stat info;
    off_t total = size;
    char new_path[1024];

    if ((dir = opendir(path)) == NULL) {
        return total;
    }

    while ((entry = readdir(dir)) != NULL) {
        snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            total += traverse(new_path, 0);
        } else {
            if (stat(new_path, &info) == -1) {
                continue;
            }

            total += info.st_size;

            HeapNode *new_node = (HeapNode *)malloc(sizeof(HeapNode));
            strcpy(new_node->path, new_path);
            new_node->size = info.st_size;

            if (heap == NULL) {
                heap = new_node;
            } else {
                HeapNode *current = heap;

                while (1) {
                    if (new_node->size > current->size) {
                        new_node->left = current;
                        current->right = new_node;
                        heap = new_node;
                        break;
                    }

                    if (current->left == NULL) {
                        current->left = new_node;
                        break;
                    }

                    current = current->left;
                }
            }
        }
    }

    closedir(dir);
    return total;
}

void print_largest_directories(int count) {
    HeapNode *current = heap;

    for (int i = 0; i < count && current != NULL; ++i) {
        printf("%d. %s (%ld bytes)\n", i + 1, current->path, current->size);
        current = current->right;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <mount_point>\n", argv[0]);
        return 1;
    }

    off_t total = traverse(argv[1], 0);
    printf("Total size of %s: %ld bytes\n", argv[1], total);

    print_largest_directories(5);

    HeapNode *current = heap;

    while (current != NULL) {
        HeapNode *temp = current;
        current = current->left;
        free(temp);
    }

    return 0;
}