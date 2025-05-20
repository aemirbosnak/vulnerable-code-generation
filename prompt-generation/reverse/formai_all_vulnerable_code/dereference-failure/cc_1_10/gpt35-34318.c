//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Define the size of the watermark
#define WATERMARK_SIZE 16

// Define macro to get bit value
#define TEST_BIT(number, position) ((number >> position) & 1)

// This function will add the watermark in the message
void addWatermark(uint8_t *msg, uint8_t *watermark) {

    // Get the length of the message
    uint32_t msgLength = strlen((char*)msg);

    // Convert the message length to 4 bytes
    uint8_t msgLengthBytes[4];
    msgLengthBytes[0] = (msgLength >> 24) & 0xFF;
    msgLengthBytes[1] = (msgLength >> 16) & 0xFF;
    msgLengthBytes[2] = (msgLength >> 8) & 0xFF;
    msgLengthBytes[3] = msgLength & 0xFF;

    // Add the watermark size, message length and watermark to the front of the message
    for (int i = WATERMARK_SIZE - 1; i >= 0; i--) {
        msg[i] = watermark[i];
    }
    for (int i = 0; i < 4; i++) {
        msg[WATERMARK_SIZE + i] = msgLengthBytes[i];
    }
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        msg[WATERMARK_SIZE + 4 + i] = watermark[i];
    }

}

// This function will extract the watermark from the message
void extractWatermark(uint8_t *msg, uint8_t *watermark) {

    // Get the message length from the first 4 bytes of the message
    uint32_t msgLength = 0;
    uint8_t *msgLengthBytes = (uint8_t*)&msg[WATERMARK_SIZE];

    msgLength |= (msgLengthBytes[0] << 24);
    msgLength |= (msgLengthBytes[1] << 16);
    msgLength |= (msgLengthBytes[2] << 8);
    msgLength |= msgLengthBytes[3];

    // Copy the watermark from the end of the message
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        watermark[i] = msg[(msgLength + WATERMARK_SIZE + 4) - WATERMARK_SIZE + i];
    }

}

int main() {

    // Define the message and watermark
    uint8_t msg[] = "This is a secret message.";
    uint8_t watermark[] = {0xA1, 0xB2, 0xC3, 0xD4, 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0, 0xFE, 0xDC, 0xBA, 0x98};
    uint8_t extractedWatermark[WATERMARK_SIZE];

    // Add the watermark to the message
    addWatermark(msg, watermark);

    // Extract the watermark from the message
    extractWatermark(msg, extractedWatermark);

    // Print the original message, the augmented message, and the extracted watermark
    printf("Original message: %s\n", msg + WATERMARK_SIZE + 4);
    printf("Augmented message: %s\n", msg);
    printf("Extracted watermark: ");
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        printf("%02X ", extractedWatermark[i]);
    }
    printf("\n");

    return 0;
}