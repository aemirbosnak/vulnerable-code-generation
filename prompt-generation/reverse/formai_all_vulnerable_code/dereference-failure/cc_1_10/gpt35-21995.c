//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

/* This function removes leading and trailing white spaces from a string */
char *trim_input(char *input) {
    int len = strlen(input);
    int i = 0, j = len - 1;
    while (isspace(input[i])) i++;
    while ((j >= 0) && isspace(input[j])) j--;
    if (i > j) {
        input[0] = '\0';
    }
    else {
        for (int k = i; k <= j; k++) {
            input[k - i] = input[k];
        }
        input[j - i + 1] = '\0';
    }
    return input;
}

/* This function converts all lower case letters into upper case */
char *to_upper(char *input) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (islower(input[i])) {
            input[i] = toupper(input[i]);
        }
    }
    return input;
}

/* This function removes all non-alphabetic characters from a string */
char *sanitize_input(char *input) {
    int len = strlen(input);
    char *temp = (char *)malloc(len * sizeof(char));
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            temp[index++] = input[i];
        }
    }
    temp[index] = '\0';
    strcpy(input, temp);
    free(temp);
    return input;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Please enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    trim_input(input);
    to_upper(input);
    sanitize_input(input);
    printf("Your sanitized input is: %s\n", input);
    return 0;
}