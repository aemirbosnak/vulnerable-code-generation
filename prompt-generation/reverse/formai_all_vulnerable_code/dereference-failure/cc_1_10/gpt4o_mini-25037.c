//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void embedMessage(char *imagePath, char *message) {
    FILE *imageFile = fopen(imagePath, "rb+");
    if (imageFile == NULL) {
        perror("Error opening image file");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, imageFile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, imageFile);

    if (bfh.bfType != 0x4D42) {
        printf("Not a BMP file!\n");
        fclose(imageFile);
        return;
    }

    // Prepare the message
    int messageLength = strlen(message);
    if (messageLength > 255) {
        printf("Message is too long! Maximum allowed is 255 characters.\n");
        fclose(imageFile);
        return;
    }

    // Write the length of the message at the end of the image
    fseek(imageFile, bfh.bfOffBits + (bih.biWidth * bih.biHeight * 3), SEEK_SET);
    fwrite(&messageLength, sizeof(int), 1, imageFile);
    fwrite(message, sizeof(char), messageLength, imageFile);

    fclose(imageFile);
    printf("Message embedded successfully!\n");
}

void extractMessage(char *imagePath) {
    FILE *imageFile = fopen(imagePath, "rb");
    if (imageFile == NULL) {
        perror("Error opening image file");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, imageFile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, imageFile);

    if (bfh.bfType != 0x4D42) {
        printf("Not a BMP file!\n");
        fclose(imageFile);
        return;
    }

    // Move to where the message length is stored
    fseek(imageFile, bfh.bfOffBits + (bih.biWidth * bih.biHeight * 3), SEEK_SET);
    int messageLength;
    fread(&messageLength, sizeof(int), 1, imageFile);
    
    char *message = (char *)malloc(messageLength + 1);
    fread(message, sizeof(char), messageLength, imageFile);
    message[messageLength] = '\0';

    fclose(imageFile);
    printf("Extracted Message: %s\n", message);
    free(message);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s [embed/extract] [image.bmp] [message]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedMessage(argv[2], argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessage(argv[2]);
    } else {
        printf("Invalid operation. Use 'embed' or 'extract'.\n");
    }

    return 0;
}