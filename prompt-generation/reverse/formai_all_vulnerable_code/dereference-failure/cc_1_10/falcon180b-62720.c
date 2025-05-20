//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

// Function to count the number of words in a string
int count_words(char* str);

// Function to reverse a string
void reverse_string(char* str);

int main() {
    // Test case 1: Counting words in a string
    char* str1 = "The quick brown fox jumps over the lazy dog";
    int num_words = count_words(str1);
    printf("Number of words in '%s': %d\n", str1, num_words);

    // Test case 2: Reversing a string
    char* str2 = "Hello, world!";
    reverse_string(str2);
    printf("Reversed string: %s\n", str2);

    return 0;
}

// Function to count the number of words in a string
int count_words(char* str) {
    int num_words = 0;
    char* word;

    word = strtok(str, " ");
    while (word!= NULL) {
        num_words++;
        word = strtok(NULL, " ");
    }

    return num_words;
}

// Function to reverse a string
void reverse_string(char* str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}