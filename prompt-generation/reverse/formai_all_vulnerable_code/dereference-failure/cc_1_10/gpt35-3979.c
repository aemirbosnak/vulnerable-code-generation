//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

unsigned char watermark[] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF};
int watermark_size = sizeof(watermark);

void embed_watermark(FILE* input_file, FILE* output_file) {
    unsigned char* buffer = malloc(watermark_size);
    int read_count;
    int i = 0;
    srand(time(NULL));

    while((read_count = fread(buffer, 1, watermark_size, input_file)) > 0) {
        if(i < 10) { // Only embed watermark in first 10 blocks
            int random_index = rand() % read_count;
            memcpy(&buffer[random_index], &watermark[random_index], 1);
        }
        fwrite(buffer, 1, read_count, output_file);
        i++;
    }

    free(buffer);
}

void extract_watermark(FILE* input_file) {
    unsigned char* buffer = malloc(watermark_size);
    int read_count;
    int i = 0;

    while((read_count = fread(buffer, 1, watermark_size, input_file)) > 0) {
        if(i < 10) { // Only look for watermark in first 10 blocks
            int j;
            for(j = 0; j < read_count; j++) {
                if(buffer[j] == watermark[j]) {
                    printf("Watermark found at block %d, byte %d\n", i, j);
                }
            }
        }
        i++;
    }

    free(buffer);
}

int main(int argc, char** argv) {
    if(argc < 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "rb");
    if(input_file == NULL) {
        printf("Unable to open input file!\n");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "wb");
    if(output_file == NULL) {
        printf("Unable to open output file!\n");
        fclose(input_file);
        return 1;
    }

    embed_watermark(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    FILE* input_file2 = fopen(argv[2], "rb");
    if(input_file2 == NULL) {
        printf("Unable to open output file!\n");
        return 1;
    }

    extract_watermark(input_file2);

    fclose(input_file2);

    return 0;
}