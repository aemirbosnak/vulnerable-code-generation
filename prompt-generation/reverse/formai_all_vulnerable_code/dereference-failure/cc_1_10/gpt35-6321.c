//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: artistic
#include <stdio.h>
#include <stdint.h>

/* Welcome to the C Checksum Calculator */
/* This program calculates the checksum of any given message */

/* The first step is to convert the message into binary */
/* This function takes a character array and returns a pointer to an integer array containing the binary values */
int* convertToBinary(char* message) {
    int* binaryMessage = (int*)malloc(strlen(message)*8*sizeof(int));
    int index = 0;
    for (int i = 0; i < strlen(message); i++) {
        int character = (int)(message[i]);
        for (int j = 7; j >= 0; j--) {
            int bitValue = (character >> j) & 1;
            binaryMessage[index] = bitValue;
            index++;
        }
    }
    return binaryMessage;
}

/* The second step is to calculate the checksum */
/* This function takes an integer array containing the binary message and the size of the message and returns the checksum */
uint16_t calculateChecksum(int* binaryMessage, int size) {
    uint16_t checksum = 0;
    for (int i = 0; i < size; i+=16) {
        uint16_t sum = 0;
        for (int j = 0; j < 16; j++) {
            sum += binaryMessage[i+j];
        }
        checksum += sum;
        if (checksum > 0xFFFF) {
            checksum = (checksum & 0xFFFF) + 1;
        }
    }
    return ~(checksum);
}

/* The third step is to print out the results */
/* This function takes the message, binary message, size of the message, and the checksum and prints out the results */
void printResults(char* message, int* binaryMessage, int size, uint16_t checksum) {
    printf("Message: %s\n", message);
    printf("Size of Message (bits): %d\n", size);
    printf("Binary Message: ");
    for (int i = 0; i < size; i++) {
        printf("%d", binaryMessage[i]);
    }
    printf("\n");
    printf("Checksum: 0x%04X\n", checksum);
}

/* Finally, the main function calls the other functions and runs the program */
int main() {
    char message[128];
    printf("Enter message: ");
    fgets(message, 128, stdin);
    int* binaryMessage = convertToBinary(message);
    int size = strlen(message)*8;
    uint16_t checksum = calculateChecksum(binaryMessage, size);
    printResults(message, binaryMessage, size, checksum);
    free(binaryMessage);
    return 0;
}