//FormAI DATASET v1.0 Category: Image Steganography ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<limits.h>

//Function to convert decimal to binary
void decToBinary(int n, int* binaryArr, int len) {
    for (int i = len-1; i >= 0; i--) {
        binaryArr[i] = n % 2;
        n = n / 2;
    }
}

//Function to convert binary to decimal
int binaryToDec(int* binaryArr, int len) {
    int val = 0;
    for (int i = 0; i < len; i++) {
        val += binaryArr[i] * pow(2, len-i-1);
    }
    return val;
}

//Function to hide message in the image
void encodeMessage(int* imageData, int imageSize, char* message, int messageSize) {
    //Converting message to binary
    int binaryMessageLen = messageSize * 8;
    int* binaryMessage = (int*)malloc(binaryMessageLen * sizeof(int));
    for (int i = 0; i < messageSize; i++) {
        decToBinary(message[i], binaryMessage+(i*8), 8);
    }
    
    //Check if message fits in image
    if (binaryMessageLen > imageSize) {
        printf("ERROR: Message size is greater than image size. Try with a bigger image!");
        free(binaryMessage);
        return;
    }
    
    //Hide message in image
    int idx = 0;
    for (int i = 0; i < binaryMessageLen; i++) {
        if (imageData[idx] % 2 != binaryMessage[i]) {
            if (imageData[idx] == 0) {
                imageData[idx] = 1;
            } else {
                imageData[idx] = 0;
            }
        }
        idx++;
        if (idx >= imageSize) {
            break;
        }
    }
    
    free(binaryMessage);
}

//Function to extract message from image
char* decodeMessage(int* imageData, int imageSize, int messageSize) {
    int* binaryMessage = (int*)malloc(messageSize * 8 * sizeof(int));
    int idx = 0;
    for (int i = 0; i < messageSize * 8; i++) {
        binaryMessage[i] = imageData[idx] % 2;
        idx++;
        if (idx >= imageSize) {
            break;
        }
    }
    char* message = (char*)malloc(messageSize + 1);
    message[messageSize] = '\0';
    for (int i = 0; i < messageSize; i++) {
        int c = binaryToDec(binaryMessage+(i*8), 8);
        message[i] = (char) c;
    }
    free(binaryMessage);
    return message;
}

//Driver function to test steganography
int main() {
    //Open image file
    FILE* fp = fopen("image.bin", "rb");
    if (fp == NULL) {
        printf("ERROR: Unable to open image file!");
        return 0;
    }
    
    //Get image size
    fseek(fp, 0, SEEK_END);
    int imageSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    //Allocate memory for image data
    int* imageData = (int*)malloc(imageSize * sizeof(int));
    
    //Read image data
    int idx = 0;
    int c = 0;
    while ((c = fgetc(fp)) != EOF) {
        imageData[idx] = c;
        idx++;
    }
    
    //Close image file
    fclose(fp);
    
    //Test encodeMessage and decodeMessage functions
    char* message = "Hello World!!!";
    printf("Original message: %s\n", message);
    encodeMessage(imageData, imageSize, message, strlen(message));
    char* decodedMessage = decodeMessage(imageData, imageSize, strlen(message));
    printf("Decoded message: %s\n", decodedMessage);
    
    //Free memory
    free(imageData);
    free(decodedMessage);
    
    return 0;
}