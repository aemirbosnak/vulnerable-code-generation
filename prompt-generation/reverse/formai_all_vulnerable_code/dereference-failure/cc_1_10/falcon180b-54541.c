//Falcon-180B DATASET v1.0 Category: Text processing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to count the number of words in a sentence
int countWords(char* sentence) {
    int count = 0;
    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Function to count the number of characters in a sentence
int countCharacters(char* sentence) {
    int count = 0;
    while (*sentence!= '\0') {
        count++;
        sentence++;
    }
    return count;
}

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    char* start = str;
    char* end = str + length - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to convert a string to uppercase
void toUppercase(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to convert a string to lowercase
void toLowercase(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    scanf("%s", sentence);

    // Count the number of words and characters in the sentence
    int numWords = countWords(sentence);
    int numCharacters = countCharacters(sentence);

    // Reverse the sentence
    reverseString(sentence);

    // Convert the sentence to uppercase
    toUppercase(sentence);

    // Convert the sentence to lowercase
    toLowercase(sentence);

    // Print the results
    printf("Original sentence: %s\n", sentence);
    printf("Number of words: %d\n", numWords);
    printf("Number of characters: %d\n", numCharacters);
    printf("Reversed sentence: %s\n", sentence);
    printf("Uppercase sentence: %s\n", sentence);
    printf("Lowercase sentence: %s\n", sentence);

    return 0;
}