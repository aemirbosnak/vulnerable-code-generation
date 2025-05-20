//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct Node {
    char *name;
    size_t size;
    struct Node *next;
} Node;

Node *head = NULL;

void insert(char *name, size_t size) {
    Node *new_node = malloc(sizeof(Node));
    new_node->name = strdup(name);
    new_node->size = size;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list() {
    Node *current = head;
    while (current != NULL) {
        printf("%s: %zu bytes\n", current->name, current->size);
        current = current->next;
    }
}

void analyze_directory(char *path) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        strcpy(full_path, path);
        strcat(full_path, "/");
        strcat(full_path, entry->d_name);
        struct stat st;
        if (lstat(full_path, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                analyze_directory(full_path);
            } else {
                insert(entry->d_name, st.st_size);
            }
        }
        free(full_path);
    }
    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }
    analyze_directory(argv[1]);
    print_list();
    return 0;
}