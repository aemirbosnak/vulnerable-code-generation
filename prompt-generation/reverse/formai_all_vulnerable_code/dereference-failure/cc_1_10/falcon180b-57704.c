//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE];
    char *token;
    int count;

    // Get input from user
    printf("Enter first string: ");
    fgets(str1, MAX_SIZE, stdin);

    printf("Enter second string: ");
    fgets(str2, MAX_SIZE, stdin);

    // Count number of words in str1
    count = 0;
    token = strtok(str1, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    // Concatenate str1 and str2
    char result[MAX_SIZE];
    strcpy(result, str1);
    strcat(result, str2);

    // Convert all characters to lowercase
    for (int i = 0; i < strlen(result); i++) {
        result[i] = tolower(result[i]);
    }

    // Reverse the order of words in result
    char *word;
    char *reverse_result = malloc(MAX_SIZE);
    strcpy(reverse_result, result);
    word = strtok(reverse_result, " ");
    while (word!= NULL) {
        strcat(result, word);
        strcat(result, " ");
        word = strtok(NULL, " ");
    }
    strcat(result, "\n");

    // Output result
    printf("Result: %s\n", result);
    printf("Number of words in str1: %d\n", count);

    return 0;
}