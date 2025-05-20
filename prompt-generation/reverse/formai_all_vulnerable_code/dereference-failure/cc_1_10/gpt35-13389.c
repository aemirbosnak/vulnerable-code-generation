//FormAI DATASET v1.0 Category: Image Steganography ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to convert decimal to binary
void decToBinary(int decimalNum, int binaryNum[])
{
    int index = 7; // 8 bits representation
    while(decimalNum > 0){
        binaryNum[index] = decimalNum % 2;
        decimalNum /= 2;
        index--;
    }

    // Fill remaining bits with 0s
    while(index >= 0){
        binaryNum[index] = 0;
        index--;
    }
}

// Function to hide message inside image
void hideMessageInImage(char *imageFile, char *secretMessage)
{
    FILE *fptr_image, *fptr_secretMsg;
    fptr_image = fopen(imageFile, "rb");
    fptr_secretMsg = fopen(secretMessage, "r");

    if(fptr_image == NULL || fptr_secretMsg == NULL){
        printf("Error: Could not open the files!");
        exit(1);
    }

    // Read the first 54 bytes (header) from the image
    unsigned char imageData[54];
    fread(imageData, 1, 54, fptr_image);

    // Read the secret message character by character
    char ch;
    int msgIndex = 0;
    int msgLength = strlen(secretMessage);
    while(msgIndex < msgLength){
        ch = fgetc(fptr_secretMsg);
        int binaryMsg[8];
        decToBinary((int)ch, binaryMsg);

        // Hide bit0 in blue pixel
        unsigned char byte0 = imageData[0] & 0xFE;
        byte0 = byte0 | binaryMsg[0];
        imageData[0] = byte0;

        // Hide bit0 in green pixel
        unsigned char byte1 = imageData[1] & 0xFE;
        byte1 = byte1 | binaryMsg[1];
        imageData[1] = byte1;

        // Hide bit0 in red pixel
        unsigned char byte2 = imageData[2] & 0xFE;
        byte2 = byte2 | binaryMsg[2];
        imageData[2] = byte2;

        // Hide bit1 in blue pixel
        byte0 = imageData[0] & 0xFD;
        byte0 = byte0 | binaryMsg[3];
        imageData[0] = byte0;

        // Hide bit1 in green pixel
        byte1 = imageData[1] & 0xFD;
        byte1 = byte1 | binaryMsg[4];
        imageData[1] = byte1;

        // Hide bit1 in red pixel
        byte2 = imageData[2] & 0xFD;
        byte2 = byte2 | binaryMsg[5];
        imageData[2] = byte2;

        // Hide bit2 in blue pixel
        byte0 = imageData[0] & 0xFB;
        byte0 = byte0 | binaryMsg[6];
        imageData[0] = byte0;

        // Hide bit2 in green pixel
        byte1 = imageData[1] & 0xFB;
        byte1 = byte1 | binaryMsg[7];
        imageData[1] = byte1;

        // Write modified pixel values to image
        fwrite(&imageData, 1, 3, fptr_image);
        msgIndex++;
    }

    // Close the files
    fclose(fptr_image);
    fclose(fptr_secretMsg);
}

// Function to extract message from image
void extractMessageFromImage(char *imageFile, char *outputFile)
{
    FILE *fptr_image = fopen(imageFile, "rb");
    FILE *fptr_output = fopen(outputFile, "w");

    if(fptr_image == NULL || fptr_output == NULL){
        printf("Error: Could not open the files!");
        exit(1);
    }

    // Skip header of the image
    fseek(fptr_image, 54, SEEK_SET);

    unsigned char imageData[3];
    char ch = 0;
    int binaryNum[8];
    int index = 0;
    while(1){
        fread(imageData, 1, 3, fptr_image);

        // Extract bits from blue pixel    
        binaryNum[0] = imageData[0] & 0x01;
        binaryNum[3] = imageData[0] & 0x02;
        binaryNum[6] = imageData[0] & 0x04;

        // Extract bits from green pixel 
        binaryNum[1] = imageData[1] & 0x01;
        binaryNum[4] = imageData[1] & 0x02;
        binaryNum[7] = imageData[1] & 0x04;

        // Extract bits from red pixel 
        binaryNum[2] = imageData[2] & 0x01;
        binaryNum[5] = imageData[2] & 0x02;

        // Convert extracted bits to decimal and then to character
        int decimalNum = 0;
        for(index = 0; index < 8; index++){
            decimalNum += binaryNum[index] * (int)(pow(2, index));
        }
        ch = (char)decimalNum;

        if(ch == '\0'){
            break;
        }

        // Write extracted character to output file
        fprintf(fptr_output, "%c", ch);
    }

    // Close the files
    fclose(fptr_image);
    fclose(fptr_output);
}

// Main function
int main()
{
    // Hide message inside image
    char *imageFile = "test_image.bmp"; // original image
    char *secretMessage = "secret_msg.txt";
    hideMessageInImage(imageFile, secretMessage);

    // Extract message from image
    char *outputFile = "recovered_msg.txt";
    extractMessageFromImage(imageFile, outputFile);

    printf("Steganography executed successfully!\n");
    return 0;
}