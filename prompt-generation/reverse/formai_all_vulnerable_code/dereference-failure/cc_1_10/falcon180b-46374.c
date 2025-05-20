//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to split a string into words based on whitespace
void split(char* str, char** words) {
    int i = 0;
    char* word = strtok(str, " ");
    while (word!= NULL) {
        words[i++] = word;
        word = strtok(NULL, " ");
    }
    words[i] = NULL;
}

// Function to remove non-alphanumeric characters from a string
void clean(char* str) {
    int i = 0;
    while (str[i]) {
        if (isalnum(str[i])) {
            str[i] = tolower(str[i]);
            i++;
        } else {
            str[i] = '\0';
        }
    }
}

// Function to count the frequency of each word in a string
void countWords(char* str, int* freq) {
    char* words[100];
    int numWords = 0;
    split(str, words);
    for (int i = 0; i < numWords; i++) {
        clean(words[i]);
        for (int j = 0; j < strlen(words[i]); j++) {
            freq[i*26 + tolower(words[i][j]) - 'a']++;
        }
    }
}

// Function to print the frequency of each word in a string
void printFreq(int* freq) {
    for (int i = 0; i < 26; i++) {
        printf("%c: ", i + 'a');
        for (int j = 0; j < 26; j++) {
            if (freq[i*26 + j] > 0) {
                printf("%d ", freq[i*26 + j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int main() {
    char* str = "Romeo, take me somewhere we can be alone. I'll be waiting; all that's left to do is run. What if this storm ends? And I don't see you? As you are now, so once I was. As I am now, so you will be. Prepare yourself to meet your maker. Juliet: My only love sprung from my only hate! Too early seen unknown, and known too late! Arise, fair sun, and kill the envious moon, who is already sick and pale with grief.";
    int freq[26*26];
    countWords(str, freq);
    printFreq(freq);
    return 0;
}