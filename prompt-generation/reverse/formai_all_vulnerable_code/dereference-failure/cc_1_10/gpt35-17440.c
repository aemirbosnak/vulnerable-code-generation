//FormAI DATASET v1.0 Category: QR code reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QR_CODE_SIZE 144
#define MAX_FILE_SIZE 512

// Function to validate the QR code data
int isQRCodeValid(char *QRCode) {
    int i;
    if(strlen(QRCode) != MAX_QR_CODE_SIZE) {
        printf("Error: Invalid QR code size!");
        return 0;
    }
    for(i = 0; i < MAX_QR_CODE_SIZE; i++) {
        if(!isalnum(QRCode[i])) {
            printf("Error: Invalid character in QR code!");
            return 0;
        }
    }
    return 1;
}

// Function to read QR code from file
char* readQRCodeFromFile(char *fileName) {
    FILE *fp;
    char *QRCode = (char*)calloc(MAX_QR_CODE_SIZE+1, sizeof(char));
    int fileSize;
    
    fp = fopen(fileName, "r");
    if(fp == NULL) {
        printf("Error: Failed to open QR code file!");
        free(QRCode);
        return NULL;
    }
    
    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    if(fileSize > MAX_FILE_SIZE) {
        printf("Error: QR code file size exceeds maximum size!");
        free(QRCode);
        fclose(fp);
        return NULL;
    }
    
    fread(QRCode, sizeof(char), MAX_QR_CODE_SIZE, fp);
    
    fclose(fp);
    return QRCode;
}

// Function to decode QR code
void decodeQRCode(char *QRCode) {
    char *data = (char*)calloc(MAX_QR_CODE_SIZE/8+1, sizeof(char));
    int i;
    for(i = 0; i < MAX_QR_CODE_SIZE; i += 8) {
        sscanf(QRCode+i, "%8s", data+i/8);
    }
    printf("Decoded QR code: %s\n", data);
    free(data);
}

// Main function
int main() {
    char *fileName = "./qr_code.txt";
    char *QRCode = readQRCodeFromFile(fileName);
    
    if(QRCode == NULL) {
        return 0;
    }
    
    if(isQRCodeValid(QRCode)) {
        decodeQRCode(QRCode);
    }
    
    free(QRCode);
    return 0;
}