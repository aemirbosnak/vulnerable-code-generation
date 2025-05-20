//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

// Function to reverse a string
void reverse_string(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to capitalize the first letter of each word in a string
void capitalize_words(char* str) {
    char* word = strtok(str, " ");
    while (word!= NULL) {
        char first_letter = toupper(word[0]);
        strcat(str, &first_letter);
        strcat(str, &word[1]);
        word = strtok(NULL, " ");
    }
}

// Function to remove all vowels from a string
void remove_vowels(char* str) {
    char vowels[] = "aeiouAEIOU";
    int i = 0;

    while (str[i]!= '\0') {
        if (strchr(vowels, str[i]) == NULL) {
            str[i] = str[i];
            i++;
        } else {
            i++;
        }
    }
}

// Function to count the number of words in a string
int count_words(char* str) {
    char* word = strtok(str, " ");
    int count = 0;

    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

int main() {
    char input_string[MAX_STRING_LENGTH];

    // Get input string from user
    printf("Enter a string: ");
    fgets(input_string, MAX_STRING_LENGTH, stdin);

    // Reverse the string
    reverse_string(input_string);
    printf("Reversed string: %s\n", input_string);

    // Capitalize the first letter of each word
    capitalize_words(input_string);
    printf("Capitalized string: %s\n", input_string);

    // Remove all vowels from the string
    remove_vowels(input_string);
    printf("String without vowels: %s\n", input_string);

    // Count the number of words in the string
    int num_words = count_words(input_string);
    printf("Number of words: %d\n", num_words);

    return 0;
}