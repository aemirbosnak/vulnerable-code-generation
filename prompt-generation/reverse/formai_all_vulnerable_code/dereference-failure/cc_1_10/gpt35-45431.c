//FormAI DATASET v1.0 Category: Image Steganography ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int n, int binaryNum[])
{
    // Counter for binary array
    int i = 0;
    while (n > 0) {
        // Storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
}

// Function to convert binary to decimal
int binaryToDecimal(int binary)
{
    int decimal = 0;
    int base = 1;
    while (binary > 0) {
        int lastDigit = binary % 10;
        binary = binary / 10;
        decimal += lastDigit * base;
        base = base * 2;
    }
    return decimal;
}

int main()
{
    // Step 1: Open the input image file
    FILE* fp = fopen("input.bmp", "rb");

    // Step 2: Open the output image file
    FILE* op = fopen("output.bmp", "wb");

    // Step 3: Find the file size of the input image
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Step 4: Allocate memory to store the image data
    unsigned char* data = (unsigned char*)malloc(size);

    // Step 5: Read the image data into the memory buffer
    fread(data, size, 1, fp);

    // Step 6: Convert the message into binary
    char message[] = "Hello World!";
    int binaryMessage[100];
    int i, j = 0;
    for (i = 0; message[i] != '\0'; i++) {
        decimalToBinary(message[i], &binaryMessage[j]);
        j += 8;
    }

    // Step 7: Embed the binary message into the image data
    int dataIndex = 0;
    for (i = 0; i < j; i += 3) {
        int pixel = data[dataIndex];
        int binaryPixel[8];
        decimalToBinary(pixel, &binaryPixel[0]);
        binaryPixel[7] = binaryMessage[i];
        binaryPixel[6] = binaryMessage[i + 1];
        binaryPixel[5] = binaryMessage[i + 2];
        int embeddedPixel = 0;
        int base = 1;
        for (int k = 7; k >= 0; k--) {
            embeddedPixel += binaryPixel[k] * base;
            base = base * 2;
        }
        data[dataIndex] = embeddedPixel;
        dataIndex++;
    }

    // Step 8: Write the modified image data to the output file
    fwrite(data, size, 1, op);

    // Step 9: Close the input and output files
    fclose(fp);
    fclose(op);

    // Step 10: Display success message
    printf("Message embedded successfully!");
    return 0;
}