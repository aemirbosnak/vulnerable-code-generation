//FormAI DATASET v1.0 Category: QR code generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

/* generate a QR code and return it as a string */
char *generate_qr_code(char *data) {
    QRcode *code = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1); // use libqrencode to generate QR code
    if (!code) {
        fprintf(stderr, "Failed to generate QR code.\n");
        return NULL;
    }

    // create a buffer to hold the QR code image
    int size = code->width;
    int bufsize = (size + 1) * size + 1;
    char *buffer = (char *)malloc(bufsize);
    memset(buffer, ' ', bufsize);

    // iterate over each row of the QR code and store it in the buffer
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int i = y * (size + 1) + x;
            buffer[i] = code->data[y * size + x] ? '#' : ' ';
        }
        buffer[(y + 1) * (size + 1) - 1] = '\n';
    }
    buffer[bufsize - 1] = '\0';

    QRcode_free(code); // free memory used by QRcode

    return buffer;
}

int main() {
    char data[1024], *code;

    printf("Enter data to encode in QR code: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0'; // remove newline character

    code = generate_qr_code(data);
    if (!code) {
        fprintf(stderr, "Failed to generate QR code.\n");
        return 1;
    }

    printf("QR code for \"%s\":\n\n%s", data, code);

    free(code); // free memory used by QR code string

    return 0;
}