//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void to_upper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void to_lower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

void remove_space(char *str) {
    char *new_str = malloc(MAX_LENGTH);
    int index = 0, i;

    for (i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            new_str[index++] = str[i];
        }
    }

    new_str[index] = '\0';
    strcpy(str, new_str);
    free(new_str);
}

void print_string(char *str) {
    printf("Original String : %s\n", str);
    reverse_string(str);
    printf("Reversed String: %s\n", str);
    to_upper(str);
    printf("Upper Case     : %s\n", str);
    to_lower(str);
    printf("Lower Case     : %s\n", str);
    remove_space(str);
    printf("No Space       : %s\n", str);
}

int main(int argc, char *argv[]) {
    char str[MAX_LENGTH];

    if (argc > 1) {
        strcpy(str, argv[1]);
    } else {
        printf("Please enter a string as an argument.\n");
        return 1;
    }

    print_string(str);

    return 0;
}