//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal to binary
void hexToBin(char *hex, char *bin) {
    int i, j;
    for (i = 0, j = strlen(hex) - 1; i < j; i++, j--) {
        char c = hex[i];
        if (c >= '0' && c <= '9') {
            bin[j] = c;
        } else if (c >= 'A' && c <= 'F') {
            bin[j] = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            bin[j] = c - 'a' + 10;
        } else {
            printf("Invalid hexadecimal character: %c\n", c);
            exit(1);
        }
    }
    bin[j] = '\0';
}

// Function to convert binary to hexadecimal
void binToHex(char *bin, char *hex) {
    int i, j;
    for (i = 0, j = 0; i < strlen(bin); i++) {
        char c = bin[i];
        if (c >= '0' && c <= '9') {
            hex[j++] = c;
        } else if (c >= 'A' && c <= 'F') {
            hex[j++] = c;
        } else {
            printf("Invalid binary character: %c\n", c);
            exit(1);
        }
    }
    hex[j] = '\0';
}

int main() {
    char hex[100], bin[100];
    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Convert hexadecimal to binary\n");
        printf("2. Convert binary to hexadecimal\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter hexadecimal number: ");
                scanf("%s", hex);
                hexToBin(hex, bin);
                printf("Binary number: %s\n", bin);
                break;
            case 2:
                printf("Enter binary number: ");
                scanf("%s", bin);
                binToHex(bin, hex);
                printf("Hexadecimal number: %s\n", hex);
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}