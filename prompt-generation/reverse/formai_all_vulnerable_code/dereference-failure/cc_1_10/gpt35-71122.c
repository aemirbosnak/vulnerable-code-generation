//FormAI DATASET v1.0 Category: Image Steganography ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024
#define INFO_SIZE 256

// Function to convert decimal to binary
char* decToBin(int decimal){
    char *binary = (char*)malloc(8*sizeof(char));
    int i, j;
    for(i=7; i>=0; i--){
        j = decimal % 2;
        decimal = decimal / 2;
        binary[i] = j + '0';
    }
    return binary;
}

// Function to convert binary to decimal
int binToDec(char *binary){
    int decimal = 0;
    int i;
    for(i=0; i<8; i++){
        decimal = decimal*2 + binary[i]-'0';
    }
    return decimal;
}

// Function to embed message in image
void embedMessage(char *image, char *message){
    int imgSize = strlen(image);
    int msgSize = strlen(message);
    if(msgSize > (imgSize/8) - INFO_SIZE){
        printf("Message too long to be embedded in image!");
        return;
    }
    char *msgSizeBin = decToBin(msgSize);
    int i, j;
    // Embed message size in first INFO_SIZE bytes
    for(i=0; i<INFO_SIZE; i++){
        char *imgBinary = decToBin(image[i]);
        imgBinary[7] = msgSizeBin[i];
        image[i] = binToDec(imgBinary);
    }
    // Embed message in remaining image
    j = 0;
    for(i=INFO_SIZE; j<msgSize; i+=8){
        char *imgBinary = decToBin(image[i]);
        int k;
        for(k=0; k<8; k++){
            if(j==msgSize){
                break;
            }
            imgBinary[k] = message[j];
            j++;
        }
        image[i] = binToDec(imgBinary);
    }
}

// Function to extract message from image
void extractMessage(char *image){
    int imgSize = strlen(image);
    char *msgSizeBin = (char*)malloc(INFO_SIZE*sizeof(char));
    int i, j;
    // Extract message size from INFO_SIZE bytes
    for(i=0; i<INFO_SIZE; i++){
        char *imgBinary = decToBin(image[i]);
        msgSizeBin[i] = imgBinary[7];
    }
    int msgSize = binToDec(msgSizeBin);
    printf("Message size: %d\n", msgSize);
    char *message = (char*)malloc((msgSize+1)*sizeof(char));
    message[msgSize] = '\0';
    // Extract message from remaining image
    j = 0;
    for(i=INFO_SIZE; j<msgSize; i+=8){
        char *imgBinary = decToBin(image[i]);
        int k;
        for(k=0; k<8; k++){
            if(j==msgSize){
                break;
            }
            message[j] = imgBinary[k];
            j++;
        }
    }
    printf("Message: %s\n", message);
}

int main(){
    char *image = (char*)malloc(MAX_SIZE*sizeof(char));
    printf("Enter image (as string of decimal values): ");
    fgets(image, MAX_SIZE, stdin);
    // Remove newline character from image
    image[strcspn(image, "\n")] = '\0';

    char *message = (char*)malloc(MAX_SIZE*sizeof(char));
    printf("Enter message to be embedded: ");
    fgets(message, MAX_SIZE, stdin);
    // Remove newline character from message
    message[strcspn(message, "\n")] = '\0';

    printf("\nEmbedding message in image...\n\n");
    embedMessage(image, message);

    printf("Extracting message from image...\n\n");
    extractMessage(image);

    return 0;
}