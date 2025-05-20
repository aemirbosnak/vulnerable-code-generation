//Falcon2-11B DATASET v1.0 Category: QR code generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1000

void generateQRCode(char *data, int size) {
    int i, j;
    int code[8][8];

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            int temp = data[i * size + j] - '0';
            code[i][j] = (temp % 4) + 1;
        }
    }

    int maxValue = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (code[i][j] > maxValue) {
                maxValue = code[i][j];
            }
        }
    }

    char *res = malloc(sizeof(char) * 1000);
    int k = 0;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (code[i][j] == maxValue) {
                sprintf(res + k, "%d", maxValue);
                k++;
            } else {
                sprintf(res + k, "0");
                k++;
            }
        }
    }

    res[k] = '\0';
    printf("QR code generated: %s\n", res);
}

int main() {
    char *data = "Hello World";
    int size = strlen(data);
    generateQRCode(data, size);
    return 0;
}