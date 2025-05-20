//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: excited
#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);
    char* start = str;
    char* end = str + length - 1;

    while (start < end) {
        *reversed++ = *end;
        *end-- = *start;
        start++;
    }

    *reversed = '\0';
    printf("Reversed string: %s\n", reversed);
    free(reversed);
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int length = strlen(str);
    char* reversed = malloc(length + 1);
    char* start = str;
    char* end = str + length - 1;

    while (start < end) {
        *reversed++ = *end;
        *end-- = *start;
        start++;
    }

    *reversed = '\0';

    if (strcmp(str, reversed) == 0) {
        printf("%s is a palindrome!\n", str);
        return 1;
    } else {
        printf("%s is not a palindrome.\n", str);
        return 0;
    }
}

int main() {
    char* str1 = "racecar";
    reverseString(str1);

    char* str2 = "hello";
    isPalindrome(str2);

    char* str3 = "A man, a plan, a canal, Panama!";
    reverseString(str3);
    isPalindrome(str3);

    return 0;
}