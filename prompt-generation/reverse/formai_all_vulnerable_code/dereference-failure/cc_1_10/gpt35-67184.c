//FormAI DATASET v1.0 Category: File system simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_FILE_SIZE 1024
#define MAX_FILES 100

/* Metadata definition for file system */
struct metadata {
    int num_blocks;
    int block_size;
    int num_files;
};

/* Block definition for file system */
struct block {
    int id;
    char data[BLOCK_SIZE];
};

/* File definition for file system */
struct file {
    char name[100];
    int start_block;
    int num_blocks;
};

/* File system definition */
struct file_system {
    struct metadata metadata;
    struct block *blocks;
    struct file files[MAX_FILES];
};

/* Function to initialize file system */
void init_file_system(struct file_system *fs, int num_blocks, int block_size) {
    fs->metadata.num_blocks = num_blocks;
    fs->metadata.block_size = block_size;
    fs->metadata.num_files = 0;

    /* Allocate memory for blocks */
    fs->blocks = (struct block *)malloc(sizeof(struct block) * num_blocks);

    /* Initialize block IDs and data to empty */
    for(int i=0; i<num_blocks; i++) {
        fs->blocks[i].id = i;
        memset(fs->blocks[i].data, 0, BLOCK_SIZE);
    }
}

/* Function to create new file in file system */
void create_file(struct file_system *fs, char *name, char *content) {
    int start = 0, num_blocks;
    int length = strlen(content);

    /* Calculate number of blocks required */
    if(length % BLOCK_SIZE == 0)
        num_blocks = length / BLOCK_SIZE;
    else
        num_blocks = length / BLOCK_SIZE + 1;

    /* Check if enough blocks available */
    if(fs->metadata.num_blocks - num_blocks < 0) {
        printf("Error: Not enough free blocks available in file system.\n");
        return;
    }

    /* Find free blocks to allocate */
    for(int i=0; i<fs->metadata.num_blocks; i++) {
        if(fs->blocks[i].id == -1) {
            if(start == 0)
                start = i;
            if(num_blocks == 1) 
                break;
            num_blocks--;
        }
    }

    /* Write file data to allocated blocks */
    int content_index = 0;
    for(int i=start; i<start+num_blocks; i++) {
        memcpy(fs->blocks[i].data, &content[content_index], BLOCK_SIZE);
        content_index += BLOCK_SIZE;
        fs->blocks[i].id = i;
    }

    /* Add file metadata */
    struct file new_file;
    strcpy(new_file.name, name);
    new_file.start_block = start;
    new_file.num_blocks = num_blocks;

    fs->files[fs->metadata.num_files] = new_file;
    fs->metadata.num_files++;
    fs->metadata.num_blocks -= num_blocks;

    printf("File '%s' created successfully.\n", name);
}

/* Function to read file from file system */
void read_file(struct file_system *fs, char *name) {
    int index = -1;

    /* Find file metadata */
    for(int i=0; i<fs->metadata.num_files; i++) {
        if(strcmp(name, fs->files[i].name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Error: File '%s' not found in file system.\n", name);
        return;
    }

    /* Read file data from blocks */
    printf("\n%s:\n", name);
    for(int i=fs->files[index].start_block; i<fs->files[index].start_block+fs->files[index].num_blocks; i++) {
        printf("%s", fs->blocks[i].data);
    }
    printf("\n");
}

/* Function to delete file from file system */
void delete_file(struct file_system *fs, char *name) {
    int index = -1;

    /* Find file metadata */
    for(int i=0; i<fs->metadata.num_files; i++) {
        if(strcmp(name, fs->files[i].name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Error: File '%s' not found in file system.\n", name);
        return;
    }

    /* Free blocks allocated to file */
    for(int i=fs->files[index].start_block; i<fs->files[index].start_block+fs->files[index].num_blocks; i++) {
        fs->blocks[i].id = -1;
        memset(fs->blocks[i].data, 0, BLOCK_SIZE);
    }

    /* Remove file metadata */
    for(int i=index+1; i<fs->metadata.num_files; i++) {
        fs->files[i-1] = fs->files[i];
    }

    fs->metadata.num_files--;
    fs->metadata.num_blocks += fs->files[index].num_blocks;

    printf("File '%s' deleted successfully.\n", name);
}

/* Function to display file system metadata */
void display_metadata(struct file_system *fs) {
    printf("\nFile system metadata:\n");
    printf("Number of blocks: %d\n", fs->metadata.num_blocks);
    printf("Block size: %d\n", fs->metadata.block_size);
    printf("Total size: %d bytes\n", fs->metadata.num_blocks * fs->metadata.block_size);
    printf("Number of files: %d\n", fs->metadata.num_files);
}

int main() {
    struct file_system fs;
    int num_blocks, block_size;
    char name[100], content[MAX_FILE_SIZE];

    printf("Enter number of blocks in file system: ");
    scanf("%d", &num_blocks);
    printf("Enter block size: ");
    scanf("%d", &block_size);

    init_file_system(&fs, num_blocks, block_size);

    while(1) {
        int choice;

        printf("\n1. Create file\n2. Read file\n3. Delete file\n4. Display metadata\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter file name: ");
                scanf("%s", name);
                printf("Enter file content (max length %d):\n", MAX_FILE_SIZE);
                getchar();  // consume newline character
                fgets(content, MAX_FILE_SIZE, stdin);
                create_file(&fs, name, content);
                break;
            case 2:
                printf("\nEnter file name: ");
                scanf("%s", name);
                read_file(&fs, name);
                break;
            case 3:
                printf("\nEnter file name: ");
                scanf("%s", name);
                delete_file(&fs, name);
                break;
            case 4:
                display_metadata(&fs);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    free(fs.blocks);
    return 0;
}