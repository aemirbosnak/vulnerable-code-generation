//FormAI DATASET v1.0 Category: Image Steganography ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
int* decimalToBinary(int decimalNum, int binaryNum[]) {
    int i = 0;
    while(decimalNum > 0) {
        binaryNum[i] = decimalNum % 2;
        decimalNum = decimalNum / 2;
        i++;
    }
    return binaryNum;
}

// Function to convert binary to decimal
int binaryToDecimal(int binaryNum[]) {
    int decimalNum = 0, i = 0, j = 1;
    for(i = 0; i < 8; i++) {
        decimalNum = decimalNum + (binaryNum[i] * j);
        j = j * 2;
    }
    return decimalNum;
}

int main() {
    FILE *img_in, *img_out;
    int pixel, i, k, j, decimal, n, bit_pos, bit_value;
    int binary[8], new_binary[8];
    char msg[] = "Hi there! I am a secret message.";
    int msg_length = strlen(msg);

    // Open input image file in read mode.
    img_in = fopen("input.bmp", "rb");
    if(img_in == NULL) {
        printf("Unable to open input image file.\n");
        exit(EXIT_FAILURE);
    }

    // Open output image file in write mode.
    img_out = fopen("output.bmp", "wb");
    if(img_out == NULL) {
        printf("Unable to create output image file.\n");
        exit(EXIT_FAILURE);
    }

    // Copy header
    for(i = 0; i < 54; i++) {
        fputc(fgetc(img_in), img_out);
    }

    // Embed secret message in LSB of pixel values
    pixel = fgetc(img_in);
    j = 0;
    while(pixel != EOF && j < msg_length) {
        decimal = pixel;
        decimalToBinary(decimal, binary);
        n = 0;
        while(n < 8) {
            bit_value = msg[j] & (1 << n);
            bit_pos = 7 - n;
            new_binary[bit_pos] = bit_value ? 1 : 0;
            n++;
        }
        for(k = 0; k < 8; k++) {
            binary[7-k] = new_binary[k];
        }
        decimal = binaryToDecimal(binary);
        fputc(decimal, img_out);
        pixel = fgetc(img_in);
        j++;
    }

    // Write remaining pixel values of the input image file
    while(pixel != EOF) {
        fputc(pixel, img_out);
        pixel = fgetc(img_in);
    }

    // Close input and output files
    fclose(img_in);
    fclose(img_out);

    printf("Secret message has been embedded in image successfully.\n");

    return 0;
}