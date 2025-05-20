//FormAI DATASET v1.0 Category: QR code reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// maximum length of QR code string
#define MAX_QR_CODE_LENGTH 500

// function to read a single QR code from user input
void readQRCode(char *qrCode) {
    printf("Please enter a QR code: ");
    fgets(qrCode, MAX_QR_CODE_LENGTH, stdin);

    // remove newline character from end of string
    size_t length = strlen(qrCode);
    if (qrCode[length-1] == '\n') {
        qrCode[length-1] = '\0';
    }
}

// function to decode a QR code and check if it is valid
bool decodeQRCode(char *qrCode) {
    // check if QR code has the correct format
    if (strncmp(qrCode, "QRCODE:", 7) != 0) {
        return false;
    }

    // extract the C code from the QR code
    char *start = qrCode+7; // start after "QRCODE:"
    char *end = strstr(start, ";"); // find the first semicolon
    if (end == NULL) {
        return false;
    }
    size_t length = end-start;
    char cCode[length+1];
    strncpy(cCode, start, length);
    cCode[length] = '\0';
    
    // print the C code
    printf("C code: %s\n", cCode);
    
    // compile and run the C code
    printf("Output:\n");
    int result = system(cCode);
    return result == 0;
}

int main() {
    // create buffer to hold QR code string
    char qrCode[MAX_QR_CODE_LENGTH];
    
    // read and decode QR codes until user quits
    while (true) {
        readQRCode(qrCode);
        if (strcmp(qrCode, "quit") == 0) {
            break;
        }
        if (!decodeQRCode(qrCode)) {
            printf("Invalid QR code\n");
        }
    }
    
    return 0;
}