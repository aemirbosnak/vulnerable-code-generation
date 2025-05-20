//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 8 // constant block size for the watermarking algorithm

// function to convert a message to binary
void toBinary(char message[], char binary[]) {
    int len = strlen(message);
    // loop through each character in the message
    for(int i = 0; i < len; i++) {
        int ascii = (int) message[i];
        int index = i * 8; // index for storing binary bits
        // loop through each bit in the ASCII value
        for(int j = 0; j < 8; j++) {
            binary[index + j] = (ascii % 2) + '0'; // convert bit to char
            ascii /= 2;
        }
    }
}

// function to convert binary to a message
void toMessage(char binary[], char message[]) {
    int len = strlen(binary);
    int index = 0;
    // loop through each block of 8 bits
    for(int i = 0; i < len; i += BLOCK_SIZE) {
        int sum = 0;
        // loop through each bit in the block
        for(int j = 0; j < BLOCK_SIZE; j++) {
            if(binary[i + j] == '1') {
                sum += 1 << (BLOCK_SIZE - j - 1);
            }
        }
        message[index++] = (char) sum;
    }
    message[index] = '\0';
}

int main() {
    char original[100];
    char binary[800];
    char watermarked[100];
    char extracted[100];
    
    printf("Enter a message to watermark: ");
    fgets(original, 100, stdin);
    original[strcspn(original, "\n")] = 0; // remove newline character
    
    toBinary(original, binary); // convert message to binary
    
    printf("Enter a message to use as a watermark: ");
    fgets(watermarked, 100, stdin);
    watermarked[strcspn(watermarked, "\n")] = 0; // remove newline character
    
    toBinary(watermarked, binary + strlen(binary) - strlen(watermarked) * 8); // add watermark to end of binary
    
    printf("Watermarked binary: %s\n", binary);
    
    toMessage(binary, extracted); // extract message from binary
    
    printf("Extracted message: %s\n", extracted);
    
    return 0;
}