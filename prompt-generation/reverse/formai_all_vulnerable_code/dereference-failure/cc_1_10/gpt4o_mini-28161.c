//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000
#define MESSAGE_PREFIX "Sir Msg: "

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct {
    Pixel *pixels;
    int width;
    int height;
} Image;

void createImage(const char *file_name, int width, int height) {
    FILE *file = fopen(file_name, "wb");
    fprintf(file, "P6\n%d %d\n255\n", width, height);
    Pixel *pixels = malloc(width * height * sizeof(Pixel));
    for (int i = 0; i < width * height; i++) {
        pixels[i].r = pixels[i].g = pixels[i].b = 255; // White background
    }
    fwrite(pixels, sizeof(Pixel), width * height, file);
    free(pixels);
    fclose(file);
}

Image load_image(const char *filename) {
    Image img;
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        fprintf(stderr, "Alas! The image cannot be found...\n");
        exit(1);
    }
    fscanf(f, "P6\n%d %d\n255\n", &img.width, &img.height);
    img.pixels = malloc(img.width * img.height * sizeof(Pixel));
    fread(img.pixels, sizeof(Pixel), img.width * img.height, f);
    fclose(f);
    return img;
}

void save_image(const char *filename, Image img) {
    FILE *f = fopen(filename, "wb");
    fprintf(f, "P6\n%d %d\n255\n", img.width, img.height);
    fwrite(img.pixels, sizeof(Pixel), img.width * img.height, f);
    fclose(f);
}

void embed_message(Image *img, const char *message) {
    int message_len = strlen(message);
    if (message_len > MAX_MESSAGE_LENGTH) {
        fprintf(stderr, "The message is too long for the pixels...\n");
        exit(1);
    }
    
    // Prefix the message with a known length indicator
    char full_message[MAX_MESSAGE_LENGTH + 10];
    snprintf(full_message, sizeof(full_message), "%s%d|", MESSAGE_PREFIX, message_len);
    strcat(full_message, message);

    for (int i = 0; i < strlen(full_message) && i < img->width * img->height; i++) {
        int pixel_index = i;
        img->pixels[pixel_index].r = (img->pixels[pixel_index].r & ~1) | ((full_message[i] >> 0) & 1);
        img->pixels[pixel_index].g = (img->pixels[pixel_index].g & ~1) | ((full_message[i] >> 1) & 1);
        img->pixels[pixel_index].b = (img->pixels[pixel_index].b & ~1) | ((full_message[i] >> 2) & 1);
    }
}

void extract_message(const Image img) {
    char message[MAX_MESSAGE_LENGTH + 10] = {0};
    int i = 0;

    while (i < img.width * img.height) {
        char current_char = 0;
        current_char |= (img.pixels[i].r & 1) << 0;
        current_char |= (img.pixels[i].g & 1) << 1;
        current_char |= (img.pixels[i].b & 1) << 2;

        if (current_char == '\0') {
            break; 
        }
        message[i] = current_char;
        i++;
    }

    printf("Hark! The hidden message is: %s\n", message);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s create/image_file_name|embed/image_file_name message|extract/image_file_name\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "create") == 0) {
        createImage(argv[2], 100, 100);
    } 
    else if (strcmp(argv[1], "embed") == 0) {
        Image img = load_image(argv[2]);
        embed_message(&img, argv[3]);
        save_image(argv[2], img);
        free(img.pixels);
        printf("The message hath been embedded!\n");
    } 
    else if (strcmp(argv[1], "extract") == 0) {
        Image img = load_image(argv[2]);
        extract_message(img);
        free(img.pixels);
    } 
    else {
        fprintf(stderr, "Unrecognized command. Pray, follow the script diligently.\n");
        return 1;
    }

    return 0;
}