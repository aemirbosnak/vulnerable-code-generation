//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// File system simulation

// Inode table
struct inode {
    int size;
    int blocks[10];
};

// Directory entry
struct dir_entry {
    char name[32];
    int inode_num;
};

// File system
struct fs {
    struct inode inodes[10];
    struct dir_entry dir[10];
    int n_inodes;
    int n_dir;
};

// Create a new file system
struct fs *create_fs() {
    struct fs *fs = malloc(sizeof(struct fs));
    fs->n_inodes = 0;
    fs->n_dir = 0;
    return fs;
}

// Create a new inode
int create_inode(struct fs *fs, int size) {
    if (fs->n_inodes >= 10) {
        return -1;
    }
    struct inode *inode = &fs->inodes[fs->n_inodes++];
    inode->size = size;
    for (int i = 0; i < 10; i++) {
        inode->blocks[i] = -1;
    }
    return fs->n_inodes - 1;
}

// Create a new directory entry
int create_dir_entry(struct fs *fs, char *name, int inode_num) {
    if (fs->n_dir >= 10) {
        return -1;
    }
    struct dir_entry *dir_entry = &fs->dir[fs->n_dir++];
    strcpy(dir_entry->name, name);
    dir_entry->inode_num = inode_num;
    return fs->n_dir - 1;
}

// Find a directory entry by name
int find_dir_entry(struct fs *fs, char *name) {
    for (int i = 0; i < fs->n_dir; i++) {
        if (strcmp(fs->dir[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Print the file system
void print_fs(struct fs *fs) {
    printf("Inodes:\n");
    for (int i = 0; i < fs->n_inodes; i++) {
        printf("  %d: size=%d, blocks=", i, fs->inodes[i].size);
        for (int j = 0; j < 10; j++) {
            printf(" %d", fs->inodes[i].blocks[j]);
        }
        printf("\n");
    }
    printf("Directory:\n");
    for (int i = 0; i < fs->n_dir; i++) {
        printf("  %s: inode=%d\n", fs->dir[i].name, fs->dir[i].inode_num);
    }
}

int main() {
    // Create a new file system
    struct fs *fs = create_fs();

    // Create a new inode for a file of size 100
    int inode_num = create_inode(fs, 100);

    // Create a new directory entry for the file
    create_dir_entry(fs, "file.txt", inode_num);

    // Print the file system
    print_fs(fs);

    return 0;
}