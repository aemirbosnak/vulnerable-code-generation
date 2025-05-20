//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 8
#define WATERMARK_SIZE 32

void generate_watermark(char* watermark) {
    int i;
    for (i = 0; i < WATERMARK_SIZE; i++) {
        watermark[i] = rand() % 26 + 'a';
    }
    watermark[WATERMARK_SIZE - 1] = '\0';
}

void embed_watermark(char* host, char* watermark) {
    int i, j;
    for (i = 0; i < strlen(host); i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE && i + j < strlen(host); j++) {
            host[i + j] = host[i + j] ^ watermark[j % WATERMARK_SIZE];
        }
    }
}

void extract_watermark(char* host, char* watermark) {
    int i, j;
    for (i = 0; i < strlen(host); i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE && i + j < strlen(host); j++) {
            watermark[j % WATERMARK_SIZE] = watermark[j % WATERMARK_SIZE] ^ host[i + j];
        }
    }
    watermark[WATERMARK_SIZE - 1] = '\0';
}

int main() {
    char* host = "This is the host image. ";
    char* watermark = "This is the watermark. ";

    generate_watermark(watermark);

    embed_watermark(host, watermark);

    printf("Watermarked image: %s\n", host);

    char extracted_watermark[WATERMARK_SIZE];
    extract_watermark(host, extracted_watermark);

    printf("Extracted watermark: %s\n", extracted_watermark);

    return 0;
}