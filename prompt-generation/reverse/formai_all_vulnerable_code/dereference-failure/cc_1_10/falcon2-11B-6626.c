//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FileSystem
{
    char* name;
    char* path;
    int size;
    int block_size;
    int blocks;
    int blocks_free;
    int inodes;
    int inodes_free;
    int meta_block_size;
    int meta_block_free;
};

struct Inode
{
    char* name;
    char* path;
    int size;
    int blocks;
    int block_size;
    int blocks_free;
    int inodes;
    int inodes_free;
    int meta_block_size;
    int meta_block_free;
};

struct Block
{
    int block_number;
    char* data;
};

struct Directory
{
    char* name;
    char* path;
    int size;
    int blocks;
    int block_size;
    int blocks_free;
    int inodes;
    int inodes_free;
    int meta_block_size;
    int meta_block_free;
};

struct MetaBlock
{
    char* name;
    char* path;
    int size;
    int blocks;
    int block_size;
    int blocks_free;
    int inodes;
    int inodes_free;
    int meta_block_size;
    int meta_block_free;
};

struct FileSystem* createFileSystem(char* name, char* path, int size, int block_size)
{
    struct FileSystem* fs = malloc(sizeof(struct FileSystem));
    if (fs == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    fs->name = strdup(name);
    fs->path = strdup(path);
    fs->size = size;
    fs->block_size = block_size;
    fs->blocks = size / block_size;
    fs->blocks_free = fs->blocks;
    fs->inodes = 0;
    fs->inodes_free = 0;
    fs->meta_block_size = sizeof(struct MetaBlock);
    fs->meta_block_free = 1;
    
    return fs;
}

struct Inode* createInode(struct FileSystem* fs, char* name, char* path, int size, int block_size)
{
    struct Inode* inode = malloc(sizeof(struct Inode));
    if (inode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    inode->name = strdup(name);
    inode->path = strdup(path);
    inode->size = size;
    inode->blocks = 0;
    inode->block_size = block_size;
    inode->blocks_free = fs->blocks_free;
    inode->inodes = 0;
    inode->inodes_free = 0;
    inode->meta_block_size = sizeof(struct MetaBlock);
    inode->meta_block_free = 1;
    
    return inode;
}

struct Block* createBlock(struct Inode* inode, int block_number, char* data)
{
    struct Block* block = malloc(sizeof(struct Block));
    if (block == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    block->block_number = block_number;
    block->data = strdup(data);
    
    return block;
}

struct Directory* createDirectory(struct Inode* inode, char* name, char* path, int size, int block_size)
{
    struct Directory* dir = malloc(sizeof(struct Directory));
    if (dir == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    dir->name = strdup(name);
    dir->path = strdup(path);
    dir->size = size;
    dir->blocks = 0;
    dir->block_size = block_size;
    dir->blocks_free = inode->blocks_free;
    dir->inodes = 0;
    dir->inodes_free = 0;
    dir->meta_block_size = sizeof(struct MetaBlock);
    dir->meta_block_free = 1;
    
    return dir;
}

struct MetaBlock* createMetaBlock(struct Inode* inode, char* name, char* path, int size, int block_size)
{
    struct MetaBlock* meta_block = malloc(sizeof(struct MetaBlock));
    if (meta_block == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    meta_block->name = strdup(name);
    meta_block->path = strdup(path);
    meta_block->size = size;
    meta_block->blocks = 0;
    meta_block->block_size = block_size;
    meta_block->blocks_free = inode->blocks_free;
    meta_block->inodes = 0;
    meta_block->inodes_free = 0;
    meta_block->meta_block_size = sizeof(struct MetaBlock);
    meta_block->meta_block_free = 1;
    
    return meta_block;
}

void freeFileSystem(struct FileSystem* fs)
{
    free(fs->name);
    free(fs->path);
    free(fs);
}

void freeInode(struct Inode* inode)
{
    free(inode->name);
    free(inode->path);
    free(inode);
}

void freeBlock(struct Block* block)
{
    free(block->data);
    free(block);
}

void freeDirectory(struct Directory* dir)
{
    free(dir->name);
    free(dir->path);
    free(dir);
}

void freeMetaBlock(struct MetaBlock* meta_block)
{
    free(meta_block->name);
    free(meta_block->path);
    free(meta_block);
}

void printFileSystem(struct FileSystem* fs)
{
    printf("Name: %s\n", fs->name);
    printf("Path: %s\n", fs->path);
    printf("Size: %d\n", fs->size);
    printf("Block size: %d\n", fs->block_size);
    printf("Blocks: %d\n", fs->blocks);
    printf("Blocks free: %d\n", fs->blocks_free);
    printf("Inodes: %d\n", fs->inodes);
    printf("Inodes free: %d\n", fs->inodes_free);
    printf("Meta block size: %d\n", fs->meta_block_size);
    printf("Meta block free: %d\n", fs->meta_block_free);
}

void printInode(struct Inode* inode)
{
    printf("Name: %s\n", inode->name);
    printf("Path: %s\n", inode->path);
    printf("Size: %d\n", inode->size);
    printf("Blocks: %d\n", inode->blocks);
    printf("Block size: %d\n", inode->block_size);
    printf("Blocks free: %d\n", inode->blocks_free);
    printf("Inodes: %d\n", inode->inodes);
    printf("Inodes free: %d\n", inode->inodes_free);
    printf("Meta block size: %d\n", inode->meta_block_size);
    printf("Meta block free: %d\n", inode->meta_block_free);
}

void printBlock(struct Block* block)
{
    printf("Block number: %d\n", block->block_number);
    printf("Data: %s\n", block->data);
}

void printDirectory(struct Directory* dir)
{
    printf("Name: %s\n", dir->name);
    printf("Path: %s\n", dir->path);
    printf("Size: %d\n", dir->size);
    printf("Blocks: %d\n", dir->blocks);
    printf("Block size: %d\n", dir->block_size);
    printf("Blocks free: %d\n", dir->blocks_free);
    printf("Inodes: %d\n", dir->inodes);
    printf("Inodes free: %d\n", dir->inodes_free);
    printf("Meta block size: %d\n", dir->meta_block_size);
    printf("Meta block free: %d\n", dir->meta_block_free);
}

void printMetaBlock(struct MetaBlock* meta_block)
{
    printf("Name: %s\n", meta_block->name);
    printf("Path: %s\n", meta_block->path);
    printf("Size: %d\n", meta_block->size);
    printf("Blocks: %d\n", meta_block->blocks);
    printf("Block size: %d\n", meta_block->block_size);
    printf("Blocks free: %d\n", meta_block->blocks_free);
    printf("Inodes: %d\n", meta_block->inodes);
    printf("Inodes free: %d\n", meta_block->inodes_free);
    printf("Meta block size: %d\n", meta_block->meta_block_size);
    printf("Meta block free: %d\n", meta_block->meta_block_free);
}

int main()
{
    struct FileSystem* fs = createFileSystem("File System", "/", 100, 512);
    struct Inode* inode = createInode(fs, "File 1", "/File 1", 100, 512);
    struct Block* block = createBlock(inode, 0, "Data 1");
    struct Directory* dir = createDirectory(inode, "Subdir", "/File 1/Subdir", 100, 512);
    struct MetaBlock* meta_block = createMetaBlock(inode, "MetaBlock", "/File 1/MetaBlock", 100, 512);
    
    printFileSystem(fs);
    printInode(inode);
    printBlock(block);
    printDirectory(dir);
    printMetaBlock(meta_block);
    
    freeFileSystem(fs);
    freeInode(inode);
    freeBlock(block);
    freeDirectory(dir);
    freeMetaBlock(meta_block);
    
    return 0;
}