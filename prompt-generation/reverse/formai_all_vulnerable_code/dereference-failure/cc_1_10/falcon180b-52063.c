//Falcon-180B DATASET v1.0 Category: Text processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Function to remove punctuation from a string
char* removePunctuation(char* str) {
    int i, j;
    char* result = malloc(strlen(str) + 1);
    for (i = 0, j = 0; str[i]; i++) {
        if (!ispunct(str[i])) {
            result[j++] = tolower(str[i]);
        }
    }
    result[j] = '\0';
    return result;
}

// Function to count the frequency of each word in a string
void countWords(char* str, int* freq) {
    int i, j;
    char* word = malloc(strlen(str) + 1);
    for (i = 0, j = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            word[j++] = tolower(str[i]);
        } else if (j > 0) {
            freq[word[0] - 'a']++;
            j = 0;
        }
    }
    freq[word[0] - 'a']++;
}

// Function to print the top n most frequent words in a string
void printTopWords(int* freq, int n) {
    int i, maxFreq = 0;
    for (i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }
    printf("Top %d most frequent words:\n", n);
    for (i = 0; i < 26; i++) {
        if (freq[i] == maxFreq) {
            printf("%c: %d\n", i + 'a', freq[i]);
        }
    }
}

int main() {
    char input[10000];
    int freq[26] = {0};
    printf("Enter a string:\n");
    fgets(input, sizeof(input), stdin);
    char* text = removePunctuation(input);
    countWords(text, freq);
    printTopWords(freq, 10);
    free(text);
    return 0;
}