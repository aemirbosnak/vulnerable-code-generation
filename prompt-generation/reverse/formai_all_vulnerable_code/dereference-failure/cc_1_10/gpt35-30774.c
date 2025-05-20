//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert decimal to binary
void decimalToBinary(int n, int* binary) {
    int i = 0;
    while (n > 0) {
        binary[i++] = n % 2;
        n = n / 2;
    }
}

// Function to convert binary to decimal
int binaryToDecimal(int* binary, int size) {
    int decimal = 0;
    for (int i = 0; i < size; i++) {
        decimal += binary[i] * pow(2, i);
    }
    return decimal;
}

// Function to encrypt the message and insert the watermark
void encryptAndInsertWatermark(int* message, int messageSize, int watermark, int* output, int* outputSize) {
    int binaryWatermark[16] = {0};
    decimalToBinary(watermark, binaryWatermark); // Convert watermark to binary

    int j = 0;
    for (int i = 0; i < messageSize; i++) {
        // Shift the bits of the message to the left and insert the watermark bit by bit
        int k = 0;
        while (k < 8) {
            output[j++] = (message[i] << 1) | binaryWatermark[k++];
        }
    }
    *outputSize = j;
}

// Function to extract the watermark from the encrypted message
int extractWatermark(int* encryptedMessage, int encryptedMessageSize) {
    int binaryWatermark[16] = {0};

    int j = 0;
    for (int i = 0; i < encryptedMessageSize; i++) {
        // Extract the least significant bit from each byte of the encrypted message
        binaryWatermark[j++] = encryptedMessage[i] & 1;
        if (j == 16) {
            break;
        }
    }

    return binaryToDecimal(binaryWatermark, 16); // Convert binary watermark to decimal
}

int main() {
    int message[] = {65, 67, 69}; // Message to be encrypted
    int messageSize = sizeof(message) / sizeof(message[0]);
    int* encryptedMessage = (int*)malloc(messageSize * sizeof(int)); // Encrypted message
    int encryptedMessageSize = 0;
    int watermark = 12345;

    encryptAndInsertWatermark(message, messageSize, watermark, encryptedMessage, &encryptedMessageSize); // Encrypt message and insert watermark

    printf("Encrypted message with watermark: ");
    for (int i = 0; i < encryptedMessageSize; i++) {
        printf("%d ", encryptedMessage[i]);
    }
    printf("\n");

    int extractedWatermark = extractWatermark(encryptedMessage, encryptedMessageSize); // Extract watermark from encrypted message

    printf("Extracted watermark: %d\n", extractedWatermark);

    free(encryptedMessage);

    return 0;
}