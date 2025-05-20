//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 16

typedef struct Dragon {
    int numDigits;
    char **digits;
} Dragon;

Dragon* createDragon(int numDigits) {
    Dragon* dragon = malloc(sizeof(Dragon));
    dragon->numDigits = numDigits;
    dragon->digits = malloc(numDigits * sizeof(char*));
    for (int i = 0; i < numDigits; i++) {
        dragon->digits[i] = malloc(2 * sizeof(char));
    }
    return dragon;
}

void slayTheDragon(Dragon* dragon) {
    free(dragon->digits);
    free(dragon);
}

int main() {
    Dragon* dragon = createDragon(MAX_DIGITS);
    dragon->digits[0] = "12";
    dragon->digits[1] = "34";
    dragon->digits[2] = "56";

    int convertedNumber = convertHexToDec(dragon);

    printf("Converted number: %d", convertedNumber);

    slayTheDragon(dragon);

    return 0;
}

int convertHexToDec(Dragon* dragon) {
    int numDigits = dragon->numDigits;
    int convertedNumber = 0;

    for (int i = numDigits - 1; i >= 0; i--) {
        char* digit = dragon->digits[i];
        int digitValue = convertToDigit(digit);
        convertedNumber += digitValue * pow(16, i);
    }

    return convertedNumber;
}

int convertToDigit(char* digit) {
    int numChars = strlen(digit);
    if (numChars == 1) {
        return digit[0] - '0';
    } else {
        return (digit[0] - 'a' + 10) * 16 + digit[1] - '0';
    }
}