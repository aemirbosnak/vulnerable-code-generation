//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1024

int main()
{
    char message[] = "You are my forever, my heart and soul.";
    int message_length = strlen(message);

    // Generate a random secret key
    int secret_key = rand() % MAX;

    // Watermark the message
    char watermarked_message[MAX];
    int watermarked_message_length = watermark(message, secret_key, watermarked_message);

    // Print the watermarked message
    printf("Watermarked message: ");
    for (int i = 0; i < watermarked_message_length; i++)
    {
        printf("%c ", watermarked_message[i]);
    }

    printf("\n");

    return 0;
}

int watermark(char *message, int secret_key, char *watermarked_message)
{
    int message_length = strlen(message);

    // Allocate memory for the watermarked message
    watermarked_message = (char *)malloc(message_length + 1);

    // Copy the original message into the watermarked message
    memcpy(watermarked_message, message, message_length);

    // Watermark the message
    for (int i = 0; i < message_length; i++)
    {
        watermarked_message[i] ^= secret_key;
    }

    // Add a terminator to the watermarked message
    watermarked_message[message_length] = '\0';

    // Return the length of the watermarked message
    return message_length + 1;
}