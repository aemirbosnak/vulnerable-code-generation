//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: rigorous
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

Image *load_image(const char *filename);
void save_image(const char *filename, Image *img);
void embed_text(Image *img, const char *text);
char *extract_text(Image *img);

void free_image(Image *img) {
    if (img) {
        free(img->pixels);
        free(img);
    }
}

Image *load_image(const char *filename) {
    // This is a simplified image loading function, in practice you'll 
    // want to use a proper library like libPNG or libJPEG
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Failed to open file %s\n", filename);
        return NULL;
    }
    
    // For simplicity, we will skip header parsing.
    // In reality, always read and interpret the image format header.
    fseek(fp, 18, SEEK_SET);
    
    Image *img = (Image *)malloc(sizeof(Image));
    if (!img) {
        printf("Memory allocation failed\n");
        fclose(fp);
        return NULL;
    }

    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);
    
    img->pixels = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));
    if (!img->pixels) {
        printf("Memory allocation for pixels failed\n");
        fclose(fp);
        free(img);
        return NULL;
    }

    fread(img->pixels, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
    return img;
}

void save_image(const char *filename, Image *img) {
    // Simplified save function, does not handle different formats.
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Failed to open file %s for writing\n", filename);
        return;
    }
    
    // In a proper implementation you need to write the correct header
    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);
    
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
}

void embed_text(Image *img, const char *text) {
    int text_length = strlen(text);
    if (text_length > img->width * img->height) {
        printf("Text too large to embed\n");
        return;
    }

    for (int i = 0; i < text_length; i++) {
        // Store each character in the least significant bit of the blue channel
        img->pixels[i].b = (img->pixels[i].b & 0xFE) | ((text[i] >> 7) & 1);
        img->pixels[i].b = (img->pixels[i].b & 0xFD) | ((text[i] >> 6) & 1) << 1;
        img->pixels[i].b = (img->pixels[i].b & 0xFB) | ((text[i] >> 5) & 1) << 2;
        img->pixels[i].b = (img->pixels[i].b & 0xF7) | ((text[i] >> 4) & 1) << 3;
        img->pixels[i].b = (img->pixels[i].b & 0xEF) | ((text[i] >> 3) & 1) << 4;
        img->pixels[i].b = (img->pixels[i].b & 0xDF) | ((text[i] >> 2) & 1) << 5;
        img->pixels[i].b = (img->pixels[i].b & 0xBF) | ((text[i] >> 1) & 1) << 6;
        img->pixels[i].b = (img->pixels[i].b & 0x7F) | (text[i] & 1) << 7;
    }
}

char *extract_text(Image *img) {
    int text_length = img->width * img->height;
    char *text = (char *)malloc(text_length + 1);
    if (!text) {
        printf("Memory allocation for extracted text failed\n");
        return NULL;
    }
    
    for (int i = 0; i < text_length; i++) {
        text[i] = 0;
        for (int j = 0; j < 8; j++) {
            text[i] |= ((img->pixels[i].b >> j) & 1) << j; 
        }
    }
    
    text[text_length] = '\0';
    return text;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_image> <output_image> <text_to_embed>\n", argv[0]);
        return 1;
    }

    Image *img = load_image(argv[1]);
    if (!img) return 1;

    embed_text(img, argv[3]);
    save_image(argv[2], img);

    char *extracted_text = extract_text(img);
    printf("Extracted Text: %s\n", extracted_text);

    free(extracted_text);
    free_image(img);
    return 0;
}