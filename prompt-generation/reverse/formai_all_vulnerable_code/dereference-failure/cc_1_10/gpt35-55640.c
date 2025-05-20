//FormAI DATASET v1.0 Category: File system simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define NUM_BLOCKS 4096
#define MAX_FILENAME_LENGTH 64

typedef struct {
    int id;
    char filename[MAX_FILENAME_LENGTH];
    int size;
} File;

File* files[NUM_BLOCKS];
char blocks[NUM_BLOCKS][BLOCK_SIZE];
int used_blocks = 0;

void create_file(char* filename, int size) {
    if (size > NUM_BLOCKS - used_blocks) {
        printf("Error: no space left on device\n");
        return;
    }

    int id = used_blocks;
    File* file = (File*)malloc(sizeof(File));
    file->id = id;
    strcpy(file->filename, filename);
    file->size = size;
    files[id] = file;

    int remaining_blocks = size;
    int block_idx = id + 1;  // start at next free block
    while (remaining_blocks > 0) {
        int block_size = BLOCK_SIZE;
        if (remaining_blocks < block_size) {
            block_size = remaining_blocks;
        }
        memcpy(blocks[block_idx], " ", block_size);
        remaining_blocks -= block_size;
        block_idx++;
    }

    used_blocks += size;
    printf("Created file %s of size %d\n", filename, size);
}

void delete_file(char* filename) {
    int id = -1;
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (files[i] != NULL && strcmp(files[i]->filename, filename) == 0) {
            id = i;
            free(files[i]);
            files[i] = NULL;
            break;
        }
    }

    if (id == -1) {
        printf("Error: file %s not found\n", filename);
        return;
    }

    int remaining_blocks = files[id]->size;
    int block_idx = id + 1;
    while (remaining_blocks > 0) {
        memset(blocks[block_idx], 0, BLOCK_SIZE);
        remaining_blocks -= BLOCK_SIZE;
        block_idx++;
    }

    used_blocks -= files[id]->size;
    printf("Deleted file %s\n", filename);
}

void list_files() {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (files[i] != NULL) {
            printf("%s (%d bytes)\n", files[i]->filename, files[i]->size);
        }
    }
}

int main() {
    char input[256];
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // remove trailing newline
        int len = strlen(input);
        if (input[len-1] == '\n') {
            input[len-1] = '\0';
        }

        char* command = strtok(input, " ");
        if (strcmp(command, "create") == 0) {
            char* filename = strtok(NULL, " ");
            char* size_str = strtok(NULL, " ");
            int size = atoi(size_str);
            create_file(filename, size);
        } else if (strcmp(command, "delete") == 0) {
            char* filename = strtok(NULL, " ");
            delete_file(filename);
        } else if (strcmp(command, "list") == 0) {
            list_files();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Error: invalid command\n");
        }
    }

    return 0;
}