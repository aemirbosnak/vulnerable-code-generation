//FormAI DATASET v1.0 Category: QR code generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char **argv) {
    QRcode *code;
    unsigned char *data;
    int version, width;
    int i, j;

    if (argc < 2) {
        printf("Usage: %s [string to encode]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* encode the string into QR code */
    code = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    /* check if the encoding succeeded */
    if (code == NULL) {
        printf("Error: Failed to encode string.\n");
        exit(EXIT_FAILURE);
    }

    /* print the QR code to terminal */
    data = code->data;
    version = code->version;
    width = code->width;

    printf("\n");
    for (i = 0; i < width+4; i++) {
        printf("*");
    }
    printf("\n");
    for (i = 0; i < width; i++) {
        printf("**");
        for (j = 0; j < width; j++) {
            if (*data & 1) {
                printf("  ");
            } else {
                printf("* ");
            }
            data++;
        }
        printf("**\n");
    }
    for (i = 0; i < width+4; i++) {
        printf("*");
    }
    printf("\nVersion: %d\n", version);

    /* free memory */
    QRcode_free(code);

    return 0;
}