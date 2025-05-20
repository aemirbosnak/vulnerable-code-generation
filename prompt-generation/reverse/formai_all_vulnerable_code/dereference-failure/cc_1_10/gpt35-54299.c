//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 20
#define BITS_IN_BYTE 8

void calculateSubnetMask(int subnetBits, char *subnetMask) {
    int byteIndex = 0;
    int bitIndex = 0;
    int subnetMaskBytes[4] = {0};

    for (int i = 0; i < subnetBits; ++i) {
        if (bitIndex == BITS_IN_BYTE) {
            // Move to next byte
            byteIndex++;
            bitIndex = 0;
        }

        subnetMaskBytes[byteIndex] |= 1 << (BITS_IN_BYTE - 1 - bitIndex);
        bitIndex++;
    }

    sprintf(subnetMask, "%d.%d.%d.%d", subnetMaskBytes[0], subnetMaskBytes[1], subnetMaskBytes[2], subnetMaskBytes[3]);
}

int getValidInput(char *input, char *errorPrompt) {
    int validInput = 0;

    do {
        printf("> ");
        fflush(stdout);
        fgets(input, MAX_INPUT_LENGTH, stdin);

        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        // Validate input
        if (strlen(input) == 0) {
            printf("%s", errorPrompt);
        } else if (atoi(input) == 0 && input[0] != '0') {
            printf("Please enter a valid number.\n");
        } else {
            validInput = 1;
        }
    } while (!validInput);

    return atoi(input);
}

int main() {
    printf("*********************************************\n");
    printf("***            SUBNET CALCULATOR           ***\n");
    printf("*********************************************\n");

    // Get IP address from user
    char ipAddress[MAX_INPUT_LENGTH];
    printf("\nEnter IP address: ");
    fflush(stdout);
    fgets(ipAddress, MAX_INPUT_LENGTH, stdin);
    ipAddress[strcspn(ipAddress, "\n")] = 0;

    // Get subnet bits from user
    int subnetBits = getValidInput((char *) malloc(MAX_INPUT_LENGTH * sizeof(char)),
                                    "Please enter the number of subnet bits: ");
    if (subnetBits < 1 || subnetBits > 30) {
        printf("Please enter a valid number of subnet bits between 1 and 30.\n");
        return 1;
    }

    // Calculate subnet mask
    char subnetMask[MAX_INPUT_LENGTH];
    calculateSubnetMask(subnetBits, subnetMask);

    // Print results
    printf("\nResults:\n");
    printf("IP Address: %s\n", ipAddress);
    printf("Subnet Bits: %d\n", subnetBits);
    printf("Subnet Mask: %s\n", subnetMask);

    return 0;
}