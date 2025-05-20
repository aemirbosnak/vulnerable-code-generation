//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <time.h>

#define OBELISK_HEIGHT 33
#define OBELISK_BASE 17
#define ALPHABET_SIZE 26
#define SEED 1337
#define MASK 0xFFFFFFFF00000000

typedef struct Obelisk {
    unsigned long long base;
    unsigned char height[OBELISK_HEIGHT][OBELISK_BASE];
} Obelisk;

Obelisk *createObelisk();
void initObelisk(Obelisk *obelisk);
unsigned long long calculateChecksum(Obelisk *obelisk, const char *input, size_t length);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    Obelisk *obelisk = createObelisk();
    initObelisk(obelisk);

    const char *input = argv[1];
    size_t length = strlen(input);

    unsigned long long checksum = calculateChecksum(obelisk, input, length);
    printf("Input: %s\nLength: %zu\nChecksum: %llx\n", input, length, checksum);

    free(obelisk);
    return 0;
}

Obelisk *createObelisk() {
    Obelisk *obelisk = mmap(NULL, sizeof(Obelisk), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (obelisk == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    memset(obelisk->height, 0, sizeof(obelisk->height));
    return obelisk;
}

void initObelisk(Obelisk *obelisk) {
    srand(SEED);

    for (unsigned int i = 0; i < OBELISK_HEIGHT; ++i) {
        for (unsigned int j = 0; j < OBELISK_BASE; ++j) {
            obelisk->height[i][j] = (unsigned char)rand() % ALPHABET_SIZE + 'A';
        }
    }

    obelisk->base = 0;
}

unsigned long long calculateChecksum(Obelisk *obelisk, const char *input, size_t length) {
    unsigned long long checksum = 0;

    for (size_t i = 0; i < length; ++i) {
        const char c = input[i];
        unsigned int index = (unsigned int)(c - 'A') % OBELISK_BASE;
        unsigned int offset = (unsigned int)(obelisk->height[i % OBELISK_HEIGHT][index]);

        checksum ^= ((obelisk->base >> offset) & MASK);
        obelisk->base = (obelisk->base << 1) | (checksum & 0xFFFFFFFF);
    }

    return checksum;
}