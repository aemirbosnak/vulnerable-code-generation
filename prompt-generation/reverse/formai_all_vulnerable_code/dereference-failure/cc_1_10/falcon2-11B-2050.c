//Falcon2-11B DATASET v1.0 Category: Binary Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_DIGIT_LENGTH 20

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *string = argv[1];
    int stringLength = strlen(string);
    int digitLength = stringLength;
    int decimalPlace = 1;
    char *digit = malloc(MAX_DIGIT_LENGTH * sizeof(char));
    if (!digit) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    int i = 0;
    for (i = 0; i < stringLength; i++) {
        if (isdigit(string[i]) == 0) {
            digitLength = i;
            break;
        }
    }

    if (digitLength == stringLength) {
        fprintf(stderr, "No digits found in the string\n");
        return 1;
    }

    digitLength += 1; // Adding one to account for the decimal point

    for (i = 0; i < digitLength; i++) {
        if (i == 0) {
            digit[i] = '.';
        } else {
            digit[i] = string[i - 1];
        }
    }

    for (i = 0; i < digitLength; i++) {
        printf("%c", digit[i]);
    }

    printf("\n");

    free(digit);
    return 0;
}