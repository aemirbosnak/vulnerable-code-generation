//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#pragma pack(1)

typedef struct {
    unsigned short bfType;
    unsigned long bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned long bfOffBits;
} BMPFileHeader;

typedef struct {
    unsigned long biSize;
    long biWidth;
    long biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned long biCompression;
    unsigned long biSizeImage;
    long biXPelsPerMeter;
    long biYPelsPerMeter;
    unsigned long biClrUsed;
    unsigned long biClrImportant;
} BMPInfoHeader;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Pixel;

// Function to load a BMP image
Pixel **load_image(const char *filename, BMPFileHeader *fileHeader, BMPInfoHeader *infoHeader) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    fread(fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(infoHeader, sizeof(BMPInfoHeader), 1, file);

    Pixel **image = malloc(infoHeader->biHeight * sizeof(Pixel *));
    for (int i = 0; i < infoHeader->biHeight; i++) {
        image[i] = malloc(infoHeader->biWidth * sizeof(Pixel));
        fread(image[i], sizeof(Pixel), infoHeader->biWidth, file);
    }

    fclose(file);
    return image;
}

// Function to save a BMP image
void save_image(const char *filename, Pixel **image, BMPFileHeader fileHeader, BMPInfoHeader infoHeader) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to save file");
        return;
    }

    fwrite(&fileHeader, sizeof(BMPFileHeader), 1, file);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, file);

    for (int i = 0; i < infoHeader.biHeight; i++) {
        fwrite(image[i], sizeof(Pixel), infoHeader.biWidth, file);
        free(image[i]);
    }
    free(image);
    fclose(file);
}

// Simple image filter (negate)
void apply_filter(Pixel **image, BMPInfoHeader infoHeader) {
    for (int i = 0; i < infoHeader.biHeight; i++) {
        for (int j = 0; j < infoHeader.biWidth; j++) {
            image[i][j].red = 255 - image[i][j].red;
            image[i][j].green = 255 - image[i][j].green;
            image[i][j].blue = 255 - image[i][j].blue;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    Pixel **image;

    // Load the image
    pid_t pid = fork();
    if (pid == 0) {  // Child process to load image
        printf("Loading image in Child Process...\n");
        image = load_image(argv[1], &fileHeader, &infoHeader);
        if (image == NULL) {
            exit(1);
        }
        exit(0);
    } else if (pid < 0) {
        perror("Failed to fork");
        return 1;
    }

    // Wait for the child process to finish
    wait(NULL);

    // Apply filter
    printf("Applying filter in Parent Process...\n");
    apply_filter(image, infoHeader);

    // Save the modified image
    save_image(argv[2], image, fileHeader, infoHeader);

    printf("Image processing complete. Saved to %s\n", argv[2]);
    return 0;
}