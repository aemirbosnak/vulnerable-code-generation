//FormAI DATASET v1.0 Category: File system simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 20
#define MAX_NAME_LENGTH 20
#define BLOCK_SIZE 512
#define NUM_BLOCKS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int size;
    int blocks[10];
} File;

File files[MAX_FILES];

char* disk[NUM_BLOCKS];

void initialize_disk() {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        disk[i] = (char*) malloc(BLOCK_SIZE);
        memset(disk[i], 0, BLOCK_SIZE);
    }
}

int allocate_block() {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (strlen(disk[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void create_file() {
    if (strlen(files[MAX_FILES - 1].name) > 0) {
        printf("Maximum number of files reached\n");
        return;
    }

    File new_file;
    printf("Enter the name of the file: ");
    scanf("%s", new_file.name);
    printf("Enter the size of the file (in bytes): ");
    scanf("%d", &new_file.size);

    int num_blocks_required = (new_file.size + BLOCK_SIZE - 1) / BLOCK_SIZE;

    int blocks_allocated = 0;
    for (int i = 0; i < NUM_BLOCKS && blocks_allocated < num_blocks_required; i++) {
        if (strlen(disk[i]) == 0) {
            new_file.blocks[blocks_allocated] = i;
            blocks_allocated++;
        }
    }

    if (blocks_allocated < num_blocks_required) {
        printf("Not enough space on disk\n");
        return;
    }

    files[MAX_FILES - 1] = new_file;
}

void delete_file() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the file to delete: ");
    scanf("%s", name);

    int file_index = -1;
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index < 0) {
        printf("File not found\n");
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (files[file_index].blocks[i] >= 0) {
            memset(disk[files[file_index].blocks[i]], 0, BLOCK_SIZE);
        }
    }

    memset(&files[file_index], 0, sizeof(File));
}

void list_files() {
    printf("%-20s %-20s %-20s\n", "Name", "Size (bytes)", "Blocks");
    for (int i = 0; i < MAX_FILES; i++) {
        if (strlen(files[i].name) > 0) {
            printf("%-20s %-20d ", files[i].name, files[i].size);
            for (int j = 0; j < 10; j++) {
                if (files[i].blocks[j] >= 0) {
                    printf("%d ", files[i].blocks[j]);
                }
            }
            printf("\n");
        }
    }
}

int main() {
    initialize_disk();

    for (int i = 0; i < MAX_FILES; i++) {
        memset(&files[i], 0, sizeof(File));
    }

    int choice = 0;
    do {
        printf("\n1. Create new file\n");
        printf("2. Delete file\n");
        printf("3. List files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_file();
                break;
            case 2:
                delete_file();
                break;
            case 3:
                list_files();
                break;
        }
    } while (choice != 4);

    return 0;
}