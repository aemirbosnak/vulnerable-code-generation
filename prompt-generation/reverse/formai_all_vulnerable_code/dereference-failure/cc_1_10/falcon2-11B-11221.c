//Falcon2-11B DATASET v1.0 Category: QR code generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to generate QR code
void generate_qr_code(char* data, int size) {
    int i, j, k;
    char *str, *tmp;
    int count = 0;
    str = malloc(size);
    tmp = malloc(size);
    if (str == NULL || tmp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Convert data to binary
    for (i = 0; i < size; i++) {
        str[count] = (data[i] & 0x80)? '1' : '0';
        count++;
    }
    str[count] = '\0';

    // Create QR code matrix
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            tmp[count] = (str[count] == '1')? 'X' : '_';
            count++;
        }
        count = 0;
    }
    tmp[count] = '\0';

    // Print QR code matrix
    printf("QR Code Matrix:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%c", tmp[j]);
        }
        printf("\n");
    }
    printf("\n");

    free(str);
    free(tmp);
}

int main() {
    char data[] = "Hello World";
    int size = strlen(data);
    generate_qr_code(data, size);
    return 0;
}