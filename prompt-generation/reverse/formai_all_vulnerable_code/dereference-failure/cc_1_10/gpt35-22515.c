//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 10000 // Maximum size of the input string
#define MARK_SIZE 64 // Size of the digital watermark

char *embed_watermark(char *message, char *watermark);
int extract_watermark(char *stego_text, char *watermark);

/* Main function */
int main() {
    char message[MAX_SIZE]; // Input message
    char watermark[MARK_SIZE]; // Watermark to be embedded
    char stego_text[MAX_SIZE]; // Stego text with embedded watermark
    
    printf("Enter text message: ");
    fgets(message, MAX_SIZE, stdin);
    
    printf("Enter digital watermark (up to 64 characters): ");
    fgets(watermark, MARK_SIZE, stdin);
    
    char *stego_message = embed_watermark(message, watermark);
    printf("Stego message: %s\n", stego_message);
    
    int success = extract_watermark(stego_message, watermark);
    if (success) {
        printf("Watermark extracted successfully!\n");
    } else {
        printf("Failed to extract watermark.\n");
    }
    
    free(stego_message); // Free memory used for stego message
    
    return 0;
}

/* Function to embed digital watermark in message */
char *embed_watermark(char *message, char *watermark) {
    char *stego_text = (char *) malloc(sizeof(char) * MAX_SIZE);
    
    int len_message = strlen(message);
    int len_watermark = strlen(watermark) - 1; // Exclude newline character
    
    // Embed watermark in every 10th character of message
    for (int i = 0, j = 0; i < len_message; i++) {
        stego_text[i] = message[i];
        if (i % 10 == 0 && j < len_watermark) {
            stego_text[i] = watermark[j++];
        }
    }
    
    return stego_text;
}

/* Function to extract watermark from stego text */
int extract_watermark(char *stego_text, char *watermark) {
    int len_stego = strlen(stego_text);
    int len_watermark = strlen(watermark) - 1; // Exclude newline character
    int success = 0;
    
    // Extract watermark from every 10th character of stego text
    for (int i = 0, j = 0; i < len_stego; i++) {
        if (i % 10 == 0 && j < len_watermark) {
            if (stego_text[i] != watermark[j++]) {
                success = 0;
                break;
            } else {
                success = 1;
            }
        }
    }
    
    return success;
}