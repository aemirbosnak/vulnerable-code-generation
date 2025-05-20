//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverseString(char* str) {
    int len = strlen(str);
    char* revStr = (char*)malloc(len+1);
    int i;
    for(i=len-1; i>=0; i--) {
        revStr[i] = tolower(str[i]);
    }
    revStr[len] = '\0';
    printf("Reversed string: %s\n", revStr);
    free(revStr);
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    int len = strlen(str);
    int i;
    for(i=0; i<len/2; i++) {
        if(tolower(str[i])!= tolower(str[len-i-1])) {
            return 0;
        }
    }
    return 1;
}

// Function to remove all vowels from a string
void removeVowels(char* str) {
    int len = strlen(str);
    char* newStr = (char*)malloc(len+1);
    int i;
    for(i=0; i<len; i++) {
        if(!isalpha(str[i])) {
            newStr[i] = str[i];
        } else {
            if(tolower(str[i])!= 'a' && tolower(str[i])!= 'e' && tolower(str[i])!= 'i' && tolower(str[i])!= 'o' && tolower(str[i])!= 'u') {
                newStr[i] = str[i];
            }
        }
    }
    newStr[len] = '\0';
    printf("String without vowels: %s\n", newStr);
    free(newStr);
}

// Function to count the number of words in a string
int countWords(char* str) {
    int len = strlen(str);
    int count = 0;
    int i;
    for(i=0; i<len; i++) {
        if(isspace(str[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    char* str = "A man, a plan, a canal: Panama";
    printf("Original string: %s\n", str);
    reverseString(str);
    removeVowels(str);
    int numWords = countWords(str);
    printf("Number of words: %d\n", numWords);
    return 0;
}