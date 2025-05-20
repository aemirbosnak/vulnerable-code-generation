//FormAI DATASET v1.0 Category: QR code reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 2048

void readQRCode(char *qrCode);
void parseQRString(char *qrString);

int main() {
    char qrCode[MAX_STR_LEN];

    printf("Please scan a QR code:\n");
    readQRCode(qrCode);

    parseQRString(qrCode);

    return 0;
}

void readQRCode(char *qrCode) {
    fgets(qrCode, MAX_STR_LEN, stdin);
    if(qrCode[strlen(qrCode) - 1] == '\n') {
        qrCode[strlen(qrCode) - 1] = '\0';
    }
}

void parseQRString(char *qrString) {
    int i, j;
    char key[MAX_STR_LEN], value[MAX_STR_LEN];
    int isKey = 1;
    int len = strlen(qrString);

    for(i = 0, j = 0; i < len; i++) {
        if(qrString[i] == '=') {
            isKey = 0;
            key[j] = '\0';
            j = 0;
        } else if(qrString[i] == '&') {
            isKey = 1;
            value[j] = '\0';
            j = 0;
            printf("%s=%s\n", key, value);
        } else {
            if(isKey) {
                key[j] = qrString[i];
                j++;
            } else {
                value[j] = qrString[i];
                j++;
            }
        }
    }
    value[j] = '\0';
    printf("%s=%s\n", key, value);
}