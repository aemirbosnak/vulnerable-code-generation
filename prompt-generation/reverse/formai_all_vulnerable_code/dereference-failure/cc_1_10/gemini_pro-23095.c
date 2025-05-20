//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// File system simulator
struct file_system {
    int num_blocks;
    int block_size;
    char *data;
};

// Create a new file system
struct file_system *create_file_system(int num_blocks, int block_size) {
    struct file_system *fs = malloc(sizeof(struct file_system));
    fs->num_blocks = num_blocks;
    fs->block_size = block_size;
    fs->data = malloc(num_blocks * block_size);
    return fs;
}

// Destroy a file system
void destroy_file_system(struct file_system *fs) {
    free(fs->data);
    free(fs);
}

// Read a block from the file system
int read_block(struct file_system *fs, int block_num, char *buf) {
    if (block_num < 0 || block_num >= fs->num_blocks) {
        return -1;
    }
    memcpy(buf, fs->data + block_num * fs->block_size, fs->block_size);
    return 0;
}

// Write a block to the file system
int write_block(struct file_system *fs, int block_num, char *buf) {
    if (block_num < 0 || block_num >= fs->num_blocks) {
        return -1;
    }
    memcpy(fs->data + block_num * fs->block_size, buf, fs->block_size);
    return 0;
}

// Create a new file
int create_file(struct file_system *fs, char *name) {
    // Find a free block
    int block_num = -1;
    for (int i = 0; i < fs->num_blocks; i++) {
        if (fs->data[i * fs->block_size] == 0) {
            block_num = i;
            break;
        }
    }

    if (block_num == -1) {
        return -1;
    }

    // Write the file name to the block
    memcpy(fs->data + block_num * fs->block_size, name, strlen(name) + 1);

    return block_num;
}

// Open a file
int open_file(struct file_system *fs, char *name) {
    // Find the file block
    int block_num = -1;
    for (int i = 0; i < fs->num_blocks; i++) {
        if (strcmp(fs->data + i * fs->block_size, name) == 0) {
            block_num = i;
            break;
        }
    }

    if (block_num == -1) {
        return -1;
    }

    return block_num;
}

// Read from a file
int read_file(struct file_system *fs, int file_num, char *buf) {
    // Read the file block
    int block_num = file_num;
    if (read_block(fs, block_num, buf) != 0) {
        return -1;
    }

    // Return the number of bytes read
    return fs->block_size;
}

// Write to a file
int write_file(struct file_system *fs, int file_num, char *buf) {
    // Read the file block
    int block_num = file_num;
    if (read_block(fs, block_num, buf) != 0) {
        return -1;
    }

    // Write the file block
    if (write_block(fs, block_num, buf) != 0) {
        return -1;
    }

    // Return the number of bytes written
    return fs->block_size;
}

// Close a file
int close_file(struct file_system *fs, int file_num) {
    // Find the file block
    int block_num = file_num;

    // Clear the file block
    memset(fs->data + block_num * fs->block_size, 0, fs->block_size);

    return 0;
}

// Delete a file
int delete_file(struct file_system *fs, char *name) {
    // Find the file block
    int block_num = -1;
    for (int i = 0; i < fs->num_blocks; i++) {
        if (strcmp(fs->data + i * fs->block_size, name) == 0) {
            block_num = i;
            break;
        }
    }

    if (block_num == -1) {
        return -1;
    }

    // Clear the file block
    memset(fs->data + block_num * fs->block_size, 0, fs->block_size);

    return 0;
}

// Print the file system
void print_file_system(struct file_system *fs) {
    for (int i = 0; i < fs->num_blocks; i++) {
        printf("Block %d: %s\n", i, fs->data + i * fs->block_size);
    }
}

int main() {
    // Create a new file system
    struct file_system *fs = create_file_system(10, 1024);

    // Create a new file
    int file_num = create_file(fs, "test.txt");

    // Open the file
    file_num = open_file(fs, "test.txt");

    // Write to the file
    char buf[1024] = "Hello, world!";
    write_file(fs, file_num, buf);

    // Read from the file
    read_file(fs, file_num, buf);

    // Print the file
    printf("%s\n", buf);

    // Close the file
    close_file(fs, file_num);

    // Delete the file
    delete_file(fs, "test.txt");

    // Print the file system
    print_file_system(fs);

    // Destroy the file system
    destroy_file_system(fs);

    return 0;
}