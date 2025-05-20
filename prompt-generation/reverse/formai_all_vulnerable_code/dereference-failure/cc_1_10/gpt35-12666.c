//FormAI DATASET v1.0 Category: String manipulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str1, *str2; // declaring pointers for storing the strings

    // dynamically allocating memory for the strings
    str1 = (char*) malloc(sizeof(char) * 50);
    str2 = (char*) malloc(sizeof(char) * 50);

    // taking input string from user
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // concatenating the two strings using strcat() function
    strcat(str1, str2);

    // printing the concatenated string
    printf("Concatenated String: %s\n", str1);

    // checking if the strings are equal or not using strcmp() function
    if (strcmp(str1, str2) == 0) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    // finding the length of the string using strlen() function
    int len = strlen(str1);
    printf("Length of the concatenated string: %d\n", len);

    // converting the string to uppercase using toupper() function
    char *upper_str = (char*) malloc(sizeof(char) * (len + 1)); // allocating memory for the uppercased string

    for (int i = 0; i < len; i++) {
        upper_str[i] = toupper(str1[i]);
    }

    // printing the uppercase string
    printf("Uppercased String: %s\n", upper_str);

    // freeing the memory allocated for the strings
    free(str1);
    free(str2);
    free(upper_str);

    return 0;
}