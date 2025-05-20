//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
char* decimal_to_binary(int n)
{
    char *binary = malloc(32 * sizeof(char)); // Allocate memory for the binary string
    int i = 0;
    while (n > 0) {
        binary[i] = n % 2 + '0'; // Convert remainder to char
        n = n / 2;
        i++;
    }
    binary[i] = '\0'; // Append null character
    // Reverse the binary string
    int len = strlen(binary);
    for (int j = 0; j < len / 2; j++) {
        char temp = binary[j];
        binary[j] = binary[len - 1 - j];
        binary[len - 1 - j] = temp;
    }
    return binary;
}

// Function to convert binary to decimal
int binary_to_decimal(char* binary)
{
    int decimal = 0;
    int len = strlen(binary);
    for (int i = 0; i < len; i++) {
        decimal = decimal * 2 + (binary[i] - '0');
    }
    return decimal;
}

int main()
{
    char message[100];
    printf("Enter the message to be watermarked: ");
    gets(message);
    int watermark = 12345;
    printf("Watermark: %d\n", watermark);
    
    // Convert watermark to binary and extract LSB
    char* binary = decimal_to_binary(watermark);
    char LSB = binary[strlen(binary) - 1];
    printf("LSB: %c\n", LSB);
    
    // Embed watermark in message
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        char c = message[i];
        if (i % 2 == 0) { // Modify even-positioned characters
            char* binary = decimal_to_binary(c);
            binary[strlen(binary) - 1] = LSB; // Replace LSB with watermark
            int decimal = binary_to_decimal(binary);
            message[i] = (char) decimal;
            free(binary);
        }
    }
    printf("Watermarked message: %s\n", message);
    
    // Extract watermark from watermarked message
    char* watermark_binary = malloc(16 * sizeof(char)); // Allocate memory for the watermark binary string
    int j = 0;
    for (int i = 0; i < len; i++) {
        char c = message[i];
        if (i % 2 == 0) { // Extract from even-positioned characters
            char* binary = decimal_to_binary(c);
            watermark_binary[j] = binary[strlen(binary) - 1];
            j++;
            free(binary);
        }
    }
    watermark_binary[j] = '\0'; // Append null character
    watermark = binary_to_decimal(watermark_binary);
    printf("Extracted watermark: %d\n", watermark);
    
    free(watermark_binary);
    free(binary);
    
    return 0;
}