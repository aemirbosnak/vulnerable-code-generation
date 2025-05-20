//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int hex;
} Person;

void convertHexToInt(char hex[]) {
    int dec = 0;
    int len = strlen(hex);
    int placeValue = 1;

    for (int i = len - 1; i >= 0; i--) {
        char hexDigit = hex[i];

        if (hexDigit >= '0' && hexDigit <= '9') {
            dec += (hexDigit - '0') * placeValue;
        } else if (hexDigit >= 'A' && hexDigit <= 'F') {
            dec += (hexDigit - 'A' + 10) * placeValue;
        }

        placeValue *= 16;
    }

    printf("%d\n", dec);
}

void printPerson(Person person) {
    printf("Person: %s, Hexadecimal: %X\n", person.name, person.hex);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <name> <hexadecimal>\n", argv[0]);
        return 1;
    }

    Person romeo = {"Romeo", strtoul(argv[1], NULL, 16)};
    Person juliet = {"Juliet", strtoul(argv[2], NULL, 16)};

    convertHexToInt(argv[1]);
    convertHexToInt(argv[2]);

    printPerson(romeo);
    printPerson(juliet);

    if (romeo.hex == juliet.hex) {
        printf("Love is not in our stars, but in our eyes.\n");
    } else {
        printf("Parting is such sweet sorrow.\n");
    }

    return 0;
}