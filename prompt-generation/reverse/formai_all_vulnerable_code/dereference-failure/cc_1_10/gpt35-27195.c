//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void embed(char* watermark, int* data, int length)
{
    int watermark_length = strlen(watermark);
    int position = 0;

    for(int i = 0; i < length; i++) {
        int bit = (int) watermark[position % watermark_length]; // Get the ASCII value of the next character in the watermark
        bit = bit & 1; // Take the last bit of the character to get either 0 or 1
        data[i] = (data[i] & ~1) | bit; // Replace the last bit of the data with the corresponding bit of the watermark
        position++;
    }
}

int extract(int* data, int length)
{
    char* watermark = (char*) malloc(sizeof(char) * length);
    int position = 0;

    for(int i = 0; i < length; i++) {
        int bit = data[i] & 1; // Extract the last bit of the data
        watermark[position] = (char) bit + '0'; // Convert the bit to a character ('0' or '1') and store in the watermark
        position++;

        if(position == 8) { // When we have a full byte (8 bits), convert it to a character and add to watermark
            watermark[position] = '\0'; // Null-terminate the string
            int watermark_char = strtol(watermark, NULL, 2); // Convert the binary string to an integer
            watermark[position - 1] = (char) watermark_char; // Add the character to the watermark
            position = 0; // Reset position for the next byte
        }
    }

    printf("Extracted watermark: %s\n", watermark);
    free(watermark);

    return 0;
}

int main()
{
    int data[] = {65, 66, 67, 68, 69}; // ASCII values for 'A' to 'E'
    char* watermark = "Watermark";

    printf("Embedding watermark...\n");
    embed(watermark, data, sizeof(data) / sizeof(int));
    printf("Watermark embedded successfully.\n\n");

    printf("Extracting watermark...\n");
    extract(data, sizeof(data) / sizeof(int));
    printf("Watermark extracted successfully.\n");

    return 0;
}