//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the message and the maximum length of the watermark
#define MAX_MSG_LENGTH 100
#define MAX_WATERMARK_LENGTH 20

// Function to embed the watermark in the message
void embed_watermark(char *message, char *watermark) {
    // Store the length of the message and the watermark
    int msg_len = strlen(message);
    int watermark_len = strlen(watermark);

    // Get the sum of the ASCII values of each character in the watermark
    int watermark_sum = 0;
    for (int i = 0; i < watermark_len; i++) {
        watermark_sum += (int)watermark[i];
    }

    // Calculate the average ASCII value of each character in the watermark
    int watermark_avg = watermark_sum / watermark_len;

    // Add the watermark as the last characters in the message
    for (int i = msg_len; i < msg_len + watermark_len; i++) {
        message[i] = watermark[i - msg_len];
    }

    // Add the average ASCII value of the watermark as the second last character in the message
    message[msg_len + watermark_len] = (char)watermark_avg;
}

// Function to check if the message has a valid watermark
int check_watermark(char *message, char *watermark) {
    // Store the length of the message and the watermark
    int msg_len = strlen(message);
    int watermark_len = strlen(watermark);

    // Get the average ASCII value of the watermark
    int watermark_avg = (int)message[msg_len - 1];

    // Calculate the sum of the ASCII values of each character in the extracted watermark
    int extracted_watermark_sum = 0;
    for (int i = msg_len - watermark_len - 1; i < msg_len - 1; i++) {
        extracted_watermark_sum += (int)message[i];
    }

    // Calculate the average of the ASCII values of each character in the extracted watermark
    int extracted_watermark_avg = extracted_watermark_sum / watermark_len;

    // Return 1 if the watermark is valid, otherwise return 0
    if (extracted_watermark_avg == watermark_avg) {
        return 1;
    } else {
        return 0;
    }
}

// Example usage of the watermarking functions
int main() {
    // Define the message and watermark strings
    char message[MAX_MSG_LENGTH];
    char watermark[MAX_WATERMARK_LENGTH];

    // Get the message and watermark input from the user
    printf("Enter the message to be watermarked (max length %d): ", MAX_MSG_LENGTH - MAX_WATERMARK_LENGTH - 2);
    fgets(message, MAX_MSG_LENGTH, stdin);

    printf("Enter the watermark to be embedded (max length %d): ", MAX_WATERMARK_LENGTH);
    fgets(watermark, MAX_WATERMARK_LENGTH, stdin);

    // Remove the newline characters from the input strings
    message[strcspn(message, "\n")] = 0;
    watermark[strcspn(watermark, "\n")] = 0;

    // Embed the watermark in the message
    embed_watermark(message, watermark);

    // Print the watermarked message
    printf("Watermarked message: %s\n", message);

    // Check if the message has a valid watermark
    int is_valid = check_watermark(message, watermark);

    // Print the result of the watermark check
    if (is_valid) {
        printf("Watermark is valid!\n");
    } else {
        printf("Watermark is not valid!\n");
    }
    
    return 0;
}