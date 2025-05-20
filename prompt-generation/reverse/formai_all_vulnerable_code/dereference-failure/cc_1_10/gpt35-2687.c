//FormAI DATASET v1.0 Category: Image Steganography ; Style: thoughtful
#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned char red, green, blue;
} pixel;

typedef struct {
    int width, height;
    pixel data[];
} image;

void encode(image *img, char *message) {
    int len = strlen(message), index = 0;
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            if (index < len) {
                img->data[i * img->width + j].red = (img->data[i * img->width + j].red & 0xFE) | ((message[index] >> 7) & 0x01);
                img->data[i * img->width + j].green = (img->data[i * img->width + j].green & 0xFE) | ((message[index] >> 6) & 0x01);
                img->data[i * img->width + j].blue = (img->data[i * img->width + j].blue & 0xFE) | ((message[index] >> 5) & 0x01);
                index++;
            }
        }
    }
}

char *decode(image *img, int len) {
    char *message = malloc(len + 1);
    int index = 0;
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            message[index] = 0;
            message[index] |= ((img->data[i * img->width + j].red & 0x01) << 7);
            message[index] |= ((img->data[i * img->width + j].green & 0x01) << 6);
            message[index] |= ((img->data[i * img->width + j].blue & 0x01) << 5);
            index++;
            if (index >= len) {
                message[len] = '\0';
                return message;
            }
        }
    }
    message[len] = '\0';
    return message;
}

int main() {
    // Load image
    FILE *file = fopen("image.bmp", "rb");
    if (!file) {
        printf("Failed to open image file\n");
        return 1;
    }
    fseek(file, 10, SEEK_SET);
    int pixel_start;
    fread(&pixel_start, sizeof(int), 1, file);
    fseek(file, 18, SEEK_SET);
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, pixel_start, SEEK_SET);
    image *img = malloc(sizeof(image) + width * height * sizeof(pixel));
    img->width = width;
    img->height = height;
    fread(img->data, sizeof(pixel), width * height, file);
    fclose(file);

    // Encode message
    char *message = "Steganography is cool!";
    encode(img, message);

    // Save image
    file = fopen("encoded_image.bmp", "wb");
    fwrite(img, sizeof(image) + (width * height * sizeof(pixel)), 1, file);
    fclose(file);

    // Decode message
    file = fopen("encoded_image.bmp", "rb");
    fseek(file, pixel_start, SEEK_SET);
    image *img2 = malloc(sizeof(image) + width * height * sizeof(pixel));
    img2->width = width;
    img2->height = height;
    fread(img2->data, sizeof(pixel), width * height, file);
    fclose(file);
    char *decoded_message = decode(img2, strlen(message));
    printf("Decoded message: %s\n", decoded_message);

    return 0;
}