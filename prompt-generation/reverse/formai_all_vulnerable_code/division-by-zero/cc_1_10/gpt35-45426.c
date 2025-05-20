//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: creative
#include<stdio.h>
#include<string.h>

#define MAX_SIZE 1000

// Function to encode the watermark into the message
void encode_watermark(char *msg, char *watermark) {

    int msg_len = strlen(msg);
    int watermark_len = strlen(watermark);

    for(int i = 0; i < msg_len; i++) {
        msg[i] = msg[i] + watermark[i % watermark_len];
    }
}

// Function to decode the watermark from the message
void decode_watermark(char *msg, char *watermark) {

    int msg_len = strlen(msg);
    int watermark_len = strlen(watermark);

    for(int i = 0; i < msg_len; i++) {
        msg[i] = msg[i] - watermark[i % watermark_len];
    }
}

int main() {

    char msg[MAX_SIZE], watermark[MAX_SIZE];

    // Asking user for input message and watermark
    printf("Enter the message: ");
    fgets(msg, MAX_SIZE, stdin);

    printf("Enter the watermark: ");
    fgets(watermark, MAX_SIZE, stdin);

    // Removing the newline character from the strings
    strtok(msg, "\n");
    strtok(watermark, "\n");

    // Encoding the watermark into the message
    encode_watermark(msg, watermark);

    printf("\nMessage after adding watermark: %s\n", msg);

    // Decoding the watermark from the message
    decode_watermark(msg, watermark);

    printf("\nMessage after removing watermark: %s\n", msg);

    return 0;
}