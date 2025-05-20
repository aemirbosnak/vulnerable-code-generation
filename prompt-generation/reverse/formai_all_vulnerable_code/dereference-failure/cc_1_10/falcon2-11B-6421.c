//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to check if the string is a palindrome or not
int is_palindrome(char *str) {
    // Get length of the string
    int len = strlen(str);
    
    // Reverse the string
    char *rev_str = (char *)malloc(len * sizeof(char));
    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        rev_str[i] = str[j];
    }
    
    // Check if the string is a palindrome or not
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i]!= rev_str[j]) {
            return 0;
        }
    }
    
    return 1;
}

// Function to spell check the string
int spell_check(char *str) {
    // Convert string to lowercase
    char *lower_str = (char *)malloc(strlen(str) * sizeof(char));
    for (int i = 0; i < strlen(str); i++) {
        lower_str[i] = tolower(str[i]);
    }
    
    // Remove punctuation from the string
    char *clean_str = (char *)malloc(strlen(lower_str) * sizeof(char));
    for (int i = 0; i < strlen(lower_str); i++) {
        if (isalnum(lower_str[i])) {
            clean_str[i] = lower_str[i];
        }
    }
    
    // Check if the string is a palindrome or not
    if (is_palindrome(clean_str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
    
    // Free memory
    free(lower_str);
    free(clean_str);
    
    return 0;
}

int main() {
    char *str = "A man, a plan, a canal: Panama";
    spell_check(str);
    return 0;
}