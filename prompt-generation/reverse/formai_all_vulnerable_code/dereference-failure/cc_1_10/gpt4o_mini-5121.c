//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)
typedef struct {
    unsigned short bfType;
    unsigned long  bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned long  bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned long  biSize;
    long           biWidth;
    long           biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned long  biCompression;
    unsigned long  biSizeImage;
    long           biXPelsPerMeter;
    long           biYPelsPerMeter;
    unsigned long  biClrUsed;
    unsigned long  biClrImportant;
} BITMAPINFOHEADER;

void hideMessageInBmp(const char* bmpFile, const char* message);
void retrieveMessageFromBmp(const char* bmpFile);

int main() {
    char bmpFile[100];
    int choice;

    printf("Image Steganography - BMP edition\n");
    printf("1. Hide a message in an image\n");
    printf("2. Retrieve a message from an image\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // clear newline character from buffer

    switch (choice) {
        case 1:
            printf("Enter the path of the BMP file: ");
            fgets(bmpFile, sizeof(bmpFile), stdin);
            bmpFile[strcspn(bmpFile, "\n")] = 0; // Remove newline
            
            printf("Enter the message to hide: ");
            char message[512];
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = 0; // Remove newline

            hideMessageInBmp(bmpFile, message);
            break;
        case 2:
            printf("Enter the path of the BMP file: ");
            fgets(bmpFile, sizeof(bmpFile), stdin);
            bmpFile[strcspn(bmpFile, "\n")] = 0; // Remove newline
            
            retrieveMessageFromBmp(bmpFile);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

void hideMessageInBmp(const char* bmpFile, const char* message) {
    FILE *inputFile = fopen(bmpFile, "rb+");
    if (!inputFile) {
        printf("Unable to open file %s\n", bmpFile);
        return;
    }

    BITMAPFILEHEADER bfHeader;
    BITMAPINFOHEADER biHeader;

    fread(&bfHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&biHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);

    fseek(inputFile, bfHeader.bfOffBits, SEEK_SET);
    
    // Check message length
    size_t messageLength = strlen(message);
    if (messageLength >= 256) {
        printf("Message too long! Maximum length is 255 characters.\n");
        fclose(inputFile);
        return;
    }

    // Append a delimiter at the end of the message
    char *secretMessage = (char*)malloc(messageLength + 2);
    strcpy(secretMessage, message);
    secretMessage[messageLength] = '\0'; // Null-terminator
    secretMessage[messageLength + 1] = '\0'; // Additional space for termination

    // Writing the message into the LSBs of the BMP
    unsigned char byte;
    for (size_t i = 0; i <= messageLength; i++) {
        fread(&byte, sizeof(unsigned char), 1, inputFile);
        byte = (byte & 0xFE) | ((secretMessage[i] >> 7) & 1); // LSB

        fseek(inputFile, -1, SEEK_CUR);
        fwrite(&byte, sizeof(unsigned char), 1, inputFile);
        fseek(inputFile, 0, SEEK_CUR);
        secretMessage[i] <<= 1; // Shift next bit for the next character
    }

    free(secretMessage);
    fclose(inputFile);
    printf("Message hidden in %s successfully!\n", bmpFile);
}

void retrieveMessageFromBmp(const char* bmpFile) {
    FILE *inputFile = fopen(bmpFile, "rb");
    if (!inputFile) {
        printf("Unable to open file %s\n", bmpFile);
        return;
    }

    BITMAPFILEHEADER bfHeader;
    BITMAPINFOHEADER biHeader;

    fread(&bfHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&biHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);

    fseek(inputFile, bfHeader.bfOffBits, SEEK_SET);

    char secretMessage[256];
    size_t length = 0;
    unsigned char byte;

    // Read LSBs until termination is found
    while (length < 255) {
        fread(&byte, sizeof(unsigned char), 1, inputFile);
        secretMessage[length] = (byte & 1) ? '?': 0; // 0 if not set, '?' indicates continuation
        if (byte == 0) break; // Stop on null byte
        secretMessage[length] = (char)((secretMessage[length] << 1) | (byte & 1));
        length++;
    }

    secretMessage[length] = '\0'; // Null-terminate the result
    fclose(inputFile);
    
    printf("Retrieved Message: %s\n", secretMessage);
}