//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decToBin(int num) {
    int rem, i = 1;
    char bin[33]; // Maximum 32 bits + 1 for null terminator

    bin[0] = '\0'; // Initialize with null terminator

    while (num!= 0) {
        rem = num % 2;
        bin[i++] = rem + '0'; // Convert remainder to character and add to binary string
        num /= 2;
    }

    printf("Binary representation: %s\n", bin);
}

// Function to convert binary to decimal
int binToDec(char* str) {
    int dec = 0, base = 1, len = strlen(str);

    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == '1') {
            dec += base;
        }
        base *= 2;
    }

    return dec;
}

int main() {
    int choice, num;

    do {
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &num);
            decToBin(num);
            break;

        case 2:
            printf("Enter a binary number: ");
            scanf("%s", &num);
            printf("Decimal representation: %d\n", binToDec(num));
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}