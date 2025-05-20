//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

// Function to split a string into words
void split_string(char* str, char** words) {
    int num_words = 0;
    char* word = strtok(str, ",.?!;:");
    while (word!= NULL && num_words < MAX_NUM_WORDS) {
        words[num_words] = word;
        num_words++;
        word = strtok(NULL, ",.?!;:");
    }
}

// Function to count the frequency of each word
void count_words(char** words, int num_words) {
    int i, j;
    for (i = 0; i < num_words; i++) {
        for (j = 0; j < i; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                break;
            }
        }
        if (j == i) {
            printf("%s: 1\n", words[i]);
        }
    }
}

// Function to convert a string to lowercase
void to_lowercase(char* str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char input[1000];
    char* words[MAX_NUM_WORDS];
    int num_words;

    // Prompt user for input
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Convert input to lowercase
    to_lowercase(input);

    // Split input into words
    split_string(input, words);
    num_words = strlen(words);

    // Count frequency of each word
    count_words(words, num_words);

    return 0;
}