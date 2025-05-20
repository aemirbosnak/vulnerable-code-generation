//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void countVowels(const char *str, int *vowelCount) {
    const char *vowels = "aeiouAEIOU";
    while (*str) {
        if (strchr(vowels, *str)) {
            (*vowelCount)++;
        }
        str++;
    }
}

void splitWords(char *str, char ***wordsArray, int *wordsCount) {
    char *token = strtok(str, " ");
    int capacity = 10;
    *wordsArray = malloc(sizeof(char*) * capacity);
    
    while (token) {
        if (*wordsCount >= capacity) {
            capacity *= 2;
            *wordsArray = realloc(*wordsArray, sizeof(char*) * capacity);
        }
        (*wordsArray)[*wordsCount] = strdup(token);
        (*wordsCount)++;
        token = strtok(NULL, " ");
    }
}

void freeWordsArray(char **wordsArray, int wordsCount) {
    for (int i = 0; i < wordsCount; i++) {
        free(wordsArray[i]);
    }
    free(wordsArray);
}

int main() {
    char str[1024];
    printf("Enter a string for mind-bending text processing:\n");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    printf("Original String: %s\n", str);

    // Convert to upper case
    char upperStr[1024];
    strcpy(upperStr, str);
    toUpperCase(upperStr);
    printf("Uppercase Version: %s\n", upperStr);

    // Convert to lower case
    char lowerStr[1024];
    strcpy(lowerStr, str);
    toLowerCase(lowerStr);
    printf("Lowercase Version: %s\n", lowerStr);

    // Reverse the string
    char reversedStr[1024];
    strcpy(reversedStr, str);
    reverseString(reversedStr);
    printf("Reversed Version: %s\n", reversedStr);

    // Count vowels
    int vowelCount = 0;
    countVowels(str, &vowelCount);
    printf("Number of vowels: %d\n", vowelCount);

    // Split words
    char **wordsArray;
    int wordsCount = 0;
    splitWords(str, &wordsArray, &wordsCount);
    printf("Words Count: %d\n", wordsCount);
    for (int i = 0; i < wordsCount; i++) {
        printf("Word %d: %s\n", i + 1, wordsArray[i]);
    }

    // Free the dynamically allocated memory
    freeWordsArray(wordsArray, wordsCount);

    // Escape the mundane
    char cryptic[1024];
    strcpy(cryptic, str);
    for (int i = 0; i < strlen(cryptic); i++) {
        if (islower(cryptic[i])) {
            cryptic[i] = cryptic[i] + 3;  // Caesar shift for lower
        } else if (isupper(cryptic[i])) {
            cryptic[i] = cryptic[i] - 3;  // Caesar shift for upper
        }
    }
    printf("Encoded (Cryptic) Version: %s\n", cryptic);

    return 0;
}