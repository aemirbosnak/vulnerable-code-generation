//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

char* remove_whitespace(char* str) {
    int i = 0;
    int j = 0;
    char* output = malloc(MAX_LENGTH * sizeof(char));

    for (i = 0; str[i]!= '\0'; i++) {
        if (!isspace(str[i])) {
            output[j] = tolower(str[i]);
            j++;
        }
    }

    output[j] = '\0';

    return output;
}

int is_palindrome(char* str) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        if (str[i]!= str[j]) {
            return 0;
        }

        i++;
        j--;
    }

    return 1;
}

void play_game() {
    char* input_str = malloc(MAX_LENGTH * sizeof(char));
    char* cleaned_str = malloc(MAX_LENGTH * sizeof(char));

    printf("Enter a string: ");
    fgets(input_str, MAX_LENGTH, stdin);

    cleaned_str = remove_whitespace(input_str);

    if (is_palindrome(cleaned_str)) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    free(input_str);
    free(cleaned_str);
}

int main() {
    int i;
    for (i = 0; i < 2; i++) {
        play_game();
    }

    return 0;
}