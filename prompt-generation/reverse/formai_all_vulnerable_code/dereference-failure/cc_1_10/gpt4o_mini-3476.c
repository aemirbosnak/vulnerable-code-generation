//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void embedMessage(const char *inputImage, const char *outputImage, const char *message);
void extractMessage(const char *inputImage);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s [embed/extract] [imagefile] [message/outputfile]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        const char *inputImage = argv[2];
        const char *outputImage = argv[3];
        char message[256];

        printf("Enter message to embed: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = 0;  // Remove newline

        embedMessage(inputImage, outputImage, message);
    } 
    else if (strcmp(argv[1], "extract") == 0) {
        extractMessage(argv[2]);
    } 
    else {
        printf("Invalid option. Use 'embed' or 'extract'.\n");
    }

    return 0;
}

// Function to embed a message into an image
void embedMessage(const char *inputImage, const char *outputImage, const char *message) {
    FILE *inFile = fopen(inputImage, "rb");
    FILE *outFile = fopen(outputImage, "wb");
    if (!inFile || !outFile) {
        printf("Error: Could not open file.\n");
        return;
    }

    // Copy the image to the output file and embed the message in the last few bytes
    fseek(inFile, 0, SEEK_END);
    long imageSize = ftell(inFile);
    fseek(inFile, 0, SEEK_SET);
    
    unsigned char *imageData = (unsigned char *)malloc(imageSize);
    fread(imageData, 1, imageSize, inFile);

    // Prepare message to be embedded
    int messageLen = strlen(message);
    int i;
    for (i = 0; i < messageLen && i < imageSize - 1; i++) {
        imageData[imageSize - 1 - i] = (imageData[imageSize - 1 - i] & 0xFE) | ((message[i] >> 7) & 1); // LSB
        imageData[imageSize - 1 - i - 1] = (imageData[imageSize - 1 - i - 1] & 0xFE) | ((message[i] >> 6) & 1); // 2nd LSB
    }

    // Add a delimiter (using 0xF0 indicates end of message)
    imageData[imageSize - 1 - i] = 0xF0; 

    fwrite(imageData, 1, imageSize, outFile);

    free(imageData);
    fclose(inFile);
    fclose(outFile);

    printf("Message embedded successfully into %s\n", outputImage);
}

// Function to extract a message from an image
void extractMessage(const char *inputImage) {
    FILE *inFile = fopen(inputImage, "rb");
    if (!inFile) {
        printf("Error: Could not open file.\n");
        return;
    }

    // Navigate to the end and read the last bytes
    fseek(inFile, -1, SEEK_END);
    unsigned char byte;
    char message[256];
    int index = 0;

    while (fread(&byte, 1, 1, inFile)) {
        if ((byte & 0xF0) == 0xF0) {
            break; // End of message delimiter
        }
        message[index++] = (byte & 0x01) << 7; // Get the LSB
        fread(&byte, 1, 1, inFile);
        message[index-1] |= (byte & 0x01) << 6; // Get the 2nd LSB as well
        index++;
    }
    message[index] = '\0'; // Null-terminate the string

    printf("Extracted message: %s\n", message);

    fclose(inFile);
}