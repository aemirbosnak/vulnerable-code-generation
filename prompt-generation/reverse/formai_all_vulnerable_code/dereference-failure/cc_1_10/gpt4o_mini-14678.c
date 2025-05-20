//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char header[54];
    unsigned int width;
    unsigned int height;
} BMP;
#pragma pack(pop)

void hideMessageInBMP(const char* bmpFile, const char* message) {
    FILE* file = fopen(bmpFile, "rb+");
    if (!file) {
        printf("Error: Could not open file %s.\n", bmpFile);
        return;
    }

    BMP bmp;
    fread(&bmp, sizeof(BMP), 1, file);

    // Calculate the start point of pixel data
    int pixelDataOffset = *(int*)&bmp.header[10];
    
    // Start hiding the message after the pixel data
    fseek(file, pixelDataOffset, SEEK_SET);

    // The message should fit into the available space in the image
    size_t messageLength = strlen(message);
    unsigned char character;

    // Loop through each pixel and embed message
    for (size_t i = 0; i < messageLength; i++) {
        fread(&character, sizeof(unsigned char), 1, file);
        character = (character & 0xFE) | ((message[i] >> 7) & 0x01); // Replace LSB with message bit
        fseek(file, -1, SEEK_CUR);
        fwrite(&character, sizeof(unsigned char), 1, file);
    }

    // Padding
    unsigned char endChar = 0; // end character
    fwrite(&endChar, sizeof(unsigned char), 1, file); // Add a byte for end of message
    
    fclose(file);
}

void extractMessageFromBMP(const char* bmpFile) {
    FILE* file = fopen(bmpFile, "rb");
    if (!file) {
        printf("Error: Could not open file %s.\n", bmpFile);
        return;
    }

    BMP bmp;
    fread(&bmp, sizeof(BMP), 1, file);

    // Calculate the start point of pixel data
    int pixelDataOffset = *(int*)&bmp.header[10];
    fseek(file, pixelDataOffset, SEEK_SET);

    unsigned char character;
    char message[256]; // Assume the message size doesn’t exceed 256 bytes
    size_t i = 0;

    while (1) {
        fread(&character, sizeof(unsigned char), 1, file);
        if (feof(file)) break; // End of file

        message[i] = 0; // clear character
        message[i] |= (character & 0x01) << 7; // get the first message bit

        // If we reach the end character, stop reading
        if (character == 0) break;
        i++;
    }

    message[i] = '\0'; // Null-terminate the string
    printf("Extracted Message: %s\n", message);

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <bmp file> <hide/extract> <message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[2], "hide") == 0) {
        hideMessageInBMP(argv[1], argv[3]);
        printf("Message hidden successfully in %s.\n", argv[1]);
    } else if (strcmp(argv[2], "extract") == 0) {
        extractMessageFromBMP(argv[1]);
    } else {
        printf("Error: Invalid operation. Use 'hide' or 'extract'.\n");
    }

    return 0;
}