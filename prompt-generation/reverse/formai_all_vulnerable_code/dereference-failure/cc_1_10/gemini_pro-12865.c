//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

int main() {
    // Open the image file.
    FILE *imageFile = fopen("image.bmp", "rb+");
    if (imageFile == NULL) {
        printf("Error opening image file.\n");
        return 1;
    }

    // Get the file size.
    fseek(imageFile, 0, SEEK_END);
    long fileSize = ftell(imageFile);
    rewind(imageFile);

    // Read the image data into a buffer.
    byte *imageData = malloc(fileSize);
    if (imageData == NULL) {
        printf("Error allocating memory for image data.\n");
        return 1;
    }
    fread(imageData, 1, fileSize, imageFile);

    // Get the message to hide.
    char *message = "Hello, world!";

    // Convert the message to a sequence of bytes.
    int messageLength = strlen(message);
    byte *messageBytes = malloc(messageLength);
    if (messageBytes == NULL) {
        printf("Error allocating memory for message bytes.\n");
        return 1;
    }
    for (int i = 0; i < messageLength; i++) {
        messageBytes[i] = message[i];
    }

    // Hide the message in the image data.
    int messageIndex = 0;
    for (int i = 0; i < fileSize; i++) {
        // Get the least significant bit of the current byte.
        byte lsb = imageData[i] & 1;

        // Set the least significant bit to the next bit of the message.
        imageData[i] &= ~1;
        imageData[i] |= messageBytes[messageIndex] & 1;

        // Increment the message index.
        messageIndex++;

        // Check if we have reached the end of the message.
        if (messageIndex >= messageLength) {
            break;
        }
    }

    // Write the modified image data back to the file.
    fseek(imageFile, 0, SEEK_SET);
    fwrite(imageData, 1, fileSize, imageFile);

    // Close the image file.
    fclose(imageFile);

    // Free the allocated memory.
    free(imageData);
    free(messageBytes);

    return 0;
}