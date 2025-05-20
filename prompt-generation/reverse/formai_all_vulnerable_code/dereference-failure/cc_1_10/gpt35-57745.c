//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100
#define MAX_WATERMARK_LENGTH 20

int binaryToDecimal(char *binary) {
    int n = 0;
    while (*binary) {
        n <<= 1;
        if (*binary++ == '1') n ^= 1;
    }
    return n;
}

char *decimalToBinary(int decimal) {
    char binary[MAX_WATERMARK_LENGTH];
    int i = 0;
    while (decimal > 0 || i < MAX_WATERMARK_LENGTH) {
        binary[i++] = (decimal & 1) ? '1' : '0';
        decimal >>= 1;
    }
    char *result = malloc(i + 1);
    memcpy(result, binary, i);
    result[i] = '\0';
    return result;
}

char *addWatermark(char *message, char *watermark) {
    char *watermarkedMessage = malloc(strlen(message) + strlen(watermark) + 1);
    int i;
    for (i = 0; i < strlen(watermark); i++) {
        int decimal = (int) watermark[i];
        char *binary = decimalToBinary(decimal);
        strcat(watermarkedMessage, binary);
    }
    strcat(watermarkedMessage, message);
    return watermarkedMessage;
}

char *retrieveWatermark(char *watermarkedMessage) {
    int watermarkLength = strlen(watermarkedMessage) % MAX_WATERMARK_LENGTH;
    char watermark[watermarkLength + 1];
    watermark[watermarkLength] = '\0';
    int i, j;
    for (i = 0; i < watermarkLength; i++) {
        for (j = i; j < strlen(watermarkedMessage); j += MAX_WATERMARK_LENGTH) {
            char binary[MAX_WATERMARK_LENGTH];
            strncpy(binary, &watermarkedMessage[j], MAX_WATERMARK_LENGTH);
            int decimal = binaryToDecimal(binary);
            watermark[i] = (char) decimal;
        }
    }
    char *result = malloc(strlen(watermark) + 1);
    strcpy(result, watermark);
    return result;
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter a message:\n");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    char watermark[MAX_WATERMARK_LENGTH];
    printf("Enter a watermark (up to %d characters):\n", MAX_WATERMARK_LENGTH);
    fgets(watermark, MAX_WATERMARK_LENGTH, stdin);
    char *watermarkedMessage = addWatermark(message, watermark);
    char *retrievedWatermark = retrieveWatermark(watermarkedMessage);
    printf("Original message:\n%s\n", message);
    printf("Watermark:\n%s\n", watermark);
    printf("Watermarked message:\n%s\n", watermarkedMessage);
    printf("Retrieved watermark:\n%s\n", retrievedWatermark);
    free(watermarkedMessage);
    free(retrievedWatermark);
    return 0;
}