//FormAI DATASET v1.0 Category: QR code generator ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

// Function to convert integer to binary
void toBinary(int num, int* binary, int len) {
    for(int i = len-1; i >= 0; i--) {
        binary[i] = num % 2;
        num /= 2;
    }
}

// Function to generate QR code
void generateQR(char* data) {
    int len = strlen(data);
    int* binary_len = (int*)malloc(14*sizeof(int)); // Length of data in binary
    int* binary_data = (int*)malloc((len+1)*8*sizeof(int)); // Data in binary
    
    // Get length of data in binary
    toBinary(len, binary_len, 14);
    
    // Get data in binary
    for(int i = 0; i < len; i++) {
        toBinary(data[i], &binary_data[i*8], 8);
    }
    
    // Add termination bits
    binary_data[len*8] = 0;
    binary_data[len*8 + 1] = 0;
    binary_data[len*8 + 2] = 0;
    binary_data[len*8 + 3] = 1;
    
    // Add padding to make length a multiple of 8
    int pad_len = (8 - ((len+1)*8 + 4) % 8) % 8;
    for(int i = 0; i < pad_len; i++) {
        binary_data[(len+1)*8 + i] = 0;
    }
    
    // Add padding length to binary_len
    toBinary(pad_len, &binary_len[11], 3);
    
    // Add mode to binary_len (8-bit binary value for QR code)
    binary_len[0] = 0;
    binary_len[1] = 1;
    binary_len[2] = 0;
    binary_len[3] = 0;
    binary_len[4] = 0;
    binary_len[5] = 1;
    binary_len[6] = 1;
    binary_len[7] = 1;
    
    // Generate QR code using binary values
    printf("QR Code for %s:\n", data);
    for(int i = 0; i < 41; i++) {
        for(int j = 0; j < 41; j++) {
            if(i == 0 || i == 40 || j == 0 || j == 40) {
                printf("█ ");
            } else if(i == 20 && j == 20) {
                printf("█ ");
            } else if(i == 6 && (j < 9 || j > 31)) {
                printf("  ");
            } else if(i == 34 && (j < 9 || j > 31)) {
                printf("  ");
            } else if(j == 6 && (i < 9 || i > 31)) {
                printf("  ");
            } else if(j == 34 && (i < 9 || i > 31)) {
                printf("  ");
            } else {
                int index = i*41 + j;
                if(index < 14) {
                    printf("%d ", binary_len[index]);
                } else {
                    printf("%d ", binary_data[index-14]);
                }
            }
        }
        printf("\n");
    }
}

// Driver code
int main() {
    char data[100];
    printf("Enter data to generate QR code: ");
    fgets(data, 100, stdin);
    data[strlen(data)-1] = '\0'; // Remove newline character
    
    generateQR(data);
    
    return 0;
}