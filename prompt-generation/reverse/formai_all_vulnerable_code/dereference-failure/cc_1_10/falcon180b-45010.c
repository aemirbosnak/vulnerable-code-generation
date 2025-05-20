//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_SIZE 64

typedef struct {
    char hash[HASH_SIZE];
    int length;
} Hash;

void hash(const char* message, Hash* hash) {
    hash->length = strlen(message);
    for (int i = 0; i < hash->length; i++) {
        hash->hash[i] = message[i];
    }
}

int compare(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int main() {
    srand(time(NULL));
    int num_hashes = 10;
    Hash* hashes = malloc(num_hashes * sizeof(Hash));
    char* messages[] = {
        "Hello, world!",
        "This is a test.",
        "The quick brown fox jumps over the lazy dog.",
        "Mary had a little lamb, its fleece was white as snow.",
        "All work and no play makes Jack a dull boy.",
        "Four score and seven years ago our fathers brought forth on this continent a new nation, conceived in liberty, and dedicated to the proposition that all men are created equal.",
        "In the beginning God created the heaven and the earth.",
        "To be, or not to be: that is the question.",
        "It was the best of times, it was the worst of times, it was the age of wisdom, it was the age of foolishness, it was the epoch of belief, it was the epoch of incredulity,",
        "I am the master of my fate, I am the captain of my soul."
    };
    
    for (int i = 0; i < num_hashes; i++) {
        hash(messages[i], &hashes[i]);
    }
    
    qsort(hashes, num_hashes, sizeof(Hash), compare);
    
    for (int i = 0; i < num_hashes; i++) {
        printf("%s\n", hashes[i].hash);
    }
    
    free(hashes);
    return 0;
}