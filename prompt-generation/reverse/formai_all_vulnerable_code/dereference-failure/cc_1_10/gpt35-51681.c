//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Define maximum number of words
#define MAX_WORDS 1000

int main() {

    // Initialize variables
    FILE *fp;
    char word[100], c;
    int i=0, j=0, count=0, freq[MAX_WORDS];
    memset(freq, 0, sizeof(freq));
    
    // Open file
    fp = fopen("sample.txt", "r");

    // Check for error
    if(fp == NULL) {
        printf("File not found.");
        return 1;
    }

    // Read file character by character
    while((c = fgetc(fp)) != EOF) {

        // Check for alphabets
        if(isalpha(c)) {
            word[i++] = tolower(c);
        }

        // Check for space or newline - end of word
        else if (isspace(c) || c == '\n') {
            
            // Add null terminating character
            word[i] = '\0';
            
            // Check if word is already counted
            for(j=0; j<count; j++) {
                if(strcmp(word, &word[freq[j]]) == 0) {
                    freq[j]++;
                    break;
                }
            }
            
            // If word is not counted, add it to array
            if(j==count) {
                freq[count] = 1;
                strcpy(&word[count*100], word);
                count++;
            }
            i = 0;
        }
    }
    
    // Print word frequency table
    printf("\nWord\t\tFrequency\n");
    for(i=0; i<count; i++) {
        printf("%-16s%4d\n", &word[i*100], freq[i]);
    }
    
    // Close file
    fclose(fp);
    
    return 0;
}