//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    unsigned int width, height;
    unsigned char *pixels;
} Bitmap;

int load_bitmap(const char *filename, Bitmap *bmp) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return -1;

    fseek(fp, 18, SEEK_SET);
    fread(&bmp->width, sizeof(unsigned int), 1, fp);
    fread(&bmp->height, sizeof(unsigned int), 1, fp);
    fseek(fp, 54, SEEK_SET);
    bmp->pixels = malloc(bmp->width * bmp->height * 3);
    fread(bmp->pixels, bmp->width * bmp->height * 3, 1, fp);
    fclose(fp);

    return 0;
}

void free_bitmap(Bitmap *bmp) {
    free(bmp->pixels);
}

int hide_message(Bitmap *bmp, const char *message) {
    int i, j, k, m = 0;
    unsigned char *msg = (unsigned char *)message;

    for (i = 0; i < bmp->height; i++) {
        for (j = 0; j < bmp->width; j++) {
            for (k = 0; k < 3; k++) {
                bmp->pixels[i * bmp->width * 3 + j * 3 + k] &= ~1;
                bmp->pixels[i * bmp->width * 3 + j * 3 + k] |= (msg[m >> 3] >> (7 - (m & 7))) & 1;
                m++;
                if (msg[m >> 3] == '\0') return 0;
            }
        }
    }

    return -1;
}

int extract_message(Bitmap *bmp, char *message) {
    int i, j, k, m = 0;

    for (i = 0; i < bmp->height; i++) {
        for (j = 0; j < bmp->width; j++) {
            for (k = 0; k < 3; k++) {
                message[m >> 3] |= (bmp->pixels[i * bmp->width * 3 + j * 3 + k] & 1) << (7 - (m & 7));
                m++;
            }
        }
    }

    message[m >> 3] = '\0';

    return 0;
}

int main(int argc, char **argv) {
    Bitmap bmp;
    char message[1024];

    if (argc < 4) {
        printf("Usage: %s <input_image> <output_image> <message>\n", argv[0]);
        return -1;
    }

    if (load_bitmap(argv[1], &bmp) == -1) {
        printf("Error loading input image.\n");
        return -1;
    }

    if (hide_message(&bmp, argv[3]) == -1) {
        printf("Error hiding message.\n");
        free_bitmap(&bmp);
        return -1;
    }

    if (extract_message(&bmp, message) == -1) {
        printf("Error extracting message.\n");
        free_bitmap(&bmp);
        return -1;
    }

    printf("Message: %s\n", message);

    free_bitmap(&bmp);

    return 0;
}