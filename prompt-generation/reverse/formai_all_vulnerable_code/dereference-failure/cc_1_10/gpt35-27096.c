//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the watermark message
char* getWatermarkMessage() {
    char* message = calloc(1024, sizeof(char));
    printf("Enter the message you want to watermark: ");
    scanf("%[^\n]%*c", message);
    return message;
}

// Function to generate random number between a and b
int getRandomNumber(int a, int b) {
    return a + rand() % (b - a + 1);
}

// Function to add watermark to the message
void addWatermark(char* message) {
    int messageLength = strlen(message);
    char watermark[] = "This is a digital watermark";

    int watermarkLength = strlen(watermark);
    int i, j;
    for (i = 0; i < messageLength; i++) {
        int r = getRandomNumber(0, 100);
        if (r < 10) {
            for (j = 0; j < watermarkLength; j++) {
                message[i + j] = watermark[j];
            }
            i = i + watermarkLength;
        }
    }
}

// Function to extract watermark from the message
void extractWatermark(char* message) {
    char watermark[] = "This is a digital watermark";
    int watermarkLength = strlen(watermark);
    int messageLength = strlen(message);
    int i, j;
    for (i = 0; i < messageLength; i++) {
        for (j = 0; j < watermarkLength; j++) {
            if (message[i + j] != watermark[j]) {
                break;
            }
        }
        if (j == watermarkLength) {
            printf("Watermark detected in the message.\n");
            return;
        }
    }
    printf("Watermark not detected in the message.\n");
}

int main() {
    char* message = getWatermarkMessage();
    addWatermark(message);
    printf("Watermarked message: %s\n", message);

    extractWatermark(message);

    free(message);
    return 0;
}