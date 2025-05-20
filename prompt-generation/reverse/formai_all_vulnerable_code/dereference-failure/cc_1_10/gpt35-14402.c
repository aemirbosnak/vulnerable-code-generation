//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define KB 1024
#define MB 1048576
#define GB 1073741824

typedef struct Node {
    char* name;
    unsigned long long size;
    struct Node* next;
} Node;

void getcwd_wrapper(char* path, size_t size) {
    // Wrapper around getcwd to handle errors if necessary
    if (getcwd(path, size) == NULL) {
        perror("getcwd error");
        exit(EXIT_FAILURE);
    }
}

char* get_basename(char* path) {
    // Get basename of file or directory path
    char* base = strrchr(path, '/');
    if (base != NULL) {
        return base + 1;
    } else {
        return path;
    }
}

void free_list(Node* head) {
    // Free linked list of Nodes
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current->name);
        free(current);
        current = next;
    }
}

void print_size(unsigned long long size) {
    // Print file size in appropriate units
    if (size >= GB) {
        printf("%.2f GB\n", (double) size / GB);
    } else if (size >= MB) {
        printf("%.2f MB\n", (double) size / MB);
    } else if (size >= KB) {
        printf("%.2f KB\n", (double) size / KB);
    } else {
        printf("%llu bytes\n", size);
    }
}

Node* create_node(char* name, unsigned long long size) {
    // Allocate memory for new Node and assign values
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }
    new_node->name = malloc(strlen(name) + 1);
    if (new_node->name == NULL) {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }
    strcpy(new_node->name, name);
    new_node->size = size;
    new_node->next = NULL;
    return new_node;
}

void insert_node(Node** head, Node* new_node) {
    // Insert new Node into linked list in sorted order by size
    Node* current = *head;
    if (*head == NULL || new_node->size >= (*head)->size) {
        new_node->next = *head;
        *head = new_node;
    } else {
        while (current->next != NULL && new_node->size < current->next->size) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void analyze_directory(char* path, Node** head) {
    // Analyze contents of directory and insert Nodes into linked list
    DIR* dir = opendir(path);
    if (dir == NULL) {
        perror("opendir error");
        exit(EXIT_FAILURE);
    }
    struct dirent* entry;
    char* subpath;
    struct stat statbuf;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            subpath = malloc(strlen(path) + strlen(entry->d_name) + 2);
            if (subpath == NULL) {
                perror("malloc error");
                exit(EXIT_FAILURE);
            }
            sprintf(subpath, "%s/%s", path, entry->d_name);
            if (stat(subpath, &statbuf) == -1) {
                perror("stat error");
                exit(EXIT_FAILURE);
            }
            if (S_ISDIR(statbuf.st_mode)) {
                analyze_directory(subpath, head);
            } else {
                insert_node(head, create_node(get_basename(subpath), statbuf.st_size));
            }
            free(subpath);
        }
    }
    closedir(dir);
}

int main() {
    char path[PATH_MAX];
    getcwd_wrapper(path, PATH_MAX);
    Node* head = NULL;
    analyze_directory(path, &head);
    Node* current = head;
    while (current != NULL) {
        printf("%-20s", current->name);
        print_size(current->size);
        current = current->next;
    }
    free_list(head);
    return 0;
}