//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 100

void reverse_string(char *str);
int is_palindrome(char *str);
int count_vowels(char *str);

int main() {
    char str[MAX_STR_LEN];

    printf("Enter a string: ");
    fgets(str, MAX_STR_LEN, stdin); // read string from input

    reverse_string(str); // reverse the string
    printf("Reversed string: %s\n", str);

    if (is_palindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    int num_vowels = count_vowels(str);
    printf("Number of vowels in the string: %d\n", num_vowels);

    return 0;
}

void reverse_string(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int is_palindrome(char *str) {
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i])!= tolower(str[len - 1 - i])) {
            return 0;
        }
    }

    return 1;
}

int count_vowels(char *str) {
    int num_vowels = 0;

    for (int i = 0; str[i]!= '\0'; i++) {
        if (tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u') {
            num_vowels++;
        }
    }

    return num_vowels;
}