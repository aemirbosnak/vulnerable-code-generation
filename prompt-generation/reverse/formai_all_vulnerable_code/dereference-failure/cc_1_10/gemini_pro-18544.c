//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverse(char *str) {
    int len = strlen(str);
    char *reversed = malloc(len + 1);
    int i, j;
    for(i = 0, j = len - 1; i < len; i++, j--) {
        reversed[j] = str[i];
    }
    reversed[len] = '\0';
    return reversed;
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    int i;
    for(i = 0; i < len / 2; i++) {
        if(str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to find the longest palindromic substring
char *longestPalindrome(char *str) {
    int len = strlen(str);
    int i, j, k, l;
    int longest = 0;
    int start = 0;
    for(i = 0; i < len; i++) {
        for(j = i + 1; j < len; j++) {
            k = i;
            l = j;
            while(k <= l && str[k] == str[l]) {
                k++;
                l--;
            }
            if(k > l && j - i + 1 > longest) {
                start = i;
                longest = j - i + 1;
            }
        }
    }
    char *palindrome = malloc(longest + 1);
    strncpy(palindrome, str + start, longest);
    palindrome[longest] = '\0';
    return palindrome;
}

// Function to find the number of different palindromic substrings
int numPalindromicSubstrings(char *str) {
    int len = strlen(str);
    int i, j, k, l;
    int count = 0;
    for(i = 0; i < len; i++) {
        for(j = i + 1; j < len; j++) {
            k = i;
            l = j;
            while(k <= l && str[k] == str[l]) {
                k++;
                l--;
            }
            if(k > l) {
                count++;
            }
        }
    }
    return count;
}

// Function to print all the different palindromic substrings
void printPalindromicSubstrings(char *str) {
    int len = strlen(str);
    int i, j, k, l;
    for(i = 0; i < len; i++) {
        for(j = i + 1; j < len; j++) {
            k = i;
            l = j;
            while(k <= l && str[k] == str[l]) {
                k++;
                l--;
            }
            if(k > l) {
                printf("%s\n", str + i);
            }
        }
    }
}

int main() {
    char str[] = "racecar";
    printf("Original string: %s\n", str);
    char *reversed = reverse(str);
    printf("Reversed string: %s\n", reversed);
    int is_palindrome = isPalindrome(str);
    printf("Is palindrome: %d\n", is_palindrome);
    char *longest = longestPalindrome(str);
    printf("Longest palindromic substring: %s\n", longest);
    int num_palindromic = numPalindromicSubstrings(str);
    printf("Number of different palindromic substrings: %d\n", num_palindromic);
    printPalindromicSubstrings(str);
    return 0;
}