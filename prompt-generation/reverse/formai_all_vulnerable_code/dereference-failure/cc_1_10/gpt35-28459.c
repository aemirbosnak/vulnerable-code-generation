//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000
#define MAX_WATERMARK_LEN 100

char *embed_watermark(char *message, const char *watermark);
char *extract_watermark(char *message);

int main() {
    char message[MAX_STR_LEN], watermark[MAX_WATERMARK_LEN], choice;
    do {
        printf("Enter the message to be watermarked: ");
        fgets(message, MAX_STR_LEN, stdin);
        printf("Enter the watermark: ");
        fgets(watermark, MAX_WATERMARK_LEN, stdin);

        char *watermarked_message = embed_watermark(message, watermark);
        printf("\nWatermarked message: %s", watermarked_message);

        char *extracted_watermark = extract_watermark(watermarked_message);
        printf("\nExtracted watermark: %s", extracted_watermark);

        printf("\n\nDo you want to continue? (y/n): ");
        scanf("%c", &choice);
        getchar();
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

char *embed_watermark(char *message, const char *watermark) {
    char *watermarked_message = (char *)malloc(strlen(message) + strlen(watermark) + 1);
    int len = strlen(watermark);

    // Embedding watermark at the beginning of the message
    strcpy(watermarked_message, watermark);
    strcat(watermarked_message, message);

    // Applying the watermark on each character of the message
    for (int i = len; i < strlen(watermarked_message); i++) {
        watermarked_message[i] = (char)(watermarked_message[i] ^ watermark[i % len]);
    }

    return watermarked_message;
}

char *extract_watermark(char *message) {
    char *watermark = (char *)malloc(MAX_WATERMARK_LEN);
    int len = strlen(watermark);

    // Retrieving watermark from the first few characters of the message
    strncpy(watermark, message, len);

    // Removing watermark from the message
    for (int i = len; i < strlen(message); i++) {
        message[i] = (char)(message[i] ^ watermark[i % len]);
    }
    memmove(message, message + len, strlen(message) - len + 1);

    return watermark;
}