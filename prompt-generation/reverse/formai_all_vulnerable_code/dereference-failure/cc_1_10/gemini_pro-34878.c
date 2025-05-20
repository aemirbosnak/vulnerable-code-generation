//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t * data;
    size_t length;
} image_t;

typedef struct {
    uint8_t * data;
    size_t length;
} secret_t;

image_t* image_load(char * filename) {
    FILE * fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    size_t length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    uint8_t * data = malloc(length);
    if (data == NULL) {
        fclose(fp);
        return NULL;
    }

    fread(data, 1, length, fp);
    fclose(fp);

    image_t * image = malloc(sizeof(image_t));
    if (image == NULL) {
        free(data);
        return NULL;
    }

    image->data = data;
    image->length = length;

    return image;
}

void image_free(image_t * image) {
    free(image->data);
    free(image);
}

secret_t* secret_load(char * filename) {
    FILE * fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    size_t length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    uint8_t * data = malloc(length);
    if (data == NULL) {
        fclose(fp);
        return NULL;
    }

    fread(data, 1, length, fp);
    fclose(fp);

    secret_t * secret = malloc(sizeof(secret_t));
    if (secret == NULL) {
        free(data);
        return NULL;
    }

    secret->data = data;
    secret->length = length;

    return secret;
}

void secret_free(secret_t * secret) {
    free(secret->data);
    free(secret);
}

int image_hide(image_t * image, secret_t * secret) {
    if (image->length < secret->length * 8) {
        return -1;
    }

    for (size_t i = 0; i < secret->length; i++) {
        for (int j = 7; j >= 0; j--) {
            int bit = (secret->data[i] >> j) & 1;
            int offset = i * 8 + j;
            image->data[offset] &= ~1;
            image->data[offset] |= bit;
        }
    }

    return 0;
}

int image_extract(image_t * image, secret_t * secret) {
    for (size_t i = 0; i < secret->length; i++) {
        secret->data[i] = 0;
        for (int j = 7; j >= 0; j--) {
            int offset = i * 8 + j;
            secret->data[i] |= (image->data[offset] & 1) << j;
        }
    }

    return 0;
}

int main(int argc, char ** argv) {
    if (argc != 5) {
        printf("Usage: %s <image file> <secret file> <output image file> <extract/hide>\n", argv[0]);
        return 1;
    }

    char * image_filename = argv[1];
    char * secret_filename = argv[2];
    char * output_filename = argv[3];
    char * mode = argv[4];

    image_t * image = image_load(image_filename);
    if (image == NULL) {
        printf("Error loading image file.\n");
        return 1;
    }

    secret_t * secret = secret_load(secret_filename);
    if (secret == NULL) {
        printf("Error loading secret file.\n");
        image_free(image);
        return 1;
    }

    int result;
    if (strcmp(mode, "hide") == 0) {
        result = image_hide(image, secret);
        if (result != 0) {
            printf("Error hiding secret in image.\n");
            image_free(image);
            secret_free(secret);
            return 1;
        }
    } else if (strcmp(mode, "extract") == 0) {
        result = image_extract(image, secret);
        if (result != 0) {
            printf("Error extracting secret from image.\n");
            image_free(image);
            secret_free(secret);
            return 1;
        }
    } else {
        printf("Invalid mode. Must be either \"hide\" or \"extract\".\n");
        image_free(image);
        secret_free(secret);
        return 1;
    }

    FILE * fp = fopen(output_filename, "wb");
    if (fp == NULL) {
        printf("Error opening output file.\n");
        image_free(image);
        secret_free(secret);
        return 1;
    }

    fwrite(image->data, 1, image->length, fp);
    fclose(fp);

    image_free(image);
    secret_free(secret);

    return 0;
}