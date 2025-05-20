//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

char *reverseString(char *str) {
    int len = strlen(str);
    char *rev = malloc(len + 1);
    int i, j;
    for (i = 0, j = len - 1; i < len; i++, j--) {
        rev[i] = str[j];
    }
    rev[len] = '\0';
    return rev;
}

char *concatStrings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *concat = malloc(len1 + len2 + 1);
    int i;
    for (i = 0; i < len1; i++) {
        concat[i] = str1[i];
    }
    for (i = 0; i < len2; i++) {
        concat[len1 + i] = str2[i];
    }
    concat[len1 + len2] = '\0';
    return concat;
}

char *removeChar(char *str, char ch) {
    char *newStr = malloc(strlen(str) + 1);
    int i, j;
    for (i = 0, j = 0; i < strlen(str); i++) {
        if (str[i] != ch) {
            newStr[j++] = str[i];
        }
    }
    newStr[j] = '\0';
    return newStr;
}

char *replaceChar(char *str, char ch1, char ch2) {
    char *newStr = malloc(strlen(str) + 1);
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == ch1) {
            newStr[i] = ch2;
        } else {
            newStr[i] = str[i];
        }
    }
    newStr[strlen(str)] = '\0';
    return newStr;
}

int main() {
    char str[] = "Hello World";
    char *rev = reverseString(str);
    printf("Original string: %s\n", str);
    printf("Reversed string: %s\n", rev);

    char str1[] = "Hello";
    char str2[] = "World";
    char *concat = concatStrings(str1, str2);
    printf("First string: %s\n", str1);
    printf("Second string: %s\n", str2);
    printf("Concatenated string: %s\n", concat);

    char str3[] = "Hello";
    char *removed = removeChar(str3, 'l');
    printf("Original string: %s\n", str3);
    printf("Modified string: %s\n", removed);

    char str4[] = "Hello";
    char *replaced = replaceChar(str4, 'l', 'x');
    printf("Original string: %s\n", str4);
    printf("Modified string: %s\n", replaced);

    return 0;
}