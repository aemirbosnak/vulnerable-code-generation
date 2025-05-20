//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BMP_HEADER_SIZE 14
#define DIB_HEADER_SIZE 40

typedef struct {
    unsigned char b;
    unsigned char g;
    unsigned char r;
} pixel_t;

typedef struct {
    unsigned char *data;
    int width;
    int height;
} image_t;

image_t *load_image(const char *filename) {
    FILE *fp;
    image_t *image;
    unsigned char header[BMP_HEADER_SIZE + DIB_HEADER_SIZE];

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    fread(header, 1, BMP_HEADER_SIZE + DIB_HEADER_SIZE, fp);

    image = malloc(sizeof(image_t));
    if (image == NULL) {
        fclose(fp);
        return NULL;
    }

    image->width = *(int *)&header[18];
    image->height = *(int *)&header[22];

    image->data = malloc(image->width * image->height * sizeof(pixel_t));
    if (image->data == NULL) {
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->data, 1, image->width * image->height * sizeof(pixel_t), fp);

    fclose(fp);

    return image;
}

void save_image(const char *filename, image_t *image) {
    FILE *fp;
    unsigned char header[BMP_HEADER_SIZE + DIB_HEADER_SIZE];

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    memset(header, 0, BMP_HEADER_SIZE + DIB_HEADER_SIZE);

    header[0] = 'B';
    header[1] = 'M';

    *(int *)&header[2] = BMP_HEADER_SIZE + DIB_HEADER_SIZE + image->width * image->height * sizeof(pixel_t);
    *(int *)&header[10] = DIB_HEADER_SIZE;
    *(int *)&header[14] = image->width;
    *(int *)&header[18] = image->height;
    *(short *)&header[28] = 24;
    *(int *)&header[34] = image->width * image->height * sizeof(pixel_t);

    fwrite(header, 1, BMP_HEADER_SIZE + DIB_HEADER_SIZE, fp);
    fwrite(image->data, 1, image->width * image->height * sizeof(pixel_t), fp);

    fclose(fp);
}

void hide_message(image_t *image, const char *message) {
    int i, j, k;
    unsigned char *p;

    for (i = 0, p = image->data; *message; i++, p += 3) {
        for (j = 0; j < 3; j++) {
            for (k = 6; k >= 0; k -= 2) {
                p[j] = (p[j] & ~(3 << k)) | ((message[i] >> k) & 3 << k);
            }
        }
    }
}

char *extract_message(image_t *image) {
    int i, j, k;
    unsigned char *p;
    char *message;

    message = malloc(image->width * image->height / 3 + 1);
    if (message == NULL) {
        return NULL;
    }

    for (i = 0, p = image->data; i < image->width * image->height / 3; i++, p += 3) {
        for (j = 0; j < 3; j++) {
            for (k = 6; k >= 0; k -= 2) {
                message[i] |= (p[j] >> k) & 3 << k;
            }
        }
    }

    message[i] = '\0';

    return message;
}

int main(int argc, char **argv) {
    image_t *image;
    char *message;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <message>\n", argv[0]);
        return 1;
    }

    image = load_image(argv[1]);
    if (image == NULL) {
        fprintf(stderr, "Error loading image: %s\n", argv[1]);
        return 1;
    }

    hide_message(image, argv[3]);

    save_image(argv[2], image);

    message = extract_message(image);
    if (message == NULL) {
        fprintf(stderr, "Error extracting message\n");
        return 1;
    }

    printf("Extracted message: %s\n", message);

    free(message);
    free(image->data);
    free(image);

    return 0;
}