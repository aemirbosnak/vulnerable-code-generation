//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

/* Function to check if a character is a letter or number */
int isAlphanumeric(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
        return 1;
    }
    return 0;
}

/* Function to convert a string to lowercase */
void toLowerCase(char str[]) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

/* Function to check if a string is palindrome */
int isPalindrome(char str[]) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        while (!isAlphanumeric(str[i])) {
            i++;
        }
        while (!isAlphanumeric(str[j])) {
            j--;
        }
        if (tolower(str[i]) != tolower(str[j])) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = 0; /* Removing the newline character */
    toLowerCase(str);
    if (isPalindrome(str)) {
        printf("%s is a palindrome\n", str);
    } else {
        printf("%s is not a palindrome\n", str);
    }
    return 0;
}