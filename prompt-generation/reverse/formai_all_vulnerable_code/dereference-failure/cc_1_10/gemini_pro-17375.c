//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// File system structure
typedef struct inode {
    char name[32];
    int size;
    time_t timestamp;
    struct inode *next;
} inode;

// File system root directory
static inode *root = NULL;

// Current working directory
static inode *cwd = NULL;

// Initialize the file system
void fs_init() {
    root = malloc(sizeof(inode));
    strcpy(root->name, "/");
    root->size = 0;
    root->timestamp = time(NULL);
    root->next = NULL;
    cwd = root;
}

// Create a new file
void fs_create(char *name) {
    inode *new_file = malloc(sizeof(inode));
    strcpy(new_file->name, name);
    new_file->size = 0;
    new_file->timestamp = time(NULL);
    new_file->next = NULL;
    if (cwd == NULL) {
        printf("Error: Current working directory not set\n");
        return;
    }
    inode *p = cwd;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = new_file;
}

// Delete a file
void fs_delete(char *name) {
    if (cwd == NULL) {
        printf("Error: Current working directory not set\n");
        return;
    }
    inode *p = cwd, *prev = NULL;
    while (p != NULL && strcmp(p->name, name) != 0) {
        prev = p;
        p = p->next;
    }
    if (p == NULL) {
        printf("Error: File not found\n");
        return;
    }
    if (prev == NULL) {
        cwd = p->next;
    } else {
        prev->next = p->next;
    }
    free(p);
}

// Change the current working directory
void fs_cd(char *name) {
    if (strcmp(name, "/") == 0) {
        cwd = root;
        return;
    }
    if (cwd == NULL) {
        printf("Error: Current working directory not set\n");
        return;
    }
    inode *p = cwd;
    while (p != NULL && strcmp(p->name, name) != 0) {
        p = p->next;
    }
    if (p == NULL) {
        printf("Error: Directory not found\n");
        return;
    }
    cwd = p;
}

// List the contents of the current working directory
void fs_ls() {
    if (cwd == NULL) {
        printf("Error: Current working directory not set\n");
        return;
    }
    inode *p = cwd;
    while (p != NULL) {
        printf("%s\n", p->name);
        p = p->next;
    }
}

// Print the file system tree
void fs_tree(inode *node, int depth) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s\n", node->name);
    fs_tree(node->next, depth + 1);
}

// Main function
int main() {
    fs_init();

    fs_create("file1.txt");
    fs_create("file2.txt");
    fs_create("dir1");
    fs_cd("dir1");
    fs_create("file3.txt");
    fs_cd("..");

    fs_ls();
    printf("\n");
    fs_tree(root, 0);

    fs_delete("file2.txt");
    fs_delete("dir1");

    fs_ls();
    printf("\n");
    fs_tree(root, 0);

    return 0;
}