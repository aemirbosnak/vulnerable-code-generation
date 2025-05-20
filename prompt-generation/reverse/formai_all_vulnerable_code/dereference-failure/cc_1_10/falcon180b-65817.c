//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to get user input as a string
char* get_input() {
    char* input = malloc(100*sizeof(char));
    printf("Enter your input: ");
    fgets(input, 100, stdin);
    return input;
}

// Function to convert input to uppercase
void to_uppercase(char* input) {
    int i = 0;
    while (input[i]!= '\0') {
        input[i] = toupper(input[i]);
        i++;
    }
}

// Function to check if input is a palindrome
int is_palindrome(char* input) {
    int i = 0;
    int j = strlen(input)-1;
    while (i < j) {
        if (input[i]!= input[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

// Function to count the number of vowels in input
int count_vowels(char* input) {
    int count = 0;
    while (*input!= '\0') {
        if (tolower(*input) == 'a' || tolower(*input) == 'e' || tolower(*input) == 'i' || tolower(*input) == 'o' || tolower(*input) == 'u') {
            count++;
        }
        input++;
    }
    return count;
}

int main() {
    char* input = get_input();
    to_uppercase(input);
    if (is_palindrome(input)) {
        printf("The input is a palindrome.\n");
    } else {
        printf("The input is not a palindrome.\n");
    }
    printf("The number of vowels in the input is %d.\n", count_vowels(input));
    free(input);
    return 0;
}