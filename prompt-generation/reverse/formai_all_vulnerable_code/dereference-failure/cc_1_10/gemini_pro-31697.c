//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct inode {
    int size;
    char *data;
} inode_t;

typedef struct directory {
    int num_entries;
    struct directory_entry {
        char *name;
        inode_t *inode;
    } *entries;
} directory_t;

directory_t *root_dir;

inode_t *create_inode(int size) {
    inode_t *inode = malloc(sizeof(inode_t));
    inode->size = size;
    inode->data = malloc(size);
    return inode;
}

void destroy_inode(inode_t *inode) {
    free(inode->data);
    free(inode);
}

directory_t *create_directory() {
    directory_t *dir = malloc(sizeof(directory_t));
    dir->num_entries = 0;
    dir->entries = NULL;
    return dir;
}

void destroy_directory(directory_t *dir) {
    for (int i = 0; i < dir->num_entries; i++) {
        free(dir->entries[i].name);
        destroy_inode(dir->entries[i].inode);
    }
    free(dir->entries);
    free(dir);
}

void add_entry_to_directory(directory_t *dir, char *name, inode_t *inode) {
    dir->entries = realloc(dir->entries, (dir->num_entries + 1) * sizeof(struct directory_entry));
    dir->entries[dir->num_entries].name = malloc(strlen(name) + 1);
    strcpy(dir->entries[dir->num_entries].name, name);
    dir->entries[dir->num_entries].inode = inode;
    dir->num_entries++;
}

inode_t *find_inode_in_directory(directory_t *dir, char *name) {
    for (int i = 0; i < dir->num_entries; i++) {
        if (strcmp(dir->entries[i].name, name) == 0) {
            return dir->entries[i].inode;
        }
    }
    return NULL;
}

void print_directory(directory_t *dir, int depth) {
    for (int i = 0; i < dir->num_entries; i++) {
        printf("%*s%s\n", depth * 2, "", dir->entries[i].name);
        if (dir->entries[i].inode->size == 0) {
            print_directory(dir->entries[i].inode->data, depth + 1);
        }
    }
}

int main() {
    root_dir = create_directory();

    inode_t *file1 = create_inode(10);
    strcpy(file1->data, "Hello, world!");
    add_entry_to_directory(root_dir, "file1.txt", file1);

    inode_t *dir1 = create_directory();
    add_entry_to_directory(root_dir, "dir1", dir1);

    inode_t *file2 = create_inode(20);
    strcpy(file2->data, "This is a longer file.");
    add_entry_to_directory(dir1, "file2.txt", file2);

    print_directory(root_dir, 0);

    destroy_directory(root_dir);

    return 0;
}