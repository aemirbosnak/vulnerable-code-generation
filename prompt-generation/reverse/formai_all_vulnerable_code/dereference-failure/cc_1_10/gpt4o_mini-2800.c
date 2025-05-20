//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image* loadImage(const char* filename);
void saveImage(const char* filename, Image* img);
void hideMessage(Image* img, const char* message);
char* extractMessage(Image* img, int maxLength);

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <message> <output_image>\n", argv[0]);
        return 1;
    }

    const char* inputImageFile = argv[1];
    const char* message = argv[2];
    const char* outputImageFile = argv[3];

    Image* img = loadImage(inputImageFile);
    if (!img) {
        fprintf(stderr, "Could not load image %s\n", inputImageFile);
        return 1;
    }

    hideMessage(img, message);
    saveImage(outputImageFile, img);

    printf("Message hidden in %s\n", outputImageFile);
    
    char* retrievedMessage = extractMessage(img, strlen(message) + 1);
    printf("Extracted message: %s\n", retrievedMessage);

    free(retrievedMessage);
    free(img->pixels);
    free(img);
    
    return 0;
}

Image* loadImage(const char* filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return NULL;

    fseek(fp, 18, SEEK_SET);  // Skip to width and height
    Image* img = malloc(sizeof(Image));
    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);
    
    fseek(fp, 54, SEEK_SET); // Skip to pixel data
    img->pixels = malloc(sizeof(Pixel) * img->width * img->height);
    fread(img->pixels, sizeof(Pixel), img->width * img->height, fp);
    
    fclose(fp);
    return img;
}

void saveImage(const char* filename, Image* img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) return;

    // Write the BMP header (assuming 24-bit BMP)
    unsigned char bmpHeader[54] = {
        0x42, 0x4D, 0x36, 0x28, 0x0, 0x0, 0x0, 0x0, 
        0x36, 0x0, 0x0, 0x0, 0x28, 0x0, 0x0, 0x0,  
        0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x18, 0x0,  
        0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
        0x0, 0x0, 0x0, 0x0
    };
    
    *(int*)&bmpHeader[18] = img->width;
    *(int*)&bmpHeader[22] = img->height;
    *(int*)&bmpHeader[34] = img->width * img->height * sizeof(Pixel);
    
    fwrite(bmpHeader, sizeof(bmpHeader), 1, fp);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, fp);
    
    fclose(fp);
}

void hideMessage(Image* img, const char* message) {
    int messageLength = strlen(message);
    for (int i = 0; i < messageLength; i++) {
        img->pixels[i].r = (img->pixels[i].r & 0xFE) | ((message[i] >> 7) & 0x01);
        img->pixels[i].g = (img->pixels[i].g & 0xFE) | ((message[i] >> 6) & 0x01);
        img->pixels[i].b = (img->pixels[i].b & 0xFE) | ((message[i] >> 5) & 0x01);
    }
    
    // End of message marker
    img->pixels[messageLength].r = (img->pixels[messageLength].r & 0xFE) | 0x01;
}

char* extractMessage(Image* img, int maxLength) {
    char* message = malloc(maxLength);
    int i;
    for (i = 0; i < maxLength; i++) {
        if ((img->pixels[i].r & 0x01) == 0x01) break;
        message[i] = ((img->pixels[i].r & 0x01) << 7) |
                     ((img->pixels[i].g & 0x01) << 6) |
                     ((img->pixels[i].b & 0x01) << 5);
    }
    message[i] = '\0';  // Null terminate the string
    return message;
}