//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void reverse(char *str, int start, int end) {
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int isPalindrome(char *str, int length) {
    if (length <= 0)
        return 1;

    if (tolower(str[0]) != tolower(str[length - 1]))
        return 0;

    return isPalindrome(str + 1, length - 2);
}

int main(int argc, char *argv[]) {
    char input[MAX_LENGTH];

    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);

    printf("String: %s\n", input);

    if (strlen(input) > MAX_LENGTH) {
        printf("Error: String too long\n");
        return 1;
    }

    printf("Reversing string...\n");
    reverse(input, 0, strlen(input) - 1);
    printf("String reversed.\n");

    if (isPalindrome(input, strlen(input)))
        printf("Palindrome!\n");
    else
        printf("Not a palindrome.\n");

    return 0;
}