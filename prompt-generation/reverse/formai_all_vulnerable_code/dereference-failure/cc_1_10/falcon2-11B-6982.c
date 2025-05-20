//Falcon2-11B DATASET v1.0 Category: String manipulation ; Style: puzzling
#include <stdio.h>
#include <string.h>

// Recursive function to find the length of the longest common prefix between two strings
int findLcp(char* str1, char* str2, int* length) {
    if (*length == 0)
        return 0;
    if (*length == 1) {
        if (*str1 == *str2)
            return 1;
        return 0;
    }
    if (*str1 == *str2) {
        (*length)--;
        return findLcp(str1, str2, length) + 1;
    }
    return findLcp(str1, str2, length) + 1;
}

// Recursive function to concatenate two strings
char* concat(char* str1, char* str2) {
    if (*str1 == '\0')
        return str2;
    if (*str2 == '\0')
        return str1;
    char* result = (char*)malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

int main() {
    char str1[100];
    char str2[100];
    int length1, length2;
    int lcpLength;
    printf("Enter string 1: ");
    fgets(str1, sizeof(str1), stdin);
    length1 = strlen(str1);
    printf("Enter string 2: ");
    fgets(str2, sizeof(str2), stdin);
    length2 = strlen(str2);
    lcpLength = findLcp(str1, str2, &length1);
    if (lcpLength == 0) {
        printf("No common prefix\n");
    } else {
        printf("Common prefix length: %d\n", lcpLength);
        printf("Concatenated string: %s\n", concat(str1, str2));
    }
    return 0;
}