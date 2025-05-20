//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: genius
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BITS_PER_BYTE 8
#define BITS_PER_WORD 32

struct bit_vector {
    uint8_t *data;
    size_t size;
};

static inline void init_bit_vector(struct bit_vector *v, size_t size) {
    v->data = malloc(size);
    v->size = size;
    memset(v->data, 0, size);
}

static inline void free_bit_vector(struct bit_vector *v) {
    free(v->data);
}

static inline void set_bit(struct bit_vector *v, size_t index) {
    v->data[index/BITS_PER_BYTE] |= (1 << (index%BITS_PER_BYTE));
}

static inline int get_bit(struct bit_vector *v, size_t index) {
    return (v->data[index/BITS_PER_BYTE] & (1 << (index%BITS_PER_BYTE))) != 0;
}

static inline void clear_bits(struct bit_vector *v, size_t start, size_t end) {
    for (size_t i = start; i < end; i++) {
        v->data[i/BITS_PER_BYTE] &= ~(1 << (i%BITS_PER_BYTE));
    }
}

static inline size_t find_first_set(struct bit_vector *v) {
    size_t i = 0;
    while (i < v->size) {
        if (v->data[i/BITS_PER_BYTE] & (1 << (i%BITS_PER_BYTE))) break;
        i++;
    }
    return i;
}

static inline size_t find_next_set(struct bit_vector *v, size_t i) {
    size_t j = i + 1;
    while (j < v->size) {
        if (v->data[j/BITS_PER_BYTE] & (1 << (j%BITS_PER_BYTE))) break;
        j++;
    }
    return j;
}

static inline size_t find_prev_set(struct bit_vector *v, size_t i) {
    size_t j = i - 1;
    while (j >= 0) {
        if (v->data[j/BITS_PER_BYTE] & (1 << (j%BITS_PER_BYTE))) break;
        j--;
    }
    return j;
}

static inline size_t find_longest_run(struct bit_vector *v) {
    size_t max_run = 0;
    size_t i = 0;
    while (i < v->size) {
        size_t j = find_next_set(v, i);
        if (j - i > max_run) {
            max_run = j - i;
        }
        i = j;
    }
    return max_run;
}

int main() {
    struct bit_vector v;
    init_bit_vector(&v, 100);

    // Compress the bit vector
    size_t max_run = find_longest_run(&v);
    size_t compressed_size = 0;
    for (size_t i = 0; i < v.size;) {
        size_t j = find_next_set(&v, i);
        if (j - i > max_run) {
            // Compress the run
            size_t k = j - i;
            v.data[i/BITS_PER_BYTE] |= (1 << (i%BITS_PER_BYTE));
            i += k;
            compressed_size++;
        } else {
            i = j;
        }
    }

    // Decompress the bit vector
    size_t decompressed_size = 0;
    for (size_t i = 0; i < v.size;) {
        if (get_bit(&v, i)) {
            size_t j = find_next_set(&v, i);
            decompressed_size++;
            i = j;
        } else {
            i++;
        }
    }

    printf("Compressed size: %zu\n", compressed_size);
    printf("Decompressed size: %zu\n", decompressed_size);

    return 0;
}