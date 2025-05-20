//FormAI DATASET v1.0 Category: QR code generator ; Style: Romeo and Juliet
// A QR Code Generator Program in Romeo and Juliet Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main() {
    char message[1000]; // Declare and initialize a character array to hold message to be encoded
    printf("O Romeo, Romeo, wherefore art thou Romeo?\n"); // Prompt to enter message
    fgets(message, 1000, stdin); // Read input from user and store in message

    QRcode *qr; // Declare a QRcode pointer variable
    QRinput *input; // Declare a QRinput pointer variable

    input = QRinput_new(); // Initialize the input variable

    QRinput_append(input, QR_MODE_8, strlen(message), message); // Append the message to input with 8-bit mode

    qr = QRcode_encodeInput(input); // Encode the input and store the result in qr

    // Print the QR code pattern
    printf("O, speak again, bright angel! for thou art\n");
    printf("As glorious to this night, being o'er my head\n");
    printf("As is a winged messenger of heaven\n");
    printf("Unto the white-upturned wondering eyes\n");
    printf("Of mortals that fall back to gaze on him\n");
    printf("When he bestrides the lazy-pacing clouds\n");
    printf("And sails upon the bosom of the air.\n");
    printf("\n");

    for (int i = 0; i < qr->width + 4; i++) {
        printf("\u2588"); // Print a black square block for the top left corner
    }

    printf("\n");

    for (int i = 0; i < qr->width; i++) {
        printf("\u2588\u2588"); // Print a black square block for the left edge of the QR code
        for (int j = 0; j < qr->width; j++) {
            if (qr->data[i*qr->width+j] & 1) {
                printf("  "); // Print two spaces for a black module
            } else {
                printf("\u2588\u2588"); // Print two black square blocks for a white module
            }
        }
        printf("\u2588\u2588\n"); // Print a black square block for the right edge of the QR code
    }

    for (int i = 0; i < qr->width + 4; i++) {
        printf("\u2588"); // Print a black square block for the bottom right corner
    }

    printf("\n");

    QRcode_free(qr); // Free the QRcode memory
    QRinput_free(input); // Free the QRinput memory

    return 0;
}