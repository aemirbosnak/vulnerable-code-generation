//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants
#define BLOCK_SIZE 8
#define WATERMARK_STR "Hello World"
#define WATERMARK_SIZE 11
#define EMBEDDING_FACTOR 1

// Functions
void embed_watermark(unsigned char* image_data, int image_size, unsigned char* watermark, int watermark_size)
{
    int num_blocks = image_size / BLOCK_SIZE;
    int watermark_index = 0;

    for (int i = 0; i < num_blocks; i++) {
        int block_sum = 0;

        for (int j = 0; j < BLOCK_SIZE; j++) {
            block_sum += *(image_data + (i * BLOCK_SIZE) + j);
        }

        int avg_intensity = block_sum / BLOCK_SIZE;

        if (watermark_index < watermark_size) {
            int bit = *(watermark + watermark_index) & 1;
            *(image_data + (i * BLOCK_SIZE) + BLOCK_SIZE - 1) += (EMBEDDING_FACTOR * pow(-1, avg_intensity) * bit);
            watermark_index++;
        }
    }
}

int extract_watermark(unsigned char* image_data, int image_size, unsigned char* watermark, int watermark_size)
{
    int num_blocks = image_size / BLOCK_SIZE;

    int watermark_index = 0;
    int watermark_found = 1;

    for (int i = 0; i < num_blocks; i++) {
        int block_sum = 0;

        for (int j = 0; j < BLOCK_SIZE; j++) {
            block_sum += *(image_data + (i * BLOCK_SIZE) + j);
        }

        int avg_intensity = block_sum / BLOCK_SIZE;
        int bit = (int)(*(image_data + (i * BLOCK_SIZE) + BLOCK_SIZE - 1) - (EMBEDDING_FACTOR * pow(-1, avg_intensity) / 2.0) + 0.5) & 1;

        if (watermark_index < watermark_size) {
            *(watermark + watermark_index) = bit + '0';
            watermark_index++;
        }
        else {
            if (bit != '0') {
                watermark_found = 0;
                break;
            }
        }
    }

    if (watermark_found) {
        return 1;
    }
    return 0;
}

void print_binary(unsigned char* data, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d", (*(data + i) & 1));
    }
    printf("\n");
}

int main()
{
    unsigned char* image_data = (unsigned char*)malloc(64 * sizeof(unsigned char));
    for (int i = 0; i < 64; i++) {
        *(image_data + i) = i % 256;
    }

    printf("Image data:\n");
    print_binary(image_data, BLOCK_SIZE * 8);

    unsigned char* watermark = (unsigned char*)malloc((WATERMARK_SIZE + 1) * sizeof(unsigned char));
    strncpy(watermark, WATERMARK_STR, WATERMARK_SIZE);
    *(watermark + WATERMARK_SIZE) = '\0';

    printf("Watermark data: %s\n", watermark);

    embed_watermark(image_data, BLOCK_SIZE * 8, watermark, WATERMARK_SIZE);

    printf("Watermarked image data:\n");
    print_binary(image_data, BLOCK_SIZE * 8);

    unsigned char* extracted_watermark = (unsigned char*)malloc((WATERMARK_SIZE + 1) * sizeof(unsigned char));
    int watermark_found = extract_watermark(image_data, BLOCK_SIZE * 8, extracted_watermark, WATERMARK_SIZE);

    if (watermark_found) {
        printf("Extracted watermark: %s\n", extracted_watermark);
    }
    else {
        printf("Watermark not found in image.\n");
    }

    free(image_data);
    free(watermark);
    free(extracted_watermark);

    return 0;
}