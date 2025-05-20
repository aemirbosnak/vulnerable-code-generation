//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/mman.h>

#define BLOCK_SIZE 4096
#define INODE_SIZE 256
#define DIR_ENTRY_SIZE 1024
#define MAX_FILES_PER_DIR 65535

typedef struct inode {
    uid_t i_uid;
    gid_t i_gid;
    dev_t i_dev;
    int i_nlink;
    off_t i_size;
    int i_atime, i_mtime, i_ctime;
    int i_flags;
    int i_blocks[12];
} inode_t;

void print_inode(inode_t *inode) {
    printf("UID: %d, GID: %d, Device: %d, Links: %d, Size: %ld\n",
           inode->i_uid, inode->i_gid, inode->i_dev, inode->i_nlink, inode->i_size);
}

void print_blocks(inode_t *inode) {
    int i;
    printf("Blocks: ");
    for (i = 0; i < 12; i++) {
        if (inode->i_blocks[i] > 0)
            printf("%d ", inode->i_blocks[i]);
    }
    printf("\n");
}

void print_dir_entry(char *entry, int size) {
    char name[256];
    memset(name, 0, sizeof(name));
    strncpy(name, entry, strlen(entry) < 255 ? strlen(entry) : 255);
    printf("%s  %ld bytes\n", name, atoi(entry + strlen(name) + 1));
}

void print_dir(char *path) {
    DIR *dir;
    struct dirent *entry;
    char buf[DIR_ENTRY_SIZE];

    if ((dir = opendir(path)) == NULL) {
        perror("Error opening directory");
        return;
    }

    printf("%s:\n", path);
    while ((entry = readdir(dir)) != NULL) {
        read(dirfd(dir), buf, DIR_ENTRY_SIZE);
        print_dir_entry(buf, DIR_ENTRY_SIZE);
    }

    closedir(dir);
}

void analyze_file(char *path) {
    struct stat file_stat;
    inode_t *inode;

    if (stat(path, &file_stat) < 0) {
        perror("Error getting file stats");
        return;
    }

    if (S_ISDIR(file_stat.st_mode)) {
        print_dir(path);
        return;
    }

    if ((inode = mmap(NULL, INODE_SIZE, PROT_READ, MAP_PRIVATE, file_stat.st_dev, file_stat.st_ino)) == MAP_FAILED) {
        perror("Error mapping inode");
        return;
    }

    print_inode(inode);
    print_blocks(inode);

    munmap(inode, INODE_SIZE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    analyze_file(argv[1]);

    return 0;
}