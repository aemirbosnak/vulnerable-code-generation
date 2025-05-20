//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 10

void generate_watermark(char watermark[WATERMARK_SIZE]) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int charset_size = strlen(charset);
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        int rand_index = rand() % charset_size;
        watermark[i] = charset[rand_index];
    }
}

void embed_watermark(FILE *input_file, FILE *output_file, char watermark[WATERMARK_SIZE]) {
    char buffer[1024];
    int watermark_index = 0;
    while (fgets(buffer, sizeof(buffer), input_file)!= NULL) {
        int buffer_size = strlen(buffer);
        int watermark_pos = rand() % buffer_size;
        for (int i = 0; i < WATERMARK_SIZE; i++) {
            if (watermark_index == WATERMARK_SIZE) {
                watermark_index = 0;
            }
            buffer[watermark_pos + i] = watermark[watermark_index];
            watermark_index++;
        }
        fputs(buffer, output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file watermark\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    char watermark[WATERMARK_SIZE];
    strncpy(watermark, argv[3], WATERMARK_SIZE);

    generate_watermark(watermark);
    embed_watermark(input_file, output_file, watermark);

    fclose(input_file);
    fclose(output_file);

    printf("Watermark embedded successfully.\n");
    return 0;
}