//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBinary(int num) {
    // Function to print binary representation of a number
    if (num / 2 != 0) {
        printBinary(num / 2);
    }
    printf("%d", num % 2);
}

char* decimalToBinary(int num) {
    // Function to convert decimal to binary and return as a string
    char* binStr = malloc(33); // Allocate memory for 32 bits + 1 for null terminator
    if (!binStr) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    int index = 0;

    for (index = 0; index < 32; index++) {
        binStr[index] = (num & (1 << (31 - index))) ? '1' : '0';
    }
    binStr[32] = '\0'; // Null-terminate the string

    return binStr;
}

void interactiveMode() {
    // Function for interactive user input
    int num;
    char choice;

    printf("Welcome to the Binary Converter!\n");
    do {
        printf("Please enter a decimal number: ");
        if (scanf("%d", &num) != 1) {
            printf("Invalid input. Please enter a valid integer.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }
        
        char* binaryRepresentation = decimalToBinary(num);
        printf("Binary representation of %d is: %s\n", num, binaryRepresentation);
        free(binaryRepresentation);

        printf("Do you want to convert another number? (y/n): ");
        while (getchar() != '\n'); // Clear the buffer before using scanf
        choice = getchar();
    } while (choice == 'y' || choice == 'Y');     

    printf("Thank you for using the Binary Converter! Goodbye!\n");
}

void batchMode(int argc, char *argv[]) {
    // Function for batch mode where numbers are passed as command line arguments
    if (argc < 2) {
        printf("No numbers provided for conversion. Please provide decimal numbers as arguments.\n");
        return;
    }

    printf("Batch mode activated!\n");
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        char* binaryRepresentation = decimalToBinary(num);
        printf("Binary representation of %d is: %s\n", num, binaryRepresentation);
        free(binaryRepresentation);
    }
    printf("Batch conversions complete!\n");
}

int main(int argc, char *argv[]) {
    // Main function to handle user input for interactive or batch mode
    printf("Enter 'i' for interactive mode or 'b' for batch mode: ");
    char mode;
    scanf(" %c", &mode);

    if (mode == 'i' || mode == 'I') {
        interactiveMode();
    } else if (mode == 'b' || mode == 'B') {
        batchMode(argc, argv);
    } else {
        printf("Invalid mode selected. Please restart the program and select either 'i' or 'b'.\n");
    }
    
    return 0;
}