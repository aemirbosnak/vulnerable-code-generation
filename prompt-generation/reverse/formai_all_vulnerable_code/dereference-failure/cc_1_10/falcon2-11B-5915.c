//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

// Function to search for a pattern in a string
bool searchPattern(char* pattern, char* str) {
    // Initialize variables
    int patternLength = strlen(pattern);
    int strLength = strlen(str);
    int i, j;
    
    // If the pattern is longer than the string, it cannot be found
    if (patternLength > strLength) {
        return false;
    }
    
    // Iterate over the string to find the pattern
    for (i = 0; i <= strLength - patternLength; i++) {
        j = 0;
        
        // Check if each character in the pattern matches the corresponding character in the string
        while (j < patternLength) {
            if (tolower(str[i+j])!= tolower(pattern[j])) {
                break;
            }
            j++;
        }
        
        // If all characters in the pattern match the corresponding characters in the string, return true
        if (j == patternLength) {
            return true;
        }
    }
    
    // If no matches are found, return false
    return false;
}

int main() {
    // Create a random string of characters
    char* str = (char*) malloc(sizeof(char) * 100);
    for (int i = 0; i < 100; i++) {
        str[i] = (char) (rand() % 26 + 'a');
    }
    
    // Create a random pattern of characters
    char* pattern = (char*) malloc(sizeof(char) * 10);
    for (int i = 0; i < 10; i++) {
        pattern[i] = (char) (rand() % 26 + 'a');
    }
    
    // Search for the pattern in the string
    if (searchPattern(pattern, str)) {
        printf("Pattern found in string\n");
    } else {
        printf("Pattern not found in string\n");
    }
    
    // Free allocated memory
    free(str);
    free(pattern);
    
    return 0;
}