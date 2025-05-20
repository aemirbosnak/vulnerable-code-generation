//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BMP file header structure
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
    int biXPixPerMeter; 
    int biYPixPerMeter; 
    unsigned int biClrUsed; 
    unsigned int biClrImportant; 
} BITMAPINFOHEADER;
#pragma pack(pop)

// Function to hide a message within BMP image
void hideMessage(const char* bmpFileName, const char* message) {
    FILE *bmpFile = fopen(bmpFileName, "rb+");
    if (!bmpFile) {
        printf("Could not open file %s for reading and writing.\n", bmpFileName);
        return;
    }

    BITMAPFILEHEADER bmpFileHeader;
    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, bmpFile);
    
    BITMAPINFOHEADER bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, bmpFile);
    
    fseek(bmpFile, 0, SEEK_END);
    long size = ftell(bmpFile);
    
    // Move back to the end of the bitmap data
    long offset = bmpFileHeader.bfOffBits + bmpInfoHeader.biSizeImage;
    fseek(bmpFile, offset, SEEK_SET);
    
    // Storing the message length at the beginning
    int messageLen = strlen(message);
    fwrite(&messageLen, sizeof(int), 1, bmpFile);
    
    // Write the message
    fwrite(message, sizeof(char), messageLen, bmpFile);
    
    fclose(bmpFile);
    printf("Message hidden in %s successfully!\n", bmpFileName);
}

// Function to extract hidden message from BMP image
void extractMessage(const char* bmpFileName) {
    FILE *bmpFile = fopen(bmpFileName, "rb");
    if (!bmpFile) {
        printf("Could not open file %s for reading.\n", bmpFileName);
        return;
    }

    BITMAPFILEHEADER bmpFileHeader;
    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, bmpFile);
    
    BITMAPINFOHEADER bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, bmpFile);
    
    // Move to the point where the message is stored
    long offset = bmpFileHeader.bfOffBits + bmpInfoHeader.biSizeImage;
    fseek(bmpFile, offset, SEEK_SET);
    
    // Read the message length
    int messageLen;
    fread(&messageLen, sizeof(int), 1, bmpFile);
    
    // Allocate memory for the message
    char* message = (char*)malloc(messageLen + 1);
    fread(message, sizeof(char), messageLen, bmpFile);
    message[messageLen] = '\0'; // Null terminate the string
    
    printf("Extracted message: %s\n", message);
    
    free(message);
    fclose(bmpFile);
}

// Main function to drive the program
int main() {
    int choice;
    char bmpFileName[256];
    char message[256];

    printf("Welcome to the BMP Image Steganography Program!\n");
    printf("1. Hide a message in BMP image\n");
    printf("2. Extract message from BMP image\n");
    printf("Choose an option (1/2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Enter the BMP file name: ");
        scanf("%s", bmpFileName);
        printf("Enter the message to hide: ");
        scanf(" %[^\n]%*c", message); // Read string with spaces
        hideMessage(bmpFileName, message);
    } else if (choice == 2) {
        printf("Enter the BMP file name: ");
        scanf("%s", bmpFileName);
        extractMessage(bmpFileName);
    } else {
        printf("Invalid choice! Please run the program again.\n");
    }

    return 0;
}