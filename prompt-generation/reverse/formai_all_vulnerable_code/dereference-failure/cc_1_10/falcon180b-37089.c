//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096

struct block {
    int index;
    char data[BLOCK_SIZE];
};

int main() {
    FILE *file;
    struct block *blocks = NULL;
    int num_blocks = 0;
    int i, j;

    // Open the file for reading
    file = fopen("example.txt", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the file into memory
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *file_data = malloc(file_size);
    if (file_data == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }
    fread(file_data, file_size, 1, file);
    fclose(file);

    // Parse the file data into blocks
    for (i = 0; i < file_size; i += BLOCK_SIZE) {
        blocks = realloc(blocks, sizeof(struct block) * ++num_blocks);
        blocks[num_blocks - 1].index = i / BLOCK_SIZE;
        memcpy(blocks[num_blocks - 1].data, file_data + i, BLOCK_SIZE - (i % BLOCK_SIZE));
    }

    // Print the block index table
    for (i = 0; i < num_blocks; i++) {
        printf("%d: ", blocks[i].index);
        for (j = 0; j < BLOCK_SIZE; j++) {
            if (j % 16 == 0) {
                printf("\n%04x ", i * BLOCK_SIZE + j);
            }
            printf("%02x ", blocks[i].data[j]);
        }
        printf("\n");
    }

    // Free memory and exit
    free(file_data);
    free(blocks);
    return 0;
}