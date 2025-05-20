//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to check if a word is in the dictionary of known words
int isWord(char *word) {
    // Initialize variables
    int i, j;
    int len = strlen(word);

    // Check if the length of the word is greater than or equal to 3
    if (len >= 3) {
        // Create an array of characters representing each letter of the word
        char *arr = malloc(len * sizeof(char));
        for (i = 0; i < len; i++) {
            arr[i] = word[i];
        }

        // Sort the array of characters
        for (i = 0; i < len - 1; i++) {
            for (j = i + 1; j < len; j++) {
                if (arr[i] > arr[j]) {
                    char temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        // Check if the sorted array of characters is equal to the dictionary of known words
        for (i = 0; i < len - 2; i++) {
            if (tolower(arr[i]) == tolower(arr[i + 1]) && tolower(arr[i + 1]) == tolower(arr[i + 2])) {
                return 1; // Word is in the dictionary
            }
        }

        free(arr);
        return 0; // Word is not in the dictionary
    }

    return 0; // Word is not in the dictionary
}

// Function to suggest possible corrections for a misspelled word
void suggestCorrections(char *word, char *suggestions) {
    // Initialize variables
    int i, j;
    int len = strlen(word);

    // Create an array of characters representing each letter of the word
    char *arr = malloc(len * sizeof(char));
    for (i = 0; i < len; i++) {
        arr[i] = word[i];
    }

    // Sort the array of characters
    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Check if the sorted array of characters is equal to the dictionary of known words
    for (i = 0; i < len - 2; i++) {
        if (tolower(arr[i]) == tolower(arr[i + 1]) && tolower(arr[i + 1]) == tolower(arr[i + 2])) {
            for (j = 0; j < len; j++) {
                if (tolower(arr[j]) == tolower(arr[i + 1]) && isWord(arr + i + 1)) {
                    sprintf(suggestions, "%c", arr[j]);
                    break;
                }
            }
        }
    }

    free(arr);
}

// Main function
int main() {
    char input[1000], *ptr, *suggestions[10];
    int i, j;

    // Prompt user for input
    printf("Enter a sentence: ");
    gets(input);

    // Iterate through each word in the input string
    for (ptr = input; *ptr!= '\0'; ptr++) {
        // Check if the word is in the dictionary of known words
        if (!isWord(*ptr)) {
            printf("Spell check: %s is misspelled\n", ptr);
            suggestCorrections(ptr, suggestions);
            printf("Suggested corrections: ");
            for (i = 0; i < 10; i++) {
                printf("%s ", suggestions[i]);
            }
            printf("\n");
        }
    }

    return 0;
}