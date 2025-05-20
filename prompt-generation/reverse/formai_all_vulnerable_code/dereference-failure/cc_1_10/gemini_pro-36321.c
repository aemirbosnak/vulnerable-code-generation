//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: retro
// Retro File System Simulator in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// File system structure
struct FileSystem {
    int numBlocks;     // Total number of blocks
    int blockSize;     // Size of each block in bytes
    int numInodes;    // Total number of inodes
    int inodeSize;    // Size of each inode in bytes
    char *data;        // Data blocks
    char *inodes;      // Inodes
};

// Initialize the file system
struct FileSystem *initFileSystem(int numBlocks, int blockSize, int numInodes, int inodeSize) {
    struct FileSystem *fs = malloc(sizeof(struct FileSystem));
    fs->numBlocks = numBlocks;
    fs->blockSize = blockSize;
    fs->numInodes = numInodes;
    fs->inodeSize = inodeSize;
    fs->data = malloc(numBlocks * blockSize);
    fs->inodes = malloc(numInodes * inodeSize);
    return fs;
}

// Create a new file
int createFile(struct FileSystem *fs, char *name) {
    // Find a free inode
    int inode = -1;
    for (int i = 0; i < fs->numInodes; i++) {
        if (fs->inodes[i] == 0) {
            inode = i;
            break;
        }
    }

    if (inode == -1) {
        printf("Error: No free inodes\n");
        return -1;
    }

    // Set the inode's file name
    strcpy(&fs->inodes[inode * fs->inodeSize], name);

    // Set the inode's file size to 0
    memset(&fs->inodes[inode * fs->inodeSize + fs->inodeSize / 2], 0, fs->inodeSize / 2);

    // Set the inode's file type to regular file
    fs->inodes[inode * fs->inodeSize + fs->inodeSize / 2 - 1] = 1;

    return inode;
}

// Open a file
int openFile(struct FileSystem *fs, char *name) {
    // Find the inode for the file
    int inode = -1;
    for (int i = 0; i < fs->numInodes; i++) {
        if (strcmp(&fs->inodes[i * fs->inodeSize], name) == 0) {
            inode = i;
            break;
        }
    }

    if (inode == -1) {
        printf("Error: File not found\n");
        return -1;
    }

    return inode;
}

// Write data to a file
int writeFile(struct FileSystem *fs, int inode, char *data, int size) {
    // Check if the file is open
    if (fs->inodes[inode * fs->inodeSize] == 0) {
        printf("Error: File not open\n");
        return -1;
    }

    // Check if there is enough space to write the data
    int fileSize = fs->inodes[inode * fs->inodeSize + fs->inodeSize / 2];
    if (fileSize + size > fs->numBlocks * fs->blockSize) {
        printf("Error: Not enough space\n");
        return -1;
    }

    // Write the data to the file
    memcpy(&fs->data[fileSize], data, size);

    // Update the file size
    fs->inodes[inode * fs->inodeSize + fs->inodeSize / 2] += size;

    return size;
}

// Read data from a file
int readFile(struct FileSystem *fs, int inode, char *data, int size) {
    // Check if the file is open
    if (fs->inodes[inode * fs->inodeSize] == 0) {
        printf("Error: File not open\n");
        return -1;
    }

    // Check if there is enough data to read
    int fileSize = fs->inodes[inode * fs->inodeSize + fs->inodeSize / 2];
    if (size > fileSize) {
        printf("Error: Not enough data\n");
        return -1;
    }

    // Read the data from the file
    memcpy(data, &fs->data[fileSize - size], size);

    return size;
}

// Close a file
int closeFile(struct FileSystem *fs, int inode) {
    // Check if the file is open
    if (fs->inodes[inode * fs->inodeSize] == 0) {
        printf("Error: File not open\n");
        return -1;
    }

    // Set the inode's file name to 0
    memset(&fs->inodes[inode * fs->inodeSize], 0, fs->inodeSize);

    return 0;
}

// Print the file system
void printFileSystem(struct FileSystem *fs) {
    printf("File System:\n");
    printf("  Num Blocks: %d\n", fs->numBlocks);
    printf("  Block Size: %d\n", fs->blockSize);
    printf("  Num Inodes: %d\n", fs->numInodes);
    printf("  Inode Size: %d\n", fs->inodeSize);
    printf("  Data Blocks:\n");
    for (int i = 0; i < fs->numBlocks; i++) {
        printf("    Block %d: %s\n", i, &fs->data[i * fs->blockSize]);
    }
    printf("  Inodes:\n");
    for (int i = 0; i < fs->numInodes; i++) {
        printf("    Inode %d:\n", i);
        printf("      Name: %s\n", &fs->inodes[i * fs->inodeSize]);
        printf("      Size: %d\n", fs->inodes[i * fs->inodeSize + fs->inodeSize / 2]);
        printf("      Type: %d\n", fs->inodes[i * fs->inodeSize + fs->inodeSize / 2 - 1]);
    }
}

// Free the file system
void freeFileSystem(struct FileSystem *fs) {
    free(fs->data);
    free(fs->inodes);
    free(fs);
}

// Main function
int main() {
    // Create a new file system
    struct FileSystem *fs = initFileSystem(10, 512, 10, 128);

    // Create a new file
    int inode = createFile(fs, "file1.txt");

    // Open the file
    inode = openFile(fs, "file1.txt");

    // Write data to the file
    writeFile(fs, inode, "Hello, world!", 13);

    // Read data from the file
    char data[13];
    readFile(fs, inode, data, 13);

    // Print the data
    printf("Data: %s\n", data);

    // Close the file
    closeFile(fs, inode);

    // Print the file system
    printFileSystem(fs);

    // Free the file system
    freeFileSystem(fs);

    return 0;
}