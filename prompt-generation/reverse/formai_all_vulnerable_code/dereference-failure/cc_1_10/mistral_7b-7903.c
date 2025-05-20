//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdint.h>

#define WIDTH 41
#define HEIGHT 12
#define SHIELD_CHAR '>'
#define BORDER_CHAR '*'
#define FILLED_CHAR '.'
#define EMPTY_CHAR ' '

typedef struct Shield {
    uint8_t data[WIDTH * HEIGHT];
} Shield;

Shield* create_shield() {
    Shield* shield = mmap(NULL, WIDTH * HEIGHT, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    memset(shield->data, EMPTY_CHAR, WIDTH * HEIGHT);

    int x = WIDTH / 2;
    int y = 1;
    int size = 3;

    for (int i = 0; i < size; i++) {
        for (int j = x - size + i; j <= x + size - i; j++) {
            shield->data[y * WIDTH + j] = SHIELD_CHAR;
        }
    }

    return shield;
}

void print_shield(Shield* shield) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(shield->data[y * WIDTH + x]);
        }
        putchar('\n');
    }
}

int main() {
    Shield* shield = create_shield();

    int border_size = 2;
    for (int y = 0; y < HEIGHT + 2 * border_size; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y < border_size || y >= HEIGHT + border_size) {
                shield->data[y * WIDTH + x] = BORDER_CHAR;
            } else {
                shield->data[y * WIDTH + x] = EMPTY_CHAR;
            }
        }
    }

    print_shield(shield);

    munmap(shield, WIDTH * HEIGHT);

    return 0;
}