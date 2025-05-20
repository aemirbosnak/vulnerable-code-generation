//FormAI DATASET v1.0 Category: QR code reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define QR code struct
typedef struct{
    uint32_t width;
    uint32_t height;
    char** data;
} QRCode;

// Function to free QR code memory
void freeQRCode(QRCode* code){
    for(int i = 0; i < code->height; i++){
        free(code->data[i]);
    }
    free(code->data);
}

// Function to read QR code from file
QRCode readQRCodeFromFile(char* filePath){
    FILE* file = fopen(filePath, "r");
    QRCode code;
    code.width = 0;
    code.height = 0;
    code.data = NULL;
    if(file != NULL){
        char* line = NULL;
        size_t len = 0;
        ssize_t read;
        int lineCount = 0;
        while((read = getline(&line, &len, file)) != -1){
            code.width = (code.width > read) ? code.width : read; // Set QR code width to length of longest line
            lineCount++;
            code.data = (char**)realloc(code.data, lineCount*sizeof(char*)); // Allocate memory for new line
            code.data[lineCount-1] = (char*)calloc(read+1, sizeof(char)); // Allocate space for line data
            strncpy(code.data[lineCount-1], line, read); // Copy line data into struct
        }
        code.height = lineCount;
        free(line);
        fclose(file);
    }else{
        printf("Could not open file: %s\n", filePath);
    }
    return code;
}

// Function to print QR code
void printQRCode(QRCode code){
    for(int i = 0; i < code.height; i++){
        printf("%s\n", code.data[i]);
    }
}

// Main function
int main(int argc, char** argv){
    if(argc != 2){
        printf("Usage: %s <QR code file path>\n", argv[0]);
        return 1;
    }
    QRCode code = readQRCodeFromFile(argv[1]);
    printf("QR code:\n");
    printQRCode(code);
    freeQRCode(&code);
    return 0;
}