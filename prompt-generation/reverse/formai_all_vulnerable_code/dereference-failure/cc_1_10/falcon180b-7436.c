//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_NAME_LENGTH 32
#define MAX_FILE_SIZE 1000

#define NODE_TYPE_FILE 1
#define NODE_TYPE_DIR 2

#define NODE_SIZE 32

typedef struct node {
    int type;
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char data[NODE_SIZE];
} node_t;

typedef struct directory {
    int num_nodes;
    node_t nodes[MAX_FILE_SIZE];
} directory_t;

directory_t* create_directory() {
    directory_t* dir = malloc(sizeof(directory_t));
    if (dir == NULL) {
        printf("Error: Failed to create directory\n");
        exit(1);
    }
    dir->num_nodes = 0;
    return dir;
}

int add_node(directory_t* dir, int type, char* name, int size, char* data) {
    node_t* node = malloc(sizeof(node_t));
    if (node == NULL) {
        printf("Error: Failed to add node\n");
        exit(1);
    }
    node->type = type;
    strcpy(node->name, name);
    node->size = size;
    memcpy(node->data, data, size);
    dir->nodes[dir->num_nodes++] = *node;
    free(node);
    return dir->num_nodes - 1;
}

int find_node(directory_t* dir, char* name) {
    int i;
    for (i = 0; i < dir->num_nodes; i++) {
        if (strcmp(dir->nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    directory_t* dir = create_directory();
    add_node(dir, NODE_TYPE_FILE, "file1.txt", 10, "Hello world!");
    int file1_index = find_node(dir, "file1.txt");
    printf("File1 index: %d\n", file1_index);
    add_node(dir, NODE_TYPE_DIR, "folder1", 0, "");
    int folder1_index = find_node(dir, "folder1");
    printf("Folder1 index: %d\n", folder1_index);
    add_node(dir, NODE_TYPE_FILE, "folder1/file2.txt", 20, "This is file2 in folder1");
    int file2_index = find_node(dir, "folder1/file2.txt");
    printf("File2 index: %d\n", file2_index);
    return 0;
}