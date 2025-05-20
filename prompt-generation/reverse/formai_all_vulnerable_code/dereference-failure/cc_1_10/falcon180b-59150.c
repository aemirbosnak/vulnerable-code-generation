//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    char input[MAX_LINE_LENGTH];
    char output[MAX_LINE_LENGTH];
    int i, j;
    int is_hex;

    // Check for correct number of arguments
    if (argc!= 2) {
        printf("Usage: %s <hexadecimal_number>\n", argv[0]);
        return 1;
    }

    // Get input from command line
    strcpy(input, argv[1]);

    // Remove any leading or trailing whitespace
    input[strcspn(input, "\n")] = '\0';

    // Check if input is a valid hexadecimal number
    for (i = 0; input[i]!= '\0'; i++) {
        if (!isxdigit(input[i])) {
            printf("Error: Input is not a valid hexadecimal number.\n");
            return 1;
        }
    }

    // Convert hexadecimal to decimal
    for (i = 0, j = 0; input[i]!= '\0'; i++) {
        if (isxdigit(input[i])) {
            if (isupper(input[i])) {
                output[j] = input[i] - 'A' + 10;
            } else {
                output[j] = input[i] - 'a' + 10;
            }
            j++;
        }
    }
    output[j] = '\0';

    // Print result
    printf("Decimal equivalent: %s\n", output);

    return 0;
}