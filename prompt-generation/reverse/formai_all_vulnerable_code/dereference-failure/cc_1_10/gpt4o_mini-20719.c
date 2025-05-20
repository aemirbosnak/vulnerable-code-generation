//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    unsigned char* data;
} BMPImage;
#pragma pack(pop)

BMPImage* loadBMP(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if(!file) return NULL;

    BMPImage* img = (BMPImage*)malloc(sizeof(BMPImage));
    fread(&img->fileHeader, sizeof(img->fileHeader), 1, file);
    fread(&img->infoHeader, sizeof(img->infoHeader), 1, file);

    img->data = (unsigned char*)malloc(img->infoHeader.biSizeImage);
    fread(img->data, img->infoHeader.biSizeImage, 1, file);
    fclose(file);

    return img;
}

void saveBMP(const char* filename, BMPImage* img) {
    FILE* file = fopen(filename, "wb");
    fwrite(&img->fileHeader, sizeof(img->fileHeader), 1, file);
    fwrite(&img->infoHeader, sizeof(img->infoHeader), 1, file);
    fwrite(img->data, img->infoHeader.biSizeImage, 1, file);
    fclose(file);
}

void embedMessage(BMPImage* img, const char* message) {
    int msg_len = strlen(message);
    int img_size = img->infoHeader.biSizeImage;

    if(img_size < msg_len * 8) {
        printf("Image is too small to embed the message.\n");
        return;
    }

    for(int i = 0; i < msg_len; i++) {
        for(int j = 0; j < 8; j++) {
            int pixel_pos = i * 8 + j;
            int byte = (message[i] >> (7 - j)) & 1;
            img->data[pixel_pos] = (img->data[pixel_pos] & ~1) | byte;  // Embed message bit
        }
    }
}

void* encodeThread(void* arg) {
    char* data = (char*)arg;
    BMPImage* img = loadBMP(data); // Load image from filepath
    char message[256];

    printf("Enter the message to embed: ");
    fgets(message, 256, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline

    embedMessage(img, message);
    saveBMP("output.bmp", img);
    free(img->data);
    free(img);
    return NULL;
}

void decodeMessage(BMPImage* img) {
    char message[256] = {0};
    int msg_len = 0;

    for(int i = 0; i < 256 * 8; i++) {
        int byte = img->data[i] & 1;
        if(i % 8 == 0 && msg_len < 255) {
            message[msg_len++] = byte << (7 - (i % 8));
        }
    }
    message[msg_len] = '\0';

    printf("Decoded message: %s\n", message);
}

void* decodeThread(void* arg) {
    BMPImage* img = loadBMP((const char*)arg); // Load image from filepath
    decodeMessage(img);
    free(img->data);
    free(img);
    return NULL;
}

int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("Usage: %s <image_path> <encode/decode>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pthread_t thread;
    if(strcmp(argv[2], "encode") == 0) {
        pthread_create(&thread, NULL, encodeThread, (void*)argv[1]);
    } else if(strcmp(argv[2], "decode") == 0) {
        pthread_create(&thread, NULL, decodeThread, (void*)argv[1]);
    } else {
        printf("Unknown command: Please use 'encode' or 'decode'\n");
        return EXIT_FAILURE;
    }

    pthread_join(thread, NULL);
    return EXIT_SUCCESS;
}