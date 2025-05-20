//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000
#define KEY_SIZE 10

int main() {
    char message[MAX_SIZE];
    char key[KEY_SIZE];
    char message_copy[MAX_SIZE];
    char watermark[MAX_SIZE];
    int i, j, k;
    int watermark_size;

    // Get message from user
    printf("Enter message: ");
    fgets(message, MAX_SIZE, stdin);

    // Get key from user
    printf("Enter key: ");
    fgets(key, KEY_SIZE, stdin);

    // Remove newline character from key
    key[strcspn(key, "\n")] = '\0';

    // Calculate watermark size
    watermark_size = strlen(message) / strlen(key);

    // Calculate watermark
    for (i = 0, j = 0; i < strlen(message); i++, j++) {
        if (j == watermark_size) {
            j = 0;
        }
        watermark[i] = message[i] ^ key[j];
    }

    // Add watermark to message
    strcpy(message_copy, message);
    for (i = 0, j = 0; i < strlen(watermark); i++, j++) {
        if (j == watermark_size) {
            j = 0;
        }
        message_copy[i + j] ^= watermark[i];
    }

    // Print watermarked message
    printf("Watermarked message: %s\n", message_copy);

    return 0;
}