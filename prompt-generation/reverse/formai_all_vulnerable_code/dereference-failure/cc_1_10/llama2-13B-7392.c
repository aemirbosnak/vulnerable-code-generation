//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 50

void print_str(char *str);
void reverse_str(char *str);
void remove_vowels(char *str);

int main() {
    char str[MAX_STR_LEN];

    printf("Enter a string: ");
    fgets(str, MAX_STR_LEN, stdin);

    print_str(str);
    reverse_str(str);
    remove_vowels(str);

    return 0;
}

void print_str(char *str) {
    printf("Original string: %s\n", str);
}

void reverse_str(char *str) {
    char *ptr = str;
    char *end = str + strlen(str) - 1;

    while (ptr < end) {
        char temp = *ptr;
        *ptr = *end;
        *end = temp;
        ptr++;
        end--;
    }
}

void remove_vowels(char *str) {
    char *ptr = str;
    char c;

    while ((c = *ptr++) != '\0') {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            *ptr = ' ';
        }
    }
}