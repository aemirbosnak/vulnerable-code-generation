//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <time.h>

// Define the max number of characters in the input string
#define MAX_CHAR_COUNT 100000

// Define the array to store the frequency of each character
char char_count[26] = {0};

// Function to count the frequency of each character in the input string
void count_frequency(char* input) {
    // Clear the char_count array
    memset(char_count, 0, sizeof(char_count));
    
    // Convert the input string to lowercase for easier comparison
    char* lowercase_input = (char*) malloc(MAX_CHAR_COUNT * sizeof(char));
    strcpy(lowercase_input, input);
    for (int i = 0; i < MAX_CHAR_COUNT; i++) {
        lowercase_input[i] = tolower(lowercase_input[i]);
    }
    
    // Count the frequency of each character
    int length = strlen(lowercase_input);
    for (int i = 0; i < length; i++) {
        char_count[lowercase_input[i] - 'a']++;
    }
    
    // Print the frequency of each character
    printf("Frequency of each character:\n");
    for (int i = 0; i < 26; i++) {
        if (char_count[i] > 0) {
            printf("%c: %d\n", i + 'a', char_count[i]);
        }
    }
}

// Main function
int main() {
    char* input = (char*) malloc(MAX_CHAR_COUNT * sizeof(char));
    
    // Get the input string from the user
    printf("Enter the input string: ");
    fgets(input, MAX_CHAR_COUNT, stdin);
    
    // Count the frequency of each character in the input string
    count_frequency(input);
    
    // Free the memory allocated for the input string
    free(input);
    
    return 0;
}