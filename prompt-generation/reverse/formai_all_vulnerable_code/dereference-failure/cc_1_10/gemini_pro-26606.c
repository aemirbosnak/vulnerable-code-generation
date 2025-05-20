//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Let's hide a funny secret message in an image!

    // First, let's load the image and the secret message.
    FILE *imageFile = fopen("image.bmp", "rb");
    if (imageFile == NULL) {
        printf("Oops, couldn't find your image file! Are you sure it's there?\n");
        return 1;
    }

    FILE *messageFile = fopen("message.txt", "r");
    if (messageFile == NULL) {
        printf("Hey, where's your secret message? I need something to hide!\n");
        return 1;
    }

    // Now, let's read the image into a buffer.
    fseek(imageFile, 0, SEEK_END);
    long imageSize = ftell(imageFile);
    rewind(imageFile);
    unsigned char *imageData = malloc(imageSize);
    fread(imageData, 1, imageSize, imageFile);

    // And let's read the secret message into a string.
    fseek(messageFile, 0, SEEK_END);
    long messageSize = ftell(messageFile);
    rewind(messageFile);
    char *message = malloc(messageSize + 1);
    fread(message, 1, messageSize, messageFile);

    // We can't just shove the message into the image, it'll look like a mess!
    // So, let's use a clever trick: we'll hide it in the least significant bits of the pixels.

    // We'll start by converting the secret message into a binary string.
    char *binaryMessage = malloc(messageSize * 8 + 1);
    for (int i = 0; i < messageSize; i++) {
        for (int j = 7; j >= 0; j--) {
            binaryMessage[i * 8 + j] = (message[i] >> j) & 1 ? '1' : '0';
        }
    }

    // Now, let's hide the binary message in the image.
    int messageIndex = 0;
    for (int i = 0; i < imageSize; i++) {
        if (messageIndex < messageSize * 8) {
            imageData[i] = (imageData[i] & 0b11111110) | (binaryMessage[messageIndex++] - '0');
        }
    }

    // We're done hiding the secret! Let's save the steganographed image.
    FILE *stegoImageFile = fopen("stego-image.bmp", "wb");
    fwrite(imageData, 1, imageSize, stegoImageFile);

    // Now, let's show off our secret-hiding skills!
    printf("Ta-da! Your secret message is now safely hidden in the image.\n");
    printf("To see the secret, just open the image in any image viewer and zoom in real close.\n");
    printf("You'll find your message blinking at you in the pixels!\n");

    // And we're all done! Let's clean up our mess.
    free(imageData);
    free(message);
    free(binaryMessage);
    fclose(imageFile);
    fclose(messageFile);
    fclose(stegoImageFile);

    return 0;
}