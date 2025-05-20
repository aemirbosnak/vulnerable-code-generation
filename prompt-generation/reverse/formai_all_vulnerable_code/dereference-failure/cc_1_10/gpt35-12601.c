//FormAI DATASET v1.0 Category: Binary Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char* toString(int);
int toDecimal(char*);

int main() {
    char choice;
    do {
        printf("Choose an option:\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Convert binary to decimal\n");
        printf("3. Quit\n");

        printf("Your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1': {
                int decimal;
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                printf("Binary equivalent is: %s\n", toString(decimal));
                break;
            }
            case '2': {
                char binary[MAX];
                printf("Enter a binary number: ");
                scanf("%s", binary);
                printf("Decimal equivalent is: %d\n", toDecimal(binary));
                break;
            }
            case '3': {
                printf("Quitting program...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }
    } while(choice != '3');

    return 0;
}

char* toString(int decimal) {
    char* binary = (char*) malloc(MAX * sizeof(char));
    int index = 0;

    while(decimal > 0) {
        binary[index++] = decimal % 2 + '0';
        decimal /= 2;
    }
    binary[index] = '\0';

    int i, j;
    char temp;
    for(i = 0, j = strlen(binary) - 1; i < j; i++, j--) {
        temp = binary[i];
        binary[i] = binary[j];
        binary[j] = temp;
    }

    return binary;
}

int toDecimal(char* binary) {
    int decimal = 0;
    int power = 1;
    int i;

    for(i = strlen(binary) - 1; i >= 0; i--) {
        if(binary[i] == '1')
            decimal += power;
        power *= 2;
    }

    return decimal;
}