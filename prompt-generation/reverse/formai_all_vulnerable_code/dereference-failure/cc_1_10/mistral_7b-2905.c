//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct HexNum {
    int decimal;
    char hex[33];
} HexNum;

void HexToDec(char hex[]) {
    HexNum num;
    int i, j, power = 0;

    for(i = 0; hex[i] != '\0'; i++) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            num.hex[power++] = hex[i];
            num.hex[power++] = 'A' + (hex[i] - '0');
            num.hex[power++] = '\0';
            break;
        }
        else if(isxdigit(hex[i])) {
            num.hex[power++] = hex[i];
            power++;
        }
        else {
            fprintf(stderr, "Invalid Hexadecimal number\n");
            exit(EXIT_FAILURE);
        }
    }

    for(i = 0; i < power; i++) {
        j = 16;
        int value = 0;

        while(j > 0) {
            if(num.hex[i] >= '0' && num.hex[i] <= '9') {
                value += (num.hex[i] - '0') * pow(16, j--);
            }
            else {
                value += (10 + (num.hex[i] - 'A') * 10) * pow(16, j--);
            }
        }

        num.decimal += value;
    }

    printf("Decimal Equivalent: %d\n", num.decimal);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <Hexadecimal Number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    HexToDec(argv[1]);

    return EXIT_SUCCESS;
}

// pow function
int pow(int base, int exp) {
    int result = 1;

    for(int i = 0; i < exp; i++) {
        result *= base;
    }

    return result;
}