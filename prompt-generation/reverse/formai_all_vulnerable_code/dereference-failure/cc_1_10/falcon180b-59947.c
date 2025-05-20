//Falcon-180B DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count the number of words in a string
int word_count(char *str) {
    int count = 0;
    char *token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to reverse a string
void reverse_string(char *str) {
    int len = strlen(str);
    char *rev_str = malloc(len + 1);
    int i = 0;
    for (int j = len - 1; j >= 0; j--) {
        rev_str[i++] = tolower(str[j]);
    }
    rev_str[i] = '\0';
    printf("%s\n", rev_str);
}

// Function to convert a string to title case
void title_case(char *str) {
    int len = strlen(str);
    char *title_str = malloc(len + 1);
    int i = 0;
    for (int j = 0; j < len; j++) {
        if (isalpha(str[j])) {
            if (j == 0) {
                title_str[i++] = tolower(str[j]);
            } else if (isalpha(str[j - 1]) && isspace(str[j])) {
                title_str[i++] = toupper(str[j]);
            } else {
                title_str[i++] = tolower(str[j]);
            }
        } else if (isspace(str[j])) {
            title_str[i++] = str[j];
        } else {
            title_str[i++] = str[j];
        }
    }
    title_str[i] = '\0';
    printf("%s\n", title_str);
}

int main() {
    char input[1000];

    // Prompt user to enter a string
    printf("Enter a string: ");
    scanf("%s", input);

    // Count the number of words in the string
    printf("Number of words: %d\n", word_count(input));

    // Reverse the string
    printf("Reversed string: ");
    reverse_string(input);

    // Convert the string to title case
    printf("Title case string: ");
    title_case(input);

    return 0;
}