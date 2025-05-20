//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;      // Magic number for file
    uint32_t bfSize;      // Size of the file in bytes
    uint16_t bfReserved1; // Reserved; must be zero
    uint16_t bfReserved2; // Reserved; must be zero
    uint32_t bfOffBits;   // Offset to start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;         // Size of this header
    int32_t  biWidth;        // Width of the image
    int32_t  biHeight;       // Height of the image
    uint16_t biPlanes;       // Number of color planes
    uint16_t biBitCount;     // Bits per pixel
    uint32_t biCompression;   // Type of compression
    uint32_t biSizeImage;    // Image size
    int32_t  biXPelsPerMeter; // X pixels per meter
    int32_t  biYPelsPerMeter; // Y pixels per meter
    uint32_t biClrUsed;      // Number of colors
    uint32_t biClrImportant;  // Important colors
} BITMAPINFOHEADER;
#pragma pack(pop)

void embed_message_in_image(const char *image_path, const char *message, const char *output_path) {
    FILE *image_file = fopen(image_path, "rb");
    FILE *output_file = fopen(output_path, "wb");
    if (!image_file || !output_file) {
        perror("File opening failed");
        return;
    }
    
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, image_file);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, image_file);
    
    int message_length = strlen(message);
    int total_bits = message_length * 8;

    // Ensure we have enough space in the image to embed the message
    if (total_bits > (bih.biWidth * bih.biHeight)) {
        printf("Message is too large to be embedded in the image.\n");
        fclose(image_file);
        fclose(output_file);
        return;
    }
    
    // Write the headers to the output file
    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, output_file);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, output_file);
    
    // Copy the pixel data and embed the message
    uint8_t pixel[3]; // For RGB (3 bytes for each pixel)
    for (int i = 0; i < bih.biWidth * bih.biHeight; i++) {
        fread(pixel, sizeof(uint8_t), 3, image_file);
        
        // Embed message bit by bit
        if (i < total_bits) {
            int bit = (message[i / 8] >> (7 - (i % 8))) & 1; // Get the bit from the message
            pixel[0] = (pixel[0] & 0xFE) | bit; // Modify the least significant bit of the blue channel
        }
        
        fwrite(pixel, sizeof(uint8_t), 3, output_file);
    }

    fclose(image_file);
    fclose(output_file);
    printf("Message embedded successfully in %s\n", output_path);
}

void extract_message_from_image(const char *image_path) {
    FILE *image_file = fopen(image_path, "rb");
    if (!image_file) {
        perror("File opening failed");
        return;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, image_file);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, image_file);

    // Prepare to extract the message
    char message[1024] = {0};  // Buffer for the extracted message
    int bit_index = 0;

    uint8_t pixel[3]; // For RGB (3 bytes for each pixel)
    for (int i = 0; i < bih.biWidth * bih.biHeight; i++) {
        fread(pixel, sizeof(uint8_t), 3, image_file);
        int bit = pixel[0] & 1; // Read the least significant bit of the blue channel
        message[bit_index / 8] |= (bit << (7 - (bit_index % 8))); // Store the bit
        bit_index++;
        
        // Stop reading if we reach a null character
        if (bit_index % 8 == 0 && message[bit_index / 8 - 1] == '\0') {
            break;
        }
    }

    fclose(image_file);
    printf("Extracted Message: %s\n", message);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <embed|extract> <image_path> <message|output_path>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embed_message_in_image(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extract_message_from_image(argv[2]);
    } else {
        printf("Invalid command. Use 'embed' or 'extract'.\n");
    }

    return 0;
}