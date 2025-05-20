//FormAI DATASET v1.0 Category: Text processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 // Maximum line length for file input

void reverseWords(char *line){
    char *wordStart, *wordEnd; // Used to keep track of start and end of words
    char *ptr = line; // Pointer to traverse the string
    char temp; // Used for swapping characters
    
    // Reverse the entire string
    while (*ptr != '\0') {
        ++ptr; // Move to end of string
    }
    --ptr; // Backtrack to last character before null terminator
    
    // Iterate through string and reverse each word
    while (ptr >= line) {
        wordEnd = ptr; // Set end of word to last character
        while (ptr >= line && *ptr != ' ') {
            --ptr; // Traverse backwards to find start of word
        }
        wordStart = ptr + 1; // Set start of word
        while (wordStart <= wordEnd) {
            temp = *wordStart;
            *wordStart = *wordEnd;
            *wordEnd = temp;
            ++wordStart; // Move start forward
            --wordEnd; // Move end backwards
        }
        --ptr; // Move ptr back to start of next word
    }
}

int main() {
    char fileName[100];
    char line[MAX_LINE_LENGTH];
    
    // Get file name from user input
    printf("Please enter the name of the file you wish to process: ");
    fgets(fileName, 100, stdin);
    fileName[strcspn(fileName, "\n")] = 0; // Remove new line character from input
    
    FILE *file = fopen(fileName, "r");
    if (file == NULL) { // Check if file exists
        printf("Error: File cannot be opened.\n");
        return 1;
    }
    
    // Process each line in the file
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) { // Read each line in the file
        reverseWords(line); // Reverse the words in the line
        printf("%s", line); // Print the modified line
    }
    
    fclose(file); // Close the file
    
    return 0;
}