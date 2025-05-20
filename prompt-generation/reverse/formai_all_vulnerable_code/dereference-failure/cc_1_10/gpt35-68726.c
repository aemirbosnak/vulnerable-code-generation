//FormAI DATASET v1.0 Category: Image Steganography ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Function to find the binary equivalent of a decimal number
int* decimalToBinary(int n) {
    int* binaryNum = (int*)malloc(8 * sizeof(int));
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    while (i < 8) {
        binaryNum[i] = 0;
        i++;
    }
    return binaryNum;
}

// Function to find the decimal equivalent of a binary number
int binaryToDecimal(int* binaryNum) {
    int decimalNum = 0;
    int power = 1;
    for (int i = 0; i < 8; i++) {
        decimalNum += binaryNum[i] * power;
        power *= 2;
    }
    return decimalNum;
}

void hideMessage(char* imageFileName, char* message) {
    FILE* imageFile = fopen(imageFileName, "rb");
    if (imageFile == NULL) {
        printf("Error opening image file.\n");
        return;
    }
    FILE* newImageFile = fopen("newimage.bmp", "wb");
    if (newImageFile == NULL) {
        printf("Error creating new image file.\n");
        return;
    }
    fseek(imageFile, 0L, SEEK_END);
    int fileSize = ftell(imageFile);
    rewind(imageFile);
    unsigned char* imageBuffer = (unsigned char*)malloc(fileSize);
    fread(imageBuffer, fileSize, 1, imageFile);
    int messageLength = strlen(message);
    if (messageLength > (fileSize - 54) * 8) {
        printf("Error: Message too long to hide in this image.\n");
        return;
    }
    int dataIndex = 54;
    for (int i = 0; i < messageLength; i++) {
        int* binaryChar = decimalToBinary((int)message[i]);
        for (int j = 0; j < 8; j++) {
            if (binaryChar[j] == 1) {
                if (imageBuffer[dataIndex] % 2 == 0) {
                    imageBuffer[dataIndex]++;
                }
            } else {
                if (imageBuffer[dataIndex] % 2 == 1) {
                    imageBuffer[dataIndex]--;
                }
            }
            dataIndex++;
        }
        free(binaryChar);
    }
    fwrite(imageBuffer, fileSize, 1, newImageFile);
    fclose(imageFile);
    fclose(newImageFile);
    printf("Message hidden in image.\n");
}

void findMessage(char* imageFileName) {
    FILE* imageFile = fopen(imageFileName, "rb");
    if (imageFile == NULL) {
        printf("Error opening image file.\n");
        return;
    }
    fseek(imageFile, 0L, SEEK_END);
    int fileSize = ftell(imageFile);
    rewind(imageFile);
    unsigned char* imageBuffer = (unsigned char*)malloc(fileSize);
    fread(imageBuffer, fileSize, 1, imageFile);
    int dataIndex = 54;
    int messageLength = 0;
    while (dataIndex < fileSize) {
        int* binaryChar = (int*)malloc(8 * sizeof(int));
        for (int i = 0; i < 8; i++) {
            binaryChar[i] = imageBuffer[dataIndex] % 2;
            dataIndex++;
        }
        int decimalChar = binaryToDecimal(binaryChar);
        if (decimalChar == 0) {
            break;
        }
        printf("%c", decimalChar);
        messageLength++;
        free(binaryChar);
    }
    if (messageLength == 0) {
        printf("No message found in image.\n");
    }
    fclose(imageFile);
}

int main() {
    char* imageFileName = "image.bmp";
    char* message = "Hello, world!";
    hideMessage(imageFileName, message);
    findMessage("newimage.bmp");
    return 0;
}