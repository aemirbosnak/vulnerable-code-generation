//FormAI DATASET v1.0 Category: Text processing ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to read string from user
char* readString() {
    char* str = malloc(1000 * sizeof(char));
    fgets(str, 1000, stdin);
    return str;
}

// function to replace substring
char* replaceString(char* original, char* target, char* replacement) {
    char* result;
    char* insertPoint; 
    char* tail;         
    int targetLen = strlen(target);
    int replaceLen = strlen(replacement);

    // allocate memory for result
    result = malloc(strlen(original) + replaceLen + 1);

    // initialize variables
    insertPoint = strstr(original, target);
    tail = original;

    // loop through each instance of target substring and copy original string to result
    while (insertPoint != NULL) {
        memcpy(result + strlen(result), tail, insertPoint - tail); // copy original string before target substring
        memcpy(result + strlen(result), replacement, replaceLen); // copy replacement string inplace of target substring

        tail = insertPoint + targetLen;
        insertPoint = strstr(tail, target);
    }

    // copy remaining part of original string to result
    strcat(result, tail);

    return result;
}

int main() {
    printf("Enter a string: ");
    char* originalStr = readString();

    printf("Enter a substring to replace: ");
    char* targetStr = readString();

    printf("Enter a replacement string: ");
    char* replacementStr = readString();

    char* result = replaceString(originalStr, targetStr, replacementStr);

    printf("Original String: %s", originalStr);
    printf("Resultant String: %s", result);

    free(originalStr);
    free(targetStr);
    free(replacementStr);
    free(result);

    return 0; 
}