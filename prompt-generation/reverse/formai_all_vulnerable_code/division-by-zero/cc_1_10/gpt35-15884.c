//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LENGTH 256
#define MAX_WATERMARK_LENGTH 32

void error(char *msg) {
    fprintf(stderr, "%s", msg);
    exit(1);
}

int main() {
    char message[MAX_MSG_LENGTH];
    printf("Enter the message: ");
    fgets(message, MAX_MSG_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; // remove trailing newline
    
    char watermark[MAX_WATERMARK_LENGTH];
    printf("Enter the watermark: ");
    fgets(watermark, MAX_WATERMARK_LENGTH, stdin);
    watermark[strcspn(watermark, "\n")] = 0; // remove trailing newline
    
    int watermark_length = strlen(watermark);

    // Allocate memory for the watermarked message
    int watermarked_length = strlen(message) + watermark_length + 1; // +1 for null terminator
    char *watermarked = (char *) malloc(watermarked_length * sizeof(char));

    // Watermark the message
    int i;
    for (i = 0; i < strlen(message); i++) {
        watermarked[i] = message[i] ^ watermark[i % watermark_length];
    }
    watermarked[i] = '\0'; // null terminate the watermarked message

    // Print original message and watermarked message
    printf("Original message: %s\n", message);
    printf("Watermarked message: %s\n", watermarked);

    // Extract the watermark
    char extracted_watermark[MAX_WATERMARK_LENGTH];
    for (i = 0; i < strlen(message); i++) {
        extracted_watermark[i % watermark_length] = message[i] ^ watermarked[i];
    }
    extracted_watermark[i % watermark_length] = '\0'; // null terminate the extracted watermark

    // Check if extracted watermark matches original watermark
    if (strcmp(extracted_watermark, watermark) != 0) {
        error("Watermark extraction failed. The extracted watermark does not match the original watermark.");
    } else {
        printf("Watermark extraction successful. The extracted watermark matches the original watermark.\n");
    }

    // Free memory allocated for watermarked message
    free(watermarked);

    return 0;
}