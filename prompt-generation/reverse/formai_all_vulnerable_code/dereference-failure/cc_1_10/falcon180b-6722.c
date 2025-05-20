//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void reverse(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;

    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

void capitalize(char *str) {
    int i = 0;
    while (str[i]) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
        i++;
    }
}

void removeSpaces(char *str) {
    int i = 0;
    int j = 0;
    while (str[i]) {
        if (!isspace(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

void countWords(char *str) {
    int count = 0;
    char *word = strtok(str, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    printf("Number of words: %d\n", count);
}

int main() {
    char input[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Original string: %s\n", input);

    reverse(input);
    printf("Reversed string: %s\n", input);

    capitalize(input);
    printf("Capitalized string: %s\n", input);

    removeSpaces(input);
    printf("String without spaces: %s\n", input);

    countWords(input);

    return 0;
}