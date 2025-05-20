//Falcon2-11B DATASET v1.0 Category: String manipulation ; Style: careful
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello, World!";
    char str2[] = "This is a test.";
    
    // Concatenate two strings
    strcat(str1, str2);
    printf("%s\n", str1);
    
    // Find length of a string
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    printf("Length of str1: %d\n", len1);
    printf("Length of str2: %d\n", len2);
    
    // Reverse a string
    char rev[len1 + 1];
    int i = 0;
    for (int j = len1 - 1; j >= 0; j--) {
        rev[i++] = str1[j];
    }
    rev[i] = '\0';
    printf("Reversed str1: %s\n", rev);
    
    // Replace a substring
    int replaceIndex = 4;
    int replaceLength = 4;
    char replaceStr[] = "World!";
    str1[replaceIndex] = '!';
    str1[replaceIndex + 1] = '!';
    str1[replaceIndex + 2] = '!';
    str1[replaceIndex + 3] = '!';
    printf("Modified str1: %s\n", str1);
    
    // Replace a substring using strcspn and strspn
    char replaceStr2[] = "Test";
    int replaceIndex2 = strcspn(str1, replaceStr2);
    str1[replaceIndex2] = '!';
    str1[replaceIndex2 + 1] = '!';
    str1[replaceIndex2 + 2] = '!';
    str1[replaceIndex2 + 3] = '!';
    printf("Modified str1: %s\n", str1);
    
    // Check if a string contains a substring
    if (strstr(str1, replaceStr)!= NULL) {
        printf("str1 contains replaceStr\n");
    } else {
        printf("str1 does not contain replaceStr\n");
    }
    
    // Convert a string to lowercase
    char lowercaseStr[len1 + 1];
    for (int i = 0; i < len1; i++) {
        lowercaseStr[i] = tolower(str1[i]);
    }
    lowercaseStr[i] = '\0';
    printf("Lowercase str1: %s\n", lowercaseStr);
    
    // Convert a string to uppercase
    char uppercaseStr[len1 + 1];
    for (int i = 0; i < len1; i++) {
        uppercaseStr[i] = toupper(str1[i]);
    }
    uppercaseStr[i] = '\0';
    printf("Uppercase str1: %s\n", uppercaseStr);
    
    return 0;
}