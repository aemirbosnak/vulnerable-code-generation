//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_WORD_LENGTH 100

// function to remove unwanted characters from the string
void removePunctuation(char *word) {
    int i, len = strlen(word);

    for(i = 0; i < len; i++) {
        if(!((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))) {
            // replace character with a space
            word[i] = ' ';
        }
    }
}

// function to convert string to lower case
void toLowerCase(char *word) {
    int i, len = strlen(word);

    for(i = 0; i < len; i++) {
        if(word[i] >= 'A' && word[i] <= 'Z') {
            // convert uppercase char to its lowercase equivalent
            word[i] = word[i] + 32;
        }
    }
}

// function to count frequency of each word
void wordFrequency(char *fileName, int n) {
    // open file in read mode
    FILE *fp = fopen(fileName, "r");

    if(fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    // create array of strings to store each word
    char **words = (char**)malloc(n * sizeof(char *));
    int *freq = (int*)calloc(n, sizeof(int));

    int i, j;
    for(i = 0; i < n; i++) {
        words[i] = (char*)calloc(MAX_WORD_LENGTH + 1, sizeof(char));
    }

    // read words from file and store in array
    i = 0;
    while(fscanf(fp, "%s", words[i]) != EOF && i < n) {
        removePunctuation(words[i]);
        toLowerCase(words[i]);
        i++;
    }
    fclose(fp);

    // count frequency of each word in array
    for(i = 0; i < n; i++) {
        if(strcmp(words[i], "") == 0) {
            // skip empty string
            continue;
        }
        freq[i]++;
        for(j = i + 1; j < n; j++) {
            if(strcmp(words[i], words[j]) == 0) {
                freq[i]++;
                // mark repeated words as ""
                strcpy(words[j], "");
            }
        }
    }

    // print frequency of each word
    for(i = 0; i < n; i++) {
        if(strcmp(words[i], "") == 0) {
            // skip empty string
            continue;
        }
        printf("%s : %d\n", words[i], freq[i]);
    }

    // free allocated memory
    for(i = 0; i < n; i++) {
        free(words[i]);
    }
    free(words);
    free(freq);
}

// main function
int main() {
    char fileName[100];
    int n;
    printf("Enter name of file: ");
    scanf("%s", fileName);
    printf("Enter maximum number of words to read: ");
    scanf("%d", &n);
    wordFrequency(fileName, n);
    return 0;
}