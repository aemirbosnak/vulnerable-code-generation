//FormAI DATASET v1.0 Category: File system simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILES 100
#define BLOCK_SIZE 512

typedef struct file {
    char *name;
    int size;
    int num_blocks;
    int *blocks;
} file;

file files[MAX_FILES];
int num_files = 0;
int num_blocks = 0;
int disk_usage = 0;

char *read_input() {
    char *input = malloc(sizeof(char) * 100);
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;
    return input;
}

void create_file() {
    printf("Enter file name: ");
    char *name = read_input();
    printf("Enter file size: ");
    int size = atoi(read_input());

    if (num_files == MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }

    if (disk_usage + size > num_blocks * BLOCK_SIZE) {
        printf("Error: Not enough disk space available.\n");
        return;
    }

    file new_file;
    new_file.name = malloc(sizeof(char) * strlen(name));
    strcpy(new_file.name, name);
    new_file.size = size;
    new_file.num_blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    new_file.blocks = malloc(sizeof(int) * new_file.num_blocks);

    int i, j;
    for (i = 0; i < new_file.num_blocks; i++) {
        for (j = 0; j < num_blocks; j++) {
            if (files[j].size == 0) {
                new_file.blocks[i] = j;
                files[j] = new_file;
                disk_usage += BLOCK_SIZE;
                break;
            }
        }
    }

    num_files++;
    printf("File %s created successfully.\n", name);
}

void delete_file() {
    printf("Enter file name: ");
    char *name = read_input();

    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            int j;
            for (j = 0; j < files[i].num_blocks; j++) {
                files[files[i].blocks[j]].size = 0;
                disk_usage -= BLOCK_SIZE;
            }
            free(files[i].blocks);
            free(files[i].name);
            files[i].size = 0;

            num_files--;
            printf("File %s deleted successfully.\n", name);
            return;
        }
    }

    printf("Error: File %s not found.\n", name);
}

void list_files() {
    printf("List of files:\n");
    int i, j;
    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes, blocks:", files[i].name, files[i].size);
        for (j = 0; j < files[i].num_blocks; j++) {
            printf(" %d", files[i].blocks[j]);
        }
        printf(")\n");
    }
}

void print_disk_usage() {
    printf("Disk usage: %d bytes\n", disk_usage);
    printf("Free space: %d bytes\n", num_blocks * BLOCK_SIZE - disk_usage);
}

int main(int argc, char *argv[]) {
    printf("Welcome to the C File System Simulation!\n");
    printf("Enter number of blocks for disk: ");
    num_blocks = atoi(read_input());

    printf("Initializing disk with %d blocks...\n", num_blocks);
    int i;
    for (i = 0; i < num_blocks; i++) {
        file empty_file;
        empty_file.name = "";
        empty_file.size = 0;
        empty_file.num_blocks = 0;
        empty_file.blocks = NULL;
        files[i] = empty_file;
    }

    while (1) {
        printf("Enter command: ");
        char *command = read_input();

        if (strcmp(command, "create") == 0) {
            create_file();
        } else if (strcmp(command, "delete") == 0) {
            delete_file();
        } else if (strcmp(command, "list") == 0) {
            list_files();
        } else if (strcmp(command, "usage") == 0) {
            print_disk_usage();
        } else if (strcmp(command, "exit") == 0) {
            return 0;
        } else {
            printf("Error: Invalid command.\n");
        }

        free(command);
    }

    return 0;
}