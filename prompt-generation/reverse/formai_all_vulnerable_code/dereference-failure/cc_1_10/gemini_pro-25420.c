//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint64_t hash;
    size_t pos;
} index_entry;

typedef struct {
    size_t count;
    index_entry *entries;
} index;

static index *create_index(void) {
    index *idx = calloc(1, sizeof(*idx));
    return idx;
}

static void destroy_index(index *idx) {
    free(idx->entries);
    free(idx);
}

static int insert_index(index *idx, uint64_t hash, size_t pos) {
    idx->entries = realloc(idx->entries, (idx->count + 1) * sizeof(*idx->entries));
    if (!idx->entries) return -1;
    idx->entries[idx->count].hash = hash;
    idx->entries[idx->count].pos = pos;
    idx->count++;
    return 0;
}

static size_t search_index(index *idx, uint64_t hash) {
    size_t low = 0;
    size_t high = idx->count - 1;
    while (low <= high) {
        size_t mid = (low + high) / 2;
        if (idx->entries[mid].hash == hash) {
            return idx->entries[mid].pos;
        } else if (idx->entries[mid].hash < hash) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    index *idx = create_index();
    insert_index(idx, 0x123456789abcdef0, 0);
    insert_index(idx, 0x23456789abcdef01, 1);
    insert_index(idx, 0x3456789abcdef012, 2);
    size_t pos = search_index(idx, 0x23456789abcdef01);
    printf("Found at position %zu\n", pos);
    destroy_index(idx);
    return 0;
}