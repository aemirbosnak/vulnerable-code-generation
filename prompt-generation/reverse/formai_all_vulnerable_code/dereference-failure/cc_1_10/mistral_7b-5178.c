//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>

#define WORD_SIZE (sizeof(unsigned int))
#define BLOCK_SIZE (1024 * 1024)

typedef struct {
    unsigned int data[WORD_SIZE];
} Bitmap;

void bitmap_init(Bitmap *bitmap) {
    memset(bitmap, 0, sizeof(Bitmap));
}

void bitmap_set_pixel(Bitmap *bitmap, int x, int y) {
    int word_index = x / WORD_SIZE;
    int bit_index = x % WORD_SIZE;

    unsigned int word = bitmap->data[word_index];
    unsigned int mask = 1 << bit_index;

    bitmap->data[word_index] = word | mask;
}

void bitmap_print(const Bitmap *bitmap) {
    for (int y = 0; y < BLOCK_SIZE / WORD_SIZE; y++) {
        for (int x = 0; x < WORD_SIZE * 8; x++) {
            int bit_index = x / 8;
            int pixel_index = y * WORD_SIZE + bit_index / 8;
            int bit_position = bit_index % 8;

            unsigned int word = bitmap->data[pixel_index];
            unsigned int mask = 1 << bit_position;

            if ((word & mask) != 0) {
                putchar('X');
            } else {
                putchar('.');
            }
        }
        putchar('\n');
    }
}

int main() {
    srand(time(NULL));

    Bitmap bitmap;
    bitmap_init(&bitmap);

    for (int i = 0; i < 1000; i++) {
        int x = rand() % (BLOCK_SIZE / WORD_SIZE);
        int y = rand() % (WORD_SIZE * 8);
        bitmap_set_pixel(&bitmap, x, y);
    }

    bitmap_print(&bitmap);

    return 0;
}