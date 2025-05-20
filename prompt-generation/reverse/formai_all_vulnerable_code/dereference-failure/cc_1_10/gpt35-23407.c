//FormAI DATASET v1.0 Category: QR code reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to determine if given character is valid QR code character
int isQRCodeChar(char c) {
    return (isdigit(c) || isalpha(c) || c == '$' || c == '%' || c == '*' || c == '+' || c == '-' || c == '.' || c == '/' || c == ':' || c == '@');
}

// function to scan QR code from file and store in array
void scanQRCode(char *filename, char **qrCode) {
    FILE *fp = fopen(filename, "r");
    
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }
    
    char c;
    int row = 0;
    int col = 0;
    
    while ((c = getc(fp)) != EOF) {
        if (isQRCodeChar(c)) {
            qrCode[row][col] = c;
            col++;
        }
        else if (c == '\n') {
            row++;
            col = 0;
        }
        else {
            printf("Error: Invalid QR code character\n");
            exit(1);
        }
    }
    
    fclose(fp);
}

// function to print QR code stored in array
void printQRCode(char **qrCode, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", qrCode[i][j]);
        }
        printf("\n");
    }
}

// function to decode QR code and print result
void decodeQRCode(char **qrCode, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (qrCode[i][j] == '$') {
                printf("Amount: ");
                for (int k = j+1; k < size; k++) {
                    if (isdigit(qrCode[i][k])) {
                        printf("%c", qrCode[i][k]);
                    }
                    else if (qrCode[i][k] == '.') {
                        printf("%c", qrCode[i][k]);
                    }
                    else {
                        printf("\n");
                        break;
                    }
                }
            }
            else if (qrCode[i][j] == ':') {
                printf("Name: ");
                for (int k = j+1; k < size; k++) {
                    if (qrCode[i][k] == ':') {
                        printf("\n");
                        break;
                    }
                    else {
                        printf("%c", qrCode[i][k]);
                    }
                }
            }
            else if (qrCode[i][j] == '@') {
                printf("Email: ");
                for (int k = j+1; k < size; k++) {
                    if (qrCode[i][k] == '@') {
                        printf("\n");
                        break;
                    }
                    else {
                        printf("%c", qrCode[i][k]);
                    }
                }
            }
            else if (qrCode[i][j] == '+') {
                printf("Phone: ");
                for (int k = j+1; k < size; k++) {
                    if (isdigit(qrCode[i][k])) {
                        printf("%c", qrCode[i][k]);
                    }
                    else if (qrCode[i][k] == '-') {
                        printf("%c", qrCode[i][k]);
                    }
                    else {
                        printf("\n");
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    char *filename = "qrcode.txt";
    int size = 21;
    
    // allocate memory for 2D array to store QR code
    char **qrCode;
    qrCode = (char**)malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        qrCode[i] = (char*)malloc(size * sizeof(char));
    }
    
    scanQRCode(filename, qrCode);
    printf("QR Code:\n");
    printQRCode(qrCode, size);
    printf("\n");
    printf("Decoded Information:\n");
    decodeQRCode(qrCode, size);
    
    // free memory allocated to 2D array
    for (int i = 0; i < size; i++) {
        free(qrCode[i]);
    }
    free(qrCode);
    
    return 0;
}