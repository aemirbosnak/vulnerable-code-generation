//FormAI DATASET v1.0 Category: Data recovery tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef struct _file_block_ {
    char data[BLOCK_SIZE];
} Block;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: data-recovery <file-to-recover>\n");
        return 1;
    }
    
    FILE* file_to_recover = fopen(argv[1], "rb");
    
    if (!file_to_recover) {
        printf("Error: Unable to open file %s\n", argv[1]);
        return 1;
    }
    
    int block_count = 0;
    fseek(file_to_recover, 0L, SEEK_END);
    long file_size = ftell(file_to_recover);
    fseek(file_to_recover, 0L, SEEK_SET);
    
    if (file_size % BLOCK_SIZE) {
        block_count = (file_size / BLOCK_SIZE) + 1;
    } else {
        block_count = file_size / BLOCK_SIZE;
    }
    
    Block* blocks = (Block*)malloc(sizeof(Block) * block_count);
    memset(blocks, 0, sizeof(Block) * block_count);
    
    long blocks_read = fread(blocks, sizeof(Block), block_count, file_to_recover);
    
    if (blocks_read != block_count) {
        printf("Error: Unable to read blocks from file %s\n", argv[1]);
        return 1;
    }
    
    printf("File size : %ld\n", file_size);
    printf("Block count : %d\n", block_count);
    printf("Blocks read : %ld\n", blocks_read);
    
    fclose(file_to_recover);
    
    printf("Data recovered successfully:\n");
    
    for (int i = 0; i < block_count; i++) {
        printf("%s", blocks[i].data);
    }
    
    free(blocks);
    
    return 0;
}