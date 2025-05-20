//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate QR code
void generateQRCode(char* input, int size) {
    int i, j, k, value, mask, pos = 0;
    char* output = (char*) malloc(size * size + 1);
    memset(output, '0', size * size);

    for (i = 0; i < strlen(input); i++) {
        value = input[i];
        if (value >= 48 && value <= 57) {
            value -= 48;
        } else if (value >= 65 && value <= 90) {
            value = value - 55;
        } else if (value >= 97 && value <= 122) {
            value = value - 87;
        } else {
            value = 0;
        }

        for (j = 0; j < 8; j++) {
            mask = 1 << (7 - j);
            if ((value & mask) == 0) {
                for (k = 0; k < size; k++) {
                    if ((k + i * size - j * 3) % size == pos) {
                        output[k + i * size - j * 3] = '1';
                    }
                }
            } else {
                for (k = 0; k < size; k++) {
                    if ((k + i * size - j * 3) % size == pos) {
                        output[k + i * size - j * 3] = '0';
                    }
                }
            }
            pos++;
        }
    }

    printf("QR Code:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%c", output[i * size + j]);
        }
        printf("\n");
    }

    free(output);
}

int main() {
    char input[100];
    int size;

    printf("Enter the text to be encoded: ");
    scanf("%s", input);

    printf("Enter the size of QR code (1-10): ");
    scanf("%d", &size);

    if (size < 1 || size > 10) {
        printf("Invalid size!\n");
        return 0;
    }

    generateQRCode(input, size);

    return 0;
}