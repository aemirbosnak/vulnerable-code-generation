//FormAI DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to count the number of vowels in a string
int vowelCount(char* str) {
    int count = 0;
    for(int i = 0; i < strlen(str); i++) {
        char c = tolower(str[i]);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

// function to reverse a string
char* reverseStr(char* str) {
    char* result = malloc(strlen(str) + 1);
    int index = 0;
    for(int i = strlen(str) - 1; i >= 0; i--) {
        result[index++] = str[i];
    }
    result[index] = '\0';
    return result;
}

// function to remove all whitespaces from a string
char* removeSpaces(char* str) {
    char* result = malloc(strlen(str) + 1);
    int index = 0;
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] != ' ') {
            result[index++] = str[i];
        }
    }
    result[index] = '\0';
    return result;
}

// main function to test the string manipulation functions
int main() {
    char str1[] = "This is a Test String";
    char str2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char str3[] = "A man a plan a canal Panama";
    
    // count the number of vowels and print the result
    int vowelCount1 = vowelCount(str1);
    int vowelCount2 = vowelCount(str2);
    int vowelCount3 = vowelCount(str3);
    printf("'%s' has %d vowels.\n", str1, vowelCount1);
    printf("'%s' has %d vowels.\n", str2, vowelCount2);
    printf("'%s' has %d vowels.\n", str3, vowelCount3);
    
    // reverse the strings and print the result
    char* reversedStr1 = reverseStr(str1);
    char* reversedStr2 = reverseStr(str2);
    char* reversedStr3 = reverseStr(str3);
    printf("'%s' reversed is '%s'.\n", str1, reversedStr1);
    printf("'%s' reversed is '%s'.\n", str2, reversedStr2);
    printf("'%s' reversed is '%s'.\n", str3, reversedStr3);
    
    // remove the whitespaces from the strings and print the result
    char* noSpacesStr1 = removeSpaces(str1);
    char* noSpacesStr2 = removeSpaces(str2);
    char* noSpacesStr3 = removeSpaces(str3);
    printf("'%s' with spaces removed is '%s'.\n", str1, noSpacesStr1);
    printf("'%s' with spaces removed is '%s'.\n", str2, noSpacesStr2);
    printf("'%s' with spaces removed is '%s'.\n", str3, noSpacesStr3);
    
    // free the memory used by the heap-allocated strings
    free(reversedStr1);
    free(reversedStr2);
    free(reversedStr3);
    free(noSpacesStr1);
    free(noSpacesStr2);
    free(noSpacesStr3);
    
    return 0;
}