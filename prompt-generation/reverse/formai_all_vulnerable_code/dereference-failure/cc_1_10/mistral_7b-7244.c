//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function to remove leading and trailing spaces from a string
void trim_spaces(char str[]){
    int start = 0, end = strlen(str) - 1;

    while(isspace(str[start]) && start < MAX_LENGTH){
        start++;
    }

    while(isspace(str[end]) && end > 0){
        end--;
    }

    for(int i = start; i <= end; i++){
        str[i - start] = str[i];
    }

    str[end - start + 1] = '\0';
}

// Function to check if two characters are same after considering their case
int is_same_char(char c1, char c2){
    return (tolower(c1) == tolower(c2));
}

// Function to check if a given string is a palindrome
int is_palindrome(char str[]){
    int start = 0, end = strlen(str) - 1;

    // Special case for even length palindromes
    if(strlen(str) % 2 == 0){
        while(start < end){
            if(!is_same_char(str[start], str[end])){
                return 0;
            }
            start++;
            end--;
        }
        return 1;
    }

    // Special case for odd length palindromes
    while(start < end){
        if(!is_same_char(str[start], str[end])){
            return 0;
        }
        start++;
        end--;
    }

    // If we reach here, it means that the center character is the only character
    // that is different from its symmetric character. So, we check if it is same
    // with itself or not.
    if(strlen(str) % 2 == 1 && is_same_char(str[start], str[start])){
        return 1;
    }

    return 0;
}

int main(){
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    trim_spaces(str); // Remove leading and trailing spaces

    if(is_palindrome(str)){
        printf("The given string is a palindrome.\n");
    }
    else{
        printf("The given string is not a palindrome.\n");
    }

    return 0;
}