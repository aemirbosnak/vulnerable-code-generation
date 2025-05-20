//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void toUpper(char *str) {
    for (int i = 0; str[i]; ++i) {
        str[i] = toupper(str[i]);
    }
}

void extractSubstring(char *str, char *substr, int start, int length) {
    int index = 0;
    while (*str && index < start) {
        ++str;
        ++index;
    }

    int sublen = 0;
    while (*str && sublen < length) {
        *substr++ = *str++;
        ++sublen;
    }

    *substr = '\0';
}

void printSubstring(char *str, char *substr) {
    printf("%s: ", str);
    printf("%s\n", substr);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <string> <substring>\n", argv[0]);
        return 1;
    }

    char str[MAX_LENGTH];
    strcpy(str, argv[1]);

    char substr[MAX_LENGTH];
    extractSubstring(str, substr, 0, strlen(argv[2]));

    reverse(substr);
    toUpper(substr);

    printSubstring(argv[1], substr);

    return 0;
}