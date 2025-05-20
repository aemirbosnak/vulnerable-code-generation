//FormAI DATASET v1.0 Category: Image Steganography ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r, g, b;
} pixel;

void encode_message(pixel *img, char *msg, size_t msg_len) {
    for (size_t i = 0, j = 0; i < msg_len * 8; i++, j++) {
        if (j == 3) { // skip alpha channel if present
            j = 0;
        }
        uint8_t bit = (msg[i / 8] >> (7 - (i % 8))) & 1;
        img[i / 3].r = (img[i / 3].r & ~1) | bit;
    }
}

void decode_message(pixel *img, size_t img_len) {
    char msg[256] = {0};
    for (size_t i = 0, j = 0; i < 256 * 8; i++, j++) {
        if (j == 3) { // skip alpha channel if present
            j = 0;
        }
        uint8_t bit = img[i / 3].r & 1;
        msg[i / 8] |= (bit << (7 - (i % 8)));
    }
    printf("Hidden message: %s\n", msg);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    char msg[] = "Hello, world!";
    size_t msg_len = strlen(msg);

    FILE *fp_in = fopen(argv[1], "rb");
    fseek(fp_in, 0, SEEK_END);
    size_t img_len = ftell(fp_in);
    fseek(fp_in, 0, SEEK_SET);
    pixel *img = calloc(img_len / 3, sizeof(pixel));
    fread(img, 1, img_len, fp_in);
    fclose(fp_in);

    encode_message(img, msg, msg_len);

    FILE *fp_out = fopen(argv[2], "wb");
    fwrite(img, 1, img_len, fp_out);
    fclose(fp_out);

    pixel *img2 = calloc(img_len / 3, sizeof(pixel));
    fp_out = fopen(argv[2], "rb");
    fread(img2, 1, img_len, fp_out);
    fclose(fp_out);

    decode_message(img2, img_len / 3);

    free(img);
    free(img2);

    return 0;
}