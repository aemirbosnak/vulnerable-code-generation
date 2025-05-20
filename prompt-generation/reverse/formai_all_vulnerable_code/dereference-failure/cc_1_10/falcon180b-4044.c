//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096

typedef struct {
    char magic[2];
    int version;
    int num_blocks;
    int block_size;
    int num_inodes;
    int num_free_blocks;
    int num_free_inodes;
    int root_inode;
} Superblock;

typedef struct {
    int inode_num;
    int size;
    int num_blocks;
    int block_map[12];
} Inode;

typedef struct {
    int inode_num;
    char name[256];
} DirEntry;

void print_inode(Inode *inode) {
    printf("Inode %d:\n", inode->inode_num);
    printf("Size: %d\n", inode->size);
    printf("Num blocks: %d\n", inode->num_blocks);
    printf("Block map:\n");
    for (int i = 0; i < inode->num_blocks; i++) {
        printf("%d ", inode->block_map[i]);
    }
    printf("\n");
}

void print_dir_entry(DirEntry *entry) {
    printf("%s\n", entry->name);
}

void print_dir(int inode_num) {
    FILE *fp;
    char buffer[BLOCK_SIZE];

    fp = fopen("data.img", "rb");
    fseek(fp, (inode_num - 1) * BLOCK_SIZE, SEEK_SET);
    fread(buffer, BLOCK_SIZE, 1, fp);
    fclose(fp);

    Superblock *sb = (Superblock *)buffer;
    Inode *inode = (Inode *)&buffer[sizeof(Superblock)];
    DirEntry *dir_entries = (DirEntry *)&buffer[sizeof(Superblock) + sb->num_inodes * sizeof(Inode)];

    for (int i = 0; i < sb->num_inodes; i++) {
        if (inode->inode_num == inode_num) {
            printf("Directory contents:\n");
            for (int j = 0; j < inode->size; j += sizeof(DirEntry)) {
                print_dir_entry(&dir_entries[j]);
            }
            break;
        }
        inode++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s inode_num\n", argv[0]);
        exit(1);
    }

    int inode_num = atoi(argv[1]);

    print_dir(inode_num);

    return 0;
}