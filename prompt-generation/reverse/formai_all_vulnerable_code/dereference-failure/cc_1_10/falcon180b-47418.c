//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 256

char *reverse_string(char *str);
void convert_to_binary(char *decimal_str, char *binary_str);

int main(int argc, char *argv[]) {
    char decimal_str[MAX_SIZE];
    char binary_str[MAX_SIZE];

    printf("Enter a decimal number: ");
    fgets(decimal_str, MAX_SIZE, stdin);

    // Remove newline character
    decimal_str[strcspn(decimal_str, "\n")] = '\0';

    // Convert decimal to binary
    convert_to_binary(decimal_str, binary_str);

    printf("Binary representation: %s\n", binary_str);

    return 0;
}

char *reverse_string(char *str) {
    char *rev_str = (char *)malloc(strlen(str) + 1);
    int i, j;

    for (i = strlen(str) - 1, j = 0; i >= 0; i--, j++) {
        rev_str[j] = str[i];
    }

    rev_str[j] = '\0';

    return rev_str;
}

void convert_to_binary(char *decimal_str, char *binary_str) {
    int decimal_num = 0, binary_num = 0, i = 0;

    while (decimal_str[i]) {
        if (isdigit(decimal_str[i])) {
            decimal_num = decimal_num * 10 + (decimal_str[i] - '0');
        } else {
            printf("Invalid input. Please enter a valid decimal number.\n");
            exit(1);
        }
        i++;
    }

    binary_str[0] = '\0';

    while (decimal_num) {
        binary_num = decimal_num % 2;
        binary_str = strcat(binary_str, binary_num + '0');
        decimal_num /= 2;
    }

    reverse_string(binary_str);
}