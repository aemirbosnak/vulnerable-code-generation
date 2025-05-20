//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define MAX_PATH 256
#define BUF_SIZE 4096

typedef struct file_info {
    char name[MAX_PATH];
    off_t size;
    struct file_info *next;
} file_info;

file_info *root = NULL;

void add_to_list(char *path, off_t size) {
    file_info *new_node = (file_info *)malloc(sizeof(file_info));
    strcpy(new_node->name, path);
    new_node->size = size;
    new_node->next = root;
    root = new_node;
}

void traverse_directory(char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        struct stat st;
        if (stat(full_path, &st) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            traverse_directory(full_path);
        } else {
            add_to_list(full_path, st.st_size);
        }
    }

    closedir(dir);
}

void print_files(file_info *list) {
    file_info *current = list;
    while (current != NULL) {
        printf("%-30s  %10ld bytes\n", current->name, current->size);
        file_info *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    printf("\033[1;32m***** Happy Disk Space Analyzer *****\033[0m\n");

    char cwd[MAX_PATH];
    getcwd(cwd, sizeof(cwd));
    traverse_directory(cwd);

    printf("\n***** Your disk usage report *****\n\n");
    print_files(root);

    file_info *temp = root;
    while (root != NULL) {
        temp = root;
        root = root->next;
        free(temp);
    }

    return 0;
}