//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Function to convert an integer to binary string
char* intToBinaryString(int num) {
    char* binaryString = malloc(32*sizeof(char));
    if(binaryString == NULL) {
        printf("Memory allocation error!");
        exit(1);
    }
    for(int i=0; i<32; i++) {
        binaryString[i] = '0';
    }
    int index = 31;
    while(num > 0) {
        binaryString[index] = ((num%2) == 0) ? '0' : '1';
        num /= 2;
        index--;
    }
    return binaryString;
}

int main() {
    //Input image binary string
    char* image = "11010111100111001001011100011111";

    //Input watermark binary string
    char* watermark = "10011001";

    int watermarkBits = strlen(watermark);
    int imageBits = strlen(image);

    //Print the input image and watermark
    printf("Input Image: %s\n", image);
    printf("Input Watermark: %s\n", watermark);

    char* watermarkedImage = malloc((imageBits + watermarkBits)*sizeof(char));
    if(watermarkedImage == NULL) {
        printf("Memory allocation error!");
        exit(1);
    }

    int watermarkIndex = 0;
    for(int i=0, j=0; i<imageBits; i++, j++) {
        if(j >= watermarkBits) {
            watermarkIndex = 0;
        }
        //Extract the ith character from input image and jth character from watermark
        int imageVal = image[i] - '0';
        int watermarkVal = watermark[watermarkIndex] - '0';

        //If both are 1, set the corresponding bit in the watermarked image to 1
        if(imageVal == 1 && watermarkVal == 1) {
            watermarkedImage[j] = '1';
        } else {
            watermarkedImage[j] = image[i];
        }
        watermarkIndex++;
    }

    //Print the watermarked image
    printf("Watermarked Image: %s\n", watermarkedImage);

    //Convert the watermarked image to integer
    int watermarkedImageInt = strtol(watermarkedImage, NULL, 2);

    //Convert the watermarked image integer to its binary string
    char* watermarkedImageBinaryString = intToBinaryString(watermarkedImageInt);

    //Print the binary representation of the watermarked image integer
    printf("Watermarked Image Binary String: %s\n", watermarkedImageBinaryString);

    free(watermarkedImage);
    free(watermarkedImageBinaryString);

    return 0;
}