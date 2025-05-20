//Falcon2-11B DATASET v1.0 Category: Palindrome Checker ; Style: protected
#include <stdio.h>
#include <stdlib.h>

//Function to check if a string is palindrome or not
int isPalindrome(char* str) {
    //Check if the string is null or not
    if (str == NULL) {
        return 0;
    }

    //Create a new string that is double the length of the input string
    int len = strlen(str);
    char* newStr = (char*)malloc(sizeof(char) * (len * 2));
    
    //Initialize the new string to all zeros
    for (int i = 0; i < len; i++) {
        newStr[i] = '0';
    }

    //Copy the input string to the new string
    for (int i = 0; i < len; i++) {
        newStr[i + len] = str[i];
    }

    //Compare the first and last characters of the new string
    for (int i = 0; i < len / 2; i++) {
        if (newStr[i]!= newStr[len - i - 1]) {
            return 0;
        }
    }

    free(newStr);
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    //Remove the newline character from the input string
    str[strcspn(str, "\n")] = '\0';

    //Check if the string is a palindrome or not
    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}