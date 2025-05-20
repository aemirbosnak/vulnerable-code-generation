//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {
    char magic[4]; // File signature
    int version; // Version number
    int count; // Number of entries
    char entries[0]; // Variable-length entries
} Directory;

typedef struct {
    int inode; // Inode number
    int offset; // Offset in file
} Entry;

void read_block(int fd, void *buf, int block) {
    lseek(fd, block * 512, SEEK_SET);
    read(fd, buf, 512);
}

Directory *read_directory(int fd) {
    Directory *dir = malloc(512);
    read_block(fd, dir, 0);

    if (strncmp(dir->magic, "DIR", 4)!= 0) {
        fprintf(stderr, "Invalid directory\n");
        exit(1);
    }

    return dir;
}

void print_entries(Directory *dir) {
    int i = 0;
    while (i < dir->count) {
        Entry *entry = (void *)&dir->entries[i];
        printf("%s\n", entry->inode == 0? "." : "..");
        i += sizeof(Entry);
    }

    for (; i < dir->count; i += sizeof(Entry)) {
        Entry *entry = (void *)&dir->entries[i];
        printf("%s\n", entry->inode == 0? "." : "..");
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <device>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Failed to open device\n");
        return 1;
    }

    Directory *root = read_directory(fd);
    print_entries(root);

    close(fd);
    return 0;
}