//FormAI DATASET v1.0 Category: QR code reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_QR_SIZE 100

int main(int argc, char *argv[]) {
    printf("*************************\n");
    printf(" QR CODE READER (CYBERPUNK STYLE) \n");
    printf("*************************\n\n");

    char *qr_code = (char*) malloc(MAX_QR_SIZE * sizeof(char));
    if (qr_code == NULL) {
        printf("Error allocating memory: %s\n", strerror(errno));
        return errno;
    }

    printf("Please enter the QR code you wish to read: ");
    fgets(qr_code, MAX_QR_SIZE, stdin);

    // Removing newline character from input
    qr_code[strcspn(qr_code, "\n")] = 0;

    printf("Scanning QR code: %s...\n\n", qr_code);

    // Convert input to binary
    int binary[MAX_QR_SIZE];
    int i;
    for (i = 0; i < strlen(qr_code); ++i) {
        int curr_char = (int) qr_code[i];
        int j;
        for (j = 7; j >= 0; --j) {
            int curr_bit = (curr_char >> j) & 1;
            binary[8 * i + (7 - j)] = curr_bit;
        }
    }

    // Verify QR code using checksum
    int checksum = 0;
    int j;
    for (j = 0; j < 8; ++j) {
        checksum += binary[j];
    }
    int valid = 1;
    for (i = 8; i < strlen(qr_code) * 8; i += 8) {
        int curr_row_checksum = 0;
        for (j = 0; j < 8; ++j) {
            curr_row_checksum += binary[i + j];
        }
        if (curr_row_checksum != checksum) {
            valid = 0;
            break;
        }
    }

    if (valid) {
        printf("QR code is VALID.\n");
    } else {
        printf("QR code is INVALID.\n");
    }

    free(qr_code);
    return 0;
}