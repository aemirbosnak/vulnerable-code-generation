//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MSG_SIZE 100
#define MAX_WATERMARK_SIZE 20

/* Function to add digital watermark to message */
void addWatermark(char *msg, char *watermark) {
    int msgLen = strlen(msg);
    int wmLen = strlen(watermark);

    /* Generate a random position in message to insert watermark */
    int pos = rand() % (msgLen - wmLen);

    /* Insert watermark at the generated position */
    for (int i = 0; i < wmLen; i++) {
        msg[pos + i] = watermark[i];
    }
}

/* Function to check if digital watermark is present in message */
int checkWatermark(char *msg, char *watermark) {
    int msgLen = strlen(msg);
    int wmLen = strlen(watermark);

    /* Iterate over each position in message */
    for (int i = 0; i < msgLen - wmLen; i++) {
        /* Check if the current position and the next wmLen characters
         * match the watermark */
        if (strncmp(msg + i, watermark, wmLen) == 0) {
            return 1;   // Watermark found
        }
    }
    return 0;   // Watermark not found
}

int main() {
    char message[MAX_MSG_SIZE];
    char watermark[MAX_WATERMARK_SIZE];

    /* Get message and watermark from user */
    printf("Enter message: ");
    fgets(message, MAX_MSG_SIZE, stdin);

    printf("Enter watermark: ");
    fgets(watermark, MAX_WATERMARK_SIZE, stdin);

    /* Remove newline character from message and watermark */
    message[strcspn(message, "\n")] = 0;
    watermark[strcspn(watermark, "\n")] = 0;

    /* Seed random number generator */
    srand(time(0));

    /* Add watermark to message */
    addWatermark(message, watermark);

    /* Print message with watermark */
    printf("\nMessage with watermark: %s\n", message);

    /* Check if watermark is present in message */
    printf("Checking if watermark is present in message...\n");
    if (checkWatermark(message, watermark)) {
        printf("%s found in message\n", watermark);
    } else {
        printf("%s not found in message\n", watermark);
    }

    return 0;
}