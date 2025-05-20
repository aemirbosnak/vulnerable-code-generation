//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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
    uint16_t bitCount;
    uint32_t compression;
    uint32_t sizeImage;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
} BMPInfoHeader;
#pragma pack(pop)

void unveilMessage(const char *filename, const char *outputFile) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Alas! The image could not be found.\n");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, fp);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, fp);

    uint32_t width = bmpInfoHeader.width;
    uint32_t height = bmpInfoHeader.height;
    int messageIndex = 0;
    char message[1024] = {0};

    for (int i = 0; i < width * height; i++) {
        uint8_t pixel[3];
        fread(pixel, sizeof(uint8_t), 3, fp);
        
        // Extract the least significant bit
        if (messageIndex < sizeof(message) - 1) {
            message[messageIndex] = (pixel[0] & 1) + '0';
            messageIndex++;
            if (messageIndex % 8 == 0) {
                message[messageIndex / 8] = '\0';  
                if (strcmp(message + messageIndex / 8, "00000000") == 0) {
                    break;  // Message end
                }
            }
        }
    }

    fclose(fp);
    printf("The hidden message is: %s\n", message);
}

void concealMessage(const char *inputFile, const char *message, const char *outputFile) {
    FILE *fp = fopen(inputFile, "rb");
    if (!fp) {
        printf("Alas! The image could not be found for concealment.\n");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, fp);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, fp);

    FILE *outFp = fopen(outputFile, "wb");
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outFp);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outFp);

    uint32_t width = bmpInfoHeader.width;
    uint32_t height = bmpInfoHeader.height;

    // Concatenate message and end marker in binary form
    char fullMessage[1024] = {0};
    snprintf(fullMessage, sizeof(fullMessage), "%s00000000", message); 

    int messageIndex = 0;

    for (int i = 0; i < width * height; i++) {
        uint8_t pixel[3];
        fread(pixel, sizeof(uint8_t), 3, fp);
        
        // LSB steganography: hide message in LSB of pixels
        for (int j = 0; j < 3; j++) {
            if (messageIndex < strlen(fullMessage)) {
                pixel[j] = (pixel[j] & ~1) | (fullMessage[messageIndex] - '0');
                messageIndex++;
            }
        }
        
        fwrite(pixel, sizeof(uint8_t), 3, outFp);
    }

    fclose(fp);
    fclose(outFp);
    printf("The message has been concealed within the image! Rejoice!\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <option> <image> <message/output_image>\n", argv[0]);
        printf("Option: -c (to conceal a message) or -u (to unveil a message)\n");
        return 1;
    }

    if (strcmp(argv[1], "-c") == 0) {
        concealMessage(argv[2], argv[3], "hidden_message.txt");
    } else if (strcmp(argv[1], "-u") == 0) {
        unveilMessage(argv[2], argv[3]);
    } else {
        printf("Noble soul, kindly choose a valid option!\n");
    }

    return 0;
}