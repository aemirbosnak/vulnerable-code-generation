//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to convert integer to binary
char* int_to_bin(int n)
{
    char *binary_str = malloc(sizeof(char) * (32 + 1)); // 32 bits for int
    binary_str[32] = '\0';
    int i;
    for (i = 31; i >= 0; i--) {
        binary_str[i] = (n & 1) ? '1' : '0';
        n >>= 1;
    }
    return binary_str;
}

// Function to embed watermark in the LSB of image pixel values
void embed_watermark(char* image_path, char* watermark)
{
    FILE* img = fopen(image_path, "rb");
    if (!img) {
        printf("Unable to open image file!\n");
        return;
    }

    char* ext = strrchr(image_path, '.');
    if (!ext) {
        printf("Invalid image file extension!\n");
        return;
    }
    char watermark_ext[5] = ".wtr";
    strcpy(ext, watermark_ext);

    FILE* wmark = fopen(image_path, "wb");
    if (!wmark) {
        printf("Unable to create watermark file!\n");
        return;
    }

    int img_size;
    fseek(img, 0, SEEK_END);
    img_size = ftell(img);
    rewind(img);

    char* img_buf = malloc(sizeof(char) * img_size);
    fread(img_buf, 1, img_size, img);

    int i, j, k;
    char* wtr_buf = malloc(sizeof(char) * (strlen(watermark) * 8 + 1));
    for (i = 0, k = 0; i < strlen(watermark); i++, k += 8) {
        char* bin = int_to_bin((int)watermark[i]);
        for (j = 0; j < 8; j++) {
            img_buf[k + j] = (img_buf[k + j] & 0xFE) | (bin[j] - '0');
        }
        free(bin);
    }

    fwrite(img_buf, 1, img_size, wmark);
    free(wtr_buf);
    free(img_buf);

    fclose(img);
    fclose(wmark);

    printf("Watermark embedded successfully in the image!\n");
}

// Function to extract watermark from the LSB of image pixel values
void extract_watermark(char* image_path)
{
    FILE* img = fopen(image_path, "rb");
    if (!img) {
        printf("Unable to open image file!\n");
        return;
    }

    char* ext = strrchr(image_path, '.');
    if (!ext || strcmp(ext, ".wtr") != 0) {
        printf("Invalid watermark file extension or missing watermark file!\n");
        return;
    }

    int img_size;
    fseek(img, 0, SEEK_END);
    img_size = ftell(img);
    rewind(img);

    char* img_buf = malloc(sizeof(char) * img_size);
    fread(img_buf, 1, img_size, img);

    char* wtr_buf = malloc(sizeof(char) * (img_size / 8 + 1));
    int i, j, k;
    for (i = 0, k = 0; k < img_size / 8; i += 8, k++) {
        char byte = 0;
        for (j = 0; j < 8; j++) {
            byte += (img_buf[i + j] & 0x01) << (7 - j);
        }
        wtr_buf[k] = byte;
    }
    wtr_buf[k] = '\0';

    printf("Extracted Watermark:\n%s\n", wtr_buf);

    free(wtr_buf);
    free(img_buf);

    fclose(img);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: watermark <image_path> [watermark]\n");
        return 1;
    }

    if (argc > 2) {
        embed_watermark(argv[1], argv[2]);
    } else {
        extract_watermark(argv[1]);
    }

    return 0;
}