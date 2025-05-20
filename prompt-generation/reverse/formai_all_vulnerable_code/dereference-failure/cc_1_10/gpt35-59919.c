//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: beginner-friendly
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// function to convert all characters to lowercase
char* toLowerCase(char* str) {
    char* result = (char*)malloc(strlen(str)*sizeof(char));
    for(int i = 0; i < strlen(str); i++) {
        result[i] = tolower(str[i]);
    }
    return result;
}

// function to count word frequency
void countWords(char* str, int size) {
    int count = 0;
    char** words = (char**)malloc(size*sizeof(char*));
    int* frequency = (int*)calloc(size, sizeof(int));
    char* word = strtok(str, " ");
    while(word != NULL) {
        int found = 0;
        char* lower = toLowerCase(word); // convert word to lowercase
        for(int i = 0; i < count; i++) {
            if(strcmp(lower, words[i]) == 0) {
                frequency[i]++;
                found = 1;
                break;
            }
        }
        if(!found) {
            words[count] = lower;
            frequency[count]++;
            count++;
        }
        word = strtok(NULL, " ");
    }
    printf("Word\t\tFrequency\n");
    for(int i = 0; i < count; i++) {
        printf("%s\t\t%d\n", words[i], frequency[i]);
    }
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    fgets(str, 1000, stdin);
    countWords(str, strlen(str));
    return 0;
}