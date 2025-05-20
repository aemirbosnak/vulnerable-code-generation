//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: recursive
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

// Function to count the frequency of a given word in a string
int countFrequency(char* str, char* word) {
    int i = 0, j = 0, count = 0;

    // Convert both string and word to lowercase for case-insensitive comparison
    for (i = 0; str[i]!= '\0'; i++) {
        str[i] = tolower(str[i]);
    }
    for (j = 0; word[j]!= '\0'; j++) {
        word[j] = tolower(word[j]);
    }

    // Recursive function to count the frequency of the word in the string
    while (str[i]!= '\0') {
        if (str[i] == word[j]) {
            i++;
            j++;
        } else if (j > 0) {
            j = 0;
        } else {
            i++;
        }
    }

    // Return the frequency of the word in the string
    return count;
}

// Function to read a string from the user
char* readString() {
    char* str = (char*)malloc(100 * sizeof(char));
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    return str;
}

// Function to read a word from the user
char* readWord() {
    char* word = (char*)malloc(20 * sizeof(char));
    printf("Enter a word: ");
    fgets(word, 20, stdin);
    word[strcspn(word, "\n")] = '\0';
    return word;
}

// Main function to run the program
int main() {
    char* str = NULL;
    char* word = NULL;

    // Read a string from the user
    str = readString();

    // Read a word from the user
    word = readWord();

    // Count the frequency of the word in the string
    int frequency = countFrequency(str, word);

    // Print the frequency of the word in the string
    printf("The frequency of '%s' in '%s' is %d\n", word, str, frequency);

    // Free the dynamically allocated memory
    free(str);
    free(word);

    return 0;
}