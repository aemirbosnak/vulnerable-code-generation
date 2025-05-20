//FormAI DATASET v1.0 Category: QR code generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_SIZE 29 // size of the QR code
#define BLANK_CHAR ' ' // blank character
#define BLOCK_CHAR '#' // block character

/* Function to generate QR code */
void generateQR(char* input) {
    // initialize rows and columns
    int rows = QR_SIZE;
    int cols = QR_SIZE;
    
    // allocate memory for QR code
    char** qr_code = (char**) malloc(rows * sizeof(char*));
    for(int i = 0; i < rows; i++) {
        qr_code[i] = (char*) malloc(cols * sizeof(char));
    }
    
    // fill QR code with blank characters
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            qr_code[i][j] = BLANK_CHAR;
        }
    }
    
    // generate QR code pattern
    int len = strlen(input);
    int index = 0;
    for(int i = 0; i < QR_SIZE; i += 2) {
        for(int j = 1; j < QR_SIZE; j += 2) {
            if(index < len) {
                // get ASCII value of character
                int ascii_value = (int) input[index];
                
                // convert ASCII value to binary
                int binary[8], k = 0;
                while(ascii_value > 0) {
                    binary[k] = ascii_value % 2;
                    ascii_value /= 2;
                    k++;
                }
                for(int l = k - 1; l >= 0; l--) {
                    // assign block character if binary digit is 1
                    if(binary[l] == 1) {
                        qr_code[i][j] = BLOCK_CHAR;
                    }
                    j--;
                }
                index++;
            }
        }
        if(i % 4 == 0) {
            // leave border blank
            i++;
        }
    }
    
    // print QR code
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%c", qr_code[i][j]);
        }
        printf("\n");
    }
    
    // free memory
    for(int i = 0; i < rows; i++) {
        free(qr_code[i]);
    }
    free(qr_code);
}

int main() {
    char* input = "Hello World!";
    generateQR(input);
    return 0;
}