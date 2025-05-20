//FormAI DATASET v1.0 Category: Image Steganography ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

// function to convert decimal number to binary
void decToBinary(int num, int *binaryArray, int binarySize){
    for(int i=binarySize-1; i>=0; i--){
        binaryArray[i] = num % 2;
        num = num / 2;
    }
}

// function to convert binary number to decimal
int binaryToDec(int *binaryArray, int binarySize){
    int num = 0;
    for(int i=binarySize-1, j=0; i>=0; i--, j++){
        num = num + binaryArray[i] * pow(2, j);
    }
    return num;
}

// function to perform steganography
void performSteganography(char *inputString, char *message, char *outputString){
    // get length of input and message strings
    int inputLength = strlen(inputString);
    int messageLength = strlen(message);

    // calculate total number of bits required for steganography
    int bitsRequired = messageLength * 8;

    // check if input string is large enough to hold message
    if(bitsRequired > inputLength * 8){
        printf("Error: Input string too small to hold message!\n");
        return;
    }

    // convert message to binary
    int binaryMessage[bitsRequired];
    for(int i=0; i<messageLength; i++){
        decToBinary((int)message[i], &binaryMessage[i*8], 8);
    }

    // perform steganography
    int binaryInput[inputLength * 8];
    decToBinary((int)inputString[0], binaryInput, 8);
    for(int i=1; i<inputLength; i++){
        decToBinary((int)inputString[i], &binaryInput[i*8], 8);
    }
    int j=0;
    for(int i=0; i<bitsRequired; i++){
        binaryInput[i] = binaryInput[i] & ~1 | binaryMessage[j];
        j++;
    }

    // convert binary input back to string
    char outputArray[inputLength];
    for(int i=0; i<inputLength; i++){
        outputArray[i] = binaryToDec(&binaryInput[i*8], 8);
    }
    outputArray[inputLength] = '\0';

    strcpy(outputString, outputArray);
}

int main(){
    char inputString[1000];
    char message[1000];

    // get input string and message from user
    printf("Enter input string: ");
    fgets(inputString, sizeof(inputString), stdin);
    printf("Enter message to hide: ");
    fgets(message, sizeof(message), stdin);

    // remove newline characters from input and message strings
    inputString[strcspn(inputString, "\n")] = 0;
    message[strcspn(message, "\n")] = 0;

    char outputString[1000];
    performSteganography(inputString, message, outputString);

    printf("Input string: %s\n", inputString);
    printf("Message: %s\n", message);
    printf("Steganography output: %s\n", outputString);

    return 0;
}