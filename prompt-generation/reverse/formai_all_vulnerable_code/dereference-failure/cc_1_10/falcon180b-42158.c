//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverse(char *str) {
    int len = strlen(str);
    char *rev = (char *)malloc(len + 1);
    int i = 0;
    for (int j = len - 1; j >= 0; j--) {
        rev[i++] = str[j];
    }
    rev[i] = '\0';
    printf("Reversed string: %s\n", rev);
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
    char *str1 = "A man, a plan, a canal: Panama";
    printf("Original string: %s\n", str1);
    reverse(str1);
    if (isPalindrome(str1)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    char *str2 = "Was it a car or a cat I saw?";
    printf("Original string: %s\n", str2);
    reverse(str2);
    if (isPalindrome(str2)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    char *str3 = "Hello, world!";
    printf("Original string: %s\n", str3);
    reverse(str3);
    printf("Reversed string: %s\n", str3);

    return 0;
}