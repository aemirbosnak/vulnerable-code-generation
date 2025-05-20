//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void convertHex(char *hexString) {
    int i, j, k, n, len;
    int dec = 0;
    char *binary;
    char *hex = (char *)malloc(strlen(hexString)*2);
    if (hex == NULL) {
        printf("Memory allocation error!\n");
        return;
    }
    for (i = 0; i < strlen(hexString); i++) {
        n = (int)hexString[i];
        if (isdigit(hexString[i])) {
            dec = dec*10 + (n - '0');
        } else {
            if (isupper(hexString[i])) {
                hex[i*2] = hexString[i] - 'A' + 10;
            } else {
                hex[i*2] = hexString[i] - 'a' + 10;
            }
        }
    }
    len = strlen(hex);
    binary = (char *)malloc((len+1)*3);
    if (binary == NULL) {
        printf("Memory allocation error!\n");
        free(hex);
        return;
    }
    for (j = 0; j < len; j += 2) {
        k = (int)hex[j];
        binary[k/16] = '1';
        binary[k%16] = '0';
    }
    for (j = len; j < len*2; j++) {
        k = (int)hex[j];
        binary[k/16] = '0';
        binary[k%16] = '1';
    }
    binary[len*2] = '\0';
    printf("Hex: %s\n", hex);
    printf("Binary: %s\n", binary);
    free(hex);
    free(binary);
}

int main() {
    char hexString[50] = "C0A8";
    convertHex(hexString);
    return 0;
}