//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100

int main() {
    // Read the text file
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    // Read the text into a buffer
    char text[MAX_WORD_LEN];
    fgets(text, MAX_WORD_LEN, fp);
    
    // Close the file
    fclose(fp);
    
    // Split the text into words
    char *words[MAX_WORD_LEN];
    int num_words = 0;
    char *token = strtok(text, " \t\n\r");
    while (token!= NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " \t\n\r");
    }
    
    // Count the frequency of each word
    int freq[MAX_WORD_LEN];
    for (int i = 0; i < num_words; i++) {
        int index = 0;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                freq[index++] = 1;
                break;
            }
        }
    }
    
    // Print the frequency of each word
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], freq[i]);
    }
    
    // Clean up
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
    
    return 0;
}