//FormAI DATASET v1.0 Category: Image Steganography ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

// Function to convert decimal to binary
void decToBinary(int num, int *binArr, int n){
    // Converting decimal to binary
    for (int i = 0; i < n; i++) {
        binArr[i] = num % 2;
        num = num / 2;
    }
}

// Function to convert binary to decimal
int binaryToDecimal(int *binArr, int n){
    int decimal = 0;
    int base = 1;
    // Converting binary to decimal
    for (int i = 0; i < n; i++) {
        decimal += (binArr[i] * base);
        base = base * 2;
    }
    return decimal;
}

// Function to hide message in the image
void hideMessage(int *imgArr, int *msgArr, int n) {
    // Hiding message in the image
    for (int i = 0; i < n; i++) {
        int binArr[8] = {0};
        decToBinary(imgArr[i], binArr, 8);
        binArr[7] = msgArr[i];
        imgArr[i] = binaryToDecimal(binArr, 8);
    }
}

// Function to extract message from the image
void extractMessage(int *imgArr, int *msgArr, int n) {
    // Extracting message from the image
    for (int i = 0; i < n; i++) {
        int binArr[8] = {0};
        decToBinary(imgArr[i], binArr, 8);
        msgArr[i] = binArr[7];
    }
}

int main() {
    // Reading image file
    FILE *fptr = fopen("image.bmp", "rb");
    if (fptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Reading image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fptr);

    // Reading image data
    int *imgArr = (int*) malloc(MAX_FILE_SIZE);
    int i = 0;
    while (!feof(fptr)) {
        fread(&imgArr[i], sizeof(unsigned char), 1, fptr);
        i++;
    }
    int imgSize = i - 1; // Excluding EOF
    fclose(fptr);

    // Reading secret message from file
    FILE *mptr = fopen("message.txt", "r");
    if (mptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char msg[MAX_FILE_SIZE];
    fgets(msg, MAX_FILE_SIZE, mptr);
    int msgSize = strlen(msg);
    fclose(mptr);

    // Converting secret message to binary
    int *msgArr = (int*) malloc(msgSize);
    for (int i = 0; i < msgSize; i++) {
        int binArr[8] = {0};
        decToBinary(msg[i], binArr, 8);
        msgArr[i] = binArr[7];
    }

    // Pad message to match image size
    if (msgSize < imgSize) {
        int padSize = imgSize - msgSize;
        for (int i = 0; i < padSize; i++) {
            msgArr[msgSize + i] = 0;
        }
    } else if (msgSize > imgSize) {
        printf("Image file too small to hide message\n");
        exit(1);
    }

    // Hiding message in the image
    hideMessage(imgArr, msgArr, imgSize);

    // Saving modified image
    fptr = fopen("stego_image.bmp", "wb");
    if (fptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fwrite(header, sizeof(unsigned char), 54, fptr);
    for (int i = 0; i < imgSize; i++) {
        fwrite(&imgArr[i], sizeof(unsigned char), 1, fptr);
    }
    fclose(fptr);

    // Extracting message from the modified image
    fptr = fopen("stego_image.bmp", "rb");
    if (fptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fread(header, sizeof(unsigned char), 54, fptr);
    i = 0;
    while (! feof(fptr)) {
        fread(&imgArr[i], sizeof(unsigned char), 1, fptr);
        i++;
    }
    imgSize = i - 1;
    fclose(fptr);

    extractMessage(imgArr, msgArr, imgSize);

    // Converting extracted message from binary to character string
    char extractedMsg[MAX_FILE_SIZE];
    int j = 0;
    for (int i = 0; i < imgSize; i += 8) {
        int binArr[8] = {0};
        for (int k = 0; k < 8; k++) {
            binArr[k] = msgArr[i + k];
        }
        char c = (char) binaryToDecimal(binArr, 8);
        extractedMsg[j] = c;
        j++;
    }
    printf("Extracted Message: %s", extractedMsg);

    // Freeing dynamically allocated memory
    free(imgArr);
    free(msgArr);

    return 0;
}