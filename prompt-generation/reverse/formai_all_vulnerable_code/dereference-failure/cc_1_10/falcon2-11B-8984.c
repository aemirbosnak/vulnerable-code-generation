//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 8
#define COVER_FILE "cover.jpg"
#define MSG_FILE "message.txt"
#define OUTPUT_FILE "output.jpg"

void write_to_file(char* filename, char* data, int size) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fwrite(data, sizeof(char), size, fp);

    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <cover_file> <msg_file>\n", argv[0]);
        return 1;
    }

    char* cover_file = argv[1];
    char* msg_file = argv[2];

    FILE* cover_fp = fopen(cover_file, "rb");
    if (cover_fp == NULL) {
        printf("Error opening cover file!\n");
        return 1;
    }

    FILE* msg_fp = fopen(msg_file, "rb");
    if (msg_fp == NULL) {
        printf("Error opening message file!\n");
        return 1;
    }

    char* cover_data = malloc(sizeof(char) * BLOCK_SIZE);
    if (cover_data == NULL) {
        printf("Error allocating memory for cover data!\n");
        return 1;
    }

    int msg_size = fread(cover_data, sizeof(char), BLOCK_SIZE, cover_fp);
    fclose(cover_fp);

    int msg_idx = 0;
    while (msg_size < BLOCK_SIZE) {
        fread(cover_data, sizeof(char), BLOCK_SIZE, cover_fp);
        msg_size += fread(cover_data, sizeof(char), BLOCK_SIZE, cover_fp);
    }

    FILE* output_fp = fopen(OUTPUT_FILE, "wb");
    if (output_fp == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }

    int i = 0;
    for (; i < msg_size; i += 1) {
        char msg_byte = fgetc(msg_fp);
        if (msg_byte == EOF) {
            printf("Error reading message file!\n");
            return 1;
        }

        cover_data[msg_idx % BLOCK_SIZE] = msg_byte;
        msg_idx += 1;
    }

    fclose(msg_fp);

    fwrite(cover_data, sizeof(char), BLOCK_SIZE, output_fp);
    fclose(output_fp);

    free(cover_data);

    return 0;
}