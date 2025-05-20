//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {HEX, DEC, OCT} BaseType;

void error(char* msg) {
    printf("%s\n", msg);
    exit(1);
}

int isValidHex(char c) {
    return (isdigit(c) || (isalpha(c) && isalpha(c) <= 'F' && isalpha(c) >= 'A'));
}

int hexStrToDec(char* str, int* len) {
    int i, sum = 0;
    int len_tmp = *len;

    for (i = 0; i < len_tmp; i++) {
        if (!isValidHex(str[i]))
            error("Invalid hexadecimal string.\n");

        sum += isdigit(str[i]) ? (str[i] - '0') : (isalpha(str[i]) ? (str[i] - 'A' + 10) : 0) << 4;

        if (i + 1 < len_tmp)
            sum += (isdigit(str[i + 1]) ? (str[i + 1] - '0') : (isalpha(str[i + 1]) ? (str[i + 1] - 'A' + 10) : 0));

        i++;
    }

    *len = i;
    return sum;
}

void printHex(int dec) {
    static char hex[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int i, j;
    char buffer[32];

    for (i = 31; dec > 0; i--) {
        buffer[i] = hex[dec % 16];
        dec /= 16;
    }

    for (j = 31; j >= 0; j--)
        putchar(buffer[j]);
    putchar('\n');
}

int main(int argc, char* argv[]) {
    int dec, len;
    char* str;

    if (argc != 2)
        error("Usage: hexconv <hex_string>\n");

    str = argv[1];

    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
        dec = hexStrToDec(str + 2, &len);
    else
        error("Invalid hex string format.\n");

    printHex(dec);

    return 0;
}