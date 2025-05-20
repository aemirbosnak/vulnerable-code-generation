//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100

void print_string(char *str) {
    printf("Original String: %s\n", str);
}

void uppercase(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
    printf("Uppercase: ");
    print_string(str);
}

void lowercase(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
    printf("Lowercase: ");
    print_string(str);
}

void reverse_string(char *str) {
    int len = strlen(str), i = 0;
    char rev_str[MAX_LENGTH] = {'\0'};

    while (i < len) {
        rev_str[len - 1 - i] = str[i];
        i++;
    }

    printf("Reversed String: ");
    print_string(rev_str);
}

void concatenate(char *str1, char *str2) {
    int len1 = strlen(str1), len2 = strlen(str2), len3;
    char *str3 = (char *) malloc((len1 + len2 + 1) * sizeof(char));

    strcpy(str3, str1);
    strcat(str3, str2);

    len3 = strlen(str3);

    printf("Concatenated String: ");
    print_string(str3);

    free(str3);
}

int main() {
    char str1[MAX_LENGTH] = "Hello, World!";
    char str2[MAX_LENGTH] = "Gracious Programming";

    print_string(str1);
    printf("\n");

    uppercase(str1);

    printf("\n");

    lowercase(str1);

    printf("\n");

    reverse_string(str1);

    printf("\n");

    concatenate(str1, str2);

    printf("\n");

    return 0;
}