//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t size;
} DataBlock;

typedef struct {
    DataBlock *blocks;
    size_t num_blocks;
} DataStore;

DataStore *create_data_store() {
    DataStore *store = malloc(sizeof(DataStore));
    store->blocks = NULL;
    store->num_blocks = 0;
    return store;
}

void destroy_data_store(DataStore *store) {
    for (size_t i = 0; i < store->num_blocks; i++) {
        free(store->blocks[i].data);
    }
    free(store->blocks);
    free(store);
}

DataBlock *add_data_block(DataStore *store, char *data, size_t size) {
    store->blocks = realloc(store->blocks, sizeof(DataBlock) * (store->num_blocks + 1));
    DataBlock *block = &store->blocks[store->num_blocks++];
    block->data = malloc(size);
    memcpy(block->data, data, size);
    block->size = size;
    return block;
}

char *recover_data(DataStore *store, size_t offset, size_t size) {
    for (size_t i = 0; i < store->num_blocks; i++) {
        DataBlock *block = &store->blocks[i];
        if (offset < block->size && offset + size <= block->size) {
            return block->data + offset;
        }
    }
    return NULL;
}

int main() {
    DataStore *store = create_data_store();

    char *data1 = "Hello, world!";
    DataBlock *block1 = add_data_block(store, data1, strlen(data1));

    char *data2 = "This is a test.";
    DataBlock *block2 = add_data_block(store, data2, strlen(data2));

    char *recovered_data = recover_data(store, 7, 5);
    if (recovered_data != NULL) {
        printf("Recovered data: %s\n", recovered_data);
    } else {
        printf("Data not found.\n");
    }

    destroy_data_store(store);
    return 0;
}