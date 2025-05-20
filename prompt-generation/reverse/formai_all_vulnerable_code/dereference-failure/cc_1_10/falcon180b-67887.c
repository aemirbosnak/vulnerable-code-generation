//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUMBER_LENGTH 32

typedef struct {
    char binary[MAX_NUMBER_LENGTH];
    int decimal;
} number_t;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <number>\n", argv[0]);
        exit(1);
    }

    char input[MAX_LINE_LENGTH];
    strcpy(input, argv[1]);

    // Remove leading/trailing whitespace
    input[strcspn(input, "\r\n")] = '\0';
    input[strspn(input, " \t\r\n")] = '\0';

    int decimal = 0;
    int i = 0;
    int is_negative = 0;
    if (input[0] == '-') {
        is_negative = 1;
        i++;
    }

    while (isdigit(input[i])) {
        decimal = decimal * 10 + input[i] - '0';
        i++;
        if (i >= MAX_NUMBER_LENGTH) {
            printf("Error: Number is too long\n");
            exit(1);
        }
    }

    number_t num;
    num.decimal = decimal;
    sprintf(num.binary, "%b", decimal);

    printf("Decimal: %d\n", decimal);
    printf("Binary  : %s\n", num.binary);

    return 0;
}