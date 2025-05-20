//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void printString(char *str) {
    printf("Original String: %s\n", str);
    reverseString(str);
    printf("Reversed String: %s\n", str);
}

void copyString(char *dest, char *src) {
    strcpy(dest, src);
}

void concatenateStrings(char *dest, char *src1, char *src2) {
    int len1 = strlen(src1);
    int len2 = strlen(src2);
    strcpy(dest, src1);
    strcat(dest, src2);
}

void compareStrings(char *str1, char *str2) {
    int res = strcmp(str1, str2);
    (res == 0) ? printf("Strings are equal.\n") : printf("Strings are not equal.\n");
}

int main(int argc, char *argv[]) {
    char str[MAX_LENGTH];
    char str1[MAX_LENGTH] = "Hello";
    char str2[MAX_LENGTH] = "World";

    if (argc < 2) {
        printf("Usage: %s <operation> [string]\n", argv[0]);
        return 1;
    }

    switch (*argv[1]) {
        case 'p':
            printString(str);
            break;
        case 'c':
            if (argc < 3) {
                printf("Usage: %s print <string>\n", argv[0]);
                return 1;
            }
            copyString(str, argv[2]);
            printf("Copied string: %s\n", str);
            break;
        case 'co':
            if (argc < 4) {
                printf("Usage: %s concatenate <dest> <src1> <src2>\n", argv[0]);
                return 1;
            }
            concatenateStrings(str, argv[2], argv[3]);
            printf("Concatenated string: %s\n", str);
            break;
        case 'ca':
            if (argc != 3) {
                printf("Usage: %s compare <str1> <str2>\n", argv[0]);
                return 1;
            }
            compareStrings(str1, str2);
            break;
        default:
            printf("Invalid operation. Use 'p' for print string, 'c' for copy string, 'co' for concatenate strings, and 'ca' for compare strings.\n");
            return 1;
    }

    return 0;
}