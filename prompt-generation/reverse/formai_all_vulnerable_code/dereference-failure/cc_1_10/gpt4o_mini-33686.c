//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void toUpperCase(char *str) {
    while (*str) {
        *str = toupper((unsigned char) *str);
        str++;
    }
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void findSubstring(char *str, char *sub) {
    char *pos = strstr(str, sub);
    if (pos) {
        printf("Oh wow! Substring '%s' found at position %ld\n", sub, pos - str);
    } else {
        printf("Oh no! Substring '%s' not found...\n", sub);
    }
}

void replaceSubstring(char *str, const char *oldSub, const char *newSub) {
    char *pos = strstr(str, oldSub);
    
    if (pos == NULL) {
        printf("Oops! Substring '%s' not found for replacement!\n", oldSub);
        return;
    }
    
    // Calculate new string length
    int lenOld = strlen(oldSub);
    int lenNew = strlen(newSub);
    int lenRest = strlen(pos + lenOld);
    
    char *newStr = (char *)malloc(strlen(str) - lenOld + lenNew + 1);
    
    // Copy the part before the substring
    strncpy(newStr, str, pos - str);
    newStr[pos - str] = '\0';

    // Append the new substring
    strcat(newStr, newSub);
    // Append the rest of the original string after the substring
    strcat(newStr, pos + lenOld);

    // Actually change the original string
    strcpy(str, newStr);
    free(newStr);
    printf("Hooray! Substring replaced!\n");
}

void userStringInput(char *str, int maxLength) {
    printf("Please enter a string (max %d characters): ", maxLength);
    fgets(str, maxLength, stdin);
    
    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    char originalString[256];
    char searchString[256];
    char replaceString[256];
    
    // Step 1 - String input
    userStringInput(originalString, sizeof(originalString));
    
    printf("You entered: %s\n", originalString);
    
    // Step 2 - Uppercase
    char upperString[256];
    strcpy(upperString, originalString);
    toUpperCase(upperString);
    
    printf("Oh my! Uppercase version: %s\n", upperString);
    
    // Step 3 - Reverse string
    char reversedString[256];
    strcpy(reversedString, originalString);
    reverseString(reversedString);
    
    printf("Surprisingly reversed: %s\n", reversedString);
    
    // Step 4 - Find substring
    printf("Enter substring to find: ");
    fgets(searchString, sizeof(searchString), stdin);
    searchString[strcspn(searchString, "\n")] = '\0'; // Remove newline
    findSubstring(originalString, searchString);
    
    // Step 5 - Replace substring
    printf("Enter substring to replace: ");
    fgets(searchString, sizeof(searchString), stdin);
    searchString[strcspn(searchString, "\n")] = '\0'; // Remove newline
    
    printf("Enter new substring: ");
    fgets(replaceString, sizeof(replaceString), stdin);
    replaceString[strcspn(replaceString, "\n")] = '\0'; // Remove newline
    
    replaceSubstring(originalString, searchString, replaceString);
    
    printf("Final modified string: %s\n", originalString);
    
    return 0;
}