//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main() {
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    char *p;
    int i, j, k;
    int count;

    // Prompt user for input string
    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    // Remove leading and trailing white spaces
    p = input;
    while (isspace(*p)) {
        p++;
    }
    k = strlen(p) - 1;
    while (isspace(p[k])) {
        p[k] = '\0';
        k--;
    }

    // Count the number of words in the string
    p = input;
    count = 0;
    while (isspace(*p)) {
        p++;
    }
    while (*p!= '\0') {
        if (isspace(*p)) {
            count++;
        }
        p++;
    }

    // Reverse the string
    p = input;
    i = 0;
    j = strlen(input) - 1;
    while (i < j) {
        char temp = *p;
        *p = *(p + j);
        *(p + j) = temp;
        p++;
        i++;
        j--;
    }

    // Convert the string to uppercase
    p = input;
    while (*p!= '\0') {
        *p = toupper(*p);
        p++;
    }

    // Convert the string to lowercase
    p = input;
    while (*p!= '\0') {
        *p = tolower(*p);
        p++;
    }

    // Replace all occurrences of a character with another character
    p = input;
    char from;
    char to;
    printf("Enter the character to replace: ");
    scanf(" %c", &from);
    printf("Enter the replacement character: ");
    scanf(" %c", &to);
    while (*p!= '\0') {
        if (*p == from) {
            *p = to;
        }
        p++;
    }

    // Copy the modified string to output
    strcpy(output, input);

    // Remove all vowels from the string
    p = output;
    while (*p!= '\0') {
        if (*p!= 'a' && *p!= 'e' && *p!= 'i' && *p!= 'o' && *p!= 'u' && *p!= 'A' && *p!= 'E' && *p!= 'I' && *p!= 'O' && *p!= 'U') {
            printf("%c", *p);
        }
        p++;
    }

    // Print the modified string
    printf("\nModified string: %s", output);

    return 0;
}