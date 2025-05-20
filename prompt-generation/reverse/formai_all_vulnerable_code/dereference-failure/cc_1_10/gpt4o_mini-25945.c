//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t importantColors;
} BMPInfoHeader;
#pragma pack(pop)

typedef struct {
    char *message;
    uint8_t *imageData;
    int width;
    int height;
    int startRow;
    int endRow;
} ThreadData;

void *embed_message(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int idx = 0;
    int imageSize = data->width * data->height * 3; // 3 bytes per pixel
    int msgLength = strlen(data->message);

    for (int row = data->startRow; row < data->endRow; row++) {
        for (int col = 0; col < data->width; col++) {
            int pixelIdx = (row * data->width + col) * 3;

            // Stop if message is finished
            if (idx < msgLength) {
                // Embed the message bit in least significant bit of each color
                data->imageData[pixelIdx] = (data->imageData[pixelIdx] & 0xFE) | ((data->message[idx] >> (7 - (col % 8))) & 0x01);
                // Move to next character if the entire byte is processed
                if (col % 8 == 7) {
                    idx++;
                }
            }
        }
    }
    return NULL;
}

void hide_message_in_image(const char *fileName, const char *message) {
    FILE *file = fopen(fileName, "rb+");
    if (!file) {
        perror("Error opening file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    
    fread(&bmpHeader, sizeof(BMPHeader), 1, file);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);
    
    int imageSize = bmpInfoHeader.width * bmpInfoHeader.height * 3; // BMP is 24 bits
    uint8_t *imageData = malloc(imageSize);
    fseek(file, bmpHeader.offset, SEEK_SET);
    fread(imageData, sizeof(uint8_t), imageSize, file);

    int numThreads = 4;
    pthread_t threads[numThreads];
    ThreadData threadData[numThreads];

    // Create threads to embed message
    for (int i = 0; i < numThreads; i++) {
        threadData[i].message = (char *)message;
        threadData[i].imageData = imageData;
        threadData[i].width = bmpInfoHeader.width;
        threadData[i].height = bmpInfoHeader.height;
        threadData[i].startRow = (bmpInfoHeader.height / numThreads) * i;
        threadData[i].endRow = (bmpInfoHeader.height / numThreads) * (i + 1);
        if (i == numThreads - 1) {
            threadData[i].endRow = bmpInfoHeader.height; // Last thread takes the remaining rows
        }
        pthread_create(&threads[i], NULL, embed_message, (void *)&threadData[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Write modified image to file
    fseek(file, bmpHeader.offset, SEEK_SET);
    fwrite(imageData, sizeof(uint8_t), imageSize, file);

    free(imageData);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <image_file.bmp> <message>\n", argv[0]);
        return 1;
    }

    hide_message_in_image(argv[1], argv[2]);
    printf("Message hidden successfully.\n");

    return 0;
}