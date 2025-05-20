//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to reverse a string
char* reverse(char* str)
{
    int len = strlen(str);
    char* rev = (char*)malloc(len + 1);
    for (int i = 0; i < len / 2; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[len] = '\0';
    return rev;
}

// Function to get the length of a string
int getLength(char* str)
{
    int len = strlen(str);
    return len;
}

// Function to compare two strings
int compare(char* str1, char* str2)
{
    int len1 = getLength(str1);
    int len2 = getLength(str2);

    if (len1!= len2) {
        return len1 - len2;
    } else {
        for (int i = 0; i < len1; i++) {
            if (str1[i]!= str2[i]) {
                return str1[i] - str2[i];
            }
        }
        return 0;
    }
}

// Function to convert a string to lowercase
char* toLower(char* str)
{
    int len = strlen(str);
    char* lower = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        lower[i] = str[i] + 32;
    }
    lower[len] = '\0';
    return lower;
}

// Main function
int main()
{
    char* str;
    int choice;

    while (1) {
        printf("Enter a string: ");
        fgets(str, sizeof(str), stdin);

        if (str[0] == 'q') {
            break;
        }

        // Reverse the string
        char* rev = reverse(str);
        printf("Reversed: %s\n", rev);

        // Get the length of the string
        int len = getLength(str);
        printf("Length: %d\n", len);

        // Compare the string with itself
        int comp = compare(str, str);
        printf("Comparison: %d\n", comp);

        // Convert the string to lowercase
        char* lower = toLower(str);
        printf("Lowercase: %s\n", lower);

        free(rev);
        free(lower);
        free(str);
    }

    return 0;
}