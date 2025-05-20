//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    char temp[len];
    strcpy(temp, str);
    for (int i = 0; i < len; i++) {
        str[i] = temp[len - 1 - i];
    }
    str[len] = '\0';
}

// Function to remove all occurrences of a character from a string
void removeCharFromString(char *str, char ch) {
    int len = strlen(str);
    char temp[len];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (str[i]!= ch) {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i]!= str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    
    // Prompt user to enter a string
    printf("Enter a string: ");
    scanf("%s", str);
    
    // Reverse the string
    printf("Reversed string: %s\n", str);
    reverseString(str);
    printf("%s\n", str);
    
    // Remove all occurrences of a character from the string
    char ch;
    printf("Enter a character to remove: ");
    scanf("%c", &ch);
    printf("String after removing %c: %s\n", ch, str);
    removeCharFromString(str, ch);
    printf("%s\n", str);
    
    // Check if the string is a palindrome
    printf("Is %s a palindrome? %s\n", str, isPalindrome(str)? "Yes" : "No");
    
    return 0;
}