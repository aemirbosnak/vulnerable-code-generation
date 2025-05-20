//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 512
#define HEIGHT 512
#define BLOCK_SIZE 8
#define NUM_BLOCKS (WIDTH/BLOCK_SIZE) * (HEIGHT/BLOCK_SIZE)
#define MAX_WATERMARK_SIZE 100
#define MAX_WATERMARK_DATA (MAX_WATERMARK_SIZE/2)

typedef struct {
    int x;
    int y;
    int value;
} Block;

typedef struct {
    int watermark_size;
    int watermark_data[MAX_WATERMARK_DATA];
} Watermark;

void generate_watermark(Watermark *watermark, int watermark_size) {
    srand(time(NULL));
    for (int i = 0; i < watermark_size; i++) {
        watermark->watermark_data[i] = rand() % 256;
    }
}

void add_watermark(Block *block, Watermark *watermark) {
    int x = block->x * BLOCK_SIZE;
    int y = block->y * BLOCK_SIZE;
    for (int i = 0; i < watermark->watermark_size; i++) {
        int value = (int) (block->value + watermark->watermark_data[i]);
        if (value < 0) {
            value = 0;
        } else if (value > 255) {
            value = 255;
        }
        int pixel = x + i % BLOCK_SIZE;
        int row = y + i / BLOCK_SIZE;
        int offset = row * WIDTH + pixel;
        block->value = value;
        block->x = pixel;
        block->y = row;
        printf("Watermark pixel: (%d, %d) Value: %d\n", pixel, row, value);
    }
}

void read_image(char *filename, Block *blocks) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening image file\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    blocks->value = malloc(filesize);
    fread(blocks->value, 1, filesize, fp);
    fclose(fp);
}

void write_image(char *filename, Block *blocks) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error creating image file\n");
        exit(1);
    }
    fwrite(blocks->value, 1, WIDTH*HEIGHT, fp);
    fclose(fp);
}

int main() {
    Watermark watermark;
    watermark.watermark_size = MAX_WATERMARK_SIZE;
    generate_watermark(&watermark, MAX_WATERMARK_SIZE);

    Block blocks[NUM_BLOCKS];
    for (int i = 0; i < NUM_BLOCKS; i++) {
        blocks[i].x = i % NUM_BLOCKS;
        blocks[i].y = i / NUM_BLOCKS;
        read_image("image.bmp", &blocks[i]);
    }

    for (int i = 0; i < NUM_BLOCKS; i++) {
        add_watermark(&blocks[i], &watermark);
    }

    for (int i = 0; i < NUM_BLOCKS; i++) {
        write_image("watermarked_image.bmp", &blocks[i]);
    }

    return 0;
}