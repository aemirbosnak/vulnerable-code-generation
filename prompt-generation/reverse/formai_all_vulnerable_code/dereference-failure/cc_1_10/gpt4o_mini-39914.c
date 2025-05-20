//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(1)
typedef struct {
    uint16_t bfType;      // Bitmap type
    uint32_t bfSize;      // Size of the file
    uint16_t bfReserved1; // Reserved
    uint16_t bfReserved2; // Reserved
    uint32_t bfOffBits;   // Offset to start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of the image
    int32_t  biHeight;        // Height of the image
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;     // Size of image data
    int32_t  biXPelsPerMeter;   // Pixels per meter in X
    int32_t  biYPelsPerMeter;   // Pixels per meter in Y
    uint32_t biClrUsed;        // Number of colors used
    uint32_t biClrImportant;    // Important colors
} BITMAPINFOHEADER;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGB;

void display_menu() {
    printf("\nBMP Image Editor\n");
    printf("1. Load Image\n");
    printf("2. Adjust Brightness\n");
    printf("3. Save Image\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int load_image(const char *filename, BITMAPFILEHEADER *bfh, BITMAPINFOHEADER *bih, RGB **pixels) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return -1;
    }

    fread(bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(bih, sizeof(BITMAPINFOHEADER), 1, file);

    // Validate BMP format
    if (bfh->bfType != 0x4D42) {
        printf("Error: Not a valid BMP file\n");
        fclose(file);
        return -1;
    }

    // Allocate memory for pixel data
    int image_size = bih->biWidth * bih->biHeight;
    *pixels = malloc(image_size * sizeof(RGB));

    fseek(file, bfh->bfOffBits, SEEK_SET);
    fread(*pixels, sizeof(RGB), image_size, file);
    fclose(file);
    
    printf("Image %s loaded successfully.\n", filename);
    return 0;
}

void adjust_brightness(RGB *pixels, int width, int height, int adjustment) {
    for (int i = 0; i < width * height; i++) {
        pixels[i].red = (pixels[i].red + adjustment > 255) ? 255 : (pixels[i].red + adjustment < 0) ? 0 : pixels[i].red + adjustment;
        pixels[i].green = (pixels[i].green + adjustment > 255) ? 255 : (pixels[i].green + adjustment < 0) ? 0 : pixels[i].green + adjustment;
        pixels[i].blue = (pixels[i].blue + adjustment > 255) ? 255 : (pixels[i].blue + adjustment < 0) ? 0 : pixels[i].blue + adjustment;
    }
}

int save_image(const char *filename, BITMAPFILEHEADER bfh, BITMAPINFOHEADER bih, RGB *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return -1;
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, file);

    fseek(file, bfh.bfOffBits, SEEK_SET);
    int image_size = bih.biWidth * bih.biHeight;
    fwrite(pixels, sizeof(RGB), image_size, file);
    fclose(file);
    
    printf("Image saved as %s successfully.\n", filename);
    return 0;
}

int main() {
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    RGB *pixels = NULL;
    char load_file[100], save_file[100];
    int choice;
    int adjustment;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the filename to load: ");
                scanf("%s", load_file);
                if (load_image(load_file, &bfh, &bih, &pixels) == 0) {
                    printf("Image loaded with width: %d, height: %d\n", bih.biWidth, bih.biHeight);
                }
                break;

            case 2:
                printf("Enter brightness adjustment (-255 to 255): ");
                scanf("%d", &adjustment);
                if (pixels) {
                    adjust_brightness(pixels, bih.biWidth, bih.biHeight, adjustment);
                    printf("Brightness adjusted.\n");
                } else {
                    printf("Error: No image loaded!\n");
                }
                break;

            case 3:
                printf("Enter the filename to save: ");
                scanf("%s", save_file);
                if (pixels) {
                    save_image(save_file, bfh, bih, pixels);
                } else {
                    printf("Error: No image loaded!\n");
                }
                break;

            case 4:
                free(pixels);
                printf("Exiting the editor. Bye!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}